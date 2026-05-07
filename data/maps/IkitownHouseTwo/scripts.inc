IkitownHouseTwo_MapScripts::
	.byte 0


IkitownHouseTwo_GirlDialog::
# 4 "data/maps/IkitownHouseTwo/scripts.pory"
	lock
# 5 "data/maps/IkitownHouseTwo/scripts.pory"
	faceplayer
# 6 "data/maps/IkitownHouseTwo/scripts.pory"
	msgbox IkitownHouseTwo_GirlDialog_Text_0
# 12 "data/maps/IkitownHouseTwo/scripts.pory"
	waitmessage
# 13 "data/maps/IkitownHouseTwo/scripts.pory"
	release
	end


IkitownHouseTwo_MomDialog::
# 18 "data/maps/IkitownHouseTwo/scripts.pory"
	lock
# 19 "data/maps/IkitownHouseTwo/scripts.pory"
	faceplayer
# 20 "data/maps/IkitownHouseTwo/scripts.pory"
	msgbox IkitownHouseTwo_MomDialog_Text_0
# 26 "data/maps/IkitownHouseTwo/scripts.pory"
	waitmessage
# 27 "data/maps/IkitownHouseTwo/scripts.pory"
	release
	end


IkitownHouseTwo_RockruffDialog::
# 32 "data/maps/IkitownHouseTwo/scripts.pory"
	lock
# 33 "data/maps/IkitownHouseTwo/scripts.pory"
	faceplayer
# 34 "data/maps/IkitownHouseTwo/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 35 "data/maps/IkitownHouseTwo/scripts.pory"
	msgbox IkitownHouseTwo_RockruffDialog_Text_0
# 36 "data/maps/IkitownHouseTwo/scripts.pory"
	waitmessage
# 37 "data/maps/IkitownHouseTwo/scripts.pory"
	release
	end


IkitownHouseTwo_GirlDialog_Text_0:
# 6 "data/maps/IkitownHouseTwo/scripts.pory"
	.string "My Rockruff is the best bodyguard\n"
	.string "ever!\p"
	.string "She always comes with me when I go\n"
	.string "shopping, and she lies outside my\l"
	.string "door when I sleep!$"

IkitownHouseTwo_MomDialog_Text_0:
# 20 "data/maps/IkitownHouseTwo/scripts.pory"
	.string "Rockruff there was a wild Pokémon\n"
	.string "when we got her, but now she's like\l"
	.string "part of the family.\p"
	.string "When I see her roughhousing with my\n"
	.string "little girl, I can't help but smile!$"

IkitownHouseTwo_RockruffDialog_Text_0:
# 35 "data/maps/IkitownHouseTwo/scripts.pory"
	.string "Ruff ruff!$"
