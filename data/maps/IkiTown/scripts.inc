IkiTown_MapScripts::
# 2 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 5 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 15 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IkiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	end

IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 5 "data/maps/IkiTown/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 6, IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 6 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 7 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_HALA
# 8 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 9 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 23, 5
# 10 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 11 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 32, 19
# 12 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 13 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 9, 14
	return

IkiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 15 "data/maps/IkiTown/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 6, Ikitown_GetPokedex
	.2byte 0


Ikitown_trigger_right::
# 19 "data/maps/IkiTown/scripts.pory"
	lock
# 20 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_right_Movement_0
# 21 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 22 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_left::
# 26 "data/maps/IkiTown/scripts.pory"
	lock
# 27 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_left_Movement_0
# 28 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 29 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_WecomeToIkitown::
# 33 "data/maps/IkiTown/scripts.pory"
	lock
# 34 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 35 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 36 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 37 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 38 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownhau, MAP_IKI_TOWN_SOUTH
# 39 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownkukui, MAP_IKI_TOWN_SOUTH
# 40 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 41 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 42 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_0
# 43 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_1
# 44 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 45 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 46 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_2
# 47 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_3
# 48 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 49 "data/maps/IkiTown/scripts.pory"
	delay 30
# 50 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_4
# 51 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 52 "data/maps/IkiTown/scripts.pory"
	delay 30
# 53 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_4
# 54 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 55 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_5
# 56 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 57 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 58 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_1, MSGBOX_AUTOCLOSE
# 60 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 61 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_6
# 62 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 63 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_7
# 64 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 65 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 66 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_2
# 72 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 73 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_8
# 74 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 75 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 76 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 77 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_9
# 78 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 79 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 80 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_3
# 86 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_5
# 87 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 88 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 89 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_5
# 92 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_10
# 93 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 94 "data/maps/IkiTown/scripts.pory"
	waitse
# 95 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 96 "data/maps/IkiTown/scripts.pory"
	waitse
# 97 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 98 "data/maps/IkiTown/scripts.pory"
	switch VAR_STARTER_MON
# 99 "data/maps/IkiTown/scripts.pory"
	case 0, Ikitown_trigger_WecomeToIkitown_3
# 103 "data/maps/IkiTown/scripts.pory"
	case 1, Ikitown_trigger_WecomeToIkitown_4
# 107 "data/maps/IkiTown/scripts.pory"
	case 2, Ikitown_trigger_WecomeToIkitown_5
Ikitown_trigger_WecomeToIkitown_1:
# 112 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_11
# 113 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 114 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau
# 115 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_5
# 116 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 117 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 118 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_9
# 130 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_10
# 131 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 132 "data/maps/IkiTown/scripts.pory"
	waitse
# 133 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 134 "data/maps/IkiTown/scripts.pory"
	waitse
# 135 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 136 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_10
# 142 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 143 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 144 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_trigger_WecomeToIkitown_3:
# 100 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_6, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_4:
# 104 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_7, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_5:
# 108 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_8, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1


Ikitown_KukuiSeeTapuKoko::
# 149 "data/maps/IkiTown/scripts.pory"
	lock
# 150 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 151 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 152 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 154 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Trigger_KukuiSeeTapuKoko::
# 160 "data/maps/IkiTown/scripts.pory"
	lock
# 161 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 162 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 163 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 164 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0
# 165 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 166 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 167 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 169 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_2
# 170 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MainSign::
# 175 "data/maps/IkiTown/scripts.pory"
	lock
# 176 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MainSign_Text_0
# 179 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 180 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyWRockruff::
# 185 "data/maps/IkiTown/scripts.pory"
	lock
# 186 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 187 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyWRockruff_Text_0
# 191 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 192 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Rockruff::
# 197 "data/maps/IkiTown/scripts.pory"
	lock
# 198 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 199 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 200 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Rockruff_Text_0
# 201 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 202 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LeftSideGuy::
# 207 "data/maps/IkiTown/scripts.pory"
	lock
# 208 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 209 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeftSideGuy_Text_0
# 211 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 212 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MomwithChild::
# 217 "data/maps/IkiTown/scripts.pory"
	lock
# 218 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 219 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MomwithChild_Text_0
# 225 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 226 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ChildwithMom::
# 231 "data/maps/IkiTown/scripts.pory"
	lock
# 232 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 233 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ChildwithMom_Text_0
# 237 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 238 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_DontForgetToSave::
# 243 "data/maps/IkiTown/scripts.pory"
	lock
# 244 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 245 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_DontForgetToSave_Text_0
# 250 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 251 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_KahunaGivesWisdom::
# 256 "data/maps/IkiTown/scripts.pory"
	lock
# 257 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 258 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KahunaGivesWisdom_Text_0
# 261 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ManBlockingDoor::
# 266 "data/maps/IkiTown/scripts.pory"
	lock
# 267 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 268 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ManBlockingDoor_Text_0
# 276 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Meowth::
# 281 "data/maps/IkiTown/scripts.pory"
	lock
# 282 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 283 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 284 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Meowth_Text_0
# 285 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 286 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_sign_Ruinsofconflict::
# 291 "data/maps/IkiTown/scripts.pory"
	lock
# 292 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_sign_Ruinsofconflict_Text_0
# 293 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 294 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_GetPokedex::
# 299 "data/maps/IkiTown/scripts.pory"
	lock
# 300 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GET_POKEDEX
# 301 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_0
# 302 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_1
# 303 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 304 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 305 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_2
# 306 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 307 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 308 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_0
# 312 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_3
# 313 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 314 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_1
# 316 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 317 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 318 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 319 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_3
# 326 "data/maps/IkiTown/scripts.pory"
	checkplayergender
# 327 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_GetPokedex_2
# 336 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 337 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_5
Ikitown_GetPokedex_1:
# 343 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_trigger_WecomeToIkitown_Movement_5
# 344 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 345 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 346 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_6, MSGBOX_AUTOCLOSE
# 350 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 351 "data/maps/IkiTown/scripts.pory"
	delay 30
# 353 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_5
# 354 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 355 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownman1, Ikitown_GetPokedex_Movement_6
# 356 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownoldman1, Ikitown_GetPokedex_Movement_6
# 357 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 358 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 359 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 360 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_7, MSGBOX_AUTOCLOSE
# 367 "data/maps/IkiTown/scripts.pory"
	delay 30
# 368 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_7
# 369 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_8
# 370 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 371 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 372 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_9, MSGBOX_AUTOCLOSE
# 373 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_9
# 374 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 375 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_10
# 376 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 377 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 378 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_10
# 380 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_11
# 381 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 382 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitown_Movement_4
# 383 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 384 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 385 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_11
# 394 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 395 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 396 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 397 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_12
# 411 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_3
# 412 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 413 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 414 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_13
# 416 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_3
# 417 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 418 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 419 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_14
# 423 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_3
# 424 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 425 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_15
# 441 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_12
# 442 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_13
# 443 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 444 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 445 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_16
# 447 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 448 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 449 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 450 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 451 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_17
# 452 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 453 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 454 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 455 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 456 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_18
# 466 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_19, MSGBOX_AUTOCLOSE
# 470 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 471 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 472 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_14
# 473 "data/maps/IkiTown/scripts.pory"
	delay 60
# 474 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 475 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 476 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 477 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_GetPokedex_2:
# 328 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 329 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_4
	goto Ikitown_GetPokedex_1


Ikitown_GetPokedexSkip::
# 482 "data/maps/IkiTown/scripts.pory"
	closemessage
# 483 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 484 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 485 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 486 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 487 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 488 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 489 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 490 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 492 "data/maps/IkiTown/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 14
# 493 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 497 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 498 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 499 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui2
# 500 "data/maps/IkiTown/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_IKI_TOWN
# 501 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownlillie, MAP_IKI_TOWN
# 502 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownhala, MAP_IKI_TOWN
# 503 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownintrokukui2, MAP_IKI_TOWN
# 504 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 21, 13
# 505 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 14
# 506 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 13
# 507 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_10
# 508 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 509 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedexSkip_Movement_0
# 510 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitown_Movement_4
# 511 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 512 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_lilliedialog2::
# 517 "data/maps/IkiTown/scripts.pory"
	lock
# 518 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 519 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 520 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 521 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_lilliedialog2_Text_0
# 525 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 526 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_kukuidialog2::
# 531 "data/maps/IkiTown/scripts.pory"
	lock
# 532 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 533 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 534 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_kukuidialog2_Text_0
# 537 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 538 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_haladialog2::
# 543 "data/maps/IkiTown/scripts.pory"
	lock
# 544 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 545 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 546 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_haladialog2_Text_0
# 549 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 550 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_GiveHalaSparklingStone::
# 555 "data/maps/IkiTown/scripts.pory"
	lock
# 556 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 557 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_0, MSGBOX_AUTOCLOSE
# 559 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 560 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_WecomeToIkitown_Movement_9
# 561 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 562 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 563 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 12
# 564 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 12
# 565 "data/maps/IkiTown/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 566 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_3
Ikitown_trigger_GiveHalaSparklingStone_1:
# 574 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_8
Ikitown_trigger_GiveHalaSparklingStone_6:
# 582 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_13
Ikitown_trigger_GiveHalaSparklingStone_11:
# 588 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_18
Ikitown_trigger_GiveHalaSparklingStone_16:
# 594 "data/maps/IkiTown/scripts.pory"
	delay 30
# 595 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 596 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_5
# 597 "data/maps/IkiTown/scripts.pory"
	delay 60
# 598 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_6
# 599 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 600 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 601 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 602 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 603 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_1
# 605 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_4
# 606 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 607 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 608 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_2
# 614 "data/maps/IkiTown/scripts.pory"
	setvar VAR_RESULT, 1
# 615 "data/maps/IkiTown/scripts.pory"
	playse SE_M_DETECT
# 616 "data/maps/IkiTown/scripts.pory"
	dofieldeffectsparkle 24, 14, 0
# 617 "data/maps/IkiTown/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 618 "data/maps/IkiTown/scripts.pory"
	closemessage
# 619 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 620 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_7
# 621 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 622 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitown_Movement_4
# 623 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 624 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 625 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 626 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_3
# 632 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_8
# 633 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 634 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 635 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_4
# 636 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_4
# 637 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 638 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 639 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_5
# 640 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitown_Movement_5
# 641 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 642 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 643 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_6
# 646 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_trigger_GiveHalaSparklingStone_Text_7, Ikitown_trigger_GiveHalaSparklingStone_Text_8
# 647 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_22
# 668 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 669 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
Ikitown_trigger_GiveHalaSparklingStone_21:
# 687 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_GiveHalaSparklingStone_Movement_9
# 688 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 689 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 690 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_10
# 692 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedexSkip_Movement_0
# 693 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_11
# 699 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 700 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 701 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 702 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_12
# 704 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 705 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 706 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 707 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 708 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 709 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 710 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 711 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 712 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 713 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 714 "data/maps/IkiTown/scripts.pory"
	waitstate
	return

Ikitown_trigger_GiveHalaSparklingStone_2:
# 567 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_0
# 568 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 569 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 570 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 571 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 572 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_3:
# 566 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_2
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_7:
# 575 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_2
# 576 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 577 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 578 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 579 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 580 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_8:
# 574 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_7
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_12:
# 583 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_3
# 584 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 585 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 586 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_13:
# 582 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_12
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_17:
# 589 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_4
# 590 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 591 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 592 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_18:
# 588 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_17
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_22:
# 648 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 649 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
	goto Ikitown_trigger_GiveHalaSparklingStone_21


# 20 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_right_Movement_0:
# 20 "data/maps/IkiTown/scripts.pory"
	walk_left
# 20 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 27 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_left_Movement_0:
# 27 "data/maps/IkiTown/scripts.pory"
	walk_right
# 27 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 42 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_0:
# 42 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 42 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 42 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 42 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 42 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 42 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 42 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 42 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 42 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 43 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_1:
# 43 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 43 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 43 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 43 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 43 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 43 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 43 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 43 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 43 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 46 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_2:
# 46 "data/maps/IkiTown/scripts.pory"
	walk_up
# 46 "data/maps/IkiTown/scripts.pory"
	walk_up
# 46 "data/maps/IkiTown/scripts.pory"
	walk_up
# 46 "data/maps/IkiTown/scripts.pory"
	walk_up
# 46 "data/maps/IkiTown/scripts.pory"
	walk_up
# 46 "data/maps/IkiTown/scripts.pory"
	walk_up
# 46 "data/maps/IkiTown/scripts.pory"
	walk_up
# 46 "data/maps/IkiTown/scripts.pory"
	walk_up
# 46 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 47 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_3:
# 47 "data/maps/IkiTown/scripts.pory"
	delay_16
# 47 "data/maps/IkiTown/scripts.pory"
	delay_16
# 47 "data/maps/IkiTown/scripts.pory"
	delay_16
# 47 "data/maps/IkiTown/scripts.pory"
	delay_16
# 47 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 47 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 47 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 47 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 47 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 47 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 47 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 47 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 50 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_4:
# 50 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 55 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_5:
# 55 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
# 55 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
	step_end

# 61 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_6:
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 61 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
	step_end

# 63 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_7:
# 63 "data/maps/IkiTown/scripts.pory"
	walk_up
# 63 "data/maps/IkiTown/scripts.pory"
	walk_up
# 63 "data/maps/IkiTown/scripts.pory"
	walk_up
# 63 "data/maps/IkiTown/scripts.pory"
	walk_up
# 63 "data/maps/IkiTown/scripts.pory"
	walk_up
# 63 "data/maps/IkiTown/scripts.pory"
	walk_up
# 63 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 73 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_8:
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 73 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 77 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_9:
# 77 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 92 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_10:
# 92 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
# 92 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
	step_end

# 112 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_11:
# 112 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 112 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 112 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 112 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 112 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 112 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 112 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 112 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 164 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0:
# 164 "data/maps/IkiTown/scripts.pory"
	face_down
# 164 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 165 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1:
# 165 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 169 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_2:
# 169 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 301 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_0:
# 301 "data/maps/IkiTown/scripts.pory"
	walk_down
# 301 "data/maps/IkiTown/scripts.pory"
	walk_down
# 301 "data/maps/IkiTown/scripts.pory"
	walk_down
# 301 "data/maps/IkiTown/scripts.pory"
	walk_down
# 301 "data/maps/IkiTown/scripts.pory"
	walk_down
# 301 "data/maps/IkiTown/scripts.pory"
	walk_down
# 301 "data/maps/IkiTown/scripts.pory"
	walk_left
# 301 "data/maps/IkiTown/scripts.pory"
	walk_left
# 301 "data/maps/IkiTown/scripts.pory"
	walk_left
# 301 "data/maps/IkiTown/scripts.pory"
	walk_left
# 301 "data/maps/IkiTown/scripts.pory"
	walk_left
# 301 "data/maps/IkiTown/scripts.pory"
	walk_left
# 301 "data/maps/IkiTown/scripts.pory"
	walk_down
# 301 "data/maps/IkiTown/scripts.pory"
	walk_down
# 301 "data/maps/IkiTown/scripts.pory"
	walk_down
# 301 "data/maps/IkiTown/scripts.pory"
	walk_down
# 301 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 301 "data/maps/IkiTown/scripts.pory"
	walk_right
# 301 "data/maps/IkiTown/scripts.pory"
	walk_right
# 301 "data/maps/IkiTown/scripts.pory"
	walk_right
# 301 "data/maps/IkiTown/scripts.pory"
	walk_up
# 301 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 302 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_1:
# 302 "data/maps/IkiTown/scripts.pory"
	delay_16
# 302 "data/maps/IkiTown/scripts.pory"
	delay_16
# 302 "data/maps/IkiTown/scripts.pory"
	delay_16
# 302 "data/maps/IkiTown/scripts.pory"
	walk_down
# 302 "data/maps/IkiTown/scripts.pory"
	walk_down
# 302 "data/maps/IkiTown/scripts.pory"
	walk_down
# 302 "data/maps/IkiTown/scripts.pory"
	walk_down
# 302 "data/maps/IkiTown/scripts.pory"
	walk_down
# 302 "data/maps/IkiTown/scripts.pory"
	walk_down
# 302 "data/maps/IkiTown/scripts.pory"
	walk_left
# 302 "data/maps/IkiTown/scripts.pory"
	walk_left
# 302 "data/maps/IkiTown/scripts.pory"
	walk_left
# 302 "data/maps/IkiTown/scripts.pory"
	walk_left
# 302 "data/maps/IkiTown/scripts.pory"
	walk_left
# 302 "data/maps/IkiTown/scripts.pory"
	walk_down
# 302 "data/maps/IkiTown/scripts.pory"
	walk_down
# 302 "data/maps/IkiTown/scripts.pory"
	walk_down
# 302 "data/maps/IkiTown/scripts.pory"
	walk_down
# 302 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 302 "data/maps/IkiTown/scripts.pory"
	walk_right
# 302 "data/maps/IkiTown/scripts.pory"
	walk_right
# 302 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 305 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_2:
# 305 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 305 "data/maps/IkiTown/scripts.pory"
	walk_down
# 305 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 312 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_3:
# 312 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
# 312 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
	step_end

# 316 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_4:
# 316 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
# 316 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
	step_end

# 353 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_5:
# 353 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 353 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 353 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 353 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 353 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 353 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 353 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 353 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 353 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
	step_end

# 355 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_6:
# 355 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 355 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 368 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_7:
# 368 "data/maps/IkiTown/scripts.pory"
	walk_down
# 368 "data/maps/IkiTown/scripts.pory"
	delay_16
# 368 "data/maps/IkiTown/scripts.pory"
	delay_16
# 368 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 369 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_8:
# 369 "data/maps/IkiTown/scripts.pory"
	walk_up
# 369 "data/maps/IkiTown/scripts.pory"
	walk_up
# 369 "data/maps/IkiTown/scripts.pory"
	walk_up
# 369 "data/maps/IkiTown/scripts.pory"
	walk_up
# 369 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 373 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_9:
# 373 "data/maps/IkiTown/scripts.pory"
	walk_left
# 373 "data/maps/IkiTown/scripts.pory"
	walk_left
# 373 "data/maps/IkiTown/scripts.pory"
	walk_left
# 373 "data/maps/IkiTown/scripts.pory"
	walk_left
# 373 "data/maps/IkiTown/scripts.pory"
	walk_left
# 373 "data/maps/IkiTown/scripts.pory"
	walk_left
# 373 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 375 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_10:
# 375 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 380 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_11:
# 380 "data/maps/IkiTown/scripts.pory"
	walk_left
# 380 "data/maps/IkiTown/scripts.pory"
	walk_left
# 380 "data/maps/IkiTown/scripts.pory"
	walk_left
# 380 "data/maps/IkiTown/scripts.pory"
	walk_left
# 380 "data/maps/IkiTown/scripts.pory"
	walk_diag_northwest
# 380 "data/maps/IkiTown/scripts.pory"
	walk_left
# 380 "data/maps/IkiTown/scripts.pory"
	walk_left
# 380 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 441 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_12:
# 441 "data/maps/IkiTown/scripts.pory"
	walk_down
# 441 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 442 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_13:
# 442 "data/maps/IkiTown/scripts.pory"
	walk_left
# 442 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 472 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_14:
# 472 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 472 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 472 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 509 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedexSkip_Movement_0:
# 509 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 567 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_0:
# 567 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 567 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 567 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 567 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 571 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_1:
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 571 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 575 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_2:
# 575 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 575 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 575 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 575 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 575 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 575 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 583 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_3:
# 583 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 583 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 583 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 583 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 583 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 583 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 583 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 583 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 589 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_4:
# 589 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 589 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 589 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 589 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 589 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 589 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 589 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 589 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 589 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 596 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_5:
# 596 "data/maps/IkiTown/scripts.pory"
	walk_right
# 596 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 596 "data/maps/IkiTown/scripts.pory"
	walk_right
# 596 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 598 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_6:
# 598 "data/maps/IkiTown/scripts.pory"
	walk_down
# 598 "data/maps/IkiTown/scripts.pory"
	delay_8
# 598 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 620 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_7:
# 620 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 632 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_8:
# 632 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
# 632 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
	step_end

# 687 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_9:
# 687 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

Ikitown_trigger_WecomeToIkitown_Text_0:
# 57 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

Ikitown_trigger_WecomeToIkitown_Text_1:
# 58 "data/maps/IkiTown/scripts.pory"
	.string "And we're here!\n"
	.string "This right here is Iki Town!$"

Ikitown_trigger_WecomeToIkitown_Text_2:
# 66 "data/maps/IkiTown/scripts.pory"
	.string "This town is where folks come to\n"
	.string "worship the Pokemon that watches\l"
	.string "over Melemele Island.\p"
	.string "Tapu Koko keeps us all safe and\n"
	.string "happy, see!$"

Ikitown_trigger_WecomeToIkitown_Text_3:
# 80 "data/maps/IkiTown/scripts.pory"
	.string "Looks like the kahuna's nowhere to be\n"
	.string "found, though…\p"
	.string "I guess there must be some trouble\n"
	.string "somewhere on the island that needs\l"
	.string "fixing, yeah?$"

Ikitown_trigger_WecomeToIkitown_Text_4:
# 88 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

Ikitown_trigger_WecomeToIkitown_Text_5:
# 89 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, the kahuna wandered off without\n"
	.string "a word to anybody, singing a little\l"
	.string "ditty or something.$"

Ikitown_trigger_WecomeToIkitown_Text_6:
# 100 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Popplio!$"

Ikitown_trigger_WecomeToIkitown_Text_7:
# 104 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Rowlet!$"

Ikitown_trigger_WecomeToIkitown_Text_8:
# 108 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Litten!$"

Ikitown_trigger_WecomeToIkitown_Text_9:
# 118 "data/maps/IkiTown/scripts.pory"
	.string "Hey, I've got an idea for you,\n"
	.string "{PLAYER}.\p"
	.string "If you head through the village and\n"
	.string "up the hill, you can visit the ruins\l"
	.string "that belong to Tapu Koko.\p"
	.string "That's our island's guardian deity,\n"
	.string "yeah.\p"
	.string "Why don't you go and introduce\n"
	.string "yourself?$"

Ikitown_trigger_WecomeToIkitown_Text_10:
# 136 "data/maps/IkiTown/scripts.pory"
	.string "If you're really lucky, maybe you'll\n"
	.string "actually get a glimpse of the\l"
	.string "guardian deity yourself!\p"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_KukuiSeeTapuKoko_Text_0:
# 152 "data/maps/IkiTown/scripts.pory"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_MainSign_Text_0:
# 176 "data/maps/IkiTown/scripts.pory"
	.string "Iki Town\n"
	.string "“The place where we give thanks to\l"
	.string "Pokémon.”$"

Ikitown_LittleBoyWRockruff_Text_0:
# 187 "data/maps/IkiTown/scripts.pory"
	.string "Hey, you've got a Pokémon! I want one,\n"
	.string "too!\p"
	.string "Where'd you get yours?$"

Ikitown_Rockruff_Text_0:
# 200 "data/maps/IkiTown/scripts.pory"
	.string "Ruff ruff!$"

Ikitown_LeftSideGuy_Text_0:
# 209 "data/maps/IkiTown/scripts.pory"
	.string "Welcome to Iki Town, the town watched\n"
	.string "over by Pokémon!$"

Ikitown_MomwithChild_Text_0:
# 219 "data/maps/IkiTown/scripts.pory"
	.string "If you treat your Pokémon wrong, the\n"
	.string "guardian deity will strike you down\l"
	.string "with lightning!\p"
	.string "But the children all laugh when I tell\n"
	.string "them that.$"

Ikitown_ChildwithMom_Text_0:
# 233 "data/maps/IkiTown/scripts.pory"
	.string "I want to meet the guardian deity!\p"
	.string "Maybe I should cause some mischief for\n"
	.string "a Pokémon…$"

Ikitown_DontForgetToSave_Text_0:
# 245 "data/maps/IkiTown/scripts.pory"
	.string "Don't forget to save!\p"
	.string "If you want to remember everything\n"
	.string "that's happened, you must not\l"
	.string "forget to save!$"

Ikitown_KahunaGivesWisdom_Text_0:
# 258 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna gives us wisdom and\n"
	.string "guidance and teaches us how to live\l"
	.string "with our Pokémon.$"

Ikitown_ManBlockingDoor_Text_0:
# 268 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala is the strongest Pokémon\n"
	.string "Trainer on all of Melemele!\p"
	.string "There must be some trouble going down\n"
	.string "somewhere on the island that needs\l"
	.string "a kahuna's touch, 'cause he said\l"
	.string "something about how it's “Time\l"
	.string "for old Hala!” and off he went…$"

Ikitown_Meowth_Text_0:
# 284 "data/maps/IkiTown/scripts.pory"
	.string "Hsss!$"

Ikitown_sign_Ruinsofconflict_Text_0:
# 292 "data/maps/IkiTown/scripts.pory"
	.string "Ruins of Conflict$"

Ikitown_GetPokedex_Text_0:
# 308 "data/maps/IkiTown/scripts.pory"
	.string "Oh, {PLAYER}!\n"
	.string "You already met Lillie, huh?\p"
	.string "She's my assistant, yeah!$"

Ikitown_GetPokedex_Text_1:
# 314 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, I thought you were with the\n"
	.string "kahuna?$"

Ikitown_GetPokedex_Text_2:
# 318 "data/maps/IkiTown/scripts.pory"
	.string "Lillie$"

Ikitown_GetPokedex_Text_3:
# 319 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala? He said that he had\n"
	.string "something to attend to, so he left\l"
	.string "town on his own.\p"
	.string "I was just, um, taking a little stroll\n"
	.string "up Mahalo Trail while I waited for\l"
	.string "him to return…$"

Ikitown_GetPokedex_Text_4:
# 329 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "He just got to Alola yesterday.\n"
	.string "Help him find his way around, yeah?$"

Ikitown_GetPokedex_Text_5:
# 337 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "She just got to Alola yesterday.\n"
	.string "Help her find her way around, yeah?$"

Ikitown_GetPokedex_Text_6:
# 346 "data/maps/IkiTown/scripts.pory"
	.string "So…you're also one of\n"
	.string "the professor's acquaintances?\p"
	.string "It's nice to meet you.$"

Ikitown_GetPokedex_Text_7:
# 360 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna is back!\n"
	.string "Kahuna Hala has returned!\p"
	.string "Our guardian's chosen one is back!\p"
	.string "Only one of the strongest Pokémon\n"
	.string "users in all Alola, yeah!$"

Ikitown_GetPokedex_Text_8:
# 371 "data/maps/IkiTown/scripts.pory"
	.string "Hala$"

Ikitown_GetPokedex_Text_9:
# 372 "data/maps/IkiTown/scripts.pory"
	.string "Have I missed something?$"

Ikitown_GetPokedex_Text_10:
# 378 "data/maps/IkiTown/scripts.pory"
	.string "There you are, Kahuna Hala!\n"
	.string "Was there some kind of trouble?$"

Ikitown_GetPokedex_Text_11:
# 385 "data/maps/IkiTown/scripts.pory"
	.string "Ahaha! Just got caught up in the\n"
	.string "middle of some brawling Rockruff,\l"
	.string "that's all!\p"
	.string "Sorry, Lillie.\n"
	.string "What were you saying before?\p"
	.string "For some reason I thought I saw\n"
	.string "Tapu Koko flying about…$"

Ikitown_GetPokedex_Text_12:
# 397 "data/maps/IkiTown/scripts.pory"
	.string "Oh, um…\n"
	.string "Yes, Kahuna Hala…\p"
	.string "Nebby got attacked by some Wingull\n"
	.string "on the Plank Bridge.\p"
	.string "And {PLAYER} here helped protect it.\p"
	.string "But the bridge collapsed, and I thought\n"
	.string "both of them might fall to the\l"
	.string "bottom of the ravine…\p"
	.string "And that was when the island's guardian\n"
	.string "deity, swooped in to save them!$"

Ikitown_GetPokedex_Text_13:
# 414 "data/maps/IkiTown/scripts.pory"
	.string "Woo! That's something you don't hear\n"
	.string "every day!$"

Ikitown_GetPokedex_Text_14:
# 419 "data/maps/IkiTown/scripts.pory"
	.string "Ho! Although it is said to protect us,\n"
	.string "our Tapu Koko is a rather fickle\l"
	.string "creature.\l"
	.string "Yet our guardian was moved to save you.$"

Ikitown_GetPokedex_Text_15:
# 425 "data/maps/IkiTown/scripts.pory"
	.string "Kukui, my boy, I think we have\n"
	.string "cause to celebrate!\p"
	.string "Looks like we have a brave and kind new\n"
	.string "Pokémon Trainer in our midst!\p"
	.string "I'm glad to meet you, child.\n"
	.string "I'm Hala, the kahuna of Melemele\l"
	.string "Island.\p"
	.string "Welcome to Alola!\n"
	.string "Young Kukui had told me of your\l"
	.string "coming.\p"
	.string "I'm glad we had the chance to meet\n"
	.string "today.$"

Ikitown_GetPokedex_Text_16:
# 445 "data/maps/IkiTown/scripts.pory"
	.string "All right, here's a lovely gift to\n"
	.string "help make today special {PLAYER}!$"

Ikitown_GetPokedex_Text_17:
# 451 "data/maps/IkiTown/scripts.pory"
	.string "You obtained a {COLOR RED}Rotom Phone{COLOR DARK_GRAY}!$"

Ikitown_GetPokedex_Text_18:
# 456 "data/maps/IkiTown/scripts.pory"
	.string "The Rotom Phone comes equipped with a\n"
	.string "Pokédex, which is a really high-tech\l"
	.string "kinda tool, that can automatically\l"
	.string "record facts about any Pokémon that\l"
	.string "you meet.\p"
	.string "Your new partner, {STR_VAR_1} is\n"
	.string "already registered, oh yeah, so\l"
	.string "check it out!$"

Ikitown_GetPokedex_Text_19:
# 466 "data/maps/IkiTown/scripts.pory"
	.string "Well, you got to meet the kahuna\n"
	.string "at least.\p"
	.string "Ready to head home now, {PLAYER}?$"

ikitown_lilliedialog2_Text_0:
# 521 "data/maps/IkiTown/scripts.pory"
	.string "I really, um, really appreciate what you\n"
	.string "did for us on the Plank Bridge.\p"
	.string "I won't forget you and {STR_VAR_1}…$"

ikitown_kukuidialog2_Text_0:
# 534 "data/maps/IkiTown/scripts.pory"
	.string "Now that you met Tapu Koko, I can't\n"
	.string "wait to see how far you can go as a\l"
	.string "Pokémon Trainer!$"

ikitown_haladialog2_Text_0:
# 546 "data/maps/IkiTown/scripts.pory"
	.string "If you two can work in harmony with\n"
	.string "each other, you can go anywhere\l"
	.string "together!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_0:
# 557 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah! {PLAYER}!\n"
	.string "Hold up a sec!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_1:
# 603 "data/maps/IkiTown/scripts.pory"
	.string "What is it Hau? Did you forget\n"
	.string "something?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_2:
# 608 "data/maps/IkiTown/scripts.pory"
	.string "You're seriously asking me that?!\p"
	.string "Who's the one here who forgot to tell\n"
	.string "anyone before wandering off for a\l"
	.string "little stroll and a sing without a\l"
	.string "word, huh?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_3:
# 626 "data/maps/IkiTown/scripts.pory"
	.string "Hm?\n"
	.string "{PLAYER}…\p"
	.string "Would you be so kind as to give me a\n"
	.string "look at that {COLOR RED}Sparkling Stone{COLOR DARK_GRAY} you\l"
	.string "have there?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_4:
# 635 "data/maps/IkiTown/scripts.pory"
	.string "Could it be?!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_5:
# 639 "data/maps/IkiTown/scripts.pory"
	.string "Tutu, isn't that…$"

Ikitown_trigger_GiveHalaSparklingStone_Text_6:
# 643 "data/maps/IkiTown/scripts.pory"
	.string "You were rescued by Tapu Koko at the\n"
	.string "bridge-isn't that what I heard,\l"
	.string "{PLAYER}?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_7:
# 646 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, it rescued me$"

Ikitown_trigger_GiveHalaSparklingStone_Text_8:
# 646 "data/maps/IkiTown/scripts.pory"
	.string "It gave me a stone$"

Ikitown_trigger_GiveHalaSparklingStone_Text_9:
# 649 "data/maps/IkiTown/scripts.pory"
	.string "So it even deigned to give you a stone…\p"
	.string "Perhaps you are here in Alola,\n"
	.string "{PLAYER}, because this is where\l"
	.string "you are meant to be.\p"
	.string "Allow me to borrow this stone for now.\p"
	.string "Fret not, I will return it to you\n"
	.string "tomorrow evening.\p"
	.string "You have the makings of a brilliant\n"
	.string "Trainer.\l"
	.string "I can see that light within you, too.\p"
	.string "You must do us the honor of joining in\n"
	.string "our festival tomorrow!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_10:
# 690 "data/maps/IkiTown/scripts.pory"
	.string "First I'll make sure you get back home\n"
	.string "safe today, though, {PLAYER}.$"

Ikitown_trigger_GiveHalaSparklingStone_Text_11:
# 693 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, you two should come with us\n"
	.string "too, yeah.\p"
	.string "Wouldn't want to go losing you twice\n"
	.string "in one day.\l"
	.string "You or that precious Pokémon of yours!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_12:
# 702 "data/maps/IkiTown/scripts.pory"
	.string "Yes…\n"
	.string "I will key an eye on Nebby$"
