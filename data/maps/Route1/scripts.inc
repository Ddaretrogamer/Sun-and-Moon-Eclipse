Route1_MapScripts::
# 2 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 14 "data/maps/Route1/scripts.pory"
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
# 12 "data/maps/Route1/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 10, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1
# 13 "data/maps/Route1/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 17, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_2
	.2byte 0

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 11 "data/maps/Route1/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_ROUTE1
	return

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
# 12 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_2:
# 13 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/Route1/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, LittleGirlChasesMeowthIntro
# 15 "data/maps/Route1/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 10, Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1
# 16 "data/maps/Route1/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 17, Route1_LillieWalkToLab
	.2byte 0

Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
# 15 "data/maps/Route1/scripts.pory"
	call Route1_KukuiCatchingTutorial
	return


Route1_LillieWalkToLab::
# 20 "data/maps/Route1/scripts.pory"
	lock
# 21 "data/maps/Route1/scripts.pory"
	playse SE_PIN
# 22 "data/maps/Route1/scripts.pory"
	hideobjectat route1_mom, MAP_ROUTE1
# 23 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_0
# 24 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 25 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 26 "data/maps/Route1/scripts.pory"
	delay 30
# 27 "data/maps/Route1/scripts.pory"
	startcutscene CUTSCENE_ROUTE1_LILLIE_WALK_TO_LAB
# 28 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_1
# 29 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_2
# 30 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_3
# 31 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 32 "data/maps/Route1/scripts.pory"
	delay 15
# 33 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_0
# 34 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_1
# 37 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_4
# 38 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 39 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_2
# 41 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_5
# 42 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 43 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_3, MSGBOX_AUTOCLOSE
# 47 "data/maps/Route1/scripts.pory"
	opendoor 16, 20
# 48 "data/maps/Route1/scripts.pory"
	waitdooranim
# 49 "data/maps/Route1/scripts.pory"
	showobjectat route1_mom, MAP_ROUTE1
# 50 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_6
# 51 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 52 "data/maps/Route1/scripts.pory"
	closedoor 16, 20
# 53 "data/maps/Route1/scripts.pory"
	waitdooranim
# 54 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_7
# 55 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_7
# 56 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 58 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_5, MSGBOX_AUTOCLOSE
# 59 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_3
# 60 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 61 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_6
# 63 "data/maps/Route1/scripts.pory"
	addmoney 1000
# 64 "data/maps/Route1/scripts.pory"
	delay 30
# 65 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_8
# 66 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 67 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_7
# 73 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_9
# 74 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 75 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_0
# 76 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_8, MSGBOX_AUTOCLOSE
# 80 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_10
# 81 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 82 "data/maps/Route1/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 83 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 84 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_9, MSGBOX_AUTOCLOSE
# 90 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_11
# 91 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 92 "data/maps/Route1/scripts.pory"
	opendoor 16, 20
# 93 "data/maps/Route1/scripts.pory"
	waitdooranim
# 94 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_12
# 95 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 96 "data/maps/Route1/scripts.pory"
	hideobjectat route1_mom, MAP_ROUTE1
# 97 "data/maps/Route1/scripts.pory"
	closedoor 16, 20
# 98 "data/maps/Route1/scripts.pory"
	waitdooranim
# 99 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_11
# 100 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 101 "data/maps/Route1/scripts.pory"
	delay 30
# 102 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_5
# 103 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_13
# 104 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 105 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_0
# 106 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_10, MSGBOX_AUTOCLOSE
# 112 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_14
# 113 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 114 "data/maps/Route1/scripts.pory"
	removeobject route1_lillie
# 115 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_ROUTE1_LILLIE
# 116 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 117 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 18
# 118 "data/maps/Route1/scripts.pory"
	endcutscene
# 119 "data/maps/Route1/scripts.pory"
	release
	end


Lillie_WalktoLabSkip::
# 124 "data/maps/Route1/scripts.pory"
	lock
# 125 "data/maps/Route1/scripts.pory"
	closemessage
# 126 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 127 "data/maps/Route1/scripts.pory"
	setobjectxy LOCALID_PLAYER, 16, 24
# 128 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_4
# 129 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 130 "data/maps/Route1/scripts.pory"
	setobjectxy route1_mom, 16, 18
# 131 "data/maps/Route1/scripts.pory"
	removeobject route1_lillie
# 132 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_ROUTE1_LILLIE
# 133 "data/maps/Route1/scripts.pory"
	special StopAllObjectMovements
# 134 "data/maps/Route1/scripts.pory"
	special CloseScriptMenus
# 135 "data/maps/Route1/scripts.pory"
	special SnapCameraToPlayer
# 136 "data/maps/Route1/scripts.pory"
	special RemoveCameraObject
# 137 "data/maps/Route1/scripts.pory"
	setobjectxy route1_mom, 16, 18
# 138 "data/maps/Route1/scripts.pory"
	setobjectxy HauoliOutskirtsLittleBoy, 14, 31
# 139 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 18
# 140 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 141 "data/maps/Route1/scripts.pory"
	release
	end


Route1_AlolanMeowthNPC::
# 146 "data/maps/Route1/scripts.pory"
	lock
# 147 "data/maps/Route1/scripts.pory"
	faceplayer
# 148 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 149 "data/maps/Route1/scripts.pory"
	msgbox Route1_AlolanMeowthNPC_Text_0
# 150 "data/maps/Route1/scripts.pory"
	release
	end


Route1_LittleGirlPressB::
# 155 "data/maps/Route1/scripts.pory"
	lock
# 156 "data/maps/Route1/scripts.pory"
	faceplayer
# 157 "data/maps/Route1/scripts.pory"
	msgbox Route1_LittleGirlPressB_Text_0
# 161 "data/maps/Route1/scripts.pory"
	release
	return


Route1_Trigger_BlockRightPath::
# 166 "data/maps/Route1/scripts.pory"
	lock
# 167 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_LillieWalkToLab_Movement_4
# 168 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 169 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_0
# 174 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_LillieWalkToLab_Movement_4
# 175 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 176 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 177 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_0
# 178 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 179 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_1, MSGBOX_AUTOCLOSE
# 180 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_6
# 181 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 182 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_LillieWalkToLab_Movement_7
# 183 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 184 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_LillieWalkToLab_Movement_7
# 185 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 186 "data/maps/Route1/scripts.pory"
	release
	end


Route1CloseGates::
# 191 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_closed
	return


Route1CloseGates2::
# 196 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_leftclosed
	return


LittleGirlChasesMeowthIntro::
# 201 "data/maps/Route1/scripts.pory"
	lock
# 202 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 203 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 204 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_0
# 205 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_0
# 206 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 207 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_1
# 208 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_2
# 209 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 210 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 211 "data/maps/Route1/scripts.pory"
	delay 60
# 212 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_3
# 213 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 214 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_4
# 215 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 216 "data/maps/Route1/scripts.pory"
	gettimeofday
# 217 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 217 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 227 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 228 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_1
LittleGirlChasesMeowthIntro_1:
# 234 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_2
# 236 "data/maps/Route1/scripts.pory"
	applymovement momintro, Route1_LillieWalkToLab_Movement_7
# 237 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 238 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_3
# 240 "data/maps/Route1/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 241 "data/maps/Route1/scripts.pory"
	waitmessage
# 242 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 243 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_4
# 244 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 245 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 246 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 247 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS3
# 248 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_INTRO_UR
# 249 "data/maps/Route1/scripts.pory"
	warp MAP_PLAYER_ROOM, 12, 10
# 250 "data/maps/Route1/scripts.pory"
	waitstate
# 251 "data/maps/Route1/scripts.pory"
	release
	end

LittleGirlChasesMeowthIntro_2:
# 218 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 219 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_0
	goto LittleGirlChasesMeowthIntro_1


Route1_KukuiCatchingTutorial::
# 256 "data/maps/Route1/scripts.pory"
	lock
# 257 "data/maps/Route1/scripts.pory"
	playse SE_PIN
# 258 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 259 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_0
# 260 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1_KukuiCatchingTutorial_Movement_1
# 261 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 262 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 263 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 264 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_1, MSGBOX_AUTOCLOSE
# 275 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_2
# 276 "data/maps/Route1/scripts.pory"
	waitmovement catchingintrokukui
# 277 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 278 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_2, MSGBOX_AUTOCLOSE
# 283 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_3
# 284 "data/maps/Route1/scripts.pory"
	waitmovement catchingintrokukui
# 285 "data/maps/Route1/scripts.pory"
	removeobject catchingintrokukui
# 286 "data/maps/Route1/scripts.pory"
	delay 30
# 287 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1_KukuiCatchingTutorial_Movement_4
# 288 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 289 "data/maps/Route1/scripts.pory"
	special RemoveCameraObject
# 290 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 11
# 291 "data/maps/Route1/scripts.pory"
	setflag FLAG_KUKUI_CATCHING_TUTORIAL1
# 292 "data/maps/Route1/scripts.pory"
	clearflag FLAG_KUKUI_CATCHING_TUTORIAL2
# 293 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 294 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 295 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_REGULARNPCS
# 296 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_INTRO_UR
# 297 "data/maps/Route1/scripts.pory"
	release
	end


Route1_trigger_kukui_catching_tutorial::
# 302 "data/maps/Route1/scripts.pory"
	lock
# 303 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 304 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_2
# 309 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_trigger_kukui_catching_tutorial_Movement_0
# 310 "data/maps/Route1/scripts.pory"
	release
	end


MomSaysHi::
# 315 "data/maps/Route1/scripts.pory"
	lock
# 316 "data/maps/Route1/scripts.pory"
	faceplayer
# 317 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 318 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_0
# 319 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 320 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 321 "data/maps/Route1/scripts.pory"
	waitfanfare
# 322 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 323 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 324 "data/maps/Route1/scripts.pory"
	setflag FLAG_ENABLE_STAT_EDITOR
# 325 "data/maps/Route1/scripts.pory"
	setflag FLAG_PORTABLE_PC_TOGGLE
# 326 "data/maps/Route1/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 327 "data/maps/Route1/scripts.pory"
	setflag FLAG_EGG_MOVES
# 328 "data/maps/Route1/scripts.pory"
	setflag FLAG_TUTOR_MOVES
# 329 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_SHINY_RIDE, MomSaysHi_2
# 335 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_RIDE
# 336 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_SURF
MomSaysHi_1:
# 338 "data/maps/Route1/scripts.pory"
	compare VAR_ROTOM_PHONE_ENABLE, 1
	goto_if_lt MomSaysHi_6
# 343 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 0
MomSaysHi_5:
# 345 "data/maps/Route1/scripts.pory"
	release
# 346 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 347 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 348 "data/maps/Route1/scripts.pory"
	release
	end

MomSaysHi_2:
# 331 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_RIDE
# 332 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_SURF
	goto MomSaysHi_1

MomSaysHi_6:
# 340 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
	goto MomSaysHi_5


Mailbox::
# 353 "data/maps/Route1/scripts.pory"
	lock
# 354 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
# 355 "data/maps/Route1/scripts.pory"
	release
	end


Route1LittleBoyNPC::
# 360 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


testscript::
# 365 "data/maps/Route1/scripts.pory"
	msgbox testscript_Text_0, MSGBOX_NPC
	end


Route1_Trigger_HeadEastToIkiTown::
# 385 "data/maps/Route1/scripts.pory"
	lock
# 386 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_HeadEastToIkiTown_Text_0, MSGBOX_AUTOCLOSE
# 388 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_trigger_kukui_catching_tutorial_Movement_0
# 389 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 390 "data/maps/Route1/scripts.pory"
	release
	end


# 23 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_0:
# 23 "data/maps/Route1/scripts.pory"
	emote_exclamation_mark
# 23 "data/maps/Route1/scripts.pory"
	face_up
	step_end

# 28 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_1:
# 28 "data/maps/Route1/scripts.pory"
	walk_down
# 28 "data/maps/Route1/scripts.pory"
	walk_down
# 28 "data/maps/Route1/scripts.pory"
	walk_down
# 28 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 29 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_2:
# 29 "data/maps/Route1/scripts.pory"
	delay_16
# 29 "data/maps/Route1/scripts.pory"
	delay_16
# 29 "data/maps/Route1/scripts.pory"
	delay_16
# 29 "data/maps/Route1/scripts.pory"
	face_right
	step_end

# 30 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_3:
# 30 "data/maps/Route1/scripts.pory"
	walk_down
# 30 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 37 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_4:
# 37 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 41 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_5:
# 41 "data/maps/Route1/scripts.pory"
	face_right
	step_end

# 50 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_6:
# 50 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 54 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_7:
# 54 "data/maps/Route1/scripts.pory"
	face_up
	step_end

# 65 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_8:
# 65 "data/maps/Route1/scripts.pory"
	walk_left
# 65 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 73 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_9:
# 73 "data/maps/Route1/scripts.pory"
	walk_in_place_up
# 73 "data/maps/Route1/scripts.pory"
	walk_in_place_up
	step_end

# 80 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_10:
# 80 "data/maps/Route1/scripts.pory"
	walk_right
# 80 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 90 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_11:
# 90 "data/maps/Route1/scripts.pory"
	walk_up
# 90 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 94 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_12:
# 94 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 103 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_13:
# 103 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 112 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_14:
# 112 "data/maps/Route1/scripts.pory"
	walk_left
# 112 "data/maps/Route1/scripts.pory"
	walk_left
# 112 "data/maps/Route1/scripts.pory"
	walk_left
# 112 "data/maps/Route1/scripts.pory"
	walk_left
# 112 "data/maps/Route1/scripts.pory"
	walk_left
# 112 "data/maps/Route1/scripts.pory"
	walk_left
# 112 "data/maps/Route1/scripts.pory"
	walk_down
# 112 "data/maps/Route1/scripts.pory"
	walk_down
# 112 "data/maps/Route1/scripts.pory"
	walk_down
# 112 "data/maps/Route1/scripts.pory"
	walk_down
# 112 "data/maps/Route1/scripts.pory"
	walk_down
# 112 "data/maps/Route1/scripts.pory"
	walk_down
# 112 "data/maps/Route1/scripts.pory"
	walk_down
# 112 "data/maps/Route1/scripts.pory"
	walk_down
# 112 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 177 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_0:
# 177 "data/maps/Route1/scripts.pory"
	walk_in_place_down
# 177 "data/maps/Route1/scripts.pory"
	walk_in_place_down
	step_end

# 204 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_0:
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_down
	step_end

# 207 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_1:
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 207 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 208 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_2:
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 208 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 212 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_3:
# 212 "data/maps/Route1/scripts.pory"
	walk_slow_up
# 212 "data/maps/Route1/scripts.pory"
	walk_slow_up
	step_end

# 214 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_4:
# 214 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 214 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 214 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
	step_end

# 259 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_0:
# 259 "data/maps/Route1/scripts.pory"
	emote_exclamation_mark
	step_end

# 260 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_1:
# 260 "data/maps/Route1/scripts.pory"
	delay_16
# 260 "data/maps/Route1/scripts.pory"
	delay_16
# 260 "data/maps/Route1/scripts.pory"
	delay_16
# 260 "data/maps/Route1/scripts.pory"
	walk_down
# 260 "data/maps/Route1/scripts.pory"
	walk_down
# 260 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 275 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_2:
# 275 "data/maps/Route1/scripts.pory"
	walk_down
# 275 "data/maps/Route1/scripts.pory"
	walk_right
# 275 "data/maps/Route1/scripts.pory"
	walk_right
# 275 "data/maps/Route1/scripts.pory"
	walk_right
# 275 "data/maps/Route1/scripts.pory"
	walk_right
# 275 "data/maps/Route1/scripts.pory"
	walk_right
# 275 "data/maps/Route1/scripts.pory"
	walk_right
# 275 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 283 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_3:
# 283 "data/maps/Route1/scripts.pory"
	walk_right
# 283 "data/maps/Route1/scripts.pory"
	walk_right
# 283 "data/maps/Route1/scripts.pory"
	walk_right
# 283 "data/maps/Route1/scripts.pory"
	walk_right
# 283 "data/maps/Route1/scripts.pory"
	walk_right
	step_end

# 287 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_4:
# 287 "data/maps/Route1/scripts.pory"
	walk_up
# 287 "data/maps/Route1/scripts.pory"
	walk_up
# 287 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 309 "data/maps/Route1/scripts.pory"
Route1_trigger_kukui_catching_tutorial_Movement_0:
# 309 "data/maps/Route1/scripts.pory"
	walk_right
	step_end

Route1_LillieWalkToLab_Text_0:
# 33 "data/maps/Route1/scripts.pory"
	.string "Lillie$"

Route1_LillieWalkToLab_Text_1:
# 34 "data/maps/Route1/scripts.pory"
	.string "Oh, Um…\p"
	.string "The professor said…$"

Route1_LillieWalkToLab_Text_2:
# 39 "data/maps/Route1/scripts.pory"
	.string "“Hey there, Lillie!\n"
	.string "Bring me that great new Trainer. Woo!”$"

Route1_LillieWalkToLab_Text_3:
# 43 "data/maps/Route1/scripts.pory"
	.string "So I'm here to show you the way to his\n"
	.string "Pokémon Lab, if you'll come with me!\p"
	.string "It's, um… It's this way.$"

Route1_LillieWalkToLab_Text_4:
# 57 "data/maps/Route1/scripts.pory"
	.string "Mom$"

Route1_LillieWalkToLab_Text_5:
# 58 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}!$"

Route1_LillieWalkToLab_Text_6:
# 61 "data/maps/Route1/scripts.pory"
	.string "Here. A little pocket money for you.\n"
	.string "Don't go wasting it on anything silly!$"

Route1_LillieWalkToLab_Text_7:
# 67 "data/maps/Route1/scripts.pory"
	.string "Oh! Well done, {PLAYER}.\n"
	.string "You're already making friends?\l"
	.string "And what a cute friend you've found!\p"
	.string "I knew Alola would be a great place for\n"
	.string "us. We keep meeting wonderful people!$"

Route1_LillieWalkToLab_Text_8:
# 76 "data/maps/Route1/scripts.pory"
	.string "M-me? Well, thank you…\p"
	.string "My name is Lillie.\n"
	.string "It's very nice to meet you.$"

Route1_LillieWalkToLab_Text_9:
# 84 "data/maps/Route1/scripts.pory"
	.string "Looks like its finally your time to\n"
	.string "shine, sweetie!\p"
	.string "Enjoy yourself out there with\n"
	.string "{STR_VAR_1}.\l"
	.string "And don't be gone too long!$"

Route1_LillieWalkToLab_Text_10:
# 106 "data/maps/Route1/scripts.pory"
	.string "You…have a very nice mother, don't you?\p"
	.string "We should get going.\p"
	.string "It's just south to the Pokémon\n"
	.string "Research Lab.$"

Route1_AlolanMeowthNPC_Text_0:
# 149 "data/maps/Route1/scripts.pory"
	.string "Hsss!$"

Route1_LittleGirlPressB_Text_0:
# 157 "data/maps/Route1/scripts.pory"
	.string "You can go with me!\n"
	.string "If you can dash with {B_BUTTON}!\p"
	.string "What do you think of my song?$"

Route1_Trigger_BlockRightPath_Text_0:
# 169 "data/maps/Route1/scripts.pory"
	.string "Watch it, cuz!\p"
	.string "It's dangerous to get too close to\n"
	.string "a Pokémon while it's using one of\l"
	.string "its moves!$"

Route1_Trigger_BlockRightPath_Text_1:
# 179 "data/maps/Route1/scripts.pory"
	.string "Ruff!$"

LittleGirlChasesMeowthIntro_Text_0:
# 219 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Could anything be more soothing?\n"
	.string "The first evening spent under\l"
	.string "Alola's calm moon!\p"
	.string "I feel like I could stay out here all\n"
	.string "night!$"

LittleGirlChasesMeowthIntro_Text_1:
# 228 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Can't you just feel that warmth?\n"
	.string "The first day spent under Alola's\l"
	.string "sun!\p"
	.string "It's so warm and bright here!$"

LittleGirlChasesMeowthIntro_Text_2:
# 234 "data/maps/Route1/scripts.pory"
	.string "But that's enough of that!\n"
	.string "Time to unpack all these boxes!$"

LittleGirlChasesMeowthIntro_Text_3:
# 238 "data/maps/Route1/scripts.pory"
	.string "Meowth?\n"
	.string "Go get {PLAYER} for me, would you?$"

LittleGirlChasesMeowthIntro_Text_4:
# 243 "data/maps/Route1/scripts.pory"
	.string "Meow?$"

Route1_KukuiCatchingTutorial_Text_0:
# 263 "data/maps/Route1/scripts.pory"
	.string "Kukui$"

Route1_KukuiCatchingTutorial_Text_1:
# 264 "data/maps/Route1/scripts.pory"
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
# 278 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}!\n"
	.string "Hurry it up, cousin!\p"
	.string "Pretend you're a Pokémon and use your\n"
	.string "Agility!$"

MomSaysHi_Text_0:
# 318 "data/maps/Route1/scripts.pory"
	.string "How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_1:
# 347 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 354 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 360 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"

testscript_Text_0:
# 365 "data/maps/Route1/scripts.pory"
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

Route1_Trigger_HeadEastToIkiTown_Text_0:
# 386 "data/maps/Route1/scripts.pory"
	.string "The Iki Town Festival awaits!\n"
	.string "Head east, cousin!$"
