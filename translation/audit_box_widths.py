#!/usr/bin/env python3
"""Pixel-width audit against the REAL window widths and fonts.

Limits derived from the window templates that draw each kind of text:
  bag item description  WIN_DESCRIPTION w=14 (112px), x=3, FONT_NORMAL -> 109
  ability description   PSS_LABEL_PANE_RIGHT w=19 (152px), x=8, FONT_NORMAL -> 144
  battle message        B_WIN_MSG w=26 (208px), FONT_NORMAL -> 208
  overworld/UI msgbox   standard text box w=26 (208px), FONT_NORMAL -> 208
  map/event scripts     sStandardTextBox w=27 (216px), x=0, FONT_NORMAL -> 216
                        (Battle Dome info card w=26 -> 208)

For .inc scripts every rendered line (split on \n, \l, \p) of every changed
message is measured. Placeholders such as {PLAYER} or {STR_VAR_1} are counted
as zero width, so a reported overflow is certain, not an estimate.

Only strings this branch actually changed are checked, so untouched English text
never shows up as a failure.

Usage:
    python3 translation/audit_box_widths.py            # summary, exits 1 if any overflow
    python3 translation/audit_box_widths.py -v         # list every overflowing string
    python3 translation/audit_box_widths.py dump FILE  # write JSON for scripted fixing
"""
import sys, os, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import re, subprocess
from width_audit import blocks, orig, line_widths, encode, W_NORMAL, ROOT

CFG = [
    ('src/data/text/item_descriptions.h', 109, W_NORMAL, False, 'bag description'),
    ('src/data/text/abilities.h',         144, W_NORMAL, False, 'ability description'),
    ('src/battle_message.c',              208, W_NORMAL, False, 'battle message'),
    ('src/strings.c',                     208, W_NORMAL, False, 'UI / msgbox'),
]

INC_LIMIT = 216
INC_LIMITS = {'data/text/battle_dome.inc': 208}


def inc_lines(text):
    """Rendered lines of every message in an .inc file, grouped by label so an
    unterminated message never runs into the next one."""
    msgs, cur = [], ''
    for line in text.split('\n'):
        if re.match(r'^\S.*:', line) and cur:
            msgs.append(cur)
            cur = ''
        cur += ''.join(re.findall(r'\.string\s+"((?:[^"\\]|\\.)*)"', line))
    if cur:
        msgs.append(cur)
    return [l for m in msgs for l in re.split(r'\\[nlp]|\$', m) if l.strip()]


GENDER = re.compile(r'\{MASC\}(.*?)\{FEM\}(.*?)\{ENDG\}')


def gender_variants(line):
    """Both renderings of a {MASC}m{FEM}f{ENDG} line (one if it has none)."""
    return [GENDER.sub(r'\1', line), GENDER.sub(r'\2', line)]


def text_width(line):
    """Pixel width with placeholders ({PLAYER}, {STR_VAR_1}, ...) counted as 0.
    Gendered text is measured on its wider branch."""
    def width(l):
        l = re.sub(r'\{[^}]*\}', '', l)
        return sum(W_NORMAL[b] for b in encode(l) if b < len(W_NORMAL))
    return max(width(v) for v in gender_variants(line))


def audit_inc(report=True):
    files = subprocess.run(['git', 'diff', '--name-only', 'main..HEAD', '--', '*.inc'],
                           capture_output=True, text=True, cwd=ROOT).stdout.split()
    over = []
    for path in files:
        limit = INC_LIMITS.get(path, INC_LIMIT)
        old = set(inc_lines(orig(path)))
        for l in inc_lines(open(f'{ROOT}/{path}', encoding='utf-8').read()):
            if l not in old and text_width(l) > limit:
                over.append((text_width(l), path, l))
    over.sort(reverse=True)
    if report:
        print(f'{"*.inc (" + str(len(files)) + " files)":38s} limit {INC_LIMIT:3d}px  {"map/event script":20s} overflowing: {len(over)}')
    return over


def audit(report=True):
    out = {}
    for path, limit, widths, asm, label in CFG:
        new = blocks(open(f'{ROOT}/{path}', encoding='utf-8', errors='replace').read(), asm)
        old = blocks(orig(path), asm)
        over = []
        for a, b in zip(old, new):
            if a == b:
                continue
            w = max(line_widths(b, widths))
            if w > limit:
                over.append((w, b))
        over.sort(reverse=True)
        out[path] = (limit, label, over)
        if report:
            print(f'{path:38s} limit {limit:3d}px  {label:20s} overflowing: {len(over)}')
    return out

if __name__ == '__main__':
    args = sys.argv[1:]
    res = audit()
    inc = audit_inc()
    total = sum(len(v[2]) for v in res.values()) + len(inc)
    print(f'\nTOTAL OVERFLOWING: {total}')

    if args and args[0] == '-v':
        for path, (limit, label, over) in res.items():
            if not over:
                continue
            print(f'\n== {path}  (limit {limit}px, {label}) ==')
            for w, s in over:
                print(f'  {w:4d}px  {s!r}')
        if inc:
            print(f'\n== *.inc  (limit {INC_LIMIT}px, map/event script) ==')
            for w, path, s in inc:
                print(f'  {w:4d}px  {path}  {s!r}')
    elif args and args[0] == 'dump':
        dest = args[1] if len(args) > 1 else 'box_overflow.json'
        data = {p: [[w, s] for w, s in v[2]] for p, v in res.items()}
        for w, path, s in inc:
            data.setdefault(path, []).append([w, s])
        json.dump(data,
                  open(dest, 'w', encoding='utf-8'), ensure_ascii=False, indent=0)
        print(f'dumped -> {dest}')

    sys.exit(1 if total else 0)
