Route1_MapScripts::
# 2 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 12 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Route1/scripts.pory"
	call_if_unset FLAG_HAUOLI_OUTSKIRTS_NEWGAME, Route1CloseGates
# 4 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_HAUOLI_OUTSKIRTS_NEWGAME, Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 8 "data/maps/Route1/scripts.pory"
	setrespawn HEAL_LOCATION_PLAYER_HOUSE
	end

Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 6 "data/maps/Route1/scripts.pory"
	call_if_unset FLAG_OPEN_TRAINER_SCHOOL, Route1CloseGates2
	goto Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 11 "data/maps/Route1/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 11 "data/maps/Route1/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_ROUTE1
	return

Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/Route1/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, LittleGirlChasesMeowthIntro
	.2byte 0


Route1_AlolanMeowthNPC::
# 16 "data/maps/Route1/scripts.pory"
	lock
# 17 "data/maps/Route1/scripts.pory"
	faceplayer
# 18 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 19 "data/maps/Route1/scripts.pory"
	msgbox Route1_AlolanMeowthNPC_Text_0
# 20 "data/maps/Route1/scripts.pory"
	release
	end


Route1_LittleGirlPressB::
# 25 "data/maps/Route1/scripts.pory"
	lock
# 26 "data/maps/Route1/scripts.pory"
	faceplayer
# 27 "data/maps/Route1/scripts.pory"
	msgbox Route1_LittleGirlPressB_Text_0
# 31 "data/maps/Route1/scripts.pory"
	release
	return


Route1_Trigger_BlockRightPath::
# 36 "data/maps/Route1/scripts.pory"
	lock
# 37 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_Trigger_BlockRightPath_Movement_0
# 38 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 39 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_0
# 44 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_0
# 45 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 46 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 47 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_1
# 48 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 49 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_1, MSGBOX_AUTOCLOSE
# 50 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_Trigger_BlockRightPath_Movement_2
# 51 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 52 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_Trigger_BlockRightPath_Movement_3
# 53 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 54 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_3
# 55 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 56 "data/maps/Route1/scripts.pory"
	release
	end


Route1CloseGates::
# 61 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_closed
	return


Route1CloseGates2::
# 66 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_leftclosed
	return


LittleGirlChasesMeowthIntro::
# 71 "data/maps/Route1/scripts.pory"
	lock
# 72 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 73 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 74 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_0
# 75 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_0
# 76 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 77 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_1
# 78 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_2
# 79 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 80 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 81 "data/maps/Route1/scripts.pory"
	delay 60
# 82 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_3
# 83 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 84 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_4
# 85 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 86 "data/maps/Route1/scripts.pory"
	gettimeofday
# 87 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 87 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 97 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 98 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_2
LittleGirlChasesMeowthIntro_1:
# 104 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_3
# 106 "data/maps/Route1/scripts.pory"
	applymovement momintro, Route1_Trigger_BlockRightPath_Movement_3
# 107 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 108 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_4
# 110 "data/maps/Route1/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 111 "data/maps/Route1/scripts.pory"
	waitmessage
# 112 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 113 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_5
# 114 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 115 "data/maps/Route1/scripts.pory"
	warp MAP_PLAYER_ROOM, 12, 10
# 116 "data/maps/Route1/scripts.pory"
	waitstate
# 117 "data/maps/Route1/scripts.pory"
	release
	end

LittleGirlChasesMeowthIntro_2:
# 88 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 89 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_1
	goto LittleGirlChasesMeowthIntro_1


MomSaysHi::
# 122 "data/maps/Route1/scripts.pory"
	lock
# 123 "data/maps/Route1/scripts.pory"
	faceplayer
# 124 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 125 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_0
# 126 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 127 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 128 "data/maps/Route1/scripts.pory"
	waitfanfare
# 129 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 130 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 131 "data/maps/Route1/scripts.pory"
	setflag FLAG_ENABLE_STAT_EDITOR
# 132 "data/maps/Route1/scripts.pory"
	setflag FLAG_PORTABLE_PC_TOGGLE
# 133 "data/maps/Route1/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 134 "data/maps/Route1/scripts.pory"
	setflag FLAG_EGG_MOVES
# 135 "data/maps/Route1/scripts.pory"
	setflag FLAG_TUTOR_MOVES
# 136 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_SHINY_RIDE, MomSaysHi_2
# 142 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_RIDE
# 143 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_SURF
MomSaysHi_1:
# 145 "data/maps/Route1/scripts.pory"
	compare VAR_ROTOM_PHONE_ENABLE, 1
	goto_if_lt MomSaysHi_6
# 150 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 0
MomSaysHi_5:
# 152 "data/maps/Route1/scripts.pory"
	release
# 153 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 154 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 155 "data/maps/Route1/scripts.pory"
	release
	end

MomSaysHi_2:
# 138 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_RIDE
# 139 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_SURF
	goto MomSaysHi_1

MomSaysHi_6:
# 147 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
	goto MomSaysHi_5


Mailbox::
# 160 "data/maps/Route1/scripts.pory"
	lock
# 161 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
	end


Route1LittleBoyNPC::
# 166 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


testscript::
# 171 "data/maps/Route1/scripts.pory"
	msgbox testscript_Text_0, MSGBOX_NPC
	end


# 37 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_0:
# 37 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 47 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_1:
# 47 "data/maps/Route1/scripts.pory"
	walk_in_place_down
# 47 "data/maps/Route1/scripts.pory"
	walk_in_place_down
	step_end

# 50 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_2:
# 50 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 52 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_3:
# 52 "data/maps/Route1/scripts.pory"
	face_up
	step_end

# 74 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_0:
# 74 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 74 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 74 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 74 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 74 "data/maps/Route1/scripts.pory"
	walk_fast_down
	step_end

# 77 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_1:
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 77 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 78 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_2:
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 78 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 82 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_3:
# 82 "data/maps/Route1/scripts.pory"
	walk_slow_up
# 82 "data/maps/Route1/scripts.pory"
	walk_slow_up
	step_end

# 84 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_4:
# 84 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 84 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 84 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
	step_end

Route1_AlolanMeowthNPC_Text_0:
# 19 "data/maps/Route1/scripts.pory"
	.string "Hsss!$"

Route1_LittleGirlPressB_Text_0:
# 27 "data/maps/Route1/scripts.pory"
	.string "You can go with me!\n"
	.string "If you can dash with {B_BUTTON}!\p"
	.string "What do you think of my song?$"

Route1_Trigger_BlockRightPath_Text_0:
# 39 "data/maps/Route1/scripts.pory"
	.string "Watch it, cuz!\p"
	.string "It's dangerous to get too close to\n"
	.string "a Pokémon while it's using one of\l"
	.string "its moves!$"

Route1_Trigger_BlockRightPath_Text_1:
# 49 "data/maps/Route1/scripts.pory"
	.string "Ruff!$"

LittleGirlChasesMeowthIntro_Text_0:
# 88 "data/maps/Route1/scripts.pory"
	.string "Mom$"

LittleGirlChasesMeowthIntro_Text_1:
# 89 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Could anything be more soothing?\n"
	.string "The first evening spent under\l"
	.string "Alola's calm moon!\p"
	.string "I feel like I could stay out here all\n"
	.string "night!$"

LittleGirlChasesMeowthIntro_Text_2:
# 98 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Can't you just feel that warmth?\n"
	.string "The first day spent under Alola's\l"
	.string "sun!\p"
	.string "It's so warm and bright here!$"

LittleGirlChasesMeowthIntro_Text_3:
# 104 "data/maps/Route1/scripts.pory"
	.string "But that's enough of that!\n"
	.string "Time to unpack all these boxes!$"

LittleGirlChasesMeowthIntro_Text_4:
# 108 "data/maps/Route1/scripts.pory"
	.string "Meowth?\n"
	.string "Go get {PLAYER} for me, would you?$"

LittleGirlChasesMeowthIntro_Text_5:
# 113 "data/maps/Route1/scripts.pory"
	.string "Meow?$"

MomSaysHi_Text_0:
# 125 "data/maps/Route1/scripts.pory"
	.string "How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_1:
# 154 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 161 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 166 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"

testscript_Text_0:
# 171 "data/maps/Route1/scripts.pory"
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
