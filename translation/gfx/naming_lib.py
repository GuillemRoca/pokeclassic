"""Pixel rules of the naming-screen labels, checked against the originals."""
N8 = [(dx, dy) for dx in (-1, 0, 1) for dy in (-1, 0, 1) if (dx, dy) != (0, 0)]

def ink_of(px, box, inkset):
    x0, y0, x1, y1 = box
    return {(x, y) for y in range(y0, y1 + 1) for x in range(x0, x1 + 1) if px[x, y] in inkset}

def render_halo(ink, box, ink_v, halo_v, fill_v, keep=None):
    """ink pixels ink_v, their 8-neighbours halo_v, the rest fill_v (inside box)."""
    x0, y0, x1, y1 = box; out = {}
    for y in range(y0, y1 + 1):
        for x in range(x0, x1 + 1):
            if (x, y) in ink: out[(x, y)] = ink_v if keep is None else keep.get((x, y), ink_v)
            elif any((x + dx, y + dy) in ink for dx, dy in N8): out[(x, y)] = halo_v
            else: out[(x, y)] = fill_v
    return out

def render_shadow(ink, box, ink_v, sh_v, bg_v):
    x0, y0, x1, y1 = box; out = {}
    for y in range(y0, y1 + 1):
        for x in range(x0, x1 + 1):
            if (x, y) in ink: out[(x, y)] = ink_v
            elif any((x - dx, y - dy) in ink for dx, dy in ((1, 0), (0, 1), (1, 1))): out[(x, y)] = sh_v
            else: out[(x, y)] = bg_v
    return out

def text_ink(glyphs, text, x, y, adv_extra=1):
    ink = set()
    for ch in text:
        if ch == ' ':
            x += 2; continue
        g = glyphs[ch]
        for r, row in enumerate(g):
            for c, v in enumerate(row):
                if v == '#': ink.add((x + c, y + r))
        x += len(g[0]) + adv_extra
    return ink

def width(glyphs, text, adv_extra=1):
    return sum(2 if ch == ' ' else len(glyphs[ch][0]) + adv_extra for ch in text) - adv_extra
