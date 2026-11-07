#!/usr/bin/env python3
"""Redraw the 'Lv' glyphs (0x34 {LV}, 0x105 {LV_2}) as 'Nv' (nivell) in every latin font.

Pieces come from the same font where possible (the N of the 'No' glyph 0x108 or of
the letter N 0xC8, the v of the old Lv glyph). Writes the PNGs and prints the new widths.
Index meaning: 0 outside, 1 ink, 2 shadow, 3 cell background.
"""
import sys, re
from PIL import Image
BG, INK, SH = 3, 1, 2

def cell(im, g):
    x, y = (g % 16) * 16, (g // 16) * 16
    return [[im.getpixel((x + xx, y + yy)) for xx in range(16)] for yy in range(16)]

def put(im, g, c):
    x, y = (g % 16) * 16, (g // 16) * 16
    for yy in range(16):
        for xx in range(16):
            im.putpixel((x + xx, y + yy), c[yy][xx])

def blank(old, width):
    """Same rows as the old cell (keeps its 0/3 row pattern), background up to width."""
    out = []
    for row in old:
        rowbg = BG if BG in row[:max(1, width)] or INK in row or SH in row else row[0]
        out.append([rowbg if x < width else 0 for x in range(16)])
    return out

def paste(dst, src, sx0, sx1, dx, rows=range(16), skip=()):
    for y in rows:
        for i, sx in enumerate(range(sx0, sx1 + 1)):
            if (sx, y) in skip:
                continue
            v = src[y][sx]
            if v in (INK, SH):
                dst[y][dx + i] = v

def shade(mask_rows, top):
    """Ink pixels from strings, shadows right / below / below-right (the font's rule for straight strokes)."""
    pts = {(x, top + y) for y, r in enumerate(mask_rows) for x, ch in enumerate(r) if ch == '#'}
    out = {}
    for (x, y) in pts:
        for d in ((1, 0), (0, 1), (1, 1)):
            q = (x + d[0], y + d[1])
            if q not in pts:
                out[q] = SH
    out.update({p: INK for p in pts})
    return out

def main(ROOT):
  FONTS = {'normal': 'Normal', 'small': 'Small', 'narrow': 'Narrow', 'short': 'Short', 'small_narrow': 'SmallNarrow'}
  widths = {}
  for f in FONTS:
      path = f'{ROOT}/graphics/fonts/latin_{f}.png'
      im = Image.open(path)
      lv, lv2, no, n = cell(im, 0x34), cell(im, 0x105), cell(im, 0x108), cell(im, 0xC8)
      if f == 'normal':
          # LV_2 (thin): N of 'No' (cols 0-5) + v of Lv_2 (cols 5-8)
          c = blank(lv2, 10); paste(c, no, 0, 5, 0); paste(c, lv2, 5, 8, 6, rows=range(8, 16))
          put(im, 0x105, c); widths[(f, 0x105)] = 10
          # LV (bold, left strokes doubled like the old L and v): drawn N + bold v (cols 4-8)
          c = blank(lv, 11)
          for (x, y), v in shade(['##..#', '###.#', '#####', '##.##', '##..#', '##..#'], 6).items():
              c[y][x] = v
          paste(c, lv, 4, 8, 6, rows=range(8, 16), skip={(4, 12)})
          put(im, 0x34, c); widths[(f, 0x34)] = 11
      elif f in ('small', 'small_narrow'):
          c = blank(lv2, 9); paste(c, n, 0, 4, 0); paste(c, lv2, 4, 7, 5, rows=range(7, 16))
          put(im, 0x34, c); put(im, 0x105, c); widths[(f, 0x34)] = widths[(f, 0x105)] = 9
      elif f == 'narrow':
          c = blank(lv2, 10); paste(c, no, 0, 5, 0); paste(c, lv2, 4, 7, 6, rows=range(8, 16))
          put(im, 0x34, c); put(im, 0x105, c); widths[(f, 0x34)] = widths[(f, 0x105)] = 10
      elif f == 'short':
          c = blank(lv2, 10); paste(c, no, 0, 5, 0)
          for (x, y), v in {**shade(['#.#', '#.#', '#.#', '#.#', '.#.'], 6)}.items():
              c[y][x + 6] = v
          put(im, 0x34, c); put(im, 0x105, c); widths[(f, 0x34)] = widths[(f, 0x105)] = 10
      im.save(path)
  for (f, g), w in sorted(widths.items()):
      print(f, hex(g), w)


if __name__ == '__main__':
    main(sys.argv[1])
