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
	call_if_unset FLAG_IKITOWN_FESTIVAL_COMPLETE, Route1CloseGates
# 4 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_IKITOWN_FESTIVAL_COMPLETE, Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
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
# 13 "data/maps/Route1/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 10, Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1
	.2byte 0

Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
# 13 "data/maps/Route1/scripts.pory"
	call Route1_KukuiCatchingTutorial
	return


Route1_AlolanMeowthNPC::
# 17 "data/maps/Route1/scripts.pory"
	lock
# 18 "data/maps/Route1/scripts.pory"
	faceplayer
# 19 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 20 "data/maps/Route1/scripts.pory"
	msgbox Route1_AlolanMeowthNPC_Text_0
# 21 "data/maps/Route1/scripts.pory"
	release
	end


Route1_LittleGirlPressB::
# 26 "data/maps/Route1/scripts.pory"
	lock
# 27 "data/maps/Route1/scripts.pory"
	faceplayer
# 28 "data/maps/Route1/scripts.pory"
	msgbox Route1_LittleGirlPressB_Text_0
# 32 "data/maps/Route1/scripts.pory"
	release
	return


Route1_Trigger_BlockRightPath::
# 37 "data/maps/Route1/scripts.pory"
	lock
# 38 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_Trigger_BlockRightPath_Movement_0
# 39 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 40 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_0
# 45 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_0
# 46 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 47 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 48 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_1
# 49 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 50 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_1, MSGBOX_AUTOCLOSE
# 51 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_Trigger_BlockRightPath_Movement_2
# 52 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 53 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_Trigger_BlockRightPath_Movement_3
# 54 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 55 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_3
# 56 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 57 "data/maps/Route1/scripts.pory"
	release
	end


Route1CloseGates::
# 62 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_closed
	return


Route1CloseGates2::
# 67 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_leftclosed
	return


LittleGirlChasesMeowthIntro::
# 72 "data/maps/Route1/scripts.pory"
	lock
# 73 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 74 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 75 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_0
# 76 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_0
# 77 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 78 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_1
# 79 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_2
# 80 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 81 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 82 "data/maps/Route1/scripts.pory"
	delay 60
# 83 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_3
# 84 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 85 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_4
# 86 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 87 "data/maps/Route1/scripts.pory"
	gettimeofday
# 88 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 88 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 98 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 99 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_2
LittleGirlChasesMeowthIntro_1:
# 105 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_3
# 107 "data/maps/Route1/scripts.pory"
	applymovement momintro, Route1_Trigger_BlockRightPath_Movement_3
# 108 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 109 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_4
# 111 "data/maps/Route1/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 112 "data/maps/Route1/scripts.pory"
	waitmessage
# 113 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 114 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_5
# 115 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 116 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 117 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 118 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS3
# 119 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_INTRO_UR
# 120 "data/maps/Route1/scripts.pory"
	warp MAP_PLAYER_ROOM, 12, 10
# 121 "data/maps/Route1/scripts.pory"
	waitstate
# 122 "data/maps/Route1/scripts.pory"
	release
	end

LittleGirlChasesMeowthIntro_2:
# 89 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 90 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_1
	goto LittleGirlChasesMeowthIntro_1


Route1_KukuiCatchingTutorial::
# 127 "data/maps/Route1/scripts.pory"
	lock
# 128 "data/maps/Route1/scripts.pory"
	playse SE_PIN
# 129 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 130 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_0
# 131 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1_KukuiCatchingTutorial_Movement_1
# 132 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 133 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 134 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_1, MSGBOX_AUTOCLOSE
# 145 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_2
# 146 "data/maps/Route1/scripts.pory"
	waitmovement catchingintrokukui
# 147 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 148 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_2, MSGBOX_AUTOCLOSE
# 153 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_3
# 154 "data/maps/Route1/scripts.pory"
	waitmovement catchingintrokukui
# 155 "data/maps/Route1/scripts.pory"
	removeobject catchingintrokukui
# 156 "data/maps/Route1/scripts.pory"
	delay 30
# 157 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1_KukuiCatchingTutorial_Movement_4
# 158 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 159 "data/maps/Route1/scripts.pory"
	special RemoveCameraObject
# 160 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 11
# 161 "data/maps/Route1/scripts.pory"
	setflag FLAG_KUKUI_CATCHING_TUTORIAL1
# 162 "data/maps/Route1/scripts.pory"
	clearflag FLAG_KUKUI_CATCHING_TUTORIAL2
# 163 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 164 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 165 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_REGULARNPCS
# 166 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_INTRO_UR
# 167 "data/maps/Route1/scripts.pory"
	release
	end


Route1_trigger_kukui_catching_tutorial::
# 172 "data/maps/Route1/scripts.pory"
	lock
# 173 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 174 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_2
# 179 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_trigger_kukui_catching_tutorial_Movement_0
# 180 "data/maps/Route1/scripts.pory"
	release
	end


MomSaysHi::
# 185 "data/maps/Route1/scripts.pory"
	lock
# 186 "data/maps/Route1/scripts.pory"
	faceplayer
# 187 "data/maps/Route1/scripts.pory"
	speakername LittleGirlChasesMeowthIntro_Text_0
# 188 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_0
# 189 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 190 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 191 "data/maps/Route1/scripts.pory"
	waitfanfare
# 192 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 193 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 194 "data/maps/Route1/scripts.pory"
	setflag FLAG_ENABLE_STAT_EDITOR
# 195 "data/maps/Route1/scripts.pory"
	setflag FLAG_PORTABLE_PC_TOGGLE
# 196 "data/maps/Route1/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 197 "data/maps/Route1/scripts.pory"
	setflag FLAG_EGG_MOVES
# 198 "data/maps/Route1/scripts.pory"
	setflag FLAG_TUTOR_MOVES
# 199 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_SHINY_RIDE, MomSaysHi_2
# 205 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_RIDE
# 206 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_SURF
MomSaysHi_1:
# 208 "data/maps/Route1/scripts.pory"
	compare VAR_ROTOM_PHONE_ENABLE, 1
	goto_if_lt MomSaysHi_6
# 213 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 0
MomSaysHi_5:
# 215 "data/maps/Route1/scripts.pory"
	release
# 216 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 217 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 218 "data/maps/Route1/scripts.pory"
	release
	end

MomSaysHi_2:
# 201 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_RIDE
# 202 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_SURF
	goto MomSaysHi_1

MomSaysHi_6:
# 210 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
	goto MomSaysHi_5


Mailbox::
# 223 "data/maps/Route1/scripts.pory"
	lock
# 224 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
# 225 "data/maps/Route1/scripts.pory"
	release
	end


Route1LittleBoyNPC::
# 230 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


testscript::
# 235 "data/maps/Route1/scripts.pory"
	msgbox testscript_Text_0, MSGBOX_NPC
	end


# 38 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_0:
# 38 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 48 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_1:
# 48 "data/maps/Route1/scripts.pory"
	walk_in_place_down
# 48 "data/maps/Route1/scripts.pory"
	walk_in_place_down
	step_end

# 51 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_2:
# 51 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 53 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_3:
# 53 "data/maps/Route1/scripts.pory"
	face_up
	step_end

# 75 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_0:
# 75 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 75 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 75 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 75 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 75 "data/maps/Route1/scripts.pory"
	walk_fast_down
	step_end

# 78 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_1:
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

# 79 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_2:
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 83 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_3:
# 83 "data/maps/Route1/scripts.pory"
	walk_slow_up
# 83 "data/maps/Route1/scripts.pory"
	walk_slow_up
	step_end

# 85 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_4:
# 85 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 85 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 85 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
	step_end

# 130 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_0:
# 130 "data/maps/Route1/scripts.pory"
	emote_exclamation_mark
	step_end

# 131 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_1:
# 131 "data/maps/Route1/scripts.pory"
	delay_16
# 131 "data/maps/Route1/scripts.pory"
	delay_16
# 131 "data/maps/Route1/scripts.pory"
	delay_16
# 131 "data/maps/Route1/scripts.pory"
	walk_down
# 131 "data/maps/Route1/scripts.pory"
	walk_down
# 131 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 145 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_2:
# 145 "data/maps/Route1/scripts.pory"
	walk_down
# 145 "data/maps/Route1/scripts.pory"
	walk_right
# 145 "data/maps/Route1/scripts.pory"
	walk_right
# 145 "data/maps/Route1/scripts.pory"
	walk_right
# 145 "data/maps/Route1/scripts.pory"
	walk_right
# 145 "data/maps/Route1/scripts.pory"
	walk_right
# 145 "data/maps/Route1/scripts.pory"
	walk_right
# 145 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 153 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_3:
# 153 "data/maps/Route1/scripts.pory"
	walk_right
# 153 "data/maps/Route1/scripts.pory"
	walk_right
# 153 "data/maps/Route1/scripts.pory"
	walk_right
# 153 "data/maps/Route1/scripts.pory"
	walk_right
# 153 "data/maps/Route1/scripts.pory"
	walk_right
	step_end

# 157 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_4:
# 157 "data/maps/Route1/scripts.pory"
	walk_up
# 157 "data/maps/Route1/scripts.pory"
	walk_up
# 157 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 179 "data/maps/Route1/scripts.pory"
Route1_trigger_kukui_catching_tutorial_Movement_0:
# 179 "data/maps/Route1/scripts.pory"
	walk_right
	step_end

Route1_AlolanMeowthNPC_Text_0:
# 20 "data/maps/Route1/scripts.pory"
	.string "Hsss!$"

Route1_LittleGirlPressB_Text_0:
# 28 "data/maps/Route1/scripts.pory"
	.string "You can go with me!\n"
	.string "If you can dash with {B_BUTTON}!\p"
	.string "What do you think of my song?$"

Route1_Trigger_BlockRightPath_Text_0:
# 40 "data/maps/Route1/scripts.pory"
	.string "Watch it, cuz!\p"
	.string "It's dangerous to get too close to\n"
	.string "a Pokémon while it's using one of\l"
	.string "its moves!$"

Route1_Trigger_BlockRightPath_Text_1:
# 50 "data/maps/Route1/scripts.pory"
	.string "Ruff!$"

LittleGirlChasesMeowthIntro_Text_0:
# 89 "data/maps/Route1/scripts.pory"
	.string "Mom$"

LittleGirlChasesMeowthIntro_Text_1:
# 90 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Could anything be more soothing?\n"
	.string "The first evening spent under\l"
	.string "Alola's calm moon!\p"
	.string "I feel like I could stay out here all\n"
	.string "night!$"

LittleGirlChasesMeowthIntro_Text_2:
# 99 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Can't you just feel that warmth?\n"
	.string "The first day spent under Alola's\l"
	.string "sun!\p"
	.string "It's so warm and bright here!$"

LittleGirlChasesMeowthIntro_Text_3:
# 105 "data/maps/Route1/scripts.pory"
	.string "But that's enough of that!\n"
	.string "Time to unpack all these boxes!$"

LittleGirlChasesMeowthIntro_Text_4:
# 109 "data/maps/Route1/scripts.pory"
	.string "Meowth?\n"
	.string "Go get {PLAYER} for me, would you?$"

LittleGirlChasesMeowthIntro_Text_5:
# 114 "data/maps/Route1/scripts.pory"
	.string "Meow?$"

Route1_KukuiCatchingTutorial_Text_0:
# 133 "data/maps/Route1/scripts.pory"
	.string "Kukui$"

Route1_KukuiCatchingTutorial_Text_1:
# 134 "data/maps/Route1/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "It's about time we set out for the\l"
	.string "festival, yeah!\p"
	.string "But first…\n"
	.string "I've got something to teach you,\l"
	.string "yeah, now that you're a real\l"
	.string "Pokémon Trainer.\p"
	.string "It's the most basic of all the basics.\n"
	.string "Come on-to Route 1!$"

Route1_KukuiCatchingTutorial_Text_2:
# 148 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}!\n"
	.string "Hurry it up, cousin!\p"
	.string "Pretend you're a Pokémon and use your\n"
	.string "Agility!$"

MomSaysHi_Text_0:
# 188 "data/maps/Route1/scripts.pory"
	.string "How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_1:
# 217 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 224 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 230 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"

testscript_Text_0:
# 235 "data/maps/Route1/scripts.pory"
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
