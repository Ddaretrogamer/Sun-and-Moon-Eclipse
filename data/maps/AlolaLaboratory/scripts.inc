AlolaLaboratory_MapScripts::
# 2 "data/maps/AlolaLaboratory/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 6 "data/maps/AlolaLaboratory/scripts.pory"
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
	return

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/AlolaLaboratory/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 18, AlolaLaboratory_FirstTimeIntro
	.2byte 0


AlolaLaboratory_FirstTimeIntro::
# 11 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 12 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_stufful, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 13 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_snubbull, MOVEMENT_TYPE_WALK_IN_PLACE_UP
# 14 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_0
# 15 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 16 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 18 "data/maps/AlolaLaboratory/scripts.pory"
	addobject lab_lillie
# 19 "data/maps/AlolaLaboratory/scripts.pory"
	special SpawnCameraObject
# 20 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_2
# 21 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 22 "data/maps/AlolaLaboratory/scripts.pory"
	delay 60
# 23 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_3
# 24 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 25 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_4
# 26 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_5
# 27 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement LOCALID_PLAYER, AlolaLaboratory_FirstTimeIntro_Movement_5
# 28 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 29 "data/maps/AlolaLaboratory/scripts.pory"
	delay 60
# 30 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 31 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_6
# 32 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 33 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 34 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 35 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_PIN
# 36 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_7
# 37 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_8
# 38 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 39 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 40 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AlolaLaboratory_FirstTimeIntro_Movement_9
# 41 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 42 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 43 "data/maps/AlolaLaboratory/scripts.pory"
	special RemoveCameraObject
# 44 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 45 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 46 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_2
# 56 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_10
# 57 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 58 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 59 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 60 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 61 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_2, MSGBOX_AUTOCLOSE
AlolaLaboratory_FirstTimeIntro_1:
# 64 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_11
# 65 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_12
# 66 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 67 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_3
# 68 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_4, MSGBOX_AUTOCLOSE
# 70 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 71 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_5, MSGBOX_AUTOCLOSE
# 77 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement LOCALID_PLAYER, AlolaLaboratory_FirstTimeIntro_Movement_13
# 78 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 79 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 80 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 81 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 82 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 83 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_6, MSGBOX_AUTOCLOSE
# 85 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 86 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_PIN
# 87 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_14
# 88 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 89 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 90 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 91 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_7
# 95 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_3
# 96 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_8
# 97 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_15
# 98 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 99 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 100 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_9
# 105 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_FirstTimeIntro_Text_10, AlolaLaboratory_FirstTimeIntro_Text_11
# 106 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_6
# 119 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_16
# 120 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 121 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_3
# 122 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_12
AlolaLaboratory_FirstTimeIntro_5:
# 129 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 130 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 131 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_13
# 144 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_14, MSGBOX_AUTOCLOSE
# 146 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_18
# 147 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 148 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 149 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 150 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 151 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_CLICK
# 152 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 153 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 154 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_WHITE
# 155 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_M_MEGA_KICK
# 156 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 157 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_M_SELF_DESTRUCT
# 158 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 159 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_BALL_OPEN
# 160 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 161 "data/maps/AlolaLaboratory/scripts.pory"
	showobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 162 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 14, 11
# 163 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 164 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 165 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 166 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 167 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 168 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_FirstTimeIntro_Movement_17
# 169 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 170 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_15
# 171 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 172 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 173 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 174 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 175 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_16
# 177 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 178 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 179 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_FirstTimeIntro_Movement_17
# 180 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 181 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_17, MSGBOX_AUTOCLOSE
# 182 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 183 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 184 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 185 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 186 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_18
# 193 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 194 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 195 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_FirstTimeIntro_Movement_17
# 196 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 197 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_19, MSGBOX_AUTOCLOSE
# 198 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 199 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 200 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 201 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_WHITE
# 202 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 203 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 204 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 205 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 206 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_CLICK
# 207 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 208 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 15, 17
# 209 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 210 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 2
# 211 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 213 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_15
# 214 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 215 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 216 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_20
# 222 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_16
# 223 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 224 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_3
# 225 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_21
# 226 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 227 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 228 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 229 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 230 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_10
# 240 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_23
AlolaLaboratory_FirstTimeIntro_9:
# 246 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_FirstTimeIntro_Text_24, AlolaLaboratory_FirstTimeIntro_Text_25
# 247 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_14
# 260 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 261 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 262 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 263 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_26
AlolaLaboratory_FirstTimeIntro_13:
# 270 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 19
# 271 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end

AlolaLaboratory_FirstTimeIntro_2:
# 47 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_10
# 48 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 49 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 50 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 51 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 52 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_1, MSGBOX_AUTOCLOSE
	goto AlolaLaboratory_FirstTimeIntro_1

AlolaLaboratory_FirstTimeIntro_6:
# 107 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_16
# 108 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 109 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_3
# 110 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_12
	goto AlolaLaboratory_FirstTimeIntro_5

AlolaLaboratory_FirstTimeIntro_10:
# 232 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_22
	goto AlolaLaboratory_FirstTimeIntro_9

AlolaLaboratory_FirstTimeIntro_14:
# 248 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_17
# 249 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 250 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_FirstTimeIntro_Text_0
# 251 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_26
	goto AlolaLaboratory_FirstTimeIntro_13


# 14 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_0:
# 14 "data/maps/AlolaLaboratory/scripts.pory"
	face_right
	step_end

# 15 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_1:
# 15 "data/maps/AlolaLaboratory/scripts.pory"
	face_left
	step_end

# 20 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_2:
# 20 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
# 20 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
# 20 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
# 20 "data/maps/AlolaLaboratory/scripts.pory"
	walk_left
	step_end

# 23 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_3:
# 23 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
# 23 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
# 23 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
# 23 "data/maps/AlolaLaboratory/scripts.pory"
	walk_diag_northeast
	step_end

# 25 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_4:
# 25 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 25 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
	step_end

# 26 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_5:
# 26 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 26 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 26 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
	step_end

# 31 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_6:
# 31 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_right
# 31 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_right
	step_end

# 36 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_7:
# 36 "data/maps/AlolaLaboratory/scripts.pory"
	emote_exclamation_mark
# 36 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 37 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_8:
# 37 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 37 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 37 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 40 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_9:
# 40 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
# 40 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
# 40 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
	step_end

# 47 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_10:
# 47 "data/maps/AlolaLaboratory/scripts.pory"
	jump_in_place_down
# 47 "data/maps/AlolaLaboratory/scripts.pory"
	jump_in_place_down
	step_end

# 64 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_11:
# 64 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
	step_end

# 65 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_12:
# 65 "data/maps/AlolaLaboratory/scripts.pory"
	delay_8
# 65 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 77 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_13:
# 77 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 77 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 77 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 77 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 87 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_14:
# 87 "data/maps/AlolaLaboratory/scripts.pory"
	emote_question_mark
	step_end

# 97 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_15:
# 97 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 107 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_16:
# 107 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 107 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 129 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_17:
# 129 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
# 129 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
	step_end

# 146 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_18:
# 146 "data/maps/AlolaLaboratory/scripts.pory"
	face_up
# 146 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 146 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 146 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 146 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 146 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

AlolaLaboratory_FirstTimeIntro_Text_0:
# 44 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Kukui$"

AlolaLaboratory_FirstTimeIntro_Text_1:
# 52 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "Thanks for getting him for me, Lillie!$"

AlolaLaboratory_FirstTimeIntro_Text_2:
# 61 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "Thanks for getting her for me, Lillie!$"

AlolaLaboratory_FirstTimeIntro_Text_3:
# 67 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie$"

AlolaLaboratory_FirstTimeIntro_Text_4:
# 68 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Of course. However I can be a help…\n"
	.string "I am supposed to be your assistant.$"

AlolaLaboratory_FirstTimeIntro_Text_5:
# 71 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rockruff's moves were just so stylin',\n"
	.string "and I was making good progress with\l"
	.string "my research.\p"
	.string "Say, {PLAYER}, lemme see your Rotom\n"
	.string "Phone for a second, yeah?$"

AlolaLaboratory_FirstTimeIntro_Text_6:
# 83 "data/maps/AlolaLaboratory/scripts.pory"
	.string "So what do you think of the place?\n"
	.string "Not bad right?$"

AlolaLaboratory_FirstTimeIntro_Text_7:
# 91 "data/maps/AlolaLaboratory/scripts.pory"
	.string "But that's not why I called you here,\n"
	.string "eh?\p"
	.string "Here! It finally arrived!$"

AlolaLaboratory_FirstTimeIntro_Text_8:
# 96 "data/maps/AlolaLaboratory/scripts.pory"
	.string "“It”…?$"

AlolaLaboratory_FirstTimeIntro_Text_9:
# 100 "data/maps/AlolaLaboratory/scripts.pory"
	.string "What's wrong, Lillie? Dont make me\n"
	.string "do all the talking?\p"
	.string "See, there's this Pokémon inside your\n"
	.string "Phone called Rotom…$"

AlolaLaboratory_FirstTimeIntro_Text_10:
# 105 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Really?$"

AlolaLaboratory_FirstTimeIntro_Text_11:
# 105 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rotom?$"

AlolaLaboratory_FirstTimeIntro_Text_12:
# 110 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Oh, I can tell you about Rotom.\p"
	.string "It's a peculiar Pokémon, with a body\n"
	.string "made up of something like\l"
	.string "electricity.\l"
	.string "It can take up residence in machines.$"

AlolaLaboratory_FirstTimeIntro_Text_13:
# 131 "data/maps/AlolaLaboratory/scripts.pory"
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
# 144 "data/maps/AlolaLaboratory/scripts.pory"
	.string "And now if I power up your Rotom Phone\n"
	.string "with the parts that I just got in…$"

AlolaLaboratory_FirstTimeIntro_Text_15:
# 170 "data/maps/AlolaLaboratory/scripts.pory"
	.string "…Kzzzt?$"

AlolaLaboratory_FirstTimeIntro_Text_16:
# 175 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey now! Sorry 'bout that, Rotom.\n"
	.string "Guess I surprised you?$"

AlolaLaboratory_FirstTimeIntro_Text_17:
# 181 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Zz-zzt…$"

AlolaLaboratory_FirstTimeIntro_Text_18:
# 186 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rotom!\p"
	.string "Here, boy!\n"
	.string "I powered up your favorite Phone!\p"
	.string "Give {PLAYER} here a Helping Hand,\n"
	.string "yeah?$"

AlolaLaboratory_FirstTimeIntro_Text_19:
# 197 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Kzzzt…$"

AlolaLaboratory_FirstTimeIntro_Text_20:
# 216 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Check it out, {PLAYER}!\n"
	.string "Now Rotom can talk right to you!\p"
	.string "It may take it a little while to get\n"
	.string "used to its new job, but I'd say\l"
	.string "Rotom's taken a liking to you!$"

AlolaLaboratory_FirstTimeIntro_Text_21:
# 225 "data/maps/AlolaLaboratory/scripts.pory"
	.string "And this will help how exactly?$"

AlolaLaboratory_FirstTimeIntro_Text_22:
# 232 "data/maps/AlolaLaboratory/scripts.pory"
	.string "{PLAYER} hasn't been here in Alola\n"
	.string "too long yet.\p"
	.string "So I decided to give him this special\n"
	.string "Phone to help him navigate around.$"

AlolaLaboratory_FirstTimeIntro_Text_23:
# 240 "data/maps/AlolaLaboratory/scripts.pory"
	.string "{PLAYER} hasn't been here in Alola\n"
	.string "too long yet.\p"
	.string "So I decided to give her this special\n"
	.string "Phone to help her navigate around.$"

AlolaLaboratory_FirstTimeIntro_Text_24:
# 246 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Thank you!$"

AlolaLaboratory_FirstTimeIntro_Text_25:
# 246 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hi, Rotom!$"

AlolaLaboratory_FirstTimeIntro_Text_26:
# 251 "data/maps/AlolaLaboratory/scripts.pory"
	.string "You can see ask Rotom for directions\n"
	.string "by opening the Rotom Phone and\l"
	.string "pressing {L_BUTTON}.\p"
	.string "You can also press the Rotom Reality\n"
	.string "feature to open the {COLOR RED}Town Map{COLOR DARK_GRAY}!$"
