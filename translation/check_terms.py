#!/usr/bin/env python3
"""Check that every message uses the agreed Catalan name for the things it mentions.

English -> Catalan pairs come from the game's own tables, so the check follows
the translation instead of a hand-kept list:
  - item names        src/data/items.h
  - move names        src/data/text/move_names.h  (compiled block)
  - ability names     src/data/text/abilities.h   (compiled block)
  - region-map names  src/data/region_map/region_map_entries.h
plus the glossary's fixed terms (TERMS below).

For every translated message (a label in data/, a symbol in src/) whose English
text contains an English name, the Catalan text must contain the Catalan name.
Matching ignores case, line breaks and the final period of abbreviations.
Reviewed exceptions (a message that legitimately paraphrases, or a name the
English uses in another sense) live in terms_exceptions.txt as
`file|label|english name`.

Usage:
    python3 translation/check_terms.py        # exits 1 on any unexplained mismatch
    python3 translation/check_terms.py -v     # also print the pairs in use
"""
import os, re, subprocess, sys, collections
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HERE = os.path.dirname(os.path.abspath(__file__))

# Glossary terms not covered by a table: (English regex, Catalan regex, description).
TERMS = [
    (r'\bPok[ée] ?Mart\b', r'Botiga Pokémon|Botiga', 'Poké Mart'),
    (r'\bPok[ée]mon Cent(er|re)\b', r'Centre Pokémon|Centre', 'Pokémon Center'),
    (r'\bTeam Rocket\b', r'Equip Rocket', 'Team Rocket'),
    (r'\bElite Four\b', r'Alt Comandament', 'Elite Four'),
    (r'\bGym Leader\b', r'Líder', 'Gym Leader'),
    (r'\bBadge\b', r'Medall', 'Badge'),
    (r'\bPok[ée]dex\b', r'Pokédex', 'Pokédex'),
    (r'\bPok[ée] ?Nav\b|\bPok[ée]Gear\b', r'PokéGear|DexNav', 'PokéNav/PokéGear'),
    (r'\bSilph Co\b', r'Silph S\.A\.', 'Silph Co.'),
    (r'\bS\.?S\.? Anne\b', r'SS Anna', 'S.S. Anne'),
    (r'\bGame Corner\b', r'Sala de Jocs', 'Game Corner'),
    (r'\bCycling Road\b', r'Carril Bici', 'Cycling Road'),
    (r'\bBattle Frontier\b', r'Frontera de Combat|Frontera', 'Battle Frontier'),
    (r'\bBattle Tower\b', r'Torre de Combat|Torre', 'Battle Tower'),
    (r'\bTrainer Tips\b', r"Consells d'Entrenador", 'Trainer Tips'),
    (r'\bHall of Fame\b', r'Saló de la Fama', 'Hall of Fame'),
    (r'\bDay ?Care\b', r'Guarderia', 'Day Care'),
    (r'\bFan Club\b', r'Club de Fans', 'Fan Club'),
    (r'\bName Rater\b', r'Valorador de Noms', 'Name Rater'),
    (r'\bPok[ée] ?Flute\b', r'Pokéflauta|Flauta', 'Poké Flute'),
]

LABEL = re.compile(r'^\s*([A-Za-z_][A-Za-z0-9_]*)::?')
CSYM = re.compile(r'([A-Za-z_][A-Za-z0-9_]*)\s*(?:\[[^\]]*\])*\s*=\s*(?:_|__|COMPOUND_STRING)\(')
STR = re.compile(r'"((?:[^"\\]|\\.)*)"')
SKIP = ('src/battle_debug.c', 'src/debug.c', 'src/data/trainers.h', 'src/data/text/species_names.h',
        'src/data/battle_frontier/', 'src/data/contest_opponents.h', 'src/data/credits.h',
        'src/data/trade.h', 'src/data/items.h', 'src/data/text/move_names.h',
        'src/data/text/abilities.h', 'src/data/region_map/region_map_entries.h',
        'src/data/easy_chat/')


def git(*a):
    return subprocess.run(['git', *a], capture_output=True, cwd=ROOT).stdout.decode('utf-8', 'replace')


def table(text, pattern):
    return dict(re.findall(pattern, text))


def pairs():
    out = []
    en = git('show', 'origin/main:src/data/items.h'); ca = open(f'{ROOT}/src/data/items.h', encoding='utf-8').read()
    item = r'\[(ITEM_[A-Z0-9_]+)\]\s*=\s*\{\s*\.name\s*=\s*_\("([^"]*)"\)'
    E, C = table(en, item), table(ca, item)
    out += [(E[k], C[k], 'item') for k in E if k in C]
    for path, kind in (('src/data/text/move_names.h', 'move'), ('src/data/text/abilities.h', 'ability')):
        en = git('show', f'origin/main:{path}'); ca = open(f'{ROOT}/{path}', encoding='utf-8').read()
        if kind == 'ability':
            en = en[en.index('gAbilityNames'):]; ca = ca[ca.index('gAbilityNames'):]
        pat = r'\[((?:MOVE|ABILITY)_[A-Z0-9_]+)\]\s*=\s*_\("([^"]*)"\)'
        E, C = table(en.split('#else')[0], pat), table(ca.split('#else')[0], pat)
        out += [(E[k], C[k], kind) for k in E if k in C]
    path = 'src/data/region_map/region_map_entries.h'
    en = git('show', f'origin/main:{path}'); ca = open(f'{ROOT}/{path}', encoding='utf-8').read()
    pat = r'static const u8 (sMapName_\w+)\[\] = _\("([^"]*)"\)'
    E, C = table(en, pat), table(ca, pat)
    out += [(E[k], C[k], 'place') for k in E if k in C]
    # keep names that are distinctive in English text: 2+ words, or one capitalised
    # word of 5+ letters that is not an everyday word
    common = set('''Potion Antidote Repel Revive Ether Elixir Protect Return Thief Bite Rest Surf Fly Cut
        Dig Flash Strength Rage Swift Growl Leer Screech Tackle Pound Slam Wrap Bind Bide Swagger Captivate
        Sketch Attract Charm Endure Present Spite Curse Snore Flail Swift Charge Snatch Recycle Secret Power
        Normal Fire Water Grass Electric Ice Fighting Poison Ground Flying Psychic Bug Rock Ghost Dragon Dark
        Steel Fairy Mystery Pressure Static Intimidate Levitate Synchronize Guts Overgrow Blaze Torrent
        Swarm Keen Eye Stench Damp Limber Insomnia Immunity Oblivious Own Tempo Shed Skin Run Away
        Underwater Secret Base None Mail Ticket Honey Stick Leftovers Metronome Transform Substitute
        Teleport Counter Disable Mist Haze Reflect Recover Harden Minimize Smokescreen Withdraw Barrier
        Agility Focus Energy Rollout Outrage Magnitude Encore Pursuit Spikes Foresight Torment Memento
        Facade Taunt Trick Ingrain Superpower Revenge Brick Break Yawn Endeavor Eruption Refresh Grudge
        Camouflage Hail Covet Uproar Stockpile Swallow Wish Assist Imprison Tickle Block Howl Extrasensory
        Overheat Snatch Astonish Shock Wave Water Pulse Doom Desire Psycho Boost Roost Gravity Feint
        Pluck Tailwind Acupressure Payback Assurance Embargo Fling Punishment Last Resort Copycat Switcheroo
        Toxic Spikes Aqua Ring Magnet Rise Defog Trick Room Rock Slide Judgment Lucky Chant Me First
        Volcano Pyramid Stone Beach Island Route Desert Ruins Cave Tower Path Forest Woods Tunnel'''.split())
    keep = []
    for e, c, kind in out:
        if e == c or not e.strip() or '{' in e:
            continue
        if ' ' not in e and (e in common or len(e) < 5):
            continue
        keep.append((e, c, kind))
    return keep


# Shorter forms of a table name accepted in running text.
ALIASES = {
    'Battle Tower': ['Torre'], 'Trainer Hill': ['Turó'], 'Pokémon League': ['Lliga'],
    'Rocket Hideout': ['Amagatall'], 'Secret Base': ['Base'], 'Sea Route': ['Ruta Marítima'],
}


def aliases(e, c):
    out = [c] + ALIASES.get(e, [])
    m = re.match(r"(Ciutat|Poble|Illa|Mont|Cova|Bosc) (.+)$", c)
    if m:
        out.append(m.group(2))            # "Gimnàs de Viridiana", "Museu de Pedrera"
    m = re.match(r'Route (\d+)$', e)
    if m:
        out.append(f'Ruta Marítima {m.group(1)}')
    return out


def norm(s):
    s = re.sub(r'\\[nlp]', ' ', s)
    s = re.sub(r'\{[^}]*\}', ' ', s)
    s = s.replace('-\n', '')
    return re.sub(r'\s+', ' ', s).lower()


def messages(text, asm):
    out = collections.defaultdict(str); key = None
    for line in text.split('\n'):
        if asm:
            m = LABEL.match(line)
            if m: key = m.group(1); continue
            m = re.match(r'\s*\.string\s+"((?:[^"\\]|\\.)*)"', line)
            if m: out[key] += m.group(1)
        else:
            m = CSYM.search(line)
            if m: key = m.group(1)
            if '"' in line and key:
                out[key] += ''.join(STR.findall(line))
    return out


def ca_matches(c, text):
    """True if the Catalan name c appears in text (already normalised).

    Table names are often abbreviated to fit 13/16 bytes ("Camp. Closca",
    "Caram.Veloc.", "BufandaElec."), while dialogue spells them out, so each
    word of the table name only has to be a prefix of consecutive words of
    the text (an abbreviation ending in '.' or a run-together word counts)."""
    import unicodedata
    def fold(x):
        return ''.join(ch for ch in unicodedata.normalize('NFD', x) if unicodedata.category(ch) != 'Mn')
    parts = [fold(p.lower()) for p in re.split(r"[\s.]+|(?<=[a-zà-ÿ])(?=[A-ZÀ-Ý])", c.replace("'", "' ")) if p]
    c = c.lower()
    if c.rstrip('.') in text:
        return True
    text = fold(text)
    if not parts:
        return False
    words = [re.sub(r"^[ld]'", '', w) for w in re.findall(r"[\wà-ÿ·']+", text)]
    for i in range(len(words)):
        j, ok = i, True
        for p in parts:
            while j < len(words) and words[j] in ('de', "d'", 'del', 'la', 'el'):
                j += 1
            if j < len(words) and (words[j].startswith(p.rstrip("'")) or
                                   (len(p) > 4 and words[j].startswith(p[:-1]))):  # Medalla/Medalles
                j += 1
            else:
                ok = False; break
        if ok:
            return True
    return False


def main():
    pr = pairs()
    if '-v' in sys.argv:
        for e, c, k in pr: print(f'{k:8} {e} -> {c}')
    exc = set()
    path = os.path.join(HERE, 'terms_exceptions.txt')
    if os.path.exists(path):
        for line in open(path, encoding='utf-8'):
            line = line.split('#')[0].strip()
            if line: exc.add(tuple(x.strip() for x in line.split('|')))
    compiled = [(re.compile(r'(?<![A-Za-z])' + re.escape(e) + r'(?![A-Za-z])'), e, c, k) for e, c, k in pr]
    compiled += [(re.compile(e), d, c, 'term') for e, c, d in TERMS]
    files = [f for f in git('ls-files', 'data', 'src').split()
             if f.endswith(('.inc', '.s', '.c', '.h')) and not f.startswith(SKIP)]
    bad = []
    checked = 0
    for rel in files:
        asm = rel.endswith(('.inc', '.s'))
        cur = messages(open(f'{ROOT}/{rel}', encoding='utf-8', errors='replace').read(), asm)
        base = messages(git('show', f'origin/main:{rel}'), asm)
        for key, en in base.items():
            ca = cur.get(key)
            if not ca or ca == en:
                continue
            enn, can = re.sub(r'\\[nlp]', ' ', en), norm(ca)
            found = [(rx, e, c, kind) for rx, e, c, kind in compiled if rx.search(enn)]
            longer = [e for _, e, _, k in found if k != 'term']
            for rx, e, c, kind in found:
                if kind != 'term' and any(e != o and e in o for o in longer):
                    continue   # 'Thunder' inside 'Thunder Wave'
                checked += 1
                ok = re.search(c, can, re.I) if kind == 'term' else any(ca_matches(x, can) for x in aliases(e, c))
                if not ok and (rel, key, e) not in exc:
                    bad.append((rel, key, kind, e, c, ca))
    for rel, key, kind, e, c, ca in bad:
        print(f'{rel} [{key}] {kind} {e!r} -> {c!r} :: {ca[:110]!r}')
    print(f'\n{len(pr)} table pairs + {len(TERMS)} glossary terms; {checked} mentions checked; '
          f'{len(bad)} without the agreed Catalan name.')
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
