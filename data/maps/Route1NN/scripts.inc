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
# 348 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 349 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 350 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_17, MSGBOX_AUTOCLOSE
# 351 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 352 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_22
# 353 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
Route1NN_Trigger_GetStarters_65:
# 355 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 356 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_2
# 357 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 358 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_18
# 359 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_70
# 369 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 370 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 371 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_19, MSGBOX_AUTOCLOSE
# 372 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 373 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 374 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_23
# 375 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
Route1NN_Trigger_GetStarters_69:
# 377 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 378 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_2
# 379 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 380 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_20
# 381 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_74
# 394 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 395 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 396 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_21, MSGBOX_AUTOCLOSE
# 397 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 398 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_24
# 399 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 400 "data/maps/Route1NN/scripts.pory"
	waitse
# 401 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 402 "data/maps/Route1NN/scripts.pory"
	waitse
# 403 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
Route1NN_Trigger_GetStarters_73:
# 405 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 406 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_25
# 407 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 408 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_22
# 420 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_23, Route1NN_Trigger_GetStarters_Text_24, Route1NN_Trigger_GetStarters_Text_25
# 421 "data/maps/Route1NN/scripts.pory"
	switch VAR_RESULT
# 422 "data/maps/Route1NN/scripts.pory"
	case 0, Route1NN_Trigger_GetStarters_79
# 461 "data/maps/Route1NN/scripts.pory"
	case 1, Route1NN_Trigger_GetStarters_80
# 504 "data/maps/Route1NN/scripts.pory"
	case 2, Route1NN_Trigger_GetStarters_81
Route1NN_Trigger_GetStarters_77:
# 548 "data/maps/Route1NN/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 549 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_31
# 550 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_10
# 551 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 552 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_26, MSGBOX_YESNO
# 554 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route1NN_Trigger_GetStarters_83
# 559 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_27, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_82:
# 562 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 563 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 564 "data/maps/Route1NN/scripts.pory"
	delay 60
# 565 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 566 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 567 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
# 568 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 569 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
# 570 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 571 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
# 572 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 573 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 574 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 575 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_28
# 586 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 587 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 588 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_29, MSGBOX_AUTOCLOSE
# 589 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 590 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 591 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_30
# 597 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_31, Route1NN_Trigger_GetStarters_Text_32
# 598 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Route1NN_Trigger_GetStarters_96
# 621 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 622 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 623 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_33, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_95:
# 640 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_32
# 641 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_33
# 642 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_33
# 643 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 644 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_HIDE_KUKUI_STARTERS
# 645 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_34
# 646 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 647 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_34, MSGBOX_AUTOCLOSE
# 648 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_31
# 649 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 650 "data/maps/Route1NN/scripts.pory"
	delay 30
# 651 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_35
# 652 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 653 "data/maps/Route1NN/scripts.pory"
	delay 90
# 654 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 655 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_36
# 656 "data/maps/Route1NN/scripts.pory"
	setobjectxy kukuistarters, 21, 19
# 657 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 658 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 659 "data/maps/Route1NN/scripts.pory"
	addobject techguy
# 660 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_TEMP_2
# 661 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTERS_STATE, 1
# 662 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 663 "data/maps/Route1NN/scripts.pory"
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
	msgbox Route1NN_Trigger_GetStarters_Text_17, MSGBOX_AUTOCLOSE
# 343 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 344 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_22
# 345 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
	goto Route1NN_Trigger_GetStarters_65

Route1NN_Trigger_GetStarters_70:
# 360 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 361 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 362 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_19, MSGBOX_AUTOCLOSE
# 363 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 364 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 365 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_23
# 366 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
	goto Route1NN_Trigger_GetStarters_69

Route1NN_Trigger_GetStarters_74:
# 382 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 383 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 384 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_21, MSGBOX_AUTOCLOSE
# 385 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 386 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_24
# 387 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 388 "data/maps/Route1NN/scripts.pory"
	waitse
# 389 "data/maps/Route1NN/scripts.pory"
	playse SE_M_CRABHAMMER
# 390 "data/maps/Route1NN/scripts.pory"
	waitse
# 391 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
	goto Route1NN_Trigger_GetStarters_73

Route1NN_Trigger_GetStarters_79:
# 423 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_87
Route1NN_Trigger_GetStarters_86:
# 426 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_100
Route1NN_Trigger_GetStarters_99:
# 429 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_109
# 443 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
# 444 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_26
# 445 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 446 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 447 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_27
# 448 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 449 "data/maps/Route1NN/scripts.pory"
	delay 30
# 450 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 451 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_28
# 452 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 453 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStarters_108:
# 455 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 456 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 457 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 458 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
# 459 "data/maps/Route1NN/scripts.pory"
	delay 150
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_80:
# 462 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_90
Route1NN_Trigger_GetStarters_89:
# 465 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_103
Route1NN_Trigger_GetStarters_102:
# 468 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_113
# 484 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
# 485 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_29
# 486 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 487 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 488 "data/maps/Route1NN/scripts.pory"
	waitse
# 489 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 490 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_23
# 491 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 492 "data/maps/Route1NN/scripts.pory"
	delay 30
# 493 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 494 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_28
# 495 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 496 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStarters_112:
# 498 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 499 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 500 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 501 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
# 502 "data/maps/Route1NN/scripts.pory"
	delay 150
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_81:
# 505 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_93
Route1NN_Trigger_GetStarters_92:
# 508 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_106
Route1NN_Trigger_GetStarters_105:
# 511 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_117
# 527 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
# 528 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_30
# 529 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 530 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 531 "data/maps/Route1NN/scripts.pory"
	waitse
# 532 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 533 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_23
# 534 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 535 "data/maps/Route1NN/scripts.pory"
	delay 30
# 536 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 537 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_28
# 538 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 539 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStarters_116:
# 541 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 542 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 543 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 544 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
# 545 "data/maps/Route1NN/scripts.pory"
	delay 150
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_83:
# 555 "data/maps/Route1NN/scripts.pory"
	setvar VAR_0x8004, 0
# 556 "data/maps/Route1NN/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto Route1NN_Trigger_GetStarters_82

Route1NN_Trigger_GetStarters_87:
# 424 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_Trigger_GetStarters_86

Route1NN_Trigger_GetStarters_90:
# 463 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_Trigger_GetStarters_89

Route1NN_Trigger_GetStarters_93:
# 506 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_Trigger_GetStarters_92

Route1NN_Trigger_GetStarters_96:
# 600 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 601 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 602 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_33, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_95

Route1NN_Trigger_GetStarters_100:
# 427 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_Trigger_GetStarters_99

Route1NN_Trigger_GetStarters_103:
# 466 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
	goto Route1NN_Trigger_GetStarters_102

Route1NN_Trigger_GetStarters_106:
# 509 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
	goto Route1NN_Trigger_GetStarters_105

Route1NN_Trigger_GetStarters_109:
# 430 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_ALWAYS
# 431 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_26
# 432 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 433 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 434 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_27
# 435 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 436 "data/maps/Route1NN/scripts.pory"
	delay 30
# 437 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 438 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 439 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 440 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_108

Route1NN_Trigger_GetStarters_113:
# 469 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_ALWAYS
# 470 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_29
# 471 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 472 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 473 "data/maps/Route1NN/scripts.pory"
	waitse
# 474 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 475 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_23
# 476 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 477 "data/maps/Route1NN/scripts.pory"
	delay 30
# 478 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 479 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 480 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 481 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_112

Route1NN_Trigger_GetStarters_117:
# 512 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_ALWAYS
# 513 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_30
# 514 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 515 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 516 "data/maps/Route1NN/scripts.pory"
	waitse
# 517 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 518 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_23
# 519 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 520 "data/maps/Route1NN/scripts.pory"
	delay 30
# 521 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 522 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 523 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 524 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_116


Route1NN_Rockruff::
# 668 "data/maps/Route1NN/scripts.pory"
	lock
# 669 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 670 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 671 "data/maps/Route1NN/scripts.pory"
	applymovement route1nnrockruff, Route1NN_Rockruff_Movement_0
# 672 "data/maps/Route1NN/scripts.pory"
	waitmovement route1nnrockruff
# 673 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Rockruff_Text_0, MSGBOX_AUTOCLOSE
# 674 "data/maps/Route1NN/scripts.pory"
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

# 365 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_23:
# 365 "data/maps/Route1NN/scripts.pory"
	jump_in_place_down
	step_end

# 386 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_24:
# 386 "data/maps/Route1NN/scripts.pory"
	face_up
# 386 "data/maps/Route1NN/scripts.pory"
	delay_16
# 386 "data/maps/Route1NN/scripts.pory"
	walk_in_place_up
# 386 "data/maps/Route1NN/scripts.pory"
	walk_in_place_up
# 386 "data/maps/Route1NN/scripts.pory"
	delay_16
# 386 "data/maps/Route1NN/scripts.pory"
	delay_16
# 386 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 406 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_25:
# 406 "data/maps/Route1NN/scripts.pory"
	walk_slow_diag_southwest
# 406 "data/maps/Route1NN/scripts.pory"
	walk_slow_down
	step_end

# 431 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_26:
# 431 "data/maps/Route1NN/scripts.pory"
	walk_down
# 431 "data/maps/Route1NN/scripts.pory"
	walk_right
# 431 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 434 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_27:
# 434 "data/maps/Route1NN/scripts.pory"
	face_left
# 434 "data/maps/Route1NN/scripts.pory"
	delay_16
# 434 "data/maps/Route1NN/scripts.pory"
	face_up
# 434 "data/maps/Route1NN/scripts.pory"
	delay_16
# 434 "data/maps/Route1NN/scripts.pory"
	face_right
# 434 "data/maps/Route1NN/scripts.pory"
	delay_16
# 434 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 438 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_28:
# 438 "data/maps/Route1NN/scripts.pory"
	emote_heart
	step_end

# 470 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_29:
# 470 "data/maps/Route1NN/scripts.pory"
	walk_down
	step_end

# 513 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_30:
# 513 "data/maps/Route1NN/scripts.pory"
	walk_down
# 513 "data/maps/Route1NN/scripts.pory"
	walk_left
# 513 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 549 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_31:
# 549 "data/maps/Route1NN/scripts.pory"
	face_left
	step_end

# 640 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_32:
# 640 "data/maps/Route1NN/scripts.pory"
	walk_down
# 640 "data/maps/Route1NN/scripts.pory"
	walk_left
# 640 "data/maps/Route1NN/scripts.pory"
	walk_left
# 640 "data/maps/Route1NN/scripts.pory"
	walk_left
# 640 "data/maps/Route1NN/scripts.pory"
	walk_left
# 640 "data/maps/Route1NN/scripts.pory"
	walk_left
# 640 "data/maps/Route1NN/scripts.pory"
	walk_left
# 640 "data/maps/Route1NN/scripts.pory"
	walk_left
	step_end

# 641 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_33:
# 641 "data/maps/Route1NN/scripts.pory"
	delay_16
# 641 "data/maps/Route1NN/scripts.pory"
	delay_16
# 641 "data/maps/Route1NN/scripts.pory"
	delay_16
# 641 "data/maps/Route1NN/scripts.pory"
	delay_16
# 641 "data/maps/Route1NN/scripts.pory"
	walk_down
# 641 "data/maps/Route1NN/scripts.pory"
	walk_down
# 641 "data/maps/Route1NN/scripts.pory"
	walk_left
# 641 "data/maps/Route1NN/scripts.pory"
	walk_left
# 641 "data/maps/Route1NN/scripts.pory"
	walk_left
# 641 "data/maps/Route1NN/scripts.pory"
	walk_left
# 641 "data/maps/Route1NN/scripts.pory"
	walk_left
# 641 "data/maps/Route1NN/scripts.pory"
	walk_left
	step_end

# 645 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_34:
# 645 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 651 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_35:
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 651 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
# 651 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
# 651 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
	step_end

# 655 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_36:
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 655 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
	step_end

# 671 "data/maps/Route1NN/scripts.pory"
Route1NN_Rockruff_Movement_0:
# 671 "data/maps/Route1NN/scripts.pory"
	face_player
# 671 "data/maps/Route1NN/scripts.pory"
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
# 358 "data/maps/Route1NN/scripts.pory"
	.string "And the Fire-type Pokémon, Litten.$"

Route1NN_Trigger_GetStarters_Text_19:
# 362 "data/maps/Route1NN/scripts.pory"
	.string "Mrawr.$"

Route1NN_Trigger_GetStarters_Text_20:
# 380 "data/maps/Route1NN/scripts.pory"
	.string "And the Water-type Pokémon Popplio.$"

Route1NN_Trigger_GetStarters_Text_21:
# 384 "data/maps/Route1NN/scripts.pory"
	.string "Bwark?$"

Route1NN_Trigger_GetStarters_Text_22:
# 408 "data/maps/Route1NN/scripts.pory"
	.string "Y'see, the fact of the matter is…\p"
	.string "one of these Pokémon will become\n"
	.string "your first partner, woo!\p"
	.string "Heh…\p"
	.string "Maybe that's why they wanted to save\n"
	.string "you?\p"
	.string "Go on and choose the one you'd like\n"
	.string "to keep as your partner, cousin!$"

Route1NN_Trigger_GetStarters_Text_23:
# 420 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR GREEN}Rowlet$"

Route1NN_Trigger_GetStarters_Text_24:
# 420 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR RED}Litten$"

Route1NN_Trigger_GetStarters_Text_25:
# 420 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR BLUE}Popplio$"

Route1NN_Trigger_GetStarters_Text_26:
# 552 "data/maps/Route1NN/scripts.pory"
	.string "Would you like to nickname your\n"
	.string "{STR_VAR_1}?$"

Route1NN_Trigger_GetStarters_Text_27:
# 559 "data/maps/Route1NN/scripts.pory"
	.string "No worries! You can nickname your\n"
	.string "Pokémon anytime from the menu.$"

Route1NN_Trigger_GetStarters_Text_28:
# 575 "data/maps/Route1NN/scripts.pory"
	.string "So you went with {STR_VAR_1}!\n"
	.string "Woo, what a fine-looking team you\l"
	.string "two are!\p"
	.string "Now that you can have Pokémon battles,\n"
	.string "you're what we call a Pokémon Trainer!\p"
	.string "Here's a Poké Ball for {STR_VAR_1},\n"
	.string "too.\p"
	.string "It should feel nice and cozy in there.$"

Route1NN_Trigger_GetStarters_Text_29:
# 588 "data/maps/Route1NN/scripts.pory"
	.string "Received {STR_VAR_1}'s Poké Ball!$"

Route1NN_Trigger_GetStarters_Text_30:
# 591 "data/maps/Route1NN/scripts.pory"
	.string "All right! Then let's get going up\n"
	.string "to Iki Town, {PLAYER}.\p"
	.string "Woo!\p"
	.string "Time to meet the {COLOR RED}Island Kahuna!$"

Route1NN_Trigger_GetStarters_Text_31:
# 597 "data/maps/Route1NN/scripts.pory"
	.string "Island Kahuna?!$"

Route1NN_Trigger_GetStarters_Text_32:
# 597 "data/maps/Route1NN/scripts.pory"
	.string "But why?!$"

Route1NN_Trigger_GetStarters_Text_33:
# 602 "data/maps/Route1NN/scripts.pory"
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

Route1NN_Trigger_GetStarters_Text_34:
# 647 "data/maps/Route1NN/scripts.pory"
	.string "Iki Town is right up here!$"

Route1NN_Rockruff_Text_0:
# 673 "data/maps/Route1NN/scripts.pory"
	.string "Ruff!$"
