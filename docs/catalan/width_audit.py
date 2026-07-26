#!/usr/bin/env python3
"""Measure the real rendered pixel width of translated strings using the
game's own glyph-width tables, and flag lines that overflow their text box."""
import re, subprocess, sys, os

ROOT = os.environ.get('POKECLASSIC_ROOT', os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

# ---- charmap: text -> byte ----
def load_charmap():
    cm = {}
    for line in open(f'{ROOT}/charmap.txt', encoding='utf-8'):
        line = line.split('@')[0].strip()
        m = re.match(r"^'(.)'\s*=\s*([0-9A-Fa-f]{2})\s*$", line)
        if m:
            cm[m.group(1)] = int(m.group(2), 16); continue
        m = re.match(r'^(\S+)\s*=\s*((?:[0-9A-Fa-f]{2}\s*)+)$', line)
        if m and not m.group(1).startswith("'"):
            cm[m.group(1)] = [int(b, 16) for b in m.group(2).split()]
    return cm
CM = load_charmap()

# ---- glyph widths ----
def load_widths(name):
    t = open(f'{ROOT}/src/fonts.c', encoding='utf-8').read()
    m = re.search(re.escape(name) + r'\[\]\s*=\s*\{(.*?)\};', t, re.S)
    vals = [int(x) for x in re.findall(r'\b(\d+)\b', m.group(1))]
    return vals
W_NORMAL = load_widths('gFontNormalLatinGlyphWidths')
W_NARROW = load_widths('gFontNarrowLatinGlyphWidths')
W_SHORT  = load_widths('gFontShortLatinGlyphWidths')

def encode(s):
    """Encode ROM text to bytes; {TOKENS} and escapes resolved via charmap."""
    out, i = [], 0
    while i < len(s):
        if s[i] == '{':
            j = s.index('}', i)
            tok = s[i+1:j]
            key = tok.split()[0]
            v = CM.get(tok, CM.get(key))
            if v is None: out.append(0x00)          # unknown control code: ignore
            elif isinstance(v, list): out.extend(v)
            else: out.append(v)
            i = j + 1
        elif s[i] == '\\':
            nxt = s[i+1]
            out.append({'n': 0xFE, 'l': 0xFA, 'p': 0xFB}.get(nxt, 0x00))
            i += 2
        else:
            v = CM.get(s[i])
            if isinstance(v, list): out.extend(v)
            elif v is not None: out.append(v)
            i += 1
    return out

def line_widths(s, widths, spacing=0):
    """Return the pixel width of each rendered line."""
    res, cur = [], 0
    for b in encode(s):
        if b in (0xFE, 0xFA, 0xFB):   # newline / scroll / paragraph
            res.append(cur); cur = 0
        elif b < len(widths):
            cur += widths[b] + spacing
    res.append(cur)
    return res

# ---- what to audit: (file, max px, font, label) ----
# widths derived from the window templates that draw each kind of text
TARGETS = [
    ('src/data/text/item_descriptions.h', 120, W_NARROW, 'item description (bag, narrow font)'),
    ('src/data/text/abilities.h',         208, W_NORMAL, 'ability desc / name'),
    ('src/data/items.h',                  208, W_NORMAL, 'item name'),
    ('src/data/text/move_names.h',        208, W_NORMAL, 'move name'),
    ('src/strings.c',                     208, W_NORMAL, 'UI string'),
    ('src/battle_message.c',              208, W_NORMAL, 'battle message'),
]

def blocks(t, asm):
    if asm: return re.findall(r'\.string\s+"((?:[^"\\]|\\.)*)"', t)
    return [''.join(re.findall(r'"((?:[^"\\]|\\.)*)"', b))
            for b in re.findall(r'_\(\s*((?:"(?:[^"\\]|\\.)*"\s*)+)\)', t)]

def orig(p):
    return subprocess.run(['git','show',f'main:{p}'],capture_output=True,text=True).stdout

changed = subprocess.run(['git','diff','--name-only','main..HEAD'],
                         capture_output=True,text=True).stdout.split()

print(f'{"file":38s} {"strings":>7s} {"over":>5s}  worst')
for path, limit, widths, label in TARGETS:
    if path not in changed: continue
    asm = path.endswith('.inc')
    new = blocks(open(f'{ROOT}/{path}',encoding='utf-8',errors='replace').read(), asm)
    old = blocks(orig(path), asm)
    over = []
    for a,b in zip(old,new):
        if a == b: continue
        # compare against the English original's own worst line: only flag if we
        # exceed the box, and report how the English compared
        wn = max(line_widths(b, widths))
        wo = max(line_widths(a, widths))
        if wn > limit:
            over.append((wn, wo, b))
    over.sort(reverse=True)
    worst = f'{over[0][0]}px (EN {over[0][1]}px)' if over else '-'
    print(f'{path:38s} {len(new):7d} {len(over):5d}  {worst}')
    for wn, wo, b in over[:6]:
        print(f'      {wn:4d}px (EN {wo:4d}px)  {b!r}')
