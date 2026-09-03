Route1N_MapScripts::
	.byte 0


TrainerSchoolSign::
# 5 "data/maps/Route1N/scripts.pory"
	lock
# 6 "data/maps/Route1N/scripts.pory"
	msgbox TrainerSchoolSign_Text_0
# 10 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_Intro::
# 15 "data/maps/Route1N/scripts.pory"
	lock
# 16 "data/maps/Route1N/scripts.pory"
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
# 17 "data/maps/Route1N/scripts.pory"
	compare VAR_TEMP_3, 20
	goto_if_eq TrainersSchool_Intro_8
TrainersSchool_Intro_6:
# 21 "data/maps/Route1N/scripts.pory"
	compare VAR_TEMP_3, 18
	goto_if_eq TrainersSchool_Intro_5
TrainersSchool_Intro_4:
# 26 "data/maps/Route1N/scripts.pory"
	applymovement LOCALID_PLAYER, TrainersSchool_Intro_Movement_2
# 27 "data/maps/Route1N/scripts.pory"
	waitmovement LOCALID_PLAYER
TrainersSchool_Intro_1:
# 29 "data/maps/Route1N/scripts.pory"
	setvar VAR_IKITOWN_STATE, 22
# 30 "data/maps/Route1N/scripts.pory"
	startcutscene CUTSCENE_TRAINER_SCHOOL_INTRO
# 31 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_Intro_Movement_3
# 32 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_lillie
# 33 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_kukui, TrainersSchool_Intro_Movement_4
# 34 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_kukui
# 35 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 36 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_1, MSGBOX_AUTOCLOSE
# 42 "data/maps/Route1N/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 43 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 44 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_teacher, TrainersSchool_Intro_Movement_5
# 45 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_teacher
# 46 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_2, MSGBOX_AUTOCLOSE
# 48 "data/maps/Route1N/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 49 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 50 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_3
# 52 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_kukui, TrainersSchool_Intro_Movement_6
# 53 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 54 "data/maps/Route1N/scripts.pory"
	waitse
# 55 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 56 "data/maps/Route1N/scripts.pory"
	waitse
# 57 "data/maps/Route1N/scripts.pory"
	waitmovement 0
# 58 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_4
# 69 "data/maps/Route1N/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 70 "data/maps/Route1N/scripts.pory"
	giveitem ITEM_EXP_SHARE, 1
# 71 "data/maps/Route1N/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 72 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 73 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_5, MSGBOX_AUTOCLOSE
# 76 "data/maps/Route1N/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 77 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_teacher, TrainersSchool_Intro_Movement_4
# 78 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_teacher
# 79 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_6
# 88 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_teacher, TrainersSchool_Intro_Movement_6
# 89 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 90 "data/maps/Route1N/scripts.pory"
	waitse
# 91 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 92 "data/maps/Route1N/scripts.pory"
	waitse
# 93 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_7, MSGBOX_AUTOCLOSE
# 94 "data/maps/Route1N/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 95 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_teacher, TrainersSchool_Intro_Movement_7
# 96 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_teacher
# 97 "data/maps/Route1N/scripts.pory"
	removeobject trainerschool_teacher
# 98 "data/maps/Route1N/scripts.pory"
	setflag FLAG_HIDE_TRAINERSCHOOL_TEACHER
# 99 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_kukui, TrainersSchool_Intro_Movement_4
# 100 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_kukui
# 101 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 102 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_8
# 105 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_Intro_Movement_8
# 106 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_lillie
# 107 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_9, MSGBOX_AUTOCLOSE
# 118 "data/maps/Route1N/scripts.pory"
	endcutscene
# 119 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_kukui, TrainersSchool_Intro_Movement_6
# 120 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 121 "data/maps/Route1N/scripts.pory"
	waitse
# 122 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 123 "data/maps/Route1N/scripts.pory"
	waitse
# 124 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_10, MSGBOX_AUTOCLOSE
# 125 "data/maps/Route1N/scripts.pory"
	release
	end

TrainersSchool_Intro_2:
# 18 "data/maps/Route1N/scripts.pory"
	applymovement LOCALID_PLAYER, TrainersSchool_Intro_Movement_0
# 19 "data/maps/Route1N/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TrainersSchool_Intro_1

TrainersSchool_Intro_3:
# 22 "data/maps/Route1N/scripts.pory"
	applymovement LOCALID_PLAYER, TrainersSchool_Intro_Movement_1
# 23 "data/maps/Route1N/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TrainersSchool_Intro_1

TrainersSchool_Intro_5:
# 21 "data/maps/Route1N/scripts.pory"
	compare VAR_TEMP_4, 23
	goto_if_eq TrainersSchool_Intro_3
	goto TrainersSchool_Intro_4

TrainersSchool_Intro_8:
# 17 "data/maps/Route1N/scripts.pory"
	compare VAR_TEMP_4, 23
	goto_if_eq TrainersSchool_Intro_2
	goto TrainersSchool_Intro_6


TrainersSchool_Intro_Skip::
# 130 "data/maps/Route1N/scripts.pory"
	closemessage
# 131 "data/maps/Route1N/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 132 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_Intro_Movement_8
# 133 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_lillie
# 134 "data/maps/Route1N/scripts.pory"
	removeobject trainerschool_teacher
# 135 "data/maps/Route1N/scripts.pory"
	setflag FLAG_HIDE_TRAINERSCHOOL_TEACHER
# 136 "data/maps/Route1N/scripts.pory"
	special StopAllObjectMovements
# 137 "data/maps/Route1N/scripts.pory"
	special CloseScriptMenus
# 138 "data/maps/Route1N/scripts.pory"
	checkitem ITEM_EXP_SHARE, 1
# 139 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TrainersSchool_Intro_Skip_2
TrainersSchool_Intro_Skip_1:
# 142 "data/maps/Route1N/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 143 "data/maps/Route1N/scripts.pory"
	release
	end

TrainersSchool_Intro_Skip_2:
# 140 "data/maps/Route1N/scripts.pory"
	additem ITEM_EXP_SHARE, 1
	goto TrainersSchool_Intro_Skip_1


TrainersSchool_BattleVs_Hiromi::
# 148 "data/maps/Route1N/scripts.pory"
	lock
# 149 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 150 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lass1, TrainersSchool_Intro_Movement_5
# 151 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_lass1
# 152 "data/maps/Route1N/scripts.pory"
	waitse
# 153 "data/maps/Route1N/scripts.pory"
	trainerbattle_single TRAINER_LASS_HIROMI, TrainersSchool_BattleVs_Hiromi_Text_0, TrainersSchool_BattleVs_Hiromi_Text_1
# 154 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Hiromi_Text_2, MSGBOX_AUTOCLOSE
# 162 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_RockPaperScissors::
# 167 "data/maps/Route1N/scripts.pory"
	lock
# 168 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 169 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_1
# 170 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 171 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_3
# 172 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 173 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littleboy, TrainersSchool_Intro_Movement_5
# 174 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_Intro_Movement_5
# 175 "data/maps/Route1N/scripts.pory"
	waitmovement 0
# 176 "data/maps/Route1N/scripts.pory"
	waitse
# 177 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 178 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_4
# 180 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littleboy, TrainersSchool_Intro_Movement_8
# 181 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_Intro_Movement_8
# 182 "data/maps/Route1N/scripts.pory"
	waitmovement 0
# 183 "data/maps/Route1N/scripts.pory"
	random 2
# 184 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TrainersSchool_RockPaperScissors_2
# 210 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TrainersSchool_RockPaperScissors_3
# 236 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq TrainersSchool_RockPaperScissors_4
TrainersSchool_RockPaperScissors_1:
# 262 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littleboy, TrainersSchool_Intro_Movement_3
# 263 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_RockPaperScissors_Movement_0
# 264 "data/maps/Route1N/scripts.pory"
	release
	end

TrainersSchool_RockPaperScissors_2:
# 185 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 186 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_5, MSGBOX_AUTOCLOSE
# 188 "data/maps/Route1N/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TrainersSchool_RockPaperScissors_Text_6, TrainersSchool_RockPaperScissors_Text_7, TrainersSchool_RockPaperScissors_Text_8
# 189 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TrainersSchool_RockPaperScissors_8
# 194 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TrainersSchool_RockPaperScissors_9
# 199 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq TrainersSchool_RockPaperScissors_10
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_3:
# 211 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 212 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_11, MSGBOX_AUTOCLOSE
# 214 "data/maps/Route1N/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TrainersSchool_RockPaperScissors_Text_6, TrainersSchool_RockPaperScissors_Text_7, TrainersSchool_RockPaperScissors_Text_8
# 215 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TrainersSchool_RockPaperScissors_14
# 225 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TrainersSchool_RockPaperScissors_15
# 230 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq TrainersSchool_RockPaperScissors_16
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_4:
# 237 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 238 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_12, MSGBOX_AUTOCLOSE
# 240 "data/maps/Route1N/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TrainersSchool_RockPaperScissors_Text_6, TrainersSchool_RockPaperScissors_Text_7, TrainersSchool_RockPaperScissors_Text_8
# 241 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TrainersSchool_RockPaperScissors_20
# 246 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TrainersSchool_RockPaperScissors_21
# 256 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq TrainersSchool_RockPaperScissors_22
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_8:
# 190 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 191 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_9:
# 195 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 196 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_10:
# 200 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_Intro_Movement_6
# 201 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 202 "data/maps/Route1N/scripts.pory"
	waitse
# 203 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 204 "data/maps/Route1N/scripts.pory"
	waitse
# 205 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 206 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_10
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_14:
# 216 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_Intro_Movement_6
# 217 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 218 "data/maps/Route1N/scripts.pory"
	waitse
# 219 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 220 "data/maps/Route1N/scripts.pory"
	waitse
# 221 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 222 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_10
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_15:
# 226 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 227 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_16:
# 231 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 232 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_20:
# 242 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 243 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_21:
# 247 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_Intro_Movement_6
# 248 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 249 "data/maps/Route1N/scripts.pory"
	waitse
# 250 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 251 "data/maps/Route1N/scripts.pory"
	waitse
# 252 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 253 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_10
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_22:
# 257 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 258 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1


# 18 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_0:
# 18 "data/maps/Route1N/scripts.pory"
	walk_up
# 18 "data/maps/Route1N/scripts.pory"
	walk_left
# 18 "data/maps/Route1N/scripts.pory"
	face_up
	step_end

# 22 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_1:
# 22 "data/maps/Route1N/scripts.pory"
	walk_up
# 22 "data/maps/Route1N/scripts.pory"
	walk_right
# 22 "data/maps/Route1N/scripts.pory"
	face_up
	step_end

# 26 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_2:
# 26 "data/maps/Route1N/scripts.pory"
	walk_up
	step_end

# 31 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_3:
# 31 "data/maps/Route1N/scripts.pory"
	face_left
	step_end

# 33 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_4:
# 33 "data/maps/Route1N/scripts.pory"
	walk_in_place_down
# 33 "data/maps/Route1N/scripts.pory"
	walk_in_place_down
	step_end

# 44 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_5:
# 44 "data/maps/Route1N/scripts.pory"
	emote_exclamation_mark
	step_end

# 52 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_6:
# 52 "data/maps/Route1N/scripts.pory"
	jump_in_place_down
# 52 "data/maps/Route1N/scripts.pory"
	jump_in_place_down
	step_end

# 95 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_7:
# 95 "data/maps/Route1N/scripts.pory"
	walk_up
# 95 "data/maps/Route1N/scripts.pory"
	walk_up
# 95 "data/maps/Route1N/scripts.pory"
	walk_up
# 95 "data/maps/Route1N/scripts.pory"
	walk_up
	step_end

# 105 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_8:
# 105 "data/maps/Route1N/scripts.pory"
	face_down
	step_end

# 263 "data/maps/Route1N/scripts.pory"
TrainersSchool_RockPaperScissors_Movement_0:
# 263 "data/maps/Route1N/scripts.pory"
	face_right
	step_end

TrainerSchoolSign_Text_0:
# 6 "data/maps/Route1N/scripts.pory"
	.string "Let's learn and grow.\n"
	.string "Let's grow and train.\l"
	.string "Unsullied, enjoyable, and academic.\l"
	.string "Everyone starts at the beginning!$"

TrainersSchool_Intro_Text_0:
# 35 "data/maps/Route1N/scripts.pory"
	.string "Kukui$"

TrainersSchool_Intro_Text_1:
# 36 "data/maps/Route1N/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "I must've passed you somehow, yeah?\p"
	.string "But welcome to the Trainers' School,\n"
	.string "the place to learn how to be a\l"
	.string "Pokémon Trainer!$"

TrainersSchool_Intro_Text_2:
# 46 "data/maps/Route1N/scripts.pory"
	.string "Professor Kukui!\n"
	.string "Is this the child you told me about?$"

TrainersSchool_Intro_Text_3:
# 50 "data/maps/Route1N/scripts.pory"
	.string "Yeah. {PLAYER}'s a tough one,too.\n"
	.string "Put em through the wringer good, Teach!$"

TrainersSchool_Intro_Text_4:
# 58 "data/maps/Route1N/scripts.pory"
	.string "Four Trainers!\p"
	.string "You've got to beat four Pokémon\n"
	.string "Trainers at the school, {PLAYER}!\p"
	.string "The experience will surely help you\n"
	.string "and your Pokemon grow stronger,\l"
	.string "yeah.\p"
	.string "Actually… Speaking of experience,\n"
	.string "why don't you take this.$"

TrainersSchool_Intro_Text_5:
# 73 "data/maps/Route1N/scripts.pory"
	.string "If you keep that Exp. Share on, yeah,\n"
	.string "all the Pokémon on your team can get\l"
	.string "Exp. Points from battle.$"

TrainersSchool_Intro_Text_6:
# 79 "data/maps/Route1N/scripts.pory"
	.string "The Trainers who will take part in this\n"
	.string "lesson may be inside or outside the\l"
	.string "school.\p"
	.string "You may also want to visit our\n"
	.string "classrooms.\p"
	.string "You'll learn things there that will\n"
	.string "help on your journey, I'd say.$"

TrainersSchool_Intro_Text_7:
# 93 "data/maps/Route1N/scripts.pory"
	.string "All right. Let the lesson begin!$"

TrainersSchool_Intro_Text_8:
# 102 "data/maps/Route1N/scripts.pory"
	.string "She may not look all that tough, but\n"
	.string "that each trains her kids right!\l"
	.string "One of her students is even a captain!$"

TrainersSchool_Intro_Text_9:
# 107 "data/maps/Route1N/scripts.pory"
	.string "If you want a bit of advice from me,\n"
	.string "here's something that might help.\p"
	.string "Once you've fought a species of\n"
	.string "Pokémon once, You can easily see\l"
	.string "what types of moves will work best\l"
	.string "on it in your next battle.\p"
	.string "Wandering about in the tall grass to\n"
	.string "meet lots of different Pokémon'll\l"
	.string "help with that!$"

TrainersSchool_Intro_Text_10:
# 124 "data/maps/Route1N/scripts.pory"
	.string "Battle all the time, oh yeah!$"

TrainersSchool_BattleVs_Hiromi_Text_0:
# 153 "data/maps/Route1N/scripts.pory"
	.string "If my previous Bonsly takes damage,\nI'll want to use a Potion on it!$"

TrainersSchool_BattleVs_Hiromi_Text_1:
# 153 "data/maps/Route1N/scripts.pory"
	.string "Don't worry-I'll heal any pain that was\ncaused by our defeat!$"

TrainersSchool_BattleVs_Hiromi_Text_2:
# 154 "data/maps/Route1N/scripts.pory"
	.string "You can help your Pokémon win by using\n"
	.string "items at the right time.\p"
	.string "They can do more than just healing\n"
	.string "your Pokémon's HP too.\p"
	.string "You can even boost their stats and\n"
	.string "things like that.$"

TrainersSchool_RockPaperScissors_Text_0:
# 168 "data/maps/Route1N/scripts.pory"
	.string "Little Boy$"

TrainersSchool_RockPaperScissors_Text_1:
# 169 "data/maps/Route1N/scripts.pory"
	.string "Ready, and…$"

TrainersSchool_RockPaperScissors_Text_2:
# 170 "data/maps/Route1N/scripts.pory"
	.string "Little Girl$"

TrainersSchool_RockPaperScissors_Text_3:
# 171 "data/maps/Route1N/scripts.pory"
	.string "GRASS, FIRE, WATER!$"

TrainersSchool_RockPaperScissors_Text_4:
# 178 "data/maps/Route1N/scripts.pory"
	.string "Um…\n"
	.string "Which one wins again?$"

TrainersSchool_RockPaperScissors_Text_5:
# 186 "data/maps/Route1N/scripts.pory"
	.string "Which would win in a matchup between\n"
	.string "Grass type and Water type?$"

TrainersSchool_RockPaperScissors_Text_6:
# 188 "data/maps/Route1N/scripts.pory"
	.string "Fire$"

TrainersSchool_RockPaperScissors_Text_7:
# 188 "data/maps/Route1N/scripts.pory"
	.string "Water$"

TrainersSchool_RockPaperScissors_Text_8:
# 188 "data/maps/Route1N/scripts.pory"
	.string "Grass$"

TrainersSchool_RockPaperScissors_Text_9:
# 191 "data/maps/Route1N/scripts.pory"
	.string "You sure? I'm pretty sure it's not…\n"
	.string "Are you messing with us maybe?$"

TrainersSchool_RockPaperScissors_Text_10:
# 206 "data/maps/Route1N/scripts.pory"
	.string "Right, right! Yeah, that's it.\n"
	.string "You must be a great Trainer!$"

TrainersSchool_RockPaperScissors_Text_11:
# 212 "data/maps/Route1N/scripts.pory"
	.string "Which would win in a matchup between\n"
	.string "Fire type and Grass type?$"

TrainersSchool_RockPaperScissors_Text_12:
# 238 "data/maps/Route1N/scripts.pory"
	.string "Which would win in a matchup between\n"
	.string "Water type and Fire type?$"
