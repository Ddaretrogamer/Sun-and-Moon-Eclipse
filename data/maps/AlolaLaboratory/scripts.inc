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
	compare VAR_IKITOWN_STATE, 20
	goto_if_lt AlolaLaboratory_Kukui_1
# 21 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 22 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Kukui_Text_1
# 27 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end

AlolaLaboratory_Kukui_1:
# 17 "data/maps/AlolaLaboratory/scripts.pory"
	goto AlolaLaboratory_CloseRotomPhoneBackup
	return


AlolaLaboratory_CloseRotomPhoneBackup::
# 34 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 35 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_0
# 41 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 42 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 43 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 44 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_2
# 45 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 46 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 47 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 48 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 49 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_CloseRotomPhoneBackup_2
# 59 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_4
AlolaLaboratory_CloseRotomPhoneBackup_1:
# 65 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_CloseRotomPhoneBackup_Text_5, AlolaLaboratory_CloseRotomPhoneBackup_Text_6
# 66 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_CloseRotomPhoneBackup_6
# 79 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 80 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 81 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 82 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_8
AlolaLaboratory_CloseRotomPhoneBackup_5:
# 89 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 90 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_9
# 97 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_CloseRotomPhoneBackup_Text_10, AlolaLaboratory_CloseRotomPhoneBackup_Text_11
# 98 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_CloseRotomPhoneBackup_10
# 118 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 119 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 120 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 121 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 122 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 123 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 124 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 125 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 126 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_12
AlolaLaboratory_CloseRotomPhoneBackup_9:
# 136 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 137 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 138 "data/maps/AlolaLaboratory/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 139 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 140 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_13
# 153 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_3
# 154 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 155 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 156 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 157 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_CloseRotomPhoneBackup_14
# 167 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_15
AlolaLaboratory_CloseRotomPhoneBackup_13:
# 173 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 174 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_16, MSGBOX_AUTOCLOSE
# 176 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_4
# 177 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement lab_lillie
# 178 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_EXIT
# 179 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_lillie, MAP_ALOLA_LABORATORY
# 180 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 181 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_5
# 182 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement lab_lillie
# 183 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_OPEN_TRAINER_SCHOOL
# 184 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 185 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_rockruff, MOVEMENT_TYPE_LOOK_AROUND
# 186 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_stufful, MOVEMENT_TYPE_LOOK_AROUND
# 187 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_snubbull, MOVEMENT_TYPE_LOOK_AROUND
# 188 "data/maps/AlolaLaboratory/scripts.pory"
	endcutscene
# 189 "data/maps/AlolaLaboratory/scripts.pory"
	helpwindow HELP_ROTOM_PHONE_GUIDE
# 190 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 20
# 191 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 192 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end

AlolaLaboratory_CloseRotomPhoneBackup_2:
# 51 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_3
	goto AlolaLaboratory_CloseRotomPhoneBackup_1

AlolaLaboratory_CloseRotomPhoneBackup_6:
# 67 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 68 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 69 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 70 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_7
	goto AlolaLaboratory_CloseRotomPhoneBackup_5

AlolaLaboratory_CloseRotomPhoneBackup_10:
# 99 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 100 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 101 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 102 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 103 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 104 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 105 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 106 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 107 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_12
	goto AlolaLaboratory_CloseRotomPhoneBackup_9

AlolaLaboratory_CloseRotomPhoneBackup_14:
# 159 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_14
	goto AlolaLaboratory_CloseRotomPhoneBackup_13


AlolaLaboratory_Stufful::
# 197 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 198 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 199 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_STUFFUL, 0
# 200 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Stufful_Text_0
# 201 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 202 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


AlolaLaboratory_Snubull::
# 207 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 208 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 209 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_SNUBBULL, 0
# 210 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Snubull_Text_0
# 211 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 212 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


AlolaLaboratory_Rockruff::
# 217 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 218 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 219 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 220 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Rockruff_Text_0
# 221 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 222 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


AlolaLaboratory_FirstTimeIntro::
# 227 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 228 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 19
# 231 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_0
# 232 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 233 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 235 "data/maps/AlolaLaboratory/scripts.pory"
	showobjectat lab_lillie, MAP_ALOLA_LABORATORY
# 236 "data/maps/AlolaLaboratory/scripts.pory"
	startcutscene CUTSCENE_ALOLA_LABORATORY_FIRST_TIME_INTRO
# 244 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_2
# 245 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement LOCALID_PLAYER, AlolaLaboratory_FirstTimeIntro_Movement_2
# 246 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 247 "data/maps/AlolaLaboratory/scripts.pory"
	delay 60
# 248 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 249 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_3
# 250 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 251 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 252 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 253 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_PIN
# 254 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_4
# 255 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_5
# 256 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 260 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 262 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 263 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 264 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_2
# 274 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 275 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 276 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 277 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 278 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 279 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_1, MSGBOX_AUTOCLOSE
AlolaLaboratory_FirstTimeIntro_1:
# 282 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_5
# 283 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_6
# 284 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 285 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 286 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_2
# 288 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 289 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_3, MSGBOX_AUTOCLOSE
# 295 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement LOCALID_PLAYER, AlolaLaboratory_FirstTimeIntro_Movement_7
# 296 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 297 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 298 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 299 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 300 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 301 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_4, MSGBOX_AUTOCLOSE
# 303 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_PIN
# 304 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_8
# 305 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 306 "data/maps/AlolaLaboratory/scripts.pory"
	delay 100
# 307 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 308 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_5
# 312 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 313 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_6
# 314 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_9
# 315 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 316 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 317 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_7
# 322 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_FirstTimeIntro_Text_8, AlolaLaboratory_FirstTimeIntro_Text_9
# 323 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_6
# 336 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 337 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 338 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 339 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_10
AlolaLaboratory_FirstTimeIntro_5:
# 346 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 347 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 348 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_11, MSGBOX_AUTOCLOSE
# 364 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_10
# 365 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 366 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 367 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 368 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 369 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_CLICK
# 370 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 371 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 372 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_WHITE
# 373 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_M_MEGA_KICK
# 374 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 375 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_M_SELF_DESTRUCT
# 376 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 377 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_BALL_OPEN
# 378 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 379 "data/maps/AlolaLaboratory/scripts.pory"
	showobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 380 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 14, 11
# 381 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 382 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 383 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 384 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 385 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 386 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 387 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 388 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_12
# 389 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 390 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 391 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 392 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 393 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_13
# 395 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 396 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 397 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 398 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 399 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_14, MSGBOX_AUTOCLOSE
# 400 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 401 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 402 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 403 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 404 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 405 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_15
# 412 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 413 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 414 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 415 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 416 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_16, MSGBOX_AUTOCLOSE
# 417 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 418 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 419 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 420 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_WHITE
# 421 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 422 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 423 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 424 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 425 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_CLICK
# 426 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 427 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 15, 17
# 428 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 429 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 2
# 430 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 431 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 432 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_11
# 433 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 434 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 435 "data/maps/AlolaLaboratory/scripts.pory"
	rotommenudisplay AlolaLaboratory_FirstTimeIntro_Text_17
# 437 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 438 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_0
# 444 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 445 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 446 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 447 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_2
# 448 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 449 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 450 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 451 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 452 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_10
# 462 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_4
AlolaLaboratory_FirstTimeIntro_9:
# 468 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_CloseRotomPhoneBackup_Text_5, AlolaLaboratory_CloseRotomPhoneBackup_Text_6
# 469 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_14
# 482 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 483 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 484 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 485 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_8
AlolaLaboratory_FirstTimeIntro_13:
# 492 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 493 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_9
# 500 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_CloseRotomPhoneBackup_Text_10, AlolaLaboratory_CloseRotomPhoneBackup_Text_11
# 501 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_18
# 521 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 522 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 523 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 524 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 525 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 526 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 527 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 528 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 529 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_12
AlolaLaboratory_FirstTimeIntro_17:
# 539 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 540 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 541 "data/maps/AlolaLaboratory/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 542 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 543 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_13
# 556 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_3
# 557 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 558 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 559 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 560 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_22
# 570 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_15
AlolaLaboratory_FirstTimeIntro_21:
# 576 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 577 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_16, MSGBOX_AUTOCLOSE
# 579 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_4
# 580 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement lab_lillie
# 581 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_EXIT
# 582 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_lillie, MAP_ALOLA_LABORATORY
# 583 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 584 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_5
# 585 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement lab_lillie
# 586 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_OPEN_TRAINER_SCHOOL
# 587 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 588 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_rockruff, MOVEMENT_TYPE_LOOK_AROUND
# 589 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_stufful, MOVEMENT_TYPE_LOOK_AROUND
# 590 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_snubbull, MOVEMENT_TYPE_LOOK_AROUND
# 591 "data/maps/AlolaLaboratory/scripts.pory"
	endcutscene
# 592 "data/maps/AlolaLaboratory/scripts.pory"
	helpwindow HELP_ROTOM_PHONE_GUIDE
# 593 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 20
# 594 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end

AlolaLaboratory_FirstTimeIntro_2:
# 265 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 266 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 267 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 268 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 269 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 270 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_0, MSGBOX_AUTOCLOSE
	goto AlolaLaboratory_FirstTimeIntro_1

AlolaLaboratory_FirstTimeIntro_6:
# 324 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 325 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 326 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 327 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_10
	goto AlolaLaboratory_FirstTimeIntro_5

AlolaLaboratory_FirstTimeIntro_10:
# 454 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_3
	goto AlolaLaboratory_FirstTimeIntro_9

AlolaLaboratory_FirstTimeIntro_14:
# 470 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 471 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 472 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 473 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_7
	goto AlolaLaboratory_FirstTimeIntro_13

AlolaLaboratory_FirstTimeIntro_18:
# 502 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 503 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 504 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 505 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 506 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 507 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 508 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 509 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 510 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_12
	goto AlolaLaboratory_FirstTimeIntro_17

AlolaLaboratory_FirstTimeIntro_22:
# 562 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_14
	goto AlolaLaboratory_FirstTimeIntro_21


AlolaLaboratory_FirstTimeIntroSkip::
# 599 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 600 "data/maps/AlolaLaboratory/scripts.pory"
	closemessage
# 601 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_BLACK
# 602 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_lillie, MAP_ALOLA_LABORATORY
# 603 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_lillie, 14, 17
# 604 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 605 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 14, 17
# 606 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 20
# 607 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_0
# 608 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 609 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_kukui, 15, 10
# 610 "data/maps/AlolaLaboratory/scripts.pory"
	special StopAllObjectMovements
# 611 "data/maps/AlolaLaboratory/scripts.pory"
	special CloseScriptMenus
# 614 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_OPEN_TRAINER_SCHOOL
# 615 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 2
# 616 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 617 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 618 "data/maps/AlolaLaboratory/scripts.pory"
	helpwindow HELP_ROTOM_PHONE_GUIDE
# 619 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


# 41 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_0:
# 41 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 41 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 45 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_1:
# 45 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
# 45 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
	step_end

# 100 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_2:
# 100 "data/maps/AlolaLaboratory/scripts.pory"
	jump_in_place_down
# 100 "data/maps/AlolaLaboratory/scripts.pory"
	jump_in_place_down
	step_end

# 153 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_3:
# 153 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 153 "data/maps/AlolaLaboratory/scripts.pory"
	delay_8
# 153 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 176 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_4:
# 176 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
# 176 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
# 176 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
	step_end

# 181 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_5:
# 181 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
	step_end

# 231 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_0:
# 231 "data/maps/AlolaLaboratory/scripts.pory"
	face_right
	step_end

# 232 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_1:
# 232 "data/maps/AlolaLaboratory/scripts.pory"
	face_left
	step_end

# 244 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_2:
# 244 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 244 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 244 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
	step_end

# 249 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_3:
# 249 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_right
# 249 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_right
	step_end

# 254 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_4:
# 254 "data/maps/AlolaLaboratory/scripts.pory"
	emote_exclamation_mark
# 254 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 255 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_5:
# 255 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 255 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 255 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 283 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_6:
# 283 "data/maps/AlolaLaboratory/scripts.pory"
	delay_8
# 283 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 295 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_7:
# 295 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 295 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 295 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 295 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 295 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 304 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_8:
# 304 "data/maps/AlolaLaboratory/scripts.pory"
	emote_question_mark
	step_end

# 314 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_9:
# 314 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 364 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_10:
# 364 "data/maps/AlolaLaboratory/scripts.pory"
	face_up
# 364 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 364 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 364 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 364 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 432 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_11:
# 432 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 432 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
# 432 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
	step_end

AlolaLaboratory_Kukui_Text_0:
# 21 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Kukui$"

AlolaLaboratory_Kukui_Text_1:
# 22 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Pokémon are my totally necessary\n"
	.string "partners in my research.\p"
	.string "Plus we all live here together.\n"
	.string "I guess I'd have to call them family!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_0:
# 35 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Check it out, {PLAYER}!\n"
	.string "Now Rotom can talk right to you!\p"
	.string "It may take it a little while to get\n"
	.string "used to its new job, but I'd say\l"
	.string "Rotom's taken a liking to you!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_1:
# 43 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_2:
# 44 "data/maps/AlolaLaboratory/scripts.pory"
	.string "And this will help how exactly?$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_3:
# 51 "data/maps/AlolaLaboratory/scripts.pory"
	.string "{PLAYER} hasn't been here in Alola\n"
	.string "too long yet.\p"
	.string "So I decided to give him this special\n"
	.string "Phone to help him navigate around.$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_4:
# 59 "data/maps/AlolaLaboratory/scripts.pory"
	.string "{PLAYER} hasn't been here in Alola\n"
	.string "too long yet.\p"
	.string "So I decided to give her this special\n"
	.string "Phone to help her navigate around.$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_5:
# 65 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Thank you!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_6:
# 65 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hi, Rotom!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_7:
# 70 "data/maps/AlolaLaboratory/scripts.pory"
	.string "You can ask Rotom for directions by\n"
	.string "opening the Rotom Phone and\l"
	.string "pressing {R_BUTTON}!\p"
	.string "You can also press the Rotom Reality\n"
	.string "feature to open the {COLOR RED}Town Map{COLOR DARK_GRAY}!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_8:
# 82 "data/maps/AlolaLaboratory/scripts.pory"
	.string "You can see ask Rotom for directions\n"
	.string "by opening the Rotom Phone and\l"
	.string "pressing {R_BUTTON}!\p"
	.string "You can also press the Rotom Reality\n"
	.string "feature to open the {COLOR RED}Town Map{COLOR DARK_GRAY}!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_9:
# 90 "data/maps/AlolaLaboratory/scripts.pory"
	.string "So, {PLAYER}, I'm leaving this Rotom\n"
	.string "Phone in your hands!\p"
	.string "Rotom, you look after {PLAYER}, yeah?\p"
	.string "All right then, {PLAYER}!\n"
	.string "Get a move on!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_10:
# 97 "data/maps/AlolaLaboratory/scripts.pory"
	.string "OK!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_11:
# 97 "data/maps/AlolaLaboratory/scripts.pory"
	.string "What?$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_12:
# 107 "data/maps/AlolaLaboratory/scripts.pory"
	.string "To the Trainers' School!\p"
	.string "You've gotta learn the basics of being\n"
	.string "a Pokémon Trainer through Pokémon\l"
	.string "battling.\p"
	.string "It's a long road to becoming the island\n"
	.string "challenge champion, and the\l"
	.string "Trainers' School is the first step!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_13:
# 140 "data/maps/AlolaLaboratory/scripts.pory"
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

AlolaLaboratory_CloseRotomPhoneBackup_Text_14:
# 159 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie!\n"
	.string "You take care of {PLAYER}, yeah?\p"
	.string "Until he gets used to Rotom,\n"
	.string "help him find his way around!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_15:
# 167 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie!\n"
	.string "You take care of {PLAYER}, yeah?\p"
	.string "Until she gets used to Rotom,\n"
	.string "help her find her way around!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_16:
# 174 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Of course, Professor Kukui!\n"
	.string "I'll wait outside.$"

AlolaLaboratory_Stufful_Text_0:
# 200 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Ayoo!$"

AlolaLaboratory_Snubull_Text_0:
# 210 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Wroo!$"

AlolaLaboratory_Rockruff_Text_0:
# 220 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Wroof!$"

AlolaLaboratory_FirstTimeIntro_Text_0:
# 270 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "Thanks for getting him for me, Lillie!$"

AlolaLaboratory_FirstTimeIntro_Text_1:
# 279 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "Thanks for getting her for me, Lillie!$"

AlolaLaboratory_FirstTimeIntro_Text_2:
# 286 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Of course. However I can be a help…\n"
	.string "I am supposed to be your assistant.$"

AlolaLaboratory_FirstTimeIntro_Text_3:
# 289 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rockruff's moves were just so stylin',\n"
	.string "and I was making good progress with\l"
	.string "my research.\p"
	.string "Say, {PLAYER}, lemme see your Rotom\n"
	.string "Phone for a second, yeah?$"

AlolaLaboratory_FirstTimeIntro_Text_4:
# 301 "data/maps/AlolaLaboratory/scripts.pory"
	.string "So what do you think of the place?\n"
	.string "Not bad right?$"

AlolaLaboratory_FirstTimeIntro_Text_5:
# 308 "data/maps/AlolaLaboratory/scripts.pory"
	.string "But that's not why I called you here,\n"
	.string "eh?\p"
	.string "Here! It finally arrived!$"

AlolaLaboratory_FirstTimeIntro_Text_6:
# 313 "data/maps/AlolaLaboratory/scripts.pory"
	.string "“It”…?$"

AlolaLaboratory_FirstTimeIntro_Text_7:
# 317 "data/maps/AlolaLaboratory/scripts.pory"
	.string "What's wrong, Lillie? Dont make me\n"
	.string "do all the talking?\p"
	.string "See, there's this Pokémon inside your\n"
	.string "Phone called Rotom…$"

AlolaLaboratory_FirstTimeIntro_Text_8:
# 322 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Really?$"

AlolaLaboratory_FirstTimeIntro_Text_9:
# 322 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rotom?$"

AlolaLaboratory_FirstTimeIntro_Text_10:
# 327 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Oh, I can tell you about Rotom.\p"
	.string "It's a peculiar Pokémon, with a body\n"
	.string "made up of something like\l"
	.string "electricity.\l"
	.string "It can take up residence in machines.$"

AlolaLaboratory_FirstTimeIntro_Text_11:
# 348 "data/maps/AlolaLaboratory/scripts.pory"
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

AlolaLaboratory_FirstTimeIntro_Text_12:
# 388 "data/maps/AlolaLaboratory/scripts.pory"
	.string "…Kzzzt?$"

AlolaLaboratory_FirstTimeIntro_Text_13:
# 393 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey now! Sorry 'bout that, Rotom.\n"
	.string "Guess I surprised you?$"

AlolaLaboratory_FirstTimeIntro_Text_14:
# 399 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Zz-zzt…$"

AlolaLaboratory_FirstTimeIntro_Text_15:
# 405 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rotom!\p"
	.string "Here, boy!\n"
	.string "I powered up your favorite Phone!\p"
	.string "Give {PLAYER} here a Helping Hand,\n"
	.string "yeah?$"

AlolaLaboratory_FirstTimeIntro_Text_16:
# 416 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Kzzzt…$"

AlolaLaboratory_FirstTimeIntro_Text_17:
# 435 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Uh, hey there! P-pleasure to meet you!\nI-I'm not nervouzzz or anything.$"
