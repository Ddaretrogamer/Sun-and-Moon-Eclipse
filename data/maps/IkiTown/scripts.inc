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
# 16 "data/maps/IkiTown/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 13, Ikitown_StartFestival
	.2byte 0


Ikitown_StartFestival::
# 20 "data/maps/IkiTown/scripts.pory"
	lockplayer
# 21 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_0
# 22 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_exeggutor_festival, Ikitown_StartFestival_Movement_1
# 23 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_oldman_festival, Ikitown_StartFestival_Movement_2
# 24 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 25 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 26 "data/maps/IkiTown/scripts.pory"
	delay 30
# 27 "data/maps/IkiTown/scripts.pory"
	removeobject ikitown_exeggutor_festival
# 28 "data/maps/IkiTown/scripts.pory"
	removeobject ikitown_oldman_festival
# 29 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 30 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_3
# 31 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 32 "data/maps/IkiTown/scripts.pory"
	delay 30
# 33 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_woman_festival, Ikitown_StartFestival_Movement_4
# 34 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 35 "data/maps/IkiTown/scripts.pory"
	delay 30
# 36 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_5
# 37 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 38 "data/maps/IkiTown/scripts.pory"
	delay 30
# 39 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_rockruff_festival, Ikitown_StartFestival_Movement_6
# 40 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_littlegirl_festival, Ikitown_StartFestival_Movement_7
# 41 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 42 "data/maps/IkiTown/scripts.pory"
	waitse
# 43 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 44 "data/maps/IkiTown/scripts.pory"
	waitse
# 45 "data/maps/IkiTown/scripts.pory"
	delay 30
# 46 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_8
# 47 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 48 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 49 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 14
# 50 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_right::
# 56 "data/maps/IkiTown/scripts.pory"
	lock
# 57 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_right_Movement_0
# 58 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 59 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_left::
# 63 "data/maps/IkiTown/scripts.pory"
	lock
# 64 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_left_Movement_0
# 65 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 66 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_WecomeToIkitownSkip::
# 70 "data/maps/IkiTown/scripts.pory"
	closemessage
# 71 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 72 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 73 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 74 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 75 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 76 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 77 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 78 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 79 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 80 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui, 33, 28
# 81 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 82 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 83 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau, MAP_IKI_TOWN
# 84 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 85 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 86 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_WecomeToIkitown::
# 91 "data/maps/IkiTown/scripts.pory"
	lock
# 92 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 93 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 94 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 95 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 96 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownhau, MAP_IKI_TOWN_SOUTH
# 97 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownkukui, MAP_IKI_TOWN_SOUTH
# 98 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 99 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 100 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_WELCOME_TO_IKITOWN
# 101 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_0
# 102 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_1
# 103 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 104 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 105 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_2
# 106 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_3
# 107 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 108 "data/maps/IkiTown/scripts.pory"
	delay 30
# 109 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 110 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 111 "data/maps/IkiTown/scripts.pory"
	delay 30
# 112 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 113 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 114 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_4
# 115 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 116 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 117 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_1, MSGBOX_AUTOCLOSE
# 119 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 120 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_5
# 121 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 122 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_6
# 123 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 124 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 125 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_2
# 131 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 132 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_7
# 133 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 134 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 135 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 136 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_8
# 137 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 138 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 139 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_3
# 145 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_4
# 146 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 147 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 148 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_5
# 151 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_9
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
	switch VAR_STARTER_MON
# 158 "data/maps/IkiTown/scripts.pory"
	case 0, Ikitown_trigger_WecomeToIkitown_3
# 162 "data/maps/IkiTown/scripts.pory"
	case 1, Ikitown_trigger_WecomeToIkitown_4
# 166 "data/maps/IkiTown/scripts.pory"
	case 2, Ikitown_trigger_WecomeToIkitown_5
Ikitown_trigger_WecomeToIkitown_1:
# 171 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_10
# 172 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 173 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau
# 174 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_4
# 175 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 176 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 177 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_9
# 189 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_9
# 190 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 191 "data/maps/IkiTown/scripts.pory"
	waitse
# 192 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 193 "data/maps/IkiTown/scripts.pory"
	waitse
# 194 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 195 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_10
# 201 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 202 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 203 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 204 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_trigger_WecomeToIkitown_3:
# 159 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_6, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_4:
# 163 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_7, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_5:
# 167 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_8, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1


Ikitown_KukuiSeeTapuKoko::
# 209 "data/maps/IkiTown/scripts.pory"
	lock
# 210 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 211 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 212 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 214 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Trigger_KukuiSeeTapuKoko::
# 220 "data/maps/IkiTown/scripts.pory"
	lock
# 221 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 222 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 223 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 224 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0
# 225 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 226 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 227 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 229 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_2
# 230 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MainSign::
# 235 "data/maps/IkiTown/scripts.pory"
	lock
# 236 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MainSign_Text_0
# 239 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 240 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyWRockruff::
# 245 "data/maps/IkiTown/scripts.pory"
	lock
# 246 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 247 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyWRockruff_Text_0
# 251 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 252 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Rockruff::
# 257 "data/maps/IkiTown/scripts.pory"
	lock
# 258 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 259 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 260 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Rockruff_Text_0
# 261 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 262 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LeftSideGuy::
# 267 "data/maps/IkiTown/scripts.pory"
	lock
# 268 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 269 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeftSideGuy_Text_0
# 271 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 272 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MomwithChild::
# 277 "data/maps/IkiTown/scripts.pory"
	lock
# 278 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 279 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MomwithChild_Text_0
# 285 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 286 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ChildwithMom::
# 291 "data/maps/IkiTown/scripts.pory"
	lock
# 292 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 293 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ChildwithMom_Text_0
# 297 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 298 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_DontForgetToSave::
# 303 "data/maps/IkiTown/scripts.pory"
	lock
# 304 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 305 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_DontForgetToSave_Text_0
# 310 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 311 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_KahunaGivesWisdom::
# 316 "data/maps/IkiTown/scripts.pory"
	lock
# 317 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 318 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KahunaGivesWisdom_Text_0
# 321 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ManBlockingDoor::
# 326 "data/maps/IkiTown/scripts.pory"
	lock
# 327 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 328 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ManBlockingDoor_Text_0
# 336 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Meowth::
# 341 "data/maps/IkiTown/scripts.pory"
	lock
# 342 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 343 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 344 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Meowth_Text_0
# 345 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 346 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_sign_Ruinsofconflict::
# 351 "data/maps/IkiTown/scripts.pory"
	lock
# 352 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_sign_Ruinsofconflict_Text_0
# 353 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 354 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_GetPokedex::
# 359 "data/maps/IkiTown/scripts.pory"
	lock
# 360 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GET_POKEDEX
# 361 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_0
# 362 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_1
# 363 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 364 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 365 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_2
# 366 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 367 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 368 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_0
# 372 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_3
# 373 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 374 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_1
# 376 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 377 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 378 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 379 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_3
# 386 "data/maps/IkiTown/scripts.pory"
	checkplayergender
# 387 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_GetPokedex_2
# 396 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 397 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_5
Ikitown_GetPokedex_1:
# 403 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_trigger_WecomeToIkitown_Movement_4
# 404 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 405 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 406 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_6, MSGBOX_AUTOCLOSE
# 410 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 411 "data/maps/IkiTown/scripts.pory"
	delay 30
# 413 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_5
# 414 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 415 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownman1, Ikitown_GetPokedex_Movement_6
# 416 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownoldman1, Ikitown_GetPokedex_Movement_6
# 417 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 418 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 419 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 420 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_7, MSGBOX_AUTOCLOSE
# 427 "data/maps/IkiTown/scripts.pory"
	delay 30
# 428 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_7
# 429 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_8
# 430 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 431 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 432 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_9, MSGBOX_AUTOCLOSE
# 433 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_9
# 434 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 435 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_StartFestival_Movement_6
# 436 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 437 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 438 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_10
# 440 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_10
# 441 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 442 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 443 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_StartFestival_Movement_6
# 444 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 445 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_11
# 454 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 455 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 456 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 457 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_12
# 471 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_3
# 472 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 473 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 474 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_13
# 476 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_3
# 477 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 478 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 479 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_14
# 483 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_3
# 484 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 485 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_15
# 501 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_11
# 502 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_8
# 503 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 504 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 505 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_16
# 507 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 508 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 509 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 510 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 511 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_17
# 512 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 513 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 514 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 515 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 516 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_18
# 526 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_19, MSGBOX_AUTOCLOSE
# 530 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 531 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 532 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_12
# 533 "data/maps/IkiTown/scripts.pory"
	delay 60
# 534 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 535 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 536 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 537 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_GetPokedex_2:
# 388 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 389 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_4
	goto Ikitown_GetPokedex_1


Ikitown_GetPokedexSkip::
# 542 "data/maps/IkiTown/scripts.pory"
	closemessage
# 543 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 544 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 545 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 546 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 547 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 548 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 549 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 550 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 552 "data/maps/IkiTown/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 14
# 553 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 558 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 559 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 560 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui2
# 561 "data/maps/IkiTown/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_IKI_TOWN
# 562 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownlillie, MAP_IKI_TOWN
# 563 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownhala, MAP_IKI_TOWN
# 564 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownintrokukui2, MAP_IKI_TOWN
# 565 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 21, 13
# 566 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 14
# 567 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 13
# 568 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_6
# 569 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_StartFestival_Movement_6
# 570 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedexSkip_Movement_0
# 571 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 572 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 573 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 574 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_lilliedialog2::
# 579 "data/maps/IkiTown/scripts.pory"
	lock
# 580 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 581 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 582 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 583 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_lilliedialog2_Text_0
# 587 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 588 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_kukuidialog2::
# 593 "data/maps/IkiTown/scripts.pory"
	lock
# 594 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 595 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 596 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_kukuidialog2_Text_0
# 599 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 600 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_haladialog2::
# 605 "data/maps/IkiTown/scripts.pory"
	lock
# 606 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 607 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 608 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_haladialog2_Text_0
# 611 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 612 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_GiveHalaSparklingStone::
# 617 "data/maps/IkiTown/scripts.pory"
	lock
# 618 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GIVE_HALA_SPARKLING_STONE
# 619 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 620 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_0, MSGBOX_AUTOCLOSE
# 622 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 623 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_WecomeToIkitown_Movement_8
# 624 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 625 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 626 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 12
# 627 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 12
# 628 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 629 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 630 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_StartFestival_Movement_6
# 631 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 632 "data/maps/IkiTown/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 633 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_3
Ikitown_trigger_GiveHalaSparklingStone_1:
# 641 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_8
Ikitown_trigger_GiveHalaSparklingStone_6:
# 649 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_13
Ikitown_trigger_GiveHalaSparklingStone_11:
# 655 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_18
Ikitown_trigger_GiveHalaSparklingStone_16:
# 661 "data/maps/IkiTown/scripts.pory"
	delay 30
# 662 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 663 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_5
# 664 "data/maps/IkiTown/scripts.pory"
	delay 60
# 665 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_6
# 666 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 667 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_StartFestival_Movement_6
# 668 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 669 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 670 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_1
# 672 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_4
# 673 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 674 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 675 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_2
# 681 "data/maps/IkiTown/scripts.pory"
	setvar VAR_RESULT, 1
# 682 "data/maps/IkiTown/scripts.pory"
	playse SE_M_DETECT
# 683 "data/maps/IkiTown/scripts.pory"
	dofieldeffectsparkle 24, 14, 0
# 684 "data/maps/IkiTown/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 685 "data/maps/IkiTown/scripts.pory"
	closemessage
# 686 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 687 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_7
# 688 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 689 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 690 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 691 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 692 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 693 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_3
# 699 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_4
# 700 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 701 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 702 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_4
# 703 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_4
# 704 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 705 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 706 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_5
# 707 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitown_Movement_4
# 708 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 709 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 710 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_6
# 713 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_trigger_GiveHalaSparklingStone_Text_7, Ikitown_trigger_GiveHalaSparklingStone_Text_8
# 714 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_22
# 735 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 736 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
Ikitown_trigger_GiveHalaSparklingStone_21:
# 754 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_GiveHalaSparklingStone_Movement_8
# 755 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 756 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 757 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_10
# 759 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedexSkip_Movement_0
# 760 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_11
# 766 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 767 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 768 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_2
# 769 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_12
# 771 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 772 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 773 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 774 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 775 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 776 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 777 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 778 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 779 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 780 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 781 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 782 "data/maps/IkiTown/scripts.pory"
	waitstate
	return

Ikitown_trigger_GiveHalaSparklingStone_2:
# 634 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_0
# 635 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 636 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 637 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 638 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 639 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_3:
# 633 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_2
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_7:
# 642 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_2
# 643 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 644 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 645 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 646 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 647 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_8:
# 641 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_7
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_12:
# 650 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_3
# 651 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 652 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 653 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_13:
# 649 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_12
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_17:
# 656 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_4
# 657 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 658 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 659 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_18:
# 655 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_17
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_22:
# 715 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_GetPokedex_Text_8
# 716 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
	goto Ikitown_trigger_GiveHalaSparklingStone_21


Ikitown_trigger_GiveHalaSparklingStoneSkip::
# 786 "data/maps/IkiTown/scripts.pory"
	closemessage
# 787 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 788 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 789 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 790 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 791 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 792 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 793 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 794 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 795 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 796 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 797 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 798 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 799 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 800 "data/maps/IkiTown/scripts.pory"
	waitstate
# 801 "data/maps/IkiTown/scripts.pory"
	release
	end


# 21 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_0:
# 21 "data/maps/IkiTown/scripts.pory"
	walk_up
# 21 "data/maps/IkiTown/scripts.pory"
	walk_up
# 21 "data/maps/IkiTown/scripts.pory"
	walk_up
# 21 "data/maps/IkiTown/scripts.pory"
	walk_up
# 21 "data/maps/IkiTown/scripts.pory"
	delay_16
# 21 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 22 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_1:
# 22 "data/maps/IkiTown/scripts.pory"
	delay_16
# 22 "data/maps/IkiTown/scripts.pory"
	delay_16
# 22 "data/maps/IkiTown/scripts.pory"
	walk_up
# 22 "data/maps/IkiTown/scripts.pory"
	walk_up
# 22 "data/maps/IkiTown/scripts.pory"
	walk_up
# 22 "data/maps/IkiTown/scripts.pory"
	walk_up
# 22 "data/maps/IkiTown/scripts.pory"
	walk_up
# 22 "data/maps/IkiTown/scripts.pory"
	walk_up
# 22 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 23 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_2:
# 23 "data/maps/IkiTown/scripts.pory"
	delay_16
# 23 "data/maps/IkiTown/scripts.pory"
	walk_up
# 23 "data/maps/IkiTown/scripts.pory"
	walk_up
# 23 "data/maps/IkiTown/scripts.pory"
	walk_up
# 23 "data/maps/IkiTown/scripts.pory"
	walk_up
# 23 "data/maps/IkiTown/scripts.pory"
	walk_up
# 23 "data/maps/IkiTown/scripts.pory"
	walk_up
# 23 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 30 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_3:
# 30 "data/maps/IkiTown/scripts.pory"
	walk_left
# 30 "data/maps/IkiTown/scripts.pory"
	walk_left
# 30 "data/maps/IkiTown/scripts.pory"
	walk_left
# 30 "data/maps/IkiTown/scripts.pory"
	walk_left
# 30 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 33 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_4:
# 33 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
# 33 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
	step_end

# 36 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_5:
# 36 "data/maps/IkiTown/scripts.pory"
	walk_right
# 36 "data/maps/IkiTown/scripts.pory"
	walk_right
# 36 "data/maps/IkiTown/scripts.pory"
	walk_right
# 36 "data/maps/IkiTown/scripts.pory"
	walk_right
# 36 "data/maps/IkiTown/scripts.pory"
	walk_right
# 36 "data/maps/IkiTown/scripts.pory"
	walk_right
# 36 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 39 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_6:
# 39 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 40 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_7:
# 40 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
# 40 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
	step_end

# 46 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_8:
# 46 "data/maps/IkiTown/scripts.pory"
	walk_left
# 46 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 57 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_right_Movement_0:
# 57 "data/maps/IkiTown/scripts.pory"
	walk_left
# 57 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 64 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_left_Movement_0:
# 64 "data/maps/IkiTown/scripts.pory"
	walk_right
# 64 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 81 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitownSkip_Movement_0:
# 81 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 101 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_0:
# 101 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 101 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 101 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 101 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 101 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 101 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 101 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 101 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 101 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 102 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_1:
# 102 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 102 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 102 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 102 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 102 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 102 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 102 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 102 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 102 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 105 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_2:
# 105 "data/maps/IkiTown/scripts.pory"
	walk_up
# 105 "data/maps/IkiTown/scripts.pory"
	walk_up
# 105 "data/maps/IkiTown/scripts.pory"
	walk_up
# 105 "data/maps/IkiTown/scripts.pory"
	walk_up
# 105 "data/maps/IkiTown/scripts.pory"
	walk_up
# 105 "data/maps/IkiTown/scripts.pory"
	walk_up
# 105 "data/maps/IkiTown/scripts.pory"
	walk_up
# 105 "data/maps/IkiTown/scripts.pory"
	walk_up
# 105 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 106 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_3:
# 106 "data/maps/IkiTown/scripts.pory"
	delay_16
# 106 "data/maps/IkiTown/scripts.pory"
	delay_16
# 106 "data/maps/IkiTown/scripts.pory"
	delay_16
# 106 "data/maps/IkiTown/scripts.pory"
	delay_16
# 106 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 106 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 106 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 106 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 106 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 106 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 106 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 106 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 114 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_4:
# 114 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
# 114 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
	step_end

# 120 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_5:
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 120 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
	step_end

# 122 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_6:
# 122 "data/maps/IkiTown/scripts.pory"
	walk_up
# 122 "data/maps/IkiTown/scripts.pory"
	walk_up
# 122 "data/maps/IkiTown/scripts.pory"
	walk_up
# 122 "data/maps/IkiTown/scripts.pory"
	walk_up
# 122 "data/maps/IkiTown/scripts.pory"
	walk_up
# 122 "data/maps/IkiTown/scripts.pory"
	walk_up
# 122 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 132 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_7:
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 132 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 136 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_8:
# 136 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 151 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_9:
# 151 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
# 151 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
	step_end

# 171 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_10:
# 171 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 171 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 171 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 171 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 171 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 171 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 171 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 171 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 224 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0:
# 224 "data/maps/IkiTown/scripts.pory"
	face_down
# 224 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 225 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1:
# 225 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 229 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_2:
# 229 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 361 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_0:
# 361 "data/maps/IkiTown/scripts.pory"
	walk_down
# 361 "data/maps/IkiTown/scripts.pory"
	walk_down
# 361 "data/maps/IkiTown/scripts.pory"
	walk_down
# 361 "data/maps/IkiTown/scripts.pory"
	walk_down
# 361 "data/maps/IkiTown/scripts.pory"
	walk_down
# 361 "data/maps/IkiTown/scripts.pory"
	walk_down
# 361 "data/maps/IkiTown/scripts.pory"
	walk_left
# 361 "data/maps/IkiTown/scripts.pory"
	walk_left
# 361 "data/maps/IkiTown/scripts.pory"
	walk_left
# 361 "data/maps/IkiTown/scripts.pory"
	walk_left
# 361 "data/maps/IkiTown/scripts.pory"
	walk_left
# 361 "data/maps/IkiTown/scripts.pory"
	walk_left
# 361 "data/maps/IkiTown/scripts.pory"
	walk_down
# 361 "data/maps/IkiTown/scripts.pory"
	walk_down
# 361 "data/maps/IkiTown/scripts.pory"
	walk_down
# 361 "data/maps/IkiTown/scripts.pory"
	walk_down
# 361 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 361 "data/maps/IkiTown/scripts.pory"
	walk_right
# 361 "data/maps/IkiTown/scripts.pory"
	walk_right
# 361 "data/maps/IkiTown/scripts.pory"
	walk_right
# 361 "data/maps/IkiTown/scripts.pory"
	walk_up
# 361 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 362 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_1:
# 362 "data/maps/IkiTown/scripts.pory"
	delay_16
# 362 "data/maps/IkiTown/scripts.pory"
	delay_16
# 362 "data/maps/IkiTown/scripts.pory"
	delay_16
# 362 "data/maps/IkiTown/scripts.pory"
	walk_down
# 362 "data/maps/IkiTown/scripts.pory"
	walk_down
# 362 "data/maps/IkiTown/scripts.pory"
	walk_down
# 362 "data/maps/IkiTown/scripts.pory"
	walk_down
# 362 "data/maps/IkiTown/scripts.pory"
	walk_down
# 362 "data/maps/IkiTown/scripts.pory"
	walk_down
# 362 "data/maps/IkiTown/scripts.pory"
	walk_left
# 362 "data/maps/IkiTown/scripts.pory"
	walk_left
# 362 "data/maps/IkiTown/scripts.pory"
	walk_left
# 362 "data/maps/IkiTown/scripts.pory"
	walk_left
# 362 "data/maps/IkiTown/scripts.pory"
	walk_left
# 362 "data/maps/IkiTown/scripts.pory"
	walk_down
# 362 "data/maps/IkiTown/scripts.pory"
	walk_down
# 362 "data/maps/IkiTown/scripts.pory"
	walk_down
# 362 "data/maps/IkiTown/scripts.pory"
	walk_down
# 362 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 362 "data/maps/IkiTown/scripts.pory"
	walk_right
# 362 "data/maps/IkiTown/scripts.pory"
	walk_right
# 362 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 365 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_2:
# 365 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 365 "data/maps/IkiTown/scripts.pory"
	walk_down
# 365 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 372 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_3:
# 372 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
# 372 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
	step_end

# 376 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_4:
# 376 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
# 376 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
	step_end

# 413 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_5:
# 413 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 413 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 413 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 413 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 413 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 413 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 413 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 413 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 413 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
	step_end

# 415 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_6:
# 415 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 415 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 428 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_7:
# 428 "data/maps/IkiTown/scripts.pory"
	walk_down
# 428 "data/maps/IkiTown/scripts.pory"
	delay_16
# 428 "data/maps/IkiTown/scripts.pory"
	delay_16
# 428 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 429 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_8:
# 429 "data/maps/IkiTown/scripts.pory"
	walk_up
# 429 "data/maps/IkiTown/scripts.pory"
	walk_up
# 429 "data/maps/IkiTown/scripts.pory"
	walk_up
# 429 "data/maps/IkiTown/scripts.pory"
	walk_up
# 429 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 433 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_9:
# 433 "data/maps/IkiTown/scripts.pory"
	walk_left
# 433 "data/maps/IkiTown/scripts.pory"
	walk_left
# 433 "data/maps/IkiTown/scripts.pory"
	walk_left
# 433 "data/maps/IkiTown/scripts.pory"
	walk_left
# 433 "data/maps/IkiTown/scripts.pory"
	walk_left
# 433 "data/maps/IkiTown/scripts.pory"
	walk_left
# 433 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 440 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_10:
# 440 "data/maps/IkiTown/scripts.pory"
	walk_left
# 440 "data/maps/IkiTown/scripts.pory"
	walk_left
# 440 "data/maps/IkiTown/scripts.pory"
	walk_left
# 440 "data/maps/IkiTown/scripts.pory"
	walk_left
# 440 "data/maps/IkiTown/scripts.pory"
	walk_diag_northwest
# 440 "data/maps/IkiTown/scripts.pory"
	walk_left
# 440 "data/maps/IkiTown/scripts.pory"
	walk_left
# 440 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 501 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_11:
# 501 "data/maps/IkiTown/scripts.pory"
	walk_down
# 501 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 532 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_12:
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 532 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 570 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedexSkip_Movement_0:
# 570 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 634 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_0:
# 634 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 634 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 634 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 634 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 638 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_1:
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 638 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 642 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_2:
# 642 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 642 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 642 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 642 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 642 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 642 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 650 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_3:
# 650 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 650 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 650 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 650 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 650 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 650 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 650 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 650 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 656 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_4:
# 656 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 656 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 656 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 656 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 656 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 656 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 656 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 656 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 656 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 663 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_5:
# 663 "data/maps/IkiTown/scripts.pory"
	walk_right
# 663 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 663 "data/maps/IkiTown/scripts.pory"
	walk_right
# 663 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 665 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_6:
# 665 "data/maps/IkiTown/scripts.pory"
	walk_down
# 665 "data/maps/IkiTown/scripts.pory"
	delay_8
# 665 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 687 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_7:
# 687 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 754 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_8:
# 754 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

Ikitown_trigger_WecomeToIkitown_Text_0:
# 116 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

Ikitown_trigger_WecomeToIkitown_Text_1:
# 117 "data/maps/IkiTown/scripts.pory"
	.string "And we're here!\n"
	.string "This right here is Iki Town!$"

Ikitown_trigger_WecomeToIkitown_Text_2:
# 125 "data/maps/IkiTown/scripts.pory"
	.string "This town is where folks come to\n"
	.string "worship the Pokemon that watches\l"
	.string "over Melemele Island.\p"
	.string "Tapu Koko keeps us all safe and\n"
	.string "happy, see!$"

Ikitown_trigger_WecomeToIkitown_Text_3:
# 139 "data/maps/IkiTown/scripts.pory"
	.string "Looks like the kahuna's nowhere to be\n"
	.string "found, though…\p"
	.string "I guess there must be some trouble\n"
	.string "somewhere on the island that needs\l"
	.string "fixing, yeah?$"

Ikitown_trigger_WecomeToIkitown_Text_4:
# 147 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

Ikitown_trigger_WecomeToIkitown_Text_5:
# 148 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, the kahuna wandered off without\n"
	.string "a word to anybody, singing a little\l"
	.string "ditty or something.$"

Ikitown_trigger_WecomeToIkitown_Text_6:
# 159 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Popplio!$"

Ikitown_trigger_WecomeToIkitown_Text_7:
# 163 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Rowlet!$"

Ikitown_trigger_WecomeToIkitown_Text_8:
# 167 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Litten!$"

Ikitown_trigger_WecomeToIkitown_Text_9:
# 177 "data/maps/IkiTown/scripts.pory"
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
# 195 "data/maps/IkiTown/scripts.pory"
	.string "If you're really lucky, maybe you'll\n"
	.string "actually get a glimpse of the\l"
	.string "guardian deity yourself!\p"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_KukuiSeeTapuKoko_Text_0:
# 212 "data/maps/IkiTown/scripts.pory"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_MainSign_Text_0:
# 236 "data/maps/IkiTown/scripts.pory"
	.string "Iki Town\n"
	.string "“The place where we give thanks to\l"
	.string "Pokémon.”$"

Ikitown_LittleBoyWRockruff_Text_0:
# 247 "data/maps/IkiTown/scripts.pory"
	.string "Hey, you've got a Pokémon! I want one,\n"
	.string "too!\p"
	.string "Where'd you get yours?$"

Ikitown_Rockruff_Text_0:
# 260 "data/maps/IkiTown/scripts.pory"
	.string "Ruff ruff!$"

Ikitown_LeftSideGuy_Text_0:
# 269 "data/maps/IkiTown/scripts.pory"
	.string "Welcome to Iki Town, the town watched\n"
	.string "over by Pokémon!$"

Ikitown_MomwithChild_Text_0:
# 279 "data/maps/IkiTown/scripts.pory"
	.string "If you treat your Pokémon wrong, the\n"
	.string "guardian deity will strike you down\l"
	.string "with lightning!\p"
	.string "But the children all laugh when I tell\n"
	.string "them that.$"

Ikitown_ChildwithMom_Text_0:
# 293 "data/maps/IkiTown/scripts.pory"
	.string "I want to meet the guardian deity!\p"
	.string "Maybe I should cause some mischief for\n"
	.string "a Pokémon…$"

Ikitown_DontForgetToSave_Text_0:
# 305 "data/maps/IkiTown/scripts.pory"
	.string "Don't forget to save!\p"
	.string "If you want to remember everything\n"
	.string "that's happened, you must not\l"
	.string "forget to save!$"

Ikitown_KahunaGivesWisdom_Text_0:
# 318 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna gives us wisdom and\n"
	.string "guidance and teaches us how to live\l"
	.string "with our Pokémon.$"

Ikitown_ManBlockingDoor_Text_0:
# 328 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala is the strongest Pokémon\n"
	.string "Trainer on all of Melemele!\p"
	.string "There must be some trouble going down\n"
	.string "somewhere on the island that needs\l"
	.string "a kahuna's touch, 'cause he said\l"
	.string "something about how it's “Time\l"
	.string "for old Hala!” and off he went…$"

Ikitown_Meowth_Text_0:
# 344 "data/maps/IkiTown/scripts.pory"
	.string "Hsss!$"

Ikitown_sign_Ruinsofconflict_Text_0:
# 352 "data/maps/IkiTown/scripts.pory"
	.string "Ruins of Conflict$"

Ikitown_GetPokedex_Text_0:
# 368 "data/maps/IkiTown/scripts.pory"
	.string "Oh, {PLAYER}!\n"
	.string "You already met Lillie, huh?\p"
	.string "She's my assistant, yeah!$"

Ikitown_GetPokedex_Text_1:
# 374 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, I thought you were with the\n"
	.string "kahuna?$"

Ikitown_GetPokedex_Text_2:
# 378 "data/maps/IkiTown/scripts.pory"
	.string "Lillie$"

Ikitown_GetPokedex_Text_3:
# 379 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala? He said that he had\n"
	.string "something to attend to, so he left\l"
	.string "town on his own.\p"
	.string "I was just, um, taking a little stroll\n"
	.string "up Mahalo Trail while I waited for\l"
	.string "him to return…$"

Ikitown_GetPokedex_Text_4:
# 389 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "He just got to Alola yesterday.\n"
	.string "Help him find his way around, yeah?$"

Ikitown_GetPokedex_Text_5:
# 397 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "She just got to Alola yesterday.\n"
	.string "Help her find her way around, yeah?$"

Ikitown_GetPokedex_Text_6:
# 406 "data/maps/IkiTown/scripts.pory"
	.string "So…you're also one of\n"
	.string "the professor's acquaintances?\p"
	.string "It's nice to meet you.$"

Ikitown_GetPokedex_Text_7:
# 420 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna is back!\n"
	.string "Kahuna Hala has returned!\p"
	.string "Our guardian's chosen one is back!\p"
	.string "Only one of the strongest Pokémon\n"
	.string "users in all Alola, yeah!$"

Ikitown_GetPokedex_Text_8:
# 431 "data/maps/IkiTown/scripts.pory"
	.string "Hala$"

Ikitown_GetPokedex_Text_9:
# 432 "data/maps/IkiTown/scripts.pory"
	.string "Have I missed something?$"

Ikitown_GetPokedex_Text_10:
# 438 "data/maps/IkiTown/scripts.pory"
	.string "There you are, Kahuna Hala!\n"
	.string "Was there some kind of trouble?$"

Ikitown_GetPokedex_Text_11:
# 445 "data/maps/IkiTown/scripts.pory"
	.string "Ahaha! Just got caught up in the\n"
	.string "middle of some brawling Rockruff,\l"
	.string "that's all!\p"
	.string "Sorry, Lillie.\n"
	.string "What were you saying before?\p"
	.string "For some reason I thought I saw\n"
	.string "Tapu Koko flying about…$"

Ikitown_GetPokedex_Text_12:
# 457 "data/maps/IkiTown/scripts.pory"
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
# 474 "data/maps/IkiTown/scripts.pory"
	.string "Woo! That's something you don't hear\n"
	.string "every day!$"

Ikitown_GetPokedex_Text_14:
# 479 "data/maps/IkiTown/scripts.pory"
	.string "Ho! Although it is said to protect us,\n"
	.string "our Tapu Koko is a rather fickle\l"
	.string "creature.\l"
	.string "Yet our guardian was moved to save you.$"

Ikitown_GetPokedex_Text_15:
# 485 "data/maps/IkiTown/scripts.pory"
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
# 505 "data/maps/IkiTown/scripts.pory"
	.string "All right, here's a lovely gift to\n"
	.string "help make today special {PLAYER}!$"

Ikitown_GetPokedex_Text_17:
# 511 "data/maps/IkiTown/scripts.pory"
	.string "You obtained a {COLOR RED}Rotom Phone{COLOR DARK_GRAY}!$"

Ikitown_GetPokedex_Text_18:
# 516 "data/maps/IkiTown/scripts.pory"
	.string "The Rotom Phone comes equipped with a\n"
	.string "Pokédex, which is a really high-tech\l"
	.string "kinda tool, that can automatically\l"
	.string "record facts about any Pokémon that\l"
	.string "you meet.\p"
	.string "Your new partner, {STR_VAR_1} is\n"
	.string "already registered, oh yeah, so\l"
	.string "check it out!$"

Ikitown_GetPokedex_Text_19:
# 526 "data/maps/IkiTown/scripts.pory"
	.string "Well, you got to meet the kahuna\n"
	.string "at least.\p"
	.string "Ready to head home now, {PLAYER}?$"

ikitown_lilliedialog2_Text_0:
# 583 "data/maps/IkiTown/scripts.pory"
	.string "I really, um, really appreciate what you\n"
	.string "did for us on the Plank Bridge.\p"
	.string "I won't forget you and {STR_VAR_1}…$"

ikitown_kukuidialog2_Text_0:
# 596 "data/maps/IkiTown/scripts.pory"
	.string "Now that you met Tapu Koko, I can't\n"
	.string "wait to see how far you can go as a\l"
	.string "Pokémon Trainer!$"

ikitown_haladialog2_Text_0:
# 608 "data/maps/IkiTown/scripts.pory"
	.string "If you two can work in harmony with\n"
	.string "each other, you can go anywhere\l"
	.string "together!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_0:
# 620 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah! {PLAYER}!\n"
	.string "Hold up a sec!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_1:
# 670 "data/maps/IkiTown/scripts.pory"
	.string "What is it Hau? Did you forget\n"
	.string "something?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_2:
# 675 "data/maps/IkiTown/scripts.pory"
	.string "You're seriously asking me that?!\p"
	.string "Who's the one here who forgot to tell\n"
	.string "anyone before wandering off for a\l"
	.string "little stroll and a sing without a\l"
	.string "word, huh?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_3:
# 693 "data/maps/IkiTown/scripts.pory"
	.string "Hm?\n"
	.string "{PLAYER}…\p"
	.string "Would you be so kind as to give me a\n"
	.string "look at that {COLOR RED}Sparkling Stone{COLOR DARK_GRAY} you\l"
	.string "have there?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_4:
# 702 "data/maps/IkiTown/scripts.pory"
	.string "Could it be?!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_5:
# 706 "data/maps/IkiTown/scripts.pory"
	.string "Tutu, isn't that…$"

Ikitown_trigger_GiveHalaSparklingStone_Text_6:
# 710 "data/maps/IkiTown/scripts.pory"
	.string "You were rescued by Tapu Koko at the\n"
	.string "bridge-isn't that what I heard,\l"
	.string "{PLAYER}?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_7:
# 713 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, it rescued me$"

Ikitown_trigger_GiveHalaSparklingStone_Text_8:
# 713 "data/maps/IkiTown/scripts.pory"
	.string "It gave me a stone$"

Ikitown_trigger_GiveHalaSparklingStone_Text_9:
# 716 "data/maps/IkiTown/scripts.pory"
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
# 757 "data/maps/IkiTown/scripts.pory"
	.string "First I'll make sure you get back home\n"
	.string "safe today, though, {PLAYER}.$"

Ikitown_trigger_GiveHalaSparklingStone_Text_11:
# 760 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, you two should come with us\n"
	.string "too, yeah.\p"
	.string "Wouldn't want to go losing you twice\n"
	.string "in one day.\l"
	.string "You or that precious Pokémon of yours!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_12:
# 769 "data/maps/IkiTown/scripts.pory"
	.string "Yes…\n"
	.string "I will key an eye on Nebby$"
