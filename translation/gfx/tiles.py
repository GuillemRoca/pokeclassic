"""Helpers for relabelling text that lives in tilesets.

A label can only be redrawn inside tiles that nothing else on screen uses, so
`usage` maps every tile of a sheet to the tilemap cells that show it.
"""
import struct, os, re
from PIL import Image


class Sheet:
    def __init__(self, path):
        self.path = path
        self.im = Image.open(path)
        self.px = self.im.load()
        self.tw = self.im.width // 8
        self.n = self.tw * (self.im.height // 8)

    def tile_at(self, x, y):
        return (y // 8) * self.tw + x // 8

    def save(self):
        self.im.save(self.path)


def load_map(path):
    d = open(path, 'rb').read()
    return [struct.unpack_from('<H', d, i)[0] for i in range(0, len(d) - 1, 2)]


def usage(sheet, maps, base=0, width=32):
    """tile -> [(map name, cell x, cell y)] for every map entry that shows it."""
    out = {}
    for name, ents in maps.items():
        for i, e in enumerate(ents):
            t = (e & 0x3FF) - base
            if 0 <= t < sheet.n:
                out.setdefault(t, []).append((name, i % width, i // width))
    return out


def report(sheet, use, box):
    """Print, for the tiles under a PNG box, where each one is used."""
    x0, y0, x1, y1 = box
    for ty in range(y0 // 8, (y1 + 7) // 8):
        row = []
        for tx in range(x0 // 8, (x1 + 7) // 8):
            t = ty * sheet.tw + tx
            u = use.get(t, [])
            row.append(f'{t:3d}:{len(u)}')
        print('   ', ' '.join(row))


# ---- the game's own fonts -------------------------------------------------
HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
_FONTS = {'normal': 'Normal', 'small': 'Small', 'narrow': 'Narrow', 'short': 'Short', 'small_narrow': 'SmallNarrow'}


def _charmap():
    m = {}
    for line in open(f'{ROOT}/charmap.txt', encoding='utf-8'):
        mm = re.match(r"^'((?:[^'\\]|\\.)+)'\s*=\s*([0-9A-Fa-f]{2})\s*$", line.strip())
        if mm:
            ch = mm.group(1).replace("\\'", "'")
            if len(ch) == 1 and ch not in m:
                m[ch] = int(mm.group(2), 16)
    return m


CHARMAP = _charmap()


class Font:
    def __init__(self, name):
        self.im = Image.open(f'{ROOT}/graphics/fonts/latin_{name}.png')
        self.px = self.im.load()
        t = open(f'{ROOT}/src/fonts.c').read()
        m = re.search('gFont%sLatinGlyphWidths' % _FONTS[name] + r'\[\]\s*=\s*\{(.*?)\};', t, re.S)
        self.w = [int(x) for x in re.findall(r'\d+', m.group(1))]

    def glyph(self, ch):
        c = CHARMAP[ch]
        x, y = (c % 16) * 16, (c // 16) * 16
        w = self.w[c]
        return [[self.px[x + i, y + j] for i in range(w)] for j in range(16)], w

    def width(self, text, spacing=0):
        return sum(self.glyph(c)[1] + spacing for c in text) - spacing


def draw_text(px, font, text, x, y, colors, spacing=0, clip=None):
    """Draw with a game font. colors maps font index (1 ink, 2 shadow) to a
    palette index; font background (0, 3) is left untouched."""
    for ch in text:
        g, w = font.glyph(ch)
        for j in range(16):
            for i in range(w):
                v = g[j][i]
                if v in colors:
                    q = (x + i, y + j)
                    if clip is None or (clip[0] <= q[0] <= clip[2] and clip[1] <= q[1] <= clip[3]):
                        px[q] = colors[v]
        x += w + spacing
    return x


def relabel(sheet, box, old, new, font, ink, shadow, bg, align='left', width=None, spacing=0, search=None):
    """Replace the label `old` drawn with `font` inside PNG `box` by `new`.

    The old label is first re-rendered at every offset near the box until it
    matches the image exactly, which proves the font and gives the position.
    `new` is drawn on the same baseline: left-aligned at the same x, or centred
    in `width` pixels starting at box x0 (`align='center'`). Returns the
    rendered width of `new`; raises if `old` cannot be matched or `new` does
    not fit in the box.
    """
    px = sheet.px
    x0, y0, x1, y1 = box
    orig = {(x, y): px[x, y] for x in range(x0, x1 + 1) for y in range(y0, y1 + 1)}
    colors = {1: ink, 2: shadow} if shadow is not None else {1: ink}

    def render_at(text, x, y):
        img = {q: (bg if v in (ink, shadow) else v) for q, v in orig.items()}
        class P(dict):
            def __setitem__(s, k, v):
                if k in img: img[k] = v
                else: raise IndexError(k)
        p = P(); draw_text(p, font, text, x, y, colors, spacing)
        return img

    best = None
    for y in range(y0 - 13, y1 - 1):
        for x in range(x0 - 1, x0 + (search if search is not None else x1 - x0) + 1):
            try:
                img = render_at(old, x, y)
            except IndexError:
                continue
            bad = sum(1 for q in orig if img[q] != orig[q])
            if best is None or bad < best[0]:
                best = (bad, x, y)
            if bad == 0:
                break
        if best and best[0] == 0:
            break
    if not best or best[0] != 0:
        raise ValueError(f'{sheet.path}: {old!r} not matched in {box} (best {best})')
    _, x, y = best
    w = font.width(new, spacing)
    if align == 'center':
        x = x0 + ((width or (x1 - x0 + 1)) - w) // 2
    try:
        img = render_at(new, x, y)
    except IndexError as e:
        raise ValueError(f'{sheet.path}: {new!r} ({w}px) does not fit in {box}') from e
    for q, v in img.items():
        px[q] = v
    return w


# ---- custom pixel fonts, learnt from the labels that already use them ------
SHADOW_RULES = {'rd': ((1, 0), (0, 1), (1, 1)), 'r_d': ((1, 0), (0, 1)), 'r': ((1, 0),), 'd': ((0, 1),)}


def ink_groups(px, box, ink):
    x0, y0, x1, y1 = box
    pts = {(x, y) for x in range(x0, x1 + 1) for y in range(y0, y1 + 1) if px[x, y] == ink}
    cols = sorted({x for x, _ in pts})
    groups, cur = [], []
    for x in cols:
        if cur and x != cur[-1] + 1:
            groups.append(cur); cur = []
        cur.append(x)
    if cur:
        groups.append(cur)
    return pts, groups


def learn_glyphs(px, box, ink, text, top=None):
    """Letters of `text` (spaces skipped) as '#' masks, from the ink in box."""
    pts, groups = ink_groups(px, box, ink)
    letters = [c for c in text if c != ' ']
    if len(groups) != len(letters):
        raise ValueError(f'{text!r}: {len(groups)} ink groups for {len(letters)} letters in {box}')
    top = min(y for _, y in pts) if top is None else top
    bot = max(y for _, y in pts)
    out = {}
    for g, c in zip(groups, letters):
        out.setdefault(c, [''.join('#' if (x, y) in pts else '.' for x in range(g[0], g[-1] + 1))
                           for y in range(top, bot + 1)])
    gaps = [b[0] - a[-1] - 1 for a, b in zip(groups, groups[1:])]
    return out, gaps, top, (groups[0][0], groups[-1][-1])


def compose(glyphs, text, x, y, gap=1, space=3):
    ink = set()
    for c in text:
        if c == ' ':
            x += space; continue
        g = glyphs[c]
        for r, row in enumerate(g):
            for k, ch in enumerate(row):
                if ch == '#':
                    ink.add((x + k, y + r))
        x += len(g[0]) + gap
    return ink


def text_width(glyphs, text, gap=1, space=3):
    return sum(space if c == ' ' else len(glyphs[c][0]) + gap for c in text) - (0 if text[-1] == ' ' else gap)


def paint(px, box, ink_pts, ink, shadow, bg, rule, clear=None):
    """Clear ink/shadow colours (or `clear`) in box to bg, then draw ink and its shadow."""
    x0, y0, x1, y1 = box
    clear = clear or {ink, shadow}
    for y in range(y0, y1 + 1):
        for x in range(x0, x1 + 1):
            if px[x, y] in clear:
                px[x, y] = bg
    for (x, y) in ink_pts:
        if not (x0 <= x <= x1 and y0 <= y <= y1):
            raise ValueError(f'ink at {(x, y)} outside {box}')
    for (x, y) in ink_pts:
        px[x, y] = ink
    if shadow is not None:
        for (x, y) in ink_pts:
            for dx, dy in SHADOW_RULES[rule]:
                q = (x + dx, y + dy)
                if q not in ink_pts and x0 <= q[0] <= x1 and y0 <= q[1] <= y1:
                    px[q] = shadow


def check_rule(px, box, ink, shadow, bg):
    """Which shadow rule reproduces the box exactly (None if none does)."""
    x0, y0, x1, y1 = box
    pts, _ = ink_groups(px, box, ink)
    orig = {(x, y): px[x, y] for x in range(x0, x1 + 1) for y in range(y0, y1 + 1)}
    for name, offs in SHADOW_RULES.items():
        ok = True
        for q, v in orig.items():
            if q in pts:
                continue
            want_sh = any((q[0] - dx, q[1] - dy) in pts for dx, dy in offs)
            if want_sh and v != shadow or not want_sh and v == shadow:
                ok = False; break
        if ok:
            return name
    return None


class SpriteView:
    """Pixel access to one sprite frame of a sheet, in sprite coordinates.

    With 1D OAM mapping a sprite w x h tiles at tile `first` uses tiles
    first .. first + w*h - 1 row by row; the sheet may be narrower than the
    sprite, so one sprite row can be split over several sheet rows."""
    def __init__(self, sheet, first, wt, ht):
        self.s, self.first, self.wt, self.ht = sheet, first, wt, ht
        self.w, self.h = wt * 8, ht * 8

    def _map(self, q):
        x, y = q
        if not (0 <= x < self.w and 0 <= y < self.h):
            raise IndexError(q)
        t = self.first + (y // 8) * self.wt + x // 8
        return (t % self.s.tw) * 8 + x % 8, (t // self.s.tw) * 8 + y % 8

    def __getitem__(self, q):
        return self.s.px[self._map(q)]

    def __setitem__(self, q, v):
        self.s.px[self._map(q)] = v

    def image(self):
        im = Image.new('P', (self.w, self.h)); im.putpalette(self.s.im.getpalette())
        for y in range(self.h):
            for x in range(self.w):
                im.putpixel((x, y), self[x, y])
        return im


class ViewSheet:
    """Adapter so relabel() can work on a SpriteView."""
    def __init__(self, view, name):
        self.px, self.path = view, name


class StripView:
    """Several equal pieces stacked vertically in a PNG, shown side by side."""
    def __init__(self, sheet, piece_w, piece_h, count):
        self.s, self.pw, self.ph, self.n = sheet, piece_w, piece_h, count
        self.w, self.h = piece_w * count, piece_h

    def _map(self, q):
        x, y = q
        if not (0 <= x < self.w and 0 <= y < self.h):
            raise IndexError(q)
        return x % self.pw, (x // self.pw) * self.ph + y

    def __getitem__(self, q):
        return self.s.px[self._map(q)]

    def __setitem__(self, q, v):
        self.s.px[self._map(q)] = v


N4 = ((1, 0), (-1, 0), (0, 1), (0, -1))
N8 = tuple((dx, dy) for dx in (-1, 0, 1) for dy in (-1, 0, 1) if (dx, dy) != (0, 0))
RULES = dict(SHADOW_RULES, outline8=tuple(N8), outline4=N4,
             rd_outline=((1, 0), (0, 1), (1, 1), (-1, 0), (0, -1), (-1, -1), (1, -1), (-1, 1)))


class LearnedLabel:
    """A label in a custom pixel font, learnt from the English it replaces.

    ink: colours of the letter fill (may vary per row: a gradient), edge: colour
    of the shadow/outline drawn by `rule` around the ink, or None. Background is
    modelled per row (its most common other colour). `check()` re-renders the
    English with the learnt glyphs and fails unless every pixel matches."""
    def __init__(self, px, box, old, ink, edge, rule, extra=None, gap=None, space=None, bgfix=None):
        self.px, self.box, self.old = px, box, old
        self.ink, self.edge, self.rule = set(ink), edge, rule
        x0, y0, x1, y1 = box
        self.orig = {(x, y): px[x, y] for x in range(x0, x1 + 1) for y in range(y0, y1 + 1)}
        pts = {q for q, v in self.orig.items() if v in self.ink}
        cols = sorted({x for x, _ in pts})
        groups, cur = [], []
        for x in cols:
            if cur and x != cur[-1] + 1:
                groups.append(cur); cur = []
            cur.append(x)
        groups.append(cur)
        letters = [c for c in old if c != ' ']
        if len(groups) != len(letters):
            raise ValueError(f'{old!r}: {len(groups)} ink groups for {len(letters)} letters')
        self.top, bot = min(y for _, y in pts), max(y for _, y in pts)
        self.rows = range(self.top, bot + 1)
        self.glyphs = {}
        for g, c in zip(groups, letters):
            self.glyphs.setdefault(c, [''.join('#' if (x, y) in pts else '.' for x in range(g[0], g[-1] + 1))
                                       for y in self.rows])
        self.glyphs.update(extra or {})
        gaps, spaces, it = [], [], iter(range(len(groups) - 1))
        li = 0
        for i, c in enumerate(old):
            if c == ' ' or i + 1 >= len(old):
                continue
            if old[i + 1] == ' ':
                spaces.append(groups[li + 1][0] - groups[li][-1] - 1); li += 1
            else:
                gaps.append(groups[li + 1][0] - groups[li][-1] - 1); li += 1
        self.gap = gap if gap is not None else (max(set(gaps), key=gaps.count) if gaps else 1)
        self.space = space if space is not None else (spaces[0] if spaces else self.gap + 3)
        self.start = groups[0][0]
        self.rowink = {}
        for y in self.rows:
            vs = [self.orig[(x, y)] for x in range(x0, x1 + 1) if (x, y) in pts]
            if vs:
                self.rowink[y] = max(set(vs), key=vs.count)
        self.bg = {}
        for y in range(y0, y1 + 1):
            vs = [self.orig[(x, y)] for x in range(x0, x1 + 1)
                  if self.orig[(x, y)] not in self.ink and self.orig[(x, y)] != edge]
            self.bg[y] = (bgfix or {}).get(y, max(set(vs), key=vs.count) if vs else None)

    def width(self, text):
        w = 0
        for i, c in enumerate(text):
            if c == ' ':
                w += self.space - self.gap
                continue
            w += len(self.glyphs[c][0]) + (self.gap if i < len(text) - 1 else 0)
        return w

    def render(self, text, x):
        x0, y0, x1, y1 = self.box
        img = {}
        for q, v in self.orig.items():
            img[q] = self.bg[q[1]] if (v in self.ink or v == self.edge) else v
        ink = set()
        for i, c in enumerate(text):
            if c == ' ':
                x += self.space - self.gap
                continue
            for r, row in enumerate(self.glyphs[c]):
                for k, ch in enumerate(row):
                    if ch == '#':
                        ink.add((x + k, self.top + r))
            x += len(self.glyphs[c][0]) + self.gap
        for q in ink:
            if q not in img:
                raise ValueError(f'{text!r} does not fit in {self.box}')
        if self.edge is not None:
            for (qx, qy) in ink:
                for dx, dy in RULES[self.rule]:
                    q = (qx + dx, qy + dy)
                    if q in img and q not in ink:
                        img[q] = self.edge
        for q in ink:
            img[q] = self.rowink.get(q[1], next(iter(self.ink)))
        return img

    def check(self):
        img = self.render(self.old, self.start)
        bad = [q for q in img if img[q] != self.orig[q]]
        if bad:
            raise ValueError(f'{self.old!r}: model differs from the image at {len(bad)} pixels, e.g. {bad[:4]}')
        return self

    def write(self, text, align='center', x=None, width=None):
        x0, _, x1, _ = self.box
        w = self.width(text)
        if x is None:
            x = self.start if align == 'left' else x0 + ((width or (x1 - x0 + 1)) - w) // 2
        for q, v in self.render(text, x).items():
            self.px[q] = v
        return w


class TileGridView:
    """A label assembled from arbitrary tiles: rows of tile numbers, as a tilemap shows them."""
    def __init__(self, sheet, rows):
        self.s, self.rows = sheet, rows
        self.w, self.h = len(rows[0]) * 8, len(rows) * 8

    def _map(self, q):
        x, y = q
        if not (0 <= x < self.w and 0 <= y < self.h):
            raise IndexError(q)
        t = self.rows[y // 8][x // 8]
        return (t % self.s.tw) * 8 + x % 8, (t // self.s.tw) * 8 + y % 8

    def __getitem__(self, q):
        return self.s.px[self._map(q)]

    def __setitem__(self, q, v):
        self.s.px[self._map(q)] = v


def font_masks(font, text):
    """Ink masks of a game font's glyphs, rows relative to the cap top (accents above are negative)."""
    cap_top = min(j for j, row in enumerate(font.glyph('E')[0]) if 1 in row)
    out = {}
    for c in set(text) - {' '}:
        g, w = font.glyph(c)
        rows = [j for j, row in enumerate(g) if 1 in row]
        out[c] = (min(rows) - cap_top, [''.join('#' if v == 1 else '.' for v in g[j]) for j in range(min(rows), max(rows) + 1)], w)
    return out, font.glyph(' ')[1]


def restyle(px, box, text, font, ink, edge, rule, align='center', top=None, x=None, extra_gap=0, bg_rows=None):
    """Write `text` in a game font, coloured like the label it replaces.

    ink: letter colours in the old label; per row the most common one is reused
    (gradients survive). edge/rule: shadow or outline colour and how it is drawn
    around the ink. Background per row is the most common other colour, unless
    bg_rows gives it. Returns the text width."""
    x0, y0, x1, y1 = box
    ink = set(ink)
    orig = {(xx, yy): px[xx, yy] for xx in range(x0, x1 + 1) for yy in range(y0, y1 + 1)}
    pts = [q for q, v in orig.items() if v in ink]
    top = min(y for _, y in pts) if top is None else top
    rowink = {}
    for yy in range(y0, y1 + 1):
        vs = [orig[(xx, yy)] for xx in range(x0, x1 + 1) if orig[(xx, yy)] in ink]
        if vs:
            rowink[yy] = max(set(vs), key=vs.count)
    default_ink = max(set(orig[q] for q in pts), key=[orig[q] for q in pts].count)
    bg = {}
    for yy in range(y0, y1 + 1):
        vs = [orig[(xx, yy)] for xx in range(x0, x1 + 1) if orig[(xx, yy)] not in ink and orig[(xx, yy)] != edge]
        bg[yy] = (bg_rows or {}).get(yy, max(set(vs), key=vs.count) if vs else None)
    masks, space = font_masks(font, text)
    w = sum(space if c == ' ' else masks[c][2] + extra_gap for c in text) - extra_gap
    if x is None:
        x = x0 + ((x1 - x0 + 1) - w) // 2 if align == 'center' else x0
    new = set()
    cx = x
    for c in text:
        if c == ' ':
            cx += space; continue
        dy, rows, gw = masks[c]
        for r, row in enumerate(rows):
            for k, ch in enumerate(row):
                if ch == '#':
                    new.add((cx + k, top + dy + r))
        cx += gw + extra_gap
    for q in new:
        if q not in orig:
            raise ValueError(f'{text!r} ({w}px) does not fit in {box}: {q}')
    img = {q: (bg[q[1]] if (v in ink or v == edge) else v) for q, v in orig.items()}
    if edge is not None:
        for (qx, qy) in new:
            for dx, dy in RULES[rule]:
                q = (qx + dx, qy + dy)
                if q in img and q not in new:
                    img[q] = edge
    for q in new:
        img[q] = rowink.get(q[1], default_ink)
    for q, v in img.items():
        px[q] = v
    return w


class TileMapView:
    """Screen pixels of a tilemap region, read from and written to the sheet's tiles
    (flips honoured). Only use it where every tile is shown once (see usage)."""
    def __init__(self, sheet, ents, cx0, cy0, wc, hc, base=0, width=32):
        self.s, self.e, self.cx0, self.cy0, self.base, self.mw = sheet, ents, cx0, cy0, base, width
        self.w, self.h = wc * 8, hc * 8

    def _map(self, q):
        x, y = q
        if not (0 <= x < self.w and 0 <= y < self.h):
            raise IndexError(q)
        e = self.e[(self.cy0 + y // 8) * self.mw + self.cx0 + x // 8]
        t = (e & 0x3FF) - self.base
        tx, ty = x % 8, y % 8
        if e & 0x400: tx = 7 - tx
        if e & 0x800: ty = 7 - ty
        return (t % self.s.tw) * 8 + tx, (t // self.s.tw) * 8 + ty

    def __getitem__(self, q):
        return self.s.px[self._map(q)]

    def __setitem__(self, q, v):
        self.s.px[self._map(q)] = v


INK, SHADOW = 1, 2


def bar_label(view, body, text, font=None, align='center', x_left=None, border=None, cap_top=None):
    """Rewrite a FONT_NORMAL-style label (ink 1, shadow 2) on a bar, in place.

    The new text keeps the old centre (or left edge), moves a row down or up when
    an accent or a cedilla would leave the bar, and must fit in `body`.
    border: (rows, colour) outside the bar the English ink spills into."""
    font = font or Font('normal')
    x0, y0, x1, y1 = body
    if border:
        rows, colour = border
        for x in range(x0, x1 + 1):
            for y in rows:
                if view[x, y] in (INK, SHADOW):
                    view[x, y] = colour
    pts = [(x, y) for x in range(x0, x1 + 1) for y in range(y0, y1 + 1) if view[x, y] == INK]
    if not pts:
        raise ValueError(f'no label in {body}')
    old_l, old_r = min(x for x, _ in pts), max(x for x, _ in pts)
    cap_top = min(y for _, y in pts) if cap_top is None else cap_top
    vs = [view[x, y] for x in range(x0, x1 + 1) for y in range(cap_top, cap_top + 9) if view[x, y] not in (INK, SHADOW)]
    bg = max(set(vs), key=vs.count)
    for x in range(x0, x1 + 1):
        for y in range(y0, y1 + 1):
            if view[x, y] in (INK, SHADOW):
                view[x, y] = bg
    glyphs = [font.glyph(c) for c in text]
    rows = [j for g, _ in glyphs for j, r in enumerate(g) if 1 in r]
    w = sum(gw for _, gw in glyphs)
    y = cap_top - 3                      # FONT_NORMAL/NARROW capitals start at glyph row 3
    y = max(y, y0 - min(rows))           # accents inside the bar
    y = min(y, y1 - max(rows))           # cedillas inside the bar
    if align == 'left':
        x = old_l if x_left is None else x_left
    else:
        x = round((old_l + old_r + 1) / 2 - w / 2)
    if x < x0 or x + w - 1 > x1 + 1:
        raise ValueError(f'{text!r} ({w}px) does not fit in {body}')
    for g, gw in glyphs:
        for j in range(16):
            for i in range(gw):
                v = g[j][i]
                q = (x + i, y + j)
                if v in (1, 2) and x0 <= q[0] <= x1 and y0 <= q[1] <= y1:
                    view[q] = INK if v == 1 else SHADOW
        x += gw
    return w

