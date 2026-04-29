Route1NN_MapScripts::
	.byte 0


Route1NN_Trigger_GetStarters::
# 6 "data/maps/Route1NN/scripts.pory"
	lock
# 7 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 8 "data/maps/Route1NN/scripts.pory"
	special SpawnCameraObject
# 9 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 10 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 11 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 12 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 13 "data/maps/Route1NN/scripts.pory"
	callnative Script_RollShiny
# 14 "data/maps/Route1NN/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 15 "data/maps/Route1NN/scripts.pory"
	playse SE_M_SCRATCH
# 16 "data/maps/Route1NN/scripts.pory"
	waitse
# 17 "data/maps/Route1NN/scripts.pory"
	addobject rt1_yungoos
# 18 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 19 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_0
# 20 "data/maps/Route1NN/scripts.pory"
	waitmovement LOCALID_PLAYER
# 21 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_1
# 22 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 23 "data/maps/Route1NN/scripts.pory"
	delay 30
# 24 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_YUNGOOS, 0
# 25 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_0, MSGBOX_AUTOCLOSE
# 26 "data/maps/Route1NN/scripts.pory"
	waitmessage
# 27 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_2
# 28 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 29 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 30 "data/maps/Route1NN/scripts.pory"
	addobject kukuistarters
# 31 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_3
# 32 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_2
# 37 "data/maps/Route1NN/scripts.pory"
	addobject rowlet
# 38 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_4
Route1NN_Trigger_GetStarters_1:
# 40 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_6
# 45 "data/maps/Route1NN/scripts.pory"
	addobject litten
# 46 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_5
Route1NN_Trigger_GetStarters_5:
# 48 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_10
# 53 "data/maps/Route1NN/scripts.pory"
	addobject popplio
# 54 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_6
Route1NN_Trigger_GetStarters_9:
# 56 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 58 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_14
# 65 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 66 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_7
# 67 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet
# 68 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_1, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_13:
# 70 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_18
# 77 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 78 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_7
# 79 "data/maps/Route1NN/scripts.pory"
	waitmovement litten
# 80 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_3, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_17:
# 82 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_22
# 89 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 90 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_7
# 91 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio
# 92 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_5, MSGBOX_AUTOCLOSE
Route1NN_Trigger_GetStarters_21:
# 94 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_YUNGOOS, 0
# 95 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_8
# 96 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 97 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_6, MSGBOX_AUTOCLOSE
# 98 "data/maps/Route1NN/scripts.pory"
	playse SE_FLEE
# 99 "data/maps/Route1NN/scripts.pory"
	applymovement rt1_yungoos, Route1NN_Trigger_GetStarters_Movement_9
# 100 "data/maps/Route1NN/scripts.pory"
	waitmovement rt1_yungoos
# 101 "data/maps/Route1NN/scripts.pory"
	delay 60
# 102 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_26
# 106 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_25:
# 108 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_30
# 112 "data/maps/Route1NN/scripts.pory"
	applymovement litten, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_29:
# 114 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_34
# 118 "data/maps/Route1NN/scripts.pory"
	applymovement popplio, Route1NN_Trigger_GetStarters_Movement_10
Route1NN_Trigger_GetStarters_33:
# 120 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 121 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_11
# 122 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 123 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 124 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_12
# 125 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 126 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_Trigger_GetStarters_Text_7
# 127 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_8
# 135 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 17, 7, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_9, Route1NN_Trigger_GetStarters_Text_10
# 136 "data/maps/Route1NN/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Route1NN_Trigger_GetStarters_38
# 145 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_12
Route1NN_Trigger_GetStarters_37:
# 147 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_13
# 180 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 181 "data/maps/Route1NN/scripts.pory"
	removeobject techguy
# 182 "data/maps/Route1NN/scripts.pory"
	applymovement LOCALID_PLAYER, Route1NN_Trigger_GetStarters_Movement_13
# 183 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 184 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_14
# 185 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 186 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_15
# 187 "data/maps/Route1NN/scripts.pory"
	applymovement kukuistarters, Route1NN_Trigger_GetStarters_Movement_16
# 188 "data/maps/Route1NN/scripts.pory"
	waitmovement kukuistarters
# 189 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet
# 190 "data/maps/Route1NN/scripts.pory"
	removeobject litten
# 191 "data/maps/Route1NN/scripts.pory"
	removeobject popplio
# 192 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny
# 193 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny
# 194 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny
# 195 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_42
# 200 "data/maps/Route1NN/scripts.pory"
	addobject rowlet2
# 201 "data/maps/Route1NN/scripts.pory"
	setobjectxy rowlet2, 26, 16
Route1NN_Trigger_GetStarters_41:
# 203 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_46
# 208 "data/maps/Route1NN/scripts.pory"
	addobject litten2
# 209 "data/maps/Route1NN/scripts.pory"
	setobjectxy litten2, 27, 16
Route1NN_Trigger_GetStarters_45:
# 211 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_50
# 216 "data/maps/Route1NN/scripts.pory"
	addobject popplio2
# 217 "data/maps/Route1NN/scripts.pory"
	setobjectxy popplio2, 28, 16
Route1NN_Trigger_GetStarters_49:
# 219 "data/maps/Route1NN/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 220 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_17
# 221 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 222 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_14
# 223 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_54
# 232 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 233 "data/maps/Route1NN/scripts.pory"
	applymovement rowlet2, Route1NN_Trigger_GetStarters_Movement_18
# 234 "data/maps/Route1NN/scripts.pory"
	waitmovement rowlet2
# 235 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 236 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_15, MSGBOX_AUTOCLOSE
# 237 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
Route1NN_Trigger_GetStarters_53:
# 239 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_Trigger_GetStarters_Text_7
# 240 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_2
# 241 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 242 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_16
# 243 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_58
# 252 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 253 "data/maps/Route1NN/scripts.pory"
	applymovement litten2, Route1NN_Trigger_GetStarters_Movement_19
# 254 "data/maps/Route1NN/scripts.pory"
	waitmovement litten2
# 255 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 256 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_17, MSGBOX_AUTOCLOSE
# 257 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
Route1NN_Trigger_GetStarters_57:
# 259 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_Trigger_GetStarters_Text_7
# 260 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_2
# 261 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 262 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_18
# 263 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_62
# 272 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 273 "data/maps/Route1NN/scripts.pory"
	applymovement popplio2, Route1NN_Trigger_GetStarters_Movement_19
# 274 "data/maps/Route1NN/scripts.pory"
	waitmovement popplio2
# 275 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 276 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_19, MSGBOX_AUTOCLOSE
# 277 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
Route1NN_Trigger_GetStarters_61:
# 279 "data/maps/Route1NN/scripts.pory"
	speakername Route1NN_Trigger_GetStarters_Text_7
# 280 "data/maps/Route1NN/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1NN_Trigger_GetStarters_Movement_20
# 281 "data/maps/Route1NN/scripts.pory"
	waitmovement 0
# 282 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_20
# 294 "data/maps/Route1NN/scripts.pory"
	dynmultichoice 19, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Route1NN_Trigger_GetStarters_Text_21, Route1NN_Trigger_GetStarters_Text_22, Route1NN_Trigger_GetStarters_Text_23
# 295 "data/maps/Route1NN/scripts.pory"
	switch VAR_RESULT
# 296 "data/maps/Route1NN/scripts.pory"
	case 0, Route1NN_Trigger_GetStarters_67
# 315 "data/maps/Route1NN/scripts.pory"
	case 1, Route1NN_Trigger_GetStarters_68
# 334 "data/maps/Route1NN/scripts.pory"
	case 2, Route1NN_Trigger_GetStarters_69
Route1NN_Trigger_GetStarters_65:
# 354 "data/maps/Route1NN/scripts.pory"
	special RemoveCameraObject
# 355 "data/maps/Route1NN/scripts.pory"
	addobject techguy
# 356 "data/maps/Route1NN/scripts.pory"
	release
	end

Route1NN_Trigger_GetStarters_2:
# 33 "data/maps/Route1NN/scripts.pory"
	addobject rowletshiny
# 34 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_4
	goto Route1NN_Trigger_GetStarters_1

Route1NN_Trigger_GetStarters_6:
# 41 "data/maps/Route1NN/scripts.pory"
	addobject littenshiny
# 42 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_5
	goto Route1NN_Trigger_GetStarters_5

Route1NN_Trigger_GetStarters_10:
# 49 "data/maps/Route1NN/scripts.pory"
	addobject popplioshiny
# 50 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_6
	goto Route1NN_Trigger_GetStarters_9

Route1NN_Trigger_GetStarters_14:
# 59 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 60 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_7
# 61 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny
# 62 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_1, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_13

Route1NN_Trigger_GetStarters_18:
# 71 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 72 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_7
# 73 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny
# 74 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_2, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_17

Route1NN_Trigger_GetStarters_22:
# 83 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 84 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_7
# 85 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny
# 86 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_4, MSGBOX_AUTOCLOSE
	goto Route1NN_Trigger_GetStarters_21

Route1NN_Trigger_GetStarters_26:
# 103 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_25

Route1NN_Trigger_GetStarters_30:
# 109 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_29

Route1NN_Trigger_GetStarters_34:
# 115 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny, Route1NN_Trigger_GetStarters_Movement_10
	goto Route1NN_Trigger_GetStarters_33

Route1NN_Trigger_GetStarters_38:
# 138 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_11
	goto Route1NN_Trigger_GetStarters_37

Route1NN_Trigger_GetStarters_42:
# 196 "data/maps/Route1NN/scripts.pory"
	addobject rowletshiny2
# 197 "data/maps/Route1NN/scripts.pory"
	setobjectxy rowletshiny2, 26, 16
	goto Route1NN_Trigger_GetStarters_41

Route1NN_Trigger_GetStarters_46:
# 204 "data/maps/Route1NN/scripts.pory"
	addobject littenshiny2
# 205 "data/maps/Route1NN/scripts.pory"
	setobjectxy littenshiny2, 27, 16
	goto Route1NN_Trigger_GetStarters_45

Route1NN_Trigger_GetStarters_50:
# 212 "data/maps/Route1NN/scripts.pory"
	addobject popplioshiny2
# 213 "data/maps/Route1NN/scripts.pory"
	setobjectxy popplioshiny2, 28, 16
	goto Route1NN_Trigger_GetStarters_49

Route1NN_Trigger_GetStarters_54:
# 224 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 225 "data/maps/Route1NN/scripts.pory"
	applymovement rowletshiny2, Route1NN_Trigger_GetStarters_Movement_18
# 226 "data/maps/Route1NN/scripts.pory"
	waitmovement rowletshiny2
# 227 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 228 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_15, MSGBOX_AUTOCLOSE
# 229 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Route1NN_Trigger_GetStarters_53

Route1NN_Trigger_GetStarters_58:
# 244 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 245 "data/maps/Route1NN/scripts.pory"
	applymovement littenshiny2, Route1NN_Trigger_GetStarters_Movement_19
# 246 "data/maps/Route1NN/scripts.pory"
	waitmovement littenshiny2
# 247 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 248 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_17, MSGBOX_AUTOCLOSE
# 249 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Route1NN_Trigger_GetStarters_57

Route1NN_Trigger_GetStarters_62:
# 264 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 265 "data/maps/Route1NN/scripts.pory"
	applymovement popplioshiny2, Route1NN_Trigger_GetStarters_Movement_19
# 266 "data/maps/Route1NN/scripts.pory"
	waitmovement popplioshiny2
# 267 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 268 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Trigger_GetStarters_Text_19, MSGBOX_AUTOCLOSE
# 269 "data/maps/Route1NN/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Route1NN_Trigger_GetStarters_61

Route1NN_Trigger_GetStarters_67:
# 297 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_71
# 300 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_72
# 304 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_73
# 309 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
Route1NN_Trigger_GetStarters_70:
# 311 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 312 "data/maps/Route1NN/scripts.pory"
	removeobject rowlet2
# 313 "data/maps/Route1NN/scripts.pory"
	removeobject rowletshiny2
	goto Route1NN_Trigger_GetStarters_65

Route1NN_Trigger_GetStarters_68:
# 316 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_79
# 319 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_80
# 323 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_81
# 328 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
Route1NN_Trigger_GetStarters_78:
# 330 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 331 "data/maps/Route1NN/scripts.pory"
	removeobject litten2
# 332 "data/maps/Route1NN/scripts.pory"
	removeobject littenshiny2
	goto Route1NN_Trigger_GetStarters_65

Route1NN_Trigger_GetStarters_69:
# 335 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_3, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_87
# 338 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_2, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_88
# 342 "data/maps/Route1NN/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq Route1NN_Trigger_GetStarters_89
# 347 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
Route1NN_Trigger_GetStarters_86:
# 349 "data/maps/Route1NN/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 350 "data/maps/Route1NN/scripts.pory"
	removeobject popplio2
# 351 "data/maps/Route1NN/scripts.pory"
	removeobject popplioshiny2
	goto Route1NN_Trigger_GetStarters_65

Route1NN_Trigger_GetStarters_71:
# 298 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_ALWAYS
	goto Route1NN_Trigger_GetStarters_70

Route1NN_Trigger_GetStarters_72:
# 301 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
# 302 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
	goto Route1NN_Trigger_GetStarters_70

Route1NN_Trigger_GetStarters_73:
# 305 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
# 306 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_ROWLET, 5, shinyMode = SHINY_MODE_NEVER
	goto Route1NN_Trigger_GetStarters_70

Route1NN_Trigger_GetStarters_79:
# 317 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_ALWAYS
	goto Route1NN_Trigger_GetStarters_78

Route1NN_Trigger_GetStarters_80:
# 320 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
# 321 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
	goto Route1NN_Trigger_GetStarters_78

Route1NN_Trigger_GetStarters_81:
# 324 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
# 325 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_LITTEN, 5, shinyMode = SHINY_MODE_NEVER
	goto Route1NN_Trigger_GetStarters_78

Route1NN_Trigger_GetStarters_87:
# 336 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_ALWAYS
	goto Route1NN_Trigger_GetStarters_86

Route1NN_Trigger_GetStarters_88:
# 339 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_RIVAL_SHINY
# 340 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
	goto Route1NN_Trigger_GetStarters_86

Route1NN_Trigger_GetStarters_89:
# 343 "data/maps/Route1NN/scripts.pory"
	setflag FLAG_KUKUI_SHINY
# 344 "data/maps/Route1NN/scripts.pory"
	givemon SPECIES_POPPLIO, 5, shinyMode = SHINY_MODE_NEVER
	goto Route1NN_Trigger_GetStarters_86


Route1NN_Rockruff::
# 362 "data/maps/Route1NN/scripts.pory"
	lock
# 363 "data/maps/Route1NN/scripts.pory"
	faceplayer
# 364 "data/maps/Route1NN/scripts.pory"
	emote_heart
# 365 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 366 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 367 "data/maps/Route1NN/scripts.pory"
	applymovement route1nnrockruff, Route1NN_Rockruff_Movement_0
# 368 "data/maps/Route1NN/scripts.pory"
	waitmovement route1nnrockruff
# 369 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Rockruff_Text_0, MSGBOX_AUTOCLOSE
# 370 "data/maps/Route1NN/scripts.pory"
	release
	end


# 19 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_0:
# 19 "data/maps/Route1NN/scripts.pory"
	emote_exclamation_mark
	step_end

# 21 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_1:
# 21 "data/maps/Route1NN/scripts.pory"
	walk_right
# 21 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 27 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_2:
# 27 "data/maps/Route1NN/scripts.pory"
	walk_right
	step_end

# 31 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_3:
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 31 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
	step_end

# 34 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_4:
# 34 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 34 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 34 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 34 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 34 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 34 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 34 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 34 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 34 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 42 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_5:
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 42 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 50 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_6:
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_down
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
# 50 "data/maps/Route1NN/scripts.pory"
	walk_faster_left
	step_end

# 60 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_7:
# 60 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
# 60 "data/maps/Route1NN/scripts.pory"
	walk_in_place_left
	step_end

# 95 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_8:
# 95 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
# 95 "data/maps/Route1NN/scripts.pory"
	walk_in_place_right
	step_end

# 99 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_9:
# 99 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 99 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 99 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 99 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 99 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 99 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
# 99 "data/maps/Route1NN/scripts.pory"
	walk_fast_left
	step_end

# 103 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_10:
# 103 "data/maps/Route1NN/scripts.pory"
	face_right
	step_end

# 121 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_11:
# 121 "data/maps/Route1NN/scripts.pory"
	walk_up
# 121 "data/maps/Route1NN/scripts.pory"
	walk_up
# 121 "data/maps/Route1NN/scripts.pory"
	walk_up
# 121 "data/maps/Route1NN/scripts.pory"
	walk_up
# 121 "data/maps/Route1NN/scripts.pory"
	walk_up
# 121 "data/maps/Route1NN/scripts.pory"
	walk_up
# 121 "data/maps/Route1NN/scripts.pory"
	walk_left
# 121 "data/maps/Route1NN/scripts.pory"
	walk_left
# 121 "data/maps/Route1NN/scripts.pory"
	walk_left
# 121 "data/maps/Route1NN/scripts.pory"
	delay_16
	step_end

# 124 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_12:
# 124 "data/maps/Route1NN/scripts.pory"
	emote_double_exclamation_mark
# 124 "data/maps/Route1NN/scripts.pory"
	face_right
	step_end

# 182 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_13:
# 182 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 182 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 182 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 182 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 182 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 182 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 182 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 182 "data/maps/Route1NN/scripts.pory"
	face_up
	step_end

# 184 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_14:
# 184 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 184 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 184 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 184 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 184 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 184 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 184 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
	step_end

# 186 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_15:
# 186 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 186 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 186 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 186 "data/maps/Route1NN/scripts.pory"
	walk_faster_right
# 186 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
# 186 "data/maps/Route1NN/scripts.pory"
	walk_faster_up
	step_end

# 187 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_16:
# 187 "data/maps/Route1NN/scripts.pory"
	face_up
	step_end

# 220 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_17:
# 220 "data/maps/Route1NN/scripts.pory"
	walk_up
# 220 "data/maps/Route1NN/scripts.pory"
	walk_diag_northwest
	step_end

# 225 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_18:
# 225 "data/maps/Route1NN/scripts.pory"
	face_left
# 225 "data/maps/Route1NN/scripts.pory"
	delay_16
# 225 "data/maps/Route1NN/scripts.pory"
	face_up
# 225 "data/maps/Route1NN/scripts.pory"
	delay_16
# 225 "data/maps/Route1NN/scripts.pory"
	face_right
# 225 "data/maps/Route1NN/scripts.pory"
	delay_16
# 225 "data/maps/Route1NN/scripts.pory"
	face_down
# 225 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 225 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
	step_end

# 245 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_19:
# 245 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 245 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 245 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
# 245 "data/maps/Route1NN/scripts.pory"
	walk_in_place_down
	step_end

# 280 "data/maps/Route1NN/scripts.pory"
Route1NN_Trigger_GetStarters_Movement_20:
# 280 "data/maps/Route1NN/scripts.pory"
	walk_diag_southwest
# 280 "data/maps/Route1NN/scripts.pory"
	walk_down
	step_end

# 367 "data/maps/Route1NN/scripts.pory"
Route1NN_Rockruff_Movement_0:
# 367 "data/maps/Route1NN/scripts.pory"
	emote_heart
	step_end

Route1NN_Trigger_GetStarters_Text_0:
# 25 "data/maps/Route1NN/scripts.pory"
	.string "Yaaahhhh!$"

Route1NN_Trigger_GetStarters_Text_1:
# 62 "data/maps/Route1NN/scripts.pory"
	.string "Hoooo!$"

Route1NN_Trigger_GetStarters_Text_2:
# 74 "data/maps/Route1NN/scripts.pory"
	.string "Mrrr!$"

Route1NN_Trigger_GetStarters_Text_3:
# 80 "data/maps/Route1NN/scripts.pory"
	.string "Mraaarrrr!$"

Route1NN_Trigger_GetStarters_Text_4:
# 86 "data/maps/Route1NN/scripts.pory"
	.string "Prrr!$"

Route1NN_Trigger_GetStarters_Text_5:
# 92 "data/maps/Route1NN/scripts.pory"
	.string "Bwark! Bwark!$"

Route1NN_Trigger_GetStarters_Text_6:
# 97 "data/maps/Route1NN/scripts.pory"
	.string "Ya…yah…$"

Route1NN_Trigger_GetStarters_Text_7:
# 126 "data/maps/Route1NN/scripts.pory"
	.string "Kukui$"

Route1NN_Trigger_GetStarters_Text_8:
# 127 "data/maps/Route1NN/scripts.pory"
	.string "Hey there, cousin!\p"
	.string "Hang on, I know you…\n"
	.string "You're {PLAYER}, right?\p"
	.string "You OK?\p"
	.string "I saw you get attacked like that!$"

Route1NN_Trigger_GetStarters_Text_9:
# 135 "data/maps/Route1NN/scripts.pory"
	.string "Yeah, I got a bit of help$"

Route1NN_Trigger_GetStarters_Text_10:
# 135 "data/maps/Route1NN/scripts.pory"
	.string "I was scared spitless!$"

Route1NN_Trigger_GetStarters_Text_11:
# 138 "data/maps/Route1NN/scripts.pory"
	.string "Looks like you did!\p"
	.string "Though I sure didn't expect that,\n"
	.string "yeah…$"

Route1NN_Trigger_GetStarters_Text_12:
# 145 "data/maps/Route1NN/scripts.pory"
	.string "Don't worry, it's totally normal to be scared in a situation like that! But you handled it like a champ!$"

Route1NN_Trigger_GetStarters_Text_13:
# 147 "data/maps/Route1NN/scripts.pory"
	.string "I didn't think these little fellows\n"
	.string "would dash out on their own to help\l"
	.string "save a stranger!\p"
	.string "But I guess I'm getting ahead of\n"
	.string "myself.\p"
	.string "Welcome to Alola, the Pokémon paradise!\p"
	.string "That's what I'm supposed to be\n"
	.string "saying.\p"
	.string "I'm Kukui, yeah. the Pokémon\n"
	.string "Professor.\p"
	.string "People and Pokémon live and work\n"
	.string "together here in Alola, too.\p"
	.string "Don't you ever forget…\p"
	.string "You can go anywhere, yeah, as long\n"
	.string "as you got Pokémon in your corner!\p"
	.string "Wild Pokémon could be lurking in\n"
	.string "the tall grass, yeah, just waiting\l"
	.string "to leap out and bite you, but\l"
	.string "you'll be fine if you've got a\l"
	.string "partner of your own!\p"
	.string "Hey there!\p"
	.string "Here, let me introduce the Pokémon\n"
	.string "that helped you just now.$"

Route1NN_Trigger_GetStarters_Text_14:
# 222 "data/maps/Route1NN/scripts.pory"
	.string "This is the Grass-type Pokémon, Rowlet.$"

Route1NN_Trigger_GetStarters_Text_15:
# 228 "data/maps/Route1NN/scripts.pory"
	.string "Hoo!$"

Route1NN_Trigger_GetStarters_Text_16:
# 242 "data/maps/Route1NN/scripts.pory"
	.string "And the Fire-type Pokémon, Litten.$"

Route1NN_Trigger_GetStarters_Text_17:
# 248 "data/maps/Route1NN/scripts.pory"
	.string "Mrawr.$"

Route1NN_Trigger_GetStarters_Text_18:
# 262 "data/maps/Route1NN/scripts.pory"
	.string "And the Water-type Pokémon Popplio.$"

Route1NN_Trigger_GetStarters_Text_19:
# 268 "data/maps/Route1NN/scripts.pory"
	.string "Bwark?$"

Route1NN_Trigger_GetStarters_Text_20:
# 282 "data/maps/Route1NN/scripts.pory"
	.string "Y'see, the fact of the matter is…\p"
	.string "one of these Pokémon will become\n"
	.string "your first parter, woo!\p"
	.string "Heh…\p"
	.string "Maybe that's why they wanted to save\n"
	.string "you?\p"
	.string "Go on and choose the one you'd like\n"
	.string "to keep as your parter, cousin!$"

Route1NN_Trigger_GetStarters_Text_21:
# 294 "data/maps/Route1NN/scripts.pory"
	.string "Rowlet$"

Route1NN_Trigger_GetStarters_Text_22:
# 294 "data/maps/Route1NN/scripts.pory"
	.string "Litten$"

Route1NN_Trigger_GetStarters_Text_23:
# 294 "data/maps/Route1NN/scripts.pory"
	.string "Popplio$"

Route1NN_Rockruff_Text_0:
# 369 "data/maps/Route1NN/scripts.pory"
	.string "Ruff!$"
