Route1_MapScripts::
# 2 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 7 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 8 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Route1/scripts.pory"
	call_if_unset FLAG_HAUOLI_OUTSKIRTS_NEWGAME, Route1CloseGates
# 4 "data/maps/Route1/scripts.pory"
	setrespawn HEAL_LOCATION_PLAYER_HOUSE
	end

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/Route1/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 7 "data/maps/Route1/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_ROUTE1
	return

Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/Route1/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, LittleGirlChasesMeowthIntro
	.2byte 0


Route1_AlolanMeowthNPC::
# 12 "data/maps/Route1/scripts.pory"
	lock
# 13 "data/maps/Route1/scripts.pory"
	faceplayer
# 14 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 15 "data/maps/Route1/scripts.pory"
	msgbox Route1_AlolanMeowthNPC_Text_0
# 16 "data/maps/Route1/scripts.pory"
	release
	end


Route1_LittleGirlPressB::
# 21 "data/maps/Route1/scripts.pory"
	lock
# 22 "data/maps/Route1/scripts.pory"
	faceplayer
# 23 "data/maps/Route1/scripts.pory"
	msgbox Route1_LittleGirlPressB_Text_0
# 27 "data/maps/Route1/scripts.pory"
	release
	return


Route1_Trigger_BlockRightPath::
# 32 "data/maps/Route1/scripts.pory"
	lock
# 33 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_Trigger_BlockRightPath_Movement_0
# 34 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 35 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_0
# 40 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_0
# 41 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 42 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 43 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_1
# 44 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 45 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_1, MSGBOX_AUTOCLOSE
# 46 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_Trigger_BlockRightPath_Movement_2
# 47 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 48 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_Trigger_BlockRightPath_Movement_3
# 49 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 50 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_3
# 51 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 52 "data/maps/Route1/scripts.pory"
	release
	end


Route1CloseGates::
# 57 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_closed
	return


LittleGirlChasesMeowthIntro::
# 62 "data/maps/Route1/scripts.pory"
	lock
# 63 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 64 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 65 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_0
# 66 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_0
# 67 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 68 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_1
# 69 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_2
# 70 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 71 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 72 "data/maps/Route1/scripts.pory"
	delay 60
# 73 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_3
# 74 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 75 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_4
# 76 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 77 "data/maps/Route1/scripts.pory"
	gettimeofday
# 78 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 78 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 88 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 89 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_2
LittleGirlChasesMeowthIntro_1:
# 95 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_3
# 97 "data/maps/Route1/scripts.pory"
	applymovement momintro, Route1_Trigger_BlockRightPath_Movement_3
# 98 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 99 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_4
# 101 "data/maps/Route1/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 102 "data/maps/Route1/scripts.pory"
	waitmessage
# 103 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 104 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_5
# 105 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 106 "data/maps/Route1/scripts.pory"
	warp MAP_PLAYER_ROOM, 12, 10
# 107 "data/maps/Route1/scripts.pory"
	waitstate
# 108 "data/maps/Route1/scripts.pory"
	release
	end

LittleGirlChasesMeowthIntro_2:
# 79 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 80 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_1
	goto LittleGirlChasesMeowthIntro_1


MomSaysHi::
# 113 "data/maps/Route1/scripts.pory"
	lock
# 114 "data/maps/Route1/scripts.pory"
	faceplayer
# 115 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 116 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_0
# 117 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 118 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 119 "data/maps/Route1/scripts.pory"
	waitfanfare
# 120 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 121 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 122 "data/maps/Route1/scripts.pory"
	setflag FLAG_ENABLE_STAT_EDITOR
# 123 "data/maps/Route1/scripts.pory"
	setflag FLAG_PORTABLE_PC_TOGGLE
# 124 "data/maps/Route1/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 125 "data/maps/Route1/scripts.pory"
	setflag FLAG_EGG_MOVES
# 126 "data/maps/Route1/scripts.pory"
	setflag FLAG_TUTOR_MOVES
# 127 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_SHINY_RIDE, MomSaysHi_2
# 133 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_RIDE
# 134 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_SURF
MomSaysHi_1:
# 136 "data/maps/Route1/scripts.pory"
	compare VAR_ROTOM_PHONE_ENABLE, 1
	goto_if_lt MomSaysHi_6
# 141 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 0
MomSaysHi_5:
# 143 "data/maps/Route1/scripts.pory"
	release
# 144 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 145 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 146 "data/maps/Route1/scripts.pory"
	release
	end

MomSaysHi_2:
# 129 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_RIDE
# 130 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_SURF
	goto MomSaysHi_1

MomSaysHi_6:
# 138 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
	goto MomSaysHi_5


Mailbox::
# 151 "data/maps/Route1/scripts.pory"
	lock
# 152 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
	end


Route1LittleBoyNPC::
# 157 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


testscript::
# 162 "data/maps/Route1/scripts.pory"
	msgbox testscript_Text_0, MSGBOX_NPC
	end


# 33 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_0:
# 33 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 43 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_1:
# 43 "data/maps/Route1/scripts.pory"
	walk_in_place_down
# 43 "data/maps/Route1/scripts.pory"
	walk_in_place_down
	step_end

# 46 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_2:
# 46 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 48 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_3:
# 48 "data/maps/Route1/scripts.pory"
	face_up
	step_end

# 65 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_0:
# 65 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 65 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 65 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 65 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 65 "data/maps/Route1/scripts.pory"
	walk_fast_down
	step_end

# 68 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_1:
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 68 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 69 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_2:
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 73 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_3:
# 73 "data/maps/Route1/scripts.pory"
	walk_slow_up
# 73 "data/maps/Route1/scripts.pory"
	walk_slow_up
	step_end

# 75 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_4:
# 75 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 75 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 75 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
	step_end

Route1_AlolanMeowthNPC_Text_0:
# 15 "data/maps/Route1/scripts.pory"
	.string "Hsss!$"

Route1_LittleGirlPressB_Text_0:
# 23 "data/maps/Route1/scripts.pory"
	.string "You can go with me!\n"
	.string "If you can dash with {B_BUTTON}!\p"
	.string "What do you think of my song?$"

Route1_Trigger_BlockRightPath_Text_0:
# 35 "data/maps/Route1/scripts.pory"
	.string "Watch it, cuz!\p"
	.string "It's dangerous to get too close to\n"
	.string "a Pokémon while it's using one of\l"
	.string "its moves!$"

Route1_Trigger_BlockRightPath_Text_1:
# 45 "data/maps/Route1/scripts.pory"
	.string "Ruff!$"

LittleGirlChasesMeowthIntro_Text_0:
# 79 "data/maps/Route1/scripts.pory"
	.string "Mom$"

LittleGirlChasesMeowthIntro_Text_1:
# 80 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Could anything be more soothing?\n"
	.string "The first evening spent under Alola's\l"
	.string "calm moon!\p"
	.string "I feel like I could stay out here all\n"
	.string "night!$"

LittleGirlChasesMeowthIntro_Text_2:
# 89 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Can't you just feel that warmth?\n"
	.string "The first day spent under Alola's\l"
	.string "sun!\p"
	.string "It's so warm and bright here!$"

LittleGirlChasesMeowthIntro_Text_3:
# 95 "data/maps/Route1/scripts.pory"
	.string "But that's enough of that!\n"
	.string "Time to unpack all these boxes!$"

LittleGirlChasesMeowthIntro_Text_4:
# 99 "data/maps/Route1/scripts.pory"
	.string "Meowth?\n"
	.string "Go get {PLAYER} for me, would you?$"

LittleGirlChasesMeowthIntro_Text_5:
# 104 "data/maps/Route1/scripts.pory"
	.string "Meow?$"

MomSaysHi_Text_0:
# 116 "data/maps/Route1/scripts.pory"
	.string "How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_1:
# 145 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 152 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 157 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"

testscript_Text_0:
# 162 "data/maps/Route1/scripts.pory"
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
