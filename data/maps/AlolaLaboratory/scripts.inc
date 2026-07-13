AlolaLaboratory_MapScripts::
# 2 "data/maps/AlolaLaboratory/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 9 "data/maps/AlolaLaboratory/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 2 "data/maps/AlolaLaboratory/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, TRUE, AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 3 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 4 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_IKITOWN_STATE, 18
	goto_if_gt AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1
	return

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1:
# 5 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_lillie, 14, 17
# 6 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_lillie, MAP_ALOLA_LABORATORY
	return

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/AlolaLaboratory/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 18, AlolaLaboratory_FirstTimeIntro
	.2byte 0


AlolaLaboratory_Kukui::
# 14 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 15 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 16 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 17 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Kukui_Text_1
# 22 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


AlolaLaboratory_Stufful::
# 27 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 28 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 29 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_STUFFUL, 0
# 30 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Stufful_Text_0
# 31 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 32 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


AlolaLaboratory_Snubull::
# 37 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 38 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 39 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_SNUBBULL, 0
# 40 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Snubull_Text_0
# 41 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 42 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


AlolaLaboratory_Rockruff::
# 47 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 48 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 49 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 50 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Rockruff_Text_0
# 51 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 52 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


AlolaLaboratory_FirstTimeIntro::
# 57 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 58 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 19
# 59 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_stufful, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 60 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_snubbull, MOVEMENT_TYPE_WALK_IN_PLACE_UP
# 61 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_0
# 62 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 63 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 65 "data/maps/AlolaLaboratory/scripts.pory"
	showobjectat lab_lillie, MAP_ALOLA_LABORATORY
# 66 "data/maps/AlolaLaboratory/scripts.pory"
	special SpawnCameraObject
# 67 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_2
# 68 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 69 "data/maps/AlolaLaboratory/scripts.pory"
	delay 60
# 70 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_3
# 71 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 72 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_4
# 73 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_5
# 74 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement LOCALID_PLAYER, AlolaLaboratory_FirstTimeIntro_Movement_5
# 75 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 76 "data/maps/AlolaLaboratory/scripts.pory"
	delay 60
# 77 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 78 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_6
# 79 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 80 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 81 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 82 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_PIN
# 83 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_7
# 84 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_8
# 85 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 86 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 87 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_9
# 88 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 89 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 90 "data/maps/AlolaLaboratory/scripts.pory"
	special RemoveCameraObject
# 91 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 92 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 93 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_2
# 103 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_10
# 104 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 105 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 106 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 107 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 108 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_1, MSGBOX_AUTOCLOSE
AlolaLaboratory_FirstTimeIntro_1:
# 111 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_11
# 112 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_12
# 113 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 114 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_2
# 115 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_3
# 117 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 118 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_4, MSGBOX_AUTOCLOSE
# 124 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement LOCALID_PLAYER, AlolaLaboratory_FirstTimeIntro_Movement_13
# 125 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 126 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 127 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 128 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 129 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 130 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_5, MSGBOX_AUTOCLOSE
# 132 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_PIN
# 133 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_14
# 134 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 135 "data/maps/AlolaLaboratory/scripts.pory"
	delay 100
# 136 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 137 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_6
# 141 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_2
# 142 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_7
# 143 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_15
# 144 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 145 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 146 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_8
# 151 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_FirstTimeIntro_Text_9, AlolaLaboratory_FirstTimeIntro_Text_10
# 152 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_6
# 165 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_16
# 166 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 167 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_2
# 168 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_11
AlolaLaboratory_FirstTimeIntro_5:
# 175 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 176 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 177 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_12, MSGBOX_AUTOCLOSE
# 193 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_18
# 194 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 195 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 196 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 197 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 198 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_CLICK
# 199 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 200 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 201 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_WHITE
# 202 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_M_MEGA_KICK
# 203 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 204 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_M_SELF_DESTRUCT
# 205 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 206 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_BALL_OPEN
# 207 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 208 "data/maps/AlolaLaboratory/scripts.pory"
	showobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 209 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 14, 11
# 210 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 211 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 212 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 213 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 214 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 215 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_FirstTimeIntro_Movement_17
# 216 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 217 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_13
# 218 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 219 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 220 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 221 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 222 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_14
# 224 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 225 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 226 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_FirstTimeIntro_Movement_17
# 227 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 228 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_15, MSGBOX_AUTOCLOSE
# 229 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 230 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 231 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 232 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 233 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 234 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_16
# 241 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 242 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 243 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_FirstTimeIntro_Movement_17
# 244 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 245 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_17, MSGBOX_AUTOCLOSE
# 246 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 247 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 248 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 249 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_WHITE
# 250 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 251 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 252 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 253 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 254 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_CLICK
# 255 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 256 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 15, 17
# 257 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 258 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 2
# 259 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 260 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 261 "data/maps/AlolaLaboratory/scripts.pory"
	rotommenudisplay AlolaLaboratory_FirstTimeIntro_Text_18
# 262 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_15
# 263 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 264 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 265 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_19
# 271 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_16
# 272 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 273 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_2
# 274 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_20
# 275 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 276 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 277 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 278 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 279 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_10
# 289 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_22
AlolaLaboratory_FirstTimeIntro_9:
# 295 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_FirstTimeIntro_Text_23, AlolaLaboratory_FirstTimeIntro_Text_24
# 296 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_14
# 308 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 309 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 310 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 311 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_26
AlolaLaboratory_FirstTimeIntro_13:
# 318 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 319 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_27
# 326 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_FirstTimeIntro_Text_28, AlolaLaboratory_FirstTimeIntro_Text_29
# 327 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_18
# 346 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_10
# 347 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 348 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 349 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 350 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 351 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 352 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 353 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_30
AlolaLaboratory_FirstTimeIntro_17:
# 363 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_16
# 364 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 365 "data/maps/AlolaLaboratory/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 366 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_2
# 367 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_31
# 380 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 381 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 382 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 383 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 384 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_22
# 394 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_33
AlolaLaboratory_FirstTimeIntro_21:
# 400 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_2
# 401 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_34, MSGBOX_AUTOCLOSE
# 403 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_9
# 404 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 405 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_EXIT
# 406 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_lillie, MAP_ALOLA_LABORATORY
# 407 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 408 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_11
# 409 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_rockruff, MOVEMENT_TYPE_LOOK_AROUND
# 410 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_stufful, MOVEMENT_TYPE_LOOK_AROUND
# 411 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_snubbull, MOVEMENT_TYPE_LOOK_AROUND
# 412 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end

AlolaLaboratory_FirstTimeIntro_2:
# 94 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_10
# 95 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 96 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 97 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 98 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 99 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_0, MSGBOX_AUTOCLOSE
	goto AlolaLaboratory_FirstTimeIntro_1

AlolaLaboratory_FirstTimeIntro_6:
# 153 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_16
# 154 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 155 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_2
# 156 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_11
	goto AlolaLaboratory_FirstTimeIntro_5

AlolaLaboratory_FirstTimeIntro_10:
# 281 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_21
	goto AlolaLaboratory_FirstTimeIntro_9

AlolaLaboratory_FirstTimeIntro_14:
# 297 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 298 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 299 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 300 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_25
	goto AlolaLaboratory_FirstTimeIntro_13

AlolaLaboratory_FirstTimeIntro_18:
# 328 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_10
# 329 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 330 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 331 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 332 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 333 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 334 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 335 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_30
	goto AlolaLaboratory_FirstTimeIntro_17

AlolaLaboratory_FirstTimeIntro_22:
# 386 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_32
	goto AlolaLaboratory_FirstTimeIntro_21


# 61 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_0:
# 61 "data/maps/AlolaLaboratory/scripts.pory"
	face_right
	step_end

# 62 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_1:
# 62 "data/maps/AlolaLaboratory/scripts.pory"
	face_left
	step_end

# 67 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_2:
# 67 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
# 67 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
# 67 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
# 67 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
	step_end

# 70 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_3:
# 70 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
# 70 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
# 70 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
# 70 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
	step_end

# 72 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_4:
# 72 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 72 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
	step_end

# 73 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_5:
# 73 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 73 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 73 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
	step_end

# 78 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_6:
# 78 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_right
# 78 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_right
	step_end

# 83 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_7:
# 83 "data/maps/AlolaLaboratory/scripts.pory"
	emote_exclamation_mark
# 83 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 84 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_8:
# 84 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 84 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 84 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 87 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_9:
# 87 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
# 87 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
# 87 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
	step_end

# 94 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_10:
# 94 "data/maps/AlolaLaboratory/scripts.pory"
	jump_in_place_down
# 94 "data/maps/AlolaLaboratory/scripts.pory"
	jump_in_place_down
	step_end

# 111 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_11:
# 111 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
	step_end

# 112 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_12:
# 112 "data/maps/AlolaLaboratory/scripts.pory"
	delay_8
# 112 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 124 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_13:
# 124 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 124 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 124 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 124 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 124 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 133 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_14:
# 133 "data/maps/AlolaLaboratory/scripts.pory"
	emote_question_mark
	step_end

# 143 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_15:
# 143 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 153 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_16:
# 153 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 153 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 175 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_17:
# 175 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
# 175 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
	step_end

# 193 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_18:
# 193 "data/maps/AlolaLaboratory/scripts.pory"
	face_up
# 193 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 193 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 193 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 193 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 193 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

AlolaLaboratory_Kukui_Text_0:
# 16 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Kukui$"

AlolaLaboratory_Kukui_Text_1:
# 17 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Pokémon are my totally necessary\n"
	.string "partners in my research.\p"
	.string "Plus we all live here together.\n"
	.string "I guess I'd have to call them family!$"

AlolaLaboratory_Stufful_Text_0:
# 30 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Ayoo!$"

AlolaLaboratory_Snubull_Text_0:
# 40 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Wroo!$"

AlolaLaboratory_Rockruff_Text_0:
# 50 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Wroof!$"

AlolaLaboratory_FirstTimeIntro_Text_0:
# 99 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "Thanks for getting him for me, Lillie!$"

AlolaLaboratory_FirstTimeIntro_Text_1:
# 108 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "Thanks for getting her for me, Lillie!$"

AlolaLaboratory_FirstTimeIntro_Text_2:
# 114 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie$"

AlolaLaboratory_FirstTimeIntro_Text_3:
# 115 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Of course. However I can be a help…\n"
	.string "I am supposed to be your assistant.$"

AlolaLaboratory_FirstTimeIntro_Text_4:
# 118 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rockruff's moves were just so stylin',\n"
	.string "and I was making good progress with\l"
	.string "my research.\p"
	.string "Say, {PLAYER}, lemme see your Rotom\n"
	.string "Phone for a second, yeah?$"

AlolaLaboratory_FirstTimeIntro_Text_5:
# 130 "data/maps/AlolaLaboratory/scripts.pory"
	.string "So what do you think of the place?\n"
	.string "Not bad right?$"

AlolaLaboratory_FirstTimeIntro_Text_6:
# 137 "data/maps/AlolaLaboratory/scripts.pory"
	.string "But that's not why I called you here,\n"
	.string "eh?\p"
	.string "Here! It finally arrived!$"

AlolaLaboratory_FirstTimeIntro_Text_7:
# 142 "data/maps/AlolaLaboratory/scripts.pory"
	.string "“It”…?$"

AlolaLaboratory_FirstTimeIntro_Text_8:
# 146 "data/maps/AlolaLaboratory/scripts.pory"
	.string "What's wrong, Lillie? Dont make me\n"
	.string "do all the talking?\p"
	.string "See, there's this Pokémon inside your\n"
	.string "Phone called Rotom…$"

AlolaLaboratory_FirstTimeIntro_Text_9:
# 151 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Really?$"

AlolaLaboratory_FirstTimeIntro_Text_10:
# 151 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rotom?$"

AlolaLaboratory_FirstTimeIntro_Text_11:
# 156 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Oh, I can tell you about Rotom.\p"
	.string "It's a peculiar Pokémon, with a body\n"
	.string "made up of something like\l"
	.string "electricity.\l"
	.string "It can take up residence in machines.$"

AlolaLaboratory_FirstTimeIntro_Text_12:
# 177 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Yeah, buddy! And to put that crazy skill\n"
	.string "of Rotom's to work…\p"
	.string "It's the next generation of Phones, but\n"
	.string "it's only complete once Rotom has\l"
	.string "gone into this body specially\l"
	.string "developed for it!\p"
	.string "A whole new way for people and Pokémon\n"
	.string "to communicate. Woo!\p"
	.string "And there's only a few of these\n"
	.string "beauties out in the world so far!\p"
	.string "And now if I power up your Rotom Phone\n"
	.string "with the parts that I just got in…$"

AlolaLaboratory_FirstTimeIntro_Text_13:
# 217 "data/maps/AlolaLaboratory/scripts.pory"
	.string "…Kzzzt?$"

AlolaLaboratory_FirstTimeIntro_Text_14:
# 222 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey now! Sorry 'bout that, Rotom.\n"
	.string "Guess I surprised you?$"

AlolaLaboratory_FirstTimeIntro_Text_15:
# 228 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Zz-zzt…$"

AlolaLaboratory_FirstTimeIntro_Text_16:
# 234 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rotom!\p"
	.string "Here, boy!\n"
	.string "I powered up your favorite Phone!\p"
	.string "Give {PLAYER} here a Helping Hand,\n"
	.string "yeah?$"

AlolaLaboratory_FirstTimeIntro_Text_17:
# 245 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Kzzzt…$"

AlolaLaboratory_FirstTimeIntro_Text_18:
# 261 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Uh, hey there! P-pleasure to meet you!\nI-I'm not nervouzzz or anything.$"

AlolaLaboratory_FirstTimeIntro_Text_19:
# 265 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Check it out, {PLAYER}!\n"
	.string "Now Rotom can talk right to you!\p"
	.string "It may take it a little while to get\n"
	.string "used to its new job, but I'd say\l"
	.string "Rotom's taken a liking to you!$"

AlolaLaboratory_FirstTimeIntro_Text_20:
# 274 "data/maps/AlolaLaboratory/scripts.pory"
	.string "And this will help how exactly?$"

AlolaLaboratory_FirstTimeIntro_Text_21:
# 281 "data/maps/AlolaLaboratory/scripts.pory"
	.string "{PLAYER} hasn't been here in Alola\n"
	.string "too long yet.\p"
	.string "So I decided to give him this special\n"
	.string "Phone to help him navigate around.$"

AlolaLaboratory_FirstTimeIntro_Text_22:
# 289 "data/maps/AlolaLaboratory/scripts.pory"
	.string "{PLAYER} hasn't been here in Alola\n"
	.string "too long yet.\p"
	.string "So I decided to give her this special\n"
	.string "Phone to help her navigate around.$"

AlolaLaboratory_FirstTimeIntro_Text_23:
# 295 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Thank you!$"

AlolaLaboratory_FirstTimeIntro_Text_24:
# 295 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hi, Rotom!$"

AlolaLaboratory_FirstTimeIntro_Text_25:
# 300 "data/maps/AlolaLaboratory/scripts.pory"
	.string "You can ask Rotom for directions by\n"
	.string "opening the Rotom Phone and pressing {R_BUTTON}.\p"
	.string "You can also press the Rotom Reality\n"
	.string "feature to open the {COLOR RED}Town Map{COLOR DARK_GRAY}!$"

AlolaLaboratory_FirstTimeIntro_Text_26:
# 311 "data/maps/AlolaLaboratory/scripts.pory"
	.string "You can see ask Rotom for directions\n"
	.string "by opening the Rotom Phone and\l"
	.string "pressing {R_BUTTON}.\p"
	.string "You can also press the Rotom Reality\n"
	.string "feature to open the {COLOR RED}Town Map{COLOR DARK_GRAY}!$"

AlolaLaboratory_FirstTimeIntro_Text_27:
# 319 "data/maps/AlolaLaboratory/scripts.pory"
	.string "So, {PLAYER}, I'm leaving this Rotom\n"
	.string "Phone in your hands!\p"
	.string "Rotom, you look after {PLAYER}, yeah?\p"
	.string "All right then, {PLAYER}!\n"
	.string "Get a move on!$"

AlolaLaboratory_FirstTimeIntro_Text_28:
# 326 "data/maps/AlolaLaboratory/scripts.pory"
	.string "OK!$"

AlolaLaboratory_FirstTimeIntro_Text_29:
# 326 "data/maps/AlolaLaboratory/scripts.pory"
	.string "What?$"

AlolaLaboratory_FirstTimeIntro_Text_30:
# 335 "data/maps/AlolaLaboratory/scripts.pory"
	.string "To the Trainers' School!\p"
	.string "You've gotta learn the basics of being\n"
	.string "a Pokémon Trainer through Pokémon\l"
	.string "battling.\p"
	.string "It's a long road to becoming the island\n"
	.string "challenge champion, and the\l"
	.string "Trainers' School is the first step!$"

AlolaLaboratory_FirstTimeIntro_Text_31:
# 367 "data/maps/AlolaLaboratory/scripts.pory"
	.string "So this is how the people of Alola\n"
	.string "connect with the world around them.\p"
	.string "And then there's the way that you and\n"
	.string "{STR_VAR_1} both chose one another.\p"
	.string "And now with Rotom helping you out as\n"
	.string "well…\p"
	.string "Even Nebby likes you! I guess there's\n"
	.string "something about you that makes\l"
	.string "Pokémon feel comfortable when\l"
	.string "they're by your side.$"

AlolaLaboratory_FirstTimeIntro_Text_32:
# 386 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie!\n"
	.string "You take care of {PLAYER}, yeah?\p"
	.string "Until he gets used to Rotom,\n"
	.string "help him find his way around!$"

AlolaLaboratory_FirstTimeIntro_Text_33:
# 394 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie!\n"
	.string "You take care of {PLAYER}, yeah?\p"
	.string "Until she gets used to Rotom,\n"
	.string "help her find her way around!$"

AlolaLaboratory_FirstTimeIntro_Text_34:
# 401 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Of course, Professor Kukui!\n"
	.string "I'll wait outside.$"
