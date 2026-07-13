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
	hideobjectat lab_hau, MAP_ALOLA_LABORATORY
# 4 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 5 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_IKITOWN_STATE, 18
	goto_if_gt AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1
	return

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1:
# 6 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_lillie, MAP_ALOLA_LABORATORY
	return

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/AlolaLaboratory/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 18, AlolaLaboratory_FirstTimeIntro
	.2byte 0


AlolaLaboratory_FirstTimeIntro::
# 14 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 15 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 19
# 16 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_stufful, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 17 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_snubbull, MOVEMENT_TYPE_WALK_IN_PLACE_UP
# 18 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_0
# 19 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 20 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 22 "data/maps/AlolaLaboratory/scripts.pory"
	addobject lab_lillie
# 23 "data/maps/AlolaLaboratory/scripts.pory"
	special SpawnCameraObject
# 24 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_2
# 25 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 26 "data/maps/AlolaLaboratory/scripts.pory"
	delay 60
# 27 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_3
# 28 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 29 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_4
# 30 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_5
# 31 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement LOCALID_PLAYER, AlolaLaboratory_FirstTimeIntro_Movement_5
# 32 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 33 "data/maps/AlolaLaboratory/scripts.pory"
	delay 60
# 34 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 35 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_6
# 36 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 37 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 38 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 39 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_PIN
# 40 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_7
# 41 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_8
# 42 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 43 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 44 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_9
# 45 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 46 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 47 "data/maps/AlolaLaboratory/scripts.pory"
	special RemoveCameraObject
# 48 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 49 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 50 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_2
# 60 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_10
# 61 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 62 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 63 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 64 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 65 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_2, MSGBOX_AUTOCLOSE
AlolaLaboratory_FirstTimeIntro_1:
# 68 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_11
# 69 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_12
# 70 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 71 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_3
# 72 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_4, MSGBOX_AUTOCLOSE
# 74 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 75 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_5, MSGBOX_AUTOCLOSE
# 81 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement LOCALID_PLAYER, AlolaLaboratory_FirstTimeIntro_Movement_13
# 82 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 83 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 84 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 85 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 86 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 87 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_6, MSGBOX_AUTOCLOSE
# 89 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 90 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_PIN
# 91 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_14
# 92 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 93 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 94 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 95 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_7
# 99 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_3
# 100 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_8
# 101 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_15
# 102 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 103 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 104 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_9
# 109 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_FirstTimeIntro_Text_10, AlolaLaboratory_FirstTimeIntro_Text_11
# 110 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_6
# 123 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_16
# 124 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 125 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_3
# 126 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_12
AlolaLaboratory_FirstTimeIntro_5:
# 133 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 134 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 135 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_13
# 148 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_14, MSGBOX_AUTOCLOSE
# 150 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_18
# 151 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 152 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 153 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 154 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 155 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_CLICK
# 156 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 157 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 158 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_WHITE
# 159 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_M_MEGA_KICK
# 160 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 161 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_M_SELF_DESTRUCT
# 162 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 163 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_BALL_OPEN
# 164 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 165 "data/maps/AlolaLaboratory/scripts.pory"
	showobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 166 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 14, 11
# 167 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 168 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 169 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 170 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 171 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 172 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_FirstTimeIntro_Movement_17
# 173 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 174 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_15
# 175 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 176 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 177 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 178 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 179 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_16
# 181 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 182 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 183 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_FirstTimeIntro_Movement_17
# 184 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 185 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_17, MSGBOX_AUTOCLOSE
# 186 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 187 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 188 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 189 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 190 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_18
# 197 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 198 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 199 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_FirstTimeIntro_Movement_17
# 200 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 201 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_19, MSGBOX_AUTOCLOSE
# 202 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 203 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 204 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 205 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_WHITE
# 206 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 207 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 208 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 209 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 210 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_CLICK
# 211 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 212 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 15, 17
# 213 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 214 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 2
# 215 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 216 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 217 "data/maps/AlolaLaboratory/scripts.pory"
	rotommenudisplay AlolaLaboratory_FirstTimeIntro_Text_20
# 218 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_15
# 219 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 220 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 221 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_21
# 227 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_16
# 228 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 229 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_3
# 230 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_22
# 231 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 232 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 233 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 234 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 235 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_10
# 245 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_24
AlolaLaboratory_FirstTimeIntro_9:
# 251 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_FirstTimeIntro_Text_25, AlolaLaboratory_FirstTimeIntro_Text_26
# 252 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_14
# 265 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 266 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 267 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 268 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_27
AlolaLaboratory_FirstTimeIntro_13:
# 275 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end

AlolaLaboratory_FirstTimeIntro_2:
# 51 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_10
# 52 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 53 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 54 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 55 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 56 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_1, MSGBOX_AUTOCLOSE
	goto AlolaLaboratory_FirstTimeIntro_1

AlolaLaboratory_FirstTimeIntro_6:
# 111 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_16
# 112 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 113 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_3
# 114 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_12
	goto AlolaLaboratory_FirstTimeIntro_5

AlolaLaboratory_FirstTimeIntro_10:
# 237 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_23
	goto AlolaLaboratory_FirstTimeIntro_9

AlolaLaboratory_FirstTimeIntro_14:
# 253 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 254 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 255 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 256 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_27
	goto AlolaLaboratory_FirstTimeIntro_13


# 18 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_0:
# 18 "data/maps/AlolaLaboratory/scripts.pory"
	face_right
	step_end

# 19 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_1:
# 19 "data/maps/AlolaLaboratory/scripts.pory"
	face_left
	step_end

# 24 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_2:
# 24 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
# 24 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
# 24 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
# 24 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
	step_end

# 27 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_3:
# 27 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
# 27 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
# 27 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
# 27 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
	step_end

# 29 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_4:
# 29 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 29 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
	step_end

# 30 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_5:
# 30 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 30 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 30 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
	step_end

# 35 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_6:
# 35 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_right
# 35 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_right
	step_end

# 40 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_7:
# 40 "data/maps/AlolaLaboratory/scripts.pory"
	emote_exclamation_mark
# 40 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 41 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_8:
# 41 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 41 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 41 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 44 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_9:
# 44 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
# 44 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
# 44 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
	step_end

# 51 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_10:
# 51 "data/maps/AlolaLaboratory/scripts.pory"
	jump_in_place_down
# 51 "data/maps/AlolaLaboratory/scripts.pory"
	jump_in_place_down
	step_end

# 68 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_11:
# 68 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
	step_end

# 69 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_12:
# 69 "data/maps/AlolaLaboratory/scripts.pory"
	delay_8
# 69 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 81 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_13:
# 81 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 81 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 81 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 81 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 91 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_14:
# 91 "data/maps/AlolaLaboratory/scripts.pory"
	emote_question_mark
	step_end

# 101 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_15:
# 101 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 111 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_16:
# 111 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 111 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 133 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_17:
# 133 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
# 133 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
	step_end

# 150 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_18:
# 150 "data/maps/AlolaLaboratory/scripts.pory"
	face_up
# 150 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 150 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 150 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 150 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 150 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

AlolaLaboratory_FirstTimeIntro_Text_0:
# 48 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Kukui$"

AlolaLaboratory_FirstTimeIntro_Text_1:
# 56 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "Thanks for getting him for me, Lillie!$"

AlolaLaboratory_FirstTimeIntro_Text_2:
# 65 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "Thanks for getting her for me, Lillie!$"

AlolaLaboratory_FirstTimeIntro_Text_3:
# 71 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie$"

AlolaLaboratory_FirstTimeIntro_Text_4:
# 72 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Of course. However I can be a help…\n"
	.string "I am supposed to be your assistant.$"

AlolaLaboratory_FirstTimeIntro_Text_5:
# 75 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rockruff's moves were just so stylin',\n"
	.string "and I was making good progress with\l"
	.string "my research.\p"
	.string "Say, {PLAYER}, lemme see your Rotom\n"
	.string "Phone for a second, yeah?$"

AlolaLaboratory_FirstTimeIntro_Text_6:
# 87 "data/maps/AlolaLaboratory/scripts.pory"
	.string "So what do you think of the place?\n"
	.string "Not bad right?$"

AlolaLaboratory_FirstTimeIntro_Text_7:
# 95 "data/maps/AlolaLaboratory/scripts.pory"
	.string "But that's not why I called you here,\n"
	.string "eh?\p"
	.string "Here! It finally arrived!$"

AlolaLaboratory_FirstTimeIntro_Text_8:
# 100 "data/maps/AlolaLaboratory/scripts.pory"
	.string "“It”…?$"

AlolaLaboratory_FirstTimeIntro_Text_9:
# 104 "data/maps/AlolaLaboratory/scripts.pory"
	.string "What's wrong, Lillie? Dont make me\n"
	.string "do all the talking?\p"
	.string "See, there's this Pokémon inside your\n"
	.string "Phone called Rotom…$"

AlolaLaboratory_FirstTimeIntro_Text_10:
# 109 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Really?$"

AlolaLaboratory_FirstTimeIntro_Text_11:
# 109 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rotom?$"

AlolaLaboratory_FirstTimeIntro_Text_12:
# 114 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Oh, I can tell you about Rotom.\p"
	.string "It's a peculiar Pokémon, with a body\n"
	.string "made up of something like\l"
	.string "electricity.\l"
	.string "It can take up residence in machines.$"

AlolaLaboratory_FirstTimeIntro_Text_13:
# 135 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Yeah, buddy! And to put that crazy skill\n"
	.string "of Rotom's to work…\p"
	.string "It's the next generation of Phones, but\n"
	.string "it's only complete once Rotom has\l"
	.string "gone into this body specially\l"
	.string "developed for it!\p"
	.string "A whole new way for people and Pokémon\n"
	.string "to communicate. Woo!\p"
	.string "And there's only a few of these\n"
	.string "beauties out in the world so far!$"

AlolaLaboratory_FirstTimeIntro_Text_14:
# 148 "data/maps/AlolaLaboratory/scripts.pory"
	.string "And now if I power up your Rotom Phone\n"
	.string "with the parts that I just got in…$"

AlolaLaboratory_FirstTimeIntro_Text_15:
# 174 "data/maps/AlolaLaboratory/scripts.pory"
	.string "…Kzzzt?$"

AlolaLaboratory_FirstTimeIntro_Text_16:
# 179 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey now! Sorry 'bout that, Rotom.\n"
	.string "Guess I surprised you?$"

AlolaLaboratory_FirstTimeIntro_Text_17:
# 185 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Zz-zzt…$"

AlolaLaboratory_FirstTimeIntro_Text_18:
# 190 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rotom!\p"
	.string "Here, boy!\n"
	.string "I powered up your favorite Phone!\p"
	.string "Give {PLAYER} here a Helping Hand,\n"
	.string "yeah?$"

AlolaLaboratory_FirstTimeIntro_Text_19:
# 201 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Kzzzt…$"

AlolaLaboratory_FirstTimeIntro_Text_20:
# 217 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Uh, hey there! P-pleasure to meet you!\nI-I'm not nervouzzz or anything.$"

AlolaLaboratory_FirstTimeIntro_Text_21:
# 221 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Check it out, {PLAYER}!\n"
	.string "Now Rotom can talk right to you!\p"
	.string "It may take it a little while to get\n"
	.string "used to its new job, but I'd say\l"
	.string "Rotom's taken a liking to you!$"

AlolaLaboratory_FirstTimeIntro_Text_22:
# 230 "data/maps/AlolaLaboratory/scripts.pory"
	.string "And this will help how exactly?$"

AlolaLaboratory_FirstTimeIntro_Text_23:
# 237 "data/maps/AlolaLaboratory/scripts.pory"
	.string "{PLAYER} hasn't been here in Alola\n"
	.string "too long yet.\p"
	.string "So I decided to give him this special\n"
	.string "Phone to help him navigate around.$"

AlolaLaboratory_FirstTimeIntro_Text_24:
# 245 "data/maps/AlolaLaboratory/scripts.pory"
	.string "{PLAYER} hasn't been here in Alola\n"
	.string "too long yet.\p"
	.string "So I decided to give her this special\n"
	.string "Phone to help her navigate around.$"

AlolaLaboratory_FirstTimeIntro_Text_25:
# 251 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Thank you!$"

AlolaLaboratory_FirstTimeIntro_Text_26:
# 251 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hi, Rotom!$"

AlolaLaboratory_FirstTimeIntro_Text_27:
# 256 "data/maps/AlolaLaboratory/scripts.pory"
	.string "You can see ask Rotom for directions\n"
	.string "by opening the Rotom Phone and\l"
	.string "pressing {R_BUTTON}.\p"
	.string "You can also press the Rotom Reality\n"
	.string "feature to open the {COLOR RED}Town Map{COLOR DARK_GRAY}!$"
