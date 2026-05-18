PlayerHouse_MapScripts::
# 2 "data/maps/PlayerHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PlayerHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 30 "data/maps/PlayerHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 32 "data/maps/PlayerHouse/scripts.pory"
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
	.2byte 0

PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 30 "data/maps/PlayerHouse/scripts.pory"
	hideobjectat playerhousemom2, MAP_PLAYER_HOUSE
# 31 "data/maps/PlayerHouse/scripts.pory"
	hideobjectat playerhousemeowth2, MAP_PLAYER_HOUSE
	return

PlayerHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 32 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 VAR_MOM_IN_HOUSE_INTRO, 1, PlayerHouse_MomNewgame
# 33 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 VAR_MOM_IN_HOUSE_INTRO, 3, PlayerHouse_GotRunningShoes
# 34 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 8, PlayerHouse_ShowMomPokemon
	.2byte 0


PlayerHouse_MomNewGoGetPokemon::
# 39 "data/maps/PlayerHouse/scripts.pory"
	lock
# 40 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 41 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 42 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewGoGetPokemon_Text_1
# 46 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_MomNewGameDialog::
# 51 "data/maps/PlayerHouse/scripts.pory"
	lock
# 52 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 53 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 54 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewGoGetPokemon_Text_1
# 58 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_MeowthNewGameDialog::
# 63 "data/maps/PlayerHouse/scripts.pory"
	lock
# 64 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 65 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 66 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MeowthNewGameDialog_Text_0, MSGBOX_AUTOCLOSE
# 67 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_MomNewgame::
# 72 "data/maps/PlayerHouse/scripts.pory"
	lock
# 73 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 1
	goto_if_eq PlayerHouse_MomNewgame_1
# 136 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, PlayerHouse_MomNewgame_Movement_1
# 137 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 138 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 139 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, Common_Movement_ExclamationMark
# 140 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 141 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 142 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_10
# 145 "data/maps/PlayerHouse/scripts.pory"
	release
	end

PlayerHouse_MomNewgame_1:
# 74 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 75 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, Common_Movement_ExclamationMark
# 76 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 77 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, PlayerHouse_MomNewgame_Movement_0
# 78 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 79 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 80 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_0
# 82 "data/maps/PlayerHouse/scripts.pory"
	gettimeofday
# 83 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq PlayerHouse_MomNewgame_5
# 83 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq PlayerHouse_MomNewgame_5
# 88 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_2
PlayerHouse_MomNewgame_4:
# 91 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_3
# 96 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_4
# 100 "data/maps/PlayerHouse/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, PlayerHouse_MomNewgame_Text_5, PlayerHouse_MomNewgame_Text_6
# 101 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq PlayerHouse_MomNewgame_11
# 106 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PlayerHouse_MomNewgame_12
PlayerHouse_MomNewgame_10:
# 110 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_9
# 131 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 2
# 132 "data/maps/PlayerHouse/scripts.pory"
	release
	end

PlayerHouse_MomNewgame_5:
# 84 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_1
	goto PlayerHouse_MomNewgame_4

PlayerHouse_MomNewgame_11:
# 103 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_7
	goto PlayerHouse_MomNewgame_10

PlayerHouse_MomNewgame_12:
# 107 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_8
	goto PlayerHouse_MomNewgame_10


PlayerHouse_GotRunningShoes::
# 151 "data/maps/PlayerHouse/scripts.pory"
	lock
# 152 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerHouse_GotRunningShoes_Movement_0
# 153 "data/maps/PlayerHouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 154 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom2, PlayerHouse_GotRunningShoes_Movement_1
# 155 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom2
# 156 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 157 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_GotRunningShoes_Text_0
# 169 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 170 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 171 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_GotRunningShoes_Text_1, MSGBOX_AUTOCLOSE
# 172 "data/maps/PlayerHouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 173 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 4
# 174 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_HIDE_STARTERS
# 175 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_HIDE_KUKUI_STARTERS
# 176 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_TalkToMom::
# 181 "data/maps/PlayerHouse/scripts.pory"
	lock
# 182 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 183 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 184 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_TalkToMom_Text_0
# 186 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_Trigger_TryingToLeaveWithoutShoes::
# 191 "data/maps/PlayerHouse/scripts.pory"
	lock
# 192 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 193 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 194 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Text_0, MSGBOX_AUTOCLOSE
# 199 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Movement_0
# 200 "data/maps/PlayerHouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 201 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_Trigger_TryingToLeaveWithoutShoes2::
# 206 "data/maps/PlayerHouse/scripts.pory"
	lock
# 207 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, PlayerHouse_GotRunningShoes_Movement_1
# 208 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 209 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 210 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, Common_Movement_ExclamationMark
# 211 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 212 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 213 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Text_0
# 216 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Movement_0
# 217 "data/maps/PlayerHouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 218 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_ShowMomPokemon::
# 223 "data/maps/PlayerHouse/scripts.pory"
	lock
# 224 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 225 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerHouse_ShowMomPokemon_Movement_0
# 226 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Movement_0
# 227 "data/maps/PlayerHouse/scripts.pory"
	waitmovement 0
# 228 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 229 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 230 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom3, PlayerHouse_ShowMomPokemon_Movement_1
# 231 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom3
# 232 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 233 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_0
# 236 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 237 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom3, PlayerHouse_ShowMomPokemon_Movement_2
# 238 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom3
# 239 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_1
# 240 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 241 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq PlayerHouse_ShowMomPokemon_2
PlayerHouse_ShowMomPokemon_1:
# 246 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq PlayerHouse_ShowMomPokemon_5
PlayerHouse_ShowMomPokemon_4:
# 251 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq PlayerHouse_ShowMomPokemon_8
PlayerHouse_ShowMomPokemon_7:
# 256 "data/maps/PlayerHouse/scripts.pory"
	waitmoncry
# 257 "data/maps/PlayerHouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 258 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom3, PlayerHouse_ShowMomPokemon_Movement_4
# 259 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom3
# 260 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 261 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_5
# 263 "data/maps/PlayerHouse/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, PlayerHouse_ShowMomPokemon_Text_6, PlayerHouse_ShowMomPokemon_Text_7
# 264 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq PlayerHouse_ShowMomPokemon_11
# 270 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PlayerHouse_ShowMomPokemon_12
PlayerHouse_ShowMomPokemon_10:
# 275 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 276 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_9, MSGBOX_AUTOCLOSE
# 279 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemeowth3, PlayerHouse_ShowMomPokemon_Movement_5
# 280 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemeowth3
# 281 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 282 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemeowth3, PlayerHouse_ShowMomPokemon_Movement_6
# 283 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 284 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_10, MSGBOX_AUTOCLOSE
# 285 "data/maps/PlayerHouse/scripts.pory"
	waitmoncry
# 286 "data/maps/PlayerHouse/scripts.pory"
	waitmessage
# 287 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq PlayerHouse_ShowMomPokemon_16
PlayerHouse_ShowMomPokemon_15:
# 292 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq PlayerHouse_ShowMomPokemon_19
PlayerHouse_ShowMomPokemon_18:
# 297 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq PlayerHouse_ShowMomPokemon_22
PlayerHouse_ShowMomPokemon_21:
# 302 "data/maps/PlayerHouse/scripts.pory"
	waitmoncry
# 303 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 304 "data/maps/PlayerHouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 305 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_0x8000, 3
# 306 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_RESULT, 1
# 307 "data/maps/PlayerHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 308 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 309 "data/maps/PlayerHouse/scripts.pory"
	playfanfare MUS_HEAL
# 311 "data/maps/PlayerHouse/scripts.pory"
	callnative OpenScreenshotsFromScript
# 312 "data/maps/PlayerHouse/scripts.pory"
	waitstate
# 313 "data/maps/PlayerHouse/scripts.pory"
	waitfanfare
# 314 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_IKITOWN_STATE, 9
# 315 "data/maps/PlayerHouse/scripts.pory"
	delay 30
# 316 "data/maps/PlayerHouse/scripts.pory"
	warpsilent MAP_PLAYER_ROOM, 12, 10
# 317 "data/maps/PlayerHouse/scripts.pory"
	waitstate
# 318 "data/maps/PlayerHouse/scripts.pory"
	special HealPlayerParty
# 319 "data/maps/PlayerHouse/scripts.pory"
	release
	end

PlayerHouse_ShowMomPokemon_2:
# 242 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 243 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 244 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_2, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_1

PlayerHouse_ShowMomPokemon_5:
# 247 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 248 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 249 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_3, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_4

PlayerHouse_ShowMomPokemon_8:
# 252 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 253 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 254 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_4, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_7

PlayerHouse_ShowMomPokemon_11:
# 266 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 267 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_8
	goto PlayerHouse_ShowMomPokemon_10

PlayerHouse_ShowMomPokemon_12:
# 271 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 272 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_8
	goto PlayerHouse_ShowMomPokemon_10

PlayerHouse_ShowMomPokemon_16:
# 288 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 289 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 290 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_2, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_15

PlayerHouse_ShowMomPokemon_19:
# 293 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 294 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 295 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_3, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_18

PlayerHouse_ShowMomPokemon_22:
# 298 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 299 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousestarter, PlayerHouse_ShowMomPokemon_Movement_3
# 300 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_ShowMomPokemon_Text_4, MSGBOX_AUTOCLOSE
	goto PlayerHouse_ShowMomPokemon_21


# 77 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_MomNewgame_Movement_0:
# 77 "data/maps/PlayerHouse/scripts.pory"
	walk_left
# 77 "data/maps/PlayerHouse/scripts.pory"
	face_up
	step_end

# 136 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_MomNewgame_Movement_1:
# 136 "data/maps/PlayerHouse/scripts.pory"
	face_up
	step_end

# 152 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_GotRunningShoes_Movement_0:
# 152 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 152 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 152 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 152 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 152 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 152 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 152 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 152 "data/maps/PlayerHouse/scripts.pory"
	walk_left
	step_end

# 154 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_GotRunningShoes_Movement_1:
# 154 "data/maps/PlayerHouse/scripts.pory"
	face_player
	step_end

# 199 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Movement_0:
# 199 "data/maps/PlayerHouse/scripts.pory"
	walk_up
	step_end

# 216 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Movement_0:
# 216 "data/maps/PlayerHouse/scripts.pory"
	walk_down
	step_end

# 225 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_0:
# 225 "data/maps/PlayerHouse/scripts.pory"
	walk_up
# 225 "data/maps/PlayerHouse/scripts.pory"
	walk_up
	step_end

# 230 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_1:
# 230 "data/maps/PlayerHouse/scripts.pory"
	face_down
# 230 "data/maps/PlayerHouse/scripts.pory"
	emote_exclamation_mark
	step_end

# 237 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_2:
# 237 "data/maps/PlayerHouse/scripts.pory"
	emote_exclamation_mark
	step_end

# 243 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_3:
# 243 "data/maps/PlayerHouse/scripts.pory"
	emote_heart
	step_end

# 258 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_4:
# 258 "data/maps/PlayerHouse/scripts.pory"
	walk_up
# 258 "data/maps/PlayerHouse/scripts.pory"
	walk_up
# 258 "data/maps/PlayerHouse/scripts.pory"
	walk_right
# 258 "data/maps/PlayerHouse/scripts.pory"
	walk_right
# 258 "data/maps/PlayerHouse/scripts.pory"
	walk_right
# 258 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 258 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 258 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 258 "data/maps/PlayerHouse/scripts.pory"
	walk_down
	step_end

# 279 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_5:
# 279 "data/maps/PlayerHouse/scripts.pory"
	walk_left
# 279 "data/maps/PlayerHouse/scripts.pory"
	face_down
	step_end

# 282 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_ShowMomPokemon_Movement_6:
# 282 "data/maps/PlayerHouse/scripts.pory"
	walk_in_place_down
# 282 "data/maps/PlayerHouse/scripts.pory"
	walk_in_place_down
	step_end

PlayerHouse_MomNewGoGetPokemon_Text_0:
# 41 "data/maps/PlayerHouse/scripts.pory"
	.string "Mom$"

PlayerHouse_MomNewGoGetPokemon_Text_1:
# 42 "data/maps/PlayerHouse/scripts.pory"
	.string "Where are your shoes, {PLAYER}?\p"
	.string "You should probably unpack the box\n"
	.string "in your room to find them!$"

PlayerHouse_MeowthNewGameDialog_Text_0:
# 66 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrrowrr!$"

PlayerHouse_MomNewgame_Text_0:
# 80 "data/maps/PlayerHouse/scripts.pory"
	.string "You were out like a light, earlier!\n"
	.string "You ought to be full of energy by now!$"

PlayerHouse_MomNewgame_Text_1:
# 84 "data/maps/PlayerHouse/scripts.pory"
	.string "And just look!\n"
	.string "It's already night here!$"

PlayerHouse_MomNewgame_Text_2:
# 88 "data/maps/PlayerHouse/scripts.pory"
	.string "And just look!\n"
	.string "It's already daytime here!$"

PlayerHouse_MomNewgame_Text_3:
# 91 "data/maps/PlayerHouse/scripts.pory"
	.string "It's completely the opposite of Kanto.\p"
	.string "But then we are so far away here in\n"
	.string "Alola.$"

PlayerHouse_MomNewgame_Text_4:
# 96 "data/maps/PlayerHouse/scripts.pory"
	.string "So {PLAYER}!\p"
	.string "Are you excited to meet some Alolan\n"
	.string "Pokémon?$"

PlayerHouse_MomNewgame_Text_5:
# 100 "data/maps/PlayerHouse/scripts.pory"
	.string "Of course!$"

PlayerHouse_MomNewgame_Text_6:
# 100 "data/maps/PlayerHouse/scripts.pory"
	.string "I guess…$"

PlayerHouse_MomNewgame_Text_7:
# 103 "data/maps/PlayerHouse/scripts.pory"
	.string "That's right!\n"
	.string "I want to hurry up and meet some, too!$"

PlayerHouse_MomNewgame_Text_8:
# 107 "data/maps/PlayerHouse/scripts.pory"
	.string "Oh you! Someday you're going to learn\n"
	.string "to have a little wonder in your life!$"

PlayerHouse_MomNewgame_Text_9:
# 110 "data/maps/PlayerHouse/scripts.pory"
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
# 142 "data/maps/PlayerHouse/scripts.pory"
	.string "Where are your shoes, {PLAYER}?\n"
	.string "You should probably unpack the box in\l"
	.string "your room to find them!$"

PlayerHouse_GotRunningShoes_Text_0:
# 157 "data/maps/PlayerHouse/scripts.pory"
	.string "Now you look ready for anything!\p"
	.string "Oh, but even so, {PLAYER}…\p"
	.string "Try to be careful walking through the\n"
	.string "tall grass!\p"
	.string "Still, I have to admit that I'd love\n"
	.string "to have a new Pokémon around…\p"
	.string "Why don't you head up towards Iki Town\n"
	.string "and see what you discover in Alola?$"

PlayerHouse_GotRunningShoes_Text_1:
# 171 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrowrr.$"

PlayerHouse_TalkToMom_Text_0:
# 184 "data/maps/PlayerHouse/scripts.pory"
	.string "Why don't you head up towards Iki Town\n"
	.string "and see what you discover in Alola?$"

PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Text_0:
# 194 "data/maps/PlayerHouse/scripts.pory"
	.string "Are you leaving without your shoes, \n"
	.string "{PLAYER}?\p"
	.string "You should unpack the box in\n"
	.string "your room to find them!$"

PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Text_0:
# 213 "data/maps/PlayerHouse/scripts.pory"
	.string "Where are you going, {PLAYER}?\n"
	.string "You should probably unpack the box in\l"
	.string "your room to find them!$"

PlayerHouse_ShowMomPokemon_Text_0:
# 233 "data/maps/PlayerHouse/scripts.pory"
	.string "Welcome back, {PLAYER}!\p"
	.string "So what did you think of Kahuna Hala?$"

PlayerHouse_ShowMomPokemon_Text_1:
# 239 "data/maps/PlayerHouse/scripts.pory"
	.string "Oh! And look who you've got with you!$"

PlayerHouse_ShowMomPokemon_Text_2:
# 244 "data/maps/PlayerHouse/scripts.pory"
	.string "Hoo?$"

PlayerHouse_ShowMomPokemon_Text_3:
# 249 "data/maps/PlayerHouse/scripts.pory"
	.string "Bar?$"

PlayerHouse_ShowMomPokemon_Text_4:
# 254 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrawr?$"

PlayerHouse_ShowMomPokemon_Text_5:
# 261 "data/maps/PlayerHouse/scripts.pory"
	.string "It came running out to help you?\n"
	.string "What a sweet little thing!$"

PlayerHouse_ShowMomPokemon_Text_6:
# 263 "data/maps/PlayerHouse/scripts.pory"
	.string "That's right$"

PlayerHouse_ShowMomPokemon_Text_7:
# 263 "data/maps/PlayerHouse/scripts.pory"
	.string "Right on Route 1$"

PlayerHouse_ShowMomPokemon_Text_8:
# 267 "data/maps/PlayerHouse/scripts.pory"
	.string "And it saved you! That's amazing.\n"
	.string "It must have been fate that you met!$"

PlayerHouse_ShowMomPokemon_Text_9:
# 276 "data/maps/PlayerHouse/scripts.pory"
	.string "The two of you look great together…\n"
	.string "I feel happier just looking at the\l"
	.string "pair of you!$"

PlayerHouse_ShowMomPokemon_Text_10:
# 284 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrrrrr!$"
