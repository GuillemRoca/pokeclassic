#!/usr/bin/env python3
"""Apply a Catalan translation map to pokeclassic source files.

Usage: apply.py <mapfile.py>
The map file must define:
    FILES = [list of paths]
    T = {english: catalan, ...}
Reports coverage and any untranslated strings.
"""
import re, sys, os, importlib.util, json

ROOT = os.environ.get('POKECLASSIC_ROOT', os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

# Matches the string literal inside _("...") or .string "..."
PAT_C = re.compile(r'_\("((?:[^"\\]|\\.)*)"\)')
PAT_ASM = re.compile(r'(\.string\s+")((?:[^"\\]|\\.)*)(")')


def load_map(path):
    spec = importlib.util.spec_from_file_location('tmap', path)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def apply_to_file(path, T, stats, kind):
    full = os.path.join(ROOT, path)
    src = open(full, encoding='utf-8').read()
    missed = []

    def repl_c(mo):
        en = mo.group(1)
        if en in T:
            stats['hit'] += 1
            return '_("%s")' % T[en]
        stats['miss'] += 1
        missed.append(en)
        return mo.group(0)

    def repl_asm(mo):
        en = mo.group(2)
        if en in T:
            stats['hit'] += 1
            return mo.group(1) + T[en] + mo.group(3)
        stats['miss'] += 1
        missed.append(en)
        return mo.group(0)

    if kind == 'asm':
        out = PAT_ASM.sub(repl_asm, src)
    else:
        out = PAT_C.sub(repl_c, src)

    if out != src:
        open(full, 'w', encoding='utf-8').write(out)
    return missed


def main():
    mapfile = sys.argv[1]
    m = load_map(mapfile)
    T = m.T
    kind = getattr(m, 'KIND', 'c')
    stats = {'hit': 0, 'miss': 0}
    all_missed = {}
    for f in m.FILES:
        missed = apply_to_file(f, T, stats, kind)
        if missed:
            all_missed[f] = missed
    total = stats['hit'] + stats['miss']
    print(f"translated {stats['hit']}/{total} string literals"
          f" ({100*stats['hit']/max(total,1):.1f}%)")
    if all_missed:
        n = sum(len(v) for v in all_missed.values())
        print(f"UNTRANSLATED: {n}")
        dump = os.path.join(os.path.dirname(mapfile), 'missed.json')
        json.dump(all_missed, open(dump, 'w'), ensure_ascii=False, indent=1)
        print('  -> ' + dump)
        for f, v in all_missed.items():
            print(f'  {f}: {len(v)}')
            for s in v[:15]:
                print('     ' + s[:110])


if __name__ == '__main__':
    main()
