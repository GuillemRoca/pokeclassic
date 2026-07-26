# -*- coding: utf-8 -*-
"""Catalan: opening speech + the highest-frequency common scripts
(Pokemon Center, Mart, PC, save, item pickup, Surf).
.inc files store one display line per .string, so each line is translated
individually and the original line structure is preserved."""
KIND = 'asm'
FILES = [
    'data/text/birch_speech.inc',
    'data/scripts/pkmn_center_nurse.inc',
    'data/text/mart_clerk.inc',
    'data/text/pc.inc',
    'data/text/pc_transfer.inc',
    'data/text/save.inc',
    'data/text/obtain_item.inc',
    'data/text/surf.inc',
]

T = {
# ---- Oak's opening speech ----
"Hello, there!\\n": "Hola!\\n",
"Glad to meet you!\\p": "Encantat de conèixer-te!\\p",
"Welcome to the world of Pokémon!\\p": "Benvingut al món dels Pokémon!\\p",
"My name is Oak.\\p": "Em dic Oak.\\p",
"People affectionately refer to me\\n": "La gent m'anomena afectuosament\\n",
"as the Pokémon Professor.\\p": "el Professor Pokémon.\\p",
"This world…\\p": "Aquest món…\\p",
"…is inhabited far and wide by\\n": "…està habitat arreu per\\n",
"creatures called Pokémon.\\p": "criatures anomenades Pokémon.\\p",
"For some people, Pokémon are pets.\\n": "Per a alguns, els Pokémon són mascotes.\\n",
"Others use them for battling.\\p": "Altres els fan servir per combatre.\\p",
"As for myself…\\p": "Pel que fa a mi…\\p",
"I study Pokémon as a profession.\\p": "Jo estudio els Pokémon de professió.\\p",
"But first, tell me a little about\\n": "Però primer, explica'm una mica sobre\\n",
"yourself.\\p$": "tu mateix.\\p$",
"Are you a boy?\\n": "Ets un noi?\\n",
"Or are you a girl?$": "O ets una noia?$",
"Let's begin with your name.\\n": "Comencem pel teu nom.\\n",
"What is it?$": "Com et dius?$",
"Right…\\n": "D'acord…\\n",
"So your name is {PLAYER}.$": "Així que et dius {PLAYER}.$",
"This is my grandson.\\p": "Aquest és el meu nét.\\p",
"He's been your rival since you both\\n": "És el teu rival des que tots dos\\n",
"were babies.\\p": "éreu nadons.\\p",
"…Erm, what was his name now?$": "…Ehm, com es deia?$",
"…Er, was it {RIVAL}?$": "…Ehm, era {RIVAL}?$",
"That's right! I remember now!\\n": "Això mateix! Ara me'n recordo!\\n",
"His name is {RIVAL}!\\p$": "Es diu {RIVAL}!\\p$",
"{PLAYER}!\\p": "{PLAYER}!\\p",
"Your very own Pokémon legend is\\n": "La teva pròpia llegenda Pokémon\\n",
"about to unfold!\\p": "està a punt de començar!\\p",
"A world of dreams and adventures\\n": "Un món de somnis i aventures\\n",
"with Pokémon awaits! Let's go!\\p": "amb Pokémon t'espera! Endavant!\\p",

# ---- Pokemon Center nurse ----
"Hello, and welcome to\\n": "Hola, benvingut al\\n",
"the Pokémon Center.\\p": "Centre Pokémon.\\p",
"We restore your tired Pokémon\\n": "Aquí recuperem els teus Pokémon\\n",
"to full health.\\p": "cansats del tot.\\p",
"Would you like to rest your Pokémon?$": "Vols que descansin els teus Pokémon?$",
"I'm delighted to see you, {PLAYER}!\\n": "Quina alegria veure't, {PLAYER}!\\n",
"You want the usual, am I right?$": "El de sempre, oi?$",
"Oh! It's the Champion, {PLAYER}!\\n": "Oh! És el campió, {PLAYER}!\\n",
"Shall we heal your Pokémon?$": "Et curem els Pokémon?$",

# ---- Mart clerk ----
"Hi, there!\\n": "Hola!\\n",
"May I help you?$": "Et puc ajudar?$",
"Please come again!$": "Torna quan vulguis!$",
"{PLAYER}{STRING 5}, welcome!\\p": "{PLAYER}{STRING 5}, benvingut!\\p",
"What can I do for you?$": "Què et puc oferir?$",

# ---- PC ----
"{PLAYER} booted up the PC.$": "{PLAYER} ha engegat el PC.$",
"Which PC should be accessed?$": "A quin PC vols entrar?$",
"Accessed Someone's PC.$": "Has entrat al PC d'algú.$",
"Pokémon Storage System opened.$": "S'ha obert el Sistema\\nd'Emmagatzematge Pokémon.$",
"Accessed {PLAYER}'s PC.$": "Has entrat al PC de {PLAYER}.$",
"Accessed Bill's PC.$": "Has entrat al PC del Bill.$",

# ---- save ----
"Would you like to save the game?$": "Vols desar la partida?$",
"There is already a saved file.\\n": "Ja hi ha una partida desada.\\n",
"Is it okay to overwrite it?$": "La vols sobreescriure?$",
"Saving…\\n": "S'està desant…\\n",
"Don't turn off the power.$": "No apaguis la consola.$",
"{PLAYER} saved the game.$": "{PLAYER} ha desat la partida.$",
"WARNING!\\p": "ATENCIÓ!\\p",
"There is a different game file that\\n": "Hi ha una altra partida diferent\\n",
"is already saved.\\p": "que ja està desada.\\p",
"If you save now, the other file's\\n": "Si deses ara, l'aventura de l'altra\\n",
"adventure, including items and\\l": "partida, amb els objectes i els\\l",
"Pokémon, will be entirely lost.\\p": "Pokémon, es perdrà del tot.\\p",
"Are you sure you want to save now\\n": "Segur que vols desar ara i\\n",
"and overwrite the other save file?$": "sobreescriure l'altra partida?$",
"Save error.\\p": "Error en desar.\\p",
"Please exchange the\\n": "Cal canviar la\\n",
"backup memory.$": "memòria de reserva.$",

# ---- obtain item ----
"Obtained the {STR_VAR_2}!$": "Has obtingut {STR_VAR_2}!$",
"The Bag is full…$": "La motxilla és plena…$",
"{PLAYER} put away the {STR_VAR_2}\\n": "{PLAYER} ha guardat {STR_VAR_2}\\n",
"in the {STR_VAR_3} Pocket.$": "a la butxaca {STR_VAR_3}.$",
"{PLAYER} found one {STR_VAR_2}!$": "{PLAYER} ha trobat un {STR_VAR_2}!$",
"Too bad!\\n": "Quina llàstima!\\n",
"in the Bag.$": "a la motxilla.$",
"Too bad! There's no room left for\\n": "Llàstima! No queda lloc per a\\n",
"another {STR_VAR_2}…$": "un altre {STR_VAR_2}…$",
"The {STR_VAR_2} was transferred\\n": "{STR_VAR_2} s'ha transferit\\n",
"to the PC.$": "al PC.$",

# ---- surf ----
"The water is dyed a deep blue…\\n": "L'aigua és d'un blau intens…\\n",
"Would you like to Surf?$": "Vols fer surf?$",
"{STR_VAR_1} used Surf!$": "{STR_VAR_1} ha fet servir Surf!$",
}
