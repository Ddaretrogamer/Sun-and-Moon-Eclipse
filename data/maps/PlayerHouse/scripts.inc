PlayerHouse_MapScripts::
# 2 "data/maps/PlayerHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 30 "data/maps/PlayerHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 35 "data/maps/PlayerHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/PlayerHouse/scripts.pory"
	callnative Script_IsLeadMonShiny
# 4 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 12 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 20 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 5 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
# 9 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( ROWLET )
	goto PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 13 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
# 17 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LITTEN )
	goto PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 21 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_14
# 25 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( POPPLIO )
	goto PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 6 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( ROWLET )
	goto PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
# 14 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( LITTEN )
	goto PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
# 22 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( POPPLIO )
	goto PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 30 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
# 32 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 8, PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1
	.2byte 0

PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 30 "data/maps/PlayerHouse/scripts.pory"
	hideobjectat playerhousemom2, MAP_PLAYER_HOUSE
# 31 "data/maps/PlayerHouse/scripts.pory"
	hideobjectat playerhousemeowth2, MAP_PLAYER_HOUSE
	return

PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
# 32 "data/maps/PlayerHouse/scripts.pory"
	clearflag FLAG_HIDE_PLAYERHOUSE_STARTER
# 33 "data/maps/PlayerHouse/scripts.pory"
	addobject playerhousestarter
# 34 "data/maps/PlayerHouse/scripts.pory"
	setobjectxy playerhousemom3, 5, 10
	return

PlayerHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 35 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 VAR_MOM_IN_HOUSE_INTRO, 1, PlayerHouse_MomNewgame
# 36 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 VAR_MOM_IN_HOUSE_INTRO, 3, PlayerHouse_GotRunningShoes
# 37 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 8, PlayerHouse_ShowMomPokemon
# 38 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 15, Playerhouse_WelcomeHomeAfterFestival
	.2byte 0


Playerhouse_WelcomeHomeAfterFestival::
# 43 "data/maps/PlayerHouse/scripts.pory"
	lock
# 44 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, Playerhouse_WelcomeHomeAfterFestival_Movement_0
# 45 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 46 "data/maps/PlayerHouse/scripts.pory"
	msgbox Playerhouse_WelcomeHomeAfterFestival_Text_1, MSGBOX_AUTOCLOSE
# 47 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 48 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 49 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemeowth3, Playerhouse_WelcomeHomeAfterFestival_Movement_1
# 50 "data/maps/PlayerHouse/scripts.pory"
	msgbox Playerhouse_WelcomeHomeAfterFestival_Text_2, MSGBOX_AUTOCLOSE
# 51 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemeowth3
# 52 "data/maps/PlayerHouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 53 "data/maps/PlayerHouse/scripts.pory"
	delay 60
# 54 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 55 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom3, Playerhouse_WelcomeHomeAfterFestival_Movement_2
# 56 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom3
# 57 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 58 "data/maps/PlayerHouse/scripts.pory"
	msgbox Playerhouse_WelcomeHomeAfterFestival_Text_3, MSGBOX_AUTOCLOSE
# 61 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom3, Playerhouse_WelcomeHomeAfterFestival_Movement_3
# 62 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemeowth3, Playerhouse_WelcomeHomeAfterFestival_Movement_4
# 63 "data/maps/PlayerHouse/scripts.pory"
	waitmovement 0
# 64 "data/maps/PlayerHouse/scripts.pory"
	checkplayergender
# 65 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Playerhouse_WelcomeHomeAfterFestival_2
# 75 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 76 "data/maps/PlayerHouse/scripts.pory"
	msgbox Playerhouse_WelcomeHomeAfterFestival_Text_5
Playerhouse_WelcomeHomeAfterFestival_1:
# 83 "data/maps/PlayerHouse/scripts.pory"
	msgbox Playerhouse_WelcomeHomeAfterFestival_Text_6, MSGBOX_AUTOCLOSE
# 97 "data/maps/PlayerHouse/scripts.pory"
	special HealPlayerParty
# 98 "data/maps/PlayerHouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 99 "data/maps/PlayerHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 100 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 101 "data/maps/PlayerHouse/scripts.pory"
	playfanfare MUS_HEAL
# 102 "data/maps/PlayerHouse/scripts.pory"
	openscreenshot 3, 1
# 103 "data/maps/PlayerHouse/scripts.pory"
	waitstate
# 104 "data/maps/PlayerHouse/scripts.pory"
	waitfanfare
# 105 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_IKITOWN_STATE, 16
# 106 "data/maps/PlayerHouse/scripts.pory"
	clearflag FLAG_HIDE_ROUTE1_LILLIE
# 107 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 108 "data/maps/PlayerHouse/scripts.pory"
	warpsilent MAP_PLAYER_ROOM, 12, 10
# 109 "data/maps/PlayerHouse/scripts.pory"
	waitstate
# 110 "data/maps/PlayerHouse/scripts.pory"
	release
	end

Playerhouse_WelcomeHomeAfterFestival_2:
# 66 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 67 "data/maps/PlayerHouse/scripts.pory"
	msgbox Playerhouse_WelcomeHomeAfterFestival_Text_4
	goto Playerhouse_WelcomeHomeAfterFestival_1


PlayerHouse_MomNewGoGetPokemon::
# 115 "data/maps/PlayerHouse/scripts.pory"
	lock
# 116 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 117 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 118 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewGoGetPokemon_Text_0
# 122 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_MomNewGameDialog::
# 127 "data/maps/PlayerHouse/scripts.pory"
	lock
# 128 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 129 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 130 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewGoGetPokemon_Text_0
# 134 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_MeowthNewGameDialog::
# 139 "data/maps/PlayerHouse/scripts.pory"
	lock
# 140 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 141 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 142 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MeowthNewGameDialog_Text_0, MSGBOX_AUTOCLOSE
# 143 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_MomNewgame::
# 148 "data/maps/PlayerHouse/scripts.pory"
	lock
# 149 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 1
	goto_if_eq PlayerHouse_MomNewgame_1
# 212 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, PlayerHouse_MomNewgame_Movement_1
# 213 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 214 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 215 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, Common_Movement_ExclamationMark
# 216 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 217 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 218 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_10
# 221 "data/maps/PlayerHouse/scripts.pory"
	release
	end

PlayerHouse_MomNewgame_1:
# 150 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 151 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, Common_Movement_ExclamationMark
# 152 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 153 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, PlayerHouse_MomNewgame_Movement_0
# 154 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 155 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 156 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_0
# 158 "data/maps/PlayerHouse/scripts.pory"
	gettimeofday
# 159 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq PlayerHouse_MomNewgame_5
# 159 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq PlayerHouse_MomNewgame_5
# 164 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_2
PlayerHouse_MomNewgame_4:
# 167 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_3
# 172 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_4
# 176 "data/maps/PlayerHouse/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, PlayerHouse_MomNewgame_Text_5, PlayerHouse_MomNewgame_Text_6
# 177 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq PlayerHouse_MomNewgame_11
# 182 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PlayerHouse_MomNewgame_12
PlayerHouse_MomNewgame_10:
# 186 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_9
# 207 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 2
# 208 "data/maps/PlayerHouse/scripts.pory"
	release
	end

PlayerHouse_MomNewgame_5:
# 160 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_1
	goto PlayerHouse_MomNewgame_4

PlayerHouse_MomNewgame_11:
# 179 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_7
	goto PlayerHouse_MomNewgame_10

PlayerHouse_MomNewgame_12:
# 183 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_8
	goto PlayerHouse_MomNewgame_10


PlayerHouse_GotRunningShoes::
# 227 "data/maps/PlayerHouse/scripts.pory"
	lock
# 228 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerHouse_GotRunningShoes_Movement_0
# 229 "data/maps/PlayerHouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 230 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom2, PlayerHouse_GotRunningShoes_Movement_1
# 231 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom2
# 232 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 233 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_GotRunningShoes_Text_0
# 245 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 246 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 247 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_GotRunningShoes_Text_1, MSGBOX_AUTOCLOSE
# 248 "data/maps/PlayerHouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 249 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 4
# 250 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_HIDE_STARTERS
# 251 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_HIDE_KUKUI_STARTERS
# 252 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_TalkToMom::
# 257 "data/maps/PlayerHouse/scripts.pory"
	lock
# 258 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 259 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 260 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_TalkToMom_Text_0
# 262 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_Trigger_TryingToLeaveWithoutShoes::
# 267 "data/maps/PlayerHouse/scripts.pory"
	lock
# 268 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 269 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 270 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Text_0, MSGBOX_AUTOCLOSE
# 275 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, Playerhouse_WelcomeHomeAfterFestival_Movement_0
# 276 "data/maps/PlayerHouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 277 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_Trigger_TryingToLeaveWithoutShoes2::
# 282 "data/maps/PlayerHouse/scripts.pory"
	lock
# 283 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, PlayerHouse_GotRunningShoes_Movement_1
# 284 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 285 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 286 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, Common_Movement_ExclamationMark
# 287 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 288 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 289 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Text_0
# 292 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Movement_0
# 293 "data/maps/PlayerHouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 294 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_ShowMomPokemon::
# 299 "data/maps/PlayerHouse/scripts.pory"
	lock
# 300 "data/maps/PlayerHouse/scripts.pory"
	startcutscene CUTSCENE_PLAYERHOUSE_SHOW_MOM_POKEMON
# 301 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 302 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerHouse_ShowMomPokemon_Movement_0
# 303 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, Playerhouse_WelcomeHomeAfterFestival_Movement_0
# 304 "data/maps/PlayerHouse/scripts.pory"
	waitmovement 0
# 305 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 306 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 307 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom3, PlayerHouse_ShowMomPokemon_Movement_1
# 308 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom3
# 309 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 310 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_0
# 313 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 314 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom3, PlayerHouse_ShowMomPokemon_Movement_2
# 315 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom3
# 316 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_1
# 317 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 318 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq PlayerHouse_ShowMomPokemon_2
PlayerHouse_ShowMomPokemon_1:
# 323 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq PlayerHouse_ShowMomPokemon_5
PlayerHouse_ShowMomPokemon_4:
# 328 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq PlayerHouse_ShowMomPokemon_8
PlayerHouse_ShowMomPokemon_7:
# 333 "data/maps/PlayerHouse/scripts.pory"
	waitmoncry
# 334 "data/maps/PlayerHouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 335 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom3, PlayerHouse_ShowMomPokemon_Movement_4
# 336 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom3
# 337 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 338 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_5
# 340 "data/maps/PlayerHouse/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, PlayerHouse_ShowMomPokemon_Text_6, PlayerHouse_ShowMomPokemon_Text_7
# 341 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq PlayerHouse_ShowMomPokemon_11
# 347 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PlayerHouse_ShowMomPokemon_12
PlayerHouse_ShowMomPokemon_10:
# 352 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 353 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_9, MSGBOX_AUTOCLOSE
# 356 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemeowth3, PlayerHouse_ShowMomPokemon_Movement_5
# 357 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemeowth3
# 358 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 359 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemeowth3, PlayerHouse_ShowMomPokemon_Movement_6
# 360 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 361 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_10, MSGBOX_AUTOCLOSE
# 362 "data/maps/PlayerHouse/scripts.pory"
	waitmoncry
# 363 "data/maps/PlayerHouse/scripts.pory"
	waitmessage
# 364 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq PlayerHouse_ShowMomPokemon_16
PlayerHouse_ShowMomPokemon_15:
# 369 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq PlayerHouse_ShowMomPokemon_19
PlayerHouse_ShowMomPokemon_18:
# 374 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq PlayerHouse_ShowMomPokemon_22
PlayerHouse_ShowMomPokemon_21:
# 379 "data/maps/PlayerHouse/scripts.pory"
	waitmoncry
# 380 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 381 "data/maps/PlayerHouse/scripts.pory"
	special HealPlayerParty
# 382 "data/maps/PlayerHouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 383 "data/maps/PlayerHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 384 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 385 "data/maps/PlayerHouse/scripts.pory"
	playfanfare MUS_HEAL
# 386 "data/maps/PlayerHouse/scripts.pory"
	openscreenshot 3, 1
# 387 "data/maps/PlayerHouse/scripts.pory"
	waitstate
# 388 "data/maps/PlayerHouse/scripts.pory"
	waitfanfare
# 389 "data/maps/PlayerHouse/scripts.pory"
	endcutscene
# 390 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_IKITOWN_STATE, 9
# 391 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_HIDE_PLAYERHOUSE_STARTER
# 392 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 393 "data/maps/PlayerHouse/scripts.pory"
	warpsilent MAP_PLAYER_ROOM, 12, 10
# 394 "data/maps/PlayerHouse/scripts.pory"
	waitstate
# 395 "data/maps/PlayerHouse/scripts.pory"
	release
	end

PlayerHouse_ShowMomPokemon_2:
# 319 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 320 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 321 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_2, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_1

PlayerHouse_ShowMomPokemon_5:
# 324 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 325 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 326 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_3, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_4

PlayerHouse_ShowMomPokemon_8:
# 329 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 330 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 331 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_4, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_7

PlayerHouse_ShowMomPokemon_11:
# 343 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 344 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_8
	goto PlayerHouse_ShowMomPokemon_10

PlayerHouse_ShowMomPokemon_12:
# 348 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 349 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_8
	goto PlayerHouse_ShowMomPokemon_10

PlayerHouse_ShowMomPokemon_16:
# 365 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 366 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 367 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_2, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_15

PlayerHouse_ShowMomPokemon_19:
# 370 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 371 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 372 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_3, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_18

PlayerHouse_ShowMomPokemon_22:
# 375 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 376 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 377 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_4, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_21


PlayerHouse_ShowMomPokemonSkip::
# 400 "data/maps/PlayerHouse/scripts.pory"
	closemessage
# 401 "data/maps/PlayerHouse/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 402 "data/maps/PlayerHouse/scripts.pory"
	special CloseScriptMenus
# 403 "data/maps/PlayerHouse/scripts.pory"
	special HideCutsceneCinematicBars
# 404 "data/maps/PlayerHouse/scripts.pory"
	special HealPlayerParty
# 405 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_IKITOWN_STATE, 9
# 406 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_HIDE_PLAYERHOUSE_STARTER
# 407 "data/maps/PlayerHouse/scripts.pory"
	warp MAP_PLAYER_ROOM, 12, 10
# 408 "data/maps/PlayerHouse/scripts.pory"
	waitstate
# 409 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_TalkToMomAfterDoorbell::
# 414 "data/maps/PlayerHouse/scripts.pory"
	lock
# 415 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 416 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_IKITOWN_STATE, 10
	goto_if_eq PlayerHouse_TalkToMomAfterDoorbell_2
# 422 "data/maps/PlayerHouse/scripts.pory"
	specialvar VAR_RESULT, IsPlayerPartyFullyHealed
# 423 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PlayerHouse_TalkToMomAfterDoorbell_5
# 431 "data/maps/PlayerHouse/scripts.pory"
	goto_if_set FLAG_DAILY_MOM_HEAL_POKEBALL, PlayerHouse_TalkToMomAfterDoorbell_8
# 445 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 446 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_TalkToMomAfterDoorbell_Text_2, MSGBOX_AUTOCLOSE
# 451 "data/maps/PlayerHouse/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 452 "data/maps/PlayerHouse/scripts.pory"
	playfanfare MUS_HEAL
# 453 "data/maps/PlayerHouse/scripts.pory"
	special HealPlayerParty
# 454 "data/maps/PlayerHouse/scripts.pory"
	waitfanfare
# 455 "data/maps/PlayerHouse/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 456 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 457 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_TalkToMomAfterDoorbell_Text_3, MSGBOX_AUTOCLOSE
# 460 "data/maps/PlayerHouse/scripts.pory"
	giveitem ITEM_POKE_BALL, 1
# 461 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_DAILY_MOM_HEAL_POKEBALL
PlayerHouse_TalkToMomAfterDoorbell_1:
# 465 "data/maps/PlayerHouse/scripts.pory"
	release
	end

PlayerHouse_TalkToMomAfterDoorbell_2:
# 417 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 418 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_TalkToMomAfterDoorbell_Text_0
	goto PlayerHouse_TalkToMomAfterDoorbell_1

PlayerHouse_TalkToMomAfterDoorbell_5:
# 424 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 425 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_TalkToMomAfterDoorbell_Text_1
	goto PlayerHouse_TalkToMomAfterDoorbell_1

PlayerHouse_TalkToMomAfterDoorbell_8:
# 432 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 433 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_TalkToMomAfterDoorbell_Text_2, MSGBOX_AUTOCLOSE
# 438 "data/maps/PlayerHouse/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 439 "data/maps/PlayerHouse/scripts.pory"
	playfanfare MUS_HEAL
# 440 "data/maps/PlayerHouse/scripts.pory"
	special HealPlayerParty
# 441 "data/maps/PlayerHouse/scripts.pory"
	waitfanfare
# 442 "data/maps/PlayerHouse/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto PlayerHouse_TalkToMomAfterDoorbell_1


PlayerHouse_MomHealPlayer::
# 470 "data/maps/PlayerHouse/scripts.pory"
	lock
# 471 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 472 "data/maps/PlayerHouse/scripts.pory"
	speakername Playerhouse_WelcomeHomeAfterFestival_Text_0
# 473 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomHealPlayer_Text_0
	return


# 44 "data/maps/PlayerHouse/scripts.pory"
Playerhouse_WelcomeHomeAfterFestival_Movement_0:
# 44 "data/maps/PlayerHouse/scripts.pory"
	walk_up
	step_end

# 49 "data/maps/PlayerHouse/scripts.pory"
Playerhouse_WelcomeHomeAfterFestival_Movement_1:
# 49 "data/maps/PlayerHouse/scripts.pory"
	face_right
	step_end

# 55 "data/maps/PlayerHouse/scripts.pory"
Playerhouse_WelcomeHomeAfterFestival_Movement_2:
# 55 "data/maps/PlayerHouse/scripts.pory"
	emote_exclamation_mark
# 55 "data/maps/PlayerHouse/scripts.pory"
	face_down
	step_end

# 61 "data/maps/PlayerHouse/scripts.pory"
Playerhouse_WelcomeHomeAfterFestival_Movement_3:
# 61 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 61 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 61 "data/maps/PlayerHouse/scripts.pory"
	walk_left
# 61 "data/maps/PlayerHouse/scripts.pory"
	walk_left
# 61 "data/maps/PlayerHouse/scripts.pory"
	walk_left
# 61 "data/maps/PlayerHouse/scripts.pory"
	walk_left
# 61 "data/maps/PlayerHouse/scripts.pory"
	face_down
	step_end

# 62 "data/maps/PlayerHouse/scripts.pory"
Playerhouse_WelcomeHomeAfterFestival_Movement_4:
# 62 "data/maps/PlayerHouse/scripts.pory"
	delay_16
# 62 "data/maps/PlayerHouse/scripts.pory"
	delay_16
# 62 "data/maps/PlayerHouse/scripts.pory"
	delay_16
# 62 "data/maps/PlayerHouse/scripts.pory"
	delay_16
# 62 "data/maps/PlayerHouse/scripts.pory"
	delay_16
# 62 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 62 "data/maps/PlayerHouse/scripts.pory"
	walk_left
# 62 "data/maps/PlayerHouse/scripts.pory"
	face_down
	step_end

# 153 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_MomNewgame_Movement_0:
# 153 "data/maps/PlayerHouse/scripts.pory"
	walk_left
# 153 "data/maps/PlayerHouse/scripts.pory"
	face_up
	step_end

# 212 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_MomNewgame_Movement_1:
# 212 "data/maps/PlayerHouse/scripts.pory"
	face_up
	step_end

# 228 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_GotRunningShoes_Movement_0:
# 228 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 228 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 228 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 228 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 228 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 228 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 228 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 228 "data/maps/PlayerHouse/scripts.pory"
	walk_left
	step_end

# 230 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_GotRunningShoes_Movement_1:
# 230 "data/maps/PlayerHouse/scripts.pory"
	face_player
	step_end

# 292 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Movement_0:
# 292 "data/maps/PlayerHouse/scripts.pory"
	walk_down
	step_end

# 302 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_0:
# 302 "data/maps/PlayerHouse/scripts.pory"
	walk_up
# 302 "data/maps/PlayerHouse/scripts.pory"
	walk_up
	step_end

# 307 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_1:
# 307 "data/maps/PlayerHouse/scripts.pory"
	face_down
# 307 "data/maps/PlayerHouse/scripts.pory"
	emote_exclamation_mark
	step_end

# 314 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_2:
# 314 "data/maps/PlayerHouse/scripts.pory"
	emote_exclamation_mark
	step_end

# 320 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_3:
# 320 "data/maps/PlayerHouse/scripts.pory"
	emote_heart
	step_end

# 335 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_4:
# 335 "data/maps/PlayerHouse/scripts.pory"
	walk_up
# 335 "data/maps/PlayerHouse/scripts.pory"
	walk_up
# 335 "data/maps/PlayerHouse/scripts.pory"
	walk_right
# 335 "data/maps/PlayerHouse/scripts.pory"
	walk_right
# 335 "data/maps/PlayerHouse/scripts.pory"
	walk_right
# 335 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 335 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 335 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 335 "data/maps/PlayerHouse/scripts.pory"
	walk_down
	step_end

# 356 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_5:
# 356 "data/maps/PlayerHouse/scripts.pory"
	walk_left
# 356 "data/maps/PlayerHouse/scripts.pory"
	face_down
	step_end

# 359 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_6:
# 359 "data/maps/PlayerHouse/scripts.pory"
	walk_in_place_down
# 359 "data/maps/PlayerHouse/scripts.pory"
	walk_in_place_down
	step_end

Playerhouse_WelcomeHomeAfterFestival_Text_0:
# 45 "data/maps/PlayerHouse/scripts.pory"
	.string "Mom$"

Playerhouse_WelcomeHomeAfterFestival_Text_1:
# 46 "data/maps/PlayerHouse/scripts.pory"
	.string "Honey, I'm home!$"

Playerhouse_WelcomeHomeAfterFestival_Text_2:
# 50 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrawr!$"

Playerhouse_WelcomeHomeAfterFestival_Text_3:
# 58 "data/maps/PlayerHouse/scripts.pory"
	.string "Oh, {PLAYER}! You're back already?\n"
	.string "I thought you'd want to stay in\l"
	.string "Iki Town longer…$"

Playerhouse_WelcomeHomeAfterFestival_Text_4:
# 67 "data/maps/PlayerHouse/scripts.pory"
	.string "Especially right after that great\n"
	.string "Pokémon battle!\p"
	.string "Ooh, I was just captivated to see my\n"
	.string "own boy fighting in such perfect\l"
	.string "sync with his partner!$"

Playerhouse_WelcomeHomeAfterFestival_Text_5:
# 76 "data/maps/PlayerHouse/scripts.pory"
	.string "Especially right after that great\n"
	.string "Pokémon battle!\p"
	.string "Ooh, I was just captivated to see my\n"
	.string "own girl fighting in such perfect\l"
	.string "sync with her partner!$"

Playerhouse_WelcomeHomeAfterFestival_Text_6:
# 83 "data/maps/PlayerHouse/scripts.pory"
	.string "Maybe it would be a good idea for you\n"
	.string "to try that island challenge thing…\p"
	.string "It's something you can only do in Alola,\n"
	.string "right?\p"
	.string "But right now, I've got a date with my\n"
	.string "bed.\p"
	.string "I danced my feet off at that\n"
	.string "festival!\p"
	.string "Night-night, sweetie.\n"
	.string "You get some sleep, too!$"

PlayerHouse_MomNewGoGetPokemon_Text_0:
# 118 "data/maps/PlayerHouse/scripts.pory"
	.string "Where are your shoes, {PLAYER}?\p"
	.string "You should probably unpack the box\n"
	.string "in your room to find them!$"

PlayerHouse_MeowthNewGameDialog_Text_0:
# 142 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrrowrr!$"

PlayerHouse_MomNewgame_Text_0:
# 156 "data/maps/PlayerHouse/scripts.pory"
	.string "You were out like a light, earlier!\n"
	.string "You ought to be full of energy by now!$"

PlayerHouse_MomNewgame_Text_1:
# 160 "data/maps/PlayerHouse/scripts.pory"
	.string "And just look!\n"
	.string "It's already night here!$"

PlayerHouse_MomNewgame_Text_2:
# 164 "data/maps/PlayerHouse/scripts.pory"
	.string "And just look!\n"
	.string "It's already daytime here!$"

PlayerHouse_MomNewgame_Text_3:
# 167 "data/maps/PlayerHouse/scripts.pory"
	.string "It's completely the opposite of Kanto.\p"
	.string "But then we are so far away here in\n"
	.string "Alola.$"

PlayerHouse_MomNewgame_Text_4:
# 172 "data/maps/PlayerHouse/scripts.pory"
	.string "So {PLAYER}!\p"
	.string "Are you excited to meet some Alolan\n"
	.string "Pokémon?$"

PlayerHouse_MomNewgame_Text_5:
# 176 "data/maps/PlayerHouse/scripts.pory"
	.string "Of course!$"

PlayerHouse_MomNewgame_Text_6:
# 176 "data/maps/PlayerHouse/scripts.pory"
	.string "I guess…$"

PlayerHouse_MomNewgame_Text_7:
# 179 "data/maps/PlayerHouse/scripts.pory"
	.string "That's right!\n"
	.string "I want to hurry up and meet some, too!$"

PlayerHouse_MomNewgame_Text_8:
# 183 "data/maps/PlayerHouse/scripts.pory"
	.string "Oh you! Someday you're going to learn\n"
	.string "to have a little wonder in your life!$"

PlayerHouse_MomNewgame_Text_9:
# 186 "data/maps/PlayerHouse/scripts.pory"
	.string "We're living in the Alola region now!\p"
	.string "The beautiful islands everyone wants\n"
	.string "to visit!\p"
	.string "I'm sure the Pokémon living in a place\n"
	.string "like this must be friendly, right?\p"
	.string "It might not be a bad idea to go out\n"
	.string "and see for yourself just how\l"
	.string "friendly Pokémon here are.\p"
	.string "Right {PLAYER}?\n"
	.string "Go and get ready for a bit of\l"
	.string "exploring!\p"
	.string "Your running shoes should be in the\n"
	.string "box in your room.\p"
	.string "And didn't you leave your copy of\n"
	.string "Adventure Rules on your desk, too?$"

PlayerHouse_MomNewgame_Text_10:
# 218 "data/maps/PlayerHouse/scripts.pory"
	.string "Where are your shoes, {PLAYER}?\n"
	.string "You should probably unpack the box in\l"
	.string "your room to find them!$"

PlayerHouse_GotRunningShoes_Text_0:
# 233 "data/maps/PlayerHouse/scripts.pory"
	.string "Now you look ready for anything!\p"
	.string "Oh, but even so, {PLAYER}…\p"
	.string "Try to be careful walking through the\n"
	.string "tall grass!\p"
	.string "Still, I have to admit that I'd love\n"
	.string "to have a new Pokémon around…\p"
	.string "Why don't you head up towards Iki Town\n"
	.string "and see what you discover in Alola?$"

PlayerHouse_GotRunningShoes_Text_1:
# 247 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrowrr.$"

PlayerHouse_TalkToMom_Text_0:
# 260 "data/maps/PlayerHouse/scripts.pory"
	.string "Why don't you head up towards Iki Town\n"
	.string "and see what you discover in Alola?$"

PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Text_0:
# 270 "data/maps/PlayerHouse/scripts.pory"
	.string "Are you leaving without your shoes, \n"
	.string "{PLAYER}?\p"
	.string "You should unpack the box in\n"
	.string "your room to find them!$"

PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Text_0:
# 289 "data/maps/PlayerHouse/scripts.pory"
	.string "Where are you going, {PLAYER}?\n"
	.string "You should probably unpack the box in\l"
	.string "your room to find them!$"

PlayerHouse_ShowMomPokemon_Text_0:
# 310 "data/maps/PlayerHouse/scripts.pory"
	.string "Welcome back, {PLAYER}!\p"
	.string "So what did you think of Kahuna Hala?$"

PlayerHouse_ShowMomPokemon_Text_1:
# 316 "data/maps/PlayerHouse/scripts.pory"
	.string "Oh! And look who you've got with you!$"

PlayerHouse_ShowMomPokemon_Text_2:
# 321 "data/maps/PlayerHouse/scripts.pory"
	.string "Hoo?$"

PlayerHouse_ShowMomPokemon_Text_3:
# 326 "data/maps/PlayerHouse/scripts.pory"
	.string "Bar?$"

PlayerHouse_ShowMomPokemon_Text_4:
# 331 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrawr?$"

PlayerHouse_ShowMomPokemon_Text_5:
# 338 "data/maps/PlayerHouse/scripts.pory"
	.string "It came running out to help you?\n"
	.string "What a sweet little thing!$"

PlayerHouse_ShowMomPokemon_Text_6:
# 340 "data/maps/PlayerHouse/scripts.pory"
	.string "That's right$"

PlayerHouse_ShowMomPokemon_Text_7:
# 340 "data/maps/PlayerHouse/scripts.pory"
	.string "Right on Route 1$"

PlayerHouse_ShowMomPokemon_Text_8:
# 344 "data/maps/PlayerHouse/scripts.pory"
	.string "And it saved you! That's amazing.\n"
	.string "It must have been fate that you met!$"

PlayerHouse_ShowMomPokemon_Text_9:
# 353 "data/maps/PlayerHouse/scripts.pory"
	.string "The two of you look great together…\n"
	.string "I feel happier just looking at the\l"
	.string "pair of you!$"

PlayerHouse_ShowMomPokemon_Text_10:
# 361 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrrrrr!$"

PlayerHouse_TalkToMomAfterDoorbell_Text_0:
# 418 "data/maps/PlayerHouse/scripts.pory"
	.string "Was that the doorbell?\n"
	.string "Go see who it is, {PLAYER}.$"

PlayerHouse_TalkToMomAfterDoorbell_Text_1:
# 425 "data/maps/PlayerHouse/scripts.pory"
	.string "Sleep does the body good!\n"
	.string "Traveling is a true education!\p"
	.string "And unpacking… will be the death of me!$"

PlayerHouse_TalkToMomAfterDoorbell_Text_2:
# 433 "data/maps/PlayerHouse/scripts.pory"
	.string "Have you been having a good time?\n"
	.string "You look a bit tired but happy.\p"
	.string "Take a little break before you head out\n"
	.string "there again, sweetie.$"

PlayerHouse_TalkToMomAfterDoorbell_Text_3:
# 457 "data/maps/PlayerHouse/scripts.pory"
	.string "Here, Take a Poké Ball, too, sweetie.\n"
	.string "I hope you'll encounter someone\l"
	.string "special today!$"

PlayerHouse_MomHealPlayer_Text_0:
# 473 "data/maps/PlayerHouse/scripts.pory"
	.string "Sleep does the$"
