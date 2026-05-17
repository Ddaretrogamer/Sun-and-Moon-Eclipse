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


Route1NN_Trigger_GetStarters::
# 69 "data/maps/Route1NN/scripts.pory"
	lock
# 70 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO
# 71 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 72 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 73 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 74 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 75 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 76 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 77 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 78 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 79 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 80 "data/maps/Route1NN/scripts.pory"
	playse SE_M_SCRATCH
# 81 "data/maps/Route1NN/scripts.pory"
	waitse
# 82 "data/maps/Route1NN/scripts.pory"
	addobject rt1_yungoos
# 83 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 84 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_0
# 85 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 86 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_1
# 87 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 88 "data/maps/Route1NN/scripts.pory"
	delay 30
# 89 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_YUNGOOS, 0
# 90 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_0, MSGBOX_AUTOCLOSE
# 91 "data/maps/Route1NN/scripts.pory"
	waitmessage
# 92 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_2
# 93 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 94 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 95 "data/maps/Route1NN/scripts.pory"
	addobject kukuistarters
# 96 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_3
# 97 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_2
# 102 "data/maps/Route1NN/scripts.pory"
	addobject rowlet
# 103 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_4
Route1NN_Trigger_GetStarters_1:
# 105 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_6
# 110 "data/maps/Route1NN/scripts.pory"
	addobject litten
# 111 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_5
Route1NN_Trigger_GetStarters_5:
# 113 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_10
# 118 "data/maps/Route1NN/scripts.pory"
	addobject popplio
# 119 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_6
Route1NN_Trigger_GetStarters_9:
# 121 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 122 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 123 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_14
# 130 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 131 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_7
# 132 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet
# 133 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_1, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_13:
# 135 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_18
# 142 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 143 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_7
# 144 "data/maps/Route1NN/scripts.pory"
	waitmovement litten
# 145 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_3, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_17:
# 147 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_22
# 154 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 155 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_7
# 156 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio
# 157 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_5, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_21:
# 159 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_YUNGOOS, 0
# 160 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_8
# 161 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 162 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_6, MSGBOX_AUTOCLOSE
# 163 "data/maps/Route1NN/scripts.pory"
	playse SE_FLEE
# 164 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_9
# 165 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 166 "data/maps/Route1NN/scripts.pory"
	delay 60
# 167 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_26
# 171 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_25:
# 173 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_30
# 177 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_29:
# 179 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_34
# 183 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_33:
# 185 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 186 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 187 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_11
# 188 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 189 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 190 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_12
# 191 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 192 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 193 "data/maps/Route1NN/scripts.pory"
	delay 60
# 194 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_13
# 195 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 196 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_7, MSGBOX_AUTOCLOSE
# 197 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_14
# 198 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_14
# 199 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 200 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_38
# 204 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_14
Route1NN_Trigger_GetStarters_37:
# 206 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_42
# 210 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_14
Route1NN_Trigger_GetStarters_41:
# 212 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_46
# 216 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_14
Route1NN_Trigger_GetStarters_45:
# 218 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 219 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 220 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_8
# 226 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 11, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_9, Route1NN_Trigger_GetStarters_Text_10
# 227 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Route1NN_Trigger_GetStarters_50
# 243 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 244 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 245 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 246 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_12
Route1NN_Trigger_GetStarters_49:
# 252 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 253 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_13
# 258 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_16
# 259 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 260 "data/maps/Route1NN/scripts.pory"
	waitse
# 261 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 262 "data/maps/Route1NN/scripts.pory"
	waitse
# 263 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 265 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_14
# 278 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_16
# 279 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 280 "data/maps/Route1NN/scripts.pory"
	waitse
# 281 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 282 "data/maps/Route1NN/scripts.pory"
	waitse
# 283 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 284 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_15, MSGBOX_AUTOCLOSE
# 294 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 295 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_TEMP_2
# 296 "data/maps/Route1NN/scripts.pory"
	removeobject techguy
# 297 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_17
# 298 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 299 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_18
# 300 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 301 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_19
# 302 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_20
# 303 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 304 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet
# 305 "data/maps/Route1NN/scripts.pory"
	removeobject litten
# 306 "data/maps/Route1NN/scripts.pory"
	removeobject popplio
# 307 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny
# 308 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny
# 309 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny
# 310 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_54
# 315 "data/maps/Route1NN/scripts.pory"
	addobject rowlet2
# 316 "data/maps/Route1NN/scripts.pory"
	setobjectxy rowlet2, 26, 16
Route1NN_Trigger_GetStarters_53:
# 318 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_58
# 323 "data/maps/Route1NN/scripts.pory"
	addobject litten2
# 324 "data/maps/Route1NN/scripts.pory"
	setobjectxy litten2, 27, 16
Route1NN_Trigger_GetStarters_57:
# 326 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_62
# 331 "data/maps/Route1NN/scripts.pory"
	addobject popplio2
# 332 "data/maps/Route1NN/scripts.pory"
	setobjectxy popplio2, 28, 16
Route1NN_Trigger_GetStarters_61:
# 334 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 335 "data/maps/Route1NN/scripts.pory"
	delay 60
# 336 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_21
# 337 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 338 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_16
# 339 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_66
# 349 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 350 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 351 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_17
# 352 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 353 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_22
# 354 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 355 "data/maps/Route1NN/scripts.pory"
	delay 30
Route1NN_Trigger_GetStarters_65:
# 357 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 358 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_2
# 359 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 360 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_18
# 361 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_70
# 372 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 373 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 374 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_19
# 375 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 376 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 377 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_23
# 378 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 379 "data/maps/Route1NN/scripts.pory"
	delay 30
Route1NN_Trigger_GetStarters_69:
# 381 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 382 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_2
# 383 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 384 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_20
# 385 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_74
# 399 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 400 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 401 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_21
# 402 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 403 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_24
# 404 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 405 "data/maps/Route1NN/scripts.pory"
	waitse
# 406 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 407 "data/maps/Route1NN/scripts.pory"
	waitse
# 408 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 409 "data/maps/Route1NN/scripts.pory"
	delay 30
Route1NN_Trigger_GetStarters_73:
# 411 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 412 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_25
# 413 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 414 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_22
# 426 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_23, Route1NN_Trigger_GetStarters_Text_24, Route1NN_Trigger_GetStarters_Text_25
# 427 "data/maps/Route1NN/scripts.pory"
	switch VAR_RESULT
# 428 "data/maps/Route1NN/scripts.pory"
	case 0, Route1NN_Trigger_GetStarters_79
# 482 "data/maps/Route1NN/scripts.pory"
	case 1, Route1NN_Trigger_GetStarters_80
# 540 "data/maps/Route1NN/scripts.pory"
	case 2, Route1NN_Trigger_GetStarters_81
Route1NN_Trigger_GetStarters_77:
# 599 "data/maps/Route1NN/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 600 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_31
# 601 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_10
# 602 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 603 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_30, MSGBOX_YESNO
# 605 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route1NN_Trigger_GetStarters_83
# 610 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_31, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_82:
# 613 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 614 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 615 "data/maps/Route1NN/scripts.pory"
	delay 60
# 616 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 617 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 618 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
# 619 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 620 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
# 621 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 622 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
# 623 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 624 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 625 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 626 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_32
# 637 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 638 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 639 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_33, MSGBOX_AUTOCLOSE
# 640 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 641 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 642 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_34
# 648 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_35, Route1NN_Trigger_GetStarters_Text_36
# 649 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Route1NN_Trigger_GetStarters_96
# 672 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 673 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 674 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_37, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_95:
# 691 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_32
# 692 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_33
# 693 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_33
# 694 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 695 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_HIDE_KUKUI_STARTERS
# 696 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_34
# 697 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 698 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_38, MSGBOX_AUTOCLOSE
# 699 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_31
# 700 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 701 "data/maps/Route1NN/scripts.pory"
	delay 30
# 702 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_35
# 703 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 704 "data/maps/Route1NN/scripts.pory"
	delay 90
# 705 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 706 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_36
# 707 "data/maps/Route1NN/scripts.pory"
	setobjectxy kukuistarters, 21, 19
# 708 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 709 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 710 "data/maps/Route1NN/scripts.pory"
	addobject techguy
# 711 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_TEMP_2
# 712 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTERS_STATE, 1
# 713 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 714 "data/maps/Route1NN/scripts.pory"
	release
	end

Route1NN_Trigger_GetStarters_2:
# 98 "data/maps/Route1NN/scripts.pory"
	addobject rowletshiny
# 99 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_4
	goto Route1NN_Trigger_GetStarters_1

Route1NN_Trigger_GetStarters_6:
# 106 "data/maps/Route1NN/scripts.pory"
	addobject littenshiny
# 107 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_5
	goto Route1NN_Trigger_GetStarters_5

Route1NN_Trigger_GetStarters_10:
# 114 "data/maps/Route1NN/scripts.pory"
	addobject popplioshiny
# 115 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_6
	goto Route1NN_Trigger_GetStarters_9

Route1NN_Trigger_GetStarters_14:
# 124 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 125 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_7
# 126 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny
# 127 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_1, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_13

Route1NN_Trigger_GetStarters_18:
# 136 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 137 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_7
# 138 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny
# 139 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_2, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_17

Route1NN_Trigger_GetStarters_22:
# 148 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 149 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_7
# 150 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny
# 151 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_4, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_21

Route1NN_Trigger_GetStarters_26:
# 168 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_25

Route1NN_Trigger_GetStarters_30:
# 174 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_29

Route1NN_Trigger_GetStarters_34:
# 180 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_33

Route1NN_Trigger_GetStarters_38:
# 201 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_14
	goto Route1NN_Trigger_GetStarters_37

Route1NN_Trigger_GetStarters_42:
# 207 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_14
	goto Route1NN_Trigger_GetStarters_41

Route1NN_Trigger_GetStarters_46:
# 213 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_14
	goto Route1NN_Trigger_GetStarters_45

Route1NN_Trigger_GetStarters_50:
# 229 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 230 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 231 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 232 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_11
	goto Route1NN_Trigger_GetStarters_49

Route1NN_Trigger_GetStarters_54:
# 311 "data/maps/Route1NN/scripts.pory"
	addobject rowletshiny2
# 312 "data/maps/Route1NN/scripts.pory"
	setobjectxy rowletshiny2, 26, 16
	goto Route1NN_Trigger_GetStarters_53

Route1NN_Trigger_GetStarters_58:
# 319 "data/maps/Route1NN/scripts.pory"
	addobject littenshiny2
# 320 "data/maps/Route1NN/scripts.pory"
	setobjectxy littenshiny2, 27, 16
	goto Route1NN_Trigger_GetStarters_57

Route1NN_Trigger_GetStarters_62:
# 327 "data/maps/Route1NN/scripts.pory"
	addobject popplioshiny2
# 328 "data/maps/Route1NN/scripts.pory"
	setobjectxy popplioshiny2, 28, 16
	goto Route1NN_Trigger_GetStarters_61

Route1NN_Trigger_GetStarters_66:
# 340 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 341 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 342 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_17
# 343 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 344 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_22
# 345 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 346 "data/maps/Route1NN/scripts.pory"
	delay 30
	goto Route1NN_Trigger_GetStarters_65

Route1NN_Trigger_GetStarters_70:
# 362 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 363 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 364 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_19
# 365 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 366 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 367 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_23
# 368 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 369 "data/maps/Route1NN/scripts.pory"
	delay 30
	goto Route1NN_Trigger_GetStarters_69

Route1NN_Trigger_GetStarters_74:
# 386 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 387 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 388 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_21
# 389 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 390 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_24
# 391 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 392 "data/maps/Route1NN/scripts.pory"
	waitse
# 393 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 394 "data/maps/Route1NN/scripts.pory"
	waitse
# 395 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 396 "data/maps/Route1NN/scripts.pory"
	delay 30
	goto Route1NN_Trigger_GetStarters_73

Route1NN_Trigger_GetStarters_79:
# 429 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 430 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_26, MSGBOX_YESNO
# 435 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_Trigger_GetStarters_86
# 476 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 477 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_27
# 480 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_80:
# 483 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 484 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_28, MSGBOX_YESNO
# 489 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_Trigger_GetStarters_89
# 534 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 535 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_27
# 538 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_81:
# 541 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 542 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_29, MSGBOX_YESNO
# 547 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_Trigger_GetStarters_92
# 592 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 593 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_27
# 596 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_83:
# 606 "data/maps/Route1NN/scripts.pory"
	setvar VAR_0x8004, 0
# 607 "data/maps/Route1NN/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto Route1NN_Trigger_GetStarters_82

Route1NN_Trigger_GetStarters_86:
# 436 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_100
Route1NN_Trigger_GetStarters_99:
# 439 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_109
Route1NN_Trigger_GetStarters_108:
# 442 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_118
# 456 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
# 457 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_26
# 458 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 459 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 460 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_27
# 461 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 462 "data/maps/Route1NN/scripts.pory"
	delay 30
# 463 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 464 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_28
# 465 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 466 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStarters_117:
# 468 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 469 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 470 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 471 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
# 472 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_89:
# 490 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_103
Route1NN_Trigger_GetStarters_102:
# 493 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_112
Route1NN_Trigger_GetStarters_111:
# 496 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_122
# 512 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
# 513 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_29
# 514 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 515 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 516 "data/maps/Route1NN/scripts.pory"
	waitse
# 517 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 518 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_23
# 519 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 520 "data/maps/Route1NN/scripts.pory"
	delay 30
# 521 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 522 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_28
# 523 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 524 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStarters_121:
# 526 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 527 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 528 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 529 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
# 530 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_92:
# 548 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_106
Route1NN_Trigger_GetStarters_105:
# 551 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_115
Route1NN_Trigger_GetStarters_114:
# 554 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_126
# 570 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
# 571 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_30
# 572 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 573 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 574 "data/maps/Route1NN/scripts.pory"
	waitse
# 575 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 576 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_23
# 577 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 578 "data/maps/Route1NN/scripts.pory"
	delay 30
# 579 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 580 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_28
# 581 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 582 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStarters_125:
# 584 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 585 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 586 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 587 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
# 588 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_96:
# 651 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 652 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 653 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_37, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_95

Route1NN_Trigger_GetStarters_100:
# 437 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_Trigger_GetStarters_99

Route1NN_Trigger_GetStarters_103:
# 491 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_Trigger_GetStarters_102

Route1NN_Trigger_GetStarters_106:
# 549 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_Trigger_GetStarters_105

Route1NN_Trigger_GetStarters_109:
# 440 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_Trigger_GetStarters_108

Route1NN_Trigger_GetStarters_112:
# 494 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_Trigger_GetStarters_111

Route1NN_Trigger_GetStarters_115:
# 552 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_Trigger_GetStarters_114

Route1NN_Trigger_GetStarters_118:
# 443 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_ALWAYS
# 444 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_26
# 445 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 446 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 447 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_27
# 448 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 449 "data/maps/Route1NN/scripts.pory"
	delay 30
# 450 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 451 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 452 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 453 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_117

Route1NN_Trigger_GetStarters_122:
# 497 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_ALWAYS
# 498 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_29
# 499 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 500 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 501 "data/maps/Route1NN/scripts.pory"
	waitse
# 502 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 503 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_23
# 504 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 505 "data/maps/Route1NN/scripts.pory"
	delay 30
# 506 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 507 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 508 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 509 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_121

Route1NN_Trigger_GetStarters_126:
# 555 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_ALWAYS
# 556 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_30
# 557 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 558 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 559 "data/maps/Route1NN/scripts.pory"
	waitse
# 560 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 561 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_23
# 562 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 563 "data/maps/Route1NN/scripts.pory"
	delay 30
# 564 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 565 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 566 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 567 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_125


Route1NN_BackOutOfStarter::
# 719 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 720 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_BackOutOfStarter_Text_0
# 722 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_23, Route1NN_Trigger_GetStarters_Text_24, Route1NN_Trigger_GetStarters_Text_25
# 723 "data/maps/Route1NN/scripts.pory"
	switch VAR_RESULT
# 724 "data/maps/Route1NN/scripts.pory"
	case 0, Route1NN_BackOutOfStarter_3
# 778 "data/maps/Route1NN/scripts.pory"
	case 1, Route1NN_BackOutOfStarter_4
# 836 "data/maps/Route1NN/scripts.pory"
	case 2, Route1NN_BackOutOfStarter_5
Route1NN_BackOutOfStarter_1:
# 895 "data/maps/Route1NN/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 896 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_31
# 897 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_10
# 898 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 899 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_30, MSGBOX_YESNO
# 901 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route1NN_BackOutOfStarter_7
# 906 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_31, MSGBOX_AUTOCLOSE
Route1NN_BackOutOfStarter_6:
# 909 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 910 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 911 "data/maps/Route1NN/scripts.pory"
	delay 60
# 912 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 913 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 914 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
# 915 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 916 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
# 917 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 918 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
# 919 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 920 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 921 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 922 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_32
# 933 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 934 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 935 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_33, MSGBOX_AUTOCLOSE
# 936 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 937 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 938 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_BackOutOfStarter_Text_1
# 944 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_35, Route1NN_Trigger_GetStarters_Text_36
# 945 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Route1NN_BackOutOfStarter_20
# 968 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 969 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 970 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_37, MSGBOX_AUTOCLOSE
Route1NN_BackOutOfStarter_19:
# 987 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_32
# 988 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_33
# 989 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_33
# 990 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 991 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_HIDE_KUKUI_STARTERS
# 992 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_34
# 993 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 994 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_38, MSGBOX_AUTOCLOSE
# 995 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_31
# 996 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 997 "data/maps/Route1NN/scripts.pory"
	delay 30
# 998 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_35
# 999 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 1000 "data/maps/Route1NN/scripts.pory"
	delay 90
# 1001 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1002 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_36
# 1003 "data/maps/Route1NN/scripts.pory"
	setobjectxy kukuistarters, 21, 19
# 1004 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 1005 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 1006 "data/maps/Route1NN/scripts.pory"
	addobject techguy
# 1007 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_TEMP_2
# 1008 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTERS_STATE, 1
# 1009 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1010 "data/maps/Route1NN/scripts.pory"
	release
	end

Route1NN_BackOutOfStarter_3:
# 725 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 726 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_26, MSGBOX_YESNO
# 731 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_BackOutOfStarter_10
# 772 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 773 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_27
# 776 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_4:
# 779 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 780 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_28, MSGBOX_YESNO
# 785 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_BackOutOfStarter_13
# 830 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 831 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_27
# 834 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_5:
# 837 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 838 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_29, MSGBOX_YESNO
# 843 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route1NN_BackOutOfStarter_16
# 888 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 889 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_27
# 892 "data/maps/Route1NN/scripts.pory"
	call Route1NN_BackOutOfStarter
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_7:
# 902 "data/maps/Route1NN/scripts.pory"
	setvar VAR_0x8004, 0
# 903 "data/maps/Route1NN/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto Route1NN_BackOutOfStarter_6

Route1NN_BackOutOfStarter_10:
# 732 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_24
Route1NN_BackOutOfStarter_23:
# 735 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_33
Route1NN_BackOutOfStarter_32:
# 738 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_42
# 752 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
# 753 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_26
# 754 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 755 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 756 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_27
# 757 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 758 "data/maps/Route1NN/scripts.pory"
	delay 30
# 759 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 760 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_28
# 761 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 762 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_BackOutOfStarter_41:
# 764 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 765 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 766 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 767 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
# 768 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_13:
# 786 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_27
Route1NN_BackOutOfStarter_26:
# 789 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_36
Route1NN_BackOutOfStarter_35:
# 792 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_46
# 808 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
# 809 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_29
# 810 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 811 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 812 "data/maps/Route1NN/scripts.pory"
	waitse
# 813 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 814 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_23
# 815 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 816 "data/maps/Route1NN/scripts.pory"
	delay 30
# 817 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 818 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_28
# 819 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 820 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_BackOutOfStarter_45:
# 822 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 823 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 824 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 825 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
# 826 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_16:
# 844 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_30
Route1NN_BackOutOfStarter_29:
# 847 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_39
Route1NN_BackOutOfStarter_38:
# 850 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_BackOutOfStarter_50
# 866 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
# 867 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_30
# 868 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 869 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 870 "data/maps/Route1NN/scripts.pory"
	waitse
# 871 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 872 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_23
# 873 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 874 "data/maps/Route1NN/scripts.pory"
	delay 30
# 875 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 876 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_28
# 877 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 878 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_BackOutOfStarter_49:
# 880 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 881 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 882 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 883 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
# 884 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_BackOutOfStarter_1

Route1NN_BackOutOfStarter_20:
# 947 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 948 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 949 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_37, MSGBOX_AUTOCLOSE
	goto Route1NN_BackOutOfStarter_19

Route1NN_BackOutOfStarter_24:
# 733 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_BackOutOfStarter_23

Route1NN_BackOutOfStarter_27:
# 787 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_BackOutOfStarter_26

Route1NN_BackOutOfStarter_30:
# 845 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_BackOutOfStarter_29

Route1NN_BackOutOfStarter_33:
# 736 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_BackOutOfStarter_32

Route1NN_BackOutOfStarter_36:
# 790 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_BackOutOfStarter_35

Route1NN_BackOutOfStarter_39:
# 848 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_BackOutOfStarter_38

Route1NN_BackOutOfStarter_42:
# 739 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_ALWAYS
# 740 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_26
# 741 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 742 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 743 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_27
# 744 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 745 "data/maps/Route1NN/scripts.pory"
	delay 30
# 746 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 747 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 748 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 749 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_BackOutOfStarter_41

Route1NN_BackOutOfStarter_46:
# 793 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_ALWAYS
# 794 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_29
# 795 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 796 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 797 "data/maps/Route1NN/scripts.pory"
	waitse
# 798 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 799 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_23
# 800 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 801 "data/maps/Route1NN/scripts.pory"
	delay 30
# 802 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 803 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 804 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 805 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_BackOutOfStarter_45

Route1NN_BackOutOfStarter_50:
# 851 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_ALWAYS
# 852 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_30
# 853 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 854 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 855 "data/maps/Route1NN/scripts.pory"
	waitse
# 856 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 857 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_23
# 858 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 859 "data/maps/Route1NN/scripts.pory"
	delay 30
# 860 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 861 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 862 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 863 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_BackOutOfStarter_49


Route1NN_Rockruff::
# 1015 "data/maps/Route1NN/scripts.pory"
	lock
# 1016 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 1017 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 1018 "data/maps/Route1NN/scripts.pory"
	applymovement route1nnrockruff, Route1NN_Rockruff_Movement_0
# 1019 "data/maps/Route1NN/scripts.pory"
	waitmovement route1nnrockruff
# 1020 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Rockruff_Text_0, MSGBOX_AUTOCLOSE
# 1021 "data/maps/Route1NN/scripts.pory"
	release
	end


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
Route1NN_Trigger_GetStarters_Movement_0:
# 84 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
	step_end

# 86 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_1:
# 86 "data/maps/Route1NN/scripts.pory"
	walk_right
# 86 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 92 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_2:
# 92 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 96 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_3:
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 96 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
	step_end

# 99 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_4:
# 99 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 99 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 99 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 99 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 99 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 99 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 99 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 99 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 99 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 107 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_5:
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 107 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 115 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_6:
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 115 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 125 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_7:
# 125 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
# 125 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
# 125 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
	step_end

# 160 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_8:
# 160 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
# 160 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
# 160 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
	step_end

# 164 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_9:
# 164 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 164 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 164 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 164 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 164 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 164 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 164 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
	step_end

# 168 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_10:
# 168 "data/maps/Route1NN/scripts.pory"
	face_right
	step_end

# 187 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_11:
# 187 "data/maps/Route1NN/scripts.pory"
	walk_up
# 187 "data/maps/Route1NN/scripts.pory"
	walk_up
# 187 "data/maps/Route1NN/scripts.pory"
	walk_up
# 187 "data/maps/Route1NN/scripts.pory"
	walk_up
# 187 "data/maps/Route1NN/scripts.pory"
	walk_up
# 187 "data/maps/Route1NN/scripts.pory"
	walk_up
# 187 "data/maps/Route1NN/scripts.pory"
	face_left
# 187 "data/maps/Route1NN/scripts.pory"
	delay_16
	step_end

# 190 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_12:
# 190 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
# 190 "data/maps/Route1NN/scripts.pory"
	face_right
	step_end

# 194 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_13:
# 194 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
# 194 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
	step_end

# 197 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_14:
# 197 "data/maps/Route1NN/scripts.pory"
	walk_right
# 197 "data/maps/Route1NN/scripts.pory"
	walk_right
# 197 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 229 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_15:
# 229 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
# 229 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
	step_end

# 258 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_16:
# 258 "data/maps/Route1NN/scripts.pory"
	jump_in_place_left
# 258 "data/maps/Route1NN/scripts.pory"
	jump_in_place_left
	step_end

# 297 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_17:
# 297 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 297 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 297 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 297 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 297 "data/maps/Route1NN/scripts.pory"
	face_up
	step_end

# 299 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_18:
# 299 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 299 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 299 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 299 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
	step_end

# 301 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_19:
# 301 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 301 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 301 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
	step_end

# 302 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_20:
# 302 "data/maps/Route1NN/scripts.pory"
	face_up
	step_end

# 336 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_21:
# 336 "data/maps/Route1NN/scripts.pory"
	walk_slow_up
# 336 "data/maps/Route1NN/scripts.pory"
	walk_slow_diag_northwest
	step_end

# 344 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_22:
# 344 "data/maps/Route1NN/scripts.pory"
	face_left
# 344 "data/maps/Route1NN/scripts.pory"
	delay_16
# 344 "data/maps/Route1NN/scripts.pory"
	face_up
# 344 "data/maps/Route1NN/scripts.pory"
	delay_16
# 344 "data/maps/Route1NN/scripts.pory"
	face_right
# 344 "data/maps/Route1NN/scripts.pory"
	delay_16
# 344 "data/maps/Route1NN/scripts.pory"
	face_down
# 344 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 344 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
	step_end

# 367 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_23:
# 367 "data/maps/Route1NN/scripts.pory"
	jump_in_place_down
	step_end

# 390 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_24:
# 390 "data/maps/Route1NN/scripts.pory"
	face_up
# 390 "data/maps/Route1NN/scripts.pory"
	delay_16
# 390 "data/maps/Route1NN/scripts.pory"
	walk_in_place_up
# 390 "data/maps/Route1NN/scripts.pory"
	walk_in_place_up
# 390 "data/maps/Route1NN/scripts.pory"
	delay_16
# 390 "data/maps/Route1NN/scripts.pory"
	delay_16
# 390 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 412 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_25:
# 412 "data/maps/Route1NN/scripts.pory"
	walk_slow_diag_southwest
# 412 "data/maps/Route1NN/scripts.pory"
	walk_slow_down
	step_end

# 444 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_26:
# 444 "data/maps/Route1NN/scripts.pory"
	walk_down
# 444 "data/maps/Route1NN/scripts.pory"
	walk_right
# 444 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 447 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_27:
# 447 "data/maps/Route1NN/scripts.pory"
	face_left
# 447 "data/maps/Route1NN/scripts.pory"
	delay_16
# 447 "data/maps/Route1NN/scripts.pory"
	face_up
# 447 "data/maps/Route1NN/scripts.pory"
	delay_16
# 447 "data/maps/Route1NN/scripts.pory"
	face_right
# 447 "data/maps/Route1NN/scripts.pory"
	delay_16
# 447 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 451 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_28:
# 451 "data/maps/Route1NN/scripts.pory"
	emote_heart
	step_end

# 498 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_29:
# 498 "data/maps/Route1NN/scripts.pory"
	walk_down
	step_end

# 556 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_30:
# 556 "data/maps/Route1NN/scripts.pory"
	walk_down
# 556 "data/maps/Route1NN/scripts.pory"
	walk_left
# 556 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 600 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_31:
# 600 "data/maps/Route1NN/scripts.pory"
	face_left
	step_end

# 691 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_32:
# 691 "data/maps/Route1NN/scripts.pory"
	walk_down
# 691 "data/maps/Route1NN/scripts.pory"
	walk_left
# 691 "data/maps/Route1NN/scripts.pory"
	walk_left
# 691 "data/maps/Route1NN/scripts.pory"
	walk_left
# 691 "data/maps/Route1NN/scripts.pory"
	walk_left
# 691 "data/maps/Route1NN/scripts.pory"
	walk_left
# 691 "data/maps/Route1NN/scripts.pory"
	walk_left
# 691 "data/maps/Route1NN/scripts.pory"
	walk_left
	step_end

# 692 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_33:
# 692 "data/maps/Route1NN/scripts.pory"
	delay_16
# 692 "data/maps/Route1NN/scripts.pory"
	delay_16
# 692 "data/maps/Route1NN/scripts.pory"
	delay_16
# 692 "data/maps/Route1NN/scripts.pory"
	delay_16
# 692 "data/maps/Route1NN/scripts.pory"
	walk_down
# 692 "data/maps/Route1NN/scripts.pory"
	walk_down
# 692 "data/maps/Route1NN/scripts.pory"
	walk_left
# 692 "data/maps/Route1NN/scripts.pory"
	walk_left
# 692 "data/maps/Route1NN/scripts.pory"
	walk_left
# 692 "data/maps/Route1NN/scripts.pory"
	walk_left
# 692 "data/maps/Route1NN/scripts.pory"
	walk_left
# 692 "data/maps/Route1NN/scripts.pory"
	walk_left
	step_end

# 696 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_34:
# 696 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 702 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_35:
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 702 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
# 702 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
# 702 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
	step_end

# 706 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_36:
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 706 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
	step_end

# 1018 "data/maps/Route1NN/scripts.pory"
Route1NN_Rockruff_Movement_0:
# 1018 "data/maps/Route1NN/scripts.pory"
	face_player
# 1018 "data/maps/Route1NN/scripts.pory"
	emote_heart
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
# 90 "data/maps/Route1NN/scripts.pory"
	.string "Yaaahhhh!$"

Route1NN_Trigger_GetStarters_Text_1:
# 127 "data/maps/Route1NN/scripts.pory"
	.string "Hoooo!$"

Route1NN_Trigger_GetStarters_Text_2:
# 139 "data/maps/Route1NN/scripts.pory"
	.string "Mrrr!$"

Route1NN_Trigger_GetStarters_Text_3:
# 145 "data/maps/Route1NN/scripts.pory"
	.string "Mraaarrrr!$"

Route1NN_Trigger_GetStarters_Text_4:
# 151 "data/maps/Route1NN/scripts.pory"
	.string "Prrr!$"

Route1NN_Trigger_GetStarters_Text_5:
# 157 "data/maps/Route1NN/scripts.pory"
	.string "Bwark! Bwark!$"

Route1NN_Trigger_GetStarters_Text_6:
# 162 "data/maps/Route1NN/scripts.pory"
	.string "Ya…yah…$"

Route1NN_Trigger_GetStarters_Text_7:
# 196 "data/maps/Route1NN/scripts.pory"
	.string "Hey there, cousin!$"

Route1NN_Trigger_GetStarters_Text_8:
# 220 "data/maps/Route1NN/scripts.pory"
	.string "Hang on, I know you…\n"
	.string "You're {PLAYER}, right?\p"
	.string "You OK?\p"
	.string "I saw you get attacked like that!$"

Route1NN_Trigger_GetStarters_Text_9:
# 226 "data/maps/Route1NN/scripts.pory"
	.string "Yeah, I got a bit of help$"

Route1NN_Trigger_GetStarters_Text_10:
# 226 "data/maps/Route1NN/scripts.pory"
	.string "I was scared spitless!$"

Route1NN_Trigger_GetStarters_Text_11:
# 232 "data/maps/Route1NN/scripts.pory"
	.string "Looks like you did!\p"
	.string "Though I sure didn't expect that,\n"
	.string "yeah…\p"
	.string "I didn't think these little fellows\n"
	.string "would dash out on their own to help\l"
	.string "save a stranger!$"

Route1NN_Trigger_GetStarters_Text_12:
# 246 "data/maps/Route1NN/scripts.pory"
	.string "You and me both, cousin!\p"
	.string "I'm looking after these Pokémon,\n"
	.string "but they dashed right out on\l"
	.string "their own to save you!$"

Route1NN_Trigger_GetStarters_Text_13:
# 253 "data/maps/Route1NN/scripts.pory"
	.string "But I guess I'm getting ahead of\n"
	.string "myself.\p"
	.string "Welcome to Alola, the Pokémon paradise!$"

Route1NN_Trigger_GetStarters_Text_14:
# 265 "data/maps/Route1NN/scripts.pory"
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
# 284 "data/maps/Route1NN/scripts.pory"
	.string "Wild Pokémon could be lurking in\n"
	.string "the tall grass, yeah, just waiting\l"
	.string "to leap out and bite you, but\l"
	.string "you'll be fine if you've got a\l"
	.string "partner of your own!\p"
	.string "Hey there!\p"
	.string "Here, let me introduce the Pokémon\n"
	.string "that helped you just now.$"

Route1NN_Trigger_GetStarters_Text_16:
# 338 "data/maps/Route1NN/scripts.pory"
	.string "This is the Grass-type Pokémon, Rowlet.$"

Route1NN_Trigger_GetStarters_Text_17:
# 342 "data/maps/Route1NN/scripts.pory"
	.string "Hoo!$"

Route1NN_Trigger_GetStarters_Text_18:
# 360 "data/maps/Route1NN/scripts.pory"
	.string "And the Fire-type Pokémon, Litten.$"

Route1NN_Trigger_GetStarters_Text_19:
# 364 "data/maps/Route1NN/scripts.pory"
	.string "Mrawr.$"

Route1NN_Trigger_GetStarters_Text_20:
# 384 "data/maps/Route1NN/scripts.pory"
	.string "And the Water-type Pokémon Popplio.$"

Route1NN_Trigger_GetStarters_Text_21:
# 388 "data/maps/Route1NN/scripts.pory"
	.string "Bwark?$"

Route1NN_Trigger_GetStarters_Text_22:
# 414 "data/maps/Route1NN/scripts.pory"
	.string "Y'see, the fact of the matter is…\p"
	.string "one of these Pokémon will become\n"
	.string "your first partner, woo!\p"
	.string "Heh…\p"
	.string "Maybe that's why they wanted to save\n"
	.string "you?\p"
	.string "Go on and choose the one you'd like\n"
	.string "to keep as your partner, cousin!$"

Route1NN_Trigger_GetStarters_Text_23:
# 426 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR GREEN}Rowlet$"

Route1NN_Trigger_GetStarters_Text_24:
# 426 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR RED}Litten$"

Route1NN_Trigger_GetStarters_Text_25:
# 426 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR BLUE}Popplio$"

Route1NN_Trigger_GetStarters_Text_26:
# 430 "data/maps/Route1NN/scripts.pory"
	.string "Rowlet can fly up on its enemies real\n"
	.string "quiet like and catch 'em by surprise!\p"
	.string "So, you wanna go with the Grass-type\n"
	.string "Pokémon Rowlet?$"

Route1NN_Trigger_GetStarters_Text_27:
# 477 "data/maps/Route1NN/scripts.pory"
	.string "I know the feeling, cousin…\n"
	.string "I had a real hard time choosing once,\l"
	.string "too.$"

Route1NN_Trigger_GetStarters_Text_28:
# 484 "data/maps/Route1NN/scripts.pory"
	.string "Litten may use Fire-type moves, but\n"
	.string "it's one cool cat!\p"
	.string "So, you wanna go with the Fire-type\n"
	.string "Pokémon Litten?$"

Route1NN_Trigger_GetStarters_Text_29:
# 542 "data/maps/Route1NN/scripts.pory"
	.string "Popplio works hard and makes some\n"
	.string "pretty awesome balloons!\p"
	.string "So, you wanna go with the Water-type\n"
	.string "Pokémon Popplio?$"

Route1NN_Trigger_GetStarters_Text_30:
# 603 "data/maps/Route1NN/scripts.pory"
	.string "Would you like to nickname your\n"
	.string "{STR_VAR_1}?$"

Route1NN_Trigger_GetStarters_Text_31:
# 610 "data/maps/Route1NN/scripts.pory"
	.string "No worries! You can nickname your\n"
	.string "Pokémon anytime from the menu.$"

Route1NN_Trigger_GetStarters_Text_32:
# 626 "data/maps/Route1NN/scripts.pory"
	.string "So you went with {STR_VAR_1}!\n"
	.string "Woo, what a fine-looking team you\l"
	.string "two are!\p"
	.string "Now that you can have Pokémon battles,\n"
	.string "you're what we call a Pokémon Trainer!\p"
	.string "Here's a Poké Ball for {STR_VAR_1},\n"
	.string "too.\p"
	.string "It should feel nice and cozy in there.$"

Route1NN_Trigger_GetStarters_Text_33:
# 639 "data/maps/Route1NN/scripts.pory"
	.string "Received {STR_VAR_1}'s Poké Ball!$"

Route1NN_Trigger_GetStarters_Text_34:
# 642 "data/maps/Route1NN/scripts.pory"
	.string "All right! Then let's get going up\n"
	.string "to Iki Town, {PLAYER}.\p"
	.string "Woo!\p"
	.string "Time to meet the {COLOR RED}Island Kahuna{COLOR DARK_GRAY}!$"

Route1NN_Trigger_GetStarters_Text_35:
# 648 "data/maps/Route1NN/scripts.pory"
	.string "Island Kahuna?!$"

Route1NN_Trigger_GetStarters_Text_36:
# 648 "data/maps/Route1NN/scripts.pory"
	.string "But why?!$"

Route1NN_Trigger_GetStarters_Text_37:
# 653 "data/maps/Route1NN/scripts.pory"
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

Route1NN_Trigger_GetStarters_Text_38:
# 698 "data/maps/Route1NN/scripts.pory"
	.string "Iki Town is right up here!$"

Route1NN_BackOutOfStarter_Text_0:
# 720 "data/maps/Route1NN/scripts.pory"
	.string "Go on and choose the one you'd like\n"
	.string "to keep as your partner, cousin!$"

Route1NN_BackOutOfStarter_Text_1:
# 938 "data/maps/Route1NN/scripts.pory"
	.string "All right! Then let's get going up\n"
	.string "to Iki Town, {PLAYER}.\p"
	.string "Woo!\p"
	.string "Time to meet the {COLOR RED}Island Kahuna!$"

Route1NN_Rockruff_Text_0:
# 1020 "data/maps/Route1NN/scripts.pory"
	.string "Ruff!$"
