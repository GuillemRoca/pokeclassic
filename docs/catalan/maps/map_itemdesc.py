# -*- coding: utf-8 -*-
"""Catalan item descriptions (3 lines, ~23 chars per line).
Repetitive families are generated; the rest are explicit."""
KIND = 'c'
FILES = ['src/data/text/item_descriptions.h']

TYPES = {  # English type word -> Catalan
 "Bug": "Insecte", "Steel": "Acer", "Ground": "Terra", "Rock": "Roca",
 "Grass": "Planta", "Dark": "Sinistre", "Water": "Aigua", "Flying": "Volador",
 "Poison": "Verí", "Ice": "Gel", "Ghost": "Fantasma", "Fire": "Foc",
 "Dragon": "Drac", "Normal": "Normal", "Fairy": "Fada",
}
HYPH = {"Fighting": "Lluita", "Electric": "Elèctric", "Psychic": "Psíquic"}

NATURES = {
 "Adamant": "Ferm", "Bold": "Audaç", "Brave": "Valent", "Calm": "Calmat",
 "Careful": "Curós", "Gentle": "Amable", "Hasty": "Precipitat",
 "Impish": "Pícar", "Jolly": "Alegre", "Lax": "Fluix", "Lonely": "Solitari",
 "Mild": "Suau", "Modest": "Modest", "Naive": "Ingenu", "Naughty": "Murri",
 "Quiet": "Tranquil", "Rash": "Impulsiu", "Relaxed": "Relaxat",
 "Sassy": "Descarat", "Serious": "Seriós", "Timid": "Tímid",
}

BERRIES = ["Razz", "Bluk", "Nanab", "Wepear", "Pinap", "Cornn", "Magost",
           "Rabuta", "Nomel", "Spelon", "Pamtre", "Watmel", "Durin", "Belue"]

MEGA = ["Venusaur", "Charizard", "Blastoise", "Beedrill", "Pidgeot",
        "Alakazam", "Slowbro", "Gengar", "Kangaskhan", "Pinsir",
        "Gyarados", "Aerodactyl", "Mewtwo"]

STATS = {  # base-stat wording
 "HP": "els PS", "Attack": "l'Atac", "Defense": "la Defensa",
 "Speed": "la Velocitat", "Sp. Atk": "l'At. Esp.", "Sp. Def": "la Def. Esp.",
}

T = {}

# --- type-boosting hold items ---
for en, ca in TYPES.items():
    T[f"A hold item that\\nraises the power of\\n{en}-type moves."] = \
        f"Objecte que puja\\nla potència dels\\nmoviments {ca}."
for en, ca in HYPH.items():
    T[f"A hold item that\\nboosts {en}-\\ntype moves."] = \
        f"Objecte que puja\\nla potència dels\\nmoviments {ca}."

# --- berry planting ---
for b in BERRIES:
    T[f"{{POKEBLOCK}} ingredient.\\nPlant in loamy soil\\nto grow {b}."] = \
        f"Ingredient {{POKEBLOCK}}.\\nPlanta-la en terra\\nper collir {b}."
T["{POKEBLOCK} ingredient.\\nPlant in loamy soil\\nto grow a mystery."] = \
    "Ingredient {POKEBLOCK}.\\nPlanta-la en terra\\nper collir misteri."

# --- mints ---
for en, ca in NATURES.items():
    art = "an" if en[0] in "AEIOU" else "a"
    T[f"Loved by Pokémon!\\nThis mint has {art}\\n{en} flavor."] = \
        f"Encanta als Pokémon!\\nAquesta menta té\\ngust {ca}."

# --- mega stones ---
for m in MEGA:
    T[f"This stone enables\\n{m} to Mega\\nEvolve in battle."] = \
        f"Permet que {m}\\nMegaevolucioni\\nen combat."

# --- base-stat vitamins ---
T["Raises the base HP\\nof one Pokémon."] = "Puja els PS base\\nd'un Pokémon."
for en, ca in STATS.items():
    if en == "HP":
        continue
    T[f"Raises the base\\n{en} stat of one\\nPokémon."] = \
        f"Puja {ca} base\\nd'un Pokémon."
T["Raises the base\\nAttack stat of one\\nPokémon."] = "Puja l'Atac base\\nd'un Pokémon."
T["Raises the base\\nDefense stat of\\none Pokémon."] = "Puja la Defensa base\\nd'un Pokémon."
T["Raises the base\\nSpeed stat of one\\nPokémon."] = "Puja la Velocitat\\nbase d'un Pokémon."
T["Raises the base\\nSp. Atk stat of one\\nPokémon."] = "Puja l'At. Esp. base\\nd'un Pokémon."
T["Raises the base\\nSp. Def stat of one\\nPokémon."] = "Puja la Def. Esp.\\nbase d'un Pokémon."

# --- friendship / base-stat lowering berries ---
for en, ca in [("HP", "els PS"), ("Attack", "l'Atac"), ("Defense", "la Defensa"),
               ("Sp. Atk", "l'At. Esp."), ("Sp. Def", "la Def. Esp."),
               ("Speed", "la Velocitat")]:
    T[f"Makes a Pokémon\\nfriendly but lowers\\nbase {en}."] = \
        f"Fa el Pokémon més\\namistós però baixa\\n{ca} base."

# --- pinch berries ---
for en, ca in [("Attack", "l'Atac"), ("Defense", "la Defensa"),
               ("Speed", "la Velocitat"), ("Sp. Atk", "l'At. Esp."),
               ("Sp. Def", "la Def. Esp.")]:
    T[f"A hold item that\\nraises {en} in\\na pinch."] = \
        f"Objecte que puja\\n{ca} en\\nun moment crític."

# --- core stat candies ---
T["Raises a Pokémon's\\ncore HP stat."] = "Puja els PS interns\\nd'un Pokémon."
T["Raises a Pokémon's\\ncore Attack\\nstat."] = "Puja l'Atac intern\\nd'un Pokémon."
T["Raises a Pokémon's\\ncore Defense\\nstat."] = "Puja la Defensa\\ninterna d'un Pokémon."
T["Raises a Pokémon's\\ncore Sp. Attack\\nstat."] = "Puja l'At. Esp.\\nintern d'un Pokémon."
T["Raises a Pokémon's\\ncore Sp. Defense\\nstat."] = "Puja la Def. Esp.\\ninterna d'un Pokémon."
T["Raises a Pokémon's\\ncore Speed\\nstat."] = "Puja la Velocitat\\ninterna d'un Pokémon."
T["Maximizes a \\nPokémon's core\\nstats."] = "Maximitza les\\nestadístiques\\ninternes."
T["Neutralizes a \\nPokémon's core\\nstats."] = "Neutralitza les\\nestadístiques\\ninternes."

# --- power items ---
for en, ca in [("HP", "PS"), ("Atk", "Atac"), ("Def", "Defensa"),
               ("Spd", "Velocitat")]:
    T[f"A hold item that\\npromotes {en} gain,\\nbut reduces Speed."] = \
        f"Objecte que ajuda a\\nguanyar {ca}, però\\nbaixa la Velocitat."
T["Hold item that pro-\\nmotes Sp. Atk gain,\\nbut reduces Speed."] = \
    "Objecte que ajuda a\\nguanyar At. Esp.,\\nperò baixa la Vel."
T["Hold item that pro-\\nmotes Sp. Def gain,\\nbut reduces Speed."] = \
    "Objecte que ajuda a\\nguanyar Def. Esp.,\\nperò baixa la Vel."

# --- in-battle stat boosters ---
for en, ca in [("Attack", "l'Atac"), ("Defense", "la Defensa"),
               ("Speed", "la Velocitat"), ("Sp. Atk", "l'At. Esp.")]:
    T[f"Raises the stat\\n{en} during one\\nbattle."] = \
        f"Puja {ca}\\ndurant un combat."

# --- mail ---
for mon in ["Zigzagoon", "Wingull", "Pikachu", "Magnemite", "Slakoth",
            "Wailmer", "Duskull", "Bellossom"]:
    T[f"A {mon}-print\\nMail to be held by\\na Pokémon."] = \
        f"Carta amb un dibuix\\nde {mon} perquè\\nla porti un Pokémon."

# --- in-battle healing hold items ---
for en, ca in [("heals paralysis", "cura la paràlisi"),
               ("awakens Pokémon", "desperta el Pokémon"),
               ("heals poisoning", "cura l'enverinament"),
               ("defrosts Pokémon", "desglaça el Pokémon"),
               ("heals confusion", "cura la confusió")]:
    T[f"A hold item that\\n{en}\\nin battle."] = \
        f"Objecte que\\n{ca}\\nen combat."

T.update({
"?????": "?????",
# --- balls ---
"The best Ball that\\ncatches a Pokémon\\nwithout fail.": "La millor Ball:\\ncaptura el Pokémon\\nsense fallar mai.",
"A better Ball with\\na higher catch rate\\nthan a Great Ball.": "Ball millor, amb més\\nencert de captura\\nque una Great Ball.",
"A good Ball with a\\nhigher catch rate\\nthan a Poké Ball.": "Bona Ball, amb més\\nencert de captura\\nque una Poké Ball.",
"A tool used for\\ncatching wild\\nPokémon.": "Estri per capturar\\nPokémon salvatges.",
"A special Ball that\\nis used only in the\\nSafari Zone.": "Ball especial que\\nnomés es fa servir\\na la Zona Safari.",
"A Ball that works\\nwell on Water- and\\nBug-type Pokémon.": "Ball que va bé amb\\nels Pokémon Aigua\\ni Insecte.",
"A Ball that works\\nbetter on Pokémon\\non the ocean floor.": "Ball que va millor\\namb els Pokémon del\\nfons marí.",
"A Ball that works\\nbetter on weaker\\nPokémon.": "Ball que va millor\\namb els Pokémon\\nmés febles.",
"A Ball that works\\nbetter on Pokémon\\ncaught before.": "Ball que va millor\\namb Pokémon ja\\ncapturats abans.",
"A Ball that gains\\npower in battles\\ntaking many turns.": "Ball que guanya\\nforça en combats\\nde molts torns.",
"A cozy Ball that\\nmakes Pokémon\\nmore friendly.": "Ball acollidora que\\nfa el Pokémon més\\namistós.",
"A rare Ball made\\nin commemoration\\nof some event.": "Ball rara feta per\\ncommemorar algun\\nesdeveniment.",
# --- medicine ---
"Restores the HP of\\na Pokémon by\\n20 points.": "Recupera 20 PS\\nd'un Pokémon.",
"Heals a poisoned\\nPokémon.": "Cura un Pokémon\\nenverinat.",
"Heals Pokémon\\nof a burn.": "Cura la cremada\\nd'un Pokémon.",
"Defrosts a frozen\\nPokémon.": "Desglaça un Pokémon\\ncongelat.",
"Awakens a sleeping\\nPokémon.": "Desperta un Pokémon\\nadormit.",
"Heals a paralyzed\\nPokémon.": "Cura un Pokémon\\nparalitzat.",
"Fully restores the\\nHP and status of a\\nPokémon.": "Recupera del tot els\\nPS i l'estat d'un\\nPokémon.",
"Fully restores the\\nHP of a Pokémon.": "Recupera del tot els\\nPS d'un Pokémon.",
"Restores the HP of\\na Pokémon by\\n200 points.": "Recupera 200 PS\\nd'un Pokémon.",
"Restores the HP of\\na Pokémon by\\n50 points.": "Recupera 50 PS\\nd'un Pokémon.",
"Heals all the\\nstatus problems of\\none Pokémon.": "Cura tots els\\nproblemes d'estat\\nd'un Pokémon.",
"Revives a fainted\\nPokémon with half\\nits HP.": "Revifa un Pokémon\\ndebilitat amb la\\nmeitat dels PS.",
"Revives a fainted\\nPokémon with all\\nits HP.": "Revifa un Pokémon\\ndebilitat amb tots\\nels PS.",
"A mineral water\\nthat restores HP\\nby 50 points.": "Aigua mineral que\\nrecupera 50 PS.",
"A fizzy soda drink\\nthat restores HP\\nby 60 points.": "Refresc amb gas que\\nrecupera 60 PS.",
"A very sweet drink\\nthat restores HP\\nby 80 points.": "Beguda molt dolça\\nque recupera 80 PS.",
"A nutritious milk\\nthat restores HP\\nby 100 points.": "Llet nutritiva que\\nrecupera 100 PS.",
"A bitter powder\\nthat restores HP\\nby 50 points.": "Pols amarga que\\nrecupera 50 PS.",
"A bitter root\\nthat restores HP\\nby 200 points.": "Arrel amarga que\\nrecupera 200 PS.",
"A bitter powder\\nthat heals all\\nstatus problems.": "Pols amarga que cura\\ntots els problemes\\nd'estat.",
"A very bitter herb\\nthat revives a\\nfainted Pokémon.": "Herba molt amarga\\nque revifa un\\nPokémon debilitat.",
"Restores the PP\\nof a selected move\\nby 10.": "Recupera 10 PP del\\nmoviment triat.",
"Fully restores the\\nPP of a selected\\nmove.": "Recupera del tot els\\nPP del moviment\\ntriat.",
"Restores the PP\\nof all moves by 10.": "Recupera 10 PP de\\ntots els moviments.",
"Fully restores the\\nPP of a Pokémon's\\nmoves.": "Recupera del tot els\\nPP dels moviments\\nd'un Pokémon.",
"A local specialty\\nthat heals all\\nstatus problems.": "Especialitat local\\nque cura tots els\\nproblemes d'estat.",
"A 100% pure juice\\nthat restores HP\\nby 20 points.": "Suc 100% pur que\\nrecupera 20 PS.",
"Fully revives and\\nrestores all\\nfainted Pokémon.": "Revifa i recupera\\ndel tot tots els\\nPokémon debilitats.",
# --- flutes ---
"A glass flute that\\nawakens sleeping\\nPokémon.": "Flauta de vidre que\\ndesperta els Pokémon\\nadormits.",
"A glass flute that\\nsnaps Pokémon\\nout of confusion.": "Flauta de vidre que\\ntreu els Pokémon de\\nla confusió.",
"A glass flute that\\nsnaps Pokémon\\nout of attraction.": "Flauta de vidre que\\ntreu els Pokémon de\\nl'atracció.",
"A glass flute that\\nkeeps away wild\\nPokémon.": "Flauta de vidre que\\nallunya els Pokémon\\nsalvatges.",
"A glass flute that\\nlures wild Pokémon.": "Flauta de vidre que\\natreu els Pokémon\\nsalvatges.",
# --- treasures ---
"Salt obtained from\\ndeep inside the\\nShoal Cave.": "Sal treta del fons\\nde la Cova del Banc.",
"A seashell found\\ndeep inside the\\nShoal Cave.": "Closca trobada al\\nfons de la Cova del\\nBanc.",
"A shard from an\\nancient item. Can\\nbe sold cheaply.": "Fragment d'un objecte\\nantic. Es pot vendre\\na baix preu.",
"A plain mushroom\\nthat would sell\\nat a cheap price.": "Bolet corrent que es\\nvendria a baix preu.",
"A rare mushroom\\nthat would sell at a\\nhigh price.": "Bolet rar que es\\nvendria a bon preu.",
"A pretty pearl\\nthat would sell at a\\ncheap price.": "Perla bonica que es\\nvendria a baix preu.",
"A lovely large pearl\\nthat would sell at a\\nhigh price.": "Perla gran i bonica\\nque es vendria a\\nbon preu.",
"Beautiful red sand.\\nCan be sold at a\\nhigh price.": "Sorra vermella molt\\nbonica. Es ven a\\nbon preu.",
"A red gem shard.\\nIt would sell for a\\nvery high price.": "Fragment de gemma\\nvermella. Es vendria\\na molt bon preu.",
"A nugget of pure\\ngold. Can be sold at\\na high price.": "Pepita d'or pur. Es\\npot vendre a bon\\npreu.",
"A lovely scale.\\nIt is coveted by\\ncollectors.": "Escata preciosa. Els\\ncol·leccionistes la\\ncobegen.",
# --- vitamins / candies ---
"Raises the level\\nof a Pokémon by\\none.": "Puja un nivell\\nel Pokémon.",
"Raises the maximum\\nPP of a selected\\nmove.": "Puja els PP màxims\\ndel moviment triat.",
"Raises the PP of a\\nmove to its maximum\\npoints.": "Puja els PP d'un\\nmoviment al màxim.",
# --- battle items ---
"Prevents stat\\nreduction when\\nused in battle.": "Impedeix perdre\\nestadístiques si es\\nfa servir en combat.",
"Raises the\\ncritical-hit ratio\\nduring one battle.": "Puja el ràtio de\\ncops crítics durant\\nun combat.",
"Raises accuracy\\nof attack moves\\nduring one battle.": "Puja la precisió\\ndels atacs durant\\nun combat.",
"Use to flee from\\nany battle with\\na wild Pokémon.": "Fes-lo servir per\\nfugir de qualsevol\\nPokémon salvatge.",
"Repels weak wild\\nPokémon for 200\\nsteps.": "Repel·leix Pokémon\\nsalvatges febles\\ndurant 200 passos.",
"Repels weak wild\\nPokémon for 250\\nsteps.": "Repel·leix Pokémon\\nsalvatges febles\\ndurant 250 passos.",
"Repels weak wild\\nPokémon for 100\\nsteps.": "Repel·leix Pokémon\\nsalvatges febles\\ndurant 100 passos.",
"Use to escape\\ninstantly from a\\ncave or a dungeon.": "Fes-lo servir per\\nsortir a l'instant\\nd'una cova o masmorra.",
"Makes certain\\nspecies of Pokémon\\nevolve.": "Fa evolucionar certes\\nespècies de Pokémon.",
# --- mail (special) ---
"Mail featuring a\\nsketch of the\\nholding Pokémon.": "Carta amb un esbós\\ndel Pokémon que\\nla porta.",
"A gorgeous-print\\nMail to be held\\nby a Pokémon.": "Carta amb un dibuix\\npreciós perquè la\\nporti un Pokémon.",
"Mail featuring the\\ndrawings of three\\nPokémon.": "Carta amb els dibuixos\\nde tres Pokémon.",
# --- battle-berry hold items ---
"A hold item that\\nrestores 10 PP in\\nbattle.": "Objecte que recupera\\n10 PP en combat.",
"A hold item that\\nrestores 10 HP in\\nbattle.": "Objecte que recupera\\n10 PS en combat.",
"A hold item that\\nrestores 30 HP in\\nbattle.": "Objecte que recupera\\n30 PS en combat.",
"A hold item that\\nheals a burn in\\nbattle.": "Objecte que cura la\\ncremada en combat.",
"A hold item that\\nheals any status\\nproblem in battle.": "Objecte que cura\\nqualsevol problema\\nd'estat en combat.",
"A hold item that\\nrestores HP but\\nmay confuse.": "Objecte que recupera\\nPS però pot causar\\nconfusió.",
"A hold item that\\nups the critical-\\nhit rate in a pinch.": "Objecte que puja els\\ncops crítics en un\\nmoment crític.",
"A hold item that\\nsharply boosts a\\nstat in a pinch.": "Objecte que puja molt\\nuna estadística en\\nun moment crític.",
# --- hold items ---
"A hold item that\\ncasts a glare to\\nreduce accuracy.": "Objecte que enlluerna\\nper reduir la\\nprecisió del rival.",
"A hold item that\\nrestores any\\nlowered stat.": "Objecte que recupera\\nqualsevol estadística\\nbaixada.",
"A hold item that\\npromotes growth,\\nbut reduces Speed.": "Objecte que afavoreix\\nel creixement però\\nbaixa la Velocitat.",
"Spreads Exp. to\\nall your Pokémon\\nwhen activated.": "Reparteix l'Exp. a\\ntots els Pokémon\\nquan s'activa.",
"A hold item that\\noccasionally allows\\nthe first strike.": "Objecte que de\\nvegades permet\\natacar primer.",
"A hold item that\\ncalms spirits and\\nfosters friendship.": "Objecte que calma\\nl'ànim i fomenta\\nl'amistat.",
"A hold item that\\nsnaps Pokémon out\\nof infatuation.": "Objecte que treu el\\nPokémon de\\nl'enamorament.",
"Raises a move's\\npower, but permits\\nonly that move.": "Puja la potència d'un\\nmoviment, però només\\npermet aquell.",
"A hold item that\\nmay cause flinching\\nwhen the foe is hit.": "Objecte que pot\\nesglaiar el rival\\nquan el toques.",
"Doubles money in\\nbattle if the\\nholder takes part.": "Duplica els diners\\ndel combat si hi\\nparticipa qui el porta.",
"A hold item that\\nhelps repel wild\\nPokémon.": "Objecte que ajuda a\\nrepel·lir els Pokémon\\nsalvatges.",
"Hold item: raises\\nSp. Atk & Sp. Def of\\nLatios & Latias.": "Objecte que puja\\nl'At. i Def. Esp. de\\nLatios i Latias.",
"A hold item that\\nraises the Sp. Atk\\nof Clamperl.": "Objecte que puja\\nl'At. Esp. de\\nClamperl.",
"A hold item that\\nraises the Sp. Def\\nof Clamperl.": "Objecte que puja la\\nDef. Esp. de\\nClamperl.",
"A hold item that\\nassures fleeing\\nfrom wild Pokémon.": "Objecte que assegura\\nla fugida dels\\nPokémon salvatges.",
"A wondrous hold\\nitem that prevents\\nevolution.": "Objecte prodigiós que\\nimpedeix l'evolució.",
"A hold item that\\noccasionally\\nprevents fainting.": "Objecte que de\\nvegades evita que\\net debilitis.",
"A hold item that\\nboosts Exp. points\\nearned in battle.": "Objecte que puja els\\nPunts d'Exp. guanyats\\nen combat.",
"A hold item that\\nimproves the\\ncritical-hit rate.": "Objecte que millora\\nel ràtio de cops\\ncrítics.",
"A hold item that\\ngradually restores\\nHP in battle.": "Objecte que recupera\\nPS a poc a poc en\\ncombat.",
"A strange scale\\nheld by Dragon-\\ntype Pokémon.": "Escata estranya que\\nporten els Pokémon\\nde tipus Drac.",
"A hold item that\\nraises the Sp. Atk\\nof Pikachu.": "Objecte que puja\\nl'At. Esp. de\\nPikachu.",
"A peculiar box made\\nby Silph Co.": "Caixa peculiar feta\\nper Silph Co.",
"A hold item that\\nrestores HP upon\\nstriking the foe.": "Objecte que recupera\\nPS en colpejar el\\nrival.",
"A hold item that\\nslightly boosts\\nWater-type moves.": "Objecte que puja una\\nmica els moviments\\nd'Aigua.",
"A hold item that\\nslightly lowers the\\nfoe's accuracy.": "Objecte que baixa una\\nmica la precisió del\\nrival.",
"A hold item that\\nraises Chansey's\\ncritical-hit rate.": "Objecte que puja els\\ncops crítics de\\nChansey.",
"A hold item that\\nraises Ditto's\\nDefense.": "Objecte que puja la\\nDefensa de Ditto.",
"A hold item that \\nraises Cubone or\\nMarowak's Attack.": "Objecte que puja\\nl'Atac de Cubone o\\nMarowak.",
"A hold item that\\nraises Farfetch'd's\\ncritical-hit ratio.": "Objecte que puja els\\ncops crítics de\\nFarfetch'd.",
"A hold item that\\nraises Cool in\\nContests.": "Objecte que puja\\nl'Estil als concursos.",
"A hold item that\\nraises Beauty in\\nContests.": "Objecte que puja la\\nBellesa als concursos.",
"A hold item that\\nraises Cute in\\nContests.": "Objecte que puja la\\nGràcia als concursos.",
"A hold item that\\nraises Smart in\\nContests.": "Objecte que puja\\nl'Enginy als concursos.",
"A hold item that\\nraises Tough in\\nContests.": "Objecte que puja la\\nDuresa als concursos.",
# --- key items ---
"A folding bicycle\\nthat doubles your\\nspeed or better.": "Bici plegable que et\\nfa anar el doble de\\nràpid o més.",
"A case that holds\\nup to 9,999 Coins.": "Estoig per guardar\\nfins a 9.999 fitxes.",
"A device that\\nsignals an invisible\\nitem by sound.": "Aparell que avisa amb\\nun so d'un objecte\\ninvisible.",
"Use by any body of\\nwater to fish for\\nwild Pokémon.": "Fes-la servir a la\\nvora de l'aigua per\\npescar Pokémon.",
"A decent fishing\\nrod for catching\\nwild Pokémon.": "Canya decent per\\npescar Pokémon\\nsalvatges.",
"The best fishing\\nrod for catching\\nwild Pokémon.": "La millor canya per\\npescar Pokémon\\nsalvatges.",
"The ticket required\\nfor sailing on a\\nferry.": "El bitllet que cal\\nper viatjar amb\\ntransbordador.",
"The pass required\\nfor entering\\nPokémon Contests.": "El passi que cal per\\nentrar als concursos\\nPokémon.",
"A tool used for\\nwatering Berries\\nand plants.": "Estri per regar\\nbaies i plantes.",
"A briefcase that\\ncontains Team\\nRocket's plans.": "Maletí que conté els\\nplans de l'Equip\\nRocket.",
"A sack used to\\ngather and hold\\nvolcanic ash.": "Sac per recollir i\\nguardar cendra\\nvolcànica.",
"The key for New\\nMauville beneath\\nMauville City.": "La clau de New\\nMauville, sota la\\nciutat de Mauville.",
"A folding bicycle\\ncapable of jumps\\nand wheelies.": "Bici plegable que pot\\nfer salts i cavallets.",
"A case for holding\\n{POKEBLOCK}s made with\\na Berry Blender.": "Estoig per guardar\\n{POKEBLOCK} fets amb la\\nBatedora de Baies.",
"A letter to Steven\\nfrom the President\\nof the Devon Corp.": "Carta per a Steven\\ndel president de\\nDevon Corp.",
"The ticket for a\\nferry to a distant\\nsouthern island.": "Bitllet per anar en\\ntransbordador a una\\nilla llunyana del sud.",
"A red, glowing orb\\nsaid to contain an\\nancient power.": "Orbe vermell lluent\\nque diuen que conté\\nun poder antic.",
"A blue, glowing orb\\nsaid to contain an\\nancient power.": "Orbe blau lluent que\\ndiuen que conté un\\npoder antic.",
"A device found\\ninside the\\nAbandoned Ship.": "Aparell trobat dins\\ndel Vaixell Abandonat.",
"Nifty goggles that\\nprotect eyes from\\ndesert sandstorms.": "Ulleres pràctiques\\nque protegeixen de\\nles tempestes de sorra.",
"A meteorite found\\nat Meteor Falls.": "Meteorit trobat a les\\nCascades Meteor.",
"A key that opens a\\ndoor inside the\\nAbandoned Ship.": "Clau que obre una\\nporta del Vaixell\\nAbandonat.",
"The key to the\\nstorage inside the\\nAbandoned Ship.": "La clau del magatzem\\ndel Vaixell\\nAbandonat.",
"A fossil of an\\nancient, seafloor-\\ndwelling Pokémon.": "Fòssil d'un Pokémon\\nantic que vivia al\\nfons marí.",
"A device by Devon\\nthat signals any\\nunseeable Pokémon.": "Aparell de Devon que\\ndetecta els Pokémon\\ninvisibles.",
"A parcel for Prof.\\nOak from a Pokémon\\nMart's clerk.": "Paquet per al Prof.\\nOak d'un dependent\\nd'una botiga Pokémon.",
"A sweet-sounding\\nflute that awakens\\nPokémon.": "Flauta de so dolç que\\ndesperta els Pokémon.",
"The key to the\\nCinnabar Island\\nGym's entrance.": "La clau de l'entrada\\ndel Gimnàs de l'Illa\\nCinnabar.",
"A voucher for\\nobtaining a bicycle\\nfrom the Bike Shop.": "Val per obtenir una\\nbici a la Botiga de\\nBicis.",
"Gold dentures lost\\nby the Safari\\nZone's Warden.": "Dentadura d'or que va\\nperdre el Guarda de\\nla Zona Safari.",
"A stone containing\\nthe genes of an\\nancient Pokémon.": "Pedra que conté els\\ngens d'un Pokémon\\nantic.",
"A card-type door\\nkey used in Silph\\nCo's office.": "Clau targeta que\\ns'usa a les oficines\\nde Silph Co.",
"An elevator key\\nused in Team\\nRocket's Hideout.": "Clau d'ascensor de\\nl'amagatall de\\nl'Equip Rocket.",
"A piece of an\\nancient marine\\nPokémon's seashell.": "Tros de closca d'un\\nPokémon marí antic.",
"A piece of an\\nancient marine\\nPokémon's shell.": "Tros de closca d'un\\nantic Pokémon marí.",
"Silph Co's scope\\nmakes unseeable\\nPokémon visible.": "El visor de Silph Co\\nfa visibles els\\nPokémon invisibles.",
"A folding bicycle\\nthat is faster than\\nthe Running Shoes.": "Bici plegable més\\nràpida que les\\nSabates de Córrer.",
"Can be viewed\\nanytime. Shows your\\npresent location.": "Es pot consultar\\nsempre. Mostra on\\nets ara.",
"A rechargeable unit\\nthat flags battle-\\nready Trainers.": "Aparell recarregable\\nque marca els\\nentrenadors a punt.",
"Stores information\\non famous people\\nfor instant recall.": "Guarda informació de\\ngent famosa per\\nconsultar-la a l'acte.",
"A convenient case \\nthat holds TMs and\\nHMs.": "Estoig pràctic per\\nguardar MTs i MOs.",
"A convenient\\ncontainer that\\nholds Berries.": "Recipient pràctic per\\nguardar baies.",
"A TV set tuned to\\nan advice program\\nfor Trainers.": "Televisor sintonitzat\\na un programa de\\nconsells per entrenadors.",
"A pass for ferries\\nbetween One, Two,\\nand Three Island.": "Passi per als\\ntransbordadors entre\\nles illes Un, Dos i Tres.",
"For ferries serving\\nVermilion and the\\nSevii Islands.": "Per als transbordadors\\nde Vermilion i les\\nIlles Sevii.",
"A thirst-quenching\\ntea prepared by an\\nold lady.": "Te que treu la set,\\npreparat per una\\nsenyora gran.",
"A ticket required\\nto board the ship\\nto Navel Rock.": "Bitllet necessari per\\npujar al vaixell cap\\na Navel Rock.",
"A ticket required\\nto board the ship\\nto Birth Island.": "Bitllet necessari per\\npujar al vaixell cap\\na Birth Island.",
"Stores Berry\\nPowder made using\\na Berry Crusher.": "Guarda Pols de Baia\\nfeta amb una\\nTrituradora de Baies.",
"An exquisite, red-\\nglowing gem that\\nsymbolizes passion.": "Gemma exquisida de\\nllum vermella que\\nsimbolitza la passió.",
"A brilliant blue gem\\nthat symbolizes\\nhonesty.": "Gemma blava brillant\\nque simbolitza\\nl'honestedat.",
"A medal-like item in\\nthe same shape as\\nTeam Magma's mark.": "Objecte com una\\nmedalla amb la forma\\nde la marca de Magma.",
"A faded sea chart\\nthat shows the way\\nto a certain island.": "Carta marina esvaïda\\nque mostra el camí a\\nuna certa illa.",
# --- competitive items ---
"Switches a Poké-\\nmon's ability.": "Canvia l'habilitat\\nd'un Pokémon.",
"Turns the ability\\nof a Pokémon into\\na rare ability.": "Converteix l'habilitat\\nd'un Pokémon en una\\nhabilitat rara.",
"Raises the Def and\\nSp. Def of Pokémon\\nthat can evolve.": "Puja la Def. i Def.\\nEsp. dels Pokémon que\\npoden evolucionar.",
"Gradually restores\\nHP of Poison-types.\\nDamages others.": "Recupera PS als de\\ntipus Verí. Fa mal\\na la resta.",
"A held item that\\nboosts the power of\\nHP-stealing moves.": "Objecte que puja la\\npotència dels\\nmoviments que xuclen PS.",
"A belt that boosts\\nthe power of super\\neffective moves.": "Cinturó que puja la\\npotència dels\\nmoviments molt eficaços.",
"Boosts the power of\\nmoves at the cost\\nof some HP per turn.": "Puja la potència dels\\nmoviments a canvi\\nd'uns PS cada torn.",
"A pair of glasses\\nthat ups the power\\nof special moves.": "Ulleres que pugen la\\npotència dels\\nmoviments especials.",
"A headband that\\nboosts the power of\\nphysical moves.": "Cinta que puja la\\npotència dels\\nmoviments físics.",
"Allows immediate\\nuse of a move that\\ncharges first.": "Permet usar a l'acte\\nun moviment que\\ncal carregar.",
"Switches out the\\nfoe if they hit the\\nholder.": "Fa sortir el rival si\\ncolpeja qui el porta.",
"Guard the holder\\nfrom contact move\\neffects.": "Protegeix qui el\\nporta dels efectes\\ndels moviments de contacte.",
"Hurts the foe if\\nthey touch its\\nholder.": "Fa mal al rival si\\ntoca qui el porta.",
"A hooked claw that\\nups the holder's\\ncritical-hit ratio.": "Urpa corbada que puja\\nels cops crítics de\\nqui la porta.",
"Boosts Sp. Atk, but\\nallows the use of\\nonly one move.": "Puja l'At. Esp., però\\nnomés permet usar un\\nsol moviment.",
"Boosts Speed, but\\nallows the use of\\nonly one move.": "Puja la Velocitat,\\nperò només permet usar\\nun sol moviment.",
"Extends the length\\nof barrier moves\\nused by the holder.": "Allarga els moviments\\nde barrera de qui\\nel porta.",
"If the holder falls\\nin love, the foe\\ndoes too.": "Si qui el porta\\ns'enamora, el rival\\ntambé.",
"Extends the length\\nof Rain Dance if\\nused by the holder.": "Allarga Dansa Pluja\\nsi la fa servir qui\\nel porta.",
"Extends the length\\nof Sunny Day if\\nused by the holder.": "Allarga Dia de Sol si\\nel fa servir qui\\nel porta.",
"Extends the length\\nof Sandstorm if\\nused by the holder.": "Allarga la Tempesta\\nde Sorra si la fa\\nservir qui el porta.",
"Extends the length\\nof the move Hail\\nused by the holder.": "Allarga Calamarsa si\\nla fa servir qui\\nel porta.",
"Enables {PKMN} holding\\ntheir Mega Stone to\\nMega Evolve.": "Permet que un {PKMN}\\namb la seva Pedra\\nMega Megaevolucioni.",
"Raises the chance\\nof finding eggs\\nat the daycare.": "Puja la possibilitat\\nde trobar ous a la\\nguarderia.",
"A charm that will\\nraise the chance\\nof Shiny Pokémon.": "Amulet que puja la\\npossibilitat de\\nPokémon Shiny.",
"A charm that raises\\nthe chance of\\nCritical Captures.": "Amulet que puja la\\npossibilitat de\\nCaptures Crítiques.",
# --- TM/HM move descriptions ---
"Powerful, but makes\\nthe user flinch if\\nhit by the foe.": "Potent, però qui\\nl'usa s'esglaia si\\nel rival el toca.",
"Hooks and slashes\\nthe foe with long,\\nsharp claws.": "Enganxa i talla el\\nrival amb urpes\\nllargues i esmolades.",
"Generates an\\nultrasonic wave\\nthat may confuse.": "Genera una onada\\nultrasònica que pot\\ncausar confusió.",
"Raises Sp. Atk and\\nSp. Def by focusing\\nthe mind.": "Puja l'At. i la Def.\\nEsp. concentrant\\nla ment.",
"A savage roar that\\nmakes the foe flee \\nto end the battle.": "Un bram salvatge que\\nfa fugir el rival i\\nacaba el combat.",
"Poisons the foe\\nwith a toxin that\\ngradually worsens.": "Enverina el rival amb\\nuna toxina que va\\nempitjorant.",
"Creates a hailstorm\\nthat damages all\\ntypes except Ice.": "Crea calamarsa que\\nfereix tots els tipus\\nmenys Gel.",
"Bulks up the body\\nto boost both\\nAttack & Defense.": "Enforteix el cos per\\npujar l'Atac i la\\nDefensa.",
"Shoots 2 to 5 seeds\\nin a row to strike\\nthe foe.": "Dispara de 2 a 5\\nllavors seguides\\ncontra el rival.",
"The attack power\\nvaries among\\ndifferent Pokémon.": "La potència de l'atac\\nvaria segons el\\nPokémon.",
"Raises the power of\\nFire-type moves\\nfor 5 turns.": "Puja la potència dels\\nmoviments Foc durant\\n5 torns.",
"Enrages the foe so\\nit can only use\\nattack moves.": "Enfureix el rival, que\\nnomés podrà usar\\nmoviments d'atac.",
"Fires an icy cold\\nbeam that may\\nfreeze the foe.": "Llança un raig glaçat\\nque pot congelar el\\nrival.",
"A brutal snow-and-\\nwind attack that\\nmay freeze the foe.": "Atac brutal de neu i\\nvent que pot congelar\\nel rival.",
"Powerful, but needs\\nrecharging the\\nnext turn.": "Potent, però cal\\nrecuperar forces el\\ntorn següent.",
"Creates a wall of\\nlight that lowers\\nSp. Atk damage.": "Crea un mur de llum\\nque baixa el dany\\nde l'At. Esp.",
"Negates all damage,\\nbut may fail if used\\nin succession.": "Anul·la tot el dany,\\nperò pot fallar si\\nes repeteix.",
"Raises the power of\\nWater-type moves\\nfor 5 turns.": "Puja la potència dels\\nmoviments Aigua\\ndurant 5 torns.",
"Recovers half the\\nHP of the damage \\nthis move inflicts.": "Recupera la meitat\\ndels PS del dany que\\nfa aquest moviment.",
"Prevents status\\nabnormality with a\\nmystical power.": "Impedeix els\\nproblemes d'estat amb\\nun poder místic.",
"The less the user\\nlikes you, the more\\npowerful this move.": "Com menys t'estimi\\nqui l'usa, més potent\\nés el moviment.",
"Absorbs sunlight in\\nthe 1st turn, then\\nattacks next turn.": "Absorbeix llum el 1r\\ntorn i ataca el torn\\nsegüent.",
"Slams the foe with\\na hard tail. It may\\nlower Defense.": "Colpeja el rival amb\\nla cua dura. Pot\\nbaixar la Defensa.",
"A powerful electric\\nattack that may\\ncause paralysis.": "Atac elèctric potent\\nque pot causar\\nparàlisi.",
"Strikes the foe\\nwith a thunderbolt.\\nIt may paralyze.": "Colpeja el rival amb\\nun llampec. Pot\\nparalitzar.",
"Causes a quake\\nthat has no effect\\non flying foes.": "Provoca un temblor\\nque no afecta els\\nrivals que volen.",
"The more the user\\nlikes you, the more\\npowerful this move.": "Com més t'estimi qui\\nl'usa, més potent és\\nel moviment.",
"Digs underground\\nthe 1st turn, then\\nstrikes next turn.": "Cava sota terra el 1r\\ntorn i colpeja el\\ntorn següent.",
"A powerful psychic\\nattack that may\\nlower Sp. Def.": "Atac psíquic potent\\nque pot baixar la\\nDef. Esp.",
"Hurls a dark lump\\nat the foe. It may\\nlower Sp. Def.": "Llança una massa\\nfosca al rival. Pot\\nbaixar la Def. Esp.",
"Destroys barriers\\nlike Light Screen\\nand causes damage.": "Destrueix barreres\\ncom Pantalla Llum i\\nfa dany.",
"Creates illusory\\ncopies to enhance\\nelusiveness.": "Crea còpies il·lusòries\\nper esquivar millor.",
"Creates a wall of\\nlight that weakens\\nphysical attacks.": "Crea un mur de llum\\nque afebleix els\\natacs físics.",
"Zaps the foe with a\\njolt of electricity\\nthat never misses.": "Descarrega electricitat\\nal rival sense fallar\\nmai.",
"Looses a stream of\\nfire that may burn\\nthe foe.": "Deixa anar un raig de\\nfoc que pot cremar\\nel rival.",
"Hurls sludge at the\\nfoe. It may poison\\nthe foe.": "Llança residus al\\nrival. El pot\\nenverinar.",
"Causes a sandstorm\\nthat hits the foe\\nover several turns.": "Provoca una tempesta\\nde sorra que fereix\\ndurant uns torns.",
"A powerful fire\\nattack that may\\nburn the foe.": "Atac de foc potent\\nque pot cremar el\\nrival.",
"Stops the foe from\\nmoving with rocks.\\nMay lower Speed.": "Atura el rival amb\\nroques. Pot baixar\\nla Velocitat.",
"An extremely fast\\nattack that can't\\nbe avoided.": "Atac extremament\\nràpid que no es pot\\nesquivar.",
"Prevents the foe\\nfrom using the same\\nmove in a row.": "Impedeix que el rival\\nrepeteixi el mateix\\nmoviment.",
"Raises Attack when\\npoisoned, burned,\\nor paralyzed.": "Puja l'Atac si està\\nenverinat, cremat o\\nparalitzat.",
"Adds an effect to\\nattack depending\\non the location.": "Afegeix un efecte a\\nl'atac segons el\\nlloc.",
"The user sleeps for\\n2 turns to restore\\nhealth and status.": "Qui l'usa dorm 2\\ntorns per recuperar\\nsalut i estat.",
"Makes it tough to\\nattack a foe of the\\nopposite gender.": "Fa difícil atacar un\\nrival del sexe\\ncontrari.",
"While attacking,\\nit may steal the\\nfoe's held item.": "En atacar, pot robar\\nl'objecte del rival.",
"Spreads hard-\\nedged wings and\\nslams into the foe.": "Obre les ales dures\\ni es llança contra\\nel rival.",
"Switches abilities\\nwith the foe on the\\nturn this is used.": "Bescanvia habilitats\\namb el rival el torn\\nque s'usa.",
"Steals the effects\\nof the move the foe\\nis trying to use.": "Roba els efectes del\\nmoviment que el rival\\nvol usar.",
"Enables full-power\\nattack, but sharply\\nlowers Sp. Atk.": "Permet atacar a tota\\npotència, però baixa\\nmolt l'At. Esp.",
"Attacks the foe\\nwith sharp blades\\nor claws.": "Ataca el rival amb\\nfulles o urpes\\nesmolades.",
"Flies up on the\\nfirst turn, then\\nattacks next turn.": "Vola amunt el primer\\ntorn i ataca el torn\\nsegüent.",
"Creates a huge\\nwave, then crashes\\nit down on the foe.": "Crea una onada enorme\\ni la fa caure sobre\\nel rival.",
"Builds enormous\\npower, then slams\\nthe foe.": "Acumula una força\\nenorme i colpeja el\\nrival.",
"Looses a powerful\\nblast of light that\\nreduces accuracy.": "Deixa anar un fogonall\\nde llum que baixa la\\nprecisió.",
"A rock-crushingly\\ntough attack that\\nmay lower Defense.": "Atac tan dur que\\ntrenca roques. Pot\\nbaixar la Defensa.",
"Attacks the foe\\nwith enough power\\nto climb waterfalls.": "Ataca el rival amb\\nprou força per pujar\\ncascades.",
"Dives underwater\\nthe 1st turn, then\\nattacks next turn.": "Es capbussa el 1r\\ntorn i ataca el torn\\nsegüent.",
})
