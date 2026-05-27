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
	removeobject ikitownintrohau
# 47 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 48 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_WecomeToIkitown::
# 53 "data/maps/IkiTown/scripts.pory"
	lock
# 54 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 55 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 56 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 57 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 58 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownhau, MAP_IKI_TOWN_SOUTH
# 59 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownkukui, MAP_IKI_TOWN_SOUTH
# 60 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 61 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 62 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_WELCOME_TO_IKITOWN
# 63 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_0
# 64 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_1
# 65 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 66 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 67 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_2
# 68 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_3
# 69 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 70 "data/maps/IkiTown/scripts.pory"
	delay 30
# 71 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 72 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 73 "data/maps/IkiTown/scripts.pory"
	delay 30
# 74 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 75 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 76 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_4
# 77 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 78 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 79 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_1, MSGBOX_AUTOCLOSE
# 81 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 82 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_5
# 83 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 84 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_6
# 85 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 86 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 87 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_2
# 93 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 94 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_7
# 95 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 96 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 97 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 98 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_8
# 99 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 100 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 101 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_3
# 107 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_4
# 108 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 109 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 110 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_5
# 113 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_9
# 114 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 115 "data/maps/IkiTown/scripts.pory"
	waitse
# 116 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 117 "data/maps/IkiTown/scripts.pory"
	waitse
# 118 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 119 "data/maps/IkiTown/scripts.pory"
	switch VAR_STARTER_MON
# 120 "data/maps/IkiTown/scripts.pory"
	case 0, Ikitown_trigger_WecomeToIkitown_3
# 124 "data/maps/IkiTown/scripts.pory"
	case 1, Ikitown_trigger_WecomeToIkitown_4
# 128 "data/maps/IkiTown/scripts.pory"
	case 2, Ikitown_trigger_WecomeToIkitown_5
Ikitown_trigger_WecomeToIkitown_1:
# 133 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_10
# 134 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 135 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau
# 136 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_4
# 137 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 138 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 139 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_9
# 151 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_9
# 152 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 153 "data/maps/IkiTown/scripts.pory"
	waitse
# 154 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 155 "data/maps/IkiTown/scripts.pory"
	waitse
# 156 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 157 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_10
# 163 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 164 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 165 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 166 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_trigger_WecomeToIkitown_3:
# 121 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_6, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_4:
# 125 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_7, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_5:
# 129 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_8, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1


Ikitown_KukuiSeeTapuKoko::
# 171 "data/maps/IkiTown/scripts.pory"
	lock
# 172 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 173 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 174 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 176 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Trigger_KukuiSeeTapuKoko::
# 182 "data/maps/IkiTown/scripts.pory"
	lock
# 183 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 184 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 185 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 186 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0
# 187 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 188 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 189 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 191 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_2
# 192 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MainSign::
# 197 "data/maps/IkiTown/scripts.pory"
	lock
# 198 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MainSign_Text_0
# 201 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 202 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyWRockruff::
# 207 "data/maps/IkiTown/scripts.pory"
	lock
# 208 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 209 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyWRockruff_Text_0
# 213 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 214 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Rockruff::
# 219 "data/maps/IkiTown/scripts.pory"
	lock
# 220 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 221 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 222 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Rockruff_Text_0
# 223 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 224 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LeftSideGuy::
# 229 "data/maps/IkiTown/scripts.pory"
	lock
# 230 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 231 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeftSideGuy_Text_0
# 233 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 234 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MomwithChild::
# 239 "data/maps/IkiTown/scripts.pory"
	lock
# 240 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 241 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MomwithChild_Text_0
# 247 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 248 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ChildwithMom::
# 253 "data/maps/IkiTown/scripts.pory"
	lock
# 254 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 255 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ChildwithMom_Text_0
# 259 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 260 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_DontForgetToSave::
# 265 "data/maps/IkiTown/scripts.pory"
	lock
# 266 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 267 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_DontForgetToSave_Text_0
# 272 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 273 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_KahunaGivesWisdom::
# 278 "data/maps/IkiTown/scripts.pory"
	lock
# 279 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 280 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KahunaGivesWisdom_Text_0
# 283 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ManBlockingDoor::
# 288 "data/maps/IkiTown/scripts.pory"
	lock
# 289 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 290 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ManBlockingDoor_Text_0
# 298 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Meowth::
# 303 "data/maps/IkiTown/scripts.pory"
	lock
# 304 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 305 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 306 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Meowth_Text_0
# 307 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 308 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_sign_Ruinsofconflict::
# 313 "data/maps/IkiTown/scripts.pory"
	lock
# 314 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_sign_Ruinsofconflict_Text_0
# 315 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 316 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_GetPokedex::
# 321 "data/maps/IkiTown/scripts.pory"
	lock
# 322 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GET_POKEDEX
# 323 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_0
# 324 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_1
# 325 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 326 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 327 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_2
# 328 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 329 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 330 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_0
# 334 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_3
# 335 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 336 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_1
# 338 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 339 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 340 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 341 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_3
# 348 "data/maps/IkiTown/scripts.pory"
	checkplayergender
# 349 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_GetPokedex_2
# 358 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 359 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_5
Ikitown_GetPokedex_1:
# 365 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_trigger_WecomeToIkitown_Movement_4
# 366 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 367 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 368 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_6, MSGBOX_AUTOCLOSE
# 372 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 373 "data/maps/IkiTown/scripts.pory"
	delay 30
# 375 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_5
# 376 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 377 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownman1, Ikitown_GetPokedex_Movement_6
# 378 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownoldman1, Ikitown_GetPokedex_Movement_6
# 379 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 380 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 381 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 382 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_7, MSGBOX_AUTOCLOSE
# 389 "data/maps/IkiTown/scripts.pory"
	delay 30
# 390 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_7
# 391 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_8
# 392 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 393 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 394 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_9, MSGBOX_AUTOCLOSE
# 395 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_9
# 396 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 397 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_10
# 398 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 399 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 400 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_10
# 402 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_11
# 403 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 404 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 405 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 406 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 407 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_11
# 416 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 417 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 418 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 419 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_12
# 433 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_3
# 434 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 435 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 436 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_13
# 438 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_3
# 439 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 440 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 441 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_14
# 445 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_3
# 446 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 447 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_15
# 463 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_12
# 464 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_13
# 465 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 466 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 467 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_16
# 469 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 470 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 471 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 472 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 473 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_17
# 474 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 475 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 476 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 477 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 478 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_18
# 488 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_19, MSGBOX_AUTOCLOSE
# 492 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 493 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 494 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_14
# 495 "data/maps/IkiTown/scripts.pory"
	delay 60
# 496 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 497 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 498 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 499 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_GetPokedex_2:
# 350 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 351 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_4
	goto Ikitown_GetPokedex_1


Ikitown_GetPokedexSkip::
# 504 "data/maps/IkiTown/scripts.pory"
	closemessage
# 505 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 506 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 507 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 508 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 509 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 510 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 511 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 512 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 514 "data/maps/IkiTown/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 14
# 515 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 520 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 521 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 522 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui2
# 523 "data/maps/IkiTown/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_IKI_TOWN
# 524 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownlillie, MAP_IKI_TOWN
# 525 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownhala, MAP_IKI_TOWN
# 526 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownintrokukui2, MAP_IKI_TOWN
# 527 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 21, 13
# 528 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 14
# 529 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 13
# 530 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_10
# 531 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 532 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedexSkip_Movement_0
# 533 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 534 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 535 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 536 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_lilliedialog2::
# 541 "data/maps/IkiTown/scripts.pory"
	lock
# 542 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 543 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 544 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 545 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_lilliedialog2_Text_0
# 549 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 550 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_kukuidialog2::
# 555 "data/maps/IkiTown/scripts.pory"
	lock
# 556 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 557 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 558 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_kukuidialog2_Text_0
# 561 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 562 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_haladialog2::
# 567 "data/maps/IkiTown/scripts.pory"
	lock
# 568 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 569 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 570 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_haladialog2_Text_0
# 573 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 574 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_GiveHalaSparklingStone::
# 579 "data/maps/IkiTown/scripts.pory"
	lock
# 580 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GIVE_HALA_SPARKLING_STONE
# 581 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 582 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_0, MSGBOX_AUTOCLOSE
# 584 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 585 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_WecomeToIkitown_Movement_8
# 586 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 587 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 588 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 12
# 589 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 12
# 590 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 591 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 592 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 593 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 594 "data/maps/IkiTown/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 595 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_3
Ikitown_trigger_GiveHalaSparklingStone_1:
# 603 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_8
Ikitown_trigger_GiveHalaSparklingStone_6:
# 611 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_13
Ikitown_trigger_GiveHalaSparklingStone_11:
# 617 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_18
Ikitown_trigger_GiveHalaSparklingStone_16:
# 623 "data/maps/IkiTown/scripts.pory"
	delay 30
# 624 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 625 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_5
# 626 "data/maps/IkiTown/scripts.pory"
	delay 60
# 627 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_6
# 628 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 629 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_10
# 630 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 631 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 632 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_1
# 634 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_4
# 635 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 636 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 637 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_2
# 643 "data/maps/IkiTown/scripts.pory"
	setvar VAR_RESULT, 1
# 644 "data/maps/IkiTown/scripts.pory"
	playse SE_M_DETECT
# 645 "data/maps/IkiTown/scripts.pory"
	dofieldeffectsparkle 24, 14, 0
# 646 "data/maps/IkiTown/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 647 "data/maps/IkiTown/scripts.pory"
	closemessage
# 648 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 649 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_7
# 650 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 651 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 652 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 653 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 654 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 655 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_3
# 661 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_8
# 662 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 663 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 664 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_4
# 665 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_4
# 666 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 667 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 668 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_5
# 669 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitown_Movement_4
# 670 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 671 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 672 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_6
# 675 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_trigger_GiveHalaSparklingStone_Text_7, Ikitown_trigger_GiveHalaSparklingStone_Text_8
# 676 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_22
# 697 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 698 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
Ikitown_trigger_GiveHalaSparklingStone_21:
# 716 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_GiveHalaSparklingStone_Movement_9
# 717 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 718 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 719 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_10
# 721 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedexSkip_Movement_0
# 722 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_11
# 728 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 729 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 730 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 731 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_12
# 733 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 734 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 735 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 736 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 737 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 738 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 739 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 740 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 741 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 742 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 743 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 744 "data/maps/IkiTown/scripts.pory"
	waitstate
	return

Ikitown_trigger_GiveHalaSparklingStone_2:
# 596 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_0
# 597 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 598 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 599 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 600 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 601 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_3:
# 595 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_2
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_7:
# 604 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_2
# 605 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 606 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 607 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 608 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 609 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_8:
# 603 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_7
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_12:
# 612 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_3
# 613 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 614 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 615 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_13:
# 611 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_12
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_17:
# 618 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_4
# 619 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 620 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 621 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_18:
# 617 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_17
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_22:
# 677 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 678 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
	goto Ikitown_trigger_GiveHalaSparklingStone_21


Ikitown_trigger_GiveHalaSparklingStoneSkip::
# 748 "data/maps/IkiTown/scripts.pory"
	closemessage
# 749 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 750 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 751 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 752 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 753 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 754 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 755 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 756 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 757 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 758 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 759 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 760 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 761 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 762 "data/maps/IkiTown/scripts.pory"
	waitstate
# 763 "data/maps/IkiTown/scripts.pory"
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

# 63 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_0:
# 63 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 63 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 63 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 63 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 63 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 63 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 63 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 63 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 63 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 64 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_1:
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
	walk_faster_down
# 64 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 67 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_2:
# 67 "data/maps/IkiTown/scripts.pory"
	walk_up
# 67 "data/maps/IkiTown/scripts.pory"
	walk_up
# 67 "data/maps/IkiTown/scripts.pory"
	walk_up
# 67 "data/maps/IkiTown/scripts.pory"
	walk_up
# 67 "data/maps/IkiTown/scripts.pory"
	walk_up
# 67 "data/maps/IkiTown/scripts.pory"
	walk_up
# 67 "data/maps/IkiTown/scripts.pory"
	walk_up
# 67 "data/maps/IkiTown/scripts.pory"
	walk_up
# 67 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 68 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_3:
# 68 "data/maps/IkiTown/scripts.pory"
	delay_16
# 68 "data/maps/IkiTown/scripts.pory"
	delay_16
# 68 "data/maps/IkiTown/scripts.pory"
	delay_16
# 68 "data/maps/IkiTown/scripts.pory"
	delay_16
# 68 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 68 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 68 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 76 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_4:
# 76 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
# 76 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
	step_end

# 82 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_5:
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 82 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
	step_end

# 84 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_6:
# 84 "data/maps/IkiTown/scripts.pory"
	walk_up
# 84 "data/maps/IkiTown/scripts.pory"
	walk_up
# 84 "data/maps/IkiTown/scripts.pory"
	walk_up
# 84 "data/maps/IkiTown/scripts.pory"
	walk_up
# 84 "data/maps/IkiTown/scripts.pory"
	walk_up
# 84 "data/maps/IkiTown/scripts.pory"
	walk_up
# 84 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 94 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_7:
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 94 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 98 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_8:
# 98 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 113 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_9:
# 113 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
# 113 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
	step_end

# 133 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_10:
# 133 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 133 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 133 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 133 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 133 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 133 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 133 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 133 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 186 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0:
# 186 "data/maps/IkiTown/scripts.pory"
	face_down
# 186 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 187 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1:
# 187 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 191 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_2:
# 191 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 323 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_0:
# 323 "data/maps/IkiTown/scripts.pory"
	walk_down
# 323 "data/maps/IkiTown/scripts.pory"
	walk_down
# 323 "data/maps/IkiTown/scripts.pory"
	walk_down
# 323 "data/maps/IkiTown/scripts.pory"
	walk_down
# 323 "data/maps/IkiTown/scripts.pory"
	walk_down
# 323 "data/maps/IkiTown/scripts.pory"
	walk_down
# 323 "data/maps/IkiTown/scripts.pory"
	walk_left
# 323 "data/maps/IkiTown/scripts.pory"
	walk_left
# 323 "data/maps/IkiTown/scripts.pory"
	walk_left
# 323 "data/maps/IkiTown/scripts.pory"
	walk_left
# 323 "data/maps/IkiTown/scripts.pory"
	walk_left
# 323 "data/maps/IkiTown/scripts.pory"
	walk_left
# 323 "data/maps/IkiTown/scripts.pory"
	walk_down
# 323 "data/maps/IkiTown/scripts.pory"
	walk_down
# 323 "data/maps/IkiTown/scripts.pory"
	walk_down
# 323 "data/maps/IkiTown/scripts.pory"
	walk_down
# 323 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 323 "data/maps/IkiTown/scripts.pory"
	walk_right
# 323 "data/maps/IkiTown/scripts.pory"
	walk_right
# 323 "data/maps/IkiTown/scripts.pory"
	walk_right
# 323 "data/maps/IkiTown/scripts.pory"
	walk_up
# 323 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 324 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_1:
# 324 "data/maps/IkiTown/scripts.pory"
	delay_16
# 324 "data/maps/IkiTown/scripts.pory"
	delay_16
# 324 "data/maps/IkiTown/scripts.pory"
	delay_16
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
	step_end

# 327 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_2:
# 327 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 327 "data/maps/IkiTown/scripts.pory"
	walk_down
# 327 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 334 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_3:
# 334 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
# 334 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
	step_end

# 338 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_4:
# 338 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
# 338 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
	step_end

# 375 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_5:
# 375 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 375 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 375 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 375 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 375 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 375 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 375 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 375 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 375 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
	step_end

# 377 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_6:
# 377 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 377 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 390 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_7:
# 390 "data/maps/IkiTown/scripts.pory"
	walk_down
# 390 "data/maps/IkiTown/scripts.pory"
	delay_16
# 390 "data/maps/IkiTown/scripts.pory"
	delay_16
# 390 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 391 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_8:
# 391 "data/maps/IkiTown/scripts.pory"
	walk_up
# 391 "data/maps/IkiTown/scripts.pory"
	walk_up
# 391 "data/maps/IkiTown/scripts.pory"
	walk_up
# 391 "data/maps/IkiTown/scripts.pory"
	walk_up
# 391 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 395 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_9:
# 395 "data/maps/IkiTown/scripts.pory"
	walk_left
# 395 "data/maps/IkiTown/scripts.pory"
	walk_left
# 395 "data/maps/IkiTown/scripts.pory"
	walk_left
# 395 "data/maps/IkiTown/scripts.pory"
	walk_left
# 395 "data/maps/IkiTown/scripts.pory"
	walk_left
# 395 "data/maps/IkiTown/scripts.pory"
	walk_left
# 395 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 397 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_10:
# 397 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 402 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_11:
# 402 "data/maps/IkiTown/scripts.pory"
	walk_left
# 402 "data/maps/IkiTown/scripts.pory"
	walk_left
# 402 "data/maps/IkiTown/scripts.pory"
	walk_left
# 402 "data/maps/IkiTown/scripts.pory"
	walk_left
# 402 "data/maps/IkiTown/scripts.pory"
	walk_diag_northwest
# 402 "data/maps/IkiTown/scripts.pory"
	walk_left
# 402 "data/maps/IkiTown/scripts.pory"
	walk_left
# 402 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 463 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_12:
# 463 "data/maps/IkiTown/scripts.pory"
	walk_down
# 463 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 464 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_13:
# 464 "data/maps/IkiTown/scripts.pory"
	walk_left
# 464 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 494 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_14:
# 494 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 494 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 494 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 532 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedexSkip_Movement_0:
# 532 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 596 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_0:
# 596 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 596 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 596 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 596 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 600 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_1:
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 604 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_2:
# 604 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 604 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 604 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 604 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 604 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 604 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 612 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_3:
# 612 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 612 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 612 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 612 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 612 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 612 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 612 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 612 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 618 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_4:
# 618 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 618 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 618 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 618 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 618 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 618 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 618 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 618 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 618 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 625 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_5:
# 625 "data/maps/IkiTown/scripts.pory"
	walk_right
# 625 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 625 "data/maps/IkiTown/scripts.pory"
	walk_right
# 625 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 627 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_6:
# 627 "data/maps/IkiTown/scripts.pory"
	walk_down
# 627 "data/maps/IkiTown/scripts.pory"
	delay_8
# 627 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 649 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_7:
# 649 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 661 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_8:
# 661 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
# 661 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
	step_end

# 716 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_9:
# 716 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

Ikitown_trigger_WecomeToIkitown_Text_0:
# 78 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

Ikitown_trigger_WecomeToIkitown_Text_1:
# 79 "data/maps/IkiTown/scripts.pory"
	.string "And we're here!\n"
	.string "This right here is Iki Town!$"

Ikitown_trigger_WecomeToIkitown_Text_2:
# 87 "data/maps/IkiTown/scripts.pory"
	.string "This town is where folks come to\n"
	.string "worship the Pokemon that watches\l"
	.string "over Melemele Island.\p"
	.string "Tapu Koko keeps us all safe and\n"
	.string "happy, see!$"

Ikitown_trigger_WecomeToIkitown_Text_3:
# 101 "data/maps/IkiTown/scripts.pory"
	.string "Looks like the kahuna's nowhere to be\n"
	.string "found, though…\p"
	.string "I guess there must be some trouble\n"
	.string "somewhere on the island that needs\l"
	.string "fixing, yeah?$"

Ikitown_trigger_WecomeToIkitown_Text_4:
# 109 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

Ikitown_trigger_WecomeToIkitown_Text_5:
# 110 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, the kahuna wandered off without\n"
	.string "a word to anybody, singing a little\l"
	.string "ditty or something.$"

Ikitown_trigger_WecomeToIkitown_Text_6:
# 121 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Popplio!$"

Ikitown_trigger_WecomeToIkitown_Text_7:
# 125 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Rowlet!$"

Ikitown_trigger_WecomeToIkitown_Text_8:
# 129 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Litten!$"

Ikitown_trigger_WecomeToIkitown_Text_9:
# 139 "data/maps/IkiTown/scripts.pory"
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
# 157 "data/maps/IkiTown/scripts.pory"
	.string "If you're really lucky, maybe you'll\n"
	.string "actually get a glimpse of the\l"
	.string "guardian deity yourself!\p"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_KukuiSeeTapuKoko_Text_0:
# 174 "data/maps/IkiTown/scripts.pory"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_MainSign_Text_0:
# 198 "data/maps/IkiTown/scripts.pory"
	.string "Iki Town\n"
	.string "“The place where we give thanks to\l"
	.string "Pokémon.”$"

Ikitown_LittleBoyWRockruff_Text_0:
# 209 "data/maps/IkiTown/scripts.pory"
	.string "Hey, you've got a Pokémon! I want one,\n"
	.string "too!\p"
	.string "Where'd you get yours?$"

Ikitown_Rockruff_Text_0:
# 222 "data/maps/IkiTown/scripts.pory"
	.string "Ruff ruff!$"

Ikitown_LeftSideGuy_Text_0:
# 231 "data/maps/IkiTown/scripts.pory"
	.string "Welcome to Iki Town, the town watched\n"
	.string "over by Pokémon!$"

Ikitown_MomwithChild_Text_0:
# 241 "data/maps/IkiTown/scripts.pory"
	.string "If you treat your Pokémon wrong, the\n"
	.string "guardian deity will strike you down\l"
	.string "with lightning!\p"
	.string "But the children all laugh when I tell\n"
	.string "them that.$"

Ikitown_ChildwithMom_Text_0:
# 255 "data/maps/IkiTown/scripts.pory"
	.string "I want to meet the guardian deity!\p"
	.string "Maybe I should cause some mischief for\n"
	.string "a Pokémon…$"

Ikitown_DontForgetToSave_Text_0:
# 267 "data/maps/IkiTown/scripts.pory"
	.string "Don't forget to save!\p"
	.string "If you want to remember everything\n"
	.string "that's happened, you must not\l"
	.string "forget to save!$"

Ikitown_KahunaGivesWisdom_Text_0:
# 280 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna gives us wisdom and\n"
	.string "guidance and teaches us how to live\l"
	.string "with our Pokémon.$"

Ikitown_ManBlockingDoor_Text_0:
# 290 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala is the strongest Pokémon\n"
	.string "Trainer on all of Melemele!\p"
	.string "There must be some trouble going down\n"
	.string "somewhere on the island that needs\l"
	.string "a kahuna's touch, 'cause he said\l"
	.string "something about how it's “Time\l"
	.string "for old Hala!” and off he went…$"

Ikitown_Meowth_Text_0:
# 306 "data/maps/IkiTown/scripts.pory"
	.string "Hsss!$"

Ikitown_sign_Ruinsofconflict_Text_0:
# 314 "data/maps/IkiTown/scripts.pory"
	.string "Ruins of Conflict$"

Ikitown_GetPokedex_Text_0:
# 330 "data/maps/IkiTown/scripts.pory"
	.string "Oh, {PLAYER}!\n"
	.string "You already met Lillie, huh?\p"
	.string "She's my assistant, yeah!$"

Ikitown_GetPokedex_Text_1:
# 336 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, I thought you were with the\n"
	.string "kahuna?$"

Ikitown_GetPokedex_Text_2:
# 340 "data/maps/IkiTown/scripts.pory"
	.string "Lillie$"

Ikitown_GetPokedex_Text_3:
# 341 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala? He said that he had\n"
	.string "something to attend to, so he left\l"
	.string "town on his own.\p"
	.string "I was just, um, taking a little stroll\n"
	.string "up Mahalo Trail while I waited for\l"
	.string "him to return…$"

Ikitown_GetPokedex_Text_4:
# 351 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "He just got to Alola yesterday.\n"
	.string "Help him find his way around, yeah?$"

Ikitown_GetPokedex_Text_5:
# 359 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "She just got to Alola yesterday.\n"
	.string "Help her find her way around, yeah?$"

Ikitown_GetPokedex_Text_6:
# 368 "data/maps/IkiTown/scripts.pory"
	.string "So…you're also one of\n"
	.string "the professor's acquaintances?\p"
	.string "It's nice to meet you.$"

Ikitown_GetPokedex_Text_7:
# 382 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna is back!\n"
	.string "Kahuna Hala has returned!\p"
	.string "Our guardian's chosen one is back!\p"
	.string "Only one of the strongest Pokémon\n"
	.string "users in all Alola, yeah!$"

Ikitown_GetPokedex_Text_8:
# 393 "data/maps/IkiTown/scripts.pory"
	.string "Hala$"

Ikitown_GetPokedex_Text_9:
# 394 "data/maps/IkiTown/scripts.pory"
	.string "Have I missed something?$"

Ikitown_GetPokedex_Text_10:
# 400 "data/maps/IkiTown/scripts.pory"
	.string "There you are, Kahuna Hala!\n"
	.string "Was there some kind of trouble?$"

Ikitown_GetPokedex_Text_11:
# 407 "data/maps/IkiTown/scripts.pory"
	.string "Ahaha! Just got caught up in the\n"
	.string "middle of some brawling Rockruff,\l"
	.string "that's all!\p"
	.string "Sorry, Lillie.\n"
	.string "What were you saying before?\p"
	.string "For some reason I thought I saw\n"
	.string "Tapu Koko flying about…$"

Ikitown_GetPokedex_Text_12:
# 419 "data/maps/IkiTown/scripts.pory"
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
# 436 "data/maps/IkiTown/scripts.pory"
	.string "Woo! That's something you don't hear\n"
	.string "every day!$"

Ikitown_GetPokedex_Text_14:
# 441 "data/maps/IkiTown/scripts.pory"
	.string "Ho! Although it is said to protect us,\n"
	.string "our Tapu Koko is a rather fickle\l"
	.string "creature.\l"
	.string "Yet our guardian was moved to save you.$"

Ikitown_GetPokedex_Text_15:
# 447 "data/maps/IkiTown/scripts.pory"
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
# 467 "data/maps/IkiTown/scripts.pory"
	.string "All right, here's a lovely gift to\n"
	.string "help make today special {PLAYER}!$"

Ikitown_GetPokedex_Text_17:
# 473 "data/maps/IkiTown/scripts.pory"
	.string "You obtained a {COLOR RED}Rotom Phone{COLOR DARK_GRAY}!$"

Ikitown_GetPokedex_Text_18:
# 478 "data/maps/IkiTown/scripts.pory"
	.string "The Rotom Phone comes equipped with a\n"
	.string "Pokédex, which is a really high-tech\l"
	.string "kinda tool, that can automatically\l"
	.string "record facts about any Pokémon that\l"
	.string "you meet.\p"
	.string "Your new partner, {STR_VAR_1} is\n"
	.string "already registered, oh yeah, so\l"
	.string "check it out!$"

Ikitown_GetPokedex_Text_19:
# 488 "data/maps/IkiTown/scripts.pory"
	.string "Well, you got to meet the kahuna\n"
	.string "at least.\p"
	.string "Ready to head home now, {PLAYER}?$"

ikitown_lilliedialog2_Text_0:
# 545 "data/maps/IkiTown/scripts.pory"
	.string "I really, um, really appreciate what you\n"
	.string "did for us on the Plank Bridge.\p"
	.string "I won't forget you and {STR_VAR_1}…$"

ikitown_kukuidialog2_Text_0:
# 558 "data/maps/IkiTown/scripts.pory"
	.string "Now that you met Tapu Koko, I can't\n"
	.string "wait to see how far you can go as a\l"
	.string "Pokémon Trainer!$"

ikitown_haladialog2_Text_0:
# 570 "data/maps/IkiTown/scripts.pory"
	.string "If you two can work in harmony with\n"
	.string "each other, you can go anywhere\l"
	.string "together!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_0:
# 582 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah! {PLAYER}!\n"
	.string "Hold up a sec!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_1:
# 632 "data/maps/IkiTown/scripts.pory"
	.string "What is it Hau? Did you forget\n"
	.string "something?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_2:
# 637 "data/maps/IkiTown/scripts.pory"
	.string "You're seriously asking me that?!\p"
	.string "Who's the one here who forgot to tell\n"
	.string "anyone before wandering off for a\l"
	.string "little stroll and a sing without a\l"
	.string "word, huh?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_3:
# 655 "data/maps/IkiTown/scripts.pory"
	.string "Hm?\n"
	.string "{PLAYER}…\p"
	.string "Would you be so kind as to give me a\n"
	.string "look at that {COLOR RED}Sparkling Stone{COLOR DARK_GRAY} you\l"
	.string "have there?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_4:
# 664 "data/maps/IkiTown/scripts.pory"
	.string "Could it be?!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_5:
# 668 "data/maps/IkiTown/scripts.pory"
	.string "Tutu, isn't that…$"

Ikitown_trigger_GiveHalaSparklingStone_Text_6:
# 672 "data/maps/IkiTown/scripts.pory"
	.string "You were rescued by Tapu Koko at the\n"
	.string "bridge-isn't that what I heard,\l"
	.string "{PLAYER}?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_7:
# 675 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, it rescued me$"

Ikitown_trigger_GiveHalaSparklingStone_Text_8:
# 675 "data/maps/IkiTown/scripts.pory"
	.string "It gave me a stone$"

Ikitown_trigger_GiveHalaSparklingStone_Text_9:
# 678 "data/maps/IkiTown/scripts.pory"
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
# 719 "data/maps/IkiTown/scripts.pory"
	.string "First I'll make sure you get back home\n"
	.string "safe today, though, {PLAYER}.$"

Ikitown_trigger_GiveHalaSparklingStone_Text_11:
# 722 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, you two should come with us\n"
	.string "too, yeah.\p"
	.string "Wouldn't want to go losing you twice\n"
	.string "in one day.\l"
	.string "You or that precious Pokémon of yours!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_12:
# 731 "data/maps/IkiTown/scripts.pory"
	.string "Yes…\n"
	.string "I will key an eye on Nebby$"
