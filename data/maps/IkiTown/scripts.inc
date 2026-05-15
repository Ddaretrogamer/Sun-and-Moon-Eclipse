IkiTown_MapScripts::
# 2 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IkiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/IkiTown/scripts.pory"
	compare VAR_IKITOWN_STATE, 6
	goto_if_eq IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 5 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, MAP_IKI_TOWN_SOUTH, 23, 5
# 6 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, MAP_IKI_TOWN_SOUTH, 32, 19
# 7 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhau, MAP_IKI_TOWN_SOUTH, 6, 14
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/IkiTown/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 6, Ikitown_GetPokedex
	.2byte 0


Ikitown_trigger_right::
# 15 "data/maps/IkiTown/scripts.pory"
	lock
# 16 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_right_Movement_0
# 17 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 18 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_left::
# 22 "data/maps/IkiTown/scripts.pory"
	lock
# 23 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_left_Movement_0
# 24 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 25 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_WecomeToIkitown::
# 29 "data/maps/IkiTown/scripts.pory"
	lock
# 30 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 31 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 32 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 33 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 34 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownhau, MAP_IKI_TOWN_SOUTH
# 35 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownkukui, MAP_IKI_TOWN_SOUTH
# 36 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 37 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 38 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_0
# 39 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_1
# 40 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 41 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 42 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_2
# 43 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_3
# 44 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 45 "data/maps/IkiTown/scripts.pory"
	delay 30
# 46 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_4
# 47 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 48 "data/maps/IkiTown/scripts.pory"
	delay 30
# 49 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_4
# 50 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 51 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_5
# 52 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 53 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 54 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_1, MSGBOX_AUTOCLOSE
# 56 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 57 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_6
# 58 "data/maps/IkiTown/scripts.pory"
	delay 100
# 59 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 60 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 61 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 62 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_2
# 68 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 69 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_7
# 70 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 71 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 72 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 73 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_8
# 74 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 75 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 76 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_3
# 82 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_5
# 83 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 84 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 85 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_5
# 88 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_9
# 89 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 90 "data/maps/IkiTown/scripts.pory"
	waitse
# 91 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 92 "data/maps/IkiTown/scripts.pory"
	waitse
# 93 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 94 "data/maps/IkiTown/scripts.pory"
	switch VAR_STARTER_MON
# 95 "data/maps/IkiTown/scripts.pory"
	case 0, Ikitown_trigger_WecomeToIkitown_3
# 99 "data/maps/IkiTown/scripts.pory"
	case 1, Ikitown_trigger_WecomeToIkitown_4
# 103 "data/maps/IkiTown/scripts.pory"
	case 2, Ikitown_trigger_WecomeToIkitown_5
Ikitown_trigger_WecomeToIkitown_1:
# 108 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_10
# 109 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 110 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau
# 111 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_5
# 112 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 113 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 114 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_9
# 126 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_9
# 127 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 128 "data/maps/IkiTown/scripts.pory"
	waitse
# 129 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 130 "data/maps/IkiTown/scripts.pory"
	waitse
# 131 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 132 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_10
# 138 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 139 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 140 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_trigger_WecomeToIkitown_3:
# 96 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_6, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_4:
# 100 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_7, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_5:
# 104 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_8, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1


Ikitown_KukuiSeeTapuKoko::
# 145 "data/maps/IkiTown/scripts.pory"
	lock
# 146 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 147 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 148 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 150 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Trigger_KukuiSeeTapuKoko::
# 156 "data/maps/IkiTown/scripts.pory"
	lock
# 157 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 158 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 159 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 160 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0
# 161 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 162 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 163 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 165 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_2
# 166 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MainSign::
# 171 "data/maps/IkiTown/scripts.pory"
	lock
# 172 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MainSign_Text_0
# 175 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 176 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyWRockruff::
# 181 "data/maps/IkiTown/scripts.pory"
	lock
# 182 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 183 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyWRockruff_Text_0
# 187 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 188 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Rockruff::
# 193 "data/maps/IkiTown/scripts.pory"
	lock
# 194 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 195 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 196 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Rockruff_Text_0
# 197 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 198 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LeftSideGuy::
# 203 "data/maps/IkiTown/scripts.pory"
	lock
# 204 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 205 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeftSideGuy_Text_0
# 207 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 208 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MomwithChild::
# 213 "data/maps/IkiTown/scripts.pory"
	lock
# 214 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 215 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MomwithChild_Text_0
# 221 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 222 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ChildwithMom::
# 227 "data/maps/IkiTown/scripts.pory"
	lock
# 228 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 229 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ChildwithMom_Text_0
# 233 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 234 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_DontForgetToSave::
# 239 "data/maps/IkiTown/scripts.pory"
	lock
# 240 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 241 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_DontForgetToSave_Text_0
# 246 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 247 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_KahunaGivesWisdom::
# 252 "data/maps/IkiTown/scripts.pory"
	lock
# 253 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 254 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KahunaGivesWisdom_Text_0
# 257 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ManBlockingDoor::
# 262 "data/maps/IkiTown/scripts.pory"
	lock
# 263 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 264 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ManBlockingDoor_Text_0
# 272 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Meowth::
# 277 "data/maps/IkiTown/scripts.pory"
	lock
# 278 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 279 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 280 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Meowth_Text_0
# 281 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 282 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_sign_Ruinsofconflict::
# 287 "data/maps/IkiTown/scripts.pory"
	lock
# 288 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_sign_Ruinsofconflict_Text_0
# 289 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 290 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_GetPokedex::
# 295 "data/maps/IkiTown/scripts.pory"
	lock
# 296 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_0
# 297 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_1
# 298 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 299 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 300 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownkukui, Ikitown_GetPokedex_Movement_2
# 301 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 302 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 303 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_0
# 307 "data/maps/IkiTown/scripts.pory"
	delay 30
# 308 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 309 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_3
# 310 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_4
# 311 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownkukui, Ikitown_trigger_WecomeToIkitown_Movement_4
# 312 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 313 "data/maps/IkiTown/scripts.pory"
	delay 30
# 314 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_5
# 315 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_6
# 316 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 317 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 318 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
	end


# 16 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_right_Movement_0:
# 16 "data/maps/IkiTown/scripts.pory"
	walk_left
# 16 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 23 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_left_Movement_0:
# 23 "data/maps/IkiTown/scripts.pory"
	walk_right
# 23 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 38 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_0:
# 38 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 38 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 38 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 38 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 38 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 38 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 38 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 38 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 38 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 39 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_1:
# 39 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 39 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 39 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 39 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 39 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 39 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 39 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 39 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 39 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 42 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_2:
# 42 "data/maps/IkiTown/scripts.pory"
	walk_up
# 42 "data/maps/IkiTown/scripts.pory"
	walk_up
# 42 "data/maps/IkiTown/scripts.pory"
	walk_up
# 42 "data/maps/IkiTown/scripts.pory"
	walk_up
# 42 "data/maps/IkiTown/scripts.pory"
	walk_up
# 42 "data/maps/IkiTown/scripts.pory"
	walk_up
# 42 "data/maps/IkiTown/scripts.pory"
	walk_up
# 42 "data/maps/IkiTown/scripts.pory"
	walk_up
# 42 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 43 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_3:
# 43 "data/maps/IkiTown/scripts.pory"
	delay_16
# 43 "data/maps/IkiTown/scripts.pory"
	delay_16
# 43 "data/maps/IkiTown/scripts.pory"
	delay_16
# 43 "data/maps/IkiTown/scripts.pory"
	delay_16
# 43 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 43 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 43 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 43 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 43 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 43 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 43 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 43 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 46 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_4:
# 46 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 51 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_5:
# 51 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
# 51 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
	step_end

# 57 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_6:
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_up
# 57 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 69 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_7:
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 69 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 73 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_8:
# 73 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 88 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_9:
# 88 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
# 88 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
	step_end

# 108 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_10:
# 108 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 108 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 108 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 108 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 108 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 108 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 108 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 108 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 160 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0:
# 160 "data/maps/IkiTown/scripts.pory"
	face_down
# 160 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 161 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1:
# 161 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 165 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_2:
# 165 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 296 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_0:
# 296 "data/maps/IkiTown/scripts.pory"
	walk_down
# 296 "data/maps/IkiTown/scripts.pory"
	walk_down
# 296 "data/maps/IkiTown/scripts.pory"
	walk_down
# 296 "data/maps/IkiTown/scripts.pory"
	walk_down
# 296 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 297 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_1:
# 297 "data/maps/IkiTown/scripts.pory"
	delay_16
# 297 "data/maps/IkiTown/scripts.pory"
	delay_16
# 297 "data/maps/IkiTown/scripts.pory"
	walk_down
# 297 "data/maps/IkiTown/scripts.pory"
	walk_down
# 297 "data/maps/IkiTown/scripts.pory"
	walk_down
# 297 "data/maps/IkiTown/scripts.pory"
	walk_down
# 297 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 300 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_2:
# 300 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 300 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 309 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_3:
# 309 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 309 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 309 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 309 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 310 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_4:
# 310 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 310 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 310 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 310 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 310 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 310 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 310 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 314 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_5:
# 314 "data/maps/IkiTown/scripts.pory"
	walk_right
# 314 "data/maps/IkiTown/scripts.pory"
	walk_right
# 314 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 315 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_6:
# 315 "data/maps/IkiTown/scripts.pory"
	delay_16
# 315 "data/maps/IkiTown/scripts.pory"
	delay_16
# 315 "data/maps/IkiTown/scripts.pory"
	walk_right
# 315 "data/maps/IkiTown/scripts.pory"
	walk_right
# 315 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

Ikitown_trigger_WecomeToIkitown_Text_0:
# 53 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

Ikitown_trigger_WecomeToIkitown_Text_1:
# 54 "data/maps/IkiTown/scripts.pory"
	.string "And we're here!\n"
	.string "This right here is Iki Town!$"

Ikitown_trigger_WecomeToIkitown_Text_2:
# 62 "data/maps/IkiTown/scripts.pory"
	.string "This town is where folks come to\n"
	.string "worship the Pokemon that watches\l"
	.string "over Melemele Island.\p"
	.string "Tapu Koko keeps us all safe and\n"
	.string "happy, see!$"

Ikitown_trigger_WecomeToIkitown_Text_3:
# 76 "data/maps/IkiTown/scripts.pory"
	.string "Looks like the kahuna's nowhere to be\n"
	.string "found, though…\p"
	.string "I guess there must be some trouble\n"
	.string "somewhere on the island that needs\l"
	.string "fixing, yeah?$"

Ikitown_trigger_WecomeToIkitown_Text_4:
# 84 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

Ikitown_trigger_WecomeToIkitown_Text_5:
# 85 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, the kahuna wandered off without\n"
	.string "a word to anybody, singing a little\l"
	.string "ditty or something.$"

Ikitown_trigger_WecomeToIkitown_Text_6:
# 96 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Popplio!$"

Ikitown_trigger_WecomeToIkitown_Text_7:
# 100 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Rowlet!$"

Ikitown_trigger_WecomeToIkitown_Text_8:
# 104 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Litten!$"

Ikitown_trigger_WecomeToIkitown_Text_9:
# 114 "data/maps/IkiTown/scripts.pory"
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
# 132 "data/maps/IkiTown/scripts.pory"
	.string "If you're really lucky, maybe you'll\n"
	.string "actually get a glimpse of the\l"
	.string "guardian deity yourself!\p"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_KukuiSeeTapuKoko_Text_0:
# 148 "data/maps/IkiTown/scripts.pory"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_MainSign_Text_0:
# 172 "data/maps/IkiTown/scripts.pory"
	.string "Iki Town\n"
	.string "“The place where we give thanks to\l"
	.string "Pokémon.”$"

Ikitown_LittleBoyWRockruff_Text_0:
# 183 "data/maps/IkiTown/scripts.pory"
	.string "Hey, you've got a Pokémon! I want one,\n"
	.string "too!\p"
	.string "Where'd you get yours?$"

Ikitown_Rockruff_Text_0:
# 196 "data/maps/IkiTown/scripts.pory"
	.string "Ruff ruff!$"

Ikitown_LeftSideGuy_Text_0:
# 205 "data/maps/IkiTown/scripts.pory"
	.string "Welcome to Iki Town, the town watched\n"
	.string "over by Pokémon!$"

Ikitown_MomwithChild_Text_0:
# 215 "data/maps/IkiTown/scripts.pory"
	.string "If you treat your Pokémon wrong, the\n"
	.string "guardian deity will strike you down\l"
	.string "with lightning!\p"
	.string "But the children all laugh when I tell\n"
	.string "them that.$"

Ikitown_ChildwithMom_Text_0:
# 229 "data/maps/IkiTown/scripts.pory"
	.string "I want to meet the guardian deity!\p"
	.string "Maybe I should cause some mischief for\n"
	.string "a Pokémon…$"

Ikitown_DontForgetToSave_Text_0:
# 241 "data/maps/IkiTown/scripts.pory"
	.string "Don't forget to save!\p"
	.string "If you want to remember everything\n"
	.string "that's happened, you must not\l"
	.string "forget to save!$"

Ikitown_KahunaGivesWisdom_Text_0:
# 254 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna gives us wisdom and\n"
	.string "guidance and teaches us how to live\l"
	.string "with our Pokémon.$"

Ikitown_ManBlockingDoor_Text_0:
# 264 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala is the strongest Pokémon\n"
	.string "Trainer on all of Melemele!\p"
	.string "There must be some trouble going down\n"
	.string "somewhere on the island that needs\l"
	.string "a kahuna's touch, 'cause he said\l"
	.string "something about how it's “Time\l"
	.string "for old Hala!” and off he went…$"

Ikitown_Meowth_Text_0:
# 280 "data/maps/IkiTown/scripts.pory"
	.string "Hsss!$"

Ikitown_sign_Ruinsofconflict_Text_0:
# 288 "data/maps/IkiTown/scripts.pory"
	.string "Ruins of Conflict$"

Ikitown_GetPokedex_Text_0:
# 303 "data/maps/IkiTown/scripts.pory"
	.string "Oh, {PLAYER}!\n"
	.string "You already met Lillie, huh?\p"
	.string "She's my assistant, yeah!$"
