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
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 71 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 72 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 73 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 74 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 75 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 76 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 77 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 78 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 79 "data/maps/Route1NN/scripts.pory"
	playse SE_M_SCRATCH
# 80 "data/maps/Route1NN/scripts.pory"
	waitse
# 81 "data/maps/Route1NN/scripts.pory"
	addobject rt1_yungoos
# 82 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 83 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_0
# 84 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 85 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_1
# 86 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 87 "data/maps/Route1NN/scripts.pory"
	delay 30
# 88 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_YUNGOOS, 0
# 89 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_0, MSGBOX_AUTOCLOSE
# 90 "data/maps/Route1NN/scripts.pory"
	waitmessage
# 91 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_2
# 92 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 93 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 94 "data/maps/Route1NN/scripts.pory"
	addobject kukuistarters
# 95 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_3
# 96 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_2
# 101 "data/maps/Route1NN/scripts.pory"
	addobject rowlet
# 102 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_4
Route1NN_Trigger_GetStarters_1:
# 104 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_6
# 109 "data/maps/Route1NN/scripts.pory"
	addobject litten
# 110 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_5
Route1NN_Trigger_GetStarters_5:
# 112 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_10
# 117 "data/maps/Route1NN/scripts.pory"
	addobject popplio
# 118 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_6
Route1NN_Trigger_GetStarters_9:
# 120 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 121 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 122 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_14
# 129 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 130 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_7
# 131 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet
# 132 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_1, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_13:
# 134 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_18
# 141 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 142 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_7
# 143 "data/maps/Route1NN/scripts.pory"
	waitmovement litten
# 144 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_3, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_17:
# 146 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_22
# 153 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 154 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_7
# 155 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio
# 156 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_5, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_21:
# 158 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_YUNGOOS, 0
# 159 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_8
# 160 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 161 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_6, MSGBOX_AUTOCLOSE
# 162 "data/maps/Route1NN/scripts.pory"
	playse SE_FLEE
# 163 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_9
# 164 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 165 "data/maps/Route1NN/scripts.pory"
	delay 60
# 166 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_26
# 170 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_25:
# 172 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_30
# 176 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_29:
# 178 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_34
# 182 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_33:
# 184 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 185 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 186 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_11
# 187 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 188 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 189 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_12
# 190 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 191 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 192 "data/maps/Route1NN/scripts.pory"
	delay 60
# 193 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_13
# 194 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 195 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_7, MSGBOX_AUTOCLOSE
# 196 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_14
# 197 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_14
# 198 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 199 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_38
# 203 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_14
Route1NN_Trigger_GetStarters_37:
# 205 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_42
# 209 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_14
Route1NN_Trigger_GetStarters_41:
# 211 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_46
# 215 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_14
Route1NN_Trigger_GetStarters_45:
# 217 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 218 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 219 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_8
# 225 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 11, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_9, Route1NN_Trigger_GetStarters_Text_10
# 226 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Route1NN_Trigger_GetStarters_50
# 242 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 243 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 244 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 245 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_12
Route1NN_Trigger_GetStarters_49:
# 251 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 252 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_13
# 257 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_16
# 258 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 259 "data/maps/Route1NN/scripts.pory"
	waitse
# 260 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 261 "data/maps/Route1NN/scripts.pory"
	waitse
# 262 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 264 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_14
# 277 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_16
# 278 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 279 "data/maps/Route1NN/scripts.pory"
	waitse
# 280 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 281 "data/maps/Route1NN/scripts.pory"
	waitse
# 282 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 283 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_15, MSGBOX_AUTOCLOSE
# 293 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 294 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_TEMP_2
# 295 "data/maps/Route1NN/scripts.pory"
	removeobject techguy
# 296 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_17
# 297 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 298 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_18
# 299 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 300 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_19
# 301 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_20
# 302 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 303 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet
# 304 "data/maps/Route1NN/scripts.pory"
	removeobject litten
# 305 "data/maps/Route1NN/scripts.pory"
	removeobject popplio
# 306 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny
# 307 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny
# 308 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny
# 309 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_54
# 314 "data/maps/Route1NN/scripts.pory"
	addobject rowlet2
# 315 "data/maps/Route1NN/scripts.pory"
	setobjectxy rowlet2, 26, 16
Route1NN_Trigger_GetStarters_53:
# 317 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_58
# 322 "data/maps/Route1NN/scripts.pory"
	addobject litten2
# 323 "data/maps/Route1NN/scripts.pory"
	setobjectxy litten2, 27, 16
Route1NN_Trigger_GetStarters_57:
# 325 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_62
# 330 "data/maps/Route1NN/scripts.pory"
	addobject popplio2
# 331 "data/maps/Route1NN/scripts.pory"
	setobjectxy popplio2, 28, 16
Route1NN_Trigger_GetStarters_61:
# 333 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 334 "data/maps/Route1NN/scripts.pory"
	delay 60
# 335 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_21
# 336 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 337 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_16
# 338 "data/maps/Route1NN/scripts.pory"
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
# 368 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 369 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 370 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_19, MSGBOX_AUTOCLOSE
# 371 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 372 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_23
# 373 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
Route1NN_Trigger_GetStarters_69:
# 375 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 376 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_2
# 377 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 378 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_20
# 379 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_74
# 389 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 390 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 391 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_21, MSGBOX_AUTOCLOSE
# 392 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 393 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 394 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_24
# 395 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
Route1NN_Trigger_GetStarters_73:
# 397 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 398 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_25
# 399 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 400 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_22
# 412 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 20, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_23, Route1NN_Trigger_GetStarters_Text_24, Route1NN_Trigger_GetStarters_Text_25
# 413 "data/maps/Route1NN/scripts.pory"
	switch VAR_RESULT
# 414 "data/maps/Route1NN/scripts.pory"
	case 0, Route1NN_Trigger_GetStarters_79
# 474 "data/maps/Route1NN/scripts.pory"
	case 1, Route1NN_Trigger_GetStarters_80
# 543 "data/maps/Route1NN/scripts.pory"
	case 2, Route1NN_Trigger_GetStarters_81
Route1NN_Trigger_GetStarters_77:
# 612 "data/maps/Route1NN/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 613 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_32
# 614 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_10
# 615 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 616 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_26, MSGBOX_YESNO
# 618 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route1NN_Trigger_GetStarters_83
# 623 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_27, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_82:
# 626 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 627 "data/maps/Route1NN/scripts.pory"
	playse SE_BALL_OPEN
# 628 "data/maps/Route1NN/scripts.pory"
	delay 60
# 629 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 630 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 631 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
# 632 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 633 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
# 634 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 635 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
# 636 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 637 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 638 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_28
# 649 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 650 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 651 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_29, MSGBOX_AUTOCLOSE
# 652 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 653 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 654 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_30
# 660 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_31, Route1NN_Trigger_GetStarters_Text_32
# 661 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Route1NN_Trigger_GetStarters_111
# 684 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 685 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 686 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_33, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_110:
# 703 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_33
# 704 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_34
# 705 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_34
# 706 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 707 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_HIDE_KUKUI_STARTERS
# 708 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_35
# 709 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 710 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_34, MSGBOX_AUTOCLOSE
# 711 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_32
# 712 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 713 "data/maps/Route1NN/scripts.pory"
	delay 30
# 714 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_36
# 715 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 716 "data/maps/Route1NN/scripts.pory"
	delay 90
# 717 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 718 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_37
# 719 "data/maps/Route1NN/scripts.pory"
	setobjectxy kukuistarters, 21, 19
# 720 "data/maps/Route1NN/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 721 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 722 "data/maps/Route1NN/scripts.pory"
	addobject techguy
# 723 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_TEMP_2
# 724 "data/maps/Route1NN/scripts.pory"
	setvar VAR_STARTERS_STATE, 1
# 725 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 726 "data/maps/Route1NN/scripts.pory"
	release
	end

Route1NN_Trigger_GetStarters_2:
# 97 "data/maps/Route1NN/scripts.pory"
	addobject rowletshiny
# 98 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_4
	goto Route1NN_Trigger_GetStarters_1

Route1NN_Trigger_GetStarters_6:
# 105 "data/maps/Route1NN/scripts.pory"
	addobject littenshiny
# 106 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_5
	goto Route1NN_Trigger_GetStarters_5

Route1NN_Trigger_GetStarters_10:
# 113 "data/maps/Route1NN/scripts.pory"
	addobject popplioshiny
# 114 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_6
	goto Route1NN_Trigger_GetStarters_9

Route1NN_Trigger_GetStarters_14:
# 123 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 124 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_7
# 125 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny
# 126 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_1, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_13

Route1NN_Trigger_GetStarters_18:
# 135 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 136 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_7
# 137 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny
# 138 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_2, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_17

Route1NN_Trigger_GetStarters_22:
# 147 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 148 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_7
# 149 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny
# 150 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_4, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_21

Route1NN_Trigger_GetStarters_26:
# 167 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_25

Route1NN_Trigger_GetStarters_30:
# 173 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_29

Route1NN_Trigger_GetStarters_34:
# 179 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_33

Route1NN_Trigger_GetStarters_38:
# 200 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_14
	goto Route1NN_Trigger_GetStarters_37

Route1NN_Trigger_GetStarters_42:
# 206 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_14
	goto Route1NN_Trigger_GetStarters_41

Route1NN_Trigger_GetStarters_46:
# 212 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_14
	goto Route1NN_Trigger_GetStarters_45

Route1NN_Trigger_GetStarters_50:
# 228 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 229 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 230 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_KukuiGoToIki_Text_0
# 231 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_11
	goto Route1NN_Trigger_GetStarters_49

Route1NN_Trigger_GetStarters_54:
# 310 "data/maps/Route1NN/scripts.pory"
	addobject rowletshiny2
# 311 "data/maps/Route1NN/scripts.pory"
	setobjectxy rowletshiny2, 26, 16
	goto Route1NN_Trigger_GetStarters_53

Route1NN_Trigger_GetStarters_58:
# 318 "data/maps/Route1NN/scripts.pory"
	addobject littenshiny2
# 319 "data/maps/Route1NN/scripts.pory"
	setobjectxy littenshiny2, 27, 16
	goto Route1NN_Trigger_GetStarters_57

Route1NN_Trigger_GetStarters_62:
# 326 "data/maps/Route1NN/scripts.pory"
	addobject popplioshiny2
# 327 "data/maps/Route1NN/scripts.pory"
	setobjectxy popplioshiny2, 28, 16
	goto Route1NN_Trigger_GetStarters_61

Route1NN_Trigger_GetStarters_66:
# 339 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 340 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 341 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_17, MSGBOX_AUTOCLOSE
# 342 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 343 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_22
# 344 "data/maps/Route1NN/scripts.pory"
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
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_23
# 365 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
	goto Route1NN_Trigger_GetStarters_69

Route1NN_Trigger_GetStarters_74:
# 380 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 381 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 382 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_21, MSGBOX_AUTOCLOSE
# 383 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 384 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 385 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_24
# 386 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
	goto Route1NN_Trigger_GetStarters_73

Route1NN_Trigger_GetStarters_79:
# 415 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_87
# 428 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_88
# 442 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_89
# 457 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
# 458 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_26
# 459 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 460 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 461 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_27
# 462 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 463 "data/maps/Route1NN/scripts.pory"
	delay 30
# 464 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 465 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_28
# 466 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 467 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStarters_86:
# 469 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 470 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 471 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
# 472 "data/maps/Route1NN/scripts.pory"
	delay 150
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_80:
# 475 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_95
# 490 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_96
# 507 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_97
# 524 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
# 525 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_29
# 526 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 527 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 528 "data/maps/Route1NN/scripts.pory"
	waitse
# 529 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 530 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_30
# 531 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 532 "data/maps/Route1NN/scripts.pory"
	delay 30
# 533 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 534 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_28
# 535 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 536 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStarters_94:
# 538 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 539 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 540 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
# 541 "data/maps/Route1NN/scripts.pory"
	delay 150
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_81:
# 544 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_103
# 559 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_104
# 575 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_105
# 592 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
# 593 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_31
# 594 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 595 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 596 "data/maps/Route1NN/scripts.pory"
	waitse
# 597 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 598 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_30
# 599 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 600 "data/maps/Route1NN/scripts.pory"
	delay 30
# 601 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 602 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_28
# 603 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 604 "data/maps/Route1NN/scripts.pory"
	delay 60
Route1NN_Trigger_GetStarters_102:
# 606 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 607 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 608 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
# 609 "data/maps/Route1NN/scripts.pory"
	delay 150
	goto Route1NN_Trigger_GetStarters_77

Route1NN_Trigger_GetStarters_83:
# 619 "data/maps/Route1NN/scripts.pory"
	setvar VAR_0x8004, 0
# 620 "data/maps/Route1NN/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto Route1NN_Trigger_GetStarters_82

Route1NN_Trigger_GetStarters_87:
# 416 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_ALWAYS
# 417 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_26
# 418 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 419 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 420 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_27
# 421 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 422 "data/maps/Route1NN/scripts.pory"
	delay 30
# 423 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 424 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 425 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 426 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_86

Route1NN_Trigger_GetStarters_88:
# 429 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
# 430 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
# 431 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_26
# 432 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 433 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 434 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_27
# 435 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 436 "data/maps/Route1NN/scripts.pory"
	delay 30
# 437 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 438 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_28
# 439 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 440 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_86

Route1NN_Trigger_GetStarters_89:
# 443 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
# 444 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
# 445 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_26
# 446 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 447 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 448 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_27
# 449 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 450 "data/maps/Route1NN/scripts.pory"
	delay 30
# 451 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 452 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_28
# 453 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 454 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_86

Route1NN_Trigger_GetStarters_95:
# 476 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_ALWAYS
# 477 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_29
# 478 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 479 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 480 "data/maps/Route1NN/scripts.pory"
	waitse
# 481 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 482 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_30
# 483 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 484 "data/maps/Route1NN/scripts.pory"
	delay 30
# 485 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 486 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 487 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 488 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_94

Route1NN_Trigger_GetStarters_96:
# 491 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
# 492 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
# 493 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_29
# 494 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 495 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 496 "data/maps/Route1NN/scripts.pory"
	waitse
# 497 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 498 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_30
# 499 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 500 "data/maps/Route1NN/scripts.pory"
	delay 30
# 501 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 502 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_28
# 503 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 504 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_94

Route1NN_Trigger_GetStarters_97:
# 508 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
# 509 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
# 510 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_29
# 511 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 512 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 513 "data/maps/Route1NN/scripts.pory"
	waitse
# 514 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 515 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_30
# 516 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 517 "data/maps/Route1NN/scripts.pory"
	delay 60
# 518 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 519 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_28
# 520 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 521 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_94

Route1NN_Trigger_GetStarters_103:
# 545 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_ALWAYS
# 546 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_31
# 547 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 548 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 549 "data/maps/Route1NN/scripts.pory"
	waitse
# 550 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 551 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_30
# 552 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 553 "data/maps/Route1NN/scripts.pory"
	delay 30
# 554 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 555 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_28
# 556 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 557 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_102

Route1NN_Trigger_GetStarters_104:
# 560 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
# 561 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
# 562 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_31
# 563 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 564 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 565 "data/maps/Route1NN/scripts.pory"
	waitse
# 566 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 567 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_30
# 568 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 569 "data/maps/Route1NN/scripts.pory"
	delay 30
# 570 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 571 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_28
# 572 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 573 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_102

Route1NN_Trigger_GetStarters_105:
# 576 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
# 577 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
# 578 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_31
# 579 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 580 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 581 "data/maps/Route1NN/scripts.pory"
	waitse
# 582 "data/maps/Route1NN/scripts.pory"
	playse SE_LEDGE
# 583 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_30
# 584 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 585 "data/maps/Route1NN/scripts.pory"
	delay 30
# 586 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 587 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_28
# 588 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 589 "data/maps/Route1NN/scripts.pory"
	delay 60
	goto Route1NN_Trigger_GetStarters_102

Route1NN_Trigger_GetStarters_111:
# 663 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_15
# 664 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 665 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_33, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_110


Route1NN_Rockruff::
# 731 "data/maps/Route1NN/scripts.pory"
	lock
# 732 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 733 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 734 "data/maps/Route1NN/scripts.pory"
	applymovement route1nnrockruff, Route1NN_Rockruff_Movement_0
# 735 "data/maps/Route1NN/scripts.pory"
	waitmovement route1nnrockruff
# 736 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Rockruff_Text_0, MSGBOX_AUTOCLOSE
# 737 "data/maps/Route1NN/scripts.pory"
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

# 83 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_0:
# 83 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
	step_end

# 85 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_1:
# 85 "data/maps/Route1NN/scripts.pory"
	walk_right
# 85 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 91 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_2:
# 91 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 95 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_3:
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 95 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
	step_end

# 98 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_4:
# 98 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 98 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 98 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 98 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 98 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 98 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 98 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 98 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 98 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 106 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_5:
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 106 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 114 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_6:
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 114 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 124 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_7:
# 124 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
# 124 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
# 124 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
	step_end

# 159 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_8:
# 159 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
# 159 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
# 159 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
	step_end

# 163 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_9:
# 163 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 163 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 163 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 163 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 163 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 163 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 163 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
	step_end

# 167 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_10:
# 167 "data/maps/Route1NN/scripts.pory"
	face_right
	step_end

# 186 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_11:
# 186 "data/maps/Route1NN/scripts.pory"
	walk_up
# 186 "data/maps/Route1NN/scripts.pory"
	walk_up
# 186 "data/maps/Route1NN/scripts.pory"
	walk_up
# 186 "data/maps/Route1NN/scripts.pory"
	walk_up
# 186 "data/maps/Route1NN/scripts.pory"
	walk_up
# 186 "data/maps/Route1NN/scripts.pory"
	walk_up
# 186 "data/maps/Route1NN/scripts.pory"
	face_left
# 186 "data/maps/Route1NN/scripts.pory"
	delay_16
	step_end

# 189 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_12:
# 189 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
# 189 "data/maps/Route1NN/scripts.pory"
	face_right
	step_end

# 193 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_13:
# 193 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
# 193 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
	step_end

# 196 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_14:
# 196 "data/maps/Route1NN/scripts.pory"
	walk_right
# 196 "data/maps/Route1NN/scripts.pory"
	walk_right
# 196 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 228 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_15:
# 228 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
# 228 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
	step_end

# 257 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_16:
# 257 "data/maps/Route1NN/scripts.pory"
	jump_in_place_left
# 257 "data/maps/Route1NN/scripts.pory"
	jump_in_place_left
	step_end

# 296 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_17:
# 296 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 296 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 296 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 296 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 296 "data/maps/Route1NN/scripts.pory"
	face_up
	step_end

# 298 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_18:
# 298 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 298 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 298 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 298 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
	step_end

# 300 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_19:
# 300 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 300 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 300 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
	step_end

# 301 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_20:
# 301 "data/maps/Route1NN/scripts.pory"
	face_up
	step_end

# 335 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_21:
# 335 "data/maps/Route1NN/scripts.pory"
	walk_slow_up
# 335 "data/maps/Route1NN/scripts.pory"
	walk_slow_diag_northwest
	step_end

# 343 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_22:
# 343 "data/maps/Route1NN/scripts.pory"
	face_left
# 343 "data/maps/Route1NN/scripts.pory"
	delay_16
# 343 "data/maps/Route1NN/scripts.pory"
	face_up
# 343 "data/maps/Route1NN/scripts.pory"
	delay_16
# 343 "data/maps/Route1NN/scripts.pory"
	face_right
# 343 "data/maps/Route1NN/scripts.pory"
	delay_16
# 343 "data/maps/Route1NN/scripts.pory"
	face_down
# 343 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 343 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
	step_end

# 364 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_23:
# 364 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 364 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 364 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 364 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
	step_end

# 385 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_24:
# 385 "data/maps/Route1NN/scripts.pory"
	jump_in_place_down
	step_end

# 398 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_25:
# 398 "data/maps/Route1NN/scripts.pory"
	walk_slow_diag_southwest
# 398 "data/maps/Route1NN/scripts.pory"
	walk_slow_down
	step_end

# 417 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_26:
# 417 "data/maps/Route1NN/scripts.pory"
	walk_down
# 417 "data/maps/Route1NN/scripts.pory"
	walk_right
# 417 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 420 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_27:
# 420 "data/maps/Route1NN/scripts.pory"
	face_left
# 420 "data/maps/Route1NN/scripts.pory"
	delay_16
# 420 "data/maps/Route1NN/scripts.pory"
	face_up
# 420 "data/maps/Route1NN/scripts.pory"
	delay_16
# 420 "data/maps/Route1NN/scripts.pory"
	face_right
# 420 "data/maps/Route1NN/scripts.pory"
	delay_16
# 420 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 424 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_28:
# 424 "data/maps/Route1NN/scripts.pory"
	emote_heart
	step_end

# 477 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_29:
# 477 "data/maps/Route1NN/scripts.pory"
	walk_down
	step_end

# 482 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_30:
# 482 "data/maps/Route1NN/scripts.pory"
	jump_in_place_up_down
	step_end

# 546 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_31:
# 546 "data/maps/Route1NN/scripts.pory"
	walk_down
# 546 "data/maps/Route1NN/scripts.pory"
	walk_left
# 546 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 613 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_32:
# 613 "data/maps/Route1NN/scripts.pory"
	face_left
	step_end

# 703 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_33:
# 703 "data/maps/Route1NN/scripts.pory"
	walk_down
# 703 "data/maps/Route1NN/scripts.pory"
	walk_left
# 703 "data/maps/Route1NN/scripts.pory"
	walk_left
# 703 "data/maps/Route1NN/scripts.pory"
	walk_left
# 703 "data/maps/Route1NN/scripts.pory"
	walk_left
# 703 "data/maps/Route1NN/scripts.pory"
	walk_left
# 703 "data/maps/Route1NN/scripts.pory"
	walk_left
# 703 "data/maps/Route1NN/scripts.pory"
	walk_left
	step_end

# 704 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_34:
# 704 "data/maps/Route1NN/scripts.pory"
	delay_16
# 704 "data/maps/Route1NN/scripts.pory"
	delay_16
# 704 "data/maps/Route1NN/scripts.pory"
	delay_16
# 704 "data/maps/Route1NN/scripts.pory"
	delay_16
# 704 "data/maps/Route1NN/scripts.pory"
	walk_down
# 704 "data/maps/Route1NN/scripts.pory"
	walk_down
# 704 "data/maps/Route1NN/scripts.pory"
	walk_left
# 704 "data/maps/Route1NN/scripts.pory"
	walk_left
# 704 "data/maps/Route1NN/scripts.pory"
	walk_left
# 704 "data/maps/Route1NN/scripts.pory"
	walk_left
# 704 "data/maps/Route1NN/scripts.pory"
	walk_left
# 704 "data/maps/Route1NN/scripts.pory"
	walk_left
	step_end

# 708 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_35:
# 708 "data/maps/Route1NN/scripts.pory"
	face_down
	step_end

# 714 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_36:
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 714 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
# 714 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
# 714 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
	step_end

# 718 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_37:
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_fast_right
# 718 "data/maps/Route1NN/scripts.pory"
	walk_diag_southeast
# 718 "data/maps/Route1NN/scripts.pory"
	walk_diag_southeast
# 718 "data/maps/Route1NN/scripts.pory"
	walk_diag_southeast
	step_end

# 734 "data/maps/Route1NN/scripts.pory"
Route1NN_Rockruff_Movement_0:
# 734 "data/maps/Route1NN/scripts.pory"
	face_player
# 734 "data/maps/Route1NN/scripts.pory"
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
# 89 "data/maps/Route1NN/scripts.pory"
	.string "Yaaahhhh!$"

Route1NN_Trigger_GetStarters_Text_1:
# 126 "data/maps/Route1NN/scripts.pory"
	.string "Hoooo!$"

Route1NN_Trigger_GetStarters_Text_2:
# 138 "data/maps/Route1NN/scripts.pory"
	.string "Mrrr!$"

Route1NN_Trigger_GetStarters_Text_3:
# 144 "data/maps/Route1NN/scripts.pory"
	.string "Mraaarrrr!$"

Route1NN_Trigger_GetStarters_Text_4:
# 150 "data/maps/Route1NN/scripts.pory"
	.string "Prrr!$"

Route1NN_Trigger_GetStarters_Text_5:
# 156 "data/maps/Route1NN/scripts.pory"
	.string "Bwark! Bwark!$"

Route1NN_Trigger_GetStarters_Text_6:
# 161 "data/maps/Route1NN/scripts.pory"
	.string "Ya…yah…$"

Route1NN_Trigger_GetStarters_Text_7:
# 195 "data/maps/Route1NN/scripts.pory"
	.string "Hey there, cousin!$"

Route1NN_Trigger_GetStarters_Text_8:
# 219 "data/maps/Route1NN/scripts.pory"
	.string "Hang on, I know you…\n"
	.string "You're {PLAYER}, right?\p"
	.string "You OK?\p"
	.string "I saw you get attacked like that!$"

Route1NN_Trigger_GetStarters_Text_9:
# 225 "data/maps/Route1NN/scripts.pory"
	.string "Yeah, I got a bit of help$"

Route1NN_Trigger_GetStarters_Text_10:
# 225 "data/maps/Route1NN/scripts.pory"
	.string "I was scared spitless!$"

Route1NN_Trigger_GetStarters_Text_11:
# 231 "data/maps/Route1NN/scripts.pory"
	.string "Looks like you did!\p"
	.string "Though I sure didn't expect that,\n"
	.string "yeah…\p"
	.string "I didn't think these little fellows\n"
	.string "would dash out on their own to help\l"
	.string "save a stranger!$"

Route1NN_Trigger_GetStarters_Text_12:
# 245 "data/maps/Route1NN/scripts.pory"
	.string "You and me both, cousin!\p"
	.string "I'm looking after these Pokémon,\n"
	.string "but they dashed right out on\l"
	.string "their own to save you!$"

Route1NN_Trigger_GetStarters_Text_13:
# 252 "data/maps/Route1NN/scripts.pory"
	.string "But I guess I'm getting ahead of\n"
	.string "myself.\p"
	.string "Welcome to Alola, the Pokémon paradise!$"

Route1NN_Trigger_GetStarters_Text_14:
# 264 "data/maps/Route1NN/scripts.pory"
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
# 283 "data/maps/Route1NN/scripts.pory"
	.string "Wild Pokémon could be lurking in\n"
	.string "the tall grass, yeah, just waiting\l"
	.string "to leap out and bite you, but\l"
	.string "you'll be fine if you've got a\l"
	.string "partner of your own!\p"
	.string "Hey there!\p"
	.string "Here, let me introduce the Pokémon\n"
	.string "that helped you just now.$"

Route1NN_Trigger_GetStarters_Text_16:
# 337 "data/maps/Route1NN/scripts.pory"
	.string "This is the Grass-type Pokémon, Rowlet.$"

Route1NN_Trigger_GetStarters_Text_17:
# 341 "data/maps/Route1NN/scripts.pory"
	.string "Hoo!$"

Route1NN_Trigger_GetStarters_Text_18:
# 358 "data/maps/Route1NN/scripts.pory"
	.string "And the Fire-type Pokémon, Litten.$"

Route1NN_Trigger_GetStarters_Text_19:
# 362 "data/maps/Route1NN/scripts.pory"
	.string "Mrawr.$"

Route1NN_Trigger_GetStarters_Text_20:
# 378 "data/maps/Route1NN/scripts.pory"
	.string "And the Water-type Pokémon Popplio.$"

Route1NN_Trigger_GetStarters_Text_21:
# 382 "data/maps/Route1NN/scripts.pory"
	.string "Bwark?$"

Route1NN_Trigger_GetStarters_Text_22:
# 400 "data/maps/Route1NN/scripts.pory"
	.string "Y'see, the fact of the matter is…\p"
	.string "one of these Pokémon will become\n"
	.string "your first parter, woo!\p"
	.string "Heh…\p"
	.string "Maybe that's why they wanted to save\n"
	.string "you?\p"
	.string "Go on and choose the one you'd like\n"
	.string "to keep as your parter, cousin!$"

Route1NN_Trigger_GetStarters_Text_23:
# 412 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR GREEN}Rowlet$"

Route1NN_Trigger_GetStarters_Text_24:
# 412 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR RED}Litten$"

Route1NN_Trigger_GetStarters_Text_25:
# 412 "data/maps/Route1NN/scripts.pory"
	.string "{COLOR BLUE}Popplio$"

Route1NN_Trigger_GetStarters_Text_26:
# 616 "data/maps/Route1NN/scripts.pory"
	.string "Would you like to nickname your\n"
	.string "{STR_VAR_1}?$"

Route1NN_Trigger_GetStarters_Text_27:
# 623 "data/maps/Route1NN/scripts.pory"
	.string "No worries! You can nickname your\n"
	.string "Pokémon anytime from the menu.$"

Route1NN_Trigger_GetStarters_Text_28:
# 638 "data/maps/Route1NN/scripts.pory"
	.string "So you went with {STR_VAR_1}!\n"
	.string "Woo, what a fine-looking team you\l"
	.string "two are!\p"
	.string "Now that you can have Pokémon battles,\n"
	.string "you're what we call a Pokémon Trainer!\p"
	.string "Here's a Poké Ball for {STR_VAR_1},\n"
	.string "too.\p"
	.string "It should feel nice and cozy in there.$"

Route1NN_Trigger_GetStarters_Text_29:
# 651 "data/maps/Route1NN/scripts.pory"
	.string "Received {STR_VAR_1}'s Poké Ball!$"

Route1NN_Trigger_GetStarters_Text_30:
# 654 "data/maps/Route1NN/scripts.pory"
	.string "All right! Then let's get going up\n"
	.string "to Iki Town, {PLAYER}.\p"
	.string "Woo!\p"
	.string "Time to meet the {COLOR RED}Island Kahuna!$"

Route1NN_Trigger_GetStarters_Text_31:
# 660 "data/maps/Route1NN/scripts.pory"
	.string "Island Kahuna?!$"

Route1NN_Trigger_GetStarters_Text_32:
# 660 "data/maps/Route1NN/scripts.pory"
	.string "But why?!$"

Route1NN_Trigger_GetStarters_Text_33:
# 665 "data/maps/Route1NN/scripts.pory"
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
# 710 "data/maps/Route1NN/scripts.pory"
	.string "Iki Town is right up here!$"

Route1NN_Rockruff_Text_0:
# 736 "data/maps/Route1NN/scripts.pory"
	.string "Ruff!$"
