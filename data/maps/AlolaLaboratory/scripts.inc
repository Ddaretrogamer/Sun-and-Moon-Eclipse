AlolaLaboratory_MapScripts::
# 2 "data/maps/AlolaLaboratory/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 10 "data/maps/AlolaLaboratory/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 2 "data/maps/AlolaLaboratory/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, TRUE, AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 3 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 14, 17
# 4 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 5 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_IKITOWN_STATE, 18
	goto_if_gt AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1
	return

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1:
# 6 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_lillie, 14, 17
# 7 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_lillie, MAP_ALOLA_LABORATORY
	return

AlolaLaboratory_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/AlolaLaboratory/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 18, AlolaLaboratory_FirstTimeIntro
	.2byte 0


AlolaLaboratory_Kukui::
# 15 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 16 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 17 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_IKITOWN_STATE, 20
	goto_if_lt AlolaLaboratory_Kukui_1
# 22 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 23 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Kukui_Text_1
# 28 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end

AlolaLaboratory_Kukui_1:
# 18 "data/maps/AlolaLaboratory/scripts.pory"
	goto AlolaLaboratory_CloseRotomPhoneBackup
	return


AlolaLaboratory_CloseRotomPhoneBackup::
# 35 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 36 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_0
# 42 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 43 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 44 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 45 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_2
# 46 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 47 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 48 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 49 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 50 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_CloseRotomPhoneBackup_2
# 60 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_4
AlolaLaboratory_CloseRotomPhoneBackup_1:
# 66 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_CloseRotomPhoneBackup_Text_5, AlolaLaboratory_CloseRotomPhoneBackup_Text_6
# 67 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_CloseRotomPhoneBackup_6
# 80 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 81 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 82 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 83 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_8
AlolaLaboratory_CloseRotomPhoneBackup_5:
# 90 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 91 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_9
# 98 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_CloseRotomPhoneBackup_Text_10, AlolaLaboratory_CloseRotomPhoneBackup_Text_11
# 99 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_CloseRotomPhoneBackup_10
# 119 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 120 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 121 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 122 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 123 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 124 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 125 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 126 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 127 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_12
AlolaLaboratory_CloseRotomPhoneBackup_9:
# 137 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 138 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 139 "data/maps/AlolaLaboratory/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 140 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 141 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_13
# 154 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_3
# 155 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 156 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 157 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 158 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_CloseRotomPhoneBackup_14
# 168 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_15
AlolaLaboratory_CloseRotomPhoneBackup_13:
# 174 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 175 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_16, MSGBOX_AUTOCLOSE
# 177 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_4
# 178 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement lab_lillie
# 179 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_EXIT
# 180 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_lillie, MAP_ALOLA_LABORATORY
# 181 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 182 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_5
# 183 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement lab_lillie
# 184 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_OPEN_TRAINER_SCHOOL
# 185 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 186 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_rockruff, MOVEMENT_TYPE_LOOK_AROUND
# 187 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_stufful, MOVEMENT_TYPE_LOOK_AROUND
# 188 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_snubbull, MOVEMENT_TYPE_LOOK_AROUND
# 189 "data/maps/AlolaLaboratory/scripts.pory"
	endcutscene
# 190 "data/maps/AlolaLaboratory/scripts.pory"
	helpwindow HELP_ROTOM_PHONE_GUIDE
# 191 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 20
# 192 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 193 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end

AlolaLaboratory_CloseRotomPhoneBackup_2:
# 52 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_3
	goto AlolaLaboratory_CloseRotomPhoneBackup_1

AlolaLaboratory_CloseRotomPhoneBackup_6:
# 68 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 69 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 70 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 71 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_7
	goto AlolaLaboratory_CloseRotomPhoneBackup_5

AlolaLaboratory_CloseRotomPhoneBackup_10:
# 100 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 101 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 102 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 103 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 104 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 105 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 106 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 107 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 108 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_12
	goto AlolaLaboratory_CloseRotomPhoneBackup_9

AlolaLaboratory_CloseRotomPhoneBackup_14:
# 160 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_14
	goto AlolaLaboratory_CloseRotomPhoneBackup_13


AlolaLaboratory_Stufful::
# 198 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 199 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 200 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_STUFFUL, 0
# 201 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Stufful_Text_0
# 202 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 203 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


AlolaLaboratory_Snubull::
# 208 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 209 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 210 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_SNUBBULL, 0
# 211 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Snubull_Text_0
# 212 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 213 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


AlolaLaboratory_Rockruff::
# 218 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 219 "data/maps/AlolaLaboratory/scripts.pory"
	faceplayer
# 220 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 221 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_Rockruff_Text_0
# 222 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 223 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


AlolaLaboratory_FirstTimeIntro::
# 228 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 229 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 19
# 232 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_0
# 233 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 234 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 236 "data/maps/AlolaLaboratory/scripts.pory"
	showobjectat lab_lillie, MAP_ALOLA_LABORATORY
# 237 "data/maps/AlolaLaboratory/scripts.pory"
	startcutscene CUTSCENE_ALOLA_LABORATORY_FIRST_TIME_INTRO
# 245 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_2
# 246 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement LOCALID_PLAYER, AlolaLaboratory_FirstTimeIntro_Movement_2
# 247 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 248 "data/maps/AlolaLaboratory/scripts.pory"
	delay 60
# 249 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 250 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_3
# 251 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 252 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 253 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 254 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_PIN
# 255 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_4
# 256 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_5
# 257 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 261 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 263 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 264 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 265 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_2
# 275 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 276 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 277 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 278 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 279 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 280 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_1, MSGBOX_AUTOCLOSE
AlolaLaboratory_FirstTimeIntro_1:
# 283 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_5
# 284 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_6
# 285 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 286 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 287 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_2
# 289 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 290 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_3, MSGBOX_AUTOCLOSE
# 296 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement LOCALID_PLAYER, AlolaLaboratory_FirstTimeIntro_Movement_7
# 297 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 298 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 299 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 300 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 301 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 302 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_4, MSGBOX_AUTOCLOSE
# 304 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_PIN
# 305 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_FirstTimeIntro_Movement_8
# 306 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 307 "data/maps/AlolaLaboratory/scripts.pory"
	delay 100
# 308 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 309 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_5
# 313 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 314 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_6
# 315 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_9
# 316 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 317 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 318 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_7
# 323 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_FirstTimeIntro_Text_8, AlolaLaboratory_FirstTimeIntro_Text_9
# 324 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_6
# 337 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 338 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 339 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 340 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_10
AlolaLaboratory_FirstTimeIntro_5:
# 347 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 348 "data/maps/AlolaLaboratory/scripts.pory"
	endcutscene
# 349 "data/maps/AlolaLaboratory/scripts.pory"
	openscreenshot 6, 2, AlolaLaboratory_RotomPhoneIntro1
# 350 "data/maps/AlolaLaboratory/scripts.pory"
	openscreenshot 7, 2, AlolaLaboratory_RotomPhoneIntro2
# 351 "data/maps/AlolaLaboratory/scripts.pory"
	openscreenshot 8, 0, AlolaLaboratory_RotomPhoneIntro3
# 352 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_10
# 353 "data/maps/AlolaLaboratory/scripts.pory"
	startcutscene CUTSCENE_ALOLA_LABORATORY_FIRST_TIME_INTRO
# 354 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 355 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 356 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 357 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 358 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_CLICK
# 359 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 360 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 361 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_WHITE
# 362 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_M_MEGA_KICK
# 363 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 364 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_M_SELF_DESTRUCT
# 365 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 366 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_BALL_OPEN
# 367 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 368 "data/maps/AlolaLaboratory/scripts.pory"
	showobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 369 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 14, 11
# 370 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 371 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_1
# 372 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 373 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 374 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 375 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 376 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 377 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_11
# 378 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 379 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 380 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 381 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 382 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_12
# 384 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 385 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 386 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 387 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 388 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_13, MSGBOX_AUTOCLOSE
# 389 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 390 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 391 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 392 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 393 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 394 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_14
# 401 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 402 "data/maps/AlolaLaboratory/scripts.pory"
	playmoncry SPECIES_ROTOM, 0
# 403 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rotom, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 404 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 405 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_15, MSGBOX_AUTOCLOSE
# 406 "data/maps/AlolaLaboratory/scripts.pory"
	waitmoncry
# 407 "data/maps/AlolaLaboratory/scripts.pory"
	waitmessage
# 408 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 409 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_WHITE
# 410 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 411 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 412 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_SWITCH
# 413 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 414 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_CLICK
# 415 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 416 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 15, 17
# 417 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 418 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 2
# 419 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 420 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 421 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_FirstTimeIntro_Movement_11
# 422 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 423 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 424 "data/maps/AlolaLaboratory/scripts.pory"
	rotommenudisplay AlolaLaboratory_FirstTimeIntro_Text_16
# 425 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 426 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_0
# 432 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 433 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 434 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 435 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_2
# 436 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 437 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 438 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 439 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 440 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_10
# 450 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_4
AlolaLaboratory_FirstTimeIntro_9:
# 456 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_CloseRotomPhoneBackup_Text_5, AlolaLaboratory_CloseRotomPhoneBackup_Text_6
# 457 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_14
# 470 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 471 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 472 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 473 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_8
AlolaLaboratory_FirstTimeIntro_13:
# 480 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 481 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_9
# 488 "data/maps/AlolaLaboratory/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, AlolaLaboratory_CloseRotomPhoneBackup_Text_10, AlolaLaboratory_CloseRotomPhoneBackup_Text_11
# 489 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AlolaLaboratory_FirstTimeIntro_18
# 509 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 510 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 511 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 512 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 513 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 514 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 515 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 516 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 517 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_12
AlolaLaboratory_FirstTimeIntro_17:
# 527 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 528 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 529 "data/maps/AlolaLaboratory/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 530 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 531 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_13
# 544 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_3
# 545 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 546 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 547 "data/maps/AlolaLaboratory/scripts.pory"
	checkplayergender
# 548 "data/maps/AlolaLaboratory/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq AlolaLaboratory_FirstTimeIntro_22
# 558 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_15
AlolaLaboratory_FirstTimeIntro_21:
# 564 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 565 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_16, MSGBOX_AUTOCLOSE
# 567 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_4
# 568 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement lab_lillie
# 569 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_EXIT
# 570 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_lillie, MAP_ALOLA_LABORATORY
# 571 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 572 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_5
# 573 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement lab_lillie
# 574 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_OPEN_TRAINER_SCHOOL
# 575 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 576 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_rockruff, MOVEMENT_TYPE_LOOK_AROUND
# 577 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_stufful, MOVEMENT_TYPE_LOOK_AROUND
# 578 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectmovementtype lab_snubbull, MOVEMENT_TYPE_LOOK_AROUND
# 579 "data/maps/AlolaLaboratory/scripts.pory"
	endcutscene
# 580 "data/maps/AlolaLaboratory/scripts.pory"
	helpwindow HELP_ROTOM_PHONE_GUIDE
# 581 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 20
# 582 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end

AlolaLaboratory_FirstTimeIntro_2:
# 266 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 267 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 268 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 269 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 270 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 271 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_0, MSGBOX_AUTOCLOSE
	goto AlolaLaboratory_FirstTimeIntro_1

AlolaLaboratory_FirstTimeIntro_6:
# 325 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_lillie, AlolaLaboratory_CloseRotomPhoneBackup_Movement_0
# 326 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 327 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_CloseRotomPhoneBackup_Text_1
# 328 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_FirstTimeIntro_Text_10
	goto AlolaLaboratory_FirstTimeIntro_5

AlolaLaboratory_FirstTimeIntro_10:
# 442 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_3
	goto AlolaLaboratory_FirstTimeIntro_9

AlolaLaboratory_FirstTimeIntro_14:
# 458 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_1
# 459 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 460 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 461 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_7
	goto AlolaLaboratory_FirstTimeIntro_13

AlolaLaboratory_FirstTimeIntro_18:
# 490 "data/maps/AlolaLaboratory/scripts.pory"
	delay 30
# 491 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_kukui, AlolaLaboratory_CloseRotomPhoneBackup_Movement_2
# 492 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 493 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 494 "data/maps/AlolaLaboratory/scripts.pory"
	playse SE_LEDGE
# 495 "data/maps/AlolaLaboratory/scripts.pory"
	waitse
# 496 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 497 "data/maps/AlolaLaboratory/scripts.pory"
	speakername AlolaLaboratory_Kukui_Text_0
# 498 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_12
	goto AlolaLaboratory_FirstTimeIntro_17

AlolaLaboratory_FirstTimeIntro_22:
# 550 "data/maps/AlolaLaboratory/scripts.pory"
	msgbox AlolaLaboratory_CloseRotomPhoneBackup_Text_14
	goto AlolaLaboratory_FirstTimeIntro_21


AlolaLaboratory_FirstTimeIntroSkip::
# 611 "data/maps/AlolaLaboratory/scripts.pory"
	lock
# 612 "data/maps/AlolaLaboratory/scripts.pory"
	closemessage
# 613 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_TO_BLACK
# 614 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_lillie, MAP_ALOLA_LABORATORY
# 615 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_lillie, 14, 17
# 616 "data/maps/AlolaLaboratory/scripts.pory"
	hideobjectat lab_rotom, MAP_ALOLA_LABORATORY
# 617 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_rotom, 14, 17
# 618 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_IKITOWN_STATE, 20
# 619 "data/maps/AlolaLaboratory/scripts.pory"
	applymovement lab_rockruff, AlolaLaboratory_FirstTimeIntro_Movement_0
# 620 "data/maps/AlolaLaboratory/scripts.pory"
	waitmovement 0
# 621 "data/maps/AlolaLaboratory/scripts.pory"
	setobjectxy lab_kukui, 15, 10
# 622 "data/maps/AlolaLaboratory/scripts.pory"
	special StopAllObjectMovements
# 623 "data/maps/AlolaLaboratory/scripts.pory"
	special CloseScriptMenus
# 626 "data/maps/AlolaLaboratory/scripts.pory"
	setflag FLAG_OPEN_TRAINER_SCHOOL
# 627 "data/maps/AlolaLaboratory/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 2
# 628 "data/maps/AlolaLaboratory/scripts.pory"
	clearflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 629 "data/maps/AlolaLaboratory/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 630 "data/maps/AlolaLaboratory/scripts.pory"
	helpwindow HELP_ROTOM_PHONE_GUIDE
# 631 "data/maps/AlolaLaboratory/scripts.pory"
	release
	end


# 42 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_0:
# 42 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 42 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 46 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_1:
# 46 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
# 46 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
	step_end

# 101 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_2:
# 101 "data/maps/AlolaLaboratory/scripts.pory"
	jump_in_place_down
# 101 "data/maps/AlolaLaboratory/scripts.pory"
	jump_in_place_down
	step_end

# 154 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_3:
# 154 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 154 "data/maps/AlolaLaboratory/scripts.pory"
	delay_8
# 154 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 177 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_4:
# 177 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
# 177 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
# 177 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
	step_end

# 182 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_CloseRotomPhoneBackup_Movement_5:
# 182 "data/maps/AlolaLaboratory/scripts.pory"
	walk_down
	step_end

# 232 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_0:
# 232 "data/maps/AlolaLaboratory/scripts.pory"
	face_right
	step_end

# 233 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_1:
# 233 "data/maps/AlolaLaboratory/scripts.pory"
	face_left
	step_end

# 245 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_2:
# 245 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 245 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 245 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
	step_end

# 250 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_3:
# 250 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_right
# 250 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_right
	step_end

# 255 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_4:
# 255 "data/maps/AlolaLaboratory/scripts.pory"
	emote_exclamation_mark
# 255 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 256 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_5:
# 256 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 256 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 256 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 284 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_6:
# 284 "data/maps/AlolaLaboratory/scripts.pory"
	delay_8
# 284 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 296 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_7:
# 296 "data/maps/AlolaLaboratory/scripts.pory"
	walk_up
# 296 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 296 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 296 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 296 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 305 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_8:
# 305 "data/maps/AlolaLaboratory/scripts.pory"
	emote_question_mark
	step_end

# 315 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_9:
# 315 "data/maps/AlolaLaboratory/scripts.pory"
	face_down
	step_end

# 352 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_10:
# 352 "data/maps/AlolaLaboratory/scripts.pory"
	face_up
# 352 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 352 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 352 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
# 352 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_up
	step_end

# 421 "data/maps/AlolaLaboratory/scripts.pory"
AlolaLaboratory_FirstTimeIntro_Movement_11:
# 421 "data/maps/AlolaLaboratory/scripts.pory"
	delay_16
# 421 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
# 421 "data/maps/AlolaLaboratory/scripts.pory"
	walk_in_place_down
	step_end

AlolaLaboratory_Kukui_Text_0:
# 22 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Kukui$"

AlolaLaboratory_Kukui_Text_1:
# 23 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Pokémon are my totally necessary\n"
	.string "partners in my research.\p"
	.string "Plus we all live here together.\n"
	.string "I guess I'd have to call them family!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_0:
# 36 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Check it out, {PLAYER}!\n"
	.string "Now Rotom can talk right to you!\p"
	.string "It may take it a little while to get\n"
	.string "used to its new job, but I'd say\l"
	.string "Rotom's taken a liking to you!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_1:
# 44 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_2:
# 45 "data/maps/AlolaLaboratory/scripts.pory"
	.string "And this will help how exactly?$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_3:
# 52 "data/maps/AlolaLaboratory/scripts.pory"
	.string "{PLAYER} hasn't been here in Alola\n"
	.string "too long yet.\p"
	.string "So I decided to give him this special\n"
	.string "Phone to help him navigate around.$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_4:
# 60 "data/maps/AlolaLaboratory/scripts.pory"
	.string "{PLAYER} hasn't been here in Alola\n"
	.string "too long yet.\p"
	.string "So I decided to give her this special\n"
	.string "Phone to help her navigate around.$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_5:
# 66 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Thank you!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_6:
# 66 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hi, Rotom!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_7:
# 71 "data/maps/AlolaLaboratory/scripts.pory"
	.string "You can ask Rotom for directions by\n"
	.string "opening the Rotom Phone and\l"
	.string "pressing {R_BUTTON}!\p"
	.string "You can also press the Rotom Reality\n"
	.string "feature to open the {COLOR RED}Town Map{COLOR DARK_GRAY}!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_8:
# 83 "data/maps/AlolaLaboratory/scripts.pory"
	.string "You can see ask Rotom for directions\n"
	.string "by opening the Rotom Phone and\l"
	.string "pressing {R_BUTTON}!\p"
	.string "You can also press the Rotom Reality\n"
	.string "feature to open the {COLOR RED}Town Map{COLOR DARK_GRAY}!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_9:
# 91 "data/maps/AlolaLaboratory/scripts.pory"
	.string "So, {PLAYER}, I'm leaving this Rotom\n"
	.string "Phone in your hands!\p"
	.string "Rotom, you look after {PLAYER}, yeah?\p"
	.string "All right then, {PLAYER}!\n"
	.string "Get a move on!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_10:
# 98 "data/maps/AlolaLaboratory/scripts.pory"
	.string "OK!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_11:
# 98 "data/maps/AlolaLaboratory/scripts.pory"
	.string "What?$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_12:
# 108 "data/maps/AlolaLaboratory/scripts.pory"
	.string "To the Trainers' School!\p"
	.string "You've gotta learn the basics of being\n"
	.string "a Pokémon Trainer through Pokémon\l"
	.string "battling.\p"
	.string "It's a long road to becoming the island\n"
	.string "challenge champion, and the\l"
	.string "Trainers' School is the first step!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_13:
# 141 "data/maps/AlolaLaboratory/scripts.pory"
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
# 160 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie!\n"
	.string "You take care of {PLAYER}, yeah?\p"
	.string "Until he gets used to Rotom,\n"
	.string "help him find his way around!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_15:
# 168 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Lillie!\n"
	.string "You take care of {PLAYER}, yeah?\p"
	.string "Until she gets used to Rotom,\n"
	.string "help her find her way around!$"

AlolaLaboratory_CloseRotomPhoneBackup_Text_16:
# 175 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Of course, Professor Kukui!\n"
	.string "I'll wait outside.$"

AlolaLaboratory_Stufful_Text_0:
# 201 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Ayoo!$"

AlolaLaboratory_Snubull_Text_0:
# 211 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Wroo!$"

AlolaLaboratory_Rockruff_Text_0:
# 221 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Wroof!$"

AlolaLaboratory_FirstTimeIntro_Text_0:
# 271 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "Thanks for getting him for me, Lillie!$"

AlolaLaboratory_FirstTimeIntro_Text_1:
# 280 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "Thanks for getting her for me, Lillie!$"

AlolaLaboratory_FirstTimeIntro_Text_2:
# 287 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Of course. However I can be a help…\n"
	.string "I am supposed to be your assistant.$"

AlolaLaboratory_FirstTimeIntro_Text_3:
# 290 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rockruff's moves were just so stylin',\n"
	.string "and I was making good progress with\l"
	.string "my research.\p"
	.string "Say, {PLAYER}, lemme see your Rotom\n"
	.string "Phone for a second, yeah?$"

AlolaLaboratory_FirstTimeIntro_Text_4:
# 302 "data/maps/AlolaLaboratory/scripts.pory"
	.string "So what do you think of the place?\n"
	.string "Not bad right?$"

AlolaLaboratory_FirstTimeIntro_Text_5:
# 309 "data/maps/AlolaLaboratory/scripts.pory"
	.string "But that's not why I called you here,\n"
	.string "eh?\p"
	.string "Here! It finally arrived!$"

AlolaLaboratory_FirstTimeIntro_Text_6:
# 314 "data/maps/AlolaLaboratory/scripts.pory"
	.string "“It”…?$"

AlolaLaboratory_FirstTimeIntro_Text_7:
# 318 "data/maps/AlolaLaboratory/scripts.pory"
	.string "What's wrong, Lillie? Dont make me\n"
	.string "do all the talking?\p"
	.string "See, there's this Pokémon inside your\n"
	.string "Phone called Rotom…$"

AlolaLaboratory_FirstTimeIntro_Text_8:
# 323 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Really?$"

AlolaLaboratory_FirstTimeIntro_Text_9:
# 323 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rotom?$"

AlolaLaboratory_FirstTimeIntro_Text_10:
# 328 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Oh, I can tell you about Rotom.\p"
	.string "It's a peculiar Pokémon, with a body\n"
	.string "made up of something like\l"
	.string "electricity.\l"
	.string "It can take up residence in machines.$"

AlolaLaboratory_FirstTimeIntro_Text_11:
# 377 "data/maps/AlolaLaboratory/scripts.pory"
	.string "…Kzzzt?$"

AlolaLaboratory_FirstTimeIntro_Text_12:
# 382 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Hey now! Sorry 'bout that, Rotom.\n"
	.string "Guess I surprised you?$"

AlolaLaboratory_FirstTimeIntro_Text_13:
# 388 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Zz-zzt…$"

AlolaLaboratory_FirstTimeIntro_Text_14:
# 394 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Rotom!\p"
	.string "Here, boy!\n"
	.string "I powered up your favorite Phone!\p"
	.string "Give {PLAYER} here a Helping Hand,\n"
	.string "yeah?$"

AlolaLaboratory_FirstTimeIntro_Text_15:
# 405 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Kzzzt…$"

AlolaLaboratory_FirstTimeIntro_Text_16:
# 424 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Uh, hey there! P-pleasure to meet you!\nI-I'm not nervouzzz or anything.$"

AlolaLaboratory_RotomPhoneIntro1::
# 586 "data/maps/AlolaLaboratory/scripts.pory"
	.string "Yeah, buddy! And to put that crazy skill\n"
	.string "of Rotom's to work…$"

AlolaLaboratory_RotomPhoneIntro2::
# 591 "data/maps/AlolaLaboratory/scripts.pory"
	.string "It's the next generation of Phones, but\n"
	.string "it's only complete once Rotom has\l"
	.string "gone into this body specially\l"
	.string "developed for it!$"

AlolaLaboratory_RotomPhoneIntro3::
# 598 "data/maps/AlolaLaboratory/scripts.pory"
	.string "A whole new way for people and Pokémon\n"
	.string "to communicate. Woo!\p"
	.string "And there's only a few of these\n"
	.string "beauties out in the world so far!\p"
	.string "And now if I power up your Rotom Phone\n"
	.string "with the parts that I just got in…$"
