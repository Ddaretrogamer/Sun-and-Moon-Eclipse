Route1_MapScripts::
# 2 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Route1/scripts.pory"
	call_if_unset FLAG_HAUOLI_OUTSKIRTS_NEWGAME, Route1CloseGates
	end


Route1CloseGates::
# 9 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_closed
	return


MomSaysHi::
# 14 "data/maps/Route1/scripts.pory"
	lock
# 15 "data/maps/Route1/scripts.pory"
	faceplayer
# 16 "data/maps/Route1/scripts.pory"
	speakername MomSaysHi_Text_0
# 17 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 18 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 19 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 20 "data/maps/Route1/scripts.pory"
	waitfanfare
# 21 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 22 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 23 "data/maps/Route1/scripts.pory"
	setflag FLAG_ENABLE_STAT_EDITOR
# 24 "data/maps/Route1/scripts.pory"
	setflag FLAG_PORTABLE_PC_TOGGLE
# 25 "data/maps/Route1/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 26 "data/maps/Route1/scripts.pory"
	setflag FLAG_EGG_MOVES
# 27 "data/maps/Route1/scripts.pory"
	setflag FLAG_TUTOR_MOVES
# 28 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_SHINY_RIDE, MomSaysHi_2
# 34 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_RIDE
# 35 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_SURF
MomSaysHi_1:
# 37 "data/maps/Route1/scripts.pory"
	compare VAR_ROTOM_PHONE_ENABLE, 1
	goto_if_lt MomSaysHi_6
# 42 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 0
MomSaysHi_5:
# 44 "data/maps/Route1/scripts.pory"
	release
# 45 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 46 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_2
# 47 "data/maps/Route1/scripts.pory"
	release
	end

MomSaysHi_2:
# 30 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_RIDE
# 31 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_SURF
	goto MomSaysHi_1

MomSaysHi_6:
# 39 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
	goto MomSaysHi_5


Mailbox::
# 52 "data/maps/Route1/scripts.pory"
	lock
# 53 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
	end


Route1LittleBoyNPC::
# 58 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


testscript::
# 63 "data/maps/Route1/scripts.pory"
	msgbox testscript_Text_0, MSGBOX_NPC
	end


MomSaysHi_Text_0:
# 16 "data/maps/Route1/scripts.pory"
	.string "Mom$"

MomSaysHi_Text_1:
# 17 "data/maps/Route1/scripts.pory"
	.string "How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_2:
# 46 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 53 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 58 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"

testscript_Text_0:
# 63 "data/maps/Route1/scripts.pory"
	.string "okay this is a test.\n"
	.string "It seems this is a suitable line lengthc\l"
	.string "for scripting. This is working well.\p"
	.string "Do I need to do anything to compile\n"
	.string "this?\p"
	.string "10-4, good buddy! I'll let everybody out\n"
	.string "here know you're on your way!\p"
	.string "Yeah, that's a name that hits you like a\n"
	.string "Trop Kick right to the head! Woo!\p"
	.string "Can't wait to see you here in person then,\n"
	.string "cousin!$"
