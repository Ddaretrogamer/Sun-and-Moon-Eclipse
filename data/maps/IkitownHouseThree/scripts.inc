IkitownHouseThree_MapScripts::
	.byte 0


IkitownHouseThree_ManDialog::
# 4 "data/maps/IkitownHouseThree/scripts.pory"
	lock
# 5 "data/maps/IkitownHouseThree/scripts.pory"
	faceplayer
# 6 "data/maps/IkitownHouseThree/scripts.pory"
	msgbox IkitownHouseThree_ManDialog_Text_0
# 10 "data/maps/IkitownHouseThree/scripts.pory"
	waitmessage
# 11 "data/maps/IkitownHouseThree/scripts.pory"
	release
	end


IkitownHouseThree_WomanDialog::
# 15 "data/maps/IkitownHouseThree/scripts.pory"
	lock
# 16 "data/maps/IkitownHouseThree/scripts.pory"
	faceplayer
# 17 "data/maps/IkitownHouseThree/scripts.pory"
	msgbox IkitownHouseThree_WomanDialog_Text_0
# 23 "data/maps/IkitownHouseThree/scripts.pory"
	waitmessage
# 24 "data/maps/IkitownHouseThree/scripts.pory"
	release
	end


IkitownHouseThree_ManDialog_Text_0:
# 6 "data/maps/IkitownHouseThree/scripts.pory"
	.string "It's said that ancient peoples rode\n"
	.string "over the waves and seas together\l"
	.string "with their Pokémon to settle the\l"
	.string "Alola Region.$"

IkitownHouseThree_WomanDialog_Text_0:
# 17 "data/maps/IkitownHouseThree/scripts.pory"
	.string "Different people interact with Pokémon\n"
	.string "in their own different ways.\p"
	.string "Some may see them as allies in battle,\n"
	.string "while others just enjoy sharing\l"
	.string "their lives with them.$"
