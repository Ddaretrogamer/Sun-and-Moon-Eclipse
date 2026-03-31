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
	fadescreenswapbuffers FADE_TO_BLACK
# 9 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 10 "data/maps/Route1/scripts.pory"
	waitfanfare
# 11 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 12 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 13 "data/maps/Route1/scripts.pory"
	setflag FLAG_ENABLE_STAT_EDITOR
# 14 "data/maps/Route1/scripts.pory"
	setflag FLAG_PORTABLE_PC_TOGGLE
# 15 "data/maps/Route1/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 16 "data/maps/Route1/scripts.pory"
	setflag FLAG_EGG_MOVES
# 17 "data/maps/Route1/scripts.pory"
	setflag FLAG_TUTOR_MOVES
# 18 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 19 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_2
# 20 "data/maps/Route1/scripts.pory"
	release
	end


Mailbox::
# 25 "data/maps/Route1/scripts.pory"
	lock
# 26 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
# 27 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_SHINY_RIDE, Mailbox_2
# 33 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_RIDE
# 34 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_SURF
Mailbox_1:
# 36 "data/maps/Route1/scripts.pory"
	compare VAR_ROTOM_PHONE_ENABLE, 1
	goto_if_lt Mailbox_6
# 41 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 0
Mailbox_5:
# 43 "data/maps/Route1/scripts.pory"
	release
	end

Mailbox_2:
# 29 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_RIDE
# 30 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_SURF
	goto Mailbox_1

Mailbox_6:
# 38 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
	goto Mailbox_5


Route1LittleBoyNPC::
# 48 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


testscript::
# 53 "data/maps/Route1/scripts.pory"
	msgbox testscript_Text_0, MSGBOX_NPC
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
# 19 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 26 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 48 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"

testscript_Text_0:
# 53 "data/maps/Route1/scripts.pory"
	.string "okay this is a test.\n"
	.string "It seems this is a suitable line length\l"
	.string "for scripting. This is working well.\p"
	.string "Do I need to do anything to compile\n"
	.string "this?$"
