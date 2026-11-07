#!/usr/bin/env python3
"""Find English left in the translated text.

Every word of every translated string literal (`.string "..."` in data/,
`_("...")` in src/) is checked with hunspell: a word is reported when the
English dictionary accepts it and the Catalan one does not. Words listed in
english_allowlist.txt (names, interjections, abbreviations, accepted loanwords,
each reviewed by hand) are not reported, nor are Pokémon species and trainer
names, which stay as they are by design.

Not checked: name tables kept in English on purpose (species, trainers,
Frontier/contest opponents, credits, in-game trade OTs), the debug menus, and
the inactive 12-character `#else` blocks of move_names.h / abilities.h.

Requires hunspell with the `ca` and `en_US` dictionaries
(apt install hunspell hunspell-ca hunspell-en-us).

Usage:
    python3 translation/check_english.py        # exits 1 if anything new is found
    python3 translation/check_english.py -v     # also list allowlisted hits
"""
import os, re, shutil, subprocess, sys, collections
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HERE = os.path.dirname(os.path.abspath(__file__))

SKIP = ('src/battle_debug.c', 'src/debug.c', 'src/data/trainers.h', 'src/data/text/species_names.h',
        'src/data/battle_frontier/', 'src/data/contest_opponents.h', 'src/data/credits.h',
        'src/data/trade.h', 'src/text_input_strings.c', 'src/naming_screen.c')
# files whose second (#else) table is not compiled
DEAD_ELSE = ('src/data/text/move_names.h', 'src/data/text/abilities.h')

STR_ASM = re.compile(r'^\s*\.string\s+"((?:[^"\\]|\\.)*)"', re.M)
STR_C = re.compile(r'(?:_|__|COMPOUND_STRING)\(\s*((?:"(?:[^"\\]|\\.)*"\s*)+)\)')
CTRL = re.compile(r'\{[^}]*\}|\\[nlpc]|\$')
WORD = re.compile(r"[A-Za-zÀ-ÿ·]+")


def strings(rel, text):
    if rel.endswith(DEAD_ELSE):
        text = text.split('#else')[0] + text[text.find('#endif'):] if '#else' in text else text
    if rel.endswith(('.inc', '.s')):
        return STR_ASM.findall(text)
    return [''.join(re.findall(r'"((?:[^"\\]|\\.)*)"', m)) for m in STR_C.findall(text)]


def hunspell_rejects(dic, words):
    out = subprocess.run(['hunspell', '-d', dic, '-l'], input='\n'.join(words),
                         capture_output=True, text=True)
    if out.returncode != 0:
        sys.exit(f'error: hunspell -d {dic} failed: {out.stderr.strip()}')
    return set(out.stdout.split())


def main():
    if not shutil.which('hunspell'):
        sys.exit('error: hunspell not found (apt install hunspell hunspell-ca hunspell-en-us)')
    files = subprocess.run(['git', 'ls-files', 'data', 'src'], capture_output=True, text=True,
                           cwd=ROOT).stdout.split()
    files = [f for f in files if f.endswith(('.inc', '.s', '.c', '.h')) and not f.startswith(SKIP)]
    occ = collections.defaultdict(list)
    for rel in files:
        text = open(os.path.join(ROOT, rel), encoding='utf-8', errors='replace').read()
        for s in strings(rel, text):
            for w in WORD.findall(CTRL.sub(' ', s).replace("'", ' ')):
                if len(w) >= 2:
                    occ[w].append((rel, s))
    names = set()
    for rel in ('src/data/text/species_names.h', 'src/data/trainers.h'):
        for m in re.finditer(r'_\("([^"]*)"\)', open(os.path.join(ROOT, rel), encoding='utf-8').read()):
            names.update(w.lower() for w in WORD.findall(m.group(1)))
    allow = set()
    for line in open(os.path.join(HERE, 'english_allowlist.txt'), encoding='utf-8'):
        line = line.split('#')[0].strip()
        if line:
            allow.add(line)
    words = sorted(occ)
    not_ca = hunspell_rejects('ca', words)
    # a capitalised word is Catalan if its lowercase form is (sentence-initial words)
    lower_rejected = hunspell_rejects('ca', sorted({w.lower() for w in not_ca}))
    not_ca = {w for w in not_ca if w.lower() in lower_rejected}
    not_en = hunspell_rejects('en_US', words)
    hits = [w for w in not_ca if w not in not_en and w.lower() not in names and not w.isupper()]
    new = sorted((w for w in hits if w not in allow), key=lambda w: -len(occ[w]))
    for w in new:
        rel, s = occ[w][0]
        print(f'{len(occ[w]):4} {w:16} {rel} :: {s[:90]!r}')
    if '-v' in sys.argv:
        print(f'\nallowlisted: {", ".join(sorted(w for w in hits if w in allow))}')
    print(f'\n{len(words)} distinct words checked; {len(hits)} English-only words, '
          f'{len(hits) - len(new)} allowlisted, {len(new)} new.')
    sys.exit(1 if new else 0)


if __name__ == '__main__':
    main()
