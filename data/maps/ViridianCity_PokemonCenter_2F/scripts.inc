ViridianCity_PokemonCenter_2F_MapScripts::
	.byte 0

ViridianCity_PokemonCenter_2F_LittleGirl::
	lock
	faceplayer
	msgbox ViridianCity_PokemonCenter_2F_Text_Rank, MSGBOX_DEFAULT
	release
	end

ViridianCity_PokemonCenter_2F_Text_Rank::
	.string "Aquell home no em deixa comprar!\n"
	.string "Diu que no tinc prou rang!\p"
	.string "Què vol dir, això?$"
