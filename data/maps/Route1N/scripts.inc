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
	goto_if_not_defeated TRAINER_LASS_HIROMI, TrainersSchool_BattleVs_Hiromi2
# 150 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Hiromi_Text_0, MSGBOX_AUTOCLOSE
# 158 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_BattleVs_Hiromi2::
# 163 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 164 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lass1, TrainersSchool_Intro_Movement_5
# 165 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_lass1
# 166 "data/maps/Route1N/scripts.pory"
	waitse
# 167 "data/maps/Route1N/scripts.pory"
	trainerbattle_single TRAINER_LASS_HIROMI, TrainersSchool_BattleVs_Hiromi2_Text_0, TrainersSchool_BattleVs_Hiromi2_Text_1
# 168 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Hiromi_Text_0, MSGBOX_AUTOCLOSE
# 176 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_RockPaperScissors::
# 181 "data/maps/Route1N/scripts.pory"
	lock
# 182 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 183 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_1
# 184 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 185 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_3
# 186 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 187 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littleboy, TrainersSchool_Intro_Movement_5
# 188 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_Intro_Movement_5
# 189 "data/maps/Route1N/scripts.pory"
	waitmovement 0
# 190 "data/maps/Route1N/scripts.pory"
	waitse
# 191 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 192 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_4
# 194 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littleboy, TrainersSchool_Intro_Movement_8
# 195 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_Intro_Movement_8
# 196 "data/maps/Route1N/scripts.pory"
	waitmovement 0
# 197 "data/maps/Route1N/scripts.pory"
	random 2
# 198 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TrainersSchool_RockPaperScissors_2
# 224 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TrainersSchool_RockPaperScissors_3
# 250 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq TrainersSchool_RockPaperScissors_4
TrainersSchool_RockPaperScissors_1:
# 276 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littleboy, TrainersSchool_Intro_Movement_3
# 277 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_RockPaperScissors_Movement_0
# 278 "data/maps/Route1N/scripts.pory"
	waitmovement 0
# 279 "data/maps/Route1N/scripts.pory"
	release
	end

TrainersSchool_RockPaperScissors_2:
# 199 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 200 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_5, MSGBOX_AUTOCLOSE
# 202 "data/maps/Route1N/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TrainersSchool_RockPaperScissors_Text_6, TrainersSchool_RockPaperScissors_Text_7, TrainersSchool_RockPaperScissors_Text_8
# 203 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TrainersSchool_RockPaperScissors_8
# 208 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TrainersSchool_RockPaperScissors_9
# 213 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq TrainersSchool_RockPaperScissors_10
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_3:
# 225 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 226 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_11, MSGBOX_AUTOCLOSE
# 228 "data/maps/Route1N/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TrainersSchool_RockPaperScissors_Text_6, TrainersSchool_RockPaperScissors_Text_7, TrainersSchool_RockPaperScissors_Text_8
# 229 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TrainersSchool_RockPaperScissors_14
# 239 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TrainersSchool_RockPaperScissors_15
# 244 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq TrainersSchool_RockPaperScissors_16
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_4:
# 251 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 252 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_12, MSGBOX_AUTOCLOSE
# 254 "data/maps/Route1N/scripts.pory"
	dynmultichoice 22, 6, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TrainersSchool_RockPaperScissors_Text_6, TrainersSchool_RockPaperScissors_Text_7, TrainersSchool_RockPaperScissors_Text_8
# 255 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TrainersSchool_RockPaperScissors_20
# 260 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TrainersSchool_RockPaperScissors_21
# 270 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq TrainersSchool_RockPaperScissors_22
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_8:
# 204 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 205 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_9:
# 209 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 210 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_10:
# 214 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_Intro_Movement_6
# 215 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 216 "data/maps/Route1N/scripts.pory"
	waitse
# 217 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 218 "data/maps/Route1N/scripts.pory"
	waitse
# 219 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 220 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_10
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_14:
# 230 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_Intro_Movement_6
# 231 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 232 "data/maps/Route1N/scripts.pory"
	waitse
# 233 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 234 "data/maps/Route1N/scripts.pory"
	waitse
# 235 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 236 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_10
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_15:
# 240 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 241 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_16:
# 245 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_0
# 246 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_20:
# 256 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 257 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_21:
# 261 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_littlegirl, TrainersSchool_Intro_Movement_6
# 262 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 263 "data/maps/Route1N/scripts.pory"
	waitse
# 264 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 265 "data/maps/Route1N/scripts.pory"
	waitse
# 266 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 267 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_10
	goto TrainersSchool_RockPaperScissors_1

TrainersSchool_RockPaperScissors_22:
# 271 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_RockPaperScissors_Text_2
# 272 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_RockPaperScissors_Text_9
	goto TrainersSchool_RockPaperScissors_1


TrainersSchool_BattleVs_Joey::
# 284 "data/maps/Route1N/scripts.pory"
	lock
# 285 "data/maps/Route1N/scripts.pory"
	goto_if_not_defeated TRAINER_YOUNGSTER_JOEY, TrainersSchool_BattleVS_joey2
# 286 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joey_Text_0, MSGBOX_AUTOCLOSE
# 292 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_BattleVS_joey2::
# 297 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 298 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_joey, TrainersSchool_BattleVS_joey2_Movement_0
# 299 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_joey
# 300 "data/maps/Route1N/scripts.pory"
	waitse
# 301 "data/maps/Route1N/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_JOEY, TrainersSchool_BattleVS_joey2_Text_0, TrainersSchool_BattleVS_joey2_Text_1
# 303 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joey_Text_0, MSGBOX_AUTOCLOSE
# 309 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_Lillie::
# 314 "data/maps/Route1N/scripts.pory"
	lock
# 315 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_Lillie_Movement_0
# 316 "data/maps/Route1N/scripts.pory"
	specialvar VAR_RESULT, IsPlayerPartyFullyHealed
# 317 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TrainersSchool_Lillie_2
# 329 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Lillie_Text_0
# 330 "data/maps/Route1N/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 331 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Lillie_Text_2
# 333 "data/maps/Route1N/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 334 "data/maps/Route1N/scripts.pory"
	playfanfare MUS_HEAL
# 335 "data/maps/Route1N/scripts.pory"
	special HealPlayerParty
# 336 "data/maps/Route1N/scripts.pory"
	waitfanfare
# 337 "data/maps/Route1N/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 338 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Lillie_Text_0
# 339 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Lillie_Text_3
# 343 "data/maps/Route1N/scripts.pory"
	release
	end

TrainersSchool_Lillie_2:
# 318 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Lillie_Text_0
# 319 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Lillie_Text_1
# 324 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_Kukui::
# 348 "data/maps/Route1N/scripts.pory"
	lock
# 349 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_kukui, TrainersSchool_Lillie_Movement_0
# 350 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 351 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Kukui_Text_0, MSGBOX_AUTOCLOSE
# 364 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_BattleVs_Joseph::
# 370 "data/maps/Route1N/scripts.pory"
	lock
# 371 "data/maps/Route1N/scripts.pory"
	faceplayer
# 372 "data/maps/Route1N/scripts.pory"
	goto_if_not_defeated TRAINER_YOUNGSTER_JOEY, TrainersSchool_BattleVs_Joseph2
# 373 "data/maps/Route1N/scripts.pory"
	goto_if_not_defeated TRAINER_LASS_HIROMI, TrainersSchool_BattleVs_Joseph2
# 374 "data/maps/Route1N/scripts.pory"
	goto_if_not_defeated TRAINER_SCHOOLKID_MIA, TrainersSchool_BattleVs_Joseph2
# 375 "data/maps/Route1N/scripts.pory"
	goto_if_defeated TRAINER_SCHOOLKID_JOSEPH, TrainersSchool_BattleVs_Joseph3
# 376 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 377 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_joseph, TrainersSchool_BattleVS_joey2_Movement_0
# 378 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_joseph
# 379 "data/maps/Route1N/scripts.pory"
	waitse
# 380 "data/maps/Route1N/scripts.pory"
	trainerbattle_single TRAINER_SCHOOLKID_JOSEPH, TrainersSchool_BattleVs_Joseph_Text_0, TrainersSchool_BattleVs_Joseph_Text_1, TrainersSchool_BattleVs_Joseph4
# 381 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_BattleVs_Joseph2::
# 386 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joseph2_Text_0, MSGBOX_AUTOCLOSE
# 391 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_BattleVs_Joseph3::
# 396 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joseph3_Text_0
# 410 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_BattleVs_Joseph4::
# 415 "data/maps/Route1N/scripts.pory"
	setflag FLAG_HIDE_TRAINERSCHOOL_BLOCKINGMEOWTH
# 416 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joseph4_Text_0, MSGBOX_AUTOCLOSE
# 428 "data/maps/Route1N/scripts.pory"
	giveitem ITEM_TM01
# 429 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joseph3_Text_0, MSGBOX_AUTOCLOSE
# 443 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_BattleVs_Joseph4_Movement_0
# 444 "data/maps/Route1N/scripts.pory"
	waitmovement 0
# 445 "data/maps/Route1N/scripts.pory"
	playse SE_DING_DONG
# 446 "data/maps/Route1N/scripts.pory"
	waitse
# 447 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Lillie_Text_0
# 448 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joseph4_Text_1, MSGBOX_AUTOCLOSE
# 449 "data/maps/Route1N/scripts.pory"
	delay 30
# 450 "data/maps/Route1N/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 451 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joseph4_Text_2
# 457 "data/maps/Route1N/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 458 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_Intro_Movement_4
# 459 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_lillie
# 460 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Lillie_Text_0
# 461 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joseph4_Text_3
# 463 "data/maps/Route1N/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TrainersSchool_BattleVs_Joseph4_Text_4, TrainersSchool_BattleVs_Joseph4_Text_5
# 464 "data/maps/Route1N/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TrainersSchool_BattleVs_Joseph4_2
# 474 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 475 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_Intro_Movement_5
# 476 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_lillie
# 477 "data/maps/Route1N/scripts.pory"
	waitse
# 478 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Lillie_Text_0
# 479 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joseph4_Text_7
TrainersSchool_BattleVs_Joseph4_1:
# 481 "data/maps/Route1N/scripts.pory"
	release
	end

TrainersSchool_BattleVs_Joseph4_2:
# 465 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 466 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_Intro_Movement_5
# 467 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_lillie
# 468 "data/maps/Route1N/scripts.pory"
	waitse
# 469 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Lillie_Text_0
# 470 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BattleVs_Joseph4_Text_6
	goto TrainersSchool_BattleVs_Joseph4_1


TrainersSchool_BlockingTauros::
# 486 "data/maps/Route1N/scripts.pory"
	lock
# 487 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_tauros, TrainersSchool_Lillie_Movement_0
# 488 "data/maps/Route1N/scripts.pory"
	waitmovement
# 489 "data/maps/Route1N/scripts.pory"
	playmoncry SPECIES_TAUROS, 0
# 490 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_BlockingTauros_Text_0, MSGBOX_AUTOCLOSE
# 491 "data/maps/Route1N/scripts.pory"
	waitmoncry
# 492 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 493 "data/maps/Route1N/scripts.pory"
	applymovement LOCALID_PLAYER, TrainersSchool_BlockingTauros_Movement_0
# 494 "data/maps/Route1N/scripts.pory"
	waitmovement LOCALID_PLAYER
# 495 "data/maps/Route1N/scripts.pory"
	release
	end


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

# 277 "data/maps/Route1N/scripts.pory"
TrainersSchool_RockPaperScissors_Movement_0:
# 277 "data/maps/Route1N/scripts.pory"
	face_right
	step_end

# 298 "data/maps/Route1N/scripts.pory"
TrainersSchool_BattleVS_joey2_Movement_0:
# 298 "data/maps/Route1N/scripts.pory"
	emote_exclamation_mark
# 298 "data/maps/Route1N/scripts.pory"
	face_player
	step_end

# 315 "data/maps/Route1N/scripts.pory"
TrainersSchool_Lillie_Movement_0:
# 315 "data/maps/Route1N/scripts.pory"
	face_player
	step_end

# 443 "data/maps/Route1N/scripts.pory"
TrainersSchool_BattleVs_Joseph4_Movement_0:
# 443 "data/maps/Route1N/scripts.pory"
	walk_faster_up
# 443 "data/maps/Route1N/scripts.pory"
	walk_faster_up
# 443 "data/maps/Route1N/scripts.pory"
	walk_faster_up
# 443 "data/maps/Route1N/scripts.pory"
	walk_faster_up
# 443 "data/maps/Route1N/scripts.pory"
	walk_faster_up
# 443 "data/maps/Route1N/scripts.pory"
	walk_left
# 443 "data/maps/Route1N/scripts.pory"
	walk_left
# 443 "data/maps/Route1N/scripts.pory"
	walk_left
# 443 "data/maps/Route1N/scripts.pory"
	walk_left
# 443 "data/maps/Route1N/scripts.pory"
	walk_left
# 443 "data/maps/Route1N/scripts.pory"
	walk_left
# 443 "data/maps/Route1N/scripts.pory"
	walk_left
# 443 "data/maps/Route1N/scripts.pory"
	walk_left
# 443 "data/maps/Route1N/scripts.pory"
	walk_down
# 443 "data/maps/Route1N/scripts.pory"
	walk_down
# 443 "data/maps/Route1N/scripts.pory"
	face_down
	step_end

# 493 "data/maps/Route1N/scripts.pory"
TrainersSchool_BlockingTauros_Movement_0:
# 493 "data/maps/Route1N/scripts.pory"
	emote_exclamation_mark
# 493 "data/maps/Route1N/scripts.pory"
	lock_facing_direction
# 493 "data/maps/Route1N/scripts.pory"
	jump_right
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
# 150 "data/maps/Route1N/scripts.pory"
	.string "You can help your Pokémon win by using\n"
	.string "items at the right time.\p"
	.string "They can do more than just healing\n"
	.string "your Pokémon's HP too.\p"
	.string "You can even boost their stats and\n"
	.string "things like that.$"

TrainersSchool_BattleVs_Hiromi2_Text_0:
# 167 "data/maps/Route1N/scripts.pory"
	.string "If my previous Bonsly takes damage,\nI'll want to use a Potion on it!$"

TrainersSchool_BattleVs_Hiromi2_Text_1:
# 167 "data/maps/Route1N/scripts.pory"
	.string "Don't worry-I'll heal any pain that was\ncaused by our defeat!$"

TrainersSchool_RockPaperScissors_Text_0:
# 182 "data/maps/Route1N/scripts.pory"
	.string "Little Boy$"

TrainersSchool_RockPaperScissors_Text_1:
# 183 "data/maps/Route1N/scripts.pory"
	.string "Ready, and…$"

TrainersSchool_RockPaperScissors_Text_2:
# 184 "data/maps/Route1N/scripts.pory"
	.string "Little Girl$"

TrainersSchool_RockPaperScissors_Text_3:
# 185 "data/maps/Route1N/scripts.pory"
	.string "GRASS, FIRE, WATER!$"

TrainersSchool_RockPaperScissors_Text_4:
# 192 "data/maps/Route1N/scripts.pory"
	.string "Um…\n"
	.string "Which one wins again?$"

TrainersSchool_RockPaperScissors_Text_5:
# 200 "data/maps/Route1N/scripts.pory"
	.string "Which would win in a matchup between\n"
	.string "Grass type and Water type?$"

TrainersSchool_RockPaperScissors_Text_6:
# 202 "data/maps/Route1N/scripts.pory"
	.string "Fire$"

TrainersSchool_RockPaperScissors_Text_7:
# 202 "data/maps/Route1N/scripts.pory"
	.string "Water$"

TrainersSchool_RockPaperScissors_Text_8:
# 202 "data/maps/Route1N/scripts.pory"
	.string "Grass$"

TrainersSchool_RockPaperScissors_Text_9:
# 205 "data/maps/Route1N/scripts.pory"
	.string "You sure? I'm pretty sure it's not…\n"
	.string "Are you messing with us maybe?$"

TrainersSchool_RockPaperScissors_Text_10:
# 220 "data/maps/Route1N/scripts.pory"
	.string "Right, right! Yeah, that's it.\n"
	.string "You must be a great Trainer!$"

TrainersSchool_RockPaperScissors_Text_11:
# 226 "data/maps/Route1N/scripts.pory"
	.string "Which would win in a matchup between\n"
	.string "Fire type and Grass type?$"

TrainersSchool_RockPaperScissors_Text_12:
# 252 "data/maps/Route1N/scripts.pory"
	.string "Which would win in a matchup between\n"
	.string "Water type and Fire type?$"

TrainersSchool_BattleVs_Joey_Text_0:
# 286 "data/maps/Route1N/scripts.pory"
	.string "Grass-type Pokémon are immune to\n"
	.string "powder moves, like Poison Powder and\l"
	.string "Sleep Powder.\p"
	.string "But you can still poison 'em with Poison\n"
	.string "Gas!$"

TrainersSchool_BattleVS_joey2_Text_0:
# 301 "data/maps/Route1N/scripts.pory"
	.string "I'll show you my Grimer's best move!\nWith Poison Gas, it'll poison\leveryone that comes at us!$"

TrainersSchool_BattleVS_joey2_Text_1:
# 302 "data/maps/Route1N/scripts.pory"
	.string "No! The Grimer I found in the tall grass\nnear the school was defeated?$"

TrainersSchool_Lillie_Text_0:
# 318 "data/maps/Route1N/scripts.pory"
	.string "Lillie$"

TrainersSchool_Lillie_Text_1:
# 319 "data/maps/Route1N/scripts.pory"
	.string "You can tell me anytime that you want\n"
	.string "your team's health restored.\p"
	.string "Seeing a Pokémon in pain makes my own\n"
	.string "heart seem to ache…$"

TrainersSchool_Lillie_Text_2:
# 331 "data/maps/Route1N/scripts.pory"
	.string "Let me take care of poor\n"
	.string "{STR_VAR_1}, OK?$"

TrainersSchool_Lillie_Text_3:
# 339 "data/maps/Route1N/scripts.pory"
	.string "Please try not to push your Pokémon\n"
	.string "too hard…\l"
	.string "Um…I mean…if you don't mind…$"

TrainersSchool_Kukui_Text_0:
# 351 "data/maps/Route1N/scripts.pory"
	.string "If you want a bit of advice from me,\n"
	.string "here's something that might help.\p"
	.string "Once you've fought a species of\n"
	.string "Pokémon once, You can easily see\l"
	.string "what types of moves will work best\l"
	.string "on it in your next battle.\p"
	.string "Wandering about in the tall grass to\n"
	.string "meet lots of different Pokémon'll\l"
	.string "help with that!\p"
	.string "Battle all the time, oh yeah!$"

TrainersSchool_BattleVs_Joseph_Text_0:
# 380 "data/maps/Route1N/scripts.pory"
	.string "Looks like you beat everyone else, huh?\pDon't think you'll beat me the same way!\nEkan's Ability is gonna get you!$"

TrainersSchool_BattleVs_Joseph_Text_1:
# 380 "data/maps/Route1N/scripts.pory"
	.string "Even after your Attack is lowered…\nAn indominable spirit indeed!$"

TrainersSchool_BattleVs_Joseph2_Text_0:
# 386 "data/maps/Route1N/scripts.pory"
	.string "You wanna know why I'm standing here?\n"
	.string "'Cause I'm the strongest, that's why!\p"
	.string "I won't even bother battling you\n"
	.string "unless you can beat everyone else here!$"

TrainersSchool_BattleVs_Joseph3_Text_0:
# 396 "data/maps/Route1N/scripts.pory"
	.string "OK. First thing to know about TMs.\p"
	.string "Technical Machines teach new moves.\n"
	.string "But if your Pokémon cant learn the\l"
	.string "move in a TM, then too bad.\p"
	.string "Second thing to know about TMs.\p"
	.string "You can use a TM as many times as you\n"
	.string "want, on as many different Pokémon as\l"
	.string "you want.\p"
	.string "They don't wear out or get used up.\n"
	.string "Pretty nice gift from me, huh?$"

TrainersSchool_BattleVs_Joseph4_Text_0:
# 416 "data/maps/Route1N/scripts.pory"
	.string "Intimidate is an Ability that lowers\n"
	.string "your opponent's Attack Stat.\p"
	.string "If you understand your Pokémon's\n"
	.string "Abilities, you can use the best\l"
	.string "strategies in battle.\p"
	.string "But fine! Whatever!\p"
	.string "I can admit it when I'm beat.\n"
	.string "I'll give you a reward even.\l"
	.string "Take this Technical Machine!$"

TrainersSchool_BattleVs_Joseph4_Text_1:
# 448 "data/maps/Route1N/scripts.pory"
	.string "Oh, that's the school bell$"

TrainersSchool_BattleVs_Joseph4_Text_2:
# 451 "data/maps/Route1N/scripts.pory"
	.string "Attention all students…\p"
	.string "Would {PLAYER} please come to the\n"
	.string "office on 2F?\p"
	.string "{PLAYER} to the 2F office, please.$"

TrainersSchool_BattleVs_Joseph4_Text_3:
# 461 "data/maps/Route1N/scripts.pory"
	.string "What terrible thing did you do to get\n"
	.string "called to the office so soon?$"

TrainersSchool_BattleVs_Joseph4_Text_4:
# 463 "data/maps/Route1N/scripts.pory"
	.string "Nothing!$"

TrainersSchool_BattleVs_Joseph4_Text_5:
# 463 "data/maps/Route1N/scripts.pory"
	.string "Well…$"

TrainersSchool_BattleVs_Joseph4_Text_6:
# 470 "data/maps/Route1N/scripts.pory"
	.string "That's what you say…$"

TrainersSchool_BattleVs_Joseph4_Text_7:
# 479 "data/maps/Route1N/scripts.pory"
	.string "So you did do something?!$"

TrainersSchool_BlockingTauros_Text_0:
# 490 "data/maps/Route1N/scripts.pory"
	.string "Graah!$"
