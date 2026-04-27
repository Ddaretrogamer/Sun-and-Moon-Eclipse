Route1_MapScripts::
# 2 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 6 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 7 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Route1/scripts.pory"
	call_if_unset FLAG_HAUOLI_OUTSKIRTS_NEWGAME, Route1CloseGates
	end

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/Route1/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 6 "data/maps/Route1/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_ROUTE1
	return

Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/Route1/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, LittleGirlChasesMeowthIntro
	.2byte 0


Route1CloseGates::
# 12 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_closed
	return


LittleGirlChasesMeowthIntro::
# 17 "data/maps/Route1/scripts.pory"
	lock
# 18 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 19 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 20 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_0
# 21 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_0
# 22 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 23 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_1
# 24 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_2
# 25 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 26 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 27 "data/maps/Route1/scripts.pory"
	delay 60
# 28 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_3
# 29 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 30 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_4
# 31 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 32 "data/maps/Route1/scripts.pory"
	gettimeofday
# 33 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 33 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 43 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 44 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_2
LittleGirlChasesMeowthIntro_1:
# 50 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_3
# 52 "data/maps/Route1/scripts.pory"
	applymovement momintro, LittleGirlChasesMeowthIntro_Movement_5
# 53 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 54 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_4
# 56 "data/maps/Route1/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 57 "data/maps/Route1/scripts.pory"
	waitmessage
# 58 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 59 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_5
# 60 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 61 "data/maps/Route1/scripts.pory"
	warp MAP_PLAYER_ROOM, 12, 10
# 62 "data/maps/Route1/scripts.pory"
	waitstate
# 63 "data/maps/Route1/scripts.pory"
	release
	end

LittleGirlChasesMeowthIntro_2:
# 34 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 35 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_1
	goto LittleGirlChasesMeowthIntro_1


MomSaysHi::
# 68 "data/maps/Route1/scripts.pory"
	lock
# 69 "data/maps/Route1/scripts.pory"
	faceplayer
# 70 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 71 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_0
# 72 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 73 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 74 "data/maps/Route1/scripts.pory"
	waitfanfare
# 75 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 76 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 77 "data/maps/Route1/scripts.pory"
	setflag FLAG_ENABLE_STAT_EDITOR
# 78 "data/maps/Route1/scripts.pory"
	setflag FLAG_PORTABLE_PC_TOGGLE
# 79 "data/maps/Route1/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 80 "data/maps/Route1/scripts.pory"
	setflag FLAG_EGG_MOVES
# 81 "data/maps/Route1/scripts.pory"
	setflag FLAG_TUTOR_MOVES
# 82 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_SHINY_RIDE, MomSaysHi_2
# 88 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_RIDE
# 89 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_SURF
MomSaysHi_1:
# 91 "data/maps/Route1/scripts.pory"
	compare VAR_ROTOM_PHONE_ENABLE, 1
	goto_if_lt MomSaysHi_6
# 96 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 0
MomSaysHi_5:
# 98 "data/maps/Route1/scripts.pory"
	release
# 99 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 100 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 101 "data/maps/Route1/scripts.pory"
	release
	end

MomSaysHi_2:
# 84 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_RIDE
# 85 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_SURF
	goto MomSaysHi_1

MomSaysHi_6:
# 93 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
	goto MomSaysHi_5


Mailbox::
# 106 "data/maps/Route1/scripts.pory"
	lock
# 107 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
	end


Route1LittleBoyNPC::
# 112 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


testscript::
# 117 "data/maps/Route1/scripts.pory"
	msgbox testscript_Text_0, MSGBOX_NPC
	end


# 20 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_0:
# 20 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 20 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 20 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 20 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 20 "data/maps/Route1/scripts.pory"
	walk_fast_down
	step_end

# 23 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_1:
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 23 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 24 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_2:
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 24 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 28 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_3:
# 28 "data/maps/Route1/scripts.pory"
	walk_slow_up
# 28 "data/maps/Route1/scripts.pory"
	walk_slow_up
	step_end

# 30 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_4:
# 30 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 30 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 30 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
	step_end

# 52 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_5:
# 52 "data/maps/Route1/scripts.pory"
	face_up
	step_end

LittleGirlChasesMeowthIntro_Text_0:
# 34 "data/maps/Route1/scripts.pory"
	.string "Mom$"

LittleGirlChasesMeowthIntro_Text_1:
# 35 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Could anything be more soothing?\n"
	.string "The first evening spent under Alola's\l"
	.string "calm moon!\p"
	.string "I feel like I could stay out here all\n"
	.string "night!$"

LittleGirlChasesMeowthIntro_Text_2:
# 44 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Can't you just feel that warmth?\n"
	.string "The first day spent under Alola's\l"
	.string "sun!\p"
	.string "It's so warm and bright here!$"

LittleGirlChasesMeowthIntro_Text_3:
# 50 "data/maps/Route1/scripts.pory"
	.string "But that's enough of that!\n"
	.string "Time to unpack all these boxes!$"

LittleGirlChasesMeowthIntro_Text_4:
# 54 "data/maps/Route1/scripts.pory"
	.string "Meowth?\n"
	.string "Go get {PLAYER} for me, would you?$"

LittleGirlChasesMeowthIntro_Text_5:
# 59 "data/maps/Route1/scripts.pory"
	.string "Meow?$"

MomSaysHi_Text_0:
# 71 "data/maps/Route1/scripts.pory"
	.string "How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_1:
# 100 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 107 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 112 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"

testscript_Text_0:
# 117 "data/maps/Route1/scripts.pory"
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
