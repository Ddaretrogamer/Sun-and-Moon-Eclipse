Route1_MapScripts::
	.byte 0


MomSaysHi::
# 4 "data/maps/Route1/scripts.pory"
	lock
# 5 "data/maps/Route1/scripts.pory"
	faceplayer
# 6 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_0
# 7 "data/maps/Route1/scripts.pory"
	fadescreen FADE_TO_BLACK
# 8 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 9 "data/maps/Route1/scripts.pory"
	waitfanfare
# 10 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 11 "data/maps/Route1/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 12 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 13 "data/maps/Route1/scripts.pory"
	release
	end


Mailbox::
# 18 "data/maps/Route1/scripts.pory"
	lock
# 19 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
# 20 "data/maps/Route1/scripts.pory"
	release
	end


Route1LittleBoyNPC::
# 25 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


MomSaysHi_Text_0:
# 6 "data/maps/Route1/scripts.pory"
	.string "Mom: How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_1:
# 12 "data/maps/Route1/scripts.pory"
	.string "Mom: Take care, honey!$"

Mailbox_Text_0:
# 19 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 25 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"
