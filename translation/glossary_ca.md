# Glossari de traducció al català — PokeClassic

Terminologia acordada per a la localització al català del joc PokeClassic (recreació de Pokémon Yellow en el motor de Pokémon Emerald).

---

## Regles generals

- Registre informal ("tu", no "vostè").
- Gènere per defecte dels Pokémon: masculí, excepte espècies exclusivament femenines (Chansey, Blissey, Nidoqueen, Nidorina, etc.).
- Ela geminada: usar `·` (ja disponible al charmap com a byte AF): col·legi, intel·ligent, etc.
- Majúscules accentuades: usar-les (À, È, É, Í, Ï, Ò, Ó, Ú, Ü, Ç).
- Longitud màxima per línia de text: **no es mesura en caràcters.** La font del GBA
  és d'amplada variable, així que comptar caràcters no diu si el text hi cap. Mesura
  l'amplada real en píxels amb `python3 translation/audit_box_widths.py` (vegeu
  [TOOLING.md](TOOLING.md)). Límits: 109 px les descripcions de motxilla,
  144 px les d'habilitat, 208 px els missatges de combat i les caixes de text.

---

## Termes del joc

### Menú principal i sistema

| Anglès | Català |
|--------|--------|
| New Game | Nou joc |
| Continue | Continuar |
| Option / Options | Opcions |
| Mystery Gift | Regal Misteriós |
| Mystery Events | Esdeveniments Misteriosos |
| Save | Desar |
| Load | Carregar |
| Quit | Sortir |
| Yes | Sí |
| No | No |
| OK | D'acord |
| Cancel | Cancel·lar |
| Back | Tornar |
| Exit | Sortir |
| Next | Següent |

### Termes Pokémon bàsics

| Anglès | Català |
|--------|--------|
| Pokémon | Pokémon |
| Pokédex | Pokédex |
| Pokéball / Poké Ball | Poké Ball |
| Trainer | Entrenador/a |
| Gym Leader | Líder de Gimnàs |
| Elite Four | Alt Comandament |
| Champion | Campió/Campiona |
| Rival | Rival |
| Professor | Professor/a |
| Badge | Medalla |
| Egg | Ou |
| Item | Objecte |
| Move | Moviment |
| Type | Tipus |
| Ability | Habilitat |
| Nature | Naturalesa |
| Held item | Objecte equipat |
| Evolution | Evolució |
| Trade | Intercanvi |
| Battle | Combat |
| Wild | Salvatge |
| Level | Nivell |
| Experience | Experiència |
| HP | PS (Punts de Salut) |
| PP | PU (Punts d'Ús) |
| Attack | Atac |
| Defense | Defensa |
| Sp. Atk | Atac Esp. |
| Sp. Def | Defensa Esp. |
| Speed | Velocitat |
| Accuracy | Precisió |
| Evasion | Esquiva |

### Llocs (Kanto)

| Anglès | Català |
|--------|--------|
| Pallet Town | Poble Paleta |
| Viridian City | Ciutat Viridiana |
| Viridian Forest | Bosc Viridià |
| Pewter City | Ciutat Pedrera |
| Mt. Moon | Mont Lluna |
| Cerulean City | Ciutat Cerúlia |
| Vermilion City | Ciutat Vermella |
| Lavender Town | Poble Lavanda |
| Celadon City | Ciutat Celadó |
| Fuchsia City | Ciutat Fúcsia |
| Saffron City | Ciutat Safrà |
| Cinnabar Island | Illa Cinabri |
| Indigo Plateau | Altiplà Índigo |
| Pokémon Center | Centre Pokémon |
| Pokémon Gym | Gimnàs Pokémon |
| Poké Mart | Botiga Pokémon |
| Safari Zone | Zona Safari |
| Game Corner | Sala de Jocs |
| Pokémon Tower | Torre Pokémon |
| Silph Co. | Silph S.A. |
| Rock Tunnel | Túnel Rocós |
| Power Plant | Central Elèctrica |
| SS Anne | SS Anna |
| Victory Road | Camí de la Victòria |

### Organitzacions

| Anglès | Català |
|--------|--------|
| Team Rocket | Equip Rocket |
| Rocket Boss | Cap Rocket |
| Gym | Gimnàs |
| Elite Four | Alt Comandament |
| Battle Frontier | Frontera de Combat |
| Battle Tower | Torre de Combat |

### Classes d'entrenador

| Anglès | Català |
|--------|--------|
| Pokémon Trainer | Entrenador Pokémon |
| Youngster | Jovenet |
| Lass | Noieta |
| Bug Catcher | Caçainsectes |
| Hiker | Excursionista |
| Fisherman | Pescador |
| Sailor | Mariner |
| Biker | Ciclista |
| Burglar | Lladre |
| Cooltrainer | Entrenador Cool |
| Expert | Expert |
| Gentleman | Senyor |
| Black Belt | Cinturó Negre |
| Psychic | Psíquic |
| Bird Keeper | Guardià d'Ocells |
| Dragon Tamer | Domador de Dragons |
| Scientist | Científic |
| Super Nerd | Súper Friqui |
| Juggler | Malabarista |
| Camper | Campista |
| Picnicker | Excursionista |
| School Kid | Estudiant |
| Swimmer | Nedador/a |
| Beauty | Bellesa |
| Lady | Senyoreta |
| Rich Boy | Nen Ric |
| Pokéfan | Pokéfan |
| Pokémaniac | Pokémaniàtic |
| Triathlete | Triatleta |
| Ninja Boy | Ninja |
| Battle Girl | Noia de Combat |
| Twins | Bessones |
| Collector | Col·leccionista |
| Interviewer | Entrevistador |
| Guitarist | Guitarrista |
| Rocker | Rocker |
| Painter | Pintor/a |
| Channeler | Mèdium |
| Gambler | Apostador |
| Old Couple | Parella Gran |
| Young Couple | Parella Jove |
| Sis and Bro | Germana i Germà |
| Sr. and Jr. | Major i Menor |
| Tamer | Domador |
| Salon Maiden | Mestra del Saló |
| Dome Ace | As del Domo |
| Palace Maven | Virtuós del Palau |
| Arena Tycoon | Magnat de l'Arena |
| Factory Head | Cap de la Fàbrica |
| Pike Queen | Reina de la Llança |
| Pyramid King | Rei de la Piràmide |
| Pkmn Prof. | Prof. Pokémon |

### Naturaleses

| Anglès | Català |
|--------|--------|
| Hardy | Robust |
| Lonely | Solitari |
| Brave | Valent |
| Adamant | Ferm |
| Naughty | Entremaliat |
| Bold | Atrevit |
| Docile | Dòcil |
| Relaxed | Relaxat |
| Impish | Murri |
| Lax | Deixat |
| Timid | Tímid |
| Hasty | Precipitat |
| Serious | Seriós |
| Jolly | Alegre |
| Naive | Ingenu |
| Modest | Modest |
| Mild | Suau |
| Quiet | Tranquil |
| Bashful | Tímid (vergonyós) |
| Rash | Impulsiu |
| Calm | Calmat |
| Gentle | Gentil |
| Sassy | Descaradet |
| Careful | Prudent |
| Quirky | Peculiar |

### Tipus

| Anglès | Català |
|--------|--------|
| Normal | Normal |
| Fire | Foc |
| Water | Aigua |
| Electric | Elèctric |
| Grass | Planta |
| Ice | Gel |
| Fighting | Lluita |
| Poison | Verí |
| Ground | Terra |
| Flying | Volador |
| Psychic | Psíquic |
| Bug | Insecte |
| Rock | Roca |
| Ghost | Fantasma |
| Dragon | Drac |
| Dark | Fosc |
| Steel | Acer |

### Condicions d'estat

| Anglès | Català |
|--------|--------|
| Paralysis / Paralyzed | Paràlisi / Paralitzat |
| Sleep / Asleep | Son / Adormit |
| Poison / Poisoned | Verí / Enverienat |
| Badly poisoned | Molt enverienat |
| Burn / Burned | Cremada / Cremat |
| Freeze / Frozen | Gel / Gelat |
| Confusion / Confused | Confusió / Confós |
| Faint / Fainted | Desmai / Desmaiat |

### Objectes comuns

| Anglès | Català |
|--------|--------|
| Poké Ball | Poké Ball |
| Great Ball | Gran Ball |
| Ultra Ball | Ultra Ball |
| Master Ball | Màster Ball |
| Potion | Poció |
| Super Potion | Superpoció |
| Hyper Potion | Hiperpoció |
| Max Potion | Poció Màxima |
| Full Restore | Restauració Total |
| Revive | Revifada |
| Max Revive | Revifada Màxima |
| Antidote | Antídot |
| Burn Heal | Cura Cremades |
| Ice Heal | Cura Gel |
| Awakening | Despertador |
| Full Heal | Cura Total |
| Escape Rope | Corda d'Escapada |
| Repel | Repel·lent |
| HM | MO (Moviment Ocult) |
| TM | MT (Màquina Tècnica) |
| Bicycle | Bicicleta |
| Fishing Rod | Canya de Pescar |
| Old Rod | Canya Vella |
| Good Rod | Bona Canya |
| Super Rod | Supercanya |
| Surf | Surf |
| Fly | Volar |
| Strength | Força |
| Cut | Tall |
| Flash | Llampec |
| Dig | Excavar |
| Teleport | Teletransport |
| Waterfall | Cascada |
| Rock Smash | Trencaroques |

### Missatges de combat

| Anglès | Català |
|--------|--------|
| What will {PLAYER} do? | Què farà {PLAYER}? |
| Fight | Lluitar |
| Bag | Motxilla |
| Run | Fugir |
| {PKMN} used {MOVE}! | {PKMN} va usar {MOVE}! |
| It's super effective! | És molt efectiu! |
| It's not very effective... | No és gaire efectiu... |
| It doesn't affect {PKMN}... | No afecta {PKMN}... |
| A critical hit! | Cop crític! |
| {PKMN} fainted! | {PKMN} es va desmaiar! |
| {PLAYER} won! | {PLAYER} va guanyar! |
| {PLAYER} lost... | {PLAYER} va perdre... |
| {PKMN} gained {AMOUNT} Exp. Points! | {PKMN} va guanyar {AMOUNT} punts d'Exp.! |
| {PKMN} grew to level {LEVEL}! | {PKMN} va arribar al nivell {LEVEL}! |

### Missatges del Centre Pokémon

| Anglès | Català |
|--------|--------|
| Welcome to the Pokémon Center! | Benvingut/da al Centre Pokémon! |
| We restore your tired Pokémon... | Restaurem els teus Pokémon cansats... |
| to full health! | fins a la salut plena! |
| Your Pokémon are all healed! | Els teus Pokémon han estat curats! |
| Thank you for waiting! | Gràcies per esperar! |
| Nurse Joy | Infermer/a |

### Paraules clau addicionals

| Anglès | Català |
|--------|--------|
| Boy | Noi |
| Girl | Noia |
| Player | Jugador/a |
| Egg | Ou |
| Wild | Salvatge |
| Caught | Capturat |
| Evolved | Evolucionat |
| Obtained | Obtingut |
| Used | Usat |
| Found | Trobat |

---

## Noms de Pokémon

Els noms de Pokémon mantenen les seves formes originals en anglès/japonès. No hi ha noms oficials en català; per coherència es manté la versió anglesa llevat que el nom sigui completament adaptable a la fonètica catalana sense pèrdua de reconeixement.

**Criteris:**
- Noms internacionalment reconeguts (Pikachu, Charizard, Mewtwo, etc.): mantenir iguals.
- Noms amb traducció evident i consistent en romànic: adaptar si escau (consulteu columna d'anotació).
- En cas de dubte: mantenir el nom en anglès.

_(La llista completa de decisions per espècie es completarà durant la Fase 2, espècie per espècie.)_

---

## Notes d'estil

- **"Centre Pokémon"** (no "Centro Pokémon" ni "Pokemon Center").
- **"Gimnàs"** per Gym.
- **"Medalla"** per Badge.
- **"Motxilla"** per Bag.
- **"Combat"** per Battle (no "batalla").
- Per a títols de classes d'entrenador, usar el masculí per defecte excepte quan la classe és exclusivament femenina.
- Noms propis de personatges (Gary, Oak, Brock, Misty, etc.): mantenir en anglès/original.
