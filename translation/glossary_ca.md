# Glossari de traducció al català — PokeClassic

Terminologia acordada per a la localització al català del joc PokeClassic (recreació de Pokémon Yellow en el motor de Pokémon Emerald).

---

## Regles generals

- Registre informal ("tu", no "vostè").
- Accents diacrítics segons la norma de l'IEC de 2016: **soc**, **dona** (verb),
  **venen**, **vens**, **os**… (no "sóc", "dóna", "vénen"). Es mantenen els 15
  diacrítics vigents: bé, déu, és, mà, més, món, pèl, què, sé, sí, sòl, són, té, ús, vós.
- **Entrenador** amb majúscula quan és el rol del joc (com l'anglès *Trainer*);
  en minúscula només en sentit genèric.
- **la Pokédex** (femení): "la teva Pokédex", "completar la Pokédex".
- Gènere per defecte dels Pokémon: masculí, excepte espècies exclusivament femenines (Chansey, Blissey, Nidoqueen, Nidorina, etc.).
- Ela geminada: usar `·` (ja disponible al charmap com a byte AF): col·legi, intel·ligent, etc.
- Majúscules accentuades: usar-les (À, È, É, Í, Ï, Ò, Ó, Ú, Ü, Ç).
- Longitud màxima per línia de text: **no es mesura en caràcters.** La font del GBA
  és d'amplada variable, així que comptar caràcters no diu si el text hi cap. Mesura
  l'amplada real en píxels amb `python3 translation/audit_box_widths.py` (vegeu
  [TOOLING.md](TOOLING.md)). Límits: 109 px les descripcions de motxilla,
  144 px les d'habilitat, 208 px els missatges de combat i les caixes de text.
  La caixa de diàleg dels scripts fa 216 px (objectiu 208 px); comprova-la amb
  `python3 translation/audit_script_widths.py -v`.
- Les descripcions d'habilitat **no es poden partir en dues línies**: el plafó és
  una sola línia de 144 px (uns 26 caràcters). Cal escriure-les curtes, com fa
  l'anglès original.

---

## Formes curtes obligatòries

Els quadres de text del GBA són estrets, així que aquestes formes s'usen sempre,
per coherència i perquè el text hi càpiga. Vegeu [TOOLING.md](TOOLING.md).

| Forma llarga | Forma curta |
|--------------|-------------|
| estadística / estadístiques | estad. |
| Velocitat | Vel. |
| Defensa | Def. |
| Augmenta la X | Puja la X |
| Redueix la X | Baixa la X |
| augmenta la potència dels moviments X | potencia els moviments X |
| en un moment crític | en perill |
| en fer contacte | al contacte |
| Objecte retingut que… | Objecte retingut: … |

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
| Victory Road | Camí Victòria |
| Seafoam Islands | Illes Escuma |
| Cerulean Cave | Cova Cerúlia |
| Diglett's Cave | Cova de Diglett |
| Underground Path | Camí Subterrani |
| Pokémon Mansion | Mansió Pokémon |
| Rocket Hideout | Amagatall Rocket |
| Mt. Battle | Mont Combat |

Els noms de lloc dels diàlegs i dels cartells han de coincidir **exactament** amb
els del mapa (`src/data/region_map/region_map_entries.h`): "Ciutat Cerúlia", mai
"Ciutat Cerulean" ni "Cerulean City". Aplica l'apòstrof: "de l'Equip Rocket",
"d'Escuma". Els llocs de Hoenn que encara apareixen conserven el nom anglès amb
"Ciutat"/"Poble"/"Mont" al davant, com al mapa: Ciutat Mauville, Mont Pyre.

**Plantes d'edifici:** 1F → **P1**, 11F → **P11**, B1F → **S1** (soterrani). L'ascensor
i els directoris dels grans magatzems han de coincidir.
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

Aquests són els noms complets, els dels diàlegs. La taula de classes
(`trainer_class_names.h`) té un límit de 12 bytes i n'usa formes abreujades
quan cal: Entr. {PKMN}, Entr. Guai, Cint. Negre, Guard.Ocells, Dom. Dragons,
Noia Combat, Col·leccion., Germ. Germà, Maj. i Menor, Mestra Saló, Virt. Palau,
Magnat Arena, Cap Fàbrica, Reina Llança, Rei Piràmide.

| Anglès | Català |
|--------|--------|
| Pokémon Trainer | Entrenador Pokémon |
| Youngster | Jovenet |
| Lass | Noieta |
| Bug Catcher | Caçainsectes |
| Hiker | Senderista |
| Fisherman | Pescador |
| Sailor | Mariner |
| Biker | Motorista |
| Burglar | Lladre |
| Cooltrainer | Entrenador Guai |
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
| Picnicker | Piqueniquera |
| School Kid | Estudiant |
| Swimmer | Nedador/a |
| Beauty | Bellesa |
| Lady | Senyoreta |
| Rich Boy | Nen Ric |
| Parasol Lady | Senyoreta Para-sol (Sny.Para-sol) |
| Pokémon Ranger | Guarda Pokémon |
| Cool Couple | Parella Guai |
| Pokéfan | Pokéfan |
| Pokémaniac | Pokémaniàtic |
| Triathlete | Triatleta |
| Ninja Boy | Ninja |
| Battle Girl | Noia de Combat |
| Twins | Bessones |
| Collector | Col·leccionista |
| Interviewer | Periodista |
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
| Bashful | Vergonyós |
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
| Poison / Poisoned | Verí / Enverinat |
| Badly poisoned | Molt enverinat |
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
| HM | MO (Màquina Oculta, f.: "la MO") |
| TM | MT (Màquina Tècnica) |
| Bicycle | Bicicleta |
| Fishing Rod | Canya de Pescar |
| Old Rod | Canya Vella |
| Good Rod | Bona Canya |
| Super Rod | Supercanya |
| Surf | Surf |
| Fly | Vol |
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

## Decisions de terminologia

| Anglès | Català | Nota |
|--------|--------|------|
| OT (Original Trainer) | EO | Pantalla de resum; `EO/` als menús. |
| ID No. | Núm. ID | |
| Pokédex No. / No. | Núm. Pokédex / Núm. | "núm." és l'abreviatura de l'IEC (no "n.º"). |
| HP / PP (etiquetes) | PS / PU | Iguals a combat. |
| BP (Battle Points) | BP | Es manté: "PC" es confondria amb l'ordinador. En text complet: "Punts de Combat". |
| critical-hit ratio | taxa de cop crític | Femení ("alta taxa"), no "ratio". |
| hatch / hatched | descloure's / nascut | "L'ou es desclou", "Aviat es desclourà"; no "eclosionar". |
| quiz | pregunta | No "quiz". |
| Pokéblock Case | Estoig {POKEBLOCK} | Un sol nom: no "Capseta", no "PokéBloc". |
| Mega Stones | -ita | Venusaurita, Charizardita X, Alakazamita, Mewtwoita X… |
| PokéNav | PokéGear / DexNav | El joc té PokéGear (menú) i DexNav; no existeix el PokéNav. |
| Wireless (Adapter) | Sense Fils | "Adaptador Sense Fils", plural. |
| slots (slot machines) | escurabutxaques | |
| Elite (adjectiu) | d'elit | "Elite Four" continua sent Alt Comandament. |
| Speaker tags | Oak:, Bill:, Mare: | Capitalització normal, no "OAK:". |
| Game cartridges | Ruby, Sapphire, Emerald | Noms de producte: es mantenen als textos de connexió i concursos (el "Mode E" ve d'Emerald). Les disfresses i les paraules d'easy chat sí que es tradueixen (Robí, Safir, Maragda). |
| Oak's Parcel / S.S. Ticket | Paquet d'Oak / Bitllet SS | |
| flinch | retrocedir | "Pot fer retrocedir", "ha retrocedit!" (no "encongir"). |
| Wild / Foe (prefix) | … salvatge / … rival | Darrere del nom: "Pidgey salvatge". El codi l'afegeix com a sufix. |
| type names (6 bytes) | Insec., Fant., Elèc., Psíq., Volant | Abreviatures amb punt; al text, el nom complet (tipus Fantasma). |
| Mail | carta | Com els objectes Carta. |
| toss (an item) | llençar | No "llançar". |
| Hail | calabruix | Com el moviment. |
| units | m, kg, cm | Sistema mètric amb coma decimal: "1,7 m", "6,9 kg". |
| Itemfinder | Cercaobjectes | |
| Premier Ball | Premier Ball | Com Ultra Ball, Màster Ball. |
| Old Sea Map | Mapa Antic | "Mapa Marí Vell" no hi cap (13 bytes). |
| Cycling Road | Carril Bici | |
| Sea Cottage | Caseta del Mar | |
| Charm (Oval/Shiny/Catching) | Amulet … | Com els objectes. |
| Name Rater | Valorador de Noms | |
| Quiz Lady | Senyora de les Preguntes | |
| Apprentice | aprenent / aprenenta | Segons el personatge. |
| Battle Tent | Carpa de Combat | |
| Battle Bag | Motxilla de Combat | |
| Exchange Service Corner | Racó d'Intercanvi | |
| challenge (Frontier) | repte | No "desafiament". |
| Frontier symbols | Valentia, Saviesa, Valor, Esperit, Tàctica, Sort, Habilitat | Com al Passi de Frontera. |
| Contest categories | Frescor, Bellesa, Tendresa, Intel·ligència, Força | |
| Contest ranks | Normal, Súper, Hiper, Màster | |
| Judge / appeal | Jutge / actuació | |
| Drive (items) | Unitat | |
| nickname | sobrenom | No "malnom". |

### Medalles i Líders

Medalla Roca (Brock), Cascada (Misty), Tro (Lt. Surge), Arc de Sant Martí
(Erika), Ànima (Koga), Pantà (Sabrina), Volcà (Blaine), Terra (Giovanni).
Sense article personal: "la Medalla Cascada de Misty", "Soc Blaine". Les MT es
presenten igual a tot arreu: "La MTxx conté …", amb el nom del moviment de
`move_names.h`. Rètols: "Gimnàs Pokémon de Ciutat Cerúlia" (d'Illa Cinabri).

## Notes d'estil

- **"Centre Pokémon"** (no "Centro Pokémon" ni "Pokemon Center").
- **"Gimnàs"** per Gym.
- **"Medalla"** per Badge.
- **"Motxilla"** per Bag.
- **"Combat"** per Battle (no "batalla").
- Per a títols de classes d'entrenador, usar el masculí per defecte excepte quan la classe és exclusivament femenina.
- Noms propis de personatges (Gary, Oak, Brock, Misty, etc.): mantenir en anglès/original.
