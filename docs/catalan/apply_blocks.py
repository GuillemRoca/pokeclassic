#!/usr/bin/env python3
"""Apply translations to _( "..." "..." ) blocks that span multiple string
literals (move/ability/item descriptions).

Keys in T are the *joined* English text, with escape sequences left verbatim
(so "\\n" appears as backslash-n, two characters).

Modes:
  dump  <file> [...]   -> print joined English strings, one per line (repr)
  apply <mapfile>      -> translate
"""
import re, sys, os, importlib.util, json

ROOT = os.environ.get('POKECLASSIC_ROOT', os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

# _( optional-ws  ("..." ws)+  optional-ws )
BLOCK = re.compile(r'_\(\s*((?:"(?:[^"\\]|\\.)*"\s*)+)\)')
LIT = re.compile(r'"((?:[^"\\]|\\.)*)"')


def join_block(body):
    return ''.join(LIT.findall(body))


def emit(cat, indent):
    """Render Catalan text back as C string literal(s), splitting on \\n."""
    parts = cat.split('\\n')
    if len(parts) == 1:
        return '_("%s")' % cat
    pad = ' ' * indent
    out = ['_(']
    for i, p in enumerate(parts):
        tail = '\\n' if i < len(parts) - 1 else ''
        out.append('\n%s    "%s%s"' % (pad, p, tail))
    out.append(')')
    return ''.join(out)


def dump(files):
    seen = []
    s = set()
    for f in files:
        src = open(os.path.join(ROOT, f), encoding='utf-8').read()
        for mo in BLOCK.finditer(src):
            j = join_block(mo.group(1))
            if j not in s:
                s.add(j)
                seen.append(j)
    for j in seen:
        print(json.dumps(j, ensure_ascii=False))


def apply(mapfile):
    spec = importlib.util.spec_from_file_location('tm', mapfile)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    T = m.T
    hit = miss = 0
    missed = []
    for f in m.FILES:
        full = os.path.join(ROOT, f)
        src = open(full, encoding='utf-8').read()

        def repl(mo):
            nonlocal hit, miss
            j = join_block(mo.group(1))
            if j in T:
                hit += 1
                # indentation of the line this block starts on
                ls = src.rfind('\n', 0, mo.start()) + 1
                indent = len(src[ls:mo.start()]) - len(src[ls:mo.start()].lstrip())
                return emit(T[j], indent)
            miss += 1
            missed.append(j)
            return mo.group(0)

        out = BLOCK.sub(repl, src)
        if out != src:
            open(full, 'w', encoding='utf-8').write(out)
    tot = hit + miss
    print(f'translated {hit}/{tot} blocks ({100*hit/max(tot,1):.1f}%)')
    if missed:
        print(f'UNTRANSLATED: {len(missed)}')
        d = os.path.join(os.path.dirname(mapfile), 'missed_multi.json')
        json.dump(missed, open(d, 'w'), ensure_ascii=False, indent=1)
        print('  -> ' + d)
        for s in missed[:20]:
            print('   ' + json.dumps(s, ensure_ascii=False)[:120])


if __name__ == '__main__':
    if sys.argv[1] == 'dump':
        dump(sys.argv[2:])
    else:
        apply(sys.argv[2])
