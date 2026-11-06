#!/usr/bin/env python3
"""Pixel-width audit for script dialogue (data/**/*.inc, data/**/*.s).

audit_box_widths.py covers four C files with known windows. Map scripts and the
shared data/text/*.inc files are most of the game's text, and almost all of it
is drawn in the standard overworld message box, so this checks every rendered
line of every *translated* script string against that box.

Box: sStandardTextBox_WindowTemplates is 27 tiles = 216px wide. The project
target is 208px (26 tiles, same as the battle box) to leave a margin; lines
between 208 and 216 px still render, so they are reported separately as
"tight" and do not fail the check.

Placeholders are measured with representative text: {PLAYER}/{RIVAL} as a
7-character name, {STR_VAR_n} as a 9-character species name. A line that only
overflows because of a long placeholder is still worth a look, since the game
does not wrap.

Only strings that differ from the English base are checked (see width_audit.base_ref).

Usage:
    python3 translation/audit_script_widths.py           # summary; exits 1 on overflow
    python3 translation/audit_script_widths.py -v        # list every line over 208px
    python3 translation/audit_script_widths.py -v PATH   # only files under PATH
"""
import os, re, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from width_audit import line_widths, orig, W_NORMAL, ROOT

LIMIT, HARD = 208, 216
SUB = {
    '{PLAYER}': 'Jugador', '{RIVAL}': 'Jugador', '{B_PLAYER_NAME}': 'Jugador',
    '{STR_VAR_1}': 'Bulbasaur', '{STR_VAR_2}': 'Bulbasaur', '{STR_VAR_3}': 'Bulbasaur',
    '{KUN}': '',
}
STR_RE = re.compile(r'^\s*\.string\s+"((?:[^"\\]|\\.)*)"')
LABEL_RE = re.compile(r'^\s*([A-Za-z_][A-Za-z0-9_]*)::?')

# Strings drawn somewhere other than the standard message box.
# label prefix -> (limit px, why)
WINDOWS = {
    'BattleDome_Text_Potential': (None, 'Dome tourney info window, measured separately'),
    'BattleDome_Text_Style': (None, 'Dome tourney info window, measured separately'),
    'BattleDome_Text_TrainerWon': (None, 'Dome tourney info window, measured separately'),
}


def labelled_strings(text):
    """{label: [string, ...]} -- one entry per `$`-terminated message."""
    out, label, buf = {}, None, ''
    for line in text.splitlines():
        m = STR_RE.match(line)
        if m:
            buf += m.group(1)
            while '$' in buf:
                msg, buf = buf.split('$', 1)
                out.setdefault(label, []).append(msg)
            continue
        lm = LABEL_RE.match(line)
        if lm:
            if buf:
                out.setdefault(label, []).append(buf); buf = ''
            label = lm.group(1)
    if buf:
        out.setdefault(label, []).append(buf)
    return out


def widths(s):
    for k, v in SUB.items():
        s = s.replace(k, v)
    return line_widths(s, W_NORMAL)


def lines(s):
    return re.split(r'\\[nlp]', s)


def script_files(under):
    """Tracked script files only: build products such as layouts.inc are skipped."""
    out = subprocess.run(['git', 'ls-files', '--', under], capture_output=True,
                         text=True, cwd=ROOT).stdout.split()
    return [f for f in out if f.endswith(('.inc', '.s'))]


def audit(under='data'):
    over, tight = [], []
    for rel in sorted(script_files(under)):
        new = labelled_strings(open(os.path.join(ROOT, rel), encoding='utf-8', errors='replace').read())
        old = labelled_strings(orig(rel))
        for label, msgs in new.items():
            if label and any(label.startswith(p) for p in WINDOWS):
                continue
            en = old.get(label, [])
            for i, msg in enumerate(msgs):
                if i < len(en) and en[i] == msg:
                    continue  # untranslated / unchanged
                for ln, w in zip(lines(msg), widths(msg)):
                    if w > HARD:
                        over.append((rel, label, w, ln))
                    elif w > LIMIT:
                        tight.append((rel, label, w, ln))
    return over, tight


if __name__ == '__main__':
    args = sys.argv[1:]
    verbose = '-v' in args
    paths = [a for a in args if a != '-v'] or ['data']
    over, tight = [], []
    for p in paths:
        o, t = audit(p)
        over += o; tight += t
    if verbose:
        for tag, rows in (('OVER', over), ('TIGHT', tight)):
            for rel, label, w, ln in sorted(rows, key=lambda r: -r[2]):
                print(f'{tag:5s} {w:4d}px  {rel} [{label}]  {ln!r}')
        print()
    print(f'lines over {HARD}px (overflow): {len(over)}')
    print(f'lines {LIMIT + 1}-{HARD}px (tight, renders): {len(tight)}')
    sys.exit(1 if over else 0)
