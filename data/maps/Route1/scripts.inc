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
	delay 15
# 30 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_0
# 31 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_1
# 34 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_4
# 35 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 36 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_2
# 38 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_5
# 39 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 40 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_3, MSGBOX_AUTOCLOSE
# 44 "data/maps/Route1/scripts.pory"
	opendoor 16, 20
# 45 "data/maps/Route1/scripts.pory"
	waitdooranim
# 46 "data/maps/Route1/scripts.pory"
	showobjectat route1_mom, MAP_ROUTE1
# 47 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_6
# 48 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 49 "data/maps/Route1/scripts.pory"
	closedoor 16, 20
# 50 "data/maps/Route1/scripts.pory"
	waitdooranim
# 51 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_7
# 52 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_7
# 53 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 54 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 55 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_5, MSGBOX_AUTOCLOSE
# 56 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_3
# 57 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 58 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_6
# 60 "data/maps/Route1/scripts.pory"
	addmoney 1000
# 61 "data/maps/Route1/scripts.pory"
	delay 30
# 62 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_8
# 63 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 64 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_7
# 70 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_9
# 71 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 72 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_0
# 73 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_8, MSGBOX_AUTOCLOSE
# 77 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_10
# 78 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 79 "data/maps/Route1/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 80 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 81 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_9, MSGBOX_AUTOCLOSE
# 87 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_11
# 88 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 89 "data/maps/Route1/scripts.pory"
	opendoor 16, 20
# 90 "data/maps/Route1/scripts.pory"
	waitdooranim
# 91 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_12
# 92 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 93 "data/maps/Route1/scripts.pory"
	hideobjectat route1_mom, MAP_ROUTE1
# 94 "data/maps/Route1/scripts.pory"
	closedoor 16, 20
# 95 "data/maps/Route1/scripts.pory"
	waitdooranim
# 96 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_11
# 97 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 98 "data/maps/Route1/scripts.pory"
	delay 30
# 99 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_5
# 100 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_13
# 101 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 102 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_0
# 103 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_10, MSGBOX_AUTOCLOSE
# 109 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_14
# 110 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 111 "data/maps/Route1/scripts.pory"
	removeobject route1_lillie
# 112 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_ROUTE1_LILLIE
# 113 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 114 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 18
# 115 "data/maps/Route1/scripts.pory"
	endcutscene
# 116 "data/maps/Route1/scripts.pory"
	release
	end


Lillie_WalktoLabSkip::
# 121 "data/maps/Route1/scripts.pory"
	lock
# 122 "data/maps/Route1/scripts.pory"
	closemessage
# 123 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 124 "data/maps/Route1/scripts.pory"
	setobjectxy LOCALID_PLAYER, 16, 24
# 125 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_4
# 126 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 127 "data/maps/Route1/scripts.pory"
	setobjectxy route1_mom, 16, 18
# 128 "data/maps/Route1/scripts.pory"
	removeobject route1_lillie
# 129 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_ROUTE1_LILLIE
# 130 "data/maps/Route1/scripts.pory"
	special StopAllObjectMovements
# 131 "data/maps/Route1/scripts.pory"
	special CloseScriptMenus
# 132 "data/maps/Route1/scripts.pory"
	special SnapCameraToPlayer
# 133 "data/maps/Route1/scripts.pory"
	special RemoveCameraObject
# 134 "data/maps/Route1/scripts.pory"
	setobjectxy route1_mom, 16, 18
# 135 "data/maps/Route1/scripts.pory"
	setobjectxy HauoliOutskirtsLittleBoy, 14, 31
# 136 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 18
# 137 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 138 "data/maps/Route1/scripts.pory"
	release
	end


Route1_AlolanMeowthNPC::
# 143 "data/maps/Route1/scripts.pory"
	lock
# 144 "data/maps/Route1/scripts.pory"
	faceplayer
# 145 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 146 "data/maps/Route1/scripts.pory"
	msgbox Route1_AlolanMeowthNPC_Text_0
# 147 "data/maps/Route1/scripts.pory"
	release
	end


Route1_LittleGirlPressB::
# 152 "data/maps/Route1/scripts.pory"
	lock
# 153 "data/maps/Route1/scripts.pory"
	faceplayer
# 154 "data/maps/Route1/scripts.pory"
	msgbox Route1_LittleGirlPressB_Text_0
# 158 "data/maps/Route1/scripts.pory"
	release
	return


Route1_Trigger_BlockRightPath::
# 163 "data/maps/Route1/scripts.pory"
	lock
# 164 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_LillieWalkToLab_Movement_4
# 165 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 166 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_0
# 171 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_LillieWalkToLab_Movement_4
# 172 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 173 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 174 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_0
# 175 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 176 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_1, MSGBOX_AUTOCLOSE
# 177 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_6
# 178 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 179 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_LillieWalkToLab_Movement_7
# 180 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 181 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_LillieWalkToLab_Movement_7
# 182 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 183 "data/maps/Route1/scripts.pory"
	release
	end


Route1CloseGates::
# 188 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_closed
	return


Route1CloseGates2::
# 193 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_leftclosed
	return


LittleGirlChasesMeowthIntro::
# 198 "data/maps/Route1/scripts.pory"
	lock
# 199 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 200 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 201 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_0
# 202 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_0
# 203 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 204 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_1
# 205 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_2
# 206 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 207 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 208 "data/maps/Route1/scripts.pory"
	delay 60
# 209 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_3
# 210 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 211 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_4
# 212 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 213 "data/maps/Route1/scripts.pory"
	gettimeofday
# 214 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 214 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 224 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 225 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_1
LittleGirlChasesMeowthIntro_1:
# 231 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_2
# 233 "data/maps/Route1/scripts.pory"
	applymovement momintro, Route1_LillieWalkToLab_Movement_7
# 234 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 235 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_3
# 237 "data/maps/Route1/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 238 "data/maps/Route1/scripts.pory"
	waitmessage
# 239 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 240 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_4
# 241 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 242 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 243 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 244 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS3
# 245 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_INTRO_UR
# 246 "data/maps/Route1/scripts.pory"
	warp MAP_PLAYER_ROOM, 12, 10
# 247 "data/maps/Route1/scripts.pory"
	waitstate
# 248 "data/maps/Route1/scripts.pory"
	release
	end

LittleGirlChasesMeowthIntro_2:
# 215 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 216 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_0
	goto LittleGirlChasesMeowthIntro_1


Route1_KukuiCatchingTutorial::
# 253 "data/maps/Route1/scripts.pory"
	lock
# 254 "data/maps/Route1/scripts.pory"
	playse SE_PIN
# 255 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 256 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_0
# 257 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1_KukuiCatchingTutorial_Movement_1
# 258 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 259 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 260 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_1, MSGBOX_AUTOCLOSE
# 271 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_2
# 272 "data/maps/Route1/scripts.pory"
	waitmovement catchingintrokukui
# 273 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 274 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_2, MSGBOX_AUTOCLOSE
# 279 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_3
# 280 "data/maps/Route1/scripts.pory"
	waitmovement catchingintrokukui
# 281 "data/maps/Route1/scripts.pory"
	removeobject catchingintrokukui
# 282 "data/maps/Route1/scripts.pory"
	delay 30
# 283 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1_KukuiCatchingTutorial_Movement_4
# 284 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 285 "data/maps/Route1/scripts.pory"
	special RemoveCameraObject
# 286 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 11
# 287 "data/maps/Route1/scripts.pory"
	setflag FLAG_KUKUI_CATCHING_TUTORIAL1
# 288 "data/maps/Route1/scripts.pory"
	clearflag FLAG_KUKUI_CATCHING_TUTORIAL2
# 289 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 290 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 291 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_REGULARNPCS
# 292 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_INTRO_UR
# 293 "data/maps/Route1/scripts.pory"
	release
	end


Route1_trigger_kukui_catching_tutorial::
# 298 "data/maps/Route1/scripts.pory"
	lock
# 299 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 300 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_2
# 305 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_trigger_kukui_catching_tutorial_Movement_0
# 306 "data/maps/Route1/scripts.pory"
	release
	end


MomSaysHi::
# 311 "data/maps/Route1/scripts.pory"
	lock
# 312 "data/maps/Route1/scripts.pory"
	faceplayer
# 313 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 314 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_0
# 315 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 316 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 317 "data/maps/Route1/scripts.pory"
	waitfanfare
# 318 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 319 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 320 "data/maps/Route1/scripts.pory"
	setflag FLAG_ENABLE_STAT_EDITOR
# 321 "data/maps/Route1/scripts.pory"
	setflag FLAG_PORTABLE_PC_TOGGLE
# 322 "data/maps/Route1/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 323 "data/maps/Route1/scripts.pory"
	setflag FLAG_EGG_MOVES
# 324 "data/maps/Route1/scripts.pory"
	setflag FLAG_TUTOR_MOVES
# 325 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_SHINY_RIDE, MomSaysHi_2
# 331 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_RIDE
# 332 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_SURF
MomSaysHi_1:
# 334 "data/maps/Route1/scripts.pory"
	compare VAR_ROTOM_PHONE_ENABLE, 1
	goto_if_lt MomSaysHi_6
# 339 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 0
MomSaysHi_5:
# 341 "data/maps/Route1/scripts.pory"
	release
# 342 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 343 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 344 "data/maps/Route1/scripts.pory"
	release
	end

MomSaysHi_2:
# 327 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_RIDE
# 328 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_SURF
	goto MomSaysHi_1

MomSaysHi_6:
# 336 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
	goto MomSaysHi_5


Mailbox::
# 349 "data/maps/Route1/scripts.pory"
	lock
# 350 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
# 351 "data/maps/Route1/scripts.pory"
	release
	end


Route1LittleBoyNPC::
# 356 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


testscript::
# 361 "data/maps/Route1/scripts.pory"
	msgbox testscript_Text_0, MSGBOX_NPC
	end


Route1_Trigger_HeadEastToIkiTown::
# 381 "data/maps/Route1/scripts.pory"
	lock
# 382 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_HeadEastToIkiTown_Text_0, MSGBOX_AUTOCLOSE
# 384 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_trigger_kukui_catching_tutorial_Movement_0
# 385 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 386 "data/maps/Route1/scripts.pory"
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

# 34 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_4:
# 34 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 38 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_5:
# 38 "data/maps/Route1/scripts.pory"
	face_right
	step_end

# 47 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_6:
# 47 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 51 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_7:
# 51 "data/maps/Route1/scripts.pory"
	face_up
	step_end

# 62 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_8:
# 62 "data/maps/Route1/scripts.pory"
	walk_left
# 62 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 70 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_9:
# 70 "data/maps/Route1/scripts.pory"
	walk_in_place_up
# 70 "data/maps/Route1/scripts.pory"
	walk_in_place_up
	step_end

# 77 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_10:
# 77 "data/maps/Route1/scripts.pory"
	walk_right
# 77 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 87 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_11:
# 87 "data/maps/Route1/scripts.pory"
	walk_up
# 87 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 91 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_12:
# 91 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 100 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_13:
# 100 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 109 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_14:
# 109 "data/maps/Route1/scripts.pory"
	walk_left
# 109 "data/maps/Route1/scripts.pory"
	walk_left
# 109 "data/maps/Route1/scripts.pory"
	walk_left
# 109 "data/maps/Route1/scripts.pory"
	walk_left
# 109 "data/maps/Route1/scripts.pory"
	walk_left
# 109 "data/maps/Route1/scripts.pory"
	walk_left
# 109 "data/maps/Route1/scripts.pory"
	walk_down
# 109 "data/maps/Route1/scripts.pory"
	walk_down
# 109 "data/maps/Route1/scripts.pory"
	walk_down
# 109 "data/maps/Route1/scripts.pory"
	walk_down
# 109 "data/maps/Route1/scripts.pory"
	walk_down
# 109 "data/maps/Route1/scripts.pory"
	walk_down
# 109 "data/maps/Route1/scripts.pory"
	walk_down
# 109 "data/maps/Route1/scripts.pory"
	walk_down
# 109 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 174 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_0:
# 174 "data/maps/Route1/scripts.pory"
	walk_in_place_down
# 174 "data/maps/Route1/scripts.pory"
	walk_in_place_down
	step_end

# 201 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_0:
# 201 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 201 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 201 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 201 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 201 "data/maps/Route1/scripts.pory"
	walk_fast_down
	step_end

# 204 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_1:
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 204 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 205 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_2:
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 205 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 209 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_3:
# 209 "data/maps/Route1/scripts.pory"
	walk_slow_up
# 209 "data/maps/Route1/scripts.pory"
	walk_slow_up
	step_end

# 211 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_4:
# 211 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 211 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 211 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
	step_end

# 256 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_0:
# 256 "data/maps/Route1/scripts.pory"
	emote_exclamation_mark
	step_end

# 257 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_1:
# 257 "data/maps/Route1/scripts.pory"
	delay_16
# 257 "data/maps/Route1/scripts.pory"
	delay_16
# 257 "data/maps/Route1/scripts.pory"
	delay_16
# 257 "data/maps/Route1/scripts.pory"
	walk_down
# 257 "data/maps/Route1/scripts.pory"
	walk_down
# 257 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 271 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_2:
# 271 "data/maps/Route1/scripts.pory"
	walk_down
# 271 "data/maps/Route1/scripts.pory"
	walk_right
# 271 "data/maps/Route1/scripts.pory"
	walk_right
# 271 "data/maps/Route1/scripts.pory"
	walk_right
# 271 "data/maps/Route1/scripts.pory"
	walk_right
# 271 "data/maps/Route1/scripts.pory"
	walk_right
# 271 "data/maps/Route1/scripts.pory"
	walk_right
# 271 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 279 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_3:
# 279 "data/maps/Route1/scripts.pory"
	walk_right
# 279 "data/maps/Route1/scripts.pory"
	walk_right
# 279 "data/maps/Route1/scripts.pory"
	walk_right
# 279 "data/maps/Route1/scripts.pory"
	walk_right
# 279 "data/maps/Route1/scripts.pory"
	walk_right
	step_end

# 283 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_4:
# 283 "data/maps/Route1/scripts.pory"
	walk_up
# 283 "data/maps/Route1/scripts.pory"
	walk_up
# 283 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 305 "data/maps/Route1/scripts.pory"
Route1_trigger_kukui_catching_tutorial_Movement_0:
# 305 "data/maps/Route1/scripts.pory"
	walk_right
	step_end

Route1_LillieWalkToLab_Text_0:
# 30 "data/maps/Route1/scripts.pory"
	.string "Lillie$"

Route1_LillieWalkToLab_Text_1:
# 31 "data/maps/Route1/scripts.pory"
	.string "Oh, Um…\p"
	.string "The professor said…$"

Route1_LillieWalkToLab_Text_2:
# 36 "data/maps/Route1/scripts.pory"
	.string "“Hey there, Lillie!\n"
	.string "Bring me that great new Trainer. Woo!”$"

Route1_LillieWalkToLab_Text_3:
# 40 "data/maps/Route1/scripts.pory"
	.string "So I'm here to show you the way to his\n"
	.string "Pokémon Lab, if you'll come with me!\p"
	.string "It's, um… It's this way.$"

Route1_LillieWalkToLab_Text_4:
# 54 "data/maps/Route1/scripts.pory"
	.string "Mom$"

Route1_LillieWalkToLab_Text_5:
# 55 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}!$"

Route1_LillieWalkToLab_Text_6:
# 58 "data/maps/Route1/scripts.pory"
	.string "Here. A little pocket money for you.\n"
	.string "Don't go wasting it on anything silly!$"

Route1_LillieWalkToLab_Text_7:
# 64 "data/maps/Route1/scripts.pory"
	.string "Oh! Well done, {PLAYER}.\n"
	.string "You're already making friends?\l"
	.string "And what a cute friend you've found!\p"
	.string "I knew Alola would be a great place for\n"
	.string "us. We keep meeting wonderful people!$"

Route1_LillieWalkToLab_Text_8:
# 73 "data/maps/Route1/scripts.pory"
	.string "M-me? Well, thank you…\p"
	.string "My name is Lillie.\n"
	.string "It's very nice to meet you.$"

Route1_LillieWalkToLab_Text_9:
# 81 "data/maps/Route1/scripts.pory"
	.string "Looks like its finally your time to\n"
	.string "shine, sweetie!\p"
	.string "Enjoy yourself out there with\n"
	.string "{STR_VAR_1}.\l"
	.string "And don't be gone too long!$"

Route1_LillieWalkToLab_Text_10:
# 103 "data/maps/Route1/scripts.pory"
	.string "You…have a very nice mother, don't you?\p"
	.string "We should get going.\p"
	.string "It's just south to the Pokémon\n"
	.string "Research Lab.$"

Route1_AlolanMeowthNPC_Text_0:
# 146 "data/maps/Route1/scripts.pory"
	.string "Hsss!$"

Route1_LittleGirlPressB_Text_0:
# 154 "data/maps/Route1/scripts.pory"
	.string "You can go with me!\n"
	.string "If you can dash with {B_BUTTON}!\p"
	.string "What do you think of my song?$"

Route1_Trigger_BlockRightPath_Text_0:
# 166 "data/maps/Route1/scripts.pory"
	.string "Watch it, cuz!\p"
	.string "It's dangerous to get too close to\n"
	.string "a Pokémon while it's using one of\l"
	.string "its moves!$"

Route1_Trigger_BlockRightPath_Text_1:
# 176 "data/maps/Route1/scripts.pory"
	.string "Ruff!$"

LittleGirlChasesMeowthIntro_Text_0:
# 216 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Could anything be more soothing?\n"
	.string "The first evening spent under\l"
	.string "Alola's calm moon!\p"
	.string "I feel like I could stay out here all\n"
	.string "night!$"

LittleGirlChasesMeowthIntro_Text_1:
# 225 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Can't you just feel that warmth?\n"
	.string "The first day spent under Alola's\l"
	.string "sun!\p"
	.string "It's so warm and bright here!$"

LittleGirlChasesMeowthIntro_Text_2:
# 231 "data/maps/Route1/scripts.pory"
	.string "But that's enough of that!\n"
	.string "Time to unpack all these boxes!$"

LittleGirlChasesMeowthIntro_Text_3:
# 235 "data/maps/Route1/scripts.pory"
	.string "Meowth?\n"
	.string "Go get {PLAYER} for me, would you?$"

LittleGirlChasesMeowthIntro_Text_4:
# 240 "data/maps/Route1/scripts.pory"
	.string "Meow?$"

Route1_KukuiCatchingTutorial_Text_0:
# 259 "data/maps/Route1/scripts.pory"
	.string "Kukui$"

Route1_KukuiCatchingTutorial_Text_1:
# 260 "data/maps/Route1/scripts.pory"
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
# 274 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}!\n"
	.string "Hurry it up, cousin!\p"
	.string "Pretend you're a Pokémon and use your\n"
	.string "Agility!$"

MomSaysHi_Text_0:
# 314 "data/maps/Route1/scripts.pory"
	.string "How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_1:
# 343 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 350 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 356 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"

testscript_Text_0:
# 361 "data/maps/Route1/scripts.pory"
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
# 382 "data/maps/Route1/scripts.pory"
	.string "The Iki Town Festival awaits!\n"
	.string "Head east, cousin!$"
