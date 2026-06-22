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


Ikitown_trigger_WecomeToIkitownSkip::
# 33 "data/maps/IkiTown/scripts.pory"
	closemessage
# 34 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 35 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 36 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 37 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 38 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 39 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 40 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 41 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 42 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 43 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui, 33, 28
# 44 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 45 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 46 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau, MAP_IKI_TOWN
# 47 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 48 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 49 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_WecomeToIkitown::
# 54 "data/maps/IkiTown/scripts.pory"
	lock
# 55 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 56 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 57 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 58 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 59 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownhau, MAP_IKI_TOWN_SOUTH
# 60 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownkukui, MAP_IKI_TOWN_SOUTH
# 61 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 62 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 63 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_WELCOME_TO_IKITOWN
# 64 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_0
# 65 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_1
# 66 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 67 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 68 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_2
# 69 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_3
# 70 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 71 "data/maps/IkiTown/scripts.pory"
	delay 30
# 72 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 73 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 74 "data/maps/IkiTown/scripts.pory"
	delay 30
# 75 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 76 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 77 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_4
# 78 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 79 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 80 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_1, MSGBOX_AUTOCLOSE
# 82 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 83 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_5
# 84 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 85 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_6
# 86 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 87 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 88 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_2
# 94 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 95 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_7
# 96 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 97 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 98 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 99 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_8
# 100 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 101 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 102 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_3
# 108 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_4
# 109 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 110 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 111 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_5
# 114 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_9
# 115 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 116 "data/maps/IkiTown/scripts.pory"
	waitse
# 117 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 118 "data/maps/IkiTown/scripts.pory"
	waitse
# 119 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 120 "data/maps/IkiTown/scripts.pory"
	switch VAR_STARTER_MON
# 121 "data/maps/IkiTown/scripts.pory"
	case 0, Ikitown_trigger_WecomeToIkitown_3
# 125 "data/maps/IkiTown/scripts.pory"
	case 1, Ikitown_trigger_WecomeToIkitown_4
# 129 "data/maps/IkiTown/scripts.pory"
	case 2, Ikitown_trigger_WecomeToIkitown_5
Ikitown_trigger_WecomeToIkitown_1:
# 134 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_10
# 135 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 136 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau
# 137 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_4
# 138 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 139 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 140 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_9
# 152 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_9
# 153 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 154 "data/maps/IkiTown/scripts.pory"
	waitse
# 155 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 156 "data/maps/IkiTown/scripts.pory"
	waitse
# 157 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 158 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_10
# 164 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 165 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 166 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 167 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_trigger_WecomeToIkitown_3:
# 122 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_6, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_4:
# 126 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_7, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_5:
# 130 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_8, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1


Ikitown_KukuiSeeTapuKoko::
# 172 "data/maps/IkiTown/scripts.pory"
	lock
# 173 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 174 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 175 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 177 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Trigger_KukuiSeeTapuKoko::
# 183 "data/maps/IkiTown/scripts.pory"
	lock
# 184 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 185 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 186 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 187 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0
# 188 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 189 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 190 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 192 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_2
# 193 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MainSign::
# 198 "data/maps/IkiTown/scripts.pory"
	lock
# 199 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MainSign_Text_0
# 202 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 203 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyWRockruff::
# 208 "data/maps/IkiTown/scripts.pory"
	lock
# 209 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 210 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyWRockruff_Text_0
# 214 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 215 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Rockruff::
# 220 "data/maps/IkiTown/scripts.pory"
	lock
# 221 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 222 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 223 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Rockruff_Text_0
# 224 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 225 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LeftSideGuy::
# 230 "data/maps/IkiTown/scripts.pory"
	lock
# 231 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 232 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeftSideGuy_Text_0
# 234 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 235 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MomwithChild::
# 240 "data/maps/IkiTown/scripts.pory"
	lock
# 241 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 242 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MomwithChild_Text_0
# 248 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 249 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ChildwithMom::
# 254 "data/maps/IkiTown/scripts.pory"
	lock
# 255 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 256 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ChildwithMom_Text_0
# 260 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 261 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_DontForgetToSave::
# 266 "data/maps/IkiTown/scripts.pory"
	lock
# 267 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 268 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_DontForgetToSave_Text_0
# 273 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 274 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_KahunaGivesWisdom::
# 279 "data/maps/IkiTown/scripts.pory"
	lock
# 280 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 281 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KahunaGivesWisdom_Text_0
# 284 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ManBlockingDoor::
# 289 "data/maps/IkiTown/scripts.pory"
	lock
# 290 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 291 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ManBlockingDoor_Text_0
# 299 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Meowth::
# 304 "data/maps/IkiTown/scripts.pory"
	lock
# 305 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 306 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 307 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Meowth_Text_0
# 308 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 309 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_sign_Ruinsofconflict::
# 314 "data/maps/IkiTown/scripts.pory"
	lock
# 315 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_sign_Ruinsofconflict_Text_0
# 316 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 317 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_GetPokedex::
# 322 "data/maps/IkiTown/scripts.pory"
	lock
# 323 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GET_POKEDEX
# 324 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_0
# 325 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_1
# 326 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 327 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 328 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_2
# 329 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 330 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 331 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_0
# 335 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_3
# 336 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 337 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_1
# 339 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 340 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 341 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 342 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_3
# 349 "data/maps/IkiTown/scripts.pory"
	checkplayergender
# 350 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_GetPokedex_2
# 359 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 360 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_5
Ikitown_GetPokedex_1:
# 366 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_trigger_WecomeToIkitown_Movement_4
# 367 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 368 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 369 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_6, MSGBOX_AUTOCLOSE
# 373 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 374 "data/maps/IkiTown/scripts.pory"
	delay 30
# 376 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_5
# 377 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 378 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownman1, Ikitown_GetPokedex_Movement_6
# 379 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownoldman1, Ikitown_GetPokedex_Movement_6
# 380 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 381 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 382 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 383 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_7, MSGBOX_AUTOCLOSE
# 390 "data/maps/IkiTown/scripts.pory"
	delay 30
# 391 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_7
# 392 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_8
# 393 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 394 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 395 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_9, MSGBOX_AUTOCLOSE
# 396 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_9
# 397 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 398 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_10
# 399 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 400 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 401 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_10
# 403 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_11
# 404 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 405 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 406 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 407 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 408 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_11
# 417 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 418 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 419 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 420 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_12
# 434 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_3
# 435 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 436 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 437 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_13
# 439 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_3
# 440 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 441 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 442 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_14
# 446 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_3
# 447 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 448 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_15
# 464 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_12
# 465 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_13
# 466 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 467 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 468 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_16
# 470 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 471 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 472 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 473 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 474 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_17
# 475 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 476 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 477 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 478 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 479 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_18
# 489 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_19, MSGBOX_AUTOCLOSE
# 493 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 494 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 495 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_14
# 496 "data/maps/IkiTown/scripts.pory"
	delay 60
# 497 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 498 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 499 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 500 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_GetPokedex_2:
# 351 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 352 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_4
	goto Ikitown_GetPokedex_1


Ikitown_GetPokedexSkip::
# 505 "data/maps/IkiTown/scripts.pory"
	closemessage
# 506 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 507 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 508 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 509 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 510 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 511 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 512 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 513 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 515 "data/maps/IkiTown/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 14
# 516 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 521 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 522 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 523 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui2
# 524 "data/maps/IkiTown/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_IKI_TOWN
# 525 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownlillie, MAP_IKI_TOWN
# 526 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownhala, MAP_IKI_TOWN
# 527 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownintrokukui2, MAP_IKI_TOWN
# 528 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 21, 13
# 529 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 14
# 530 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 13
# 531 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_10
# 532 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 533 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedexSkip_Movement_0
# 534 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 535 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 536 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 537 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_lilliedialog2::
# 542 "data/maps/IkiTown/scripts.pory"
	lock
# 543 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 544 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 545 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 546 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_lilliedialog2_Text_0
# 550 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 551 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_kukuidialog2::
# 556 "data/maps/IkiTown/scripts.pory"
	lock
# 557 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 558 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 559 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_kukuidialog2_Text_0
# 562 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 563 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_haladialog2::
# 568 "data/maps/IkiTown/scripts.pory"
	lock
# 569 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 570 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 571 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_haladialog2_Text_0
# 574 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 575 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_GiveHalaSparklingStone::
# 580 "data/maps/IkiTown/scripts.pory"
	lock
# 581 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GIVE_HALA_SPARKLING_STONE
# 582 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 583 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_0, MSGBOX_AUTOCLOSE
# 585 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 586 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_WecomeToIkitown_Movement_8
# 587 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 588 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 589 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 12
# 590 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 12
# 591 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 592 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 593 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 594 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 595 "data/maps/IkiTown/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 596 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_3
Ikitown_trigger_GiveHalaSparklingStone_1:
# 604 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_8
Ikitown_trigger_GiveHalaSparklingStone_6:
# 612 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_13
Ikitown_trigger_GiveHalaSparklingStone_11:
# 618 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_18
Ikitown_trigger_GiveHalaSparklingStone_16:
# 624 "data/maps/IkiTown/scripts.pory"
	delay 30
# 625 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 626 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_5
# 627 "data/maps/IkiTown/scripts.pory"
	delay 60
# 628 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_6
# 629 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 630 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 631 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 632 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 633 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_1
# 635 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_4
# 636 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 637 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 638 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_2
# 644 "data/maps/IkiTown/scripts.pory"
	setvar VAR_RESULT, 1
# 645 "data/maps/IkiTown/scripts.pory"
	playse SE_M_DETECT
# 646 "data/maps/IkiTown/scripts.pory"
	dofieldeffectsparkle 24, 14, 0
# 647 "data/maps/IkiTown/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 648 "data/maps/IkiTown/scripts.pory"
	closemessage
# 649 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 650 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_7
# 651 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 652 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 653 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 654 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 655 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 656 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_3
# 662 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_8
# 663 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 664 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 665 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_4
# 666 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_4
# 667 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 668 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 669 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_5
# 670 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitown_Movement_4
# 671 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 672 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 673 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_6
# 676 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_trigger_GiveHalaSparklingStone_Text_7, Ikitown_trigger_GiveHalaSparklingStone_Text_8
# 677 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_22
# 698 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 699 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
Ikitown_trigger_GiveHalaSparklingStone_21:
# 717 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_GiveHalaSparklingStone_Movement_9
# 718 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 719 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 720 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_10
# 722 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedexSkip_Movement_0
# 723 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_11
# 729 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 730 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 731 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 732 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_12
# 734 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 735 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 736 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 737 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 738 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 739 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 740 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 741 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 742 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 743 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 744 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 745 "data/maps/IkiTown/scripts.pory"
	waitstate
	return

Ikitown_trigger_GiveHalaSparklingStone_2:
# 597 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_0
# 598 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 599 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 600 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 601 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 602 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_3:
# 596 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_2
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_7:
# 605 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_2
# 606 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 607 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 608 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 609 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 610 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_8:
# 604 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_7
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_12:
# 613 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_3
# 614 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 615 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 616 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_13:
# 612 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_12
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_17:
# 619 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_4
# 620 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 621 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 622 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_18:
# 618 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_17
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_22:
# 678 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 679 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
	goto Ikitown_trigger_GiveHalaSparklingStone_21


Ikitown_trigger_GiveHalaSparklingStoneSkip::
# 749 "data/maps/IkiTown/scripts.pory"
	closemessage
# 750 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 751 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 752 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 753 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 754 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 755 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 756 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 757 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 758 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 759 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 760 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 761 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 762 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 763 "data/maps/IkiTown/scripts.pory"
	waitstate
# 764 "data/maps/IkiTown/scripts.pory"
	release
	end


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

# 44 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitownSkip_Movement_0:
# 44 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 64 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_0:
# 64 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 64 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 64 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 64 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 64 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 64 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 64 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 64 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 64 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 65 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_1:
# 65 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 65 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 65 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 65 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 65 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 65 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 65 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 65 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 65 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 68 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_2:
# 68 "data/maps/IkiTown/scripts.pory"
	walk_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 69 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_3:
# 69 "data/maps/IkiTown/scripts.pory"
	delay_16
# 69 "data/maps/IkiTown/scripts.pory"
	delay_16
# 69 "data/maps/IkiTown/scripts.pory"
	delay_16
# 69 "data/maps/IkiTown/scripts.pory"
	delay_16
# 69 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 69 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 69 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 69 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 69 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 69 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 69 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 69 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 77 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_4:
# 77 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
# 77 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
	step_end

# 83 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_5:
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 83 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
	step_end

# 85 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_6:
# 85 "data/maps/IkiTown/scripts.pory"
	walk_up
# 85 "data/maps/IkiTown/scripts.pory"
	walk_up
# 85 "data/maps/IkiTown/scripts.pory"
	walk_up
# 85 "data/maps/IkiTown/scripts.pory"
	walk_up
# 85 "data/maps/IkiTown/scripts.pory"
	walk_up
# 85 "data/maps/IkiTown/scripts.pory"
	walk_up
# 85 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 95 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_7:
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 95 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 99 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_8:
# 99 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 114 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_9:
# 114 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
# 114 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
	step_end

# 134 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_10:
# 134 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 134 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 134 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 134 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 134 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 134 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 134 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 134 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 187 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0:
# 187 "data/maps/IkiTown/scripts.pory"
	face_down
# 187 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 188 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1:
# 188 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 192 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_2:
# 192 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 324 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_0:
# 324 "data/maps/IkiTown/scripts.pory"
	walk_down
# 324 "data/maps/IkiTown/scripts.pory"
	walk_down
# 324 "data/maps/IkiTown/scripts.pory"
	walk_down
# 324 "data/maps/IkiTown/scripts.pory"
	walk_down
# 324 "data/maps/IkiTown/scripts.pory"
	walk_down
# 324 "data/maps/IkiTown/scripts.pory"
	walk_down
# 324 "data/maps/IkiTown/scripts.pory"
	walk_left
# 324 "data/maps/IkiTown/scripts.pory"
	walk_left
# 324 "data/maps/IkiTown/scripts.pory"
	walk_left
# 324 "data/maps/IkiTown/scripts.pory"
	walk_left
# 324 "data/maps/IkiTown/scripts.pory"
	walk_left
# 324 "data/maps/IkiTown/scripts.pory"
	walk_left
# 324 "data/maps/IkiTown/scripts.pory"
	walk_down
# 324 "data/maps/IkiTown/scripts.pory"
	walk_down
# 324 "data/maps/IkiTown/scripts.pory"
	walk_down
# 324 "data/maps/IkiTown/scripts.pory"
	walk_down
# 324 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 324 "data/maps/IkiTown/scripts.pory"
	walk_right
# 324 "data/maps/IkiTown/scripts.pory"
	walk_right
# 324 "data/maps/IkiTown/scripts.pory"
	walk_right
# 324 "data/maps/IkiTown/scripts.pory"
	walk_up
# 324 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 325 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_1:
# 325 "data/maps/IkiTown/scripts.pory"
	delay_16
# 325 "data/maps/IkiTown/scripts.pory"
	delay_16
# 325 "data/maps/IkiTown/scripts.pory"
	delay_16
# 325 "data/maps/IkiTown/scripts.pory"
	walk_down
# 325 "data/maps/IkiTown/scripts.pory"
	walk_down
# 325 "data/maps/IkiTown/scripts.pory"
	walk_down
# 325 "data/maps/IkiTown/scripts.pory"
	walk_down
# 325 "data/maps/IkiTown/scripts.pory"
	walk_down
# 325 "data/maps/IkiTown/scripts.pory"
	walk_down
# 325 "data/maps/IkiTown/scripts.pory"
	walk_left
# 325 "data/maps/IkiTown/scripts.pory"
	walk_left
# 325 "data/maps/IkiTown/scripts.pory"
	walk_left
# 325 "data/maps/IkiTown/scripts.pory"
	walk_left
# 325 "data/maps/IkiTown/scripts.pory"
	walk_left
# 325 "data/maps/IkiTown/scripts.pory"
	walk_down
# 325 "data/maps/IkiTown/scripts.pory"
	walk_down
# 325 "data/maps/IkiTown/scripts.pory"
	walk_down
# 325 "data/maps/IkiTown/scripts.pory"
	walk_down
# 325 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 325 "data/maps/IkiTown/scripts.pory"
	walk_right
# 325 "data/maps/IkiTown/scripts.pory"
	walk_right
# 325 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 328 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_2:
# 328 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 328 "data/maps/IkiTown/scripts.pory"
	walk_down
# 328 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 335 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_3:
# 335 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
# 335 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
	step_end

# 339 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_4:
# 339 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
# 339 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
	step_end

# 376 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_5:
# 376 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 376 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 376 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 376 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 376 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 376 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 376 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 376 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 376 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
	step_end

# 378 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_6:
# 378 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 378 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 391 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_7:
# 391 "data/maps/IkiTown/scripts.pory"
	walk_down
# 391 "data/maps/IkiTown/scripts.pory"
	delay_16
# 391 "data/maps/IkiTown/scripts.pory"
	delay_16
# 391 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 392 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_8:
# 392 "data/maps/IkiTown/scripts.pory"
	walk_up
# 392 "data/maps/IkiTown/scripts.pory"
	walk_up
# 392 "data/maps/IkiTown/scripts.pory"
	walk_up
# 392 "data/maps/IkiTown/scripts.pory"
	walk_up
# 392 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 396 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_9:
# 396 "data/maps/IkiTown/scripts.pory"
	walk_left
# 396 "data/maps/IkiTown/scripts.pory"
	walk_left
# 396 "data/maps/IkiTown/scripts.pory"
	walk_left
# 396 "data/maps/IkiTown/scripts.pory"
	walk_left
# 396 "data/maps/IkiTown/scripts.pory"
	walk_left
# 396 "data/maps/IkiTown/scripts.pory"
	walk_left
# 396 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 398 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_10:
# 398 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 403 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_11:
# 403 "data/maps/IkiTown/scripts.pory"
	walk_left
# 403 "data/maps/IkiTown/scripts.pory"
	walk_left
# 403 "data/maps/IkiTown/scripts.pory"
	walk_left
# 403 "data/maps/IkiTown/scripts.pory"
	walk_left
# 403 "data/maps/IkiTown/scripts.pory"
	walk_diag_northwest
# 403 "data/maps/IkiTown/scripts.pory"
	walk_left
# 403 "data/maps/IkiTown/scripts.pory"
	walk_left
# 403 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 464 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_12:
# 464 "data/maps/IkiTown/scripts.pory"
	walk_down
# 464 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 465 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_13:
# 465 "data/maps/IkiTown/scripts.pory"
	walk_left
# 465 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 495 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_14:
# 495 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 495 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 495 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 533 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedexSkip_Movement_0:
# 533 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 597 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_0:
# 597 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 597 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 597 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 597 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 601 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_1:
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 601 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 605 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_2:
# 605 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 605 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 605 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 605 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 605 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 605 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 613 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_3:
# 613 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 613 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 613 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 613 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 613 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 613 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 613 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 613 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 619 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_4:
# 619 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 619 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 619 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 619 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 619 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 619 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 619 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 619 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 619 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 626 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_5:
# 626 "data/maps/IkiTown/scripts.pory"
	walk_right
# 626 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 626 "data/maps/IkiTown/scripts.pory"
	walk_right
# 626 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 628 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_6:
# 628 "data/maps/IkiTown/scripts.pory"
	walk_down
# 628 "data/maps/IkiTown/scripts.pory"
	delay_8
# 628 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 650 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_7:
# 650 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 662 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_8:
# 662 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
# 662 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
	step_end

# 717 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_9:
# 717 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

Ikitown_trigger_WecomeToIkitown_Text_0:
# 79 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

Ikitown_trigger_WecomeToIkitown_Text_1:
# 80 "data/maps/IkiTown/scripts.pory"
	.string "And we're here!\n"
	.string "This right here is Iki Town!$"

Ikitown_trigger_WecomeToIkitown_Text_2:
# 88 "data/maps/IkiTown/scripts.pory"
	.string "This town is where folks come to\n"
	.string "worship the Pokemon that watches\l"
	.string "over Melemele Island.\p"
	.string "Tapu Koko keeps us all safe and\n"
	.string "happy, see!$"

Ikitown_trigger_WecomeToIkitown_Text_3:
# 102 "data/maps/IkiTown/scripts.pory"
	.string "Looks like the kahuna's nowhere to be\n"
	.string "found, though…\p"
	.string "I guess there must be some trouble\n"
	.string "somewhere on the island that needs\l"
	.string "fixing, yeah?$"

Ikitown_trigger_WecomeToIkitown_Text_4:
# 110 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

Ikitown_trigger_WecomeToIkitown_Text_5:
# 111 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, the kahuna wandered off without\n"
	.string "a word to anybody, singing a little\l"
	.string "ditty or something.$"

Ikitown_trigger_WecomeToIkitown_Text_6:
# 122 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Popplio!$"

Ikitown_trigger_WecomeToIkitown_Text_7:
# 126 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Rowlet!$"

Ikitown_trigger_WecomeToIkitown_Text_8:
# 130 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Litten!$"

Ikitown_trigger_WecomeToIkitown_Text_9:
# 140 "data/maps/IkiTown/scripts.pory"
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
# 158 "data/maps/IkiTown/scripts.pory"
	.string "If you're really lucky, maybe you'll\n"
	.string "actually get a glimpse of the\l"
	.string "guardian deity yourself!\p"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_KukuiSeeTapuKoko_Text_0:
# 175 "data/maps/IkiTown/scripts.pory"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_MainSign_Text_0:
# 199 "data/maps/IkiTown/scripts.pory"
	.string "Iki Town\n"
	.string "“The place where we give thanks to\l"
	.string "Pokémon.”$"

Ikitown_LittleBoyWRockruff_Text_0:
# 210 "data/maps/IkiTown/scripts.pory"
	.string "Hey, you've got a Pokémon! I want one,\n"
	.string "too!\p"
	.string "Where'd you get yours?$"

Ikitown_Rockruff_Text_0:
# 223 "data/maps/IkiTown/scripts.pory"
	.string "Ruff ruff!$"

Ikitown_LeftSideGuy_Text_0:
# 232 "data/maps/IkiTown/scripts.pory"
	.string "Welcome to Iki Town, the town watched\n"
	.string "over by Pokémon!$"

Ikitown_MomwithChild_Text_0:
# 242 "data/maps/IkiTown/scripts.pory"
	.string "If you treat your Pokémon wrong, the\n"
	.string "guardian deity will strike you down\l"
	.string "with lightning!\p"
	.string "But the children all laugh when I tell\n"
	.string "them that.$"

Ikitown_ChildwithMom_Text_0:
# 256 "data/maps/IkiTown/scripts.pory"
	.string "I want to meet the guardian deity!\p"
	.string "Maybe I should cause some mischief for\n"
	.string "a Pokémon…$"

Ikitown_DontForgetToSave_Text_0:
# 268 "data/maps/IkiTown/scripts.pory"
	.string "Don't forget to save!\p"
	.string "If you want to remember everything\n"
	.string "that's happened, you must not\l"
	.string "forget to save!$"

Ikitown_KahunaGivesWisdom_Text_0:
# 281 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna gives us wisdom and\n"
	.string "guidance and teaches us how to live\l"
	.string "with our Pokémon.$"

Ikitown_ManBlockingDoor_Text_0:
# 291 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala is the strongest Pokémon\n"
	.string "Trainer on all of Melemele!\p"
	.string "There must be some trouble going down\n"
	.string "somewhere on the island that needs\l"
	.string "a kahuna's touch, 'cause he said\l"
	.string "something about how it's “Time\l"
	.string "for old Hala!” and off he went…$"

Ikitown_Meowth_Text_0:
# 307 "data/maps/IkiTown/scripts.pory"
	.string "Hsss!$"

Ikitown_sign_Ruinsofconflict_Text_0:
# 315 "data/maps/IkiTown/scripts.pory"
	.string "Ruins of Conflict$"

Ikitown_GetPokedex_Text_0:
# 331 "data/maps/IkiTown/scripts.pory"
	.string "Oh, {PLAYER}!\n"
	.string "You already met Lillie, huh?\p"
	.string "She's my assistant, yeah!$"

Ikitown_GetPokedex_Text_1:
# 337 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, I thought you were with the\n"
	.string "kahuna?$"

Ikitown_GetPokedex_Text_2:
# 341 "data/maps/IkiTown/scripts.pory"
	.string "Lillie$"

Ikitown_GetPokedex_Text_3:
# 342 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala? He said that he had\n"
	.string "something to attend to, so he left\l"
	.string "town on his own.\p"
	.string "I was just, um, taking a little stroll\n"
	.string "up Mahalo Trail while I waited for\l"
	.string "him to return…$"

Ikitown_GetPokedex_Text_4:
# 352 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "He just got to Alola yesterday.\n"
	.string "Help him find his way around, yeah?$"

Ikitown_GetPokedex_Text_5:
# 360 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "She just got to Alola yesterday.\n"
	.string "Help her find her way around, yeah?$"

Ikitown_GetPokedex_Text_6:
# 369 "data/maps/IkiTown/scripts.pory"
	.string "So…you're also one of\n"
	.string "the professor's acquaintances?\p"
	.string "It's nice to meet you.$"

Ikitown_GetPokedex_Text_7:
# 383 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna is back!\n"
	.string "Kahuna Hala has returned!\p"
	.string "Our guardian's chosen one is back!\p"
	.string "Only one of the strongest Pokémon\n"
	.string "users in all Alola, yeah!$"

Ikitown_GetPokedex_Text_8:
# 394 "data/maps/IkiTown/scripts.pory"
	.string "Hala$"

Ikitown_GetPokedex_Text_9:
# 395 "data/maps/IkiTown/scripts.pory"
	.string "Have I missed something?$"

Ikitown_GetPokedex_Text_10:
# 401 "data/maps/IkiTown/scripts.pory"
	.string "There you are, Kahuna Hala!\n"
	.string "Was there some kind of trouble?$"

Ikitown_GetPokedex_Text_11:
# 408 "data/maps/IkiTown/scripts.pory"
	.string "Ahaha! Just got caught up in the\n"
	.string "middle of some brawling Rockruff,\l"
	.string "that's all!\p"
	.string "Sorry, Lillie.\n"
	.string "What were you saying before?\p"
	.string "For some reason I thought I saw\n"
	.string "Tapu Koko flying about…$"

Ikitown_GetPokedex_Text_12:
# 420 "data/maps/IkiTown/scripts.pory"
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
# 437 "data/maps/IkiTown/scripts.pory"
	.string "Woo! That's something you don't hear\n"
	.string "every day!$"

Ikitown_GetPokedex_Text_14:
# 442 "data/maps/IkiTown/scripts.pory"
	.string "Ho! Although it is said to protect us,\n"
	.string "our Tapu Koko is a rather fickle\l"
	.string "creature.\l"
	.string "Yet our guardian was moved to save you.$"

Ikitown_GetPokedex_Text_15:
# 448 "data/maps/IkiTown/scripts.pory"
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
# 468 "data/maps/IkiTown/scripts.pory"
	.string "All right, here's a lovely gift to\n"
	.string "help make today special {PLAYER}!$"

Ikitown_GetPokedex_Text_17:
# 474 "data/maps/IkiTown/scripts.pory"
	.string "You obtained a {COLOR RED}Rotom Phone{COLOR DARK_GRAY}!$"

Ikitown_GetPokedex_Text_18:
# 479 "data/maps/IkiTown/scripts.pory"
	.string "The Rotom Phone comes equipped with a\n"
	.string "Pokédex, which is a really high-tech\l"
	.string "kinda tool, that can automatically\l"
	.string "record facts about any Pokémon that\l"
	.string "you meet.\p"
	.string "Your new partner, {STR_VAR_1} is\n"
	.string "already registered, oh yeah, so\l"
	.string "check it out!$"

Ikitown_GetPokedex_Text_19:
# 489 "data/maps/IkiTown/scripts.pory"
	.string "Well, you got to meet the kahuna\n"
	.string "at least.\p"
	.string "Ready to head home now, {PLAYER}?$"

ikitown_lilliedialog2_Text_0:
# 546 "data/maps/IkiTown/scripts.pory"
	.string "I really, um, really appreciate what you\n"
	.string "did for us on the Plank Bridge.\p"
	.string "I won't forget you and {STR_VAR_1}…$"

ikitown_kukuidialog2_Text_0:
# 559 "data/maps/IkiTown/scripts.pory"
	.string "Now that you met Tapu Koko, I can't\n"
	.string "wait to see how far you can go as a\l"
	.string "Pokémon Trainer!$"

ikitown_haladialog2_Text_0:
# 571 "data/maps/IkiTown/scripts.pory"
	.string "If you two can work in harmony with\n"
	.string "each other, you can go anywhere\l"
	.string "together!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_0:
# 583 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah! {PLAYER}!\n"
	.string "Hold up a sec!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_1:
# 633 "data/maps/IkiTown/scripts.pory"
	.string "What is it Hau? Did you forget\n"
	.string "something?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_2:
# 638 "data/maps/IkiTown/scripts.pory"
	.string "You're seriously asking me that?!\p"
	.string "Who's the one here who forgot to tell\n"
	.string "anyone before wandering off for a\l"
	.string "little stroll and a sing without a\l"
	.string "word, huh?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_3:
# 656 "data/maps/IkiTown/scripts.pory"
	.string "Hm?\n"
	.string "{PLAYER}…\p"
	.string "Would you be so kind as to give me a\n"
	.string "look at that {COLOR RED}Sparkling Stone{COLOR DARK_GRAY} you\l"
	.string "have there?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_4:
# 665 "data/maps/IkiTown/scripts.pory"
	.string "Could it be?!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_5:
# 669 "data/maps/IkiTown/scripts.pory"
	.string "Tutu, isn't that…$"

Ikitown_trigger_GiveHalaSparklingStone_Text_6:
# 673 "data/maps/IkiTown/scripts.pory"
	.string "You were rescued by Tapu Koko at the\n"
	.string "bridge-isn't that what I heard,\l"
	.string "{PLAYER}?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_7:
# 676 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, it rescued me$"

Ikitown_trigger_GiveHalaSparklingStone_Text_8:
# 676 "data/maps/IkiTown/scripts.pory"
	.string "It gave me a stone$"

Ikitown_trigger_GiveHalaSparklingStone_Text_9:
# 679 "data/maps/IkiTown/scripts.pory"
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
# 720 "data/maps/IkiTown/scripts.pory"
	.string "First I'll make sure you get back home\n"
	.string "safe today, though, {PLAYER}.$"

Ikitown_trigger_GiveHalaSparklingStone_Text_11:
# 723 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, you two should come with us\n"
	.string "too, yeah.\p"
	.string "Wouldn't want to go losing you twice\n"
	.string "in one day.\l"
	.string "You or that precious Pokémon of yours!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_12:
# 732 "data/maps/IkiTown/scripts.pory"
	.string "Yes…\n"
	.string "I will key an eye on Nebby$"
