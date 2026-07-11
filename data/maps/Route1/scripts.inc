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
# 14 "data/maps/Route1/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 17, Route1_LillieWalkToLab
	.2byte 0

Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
# 13 "data/maps/Route1/scripts.pory"
	call Route1_KukuiCatchingTutorial
	return


Route1_LillieWalkToLab::
# 18 "data/maps/Route1/scripts.pory"
	lock
# 19 "data/maps/Route1/scripts.pory"
	startcutscene CUTSCENE_ROUTE1_LILLIE_WALK_TO_LAB
# 20 "data/maps/Route1/scripts.pory"
	playse SE_PIN
# 21 "data/maps/Route1/scripts.pory"
	hideobjectat route1_mom, MAP_ROUTE1
# 22 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_0
# 23 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 24 "data/maps/Route1/scripts.pory"
	delay 30
# 25 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_1
# 26 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_2
# 27 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_3
# 28 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 29 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_0
# 30 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_1
# 33 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_4
# 34 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 35 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_2
# 37 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_5
# 38 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 39 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_3, MSGBOX_AUTOCLOSE
# 43 "data/maps/Route1/scripts.pory"
	opendoor 16, 20
# 44 "data/maps/Route1/scripts.pory"
	waitdooranim
# 45 "data/maps/Route1/scripts.pory"
	showobjectat route1_mom, MAP_ROUTE1
# 46 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_6
# 47 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 48 "data/maps/Route1/scripts.pory"
	closedoor 16, 20
# 49 "data/maps/Route1/scripts.pory"
	waitdooranim
# 50 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_7
# 51 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_7
# 52 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 53 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 54 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_5, MSGBOX_AUTOCLOSE
# 55 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_3
# 56 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 57 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_6
# 59 "data/maps/Route1/scripts.pory"
	addmoney 1000
# 60 "data/maps/Route1/scripts.pory"
	delay 30
# 61 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_8
# 62 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 63 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_7
# 69 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_9
# 70 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 71 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_0
# 72 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_8, MSGBOX_AUTOCLOSE
# 76 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_10
# 77 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 78 "data/maps/Route1/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 79 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_9, MSGBOX_AUTOCLOSE
# 85 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_11
# 86 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 87 "data/maps/Route1/scripts.pory"
	opendoor 16, 20
# 88 "data/maps/Route1/scripts.pory"
	waitdooranim
# 89 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_12
# 90 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 91 "data/maps/Route1/scripts.pory"
	hideobjectat route1_mom, MAP_ROUTE1
# 92 "data/maps/Route1/scripts.pory"
	closedoor 16, 20
# 93 "data/maps/Route1/scripts.pory"
	waitdooranim
# 94 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_11
# 95 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 96 "data/maps/Route1/scripts.pory"
	delay 30
# 97 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_5
# 98 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_13
# 99 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 100 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_10, MSGBOX_AUTOCLOSE
# 106 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_14
# 107 "data/maps/Route1/scripts.pory"
	removeobject route1_lillie
# 108 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_ROUTE1_LILLIE
# 109 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 110 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 18
# 111 "data/maps/Route1/scripts.pory"
	endcutscene
# 112 "data/maps/Route1/scripts.pory"
	release
	end


Lillie_WalktoLabSkip::
# 117 "data/maps/Route1/scripts.pory"
	lock
# 118 "data/maps/Route1/scripts.pory"
	closemessage
# 119 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 120 "data/maps/Route1/scripts.pory"
	setobjectxy LOCALID_PLAYER, 16, 24
# 121 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_4
# 122 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 123 "data/maps/Route1/scripts.pory"
	setobjectxy route1_mom, 16, 18
# 124 "data/maps/Route1/scripts.pory"
	removeobject route1_lillie
# 125 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_ROUTE1_LILLIE
# 126 "data/maps/Route1/scripts.pory"
	special StopAllObjectMovements
# 127 "data/maps/Route1/scripts.pory"
	special CloseScriptMenus
# 128 "data/maps/Route1/scripts.pory"
	special SnapCameraToPlayer
# 129 "data/maps/Route1/scripts.pory"
	special RemoveCameraObject
# 130 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 18
# 131 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 132 "data/maps/Route1/scripts.pory"
	release
	end


Route1_AlolanMeowthNPC::
# 137 "data/maps/Route1/scripts.pory"
	lock
# 138 "data/maps/Route1/scripts.pory"
	faceplayer
# 139 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 140 "data/maps/Route1/scripts.pory"
	msgbox Route1_AlolanMeowthNPC_Text_0
# 141 "data/maps/Route1/scripts.pory"
	release
	end


Route1_LittleGirlPressB::
# 146 "data/maps/Route1/scripts.pory"
	lock
# 147 "data/maps/Route1/scripts.pory"
	faceplayer
# 148 "data/maps/Route1/scripts.pory"
	msgbox Route1_LittleGirlPressB_Text_0
# 152 "data/maps/Route1/scripts.pory"
	release
	return


Route1_Trigger_BlockRightPath::
# 157 "data/maps/Route1/scripts.pory"
	lock
# 158 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_LillieWalkToLab_Movement_4
# 159 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 160 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_0
# 165 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_LillieWalkToLab_Movement_4
# 166 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 167 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 168 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_0
# 169 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 170 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_1, MSGBOX_AUTOCLOSE
# 171 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_6
# 172 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 173 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_LillieWalkToLab_Movement_7
# 174 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 175 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_LillieWalkToLab_Movement_7
# 176 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 177 "data/maps/Route1/scripts.pory"
	release
	end


Route1CloseGates::
# 182 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_closed
	return


Route1CloseGates2::
# 187 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_leftclosed
	return


LittleGirlChasesMeowthIntro::
# 192 "data/maps/Route1/scripts.pory"
	lock
# 193 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 194 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 195 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_0
# 196 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_0
# 197 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 198 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_1
# 199 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_2
# 200 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 201 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 202 "data/maps/Route1/scripts.pory"
	delay 60
# 203 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_3
# 204 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 205 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_4
# 206 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 207 "data/maps/Route1/scripts.pory"
	gettimeofday
# 208 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 208 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 218 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 219 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_1
LittleGirlChasesMeowthIntro_1:
# 225 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_2
# 227 "data/maps/Route1/scripts.pory"
	applymovement momintro, Route1_LillieWalkToLab_Movement_7
# 228 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 229 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_3
# 231 "data/maps/Route1/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 232 "data/maps/Route1/scripts.pory"
	waitmessage
# 233 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 234 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_4
# 235 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 236 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 237 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 238 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS3
# 239 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_INTRO_UR
# 240 "data/maps/Route1/scripts.pory"
	warp MAP_PLAYER_ROOM, 12, 10
# 241 "data/maps/Route1/scripts.pory"
	waitstate
# 242 "data/maps/Route1/scripts.pory"
	release
	end

LittleGirlChasesMeowthIntro_2:
# 209 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 210 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_0
	goto LittleGirlChasesMeowthIntro_1


Route1_KukuiCatchingTutorial::
# 247 "data/maps/Route1/scripts.pory"
	lock
# 248 "data/maps/Route1/scripts.pory"
	playse SE_PIN
# 249 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 250 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_0
# 251 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1_KukuiCatchingTutorial_Movement_1
# 252 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 253 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 254 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_1, MSGBOX_AUTOCLOSE
# 265 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_2
# 266 "data/maps/Route1/scripts.pory"
	waitmovement catchingintrokukui
# 267 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 268 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_2, MSGBOX_AUTOCLOSE
# 273 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_3
# 274 "data/maps/Route1/scripts.pory"
	waitmovement catchingintrokukui
# 275 "data/maps/Route1/scripts.pory"
	removeobject catchingintrokukui
# 276 "data/maps/Route1/scripts.pory"
	delay 30
# 277 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1_KukuiCatchingTutorial_Movement_4
# 278 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 279 "data/maps/Route1/scripts.pory"
	special RemoveCameraObject
# 280 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 11
# 281 "data/maps/Route1/scripts.pory"
	setflag FLAG_KUKUI_CATCHING_TUTORIAL1
# 282 "data/maps/Route1/scripts.pory"
	clearflag FLAG_KUKUI_CATCHING_TUTORIAL2
# 283 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 284 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 285 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_REGULARNPCS
# 286 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_INTRO_UR
# 287 "data/maps/Route1/scripts.pory"
	release
	end


Route1_trigger_kukui_catching_tutorial::
# 292 "data/maps/Route1/scripts.pory"
	lock
# 293 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 294 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_2
# 299 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_trigger_kukui_catching_tutorial_Movement_0
# 300 "data/maps/Route1/scripts.pory"
	release
	end


MomSaysHi::
# 305 "data/maps/Route1/scripts.pory"
	lock
# 306 "data/maps/Route1/scripts.pory"
	faceplayer
# 307 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 308 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_0
# 309 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 310 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 311 "data/maps/Route1/scripts.pory"
	waitfanfare
# 312 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 313 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 314 "data/maps/Route1/scripts.pory"
	setflag FLAG_ENABLE_STAT_EDITOR
# 315 "data/maps/Route1/scripts.pory"
	setflag FLAG_PORTABLE_PC_TOGGLE
# 316 "data/maps/Route1/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 317 "data/maps/Route1/scripts.pory"
	setflag FLAG_EGG_MOVES
# 318 "data/maps/Route1/scripts.pory"
	setflag FLAG_TUTOR_MOVES
# 319 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_SHINY_RIDE, MomSaysHi_2
# 325 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_RIDE
# 326 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_SURF
MomSaysHi_1:
# 328 "data/maps/Route1/scripts.pory"
	compare VAR_ROTOM_PHONE_ENABLE, 1
	goto_if_lt MomSaysHi_6
# 333 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 0
MomSaysHi_5:
# 335 "data/maps/Route1/scripts.pory"
	release
# 336 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 337 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 338 "data/maps/Route1/scripts.pory"
	release
	end

MomSaysHi_2:
# 321 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_RIDE
# 322 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_SURF
	goto MomSaysHi_1

MomSaysHi_6:
# 330 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
	goto MomSaysHi_5


Mailbox::
# 343 "data/maps/Route1/scripts.pory"
	lock
# 344 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
# 345 "data/maps/Route1/scripts.pory"
	release
	end


Route1LittleBoyNPC::
# 350 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


testscript::
# 355 "data/maps/Route1/scripts.pory"
	msgbox testscript_Text_0, MSGBOX_NPC
	end


Route1_Trigger_HeadEastToIkiTown::
# 375 "data/maps/Route1/scripts.pory"
	lock
# 376 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_HeadEastToIkiTown_Text_0, MSGBOX_AUTOCLOSE
# 378 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_trigger_kukui_catching_tutorial_Movement_0
# 379 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 380 "data/maps/Route1/scripts.pory"
	release
	end


# 22 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_0:
# 22 "data/maps/Route1/scripts.pory"
	emote_exclamation_mark
# 22 "data/maps/Route1/scripts.pory"
	face_up
	step_end

# 25 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_1:
# 25 "data/maps/Route1/scripts.pory"
	walk_down
# 25 "data/maps/Route1/scripts.pory"
	walk_down
# 25 "data/maps/Route1/scripts.pory"
	walk_down
# 25 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 26 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_2:
# 26 "data/maps/Route1/scripts.pory"
	delay_16
# 26 "data/maps/Route1/scripts.pory"
	delay_16
# 26 "data/maps/Route1/scripts.pory"
	delay_16
# 26 "data/maps/Route1/scripts.pory"
	face_right
	step_end

# 27 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_3:
# 27 "data/maps/Route1/scripts.pory"
	walk_down
# 27 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 33 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_4:
# 33 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 37 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_5:
# 37 "data/maps/Route1/scripts.pory"
	face_right
	step_end

# 46 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_6:
# 46 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 50 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_7:
# 50 "data/maps/Route1/scripts.pory"
	face_up
	step_end

# 61 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_8:
# 61 "data/maps/Route1/scripts.pory"
	walk_left
# 61 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 69 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_9:
# 69 "data/maps/Route1/scripts.pory"
	walk_in_place_up
# 69 "data/maps/Route1/scripts.pory"
	walk_in_place_up
	step_end

# 76 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_10:
# 76 "data/maps/Route1/scripts.pory"
	walk_right
# 76 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 85 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_11:
# 85 "data/maps/Route1/scripts.pory"
	walk_up
# 85 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 89 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_12:
# 89 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 98 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_13:
# 98 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 106 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_14:
# 106 "data/maps/Route1/scripts.pory"
	walk_left
# 106 "data/maps/Route1/scripts.pory"
	walk_left
# 106 "data/maps/Route1/scripts.pory"
	walk_left
# 106 "data/maps/Route1/scripts.pory"
	walk_left
# 106 "data/maps/Route1/scripts.pory"
	walk_left
# 106 "data/maps/Route1/scripts.pory"
	walk_left
# 106 "data/maps/Route1/scripts.pory"
	walk_down
# 106 "data/maps/Route1/scripts.pory"
	walk_down
# 106 "data/maps/Route1/scripts.pory"
	walk_down
# 106 "data/maps/Route1/scripts.pory"
	walk_down
# 106 "data/maps/Route1/scripts.pory"
	walk_down
# 106 "data/maps/Route1/scripts.pory"
	walk_down
# 106 "data/maps/Route1/scripts.pory"
	walk_down
# 106 "data/maps/Route1/scripts.pory"
	walk_down
# 106 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 168 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_0:
# 168 "data/maps/Route1/scripts.pory"
	walk_in_place_down
# 168 "data/maps/Route1/scripts.pory"
	walk_in_place_down
	step_end

# 195 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_0:
# 195 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 195 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 195 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 195 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 195 "data/maps/Route1/scripts.pory"
	walk_fast_down
	step_end

# 198 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_1:
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 198 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 199 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_2:
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 199 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 203 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_3:
# 203 "data/maps/Route1/scripts.pory"
	walk_slow_up
# 203 "data/maps/Route1/scripts.pory"
	walk_slow_up
	step_end

# 205 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_4:
# 205 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 205 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 205 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
	step_end

# 250 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_0:
# 250 "data/maps/Route1/scripts.pory"
	emote_exclamation_mark
	step_end

# 251 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_1:
# 251 "data/maps/Route1/scripts.pory"
	delay_16
# 251 "data/maps/Route1/scripts.pory"
	delay_16
# 251 "data/maps/Route1/scripts.pory"
	delay_16
# 251 "data/maps/Route1/scripts.pory"
	walk_down
# 251 "data/maps/Route1/scripts.pory"
	walk_down
# 251 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 265 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_2:
# 265 "data/maps/Route1/scripts.pory"
	walk_down
# 265 "data/maps/Route1/scripts.pory"
	walk_right
# 265 "data/maps/Route1/scripts.pory"
	walk_right
# 265 "data/maps/Route1/scripts.pory"
	walk_right
# 265 "data/maps/Route1/scripts.pory"
	walk_right
# 265 "data/maps/Route1/scripts.pory"
	walk_right
# 265 "data/maps/Route1/scripts.pory"
	walk_right
# 265 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 273 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_3:
# 273 "data/maps/Route1/scripts.pory"
	walk_right
# 273 "data/maps/Route1/scripts.pory"
	walk_right
# 273 "data/maps/Route1/scripts.pory"
	walk_right
# 273 "data/maps/Route1/scripts.pory"
	walk_right
# 273 "data/maps/Route1/scripts.pory"
	walk_right
	step_end

# 277 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_4:
# 277 "data/maps/Route1/scripts.pory"
	walk_up
# 277 "data/maps/Route1/scripts.pory"
	walk_up
# 277 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 299 "data/maps/Route1/scripts.pory"
Route1_trigger_kukui_catching_tutorial_Movement_0:
# 299 "data/maps/Route1/scripts.pory"
	walk_right
	step_end

Route1_LillieWalkToLab_Text_0:
# 29 "data/maps/Route1/scripts.pory"
	.string "Lillie$"

Route1_LillieWalkToLab_Text_1:
# 30 "data/maps/Route1/scripts.pory"
	.string "Oh, Um…\p"
	.string "The professor said…$"

Route1_LillieWalkToLab_Text_2:
# 35 "data/maps/Route1/scripts.pory"
	.string "“Hey there, Lillie!\n"
	.string "Bring me that great new Trainer. Woo!”$"

Route1_LillieWalkToLab_Text_3:
# 39 "data/maps/Route1/scripts.pory"
	.string "So I'm here to show you the way to his\n"
	.string "Pokémon Lab, if you'll come with me!\p"
	.string "It's, um… It's this way.$"

Route1_LillieWalkToLab_Text_4:
# 53 "data/maps/Route1/scripts.pory"
	.string "Mom$"

Route1_LillieWalkToLab_Text_5:
# 54 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}!$"

Route1_LillieWalkToLab_Text_6:
# 57 "data/maps/Route1/scripts.pory"
	.string "Here. A little pocket money for you.\n"
	.string "Don't go wasting it on anything silly!$"

Route1_LillieWalkToLab_Text_7:
# 63 "data/maps/Route1/scripts.pory"
	.string "Oh! Well done, {PLAYER}.\n"
	.string "You're already making friends?\l"
	.string "And what a cute friend you've found!\p"
	.string "I knew Alola would be a great place for\n"
	.string "us. We keep meeting wonderful people!$"

Route1_LillieWalkToLab_Text_8:
# 72 "data/maps/Route1/scripts.pory"
	.string "M-me? Well, thank you…\p"
	.string "My name is Lillie.\n"
	.string "It's very nice to meet you.$"

Route1_LillieWalkToLab_Text_9:
# 79 "data/maps/Route1/scripts.pory"
	.string "Looks like its finally your time to\n"
	.string "shine, sweetie!\p"
	.string "Enjoy yourself out there with\n"
	.string "{STR_VAR_1}.\l"
	.string "And don't be gone too long!$"

Route1_LillieWalkToLab_Text_10:
# 100 "data/maps/Route1/scripts.pory"
	.string "You…have a very nice mother, don't you?\p"
	.string "We should get going.\p"
	.string "It's just south to the Pokémon\n"
	.string "Research Lab.$"

Route1_AlolanMeowthNPC_Text_0:
# 140 "data/maps/Route1/scripts.pory"
	.string "Hsss!$"

Route1_LittleGirlPressB_Text_0:
# 148 "data/maps/Route1/scripts.pory"
	.string "You can go with me!\n"
	.string "If you can dash with {B_BUTTON}!\p"
	.string "What do you think of my song?$"

Route1_Trigger_BlockRightPath_Text_0:
# 160 "data/maps/Route1/scripts.pory"
	.string "Watch it, cuz!\p"
	.string "It's dangerous to get too close to\n"
	.string "a Pokémon while it's using one of\l"
	.string "its moves!$"

Route1_Trigger_BlockRightPath_Text_1:
# 170 "data/maps/Route1/scripts.pory"
	.string "Ruff!$"

LittleGirlChasesMeowthIntro_Text_0:
# 210 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Could anything be more soothing?\n"
	.string "The first evening spent under\l"
	.string "Alola's calm moon!\p"
	.string "I feel like I could stay out here all\n"
	.string "night!$"

LittleGirlChasesMeowthIntro_Text_1:
# 219 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Can't you just feel that warmth?\n"
	.string "The first day spent under Alola's\l"
	.string "sun!\p"
	.string "It's so warm and bright here!$"

LittleGirlChasesMeowthIntro_Text_2:
# 225 "data/maps/Route1/scripts.pory"
	.string "But that's enough of that!\n"
	.string "Time to unpack all these boxes!$"

LittleGirlChasesMeowthIntro_Text_3:
# 229 "data/maps/Route1/scripts.pory"
	.string "Meowth?\n"
	.string "Go get {PLAYER} for me, would you?$"

LittleGirlChasesMeowthIntro_Text_4:
# 234 "data/maps/Route1/scripts.pory"
	.string "Meow?$"

Route1_KukuiCatchingTutorial_Text_0:
# 253 "data/maps/Route1/scripts.pory"
	.string "Kukui$"

Route1_KukuiCatchingTutorial_Text_1:
# 254 "data/maps/Route1/scripts.pory"
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
# 268 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}!\n"
	.string "Hurry it up, cousin!\p"
	.string "Pretend you're a Pokémon and use your\n"
	.string "Agility!$"

MomSaysHi_Text_0:
# 308 "data/maps/Route1/scripts.pory"
	.string "How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_1:
# 337 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 344 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 350 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"

testscript_Text_0:
# 355 "data/maps/Route1/scripts.pory"
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
# 376 "data/maps/Route1/scripts.pory"
	.string "The Iki Town Festival awaits!\n"
	.string "Head east, cousin!$"
