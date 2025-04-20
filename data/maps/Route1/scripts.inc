Route1_MapScripts::
	.byte 0


MomSaysHi::
# 4 "data/maps/Route1/scripts.pory"
	lock
# 5 "data/maps/Route1/scripts.pory"
	faceplayer
# 6 "data/maps/Route1/scripts.pory"
	speakername MomSaysHi_Text_0
# 7 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 8 "data/maps/Route1/scripts.pory"
	fadescreen FADE_TO_BLACK
# 9 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 10 "data/maps/Route1/scripts.pory"
	waitfanfare
# 11 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 12 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_SEARCHING
# 13 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 14 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DETECTOR_MODE
# 15 "data/maps/Route1/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 16 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_2
# 17 "data/maps/Route1/scripts.pory"
	release
	end


Mailbox::
# 22 "data/maps/Route1/scripts.pory"
	lock
# 23 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
# 24 "data/maps/Route1/scripts.pory"
	release
	end


Route1LittleBoyNPC::
# 29 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


MomSaysHi_Text_0:
# 6 "data/maps/Route1/scripts.pory"
	.string "Mom$"

MomSaysHi_Text_1:
# 7 "data/maps/Route1/scripts.pory"
	.string "How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_2:
# 16 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 23 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 29 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"
