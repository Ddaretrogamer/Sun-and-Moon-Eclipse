Route1NN_MapScripts::
	.byte 0


YungoosMeowth_Blocking::
# 6 "data/maps/Route1NN/scripts.pory"
	lock
# 7 "data/maps/Route1NN/scripts.pory"
	msgbox YungoosMeowth_Blocking_Text_0, MSGBOX_AUTOCLOSE
# 9 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_YUNGOOS, 0
# 10 "data/maps/Route1NN/scripts.pory"
	applymovement route1yungoos2, YungoosMeowth_Blocking_Movement_0
# 11 "data/maps/Route1NN/scripts.pory"
	waitmovement route1yungoos2
# 12 "data/maps/Route1NN/scripts.pory"
	msgbox YungoosMeowth_Blocking_Text_1, MSGBOX_AUTOCLOSE
# 13 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 14 "data/maps/Route1NN/scripts.pory"
	applymovement route1meowth2, YungoosMeowth_Blocking_Movement_1
# 15 "data/maps/Route1NN/scripts.pory"
	waitmovement route1meowth2
# 16 "data/maps/Route1NN/scripts.pory"
	playse SE_M_SCRATCH
# 17 "data/maps/Route1NN/scripts.pory"
	waitse
# 18 "data/maps/Route1NN/scripts.pory"
	release
	end


PowerOfScience::
# 24 "data/maps/Route1NN/scripts.pory"
	lock
# 25 "data/maps/Route1NN/scripts.pory"
	faceplayer
# 26 "data/maps/Route1NN/scripts.pory"
	msgbox PowerOfScience_Text_0
# 34 "data/maps/Route1NN/scripts.pory"
	release
	end


Route1NN_KukuiGoToIki::
# 39 "data/maps/Route1NN/scripts.pory"
	lock
# 40 "data/maps/Route1NN/scripts.pory"
	faceplayer
# 41 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 42 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_KukuiGoToIki_Text_1
# 43 "data/maps/Route1NN/scripts.pory"
	release
	end


Route1NN_Trigger_MiddleGetStarters::
# 48 "data/maps/Route1NN/scripts.pory"
	lock
# 49 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_MiddleGetStarters_Movement_0
# 50 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 51 "data/maps/Route1NN/scripts.pory"
	call Route1NN_Trigger_GetStarters
	return


Route1NN_Trigger_BottomGetStarters::
# 55 "data/maps/Route1NN/scripts.pory"
	lock
# 56 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_BottomGetStarters_Movement_0
# 57 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 58 "data/maps/Route1NN/scripts.pory"
	call Route1NN_Trigger_GetStarters
	return


Route1NN_Trigger_TopGetStarters::
# 62 "data/maps/Route1NN/scripts.pory"
	lock
# 63 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_TopGetStarters_Movement_0
# 64 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 65 "data/maps/Route1NN/scripts.pory"
	call Route1NN_Trigger_GetStarters
	return


Route1NN_Trigger_GetStartersSkip::
# 69 "data/maps/Route1NN/scripts.pory"
	closemessage
# 70 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 71 "data/maps/Route1NN/scripts.pory"
	setobjectxy LOCALID_PLAYER, 27, 18
# 72 "data/maps/Route1NN/scripts.pory"
	special StopAllObjectMovements
# 73 "data/maps/Route1NN/scripts.pory"
	special CloseScriptMenus
# 74 "data/maps/Route1NN/scripts.pory"
	special SnapCameraToPlayer
# 75 "data/maps/Route1NN/scripts.pory"
	removeobject rt1_yungoos
# 76 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet
# 77 "data/maps/Route1NN/scripts.pory"
	removeobject litten
# 78 "data/maps/Route1NN/scripts.pory"
	removeobject popplio
# 79 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny
# 80 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny
# 81 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny
# 82 "data/maps/Route1NN/scripts.pory"
	removeobject techguy
# 83 "data/maps/Route1NN/scripts.pory"
	addobject kukuistarters
# 84 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStartersSkip_Movement_0
# 85 "data/maps/Route1NN/scripts.pory"
	setobjectxy kukuistarters, 28, 18
# 86 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersSkip_Movement_0
# 87 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersSkip_2
# 93 "data/maps/Route1NN/scripts.pory"
	addobject rowlet2
# 94 "data/maps/Route1NN/scripts.pory"
	setobjectxy rowlet2, 26, 16
# 95 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStartersSkip_Movement_1
Route1NN_Trigger_GetStartersSkip_1:
# 97 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersSkip_6
# 103 "data/maps/Route1NN/scripts.pory"
	addobject litten2
# 104 "data/maps/Route1NN/scripts.pory"
	setobjectxy litten2, 27, 16
# 105 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStartersSkip_Movement_1
Route1NN_Trigger_GetStartersSkip_5:
# 107 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersSkip_10
# 113 "data/maps/Route1NN/scripts.pory"
	addobject popplio2
# 114 "data/maps/Route1NN/scripts.pory"
	setobjectxy popplio2, 28, 16
# 115 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStartersSkip_Movement_1
Route1NN_Trigger_GetStartersSkip_9:
# 117 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 118 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 119 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO
# 120 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 121 "data/maps/Route1NN/scripts.pory"
	call Route1NN_Trigger_GetStartersPart2
	return

Route1NN_Trigger_GetStartersSkip_2:
# 88 "data/maps/Route1NN/scripts.pory"
	addobject rowletshiny2
# 89 "data/maps/Route1NN/scripts.pory"
	setobjectxy rowletshiny2, 26, 16
# 90 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStartersSkip_Movement_1
	goto Route1NN_Trigger_GetStartersSkip_1

Route1NN_Trigger_GetStartersSkip_6:
# 98 "data/maps/Route1NN/scripts.pory"
	addobject littenshiny2
# 99 "data/maps/Route1NN/scripts.pory"
	setobjectxy littenshiny2, 27, 16
# 100 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStartersSkip_Movement_1
	goto Route1NN_Trigger_GetStartersSkip_5

Route1NN_Trigger_GetStartersSkip_10:
# 108 "data/maps/Route1NN/scripts.pory"
	addobject popplioshiny2
# 109 "data/maps/Route1NN/scripts.pory"
	setobjectxy popplioshiny2, 28, 16
# 110 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStartersSkip_Movement_1
	goto Route1NN_Trigger_GetStartersSkip_9


Route1NN_Trigger_GetStarters::
# 126 "data/maps/Route1NN/scripts.pory"
	lock
# 127 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO
# 128 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 129 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 130 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 131 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 132 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 133 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 134 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 135 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 136 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 137 "data/maps/Route1NN/scripts.pory"
	startcutscene CUTSCENE_PLAYER_GET_STARTER
# 138 "data/maps/Route1NN/scripts.pory"
	playse SE_M_SCRATCH
# 139 "data/maps/Route1NN/scripts.pory"
	waitse
# 140 "data/maps/Route1NN/scripts.pory"
	addobject rt1_yungoos
# 141 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 142 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_0
# 143 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 144 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_1
# 145 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 146 "data/maps/Route1NN/scripts.pory"
	delay 30
# 147 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_YUNGOOS, 0
# 148 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_0, MSGBOX_AUTOCLOSE
# 149 "data/maps/Route1NN/scripts.pory"
	waitmessage
# 150 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_2
# 151 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 152 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 153 "data/maps/Route1NN/scripts.pory"
	addobject kukuistarters
# 154 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_3
# 155 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_2
# 160 "data/maps/Route1NN/scripts.pory"
	addobject rowlet
# 161 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_4
Route1NN_Trigger_GetStarters_1:
# 163 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_6
# 168 "data/maps/Route1NN/scripts.pory"
	addobject litten
# 169 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_5
Route1NN_Trigger_GetStarters_5:
# 171 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_10
# 176 "data/maps/Route1NN/scripts.pory"
	addobject popplio
# 177 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_6
Route1NN_Trigger_GetStarters_9:
# 179 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 180 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 181 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_14
# 188 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 189 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_7
# 190 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet
# 191 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_1, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_13:
# 193 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_18
# 200 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 201 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_7
# 202 "data/maps/Route1NN/scripts.pory"
	waitmovement litten
# 203 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_3, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_17:
# 205 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_22
# 212 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 213 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_7
# 214 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio
# 215 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_5, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_21:
# 217 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_YUNGOOS, 0
# 218 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_8
# 219 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 220 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_6, MSGBOX_AUTOCLOSE
# 221 "data/maps/Route1NN/scripts.pory"
	playse SE_FLEE
# 222 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_9
# 223 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 224 "data/maps/Route1NN/scripts.pory"
	delay 60
# 225 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_26
# 229 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_25:
# 231 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_30
# 235 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_29:
# 237 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_34
# 241 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_33:
# 243 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 244 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 245 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_11
# 246 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 247 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 248 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_12
# 249 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 250 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 251 "data/maps/Route1NN/scripts.pory"
	delay 60
# 252 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_13
# 253 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 254 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_7, MSGBOX_AUTOCLOSE
# 255 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_14
# 256 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_14
# 257 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 258 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_38
# 262 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_14
Route1NN_Trigger_GetStarters_37:
# 264 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_42
# 268 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_14
Route1NN_Trigger_GetStarters_41:
# 270 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_46
# 274 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_14
Route1NN_Trigger_GetStarters_45:
# 276 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 277 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 278 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_8
# 284 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 11, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_9, Route1NN_Trigger_GetStarters_Text_10
# 285 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Route1NN_Trigger_GetStarters_50
# 301 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 302 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 303 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 304 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_12
Route1NN_Trigger_GetStarters_49:
# 310 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 311 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_13
# 316 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_16
# 317 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 318 "data/maps/Route1NN/scripts.pory"
	waitse
# 319 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 320 "data/maps/Route1NN/scripts.pory"
	waitse
# 321 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 323 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_14
# 336 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_16
# 337 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 338 "data/maps/Route1NN/scripts.pory"
	waitse
# 339 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 340 "data/maps/Route1NN/scripts.pory"
	waitse
# 341 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 342 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_15, MSGBOX_AUTOCLOSE
# 352 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 353 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_TEMP_2
# 354 "data/maps/Route1NN/scripts.pory"
	removeobject techguy
# 355 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_17
# 356 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 357 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_18
# 358 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 359 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_19
# 360 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersSkip_Movement_0
# 361 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 362 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet
# 363 "data/maps/Route1NN/scripts.pory"
	removeobject litten
# 364 "data/maps/Route1NN/scripts.pory"
	removeobject popplio
# 365 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny
# 366 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny
# 367 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny
# 368 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_54
# 373 "data/maps/Route1NN/scripts.pory"
	addobject rowlet2
# 374 "data/maps/Route1NN/scripts.pory"
	setobjectxy rowlet2, 26, 16
Route1NN_Trigger_GetStarters_53:
# 376 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_58
# 381 "data/maps/Route1NN/scripts.pory"
	addobject litten2
# 382 "data/maps/Route1NN/scripts.pory"
	setobjectxy litten2, 27, 16
Route1NN_Trigger_GetStarters_57:
# 384 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_62
# 389 "data/maps/Route1NN/scripts.pory"
	addobject popplio2
# 390 "data/maps/Route1NN/scripts.pory"
	setobjectxy popplio2, 28, 16
Route1NN_Trigger_GetStarters_61:
# 392 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 393 "data/maps/Route1NN/scripts.pory"
	delay 60
# 394 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_20
# 395 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 396 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_16
# 397 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_66
# 408 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 409 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 410 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_17, MSGBOX_AUTOCLOSE
# 411 "data/maps/Route1NN/scripts.pory"
	closemessage
# 412 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_21
# 413 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 414 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 415 "data/maps/Route1NN/scripts.pory"
	delay 30
Route1NN_Trigger_GetStarters_65:
# 417 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 418 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_2
# 419 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 420 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_18
# 421 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_70
# 433 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 434 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 435 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_19, MSGBOX_AUTOCLOSE
# 436 "data/maps/Route1NN/scripts.pory"
	closemessage
# 437 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_22
# 438 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 439 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 440 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 441 "data/maps/Route1NN/scripts.pory"
	delay 30
Route1NN_Trigger_GetStarters_69:
# 443 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 444 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_2
# 445 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 446 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_20
# 447 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_74
# 462 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 463 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 464 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_21, MSGBOX_AUTOCLOSE
# 465 "data/maps/Route1NN/scripts.pory"
	closemessage
# 466 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_23
# 467 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 468 "data/maps/Route1NN/scripts.pory"
	waitse
# 469 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 470 "data/maps/Route1NN/scripts.pory"
	waitse
# 471 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 472 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 473 "data/maps/Route1NN/scripts.pory"
	delay 30
Route1NN_Trigger_GetStarters_73:
# 475 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 476 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_24
# 477 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 478 "data/maps/Route1NN/scripts.pory"
	call Route1NN_Trigger_GetStartersPart2
# 479 "data/maps/Route1NN/scripts.pory"
	endcutscene
	return

Route1NN_Trigger_GetStarters_2:
# 156 "data/maps/Route1NN/scripts.pory"
	addobject rowletshiny
# 157 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_4
	goto Route1NN_Trigger_GetStarters_1

Route1NN_Trigger_GetStarters_6:
# 164 "data/maps/Route1NN/scripts.pory"
	addobject littenshiny
# 165 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_5
	goto Route1NN_Trigger_GetStarters_5

Route1NN_Trigger_GetStarters_10:
# 172 "data/maps/Route1NN/scripts.pory"
	addobject popplioshiny
# 173 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_6
	goto Route1NN_Trigger_GetStarters_9

Route1NN_Trigger_GetStarters_14:
# 182 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 183 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_7
# 184 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny
# 185 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_1, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_13

Route1NN_Trigger_GetStarters_18:
# 194 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 195 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_7
# 196 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny
# 197 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_2, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_17

Route1NN_Trigger_GetStarters_22:
# 206 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 207 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_7
# 208 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny
# 209 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_4, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_21

Route1NN_Trigger_GetStarters_26:
# 226 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_25

Route1NN_Trigger_GetStarters_30:
# 232 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_29

Route1NN_Trigger_GetStarters_34:
# 238 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_33

Route1NN_Trigger_GetStarters_38:
# 259 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_14
	goto Route1NN_Trigger_GetStarters_37

Route1NN_Trigger_GetStarters_42:
# 265 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_14
	goto Route1NN_Trigger_GetStarters_41

Route1NN_Trigger_GetStarters_46:
# 271 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_14
	goto Route1NN_Trigger_GetStarters_45

Route1NN_Trigger_GetStarters_50:
# 287 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 288 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 289 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 290 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_11
	goto Route1NN_Trigger_GetStarters_49

Route1NN_Trigger_GetStarters_54:
# 369 "data/maps/Route1NN/scripts.pory"
	addobject rowletshiny2
# 370 "data/maps/Route1NN/scripts.pory"
	setobjectxy rowletshiny2, 26, 16
	goto Route1NN_Trigger_GetStarters_53

Route1NN_Trigger_GetStarters_58:
# 377 "data/maps/Route1NN/scripts.pory"
	addobject littenshiny2
# 378 "data/maps/Route1NN/scripts.pory"
	setobjectxy littenshiny2, 27, 16
	goto Route1NN_Trigger_GetStarters_57

Route1NN_Trigger_GetStarters_62:
# 385 "data/maps/Route1NN/scripts.pory"
	addobject popplioshiny2
# 386 "data/maps/Route1NN/scripts.pory"
	setobjectxy popplioshiny2, 28, 16
	goto Route1NN_Trigger_GetStarters_61

Route1NN_Trigger_GetStarters_66:
# 398 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 399 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 400 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_17, MSGBOX_AUTOCLOSE
# 401 "data/maps/Route1NN/scripts.pory"
	closemessage
# 402 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_21
# 403 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 404 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 405 "data/maps/Route1NN/scripts.pory"
	delay 30
	goto Route1NN_Trigger_GetStarters_65

Route1NN_Trigger_GetStarters_70:
# 422 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 423 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 424 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_19, MSGBOX_AUTOCLOSE
# 425 "data/maps/Route1NN/scripts.pory"
	closemessage
# 426 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_22
# 427 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 428 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 429 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 430 "data/maps/Route1NN/scripts.pory"
	delay 30
	goto Route1NN_Trigger_GetStarters_69

Route1NN_Trigger_GetStarters_74:
# 448 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 449 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 450 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_21, MSGBOX_AUTOCLOSE
# 451 "data/maps/Route1NN/scripts.pory"
	closemessage
# 452 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_23
# 453 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 454 "data/maps/Route1NN/scripts.pory"
	waitse
# 455 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 456 "data/maps/Route1NN/scripts.pory"
	waitse
# 457 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 458 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 459 "data/maps/Route1NN/scripts.pory"
	delay 30
	goto Route1NN_Trigger_GetStarters_73


Route1NN_Trigger_GetStartersPart2::
# 483 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_0
# 495 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStartersPart2_Text_1, Route1NN_Trigger_GetStartersPart2_Text_2, Route1NN_Trigger_GetStartersPart2_Text_3
# 496 "data/maps/Route1NN/scripts.pory"
	switch VAR_RESULT
# 497 "data/maps/Route1NN/scripts.pory"
	case 0, Route1NN_Trigger_GetStartersPart2_3
# 547 "data/maps/Route1NN/scripts.pory"
	case 1, Route1NN_Trigger_GetStartersPart2_4
# 601 "data/maps/Route1NN/scripts.pory"
	case 2, Route1NN_Trigger_GetStartersPart2_5
Route1NN_Trigger_GetStartersPart2_1:
# 656 "data/maps/Route1NN/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 657 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersPart2_Movement_5
# 658 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_10
# 659 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 660 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_8, MSGBOX_YESNO
# 662 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route1NN_Trigger_GetStartersPart2_7
# 667 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_9, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStartersPart2_6:
# 670 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 671 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 672 "data/maps/Route1NN/scripts.pory"
	delay 60
# 673 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 674 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 675 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
# 676 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 677 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
# 678 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 679 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
# 680 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 681 "data/maps/Route1NN/scripts.pory"
	startcutscene CUTSCENE_KUKUI_POINTS_TO_IKI
# 682 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 683 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 684 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_10
# 695 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 696 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 697 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_11, MSGBOX_AUTOCLOSE
# 698 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 699 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 700 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_12
# 706 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStartersPart2_Text_13, Route1NN_Trigger_GetStartersPart2_Text_14
# 707 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Route1NN_Trigger_GetStartersPart2_20
# 730 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 731 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 732 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_15, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStartersPart2_19:
# 749 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersPart2_Movement_6
# 750 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStartersPart2_Movement_7
# 751 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStartersPart2_Movement_7
# 752 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 753 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_HIDE_KUKUI_STARTERS
# 754 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersSkip_Movement_1
# 755 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 756 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_16, MSGBOX_AUTOCLOSE
# 757 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 758 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersPart2_Movement_5
# 759 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 760 "data/maps/Route1NN/scripts.pory"
	delay 30
# 761 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStartersPart2_Movement_8
# 762 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 763 "data/maps/Route1NN/scripts.pory"
	delay 90
# 764 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 765 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStartersPart2_Movement_9
# 766 "data/maps/Route1NN/scripts.pory"
	setobjectxy kukuistarters, 21, 19
# 767 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 768 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 769 "data/maps/Route1NN/scripts.pory"
	addobject techguy
# 770 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_TEMP_2
# 771 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTERS_STATE, 1
# 772 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 773 "data/maps/Route1NN/scripts.pory"
	endcutscene
# 774 "data/maps/Route1NN/scripts.pory"
	release
	end

Route1NN_Trigger_GetStartersPart2_3:
# 498 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 499 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_4, MSGBOX_YESNO
# 504 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_Trigger_GetStartersPart2_10
# 541 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 542 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_5
# 545 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_Trigger_GetStartersPart2_1

Route1NN_Trigger_GetStartersPart2_4:
# 548 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 549 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_6, MSGBOX_YESNO
# 554 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_Trigger_GetStartersPart2_13
# 595 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 596 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_5
# 599 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_Trigger_GetStartersPart2_1

Route1NN_Trigger_GetStartersPart2_5:
# 602 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 603 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_7, MSGBOX_YESNO
# 608 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_Trigger_GetStartersPart2_16
# 649 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 650 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_5
# 653 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_Trigger_GetStartersPart2_1

Route1NN_Trigger_GetStartersPart2_7:
# 663 "data/maps/Route1NN/scripts.pory"
	setvar VAR_0x8004, 0
# 664 "data/maps/Route1NN/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto Route1NN_Trigger_GetStartersPart2_6

Route1NN_Trigger_GetStartersPart2_10:
# 505 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersPart2_24
Route1NN_Trigger_GetStartersPart2_23:
# 508 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersPart2_33
Route1NN_Trigger_GetStartersPart2_32:
# 511 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersPart2_42
# 525 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
# 526 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStartersPart2_Movement_0
# 527 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 528 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 529 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStartersPart2_Movement_1
# 530 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 531 "data/maps/Route1NN/scripts.pory"
	delay 30
# 532 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 533 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 534 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 535 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStartersPart2_41:
# 537 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 0
	goto Route1NN_Trigger_GetStartersPart2_1

Route1NN_Trigger_GetStartersPart2_13:
# 555 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersPart2_27
Route1NN_Trigger_GetStartersPart2_26:
# 558 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersPart2_36
Route1NN_Trigger_GetStartersPart2_35:
# 561 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersPart2_46
# 577 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
# 578 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStartersPart2_Movement_3
# 579 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 580 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 581 "data/maps/Route1NN/scripts.pory"
	waitse
# 582 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 583 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_22
# 584 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 585 "data/maps/Route1NN/scripts.pory"
	delay 30
# 586 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 587 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 588 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 589 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStartersPart2_45:
# 591 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 1
	goto Route1NN_Trigger_GetStartersPart2_1

Route1NN_Trigger_GetStartersPart2_16:
# 609 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersPart2_30
Route1NN_Trigger_GetStartersPart2_29:
# 612 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersPart2_39
Route1NN_Trigger_GetStartersPart2_38:
# 615 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStartersPart2_50
# 631 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
# 632 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStartersPart2_Movement_4
# 633 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 634 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 635 "data/maps/Route1NN/scripts.pory"
	waitse
# 636 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 637 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_22
# 638 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 639 "data/maps/Route1NN/scripts.pory"
	delay 30
# 640 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 641 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 642 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 643 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStartersPart2_49:
# 645 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 2
	goto Route1NN_Trigger_GetStartersPart2_1

Route1NN_Trigger_GetStartersPart2_20:
# 709 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 710 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 711 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_15, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStartersPart2_19

Route1NN_Trigger_GetStartersPart2_24:
# 506 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_Trigger_GetStartersPart2_23

Route1NN_Trigger_GetStartersPart2_27:
# 556 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_Trigger_GetStartersPart2_26

Route1NN_Trigger_GetStartersPart2_30:
# 610 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_Trigger_GetStartersPart2_29

Route1NN_Trigger_GetStartersPart2_33:
# 509 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_Trigger_GetStartersPart2_32

Route1NN_Trigger_GetStartersPart2_36:
# 559 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_Trigger_GetStartersPart2_35

Route1NN_Trigger_GetStartersPart2_39:
# 613 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_Trigger_GetStartersPart2_38

Route1NN_Trigger_GetStartersPart2_42:
# 512 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_ALWAYS
# 513 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStartersPart2_Movement_0
# 514 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 515 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 516 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStartersPart2_Movement_1
# 517 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 518 "data/maps/Route1NN/scripts.pory"
	delay 30
# 519 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 520 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 521 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 522 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStartersPart2_41

Route1NN_Trigger_GetStartersPart2_46:
# 562 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_ALWAYS
# 563 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStartersPart2_Movement_3
# 564 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 565 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 566 "data/maps/Route1NN/scripts.pory"
	waitse
# 567 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 568 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_22
# 569 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 570 "data/maps/Route1NN/scripts.pory"
	delay 30
# 571 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 572 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 573 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 574 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStartersPart2_45

Route1NN_Trigger_GetStartersPart2_50:
# 616 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_ALWAYS
# 617 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStartersPart2_Movement_4
# 618 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 619 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 620 "data/maps/Route1NN/scripts.pory"
	waitse
# 621 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 622 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_22
# 623 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 624 "data/maps/Route1NN/scripts.pory"
	delay 30
# 625 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 626 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 627 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 628 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStartersPart2_49


Route1NN_Trigger_GetStartersSkipPart2::
# 779 "data/maps/Route1NN/scripts.pory"
	closemessage
# 780 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 781 "data/maps/Route1NN/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 20
# 782 "data/maps/Route1NN/scripts.pory"
	special StopAllObjectMovements
# 783 "data/maps/Route1NN/scripts.pory"
	special CloseScriptMenus
# 784 "data/maps/Route1NN/scripts.pory"
	special SnapCameraToPlayer
# 785 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 786 "data/maps/Route1NN/scripts.pory"
	setobjectxy kukuistarters, 21, 19
# 787 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersPart2_Movement_5
# 788 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStartersPart2_Movement_5
# 789 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 790 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_HIDE_KUKUI_STARTERS
# 791 "data/maps/Route1NN/scripts.pory"
	addobject techguy
# 792 "data/maps/Route1NN/scripts.pory"
	setobjectxy techguy, 25, 16
# 793 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_TEMP_2
# 794 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTERS_STATE, 1
# 795 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 796 "data/maps/Route1NN/scripts.pory"
	release
	end


Route1NN_BackOutOfStarter::
# 802 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 803 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_BackOutOfStarter_Text_0
# 805 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStartersPart2_Text_1, Route1NN_Trigger_GetStartersPart2_Text_2, Route1NN_Trigger_GetStartersPart2_Text_3
# 806 "data/maps/Route1NN/scripts.pory"
	switch VAR_RESULT
# 807 "data/maps/Route1NN/scripts.pory"
	case 0, Route1NN_BackOutOfStarter_3
# 857 "data/maps/Route1NN/scripts.pory"
	case 1, Route1NN_BackOutOfStarter_4
# 911 "data/maps/Route1NN/scripts.pory"
	case 2, Route1NN_BackOutOfStarter_5
Route1NN_BackOutOfStarter_1:
# 966 "data/maps/Route1NN/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 967 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersPart2_Movement_5
# 968 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_10
# 969 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 970 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_8, MSGBOX_YESNO
# 972 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route1NN_BackOutOfStarter_7
# 977 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_9, MSGBOX_AUTOCLOSE
Route1NN_BackOutOfStarter_6:
# 980 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 981 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 982 "data/maps/Route1NN/scripts.pory"
	delay 60
# 983 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 984 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 985 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
# 986 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 987 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
# 988 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 989 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
# 990 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 991 "data/maps/Route1NN/scripts.pory"
	startcutscene CUTSCENE_KUKUI_POINTS_TO_IKI
# 992 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 993 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 994 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_10
# 1005 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1006 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1007 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_11, MSGBOX_AUTOCLOSE
# 1008 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1009 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 1010 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_BackOutOfStarter_Text_1
# 1016 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStartersPart2_Text_13, Route1NN_Trigger_GetStartersPart2_Text_14
# 1017 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Route1NN_BackOutOfStarter_20
# 1040 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 1041 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 1042 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_15, MSGBOX_AUTOCLOSE
Route1NN_BackOutOfStarter_19:
# 1059 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersPart2_Movement_6
# 1060 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStartersPart2_Movement_7
# 1061 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStartersPart2_Movement_7
# 1062 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 1063 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_HIDE_KUKUI_STARTERS
# 1064 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersSkip_Movement_1
# 1065 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 1066 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_16, MSGBOX_AUTOCLOSE
# 1067 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 1068 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStartersPart2_Movement_5
# 1069 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 1070 "data/maps/Route1NN/scripts.pory"
	delay 30
# 1071 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStartersPart2_Movement_8
# 1072 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 1073 "data/maps/Route1NN/scripts.pory"
	delay 90
# 1074 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1075 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStartersPart2_Movement_9
# 1076 "data/maps/Route1NN/scripts.pory"
	setobjectxy kukuistarters, 21, 19
# 1077 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 1078 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 1079 "data/maps/Route1NN/scripts.pory"
	addobject techguy
# 1080 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_TEMP_2
# 1081 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTERS_STATE, 1
# 1082 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1083 "data/maps/Route1NN/scripts.pory"
	endcutscene
# 1084 "data/maps/Route1NN/scripts.pory"
	release
	end

Route1NN_BackOutOfStarter_3:
# 808 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 809 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_4, MSGBOX_YESNO
# 814 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_BackOutOfStarter_10
# 851 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 852 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_5
# 855 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_4:
# 858 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 859 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_6, MSGBOX_YESNO
# 864 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_BackOutOfStarter_13
# 905 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 906 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_5
# 909 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_5:
# 912 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 913 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_7, MSGBOX_YESNO
# 918 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_BackOutOfStarter_16
# 959 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 960 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_5
# 963 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_7:
# 973 "data/maps/Route1NN/scripts.pory"
	setvar VAR_0x8004, 0
# 974 "data/maps/Route1NN/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto Route1NN_BackOutOfStarter_6

Route1NN_BackOutOfStarter_10:
# 815 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_24
Route1NN_BackOutOfStarter_23:
# 818 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_33
Route1NN_BackOutOfStarter_32:
# 821 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_42
# 835 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
# 836 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStartersPart2_Movement_0
# 837 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 838 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 839 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStartersPart2_Movement_1
# 840 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 841 "data/maps/Route1NN/scripts.pory"
	delay 30
# 842 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 843 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 844 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 845 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_BackOutOfStarter_41:
# 847 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 0
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_13:
# 865 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_27
Route1NN_BackOutOfStarter_26:
# 868 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_36
Route1NN_BackOutOfStarter_35:
# 871 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_46
# 887 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
# 888 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStartersPart2_Movement_3
# 889 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 890 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 891 "data/maps/Route1NN/scripts.pory"
	waitse
# 892 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 893 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_22
# 894 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 895 "data/maps/Route1NN/scripts.pory"
	delay 30
# 896 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 897 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 898 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 899 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_BackOutOfStarter_45:
# 901 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 1
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_16:
# 919 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_30
Route1NN_BackOutOfStarter_29:
# 922 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_39
Route1NN_BackOutOfStarter_38:
# 925 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_50
# 941 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
# 942 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStartersPart2_Movement_4
# 943 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 944 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 945 "data/maps/Route1NN/scripts.pory"
	waitse
# 946 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 947 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_22
# 948 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 949 "data/maps/Route1NN/scripts.pory"
	delay 30
# 950 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 951 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 952 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 953 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_BackOutOfStarter_49:
# 955 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 2
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_20:
# 1019 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 1020 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 1021 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStartersPart2_Text_15, MSGBOX_AUTOCLOSE
	goto Route1NN_BackOutOfStarter_19

Route1NN_BackOutOfStarter_24:
# 816 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_BackOutOfStarter_23

Route1NN_BackOutOfStarter_27:
# 866 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_BackOutOfStarter_26

Route1NN_BackOutOfStarter_30:
# 920 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_BackOutOfStarter_29

Route1NN_BackOutOfStarter_33:
# 819 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_BackOutOfStarter_32

Route1NN_BackOutOfStarter_36:
# 869 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_BackOutOfStarter_35

Route1NN_BackOutOfStarter_39:
# 923 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_BackOutOfStarter_38

Route1NN_BackOutOfStarter_42:
# 822 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_ALWAYS
# 823 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStartersPart2_Movement_0
# 824 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 825 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 826 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStartersPart2_Movement_1
# 827 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 828 "data/maps/Route1NN/scripts.pory"
	delay 30
# 829 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 830 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 831 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 832 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_BackOutOfStarter_41

Route1NN_BackOutOfStarter_46:
# 872 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_ALWAYS
# 873 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStartersPart2_Movement_3
# 874 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 875 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 876 "data/maps/Route1NN/scripts.pory"
	waitse
# 877 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 878 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_22
# 879 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 880 "data/maps/Route1NN/scripts.pory"
	delay 30
# 881 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 882 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 883 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 884 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_BackOutOfStarter_45

Route1NN_BackOutOfStarter_50:
# 926 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_ALWAYS
# 927 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStartersPart2_Movement_4
# 928 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 929 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 930 "data/maps/Route1NN/scripts.pory"
	waitse
# 931 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 932 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_22
# 933 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 934 "data/maps/Route1NN/scripts.pory"
	delay 30
# 935 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 936 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStartersPart2_Movement_2
# 937 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 938 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_BackOutOfStarter_49


Route1NN_Rockruff::
# 1089 "data/maps/Route1NN/scripts.pory"
	lock
# 1090 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 1091 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 1092 "data/maps/Route1NN/scripts.pory"
	applymovement route1nnrockruff, Route1NN_Rockruff_Movement_0
# 1093 "data/maps/Route1NN/scripts.pory"
	waitmovement route1nnrockruff
# 1094 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Rockruff_Text_0, MSGBOX_AUTOCLOSE
# 1095 "data/maps/Route1NN/scripts.pory"
	release
	end


Route1NN_CatchingTutorial::
# 1100 "data/maps/Route1NN/scripts.pory"
	lock
# 1101 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 1102 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_CatchingTutorial_Movement_0
# 1103 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 1104 "data/maps/Route1NN/scripts.pory"
	delay 30
# 1105 "data/maps/Route1NN/scripts.pory"
	applymovement kukuicatchtut, Route1NN_CatchingTutorial_Movement_1
# 1106 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 1107 "data/maps/Route1NN/scripts.pory"
	waitse
# 1108 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 1109 "data/maps/Route1NN/scripts.pory"
	waitse
# 1110 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuicatchtut
# 1111 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 1112 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_CatchingTutorial_Text_0, MSGBOX_AUTOCLOSE
# 1113 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_CatchingTutorial_Movement_2
# 1114 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 1115 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 1116 "data/maps/Route1NN/scripts.pory"
	delay 30
# 1117 "data/maps/Route1NN/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 1118 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_0, 48
	goto_if_eq Route1NN_CatchingTutorial_2
Route1NN_CatchingTutorial_1:
# 1122 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_0, 46
	goto_if_eq Route1NN_CatchingTutorial_5
Route1NN_CatchingTutorial_4:
# 1126 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_0, 47
	goto_if_eq Route1NN_CatchingTutorial_8
Route1NN_CatchingTutorial_7:
# 1130 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_0, 49
	goto_if_eq Route1NN_CatchingTutorial_11
Route1NN_CatchingTutorial_10:
# 1134 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 1135 "data/maps/Route1NN/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 1136 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_CatchingTutorial_Text_1, MSGBOX_AUTOCLOSE
# 1143 "data/maps/Route1NN/scripts.pory"
	waitmessage
# 1144 "data/maps/Route1NN/scripts.pory"
	helpwindow HELP_CATCHING_GUIDE
# 1145 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 1146 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_CatchingTutorial_Text_2
# 1158 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1159 "data/maps/Route1NN/scripts.pory"
	giveitem ITEM_POKE_BALL, 10
# 1160 "data/maps/Route1NN/scripts.pory"
	giveitem ITEM_POTION, 5
# 1161 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1162 "data/maps/Route1NN/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 1163 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 1164 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_CatchingTutorial_Text_3, MSGBOX_AUTOCLOSE
# 1169 "data/maps/Route1NN/scripts.pory"
	applymovement kukuicatchtut, Route1NN_CatchingTutorial_Movement_3
# 1170 "data/maps/Route1NN/scripts.pory"
	applymovement rockruffcatchtut, Route1NN_CatchingTutorial_Movement_3
# 1171 "data/maps/Route1NN/scripts.pory"
	delay 60
# 1172 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1173 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1174 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_CATCHING_TUTORIAL2
# 1175 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_ENABLE_OW_MON_OPTION
# 1176 "data/maps/Route1NN/scripts.pory"
	setvar VAR_IKITOWN_STATE, 12
# 1177 "data/maps/Route1NN/scripts.pory"
	playse SE_EXIT
# 1178 "data/maps/Route1NN/scripts.pory"
	waitse
# 1179 "data/maps/Route1NN/scripts.pory"
	removeobject kukuicatchtut
# 1180 "data/maps/Route1NN/scripts.pory"
	removeobject rockruffcatchtut
# 1181 "data/maps/Route1NN/scripts.pory"
	delay 60
# 1182 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1183 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1184 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_CatchingTutorial_Text_4, MSGBOX_AUTOCLOSE
# 1186 "data/maps/Route1NN/scripts.pory"
	waitfanfare
# 1187 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1188 "data/maps/Route1NN/scripts.pory"
	helpwindow HELP_OVERWORLD_MON_GUIDE
# 1189 "data/maps/Route1NN/scripts.pory"
	release
	end

Route1NN_CatchingTutorial_2:
# 1120 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_CatchingTutorial_Movement_3
	goto Route1NN_CatchingTutorial_1

Route1NN_CatchingTutorial_5:
# 1124 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_CatchingTutorial_Movement_4
	goto Route1NN_CatchingTutorial_4

Route1NN_CatchingTutorial_8:
# 1128 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_CatchingTutorial_Movement_5
	goto Route1NN_CatchingTutorial_7

Route1NN_CatchingTutorial_11:
# 1132 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_CatchingTutorial_Movement_6
	goto Route1NN_CatchingTutorial_10


# 10 "data/maps/Route1NN/scripts.pory"
YungoosMeowth_Blocking_Movement_0:
# 10 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 10 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
	step_end

# 14 "data/maps/Route1NN/scripts.pory"
YungoosMeowth_Blocking_Movement_1:
# 14 "data/maps/Route1NN/scripts.pory"
	walk_in_place_up
# 14 "data/maps/Route1NN/scripts.pory"
	walk_in_place_up
	step_end

# 49 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_MiddleGetStarters_Movement_0:
# 49 "data/maps/Route1NN/scripts.pory"
	walk_up
# 49 "data/maps/Route1NN/scripts.pory"
	face_left
	step_end

# 56 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_BottomGetStarters_Movement_0:
# 56 "data/maps/Route1NN/scripts.pory"
	walk_up
# 56 "data/maps/Route1NN/scripts.pory"
	walk_up
# 56 "data/maps/Route1NN/scripts.pory"
	face_left
	step_end

# 63 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_TopGetStarters_Movement_0:
# 63 "data/maps/Route1NN/scripts.pory"
	walk_down
# 63 "data/maps/Route1NN/scripts.pory"
	face_left
	step_end

# 84 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersSkip_Movement_0:
# 84 "data/maps/Route1NN/scripts.pory"
	face_up
	step_end

# 90 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersSkip_Movement_1:
# 90 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 142 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_0:
# 142 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
	step_end

# 144 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_1:
# 144 "data/maps/Route1NN/scripts.pory"
	walk_right
# 144 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 150 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_2:
# 150 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 154 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_3:
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 154 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
	step_end

# 157 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_4:
# 157 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 157 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 157 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 157 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 157 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 157 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 157 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 157 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 157 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 165 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_5:
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 165 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 173 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_6:
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 173 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 183 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_7:
# 183 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
# 183 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
# 183 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
	step_end

# 218 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_8:
# 218 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
# 218 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
# 218 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
	step_end

# 222 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_9:
# 222 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 222 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 222 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 222 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 222 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 222 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 222 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
	step_end

# 226 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_10:
# 226 "data/maps/Route1NN/scripts.pory"
	face_right
	step_end

# 245 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_11:
# 245 "data/maps/Route1NN/scripts.pory"
	walk_up
# 245 "data/maps/Route1NN/scripts.pory"
	walk_up
# 245 "data/maps/Route1NN/scripts.pory"
	walk_up
# 245 "data/maps/Route1NN/scripts.pory"
	walk_up
# 245 "data/maps/Route1NN/scripts.pory"
	walk_up
# 245 "data/maps/Route1NN/scripts.pory"
	walk_up
# 245 "data/maps/Route1NN/scripts.pory"
	face_left
# 245 "data/maps/Route1NN/scripts.pory"
	delay_16
	step_end

# 248 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_12:
# 248 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
# 248 "data/maps/Route1NN/scripts.pory"
	face_right
	step_end

# 252 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_13:
# 252 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
# 252 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
	step_end

# 255 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_14:
# 255 "data/maps/Route1NN/scripts.pory"
	walk_right
# 255 "data/maps/Route1NN/scripts.pory"
	walk_right
# 255 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 287 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_15:
# 287 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
# 287 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
	step_end

# 316 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_16:
# 316 "data/maps/Route1NN/scripts.pory"
	jump_in_place_left
# 316 "data/maps/Route1NN/scripts.pory"
	jump_in_place_left
	step_end

# 355 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_17:
# 355 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 355 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 355 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 355 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 355 "data/maps/Route1NN/scripts.pory"
	face_up
	step_end

# 357 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_18:
# 357 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 357 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 357 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 357 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
	step_end

# 359 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_19:
# 359 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 359 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 359 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
	step_end

# 394 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_20:
# 394 "data/maps/Route1NN/scripts.pory"
	walk_slow_up
# 394 "data/maps/Route1NN/scripts.pory"
	walk_slow_diag_northwest
	step_end

# 402 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_21:
# 402 "data/maps/Route1NN/scripts.pory"
	face_left
# 402 "data/maps/Route1NN/scripts.pory"
	delay_16
# 402 "data/maps/Route1NN/scripts.pory"
	face_up
# 402 "data/maps/Route1NN/scripts.pory"
	delay_16
# 402 "data/maps/Route1NN/scripts.pory"
	face_right
# 402 "data/maps/Route1NN/scripts.pory"
	delay_16
# 402 "data/maps/Route1NN/scripts.pory"
	face_down
# 402 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 402 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
	step_end

# 426 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_22:
# 426 "data/maps/Route1NN/scripts.pory"
	jump_in_place_down
	step_end

# 452 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_23:
# 452 "data/maps/Route1NN/scripts.pory"
	face_up
# 452 "data/maps/Route1NN/scripts.pory"
	delay_16
# 452 "data/maps/Route1NN/scripts.pory"
	walk_in_place_up
# 452 "data/maps/Route1NN/scripts.pory"
	walk_in_place_up
# 452 "data/maps/Route1NN/scripts.pory"
	delay_16
# 452 "data/maps/Route1NN/scripts.pory"
	delay_16
# 452 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 476 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_24:
# 476 "data/maps/Route1NN/scripts.pory"
	walk_slow_diag_southwest
# 476 "data/maps/Route1NN/scripts.pory"
	walk_slow_down
	step_end

# 513 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersPart2_Movement_0:
# 513 "data/maps/Route1NN/scripts.pory"
	walk_down
# 513 "data/maps/Route1NN/scripts.pory"
	walk_right
# 513 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 516 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersPart2_Movement_1:
# 516 "data/maps/Route1NN/scripts.pory"
	face_left
# 516 "data/maps/Route1NN/scripts.pory"
	delay_16
# 516 "data/maps/Route1NN/scripts.pory"
	face_up
# 516 "data/maps/Route1NN/scripts.pory"
	delay_16
# 516 "data/maps/Route1NN/scripts.pory"
	face_right
# 516 "data/maps/Route1NN/scripts.pory"
	delay_16
# 516 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 520 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersPart2_Movement_2:
# 520 "data/maps/Route1NN/scripts.pory"
	emote_heart
	step_end

# 563 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersPart2_Movement_3:
# 563 "data/maps/Route1NN/scripts.pory"
	walk_down
	step_end

# 617 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersPart2_Movement_4:
# 617 "data/maps/Route1NN/scripts.pory"
	walk_down
# 617 "data/maps/Route1NN/scripts.pory"
	walk_left
# 617 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 657 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersPart2_Movement_5:
# 657 "data/maps/Route1NN/scripts.pory"
	face_left
	step_end

# 749 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersPart2_Movement_6:
# 749 "data/maps/Route1NN/scripts.pory"
	walk_down
# 749 "data/maps/Route1NN/scripts.pory"
	walk_left
# 749 "data/maps/Route1NN/scripts.pory"
	walk_left
# 749 "data/maps/Route1NN/scripts.pory"
	walk_left
# 749 "data/maps/Route1NN/scripts.pory"
	walk_left
# 749 "data/maps/Route1NN/scripts.pory"
	walk_left
# 749 "data/maps/Route1NN/scripts.pory"
	walk_left
# 749 "data/maps/Route1NN/scripts.pory"
	walk_left
	step_end

# 750 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersPart2_Movement_7:
# 750 "data/maps/Route1NN/scripts.pory"
	delay_16
# 750 "data/maps/Route1NN/scripts.pory"
	delay_16
# 750 "data/maps/Route1NN/scripts.pory"
	delay_16
# 750 "data/maps/Route1NN/scripts.pory"
	delay_16
# 750 "data/maps/Route1NN/scripts.pory"
	walk_down
# 750 "data/maps/Route1NN/scripts.pory"
	walk_down
# 750 "data/maps/Route1NN/scripts.pory"
	walk_left
# 750 "data/maps/Route1NN/scripts.pory"
	walk_left
# 750 "data/maps/Route1NN/scripts.pory"
	walk_left
# 750 "data/maps/Route1NN/scripts.pory"
	walk_left
# 750 "data/maps/Route1NN/scripts.pory"
	walk_left
# 750 "data/maps/Route1NN/scripts.pory"
	walk_left
	step_end

# 761 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersPart2_Movement_8:
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 761 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
# 761 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
# 761 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
	step_end

# 765 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStartersPart2_Movement_9:
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 765 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
	step_end

# 1092 "data/maps/Route1NN/scripts.pory"
Route1NN_Rockruff_Movement_0:
# 1092 "data/maps/Route1NN/scripts.pory"
	face_player
# 1092 "data/maps/Route1NN/scripts.pory"
	emote_heart
	step_end

# 1102 "data/maps/Route1NN/scripts.pory"
Route1NN_CatchingTutorial_Movement_0:
# 1102 "data/maps/Route1NN/scripts.pory"
	walk_fast_up
# 1102 "data/maps/Route1NN/scripts.pory"
	walk_fast_up
# 1102 "data/maps/Route1NN/scripts.pory"
	walk_fast_up
# 1102 "data/maps/Route1NN/scripts.pory"
	walk_fast_up
	step_end

# 1105 "data/maps/Route1NN/scripts.pory"
Route1NN_CatchingTutorial_Movement_1:
# 1105 "data/maps/Route1NN/scripts.pory"
	jump_in_place_down
# 1105 "data/maps/Route1NN/scripts.pory"
	jump_in_place_down
	step_end

# 1113 "data/maps/Route1NN/scripts.pory"
Route1NN_CatchingTutorial_Movement_2:
# 1113 "data/maps/Route1NN/scripts.pory"
	walk_fast_down
# 1113 "data/maps/Route1NN/scripts.pory"
	walk_fast_down
# 1113 "data/maps/Route1NN/scripts.pory"
	walk_fast_down
# 1113 "data/maps/Route1NN/scripts.pory"
	walk_fast_down
	step_end

# 1120 "data/maps/Route1NN/scripts.pory"
Route1NN_CatchingTutorial_Movement_3:
# 1120 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1120 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1120 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1120 "data/maps/Route1NN/scripts.pory"
	walk_up
	step_end

# 1124 "data/maps/Route1NN/scripts.pory"
Route1NN_CatchingTutorial_Movement_4:
# 1124 "data/maps/Route1NN/scripts.pory"
	walk_right
# 1124 "data/maps/Route1NN/scripts.pory"
	walk_right
# 1124 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1124 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1124 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1124 "data/maps/Route1NN/scripts.pory"
	walk_up
	step_end

# 1128 "data/maps/Route1NN/scripts.pory"
Route1NN_CatchingTutorial_Movement_5:
# 1128 "data/maps/Route1NN/scripts.pory"
	walk_right
# 1128 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1128 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1128 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1128 "data/maps/Route1NN/scripts.pory"
	walk_up
	step_end

# 1132 "data/maps/Route1NN/scripts.pory"
Route1NN_CatchingTutorial_Movement_6:
# 1132 "data/maps/Route1NN/scripts.pory"
	walk_left
# 1132 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1132 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1132 "data/maps/Route1NN/scripts.pory"
	walk_up
# 1132 "data/maps/Route1NN/scripts.pory"
	walk_up
	step_end

YungoosMeowth_Blocking_Text_0:
# 7 "data/maps/Route1NN/scripts.pory"
	.string "We can win this! We can win this!\n"
	.string "Just a bit more!$"

YungoosMeowth_Blocking_Text_1:
# 12 "data/maps/Route1NN/scripts.pory"
	.string "Meowth, use Scratch!$"

PowerOfScience_Text_0:
# 26 "data/maps/Route1NN/scripts.pory"
	.string "The power of science is amazing!\p"
	.string "You can enjoy a festival with people\n"
	.string "from around the world without taking\l"
	.string "a step!\p"
	.string "Every day is a festival when you can\n"
	.string "do that!$"

Route1NN_KukuiGoToIki_Text_0:
# 41 "data/maps/Route1NN/scripts.pory"
	.string "Kukui$"

Route1NN_KukuiGoToIki_Text_1:
# 42 "data/maps/Route1NN/scripts.pory"
	.string "Iki Town is just up ahead, yeah.$"

Route1NN_Trigger_GetStarters_Text_0:
# 148 "data/maps/Route1NN/scripts.pory"
	.string "Yaaahhhh!$"

Route1NN_Trigger_GetStarters_Text_1:
# 185 "data/maps/Route1NN/scripts.pory"
	.string "Hoooo!$"

Route1NN_Trigger_GetStarters_Text_2:
# 197 "data/maps/Route1NN/scripts.pory"
	.string "Mrrr!$"

Route1NN_Trigger_GetStarters_Text_3:
# 203 "data/maps/Route1NN/scripts.pory"
	.string "Mraaarrrr!$"

Route1NN_Trigger_GetStarters_Text_4:
# 209 "data/maps/Route1NN/scripts.pory"
	.string "Prrr!$"

Route1NN_Trigger_GetStarters_Text_5:
# 215 "data/maps/Route1NN/scripts.pory"
	.string "Bwark! Bwark!$"

Route1NN_Trigger_GetStarters_Text_6:
# 220 "data/maps/Route1NN/scripts.pory"
	.string "Ya…yah…$"

Route1NN_Trigger_GetStarters_Text_7:
# 254 "data/maps/Route1NN/scripts.pory"
	.string "Hey there, cousin!$"

Route1NN_Trigger_GetStarters_Text_8:
# 278 "data/maps/Route1NN/scripts.pory"
	.string "Hang on, I know you…\n"
	.string "You're {PLAYER}, right?\p"
	.string "You OK?\p"
	.string "I saw you get attacked like that!$"

Route1NN_Trigger_GetStarters_Text_9:
# 284 "data/maps/Route1NN/scripts.pory"
	.string "Yeah, I got a bit of help$"

Route1NN_Trigger_GetStarters_Text_10:
# 284 "data/maps/Route1NN/scripts.pory"
	.string "I was scared spitless!$"

Route1NN_Trigger_GetStarters_Text_11:
# 290 "data/maps/Route1NN/scripts.pory"
	.string "Looks like you did!\p"
	.string "Though I sure didn't expect that,\n"
	.string "yeah…\p"
	.string "I didn't think these little fellows\n"
	.string "would dash out on their own to help\l"
	.string "save a stranger!$"

Route1NN_Trigger_GetStarters_Text_12:
# 304 "data/maps/Route1NN/scripts.pory"
	.string "You and me both, cousin!\p"
	.string "I'm looking after these Pokémon,\n"
	.string "but they dashed right out on\l"
	.string "their own to save you!$"

Route1NN_Trigger_GetStarters_Text_13:
# 311 "data/maps/Route1NN/scripts.pory"
	.string "But I guess I'm getting ahead of\n"
	.string "myself.\p"
	.string "Welcome to Alola, the Pokémon paradise!$"

Route1NN_Trigger_GetStarters_Text_14:
# 323 "data/maps/Route1NN/scripts.pory"
	.string "That's what I'm supposed to be\n"
	.string "saying.\p"
	.string "I'm Kukui, yeah. the Pokémon\n"
	.string "Professor.\p"
	.string "People and Pokémon live and work\n"
	.string "together here in Alola, too.\p"
	.string "Don't you ever forget…\p"
	.string "You can go anywhere, yeah, as long\n"
	.string "as you got Pokémon in your corner!$"

Route1NN_Trigger_GetStarters_Text_15:
# 342 "data/maps/Route1NN/scripts.pory"
	.string "Wild Pokémon could be lurking in\n"
	.string "the tall grass, yeah, just waiting\l"
	.string "to leap out and bite you, but\l"
	.string "you'll be fine if you've got a\l"
	.string "partner of your own!\p"
	.string "Hey there!\p"
	.string "Here, let me introduce the Pokémon\n"
	.string "that helped you just now.$"

Route1NN_Trigger_GetStarters_Text_16:
# 396 "data/maps/Route1NN/scripts.pory"
	.string "This is the Grass-type Pokémon, Rowlet.$"

Route1NN_Trigger_GetStarters_Text_17:
# 400 "data/maps/Route1NN/scripts.pory"
	.string "Hoo!$"

Route1NN_Trigger_GetStarters_Text_18:
# 420 "data/maps/Route1NN/scripts.pory"
	.string "And the Fire-type Pokémon, Litten.$"

Route1NN_Trigger_GetStarters_Text_19:
# 424 "data/maps/Route1NN/scripts.pory"
	.string "Mrawr.$"

Route1NN_Trigger_GetStarters_Text_20:
# 446 "data/maps/Route1NN/scripts.pory"
	.string "And the Water-type Pokémon Popplio.$"

Route1NN_Trigger_GetStarters_Text_21:
# 450 "data/maps/Route1NN/scripts.pory"
	.string "Bwark?$"

Route1NN_Trigger_GetStartersPart2_Text_0:
# 483 "data/maps/Route1NN/scripts.pory"
	.string "Y'see, the fact of the matter is…\p"
	.string "one of these Pokémon will become\n"
	.string "your first partner, woo!\p"
	.string "Heh…\p"
	.string "Maybe that's why they wanted to save\n"
	.string "you?\p"
	.string "Go on and choose the one you'd like\n"
	.string "to keep as your partner, cousin!$"

Route1NN_Trigger_GetStartersPart2_Text_1:
# 495 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR GREEN}Rowlet$"

Route1NN_Trigger_GetStartersPart2_Text_2:
# 495 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR RED}Litten$"

Route1NN_Trigger_GetStartersPart2_Text_3:
# 495 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR BLUE}Popplio$"

Route1NN_Trigger_GetStartersPart2_Text_4:
# 499 "data/maps/Route1NN/scripts.pory"
	.string "Rowlet can fly up on its enemies real\n"
	.string "quiet like and catch 'em by surprise!\p"
	.string "So, you wanna go with the Grass-type\n"
	.string "Pokémon Rowlet?$"

Route1NN_Trigger_GetStartersPart2_Text_5:
# 542 "data/maps/Route1NN/scripts.pory"
	.string "I know the feeling, cousin…\n"
	.string "I had a real hard time choosing once,\l"
	.string "too.$"

Route1NN_Trigger_GetStartersPart2_Text_6:
# 549 "data/maps/Route1NN/scripts.pory"
	.string "Litten may use Fire-type moves, but\n"
	.string "it's one cool cat!\p"
	.string "So, you wanna go with the Fire-type\n"
	.string "Pokémon Litten?$"

Route1NN_Trigger_GetStartersPart2_Text_7:
# 603 "data/maps/Route1NN/scripts.pory"
	.string "Popplio works hard and makes some\n"
	.string "pretty awesome balloons!\p"
	.string "So, you wanna go with the Water-type\n"
	.string "Pokémon Popplio?$"

Route1NN_Trigger_GetStartersPart2_Text_8:
# 660 "data/maps/Route1NN/scripts.pory"
	.string "Would you like to nickname your\n"
	.string "{STR_VAR_1}?$"

Route1NN_Trigger_GetStartersPart2_Text_9:
# 667 "data/maps/Route1NN/scripts.pory"
	.string "No worries! You can nickname your\n"
	.string "Pokémon anytime from the menu.$"

Route1NN_Trigger_GetStartersPart2_Text_10:
# 684 "data/maps/Route1NN/scripts.pory"
	.string "So you went with {STR_VAR_1}!\n"
	.string "Woo, what a fine-looking team you\l"
	.string "two are!\p"
	.string "Now that you can have Pokémon battles,\n"
	.string "you're what we call a Pokémon Trainer!\p"
	.string "Here's a Poké Ball for {STR_VAR_1},\n"
	.string "too.\p"
	.string "It should feel nice and cozy in there.$"

Route1NN_Trigger_GetStartersPart2_Text_11:
# 697 "data/maps/Route1NN/scripts.pory"
	.string "Received {STR_VAR_1}'s Poké Ball!$"

Route1NN_Trigger_GetStartersPart2_Text_12:
# 700 "data/maps/Route1NN/scripts.pory"
	.string "All right! Then let's get going up\n"
	.string "to Iki Town, {PLAYER}.\p"
	.string "Woo!\p"
	.string "Time to meet the {COLOR RED}Island Kahuna{COLOR DARK_GRAY}!$"

Route1NN_Trigger_GetStartersPart2_Text_13:
# 706 "data/maps/Route1NN/scripts.pory"
	.string "Island Kahuna?!$"

Route1NN_Trigger_GetStartersPart2_Text_14:
# 706 "data/maps/Route1NN/scripts.pory"
	.string "But why?!$"

Route1NN_Trigger_GetStartersPart2_Text_15:
# 711 "data/maps/Route1NN/scripts.pory"
	.string "Truth is, that partner {STR_VAR_1}\n"
	.string "of yours is a gift from the kahuna,\l"
	.string "not me.\p"
	.string "So let's go show it off and say a\n"
	.string "proper thank-you, cousin.\p"
	.string "It may not be the only gift you\n"
	.string "get!\p"
	.string "In case you hadn't heard, the\n"
	.string "kahunas are all crazy-strong\l"
	.string "Pokémon Trainers.\p"
	.string "Be careful about getting into a\n"
	.string "battle with one!$"

Route1NN_Trigger_GetStartersPart2_Text_16:
# 756 "data/maps/Route1NN/scripts.pory"
	.string "Iki Town is right up here!$"

Route1NN_BackOutOfStarter_Text_0:
# 803 "data/maps/Route1NN/scripts.pory"
	.string "Go on and choose the one you'd like\n"
	.string "to keep as your partner, cousin!$"

Route1NN_BackOutOfStarter_Text_1:
# 1010 "data/maps/Route1NN/scripts.pory"
	.string "All right! Then let's get going up\n"
	.string "to Iki Town, {PLAYER}.\p"
	.string "Woo!\p"
	.string "Time to meet the {COLOR RED}Island Kahuna!$"

Route1NN_Rockruff_Text_0:
# 1094 "data/maps/Route1NN/scripts.pory"
	.string "Ruff!$"

Route1NN_CatchingTutorial_Text_0:
# 1112 "data/maps/Route1NN/scripts.pory"
	.string "Yeah, over here!$"

Route1NN_CatchingTutorial_Text_1:
# 1136 "data/maps/Route1NN/scripts.pory"
	.string "So you know that wild Pokémon will\n"
	.string "sometimes jump at you in the tall\l"
	.string "grass, yeah?\p"
	.string "Now that you've got {STR_VAR_1},\n"
	.string "you can not only fight wild Pokémon…\l"
	.string "you can also try to catch 'em. Woo!$"

Route1NN_CatchingTutorial_Text_2:
# 1146 "data/maps/Route1NN/scripts.pory"
	.string "Wild Pokémon do sometimes attack\n"
	.string "people if they get close… \p"
	.string "But catch 'em and they'll join your team\n"
	.string "and be a great help to you, yeah!\p"
	.string "And if your Pokémon get all tuckered\n"
	.string "out, you can always head home and\l"
	.string "rest up a bit, yeah?\p"
	.string "Here're some Poké Balls and Potions\n"
	.string "to get you started out.$"

Route1NN_CatchingTutorial_Text_3:
# 1164 "data/maps/Route1NN/scripts.pory"
	.string "Why don't you have a little adventure\n"
	.string "of your own on the way to Iki Town?\p"
	.string "Take good care of {PLAYER}, \n"
	.string "{STR_VAR_1}!$"

Route1NN_CatchingTutorial_Text_4:
# 1184 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR RED}Overworld Pokémon encounters{COLOR DARK_GRAY} can now\n"
	.string "be enabled!$"
