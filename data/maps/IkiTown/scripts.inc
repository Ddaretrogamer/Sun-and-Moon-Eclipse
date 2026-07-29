IkiTown_MapScripts::
# 2 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 29 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 39 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IkiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 11 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 19 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
# 8 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( POPPLIO )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 12 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
# 16 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( ROWLET )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 20 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14
# 24 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LITTEN )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 5 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( POPPLIO )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
# 13 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( ROWLET )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
# 21 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( LITTEN )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 29 "data/maps/IkiTown/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 6, IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 30 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 31 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_HALA
# 32 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 33 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 23, 5
# 34 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 35 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 32, 19
# 36 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 37 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 9, 14
	return

IkiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 39 "data/maps/IkiTown/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 6, Ikitown_GetPokedex
# 40 "data/maps/IkiTown/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 13, Ikitown_StartFestival
	.2byte 0


Ikitown_Trigger_FestivalBattleleft::
# 44 "data/maps/IkiTown/scripts.pory"
	lock
# 45 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 46 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleleft_Movement_0
# 47 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 48 "data/maps/IkiTown/scripts.pory"
	delay 30
# 49 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleleft_Movement_1
# 50 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 51 "data/maps/IkiTown/scripts.pory"
	call Ikitown_Trigger_FestivalBattle
	return


Ikitown_Trigger_FestivalBattleRight::
# 55 "data/maps/IkiTown/scripts.pory"
	lock
# 56 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 57 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleleft_Movement_0
# 58 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 59 "data/maps/IkiTown/scripts.pory"
	delay 30
# 60 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleRight_Movement_0
# 61 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 62 "data/maps/IkiTown/scripts.pory"
	call Ikitown_Trigger_FestivalBattle
	return


Ikitown_Trigger_FestivalBattleMiddle::
# 66 "data/maps/IkiTown/scripts.pory"
	lock
# 67 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 68 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleleft_Movement_0
# 69 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 70 "data/maps/IkiTown/scripts.pory"
	delay 30
# 71 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleMiddle_Movement_0
# 72 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 73 "data/maps/IkiTown/scripts.pory"
	call Ikitown_Trigger_FestivalBattle
	return


Ikitown_Trigger_FestivalBattle::
# 77 "data/maps/IkiTown/scripts.pory"
	delay 30
# 78 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_FESTIVAL_BATTLE_1
# 79 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 80 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 81 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 82 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_1, MSGBOX_AUTOCLOSE
# 99 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 100 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 101 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 102 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_Trigger_FestivalBattle_2
# 114 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_Trigger_FestivalBattle_3
# 126 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_Trigger_FestivalBattle_4
Ikitown_Trigger_FestivalBattle_1:
# 138 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 139 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_9, MSGBOX_AUTOCLOSE
# 141 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_kukui_festival
# 142 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_lillie_festival
# 143 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_2
# 144 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_3
# 145 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_3
# 146 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 147 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 148 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_11, MSGBOX_AUTOCLOSE
# 149 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_4
# 150 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_5
# 151 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 152 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 153 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_13, MSGBOX_AUTOCLOSE
# 154 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 155 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_6
# 156 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 157 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_14, MSGBOX_AUTOCLOSE
# 158 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 159 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 160 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 161 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 162 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_15, MSGBOX_AUTOCLOSE
# 169 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_7
# 170 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 171 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 172 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_16
# 179 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 180 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 181 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 182 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 183 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_17
# 188 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_8
# 189 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 190 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 191 "data/maps/IkiTown/scripts.pory"
	special HealPlayerParty
# 192 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_HEAL
# 193 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 194 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 195 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 196 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 197 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_18, MSGBOX_YESNO
# 198 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Ikitown_Trigger_FestivalBattle_8
# 204 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 205 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_20, MSGBOX_AUTOCLOSE
# 207 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleSaidNo
	return

Ikitown_Trigger_FestivalBattle_2:
# 104 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_3, MSGBOX_AUTOCLOSE
# 106 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 107 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 108 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_4, MSGBOX_AUTOCLOSE
# 109 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_dynhaumon_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 110 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 111 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 112 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Ikitown_Trigger_FestivalBattle_1

Ikitown_Trigger_FestivalBattle_3:
# 116 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_5, MSGBOX_AUTOCLOSE
# 118 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 119 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 120 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_6, MSGBOX_AUTOCLOSE
# 121 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_dynhaumon_festival, Ikitown_Trigger_FestivalBattle_Movement_1
# 122 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 123 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 124 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Ikitown_Trigger_FestivalBattle_1

Ikitown_Trigger_FestivalBattle_4:
# 128 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_7, MSGBOX_AUTOCLOSE
# 130 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 131 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 132 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_8, MSGBOX_AUTOCLOSE
# 133 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_dynhaumon_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 134 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 135 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 136 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Ikitown_Trigger_FestivalBattle_1

Ikitown_Trigger_FestivalBattle_8:
# 199 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 200 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_19, MSGBOX_AUTOCLOSE
# 201 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage
	return


Ikitown_Trigger_FestivalBattleSkip1::
# 213 "data/maps/IkiTown/scripts.pory"
	closemessage
# 214 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 215 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 216 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 217 "data/maps/IkiTown/scripts.pory"
	special HealPlayerParty
# 218 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_kukui_festival
# 219 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_lillie_festival
# 220 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_kukui_festival, 32, 17
# 221 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_lillie_festival, 31, 17
# 222 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_hala_festival
# 223 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_hau_festival
# 224 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_hala_festival, 32, 15
# 225 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_hau_festival, 32, 14
# 226 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 227 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 228 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleSaidNo
	return


Ikitown_FestivalBattleSaidNo::
# 232 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 233 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_18, MSGBOX_YESNO
# 234 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Ikitown_FestivalBattleSaidNo_1
# 240 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 241 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_20, MSGBOX_AUTOCLOSE
# 243 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleSaidNo
	return

Ikitown_FestivalBattleSaidNo_1:
# 235 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 236 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_19, MSGBOX_AUTOCLOSE
# 237 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage
	return


Ikitown_Trigger_FestivalBattleSkip2::
# 248 "data/maps/IkiTown/scripts.pory"
	closemessage
# 249 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 250 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 251 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 252 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 253 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 254 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage2
	return


Ikitown_FestivalBattleOnStage::
# 258 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 260 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_FestivalBattleOnStage_Movement_0
# 262 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_FestivalBattleOnStage_Movement_1
# 264 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage_Movement_2
# 266 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_3
# 268 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_FestivalBattleOnStage_Movement_4
# 269 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 270 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_FESTIVAL_BATTLE_2
# 271 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 272 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_FestivalBattleOnStage_Movement_5
# 273 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 274 "data/maps/IkiTown/scripts.pory"
	hideobjectat ikitown_dynhaumon_festival, MAP_IKI_TOWN
# 275 "data/maps/IkiTown/scripts.pory"
	delay 30
# 276 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 277 "data/maps/IkiTown/scripts.pory"
	delay 30
# 278 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 279 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 280 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 281 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_0, MSGBOX_AUTOCLOSE
# 295 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 296 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 297 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_FestivalBattleOnStage_2
# 301 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_FestivalBattleOnStage_3
# 305 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_FestivalBattleOnStage_4
Ikitown_FestivalBattleOnStage_1:
# 309 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 310 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 311 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 312 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_4, MSGBOX_AUTOCLOSE
# 314 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 315 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_5, MSGBOX_AUTOCLOSE
# 319 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 320 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_mom_festival, Ikitown_FestivalBattleOnStage_Movement_7
# 321 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 322 "data/maps/IkiTown/scripts.pory"
	waitse
# 323 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 324 "data/maps/IkiTown/scripts.pory"
	waitse
# 325 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_FestivalBattleOnStage_Text_6
# 326 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 327 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_7, MSGBOX_AUTOCLOSE
# 329 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 330 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 331 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 332 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_8, MSGBOX_AUTOCLOSE
# 335 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 336 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 337 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 338 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 339 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage2
	return

Ikitown_FestivalBattleOnStage_2:
# 298 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 299 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_1, MSGBOX_AUTOCLOSE
	goto Ikitown_FestivalBattleOnStage_1

Ikitown_FestivalBattleOnStage_3:
# 302 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 303 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_2, MSGBOX_AUTOCLOSE
	goto Ikitown_FestivalBattleOnStage_1

Ikitown_FestivalBattleOnStage_4:
# 306 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 307 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_3, MSGBOX_AUTOCLOSE
	goto Ikitown_FestivalBattleOnStage_1


Ikitown_FestivalBattleOnStage2::
# 343 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 344 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_0, MSGBOX_AUTOCLOSE
# 346 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_FestivalBattleOnStage2_2
# 356 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_FestivalBattleOnStage2_3
# 366 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_FestivalBattleOnStage2_4
Ikitown_FestivalBattleOnStage2_1:
# 376 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 377 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_FESTIVAL_BATTLE_3
# 378 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_2, MSGBOX_AUTOCLOSE
# 381 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 382 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 383 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 384 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 385 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_3
# 387 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage2_Movement_0
# 388 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 389 "data/maps/IkiTown/scripts.pory"
	waitse
# 390 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 391 "data/maps/IkiTown/scripts.pory"
	waitse
# 392 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_4, MSGBOX_AUTOCLOSE
# 394 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 395 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 396 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 397 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_5
# 399 "data/maps/IkiTown/scripts.pory"
	closemessage
# 400 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 401 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 402 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_6, MSGBOX_AUTOCLOSE
# 403 "data/maps/IkiTown/scripts.pory"
	waitmoncry
# 404 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 405 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 406 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 407 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 408 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_7, MSGBOX_AUTOCLOSE
# 410 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage2_Movement_1
# 411 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 412 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_8, MSGBOX_AUTOCLOSE
# 414 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 415 "data/maps/IkiTown/scripts.pory"
	giveitem ITEM_Z_POWER_RING
# 416 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 417 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 418 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_9, MSGBOX_AUTOCLOSE
# 439 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_FestivalBattleOnStage_Movement_7
# 440 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 441 "data/maps/IkiTown/scripts.pory"
	waitse
# 442 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 443 "data/maps/IkiTown/scripts.pory"
	waitse
# 444 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 445 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_10
# 450 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_FestivalBattleOnStage2_Text_11, Ikitown_FestivalBattleOnStage2_Text_12
# 451 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_FestivalBattleOnStage2_9
# 459 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 460 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_13
Ikitown_FestivalBattleOnStage2_8:
# 465 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 466 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_14, MSGBOX_AUTOCLOSE
# 469 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 470 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 471 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 472 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_15, MSGBOX_AUTOCLOSE
# 474 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 475 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 476 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 477 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_16, MSGBOX_AUTOCLOSE
# 488 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage2_Movement_2
# 489 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 490 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 491 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_17, MSGBOX_AUTOCLOSE
# 493 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 494 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 495 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 496 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_18, MSGBOX_AUTOCLOSE
# 502 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage2_Movement_3
# 503 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 504 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 505 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_19, MSGBOX_AUTOCLOSE
# 510 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 511 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 512 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_20
# 514 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 515 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 516 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 517 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_FestivalBattleOnStage_Movement_7
# 518 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 519 "data/maps/IkiTown/scripts.pory"
	waitse
# 520 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 521 "data/maps/IkiTown/scripts.pory"
	waitse
# 522 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 523 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 524 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_21, MSGBOX_AUTOCLOSE
# 526 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 527 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 528 "data/maps/IkiTown/scripts.pory"
	call Ikitown_LeavingIkitownFestival
	return

Ikitown_FestivalBattleOnStage2_2:
# 347 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage2_12
# 353 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_POPPLIO, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_3:
# 357 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage2_15
# 363 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_ROWLET, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_4:
# 367 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage2_18
# 373 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_LITTEN, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_9:
# 452 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 453 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_13
	goto Ikitown_FestivalBattleOnStage2_8

Ikitown_FestivalBattleOnStage2_12:
# 349 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_POPPLIOSHINY, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_15:
# 359 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_ROWLETSHINY, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_18:
# 369 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_LITTENSHINY, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1


Ikitown_LeavingIkitownFestival::
# 532 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 533 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_LeavingIkitownFestival_Movement_0
# 534 "data/maps/IkiTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 535 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 536 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_LeavingIkitownFestival_Movement_1
# 537 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_LeavingIkitownFestival_Movement_2
# 538 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_LeavingIkitownFestival_Movement_3
# 539 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 540 "data/maps/IkiTown/scripts.pory"
	delay 15
# 541 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 542 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_FESTIVAL_BATTLE_4
# 543 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_LeavingIkitownFestival_Movement_4
# 544 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_LeavingIkitownFestival_Movement_4
# 545 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_LeavingIkitownFestival_Movement_4
# 546 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 547 "data/maps/IkiTown/scripts.pory"
	delay 30
# 548 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_5
# 549 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_4
# 550 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 551 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 552 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_0, MSGBOX_AUTOCLOSE
# 556 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 557 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_6
# 558 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 559 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_1
# 560 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 561 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 562 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 563 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_LeavingIkitownFestival_Text_2, Ikitown_LeavingIkitownFestival_Text_3
# 564 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_LeavingIkitownFestival_2
# 573 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 574 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_5, MSGBOX_AUTOCLOSE
Ikitown_LeavingIkitownFestival_1:
# 582 "data/maps/IkiTown/scripts.pory"
	delay 30
# 583 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattleMiddle_Movement_0
# 584 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_LeavingIkitownFestival_Movement_5
# 585 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_LeavingIkitownFestival_Movement_5
# 586 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 587 "data/maps/IkiTown/scripts.pory"
	delay 30
# 588 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 589 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_6, MSGBOX_AUTOCLOSE
# 591 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 592 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_7, MSGBOX_AUTOCLOSE
# 595 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 596 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_LeavingIkitownFestival_Movement_6
# 597 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_LeavingIkitownFestival_Movement_7
# 598 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_LeavingIkitownFestival_Movement_8
# 599 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 600 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownfestivalur4, 31, 20
# 601 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownfestivalur1, 33, 20
# 602 "data/maps/IkiTown/scripts.pory"
	delay 90
# 603 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_Trigger_FestivalBattle_Movement_3
# 604 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownfestivalur4, Ikitown_LeavingIkitownFestival_Movement_9
# 605 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownfestivalur1, Ikitown_LeavingIkitownFestival_Movement_9
# 606 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 607 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_LeavingIkitownFestival_Text_8
# 608 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_9
# 623 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownfestivalur1, Ikitown_Trigger_FestivalBattle_Movement_4
# 624 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 625 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_10
# 628 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownfestivalur4, Ikitown_Trigger_FestivalBattle_Movement_0
# 629 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 630 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_11
# 636 "data/maps/IkiTown/scripts.pory"
	delay 30
# 637 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 638 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 15
# 639 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_IKITOWN_FESTIVAL_COMPLETE
# 640 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 641 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS3
# 642 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 643 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_SOUTH_YOUNGSTER
# 644 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_REGULARNPCS
# 645 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_SOUTH_LASS
# 646 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 647 "data/maps/IkiTown/scripts.pory"
	waitstate
# 648 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_LeavingIkitownFestival_2:
# 565 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 566 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_4, MSGBOX_AUTOCLOSE
	goto Ikitown_LeavingIkitownFestival_1


Ikitown_Trigger_FestivalBattleSkip3::
# 654 "data/maps/IkiTown/scripts.pory"
	closemessage
# 655 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 656 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 657 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 658 "data/maps/IkiTown/scripts.pory"
	additem ITEM_Z_POWER_RING, 1
# 659 "data/maps/IkiTown/scripts.pory"
	call Ikitown_LeavingIkitownFestival
	return


Ikitown_Trigger_FestivalBattleSkip4::
# 663 "data/maps/IkiTown/scripts.pory"
	closemessage
# 664 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 665 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 666 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 667 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 668 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 669 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 670 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 15
# 671 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_IKITOWN_FESTIVAL_COMPLETE
# 672 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 673 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS3
# 674 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 675 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_SOUTH_YOUNGSTER
# 676 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_REGULARNPCS
# 677 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_SOUTH_LASS
# 678 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 679 "data/maps/IkiTown/scripts.pory"
	waitstate
# 680 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_StartFestival::
# 685 "data/maps/IkiTown/scripts.pory"
	lockplayer
# 686 "data/maps/IkiTown/scripts.pory"
	special ShowCutsceneCinematicBars
# 687 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_0
# 688 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_exeggutor_festival, Ikitown_StartFestival_Movement_1
# 689 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_oldman_festival, Ikitown_StartFestival_Movement_2
# 690 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 691 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 692 "data/maps/IkiTown/scripts.pory"
	delay 30
# 693 "data/maps/IkiTown/scripts.pory"
	removeobject ikitown_exeggutor_festival
# 694 "data/maps/IkiTown/scripts.pory"
	removeobject ikitown_oldman_festival
# 695 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 696 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_4
# 697 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 698 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_3
# 699 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 700 "data/maps/IkiTown/scripts.pory"
	delay 30
# 701 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_woman_festival, Ikitown_StartFestival_Movement_4
# 702 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 703 "data/maps/IkiTown/scripts.pory"
	delay 30
# 704 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_5
# 705 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_6
# 706 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 707 "data/maps/IkiTown/scripts.pory"
	delay 30
# 708 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_rockruff_festival, Ikitown_Trigger_FestivalBattle_Movement_5
# 709 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_littlegirl_festival, Ikitown_FestivalBattleOnStage2_Movement_0
# 710 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 711 "data/maps/IkiTown/scripts.pory"
	waitse
# 712 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 713 "data/maps/IkiTown/scripts.pory"
	waitse
# 714 "data/maps/IkiTown/scripts.pory"
	delay 30
# 715 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_7
# 716 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 717 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 718 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 719 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 14
# 720 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_right::
# 726 "data/maps/IkiTown/scripts.pory"
	lock
# 727 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_right_Movement_0
# 728 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 729 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_left::
# 733 "data/maps/IkiTown/scripts.pory"
	lock
# 734 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_left_Movement_0
# 735 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 736 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_WecomeToIkitownSkip::
# 740 "data/maps/IkiTown/scripts.pory"
	closemessage
# 741 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 742 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 743 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 744 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 745 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 746 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 747 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 748 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 749 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 750 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui, 33, 28
# 751 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 752 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 753 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau, MAP_IKI_TOWN
# 754 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 755 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 756 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_WecomeToIkitown::
# 761 "data/maps/IkiTown/scripts.pory"
	lock
# 762 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 763 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 764 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 765 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 766 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownhau, MAP_IKI_TOWN_SOUTH
# 767 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownkukui, MAP_IKI_TOWN_SOUTH
# 768 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 769 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 770 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_WELCOME_TO_IKITOWN
# 771 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_0
# 772 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_1
# 773 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 774 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 775 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_2
# 776 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_3
# 777 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 778 "data/maps/IkiTown/scripts.pory"
	delay 30
# 779 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 780 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 781 "data/maps/IkiTown/scripts.pory"
	delay 30
# 782 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 783 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 784 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_FestivalBattle_Movement_0
# 785 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 786 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 787 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_0, MSGBOX_AUTOCLOSE
# 789 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 790 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_4
# 791 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 792 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_5
# 793 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 794 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 795 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_1, MSGBOX_AUTOCLOSE
# 801 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 802 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_6
# 803 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 804 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 805 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 806 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_7
# 807 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 808 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 809 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_2
# 815 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_Trigger_FestivalBattle_Movement_0
# 816 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 817 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 818 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_3
# 821 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_FestivalBattleOnStage_Movement_7
# 822 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 823 "data/maps/IkiTown/scripts.pory"
	waitse
# 824 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 825 "data/maps/IkiTown/scripts.pory"
	waitse
# 826 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 827 "data/maps/IkiTown/scripts.pory"
	switch VAR_STARTER_MON
# 828 "data/maps/IkiTown/scripts.pory"
	case 0, Ikitown_trigger_WecomeToIkitown_3
# 832 "data/maps/IkiTown/scripts.pory"
	case 1, Ikitown_trigger_WecomeToIkitown_4
# 836 "data/maps/IkiTown/scripts.pory"
	case 2, Ikitown_trigger_WecomeToIkitown_5
Ikitown_trigger_WecomeToIkitown_1:
# 841 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_8
# 842 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 843 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau
# 844 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_FestivalBattle_Movement_0
# 845 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 846 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 847 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_7
# 859 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_FestivalBattleOnStage_Movement_7
# 860 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 861 "data/maps/IkiTown/scripts.pory"
	waitse
# 862 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 863 "data/maps/IkiTown/scripts.pory"
	waitse
# 864 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 865 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_8
# 871 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 872 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 873 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 874 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_trigger_WecomeToIkitown_3:
# 829 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_4, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_4:
# 833 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_5, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_5:
# 837 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_6, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1


Ikitown_KukuiSeeTapuKoko::
# 879 "data/maps/IkiTown/scripts.pory"
	lock
# 880 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 881 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 882 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 884 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Trigger_KukuiSeeTapuKoko::
# 890 "data/maps/IkiTown/scripts.pory"
	lock
# 891 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 892 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 893 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 894 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0
# 895 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 896 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 897 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 899 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 900 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MainSign::
# 905 "data/maps/IkiTown/scripts.pory"
	lock
# 906 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MainSign_Text_0
# 909 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 910 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyWRockruff::
# 915 "data/maps/IkiTown/scripts.pory"
	lock
# 916 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 917 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyWRockruff_Text_0
# 921 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 922 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Rockruff::
# 927 "data/maps/IkiTown/scripts.pory"
	lock
# 928 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 929 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 930 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Rockruff_Text_0
# 931 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 932 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LeftSideGuy::
# 937 "data/maps/IkiTown/scripts.pory"
	lock
# 938 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 939 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeftSideGuy_Text_0
# 941 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 942 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MomwithChild::
# 947 "data/maps/IkiTown/scripts.pory"
	lock
# 948 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 949 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MomwithChild_Text_0
# 955 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 956 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ChildwithMom::
# 961 "data/maps/IkiTown/scripts.pory"
	lock
# 962 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 963 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ChildwithMom_Text_0
# 967 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 968 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_DontForgetToSave::
# 973 "data/maps/IkiTown/scripts.pory"
	lock
# 974 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 975 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_DontForgetToSave_Text_0
# 980 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 981 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_KahunaGivesWisdom::
# 986 "data/maps/IkiTown/scripts.pory"
	lock
# 987 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 988 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KahunaGivesWisdom_Text_0
# 991 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ManBlockingDoor::
# 996 "data/maps/IkiTown/scripts.pory"
	lock
# 997 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 998 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ManBlockingDoor_Text_0
# 1006 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Meowth::
# 1011 "data/maps/IkiTown/scripts.pory"
	lock
# 1012 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1013 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 1014 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Meowth_Text_0
# 1015 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1016 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_sign_Ruinsofconflict::
# 1021 "data/maps/IkiTown/scripts.pory"
	lock
# 1022 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_sign_Ruinsofconflict_Text_0
# 1023 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1024 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_GetPokedex::
# 1029 "data/maps/IkiTown/scripts.pory"
	lock
# 1030 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GET_POKEDEX
# 1031 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_0
# 1032 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_1
# 1033 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1034 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 1035 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_2
# 1036 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1037 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1038 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_0
# 1042 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_FestivalBattleOnStage_Movement_6
# 1043 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1044 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_1
# 1046 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 1047 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1048 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1049 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_2
# 1056 "data/maps/IkiTown/scripts.pory"
	checkplayergender
# 1057 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_GetPokedex_2
# 1066 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1067 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_4
Ikitown_GetPokedex_1:
# 1073 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_0
# 1074 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1075 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1076 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_5, MSGBOX_AUTOCLOSE
# 1080 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 1081 "data/maps/IkiTown/scripts.pory"
	delay 30
# 1083 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_4
# 1084 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1085 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownman1, Ikitown_GetPokedex_Movement_5
# 1086 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownoldman1, Ikitown_GetPokedex_Movement_5
# 1087 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1088 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1089 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1090 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_6, MSGBOX_AUTOCLOSE
# 1097 "data/maps/IkiTown/scripts.pory"
	delay 30
# 1098 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_6
# 1099 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_7
# 1100 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1101 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1102 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_7, MSGBOX_AUTOCLOSE
# 1103 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_8
# 1104 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1105 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_Trigger_FestivalBattle_Movement_5
# 1106 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1107 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1108 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_8, MSGBOX_AUTOCLOSE
# 1110 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_9
# 1111 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1112 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1113 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1114 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1115 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_9
# 1124 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 1125 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1126 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1127 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_10
# 1141 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_FestivalBattleOnStage_Movement_6
# 1142 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1143 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1144 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_11
# 1146 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_FestivalBattleOnStage_Movement_6
# 1147 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1148 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1149 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_12
# 1153 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_FestivalBattleOnStage_Movement_6
# 1154 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1155 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_13, MSGBOX_AUTOCLOSE
# 1171 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_10
# 1172 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_7
# 1173 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1174 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1175 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_14, MSGBOX_AUTOCLOSE
# 1177 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 1178 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 1179 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1180 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1181 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_15
# 1182 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 1183 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1184 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1185 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 1186 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1187 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_16
# 1197 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_17, MSGBOX_AUTOCLOSE
# 1201 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 1202 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1203 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_11
# 1204 "data/maps/IkiTown/scripts.pory"
	delay 60
# 1205 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1206 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 1207 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 1208 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_GetPokedex_2:
# 1058 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1059 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_3
	goto Ikitown_GetPokedex_1


Ikitown_GetPokedexSkip::
# 1213 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1214 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1215 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 1216 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 1217 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 1218 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 1219 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 1220 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 1221 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 1223 "data/maps/IkiTown/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 14
# 1224 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 1229 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 1230 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 1231 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui2
# 1232 "data/maps/IkiTown/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_IKI_TOWN
# 1233 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownlillie, MAP_IKI_TOWN
# 1234 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownhala, MAP_IKI_TOWN
# 1235 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownintrokukui2, MAP_IKI_TOWN
# 1236 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 21, 13
# 1237 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 14
# 1238 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 13
# 1239 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_5
# 1240 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1241 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattle_Movement_4
# 1242 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1243 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1244 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1245 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_lilliedialog2::
# 1250 "data/maps/IkiTown/scripts.pory"
	lock
# 1251 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1252 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 1253 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1254 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_lilliedialog2_Text_0
# 1258 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1259 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_kukuidialog2::
# 1264 "data/maps/IkiTown/scripts.pory"
	lock
# 1265 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1266 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1267 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_kukuidialog2_Text_0
# 1270 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1271 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_haladialog2::
# 1276 "data/maps/IkiTown/scripts.pory"
	lock
# 1277 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1278 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1279 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_haladialog2_Text_0
# 1282 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1283 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_GiveHalaSparklingStone::
# 1288 "data/maps/IkiTown/scripts.pory"
	lock
# 1289 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GIVE_HALA_SPARKLING_STONE
# 1290 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1291 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_0, MSGBOX_AUTOCLOSE
# 1293 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 1294 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_WecomeToIkitown_Movement_7
# 1295 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1296 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1297 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 12
# 1298 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 12
# 1299 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1300 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1301 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1302 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1303 "data/maps/IkiTown/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 1304 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_3
Ikitown_trigger_GiveHalaSparklingStone_1:
# 1312 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_8
Ikitown_trigger_GiveHalaSparklingStone_6:
# 1320 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_13
Ikitown_trigger_GiveHalaSparklingStone_11:
# 1326 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_18
Ikitown_trigger_GiveHalaSparklingStone_16:
# 1332 "data/maps/IkiTown/scripts.pory"
	delay 30
# 1333 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1334 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_5
# 1335 "data/maps/IkiTown/scripts.pory"
	delay 60
# 1336 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_6
# 1337 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1338 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1339 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1340 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1341 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_1
# 1343 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_3
# 1344 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1345 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1346 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_2
# 1352 "data/maps/IkiTown/scripts.pory"
	setvar VAR_RESULT, 1
# 1353 "data/maps/IkiTown/scripts.pory"
	playse SE_M_DETECT
# 1354 "data/maps/IkiTown/scripts.pory"
	dofieldeffectsparkle 24, 14, 0
# 1355 "data/maps/IkiTown/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 1356 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1357 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 1358 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattleleft_Movement_0
# 1359 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1360 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1361 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 1362 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1363 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1364 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_3
# 1370 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_4
# 1371 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1372 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1373 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_4
# 1374 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_3
# 1375 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1376 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1377 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_5
# 1378 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattle_Movement_0
# 1379 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1380 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1381 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_6
# 1384 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_trigger_GiveHalaSparklingStone_Text_7, Ikitown_trigger_GiveHalaSparklingStone_Text_8
# 1385 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_22
# 1406 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1407 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
Ikitown_trigger_GiveHalaSparklingStone_21:
# 1425 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_GiveHalaSparklingStone_Movement_7
# 1426 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1427 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1428 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_10
# 1430 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_Trigger_FestivalBattle_Movement_4
# 1431 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_11
# 1437 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 1438 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1439 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1440 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_12
# 1442 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1443 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 1444 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 1445 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 1446 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 1447 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 1448 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 1449 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 1450 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 1451 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 1452 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 1453 "data/maps/IkiTown/scripts.pory"
	waitstate
	return

Ikitown_trigger_GiveHalaSparklingStone_2:
# 1305 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_0
# 1306 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1307 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1308 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 1309 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 1310 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_3:
# 1304 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_2
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_7:
# 1313 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_2
# 1314 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1315 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1316 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 1317 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 1318 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_8:
# 1312 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_7
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_12:
# 1321 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_3
# 1322 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1323 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1324 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_13:
# 1320 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_12
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_17:
# 1327 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_4
# 1328 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1329 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1330 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_18:
# 1326 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_17
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_22:
# 1386 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1387 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
	goto Ikitown_trigger_GiveHalaSparklingStone_21


Ikitown_trigger_GiveHalaSparklingStoneSkip::
# 1457 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1458 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1459 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 1460 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 1461 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 1462 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 1463 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 1464 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 1465 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 1466 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 1467 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 1468 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 1469 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 1470 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 1471 "data/maps/IkiTown/scripts.pory"
	waitstate
# 1472 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyFestivalRockruffDialog::
# 1478 "data/maps/IkiTown/scripts.pory"
	lock
# 1479 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1480 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyFestivalRockruffDialog_Text_0
# 1482 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleGirlFestivalRockruffDialog::
# 1487 "data/maps/IkiTown/scripts.pory"
	lock
# 1488 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1489 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleGirlFestivalRockruffDialog_Text_0
# 1491 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_FestivalNPC3Dialog::
# 1496 "data/maps/IkiTown/scripts.pory"
	lock
# 1497 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1498 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalNPC3Dialog_Text_0
# 1500 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_FestivalNPC4Dialog::
# 1505 "data/maps/IkiTown/scripts.pory"
	lock
# 1506 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1507 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalNPC4Dialog_Text_0
# 1509 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_FestivalNPC5Dialog::
# 1514 "data/maps/IkiTown/scripts.pory"
	lock
# 1515 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1516 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalNPC5Dialog_Text_0
# 1519 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_FestivalNPC6Dialog::
# 1524 "data/maps/IkiTown/scripts.pory"
	lock
# 1525 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1526 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalNPC6Dialog_Text_0
# 1528 "data/maps/IkiTown/scripts.pory"
	release
	end


# 46 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattleleft_Movement_0:
# 46 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 49 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattleleft_Movement_1:
# 49 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 49 "data/maps/IkiTown/scripts.pory"
	walk_up
# 49 "data/maps/IkiTown/scripts.pory"
	walk_up
# 49 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 60 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattleRight_Movement_0:
# 60 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 60 "data/maps/IkiTown/scripts.pory"
	walk_up
# 60 "data/maps/IkiTown/scripts.pory"
	walk_up
# 60 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 71 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattleMiddle_Movement_0:
# 71 "data/maps/IkiTown/scripts.pory"
	walk_up
# 71 "data/maps/IkiTown/scripts.pory"
	walk_up
# 71 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 79 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_0:
# 79 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
# 79 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
	step_end

# 121 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_1:
# 121 "data/maps/IkiTown/scripts.pory"
	face_left
# 121 "data/maps/IkiTown/scripts.pory"
	delay_16
# 121 "data/maps/IkiTown/scripts.pory"
	face_up
# 121 "data/maps/IkiTown/scripts.pory"
	delay_16
# 121 "data/maps/IkiTown/scripts.pory"
	face_right
# 121 "data/maps/IkiTown/scripts.pory"
	delay_16
# 121 "data/maps/IkiTown/scripts.pory"
	face_down
# 121 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
# 121 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
	step_end

# 143 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_2:
# 143 "data/maps/IkiTown/scripts.pory"
	delay_16
# 143 "data/maps/IkiTown/scripts.pory"
	delay_16
# 143 "data/maps/IkiTown/scripts.pory"
	delay_16
# 143 "data/maps/IkiTown/scripts.pory"
	delay_16
# 143 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 144 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_3:
# 144 "data/maps/IkiTown/scripts.pory"
	walk_up
# 144 "data/maps/IkiTown/scripts.pory"
	walk_up
# 144 "data/maps/IkiTown/scripts.pory"
	walk_up
# 144 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 149 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_4:
# 149 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 150 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_5:
# 150 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 155 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_6:
# 155 "data/maps/IkiTown/scripts.pory"
	shake_horizontal
	step_end

# 169 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_7:
# 169 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 188 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_8:
# 188 "data/maps/IkiTown/scripts.pory"
	walk_left
# 188 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 260 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_0:
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 260 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 260 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 262 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_1:
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 262 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 262 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 264 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_2:
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 264 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 264 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 266 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_3:
# 266 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 266 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 266 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 266 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 266 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 266 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 266 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 266 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 268 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_4:
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 268 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 272 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_5:
# 272 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 272 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
	step_end

# 295 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_6:
# 295 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
# 295 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
	step_end

# 320 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_7:
# 320 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
# 320 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
	step_end

# 387 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_0:
# 387 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
# 387 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
	step_end

# 410 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_1:
# 410 "data/maps/IkiTown/scripts.pory"
	walk_down
# 410 "data/maps/IkiTown/scripts.pory"
	walk_down
# 410 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 488 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_2:
# 488 "data/maps/IkiTown/scripts.pory"
	walk_right
# 488 "data/maps/IkiTown/scripts.pory"
	walk_right
# 488 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 502 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_3:
# 502 "data/maps/IkiTown/scripts.pory"
	walk_left
# 502 "data/maps/IkiTown/scripts.pory"
	walk_left
# 502 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 533 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_0:
# 533 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 533 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
	step_end

# 536 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_1:
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 536 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 537 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_2:
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 537 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 538 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_3:
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 538 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 543 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_4:
# 543 "data/maps/IkiTown/scripts.pory"
	delay_16
# 543 "data/maps/IkiTown/scripts.pory"
	walk_down
# 543 "data/maps/IkiTown/scripts.pory"
	walk_down
# 543 "data/maps/IkiTown/scripts.pory"
	walk_down
# 543 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 584 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_5:
# 584 "data/maps/IkiTown/scripts.pory"
	delay_16
# 584 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 596 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_6:
# 596 "data/maps/IkiTown/scripts.pory"
	delay_16
# 596 "data/maps/IkiTown/scripts.pory"
	walk_down
# 596 "data/maps/IkiTown/scripts.pory"
	walk_down
# 596 "data/maps/IkiTown/scripts.pory"
	walk_down
# 596 "data/maps/IkiTown/scripts.pory"
	walk_down
# 596 "data/maps/IkiTown/scripts.pory"
	walk_down
# 596 "data/maps/IkiTown/scripts.pory"
	walk_down
# 596 "data/maps/IkiTown/scripts.pory"
	walk_down
# 596 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 597 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_7:
# 597 "data/maps/IkiTown/scripts.pory"
	delay_16
# 597 "data/maps/IkiTown/scripts.pory"
	delay_16
# 597 "data/maps/IkiTown/scripts.pory"
	delay_16
# 597 "data/maps/IkiTown/scripts.pory"
	delay_16
# 597 "data/maps/IkiTown/scripts.pory"
	delay_16
# 597 "data/maps/IkiTown/scripts.pory"
	delay_16
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 598 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_8:
# 598 "data/maps/IkiTown/scripts.pory"
	walk_down
# 598 "data/maps/IkiTown/scripts.pory"
	walk_down
# 598 "data/maps/IkiTown/scripts.pory"
	walk_down
# 598 "data/maps/IkiTown/scripts.pory"
	walk_down
# 598 "data/maps/IkiTown/scripts.pory"
	walk_down
# 598 "data/maps/IkiTown/scripts.pory"
	walk_down
# 598 "data/maps/IkiTown/scripts.pory"
	walk_down
# 598 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 604 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_9:
# 604 "data/maps/IkiTown/scripts.pory"
	delay_16
# 604 "data/maps/IkiTown/scripts.pory"
	delay_16
# 604 "data/maps/IkiTown/scripts.pory"
	delay_16
# 604 "data/maps/IkiTown/scripts.pory"
	walk_down
# 604 "data/maps/IkiTown/scripts.pory"
	walk_down
# 604 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 687 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_0:
# 687 "data/maps/IkiTown/scripts.pory"
	walk_up
# 687 "data/maps/IkiTown/scripts.pory"
	walk_up
# 687 "data/maps/IkiTown/scripts.pory"
	walk_up
# 687 "data/maps/IkiTown/scripts.pory"
	walk_up
# 687 "data/maps/IkiTown/scripts.pory"
	delay_16
# 687 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 688 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_1:
# 688 "data/maps/IkiTown/scripts.pory"
	delay_16
# 688 "data/maps/IkiTown/scripts.pory"
	delay_16
# 688 "data/maps/IkiTown/scripts.pory"
	walk_up
# 688 "data/maps/IkiTown/scripts.pory"
	walk_up
# 688 "data/maps/IkiTown/scripts.pory"
	walk_up
# 688 "data/maps/IkiTown/scripts.pory"
	walk_up
# 688 "data/maps/IkiTown/scripts.pory"
	walk_up
# 688 "data/maps/IkiTown/scripts.pory"
	walk_up
# 688 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 689 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_2:
# 689 "data/maps/IkiTown/scripts.pory"
	delay_16
# 689 "data/maps/IkiTown/scripts.pory"
	walk_up
# 689 "data/maps/IkiTown/scripts.pory"
	walk_up
# 689 "data/maps/IkiTown/scripts.pory"
	walk_up
# 689 "data/maps/IkiTown/scripts.pory"
	walk_up
# 689 "data/maps/IkiTown/scripts.pory"
	walk_up
# 689 "data/maps/IkiTown/scripts.pory"
	walk_up
# 689 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 698 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_3:
# 698 "data/maps/IkiTown/scripts.pory"
	walk_left
# 698 "data/maps/IkiTown/scripts.pory"
	walk_left
# 698 "data/maps/IkiTown/scripts.pory"
	walk_left
# 698 "data/maps/IkiTown/scripts.pory"
	walk_left
# 698 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 701 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_4:
# 701 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
# 701 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
	step_end

# 704 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_5:
# 704 "data/maps/IkiTown/scripts.pory"
	delay_16
# 704 "data/maps/IkiTown/scripts.pory"
	delay_16
# 704 "data/maps/IkiTown/scripts.pory"
	delay_16
# 704 "data/maps/IkiTown/scripts.pory"
	delay_16
# 704 "data/maps/IkiTown/scripts.pory"
	delay_16
# 704 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 705 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_6:
# 705 "data/maps/IkiTown/scripts.pory"
	walk_right
# 705 "data/maps/IkiTown/scripts.pory"
	walk_right
# 705 "data/maps/IkiTown/scripts.pory"
	walk_right
# 705 "data/maps/IkiTown/scripts.pory"
	walk_right
# 705 "data/maps/IkiTown/scripts.pory"
	walk_right
# 705 "data/maps/IkiTown/scripts.pory"
	walk_right
# 705 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 715 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_7:
# 715 "data/maps/IkiTown/scripts.pory"
	walk_left
# 715 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 727 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_right_Movement_0:
# 727 "data/maps/IkiTown/scripts.pory"
	walk_left
# 727 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 734 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_left_Movement_0:
# 734 "data/maps/IkiTown/scripts.pory"
	walk_right
# 734 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 751 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitownSkip_Movement_0:
# 751 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 771 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_0:
# 771 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 771 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 771 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 771 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 771 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 771 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 771 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 771 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 771 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 772 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_1:
# 772 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 772 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 772 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 772 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 772 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 772 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 772 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 772 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 772 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 775 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_2:
# 775 "data/maps/IkiTown/scripts.pory"
	walk_up
# 775 "data/maps/IkiTown/scripts.pory"
	walk_up
# 775 "data/maps/IkiTown/scripts.pory"
	walk_up
# 775 "data/maps/IkiTown/scripts.pory"
	walk_up
# 775 "data/maps/IkiTown/scripts.pory"
	walk_up
# 775 "data/maps/IkiTown/scripts.pory"
	walk_up
# 775 "data/maps/IkiTown/scripts.pory"
	walk_up
# 775 "data/maps/IkiTown/scripts.pory"
	walk_up
# 775 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 776 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_3:
# 776 "data/maps/IkiTown/scripts.pory"
	delay_16
# 776 "data/maps/IkiTown/scripts.pory"
	delay_16
# 776 "data/maps/IkiTown/scripts.pory"
	delay_16
# 776 "data/maps/IkiTown/scripts.pory"
	delay_16
# 776 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 776 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 776 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 776 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 776 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 776 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 776 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 776 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 790 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_4:
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 790 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
	step_end

# 792 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_5:
# 792 "data/maps/IkiTown/scripts.pory"
	walk_up
# 792 "data/maps/IkiTown/scripts.pory"
	walk_up
# 792 "data/maps/IkiTown/scripts.pory"
	walk_up
# 792 "data/maps/IkiTown/scripts.pory"
	walk_up
# 792 "data/maps/IkiTown/scripts.pory"
	walk_up
# 792 "data/maps/IkiTown/scripts.pory"
	walk_up
# 792 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 802 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_6:
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 802 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 806 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_7:
# 806 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 841 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_8:
# 841 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 841 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 841 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 841 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 841 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 841 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 841 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 841 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 894 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0:
# 894 "data/maps/IkiTown/scripts.pory"
	face_down
# 894 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 899 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1:
# 899 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 1031 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_0:
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1031 "data/maps/IkiTown/scripts.pory"
	walk_up
# 1031 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 1032 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_1:
# 1032 "data/maps/IkiTown/scripts.pory"
	delay_16
# 1032 "data/maps/IkiTown/scripts.pory"
	delay_16
# 1032 "data/maps/IkiTown/scripts.pory"
	delay_16
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1032 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 1035 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_2:
# 1035 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 1035 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1035 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1046 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_3:
# 1046 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
# 1046 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
	step_end

# 1083 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_4:
# 1083 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1083 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1083 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1083 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1083 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1083 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1083 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1083 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1083 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
	step_end

# 1085 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_5:
# 1085 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 1085 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 1098 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_6:
# 1098 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1098 "data/maps/IkiTown/scripts.pory"
	delay_16
# 1098 "data/maps/IkiTown/scripts.pory"
	delay_16
# 1098 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 1099 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_7:
# 1099 "data/maps/IkiTown/scripts.pory"
	walk_up
# 1099 "data/maps/IkiTown/scripts.pory"
	walk_up
# 1099 "data/maps/IkiTown/scripts.pory"
	walk_up
# 1099 "data/maps/IkiTown/scripts.pory"
	walk_up
# 1099 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1103 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_8:
# 1103 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1103 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1103 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1103 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1103 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1103 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1103 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 1110 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_9:
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_diag_northwest
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 1171 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_10:
# 1171 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1171 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 1203 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_11:
# 1203 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1203 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1203 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 1305 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_0:
# 1305 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1305 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1305 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1305 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 1309 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_1:
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1309 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 1313 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_2:
# 1313 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1313 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1313 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1313 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1313 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1313 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1321 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_3:
# 1321 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1321 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1321 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1321 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1321 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1321 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1321 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1321 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1327 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_4:
# 1327 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1327 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1327 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1327 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1327 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1327 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1327 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1327 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1327 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1334 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_5:
# 1334 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1334 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 1334 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1334 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 1336 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_6:
# 1336 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1336 "data/maps/IkiTown/scripts.pory"
	delay_8
# 1336 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1425 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_7:
# 1425 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

Ikitown_Trigger_FestivalBattle_Text_0:
# 81 "data/maps/IkiTown/scripts.pory"
	.string "Hala$"

Ikitown_Trigger_FestivalBattle_Text_1:
# 82 "data/maps/IkiTown/scripts.pory"
	.string "The Alola Region is made up of our\n"
	.string "four islands.\p"
	.string "And each island has its own guardian\n"
	.string "Pokémon.\p"
	.string "Our festival today is help to express\n"
	.string "our thanks to these great Pokémon\l"
	.string "guardian deities for always\l"
	.string "remaining by our sides.\p"
	.string "Well, we may call it a festival, but it's\n"
	.string "just this little thing you see here.\p"
	.string "There may not be many of us, but at\n"
	.string "least every last one of us here goes\l"
	.string "all out.$"

Ikitown_Trigger_FestivalBattle_Text_2:
# 101 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

Ikitown_Trigger_FestivalBattle_Text_3:
# 104 "data/maps/IkiTown/scripts.pory"
	.string "Man, I thought you'd never make it!\n"
	.string "Me and Popplio've been waiting for ages!$"

Ikitown_Trigger_FestivalBattle_Text_4:
# 108 "data/maps/IkiTown/scripts.pory"
	.string "Arf!$"

Ikitown_Trigger_FestivalBattle_Text_5:
# 116 "data/maps/IkiTown/scripts.pory"
	.string "Man, I thought you'd never make it!\n"
	.string "Me and Rowlet've been waiting for ages!$"

Ikitown_Trigger_FestivalBattle_Text_6:
# 120 "data/maps/IkiTown/scripts.pory"
	.string "Hoo!$"

Ikitown_Trigger_FestivalBattle_Text_7:
# 128 "data/maps/IkiTown/scripts.pory"
	.string "Man, I thought you'd never make it!\n"
	.string "Me and Litten've been waiting for ages!$"

Ikitown_Trigger_FestivalBattle_Text_8:
# 132 "data/maps/IkiTown/scripts.pory"
	.string "Grrr!$"

Ikitown_Trigger_FestivalBattle_Text_9:
# 139 "data/maps/IkiTown/scripts.pory"
	.string "Hold on… Didn't anyone explain to\n"
	.string "you about tonight?!$"

Ikitown_Trigger_FestivalBattle_Text_10:
# 147 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

Ikitown_Trigger_FestivalBattle_Text_11:
# 148 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah, right on time!$"

Ikitown_Trigger_FestivalBattle_Text_12:
# 152 "data/maps/IkiTown/scripts.pory"
	.string "Lillie$"

Ikitown_Trigger_FestivalBattle_Text_13:
# 153 "data/maps/IkiTown/scripts.pory"
	.string "But to what exactly?$"

Ikitown_Trigger_FestivalBattle_Text_14:
# 157 "data/maps/IkiTown/scripts.pory"
	.string "Pew!!$"

Ikitown_Trigger_FestivalBattle_Text_15:
# 162 "data/maps/IkiTown/scripts.pory"
	.string "A full-powered festival for Pokemon\n"
	.string "battling!\p"
	.string "We battle in the name of Tapu Koko,\n"
	.string "pitting our best move against one\l"
	.string "another in friendly competition to\l"
	.string "please our guardian. Woo!$"

Ikitown_Trigger_FestivalBattle_Text_16:
# 172 "data/maps/IkiTown/scripts.pory"
	.string "So, you two will be taking part in\n"
	.string "battle?\p"
	.string "I don't like seeing Pokémon fight one\n"
	.string "another…they often end up hurt.\p"
	.string "But…I'll be sure to watch you both.$"

Ikitown_Trigger_FestivalBattle_Text_17:
# 183 "data/maps/IkiTown/scripts.pory"
	.string "Your Pokémon have fought for you, so\n"
	.string "show them the same care in return,\l"
	.string "{PLAYER}.\p"
	.string "Allow me to heal them for you this time.$"

Ikitown_Trigger_FestivalBattle_Text_18:
# 197 "data/maps/IkiTown/scripts.pory"
	.string "Are you ready for this Pokémon battle?$"

Ikitown_Trigger_FestivalBattle_Text_19:
# 200 "data/maps/IkiTown/scripts.pory"
	.string "Then let's begin!$"

Ikitown_Trigger_FestivalBattle_Text_20:
# 205 "data/maps/IkiTown/scripts.pory"
	.string "Oh come on!\n"
	.string "It's the festival!$"

Ikitown_FestivalBattleOnStage_Text_0:
# 281 "data/maps/IkiTown/scripts.pory"
	.string "For all life on our islands…\p"
	.string "and for those who undertake the island\n"
	.string "challenge with joy in their hearts…\p"
	.string "we pray for your protection…\n"
	.string "for them and all Melemele.\p"
	.string "May this Pokémon battle be an offering\n"
	.string "to our island's guardian deity\l"
	.string "Tapu Koko!\p"
	.string "Before you stands Hau-grandson\n"
	.string "to the kahuna.$"

Ikitown_FestivalBattleOnStage_Text_1:
# 299 "data/maps/IkiTown/scripts.pory"
	.string "Let's have fun with this, Popplio!$"

Ikitown_FestivalBattleOnStage_Text_2:
# 303 "data/maps/IkiTown/scripts.pory"
	.string "Let's have fun with this, Rowlet!$"

Ikitown_FestivalBattleOnStage_Text_3:
# 307 "data/maps/IkiTown/scripts.pory"
	.string "Let's have fun with this, Litten!$"

Ikitown_FestivalBattleOnStage_Text_4:
# 312 "data/maps/IkiTown/scripts.pory"
	.string "Before him stands {PLAYER}-\n"
	.string "one who has met with Tapu Koko.$"

Ikitown_FestivalBattleOnStage_Text_5:
# 315 "data/maps/IkiTown/scripts.pory"
	.string "What?!\p"
	.string "What a curious thing Tapu Koko is!\n"
	.string "Hah, that's just typical of it!$"

Ikitown_FestivalBattleOnStage_Text_6:
# 325 "data/maps/IkiTown/scripts.pory"
	.string "Mom$"

Ikitown_FestivalBattleOnStage_Text_7:
# 327 "data/maps/IkiTown/scripts.pory"
	.string "{STR_VAR_1}!\n"
	.string "Take good care of my little {PLAYER}!$"

Ikitown_FestivalBattleOnStage_Text_8:
# 332 "data/maps/IkiTown/scripts.pory"
	.string "As long as we both have a good time,\n"
	.string "then I think we can call it a great\l"
	.string "battle, eh?$"

Ikitown_FestivalBattleOnStage2_Text_0:
# 344 "data/maps/IkiTown/scripts.pory"
	.string "{PLAYER}! Hau!\n"
	.string "Bring forth the power of your Pokémon!$"

Ikitown_FestivalBattleOnStage2_Text_1:
# 349 "data/maps/IkiTown/scripts.pory"
	.string "What? It's already over?!$"

Ikitown_FestivalBattleOnStage2_Text_2:
# 378 "data/maps/IkiTown/scripts.pory"
	.string "Hoo-ee! Another great battle this year.\p"
	.string "I bet Tapu Koko liked it, too.$"

Ikitown_FestivalBattleOnStage2_Text_3:
# 385 "data/maps/IkiTown/scripts.pory"
	.string "Phew…\n"
	.string "That was awesome, {PLAYER}!$"

Ikitown_FestivalBattleOnStage2_Text_4:
# 392 "data/maps/IkiTown/scripts.pory"
	.string "That was a really great battle!\n"
	.string "I had a blast fighting you!$"

Ikitown_FestivalBattleOnStage2_Text_5:
# 397 "data/maps/IkiTown/scripts.pory"
	.string "It was a good battle.\n"
	.string "With this, even Tapu Koko…$"

Ikitown_FestivalBattleOnStage2_Text_6:
# 402 "data/maps/IkiTown/scripts.pory"
	.string "Ko-ko-kooo!$"

Ikitown_FestivalBattleOnStage2_Text_7:
# 408 "data/maps/IkiTown/scripts.pory"
	.string "Ho! You heard it yourself!\n"
	.string "Tapu Koko's song of approval.$"

Ikitown_FestivalBattleOnStage2_Text_8:
# 412 "data/maps/IkiTown/scripts.pory"
	.string "Oh, I nearly forgot! I think its\n"
	.string "time you take this, {PLAYER}.$"

Ikitown_FestivalBattleOnStage2_Text_9:
# 418 "data/maps/IkiTown/scripts.pory"
	.string "Your {COLOR RED}Z-Power Ring{COLOR DARK_GRAY}, a mysterious armband\n"
	.string "that can draw out the power that\l"
	.string "lies deep within Pokémon…\p"
	.string "It can bring forth their {COLOR RED}Z-Power{COLOR DARK_GRAY}!\p"
	.string "We kahunas can make Z-Power rings\n"
	.string "using stones like the Sparkling\l"
	.string "Stone you received from Tapu Koko.\p"
	.string "Though you will need to undergo the\n"
	.string "island challenge and collect\l"
	.string "Z-Crystals for yourself, if you wish\l"
	.string "to draw forth Pokémon's Z-Power!\p"
	.string "And yet you have already received that\n"
	.string "Sparkling Stone…\p"
	.string "It seems that Tapu Koko took quite a\n"
	.string "liking to you…\l"
	.string "or perhaps it has a mission for you.$"

Ikitown_FestivalBattleOnStage2_Text_10:
# 445 "data/maps/IkiTown/scripts.pory"
	.string "Well, it's time for you to get out there\n"
	.string "and start your {COLOR RED}island challenge{COLOR DARK_GRAY}!\p"
	.string "If you visit every island, maybe you'll\n"
	.string "figure out what that mission is.$"

Ikitown_FestivalBattleOnStage2_Text_11:
# 450 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge?$"

Ikitown_FestivalBattleOnStage2_Text_12:
# 450 "data/maps/IkiTown/scripts.pory"
	.string "Every Island?$"

Ikitown_FestivalBattleOnStage2_Text_13:
# 453 "data/maps/IkiTown/scripts.pory"
	.string "Four Islands!\p"
	.string "You'll travel to each of the four\n"
	.string "islands here in the Alola Region.$"

Ikitown_FestivalBattleOnStage2_Text_14:
# 466 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge is about aiming to\n"
	.string "be the strongest Trainer-\l"
	.string "the {COLOR RED}island challenge champion{COLOR DARK_GRAY}. Woo!$"

Ikitown_FestivalBattleOnStage2_Text_15:
# 472 "data/maps/IkiTown/scripts.pory"
	.string "Sounds great, right?\n"
	.string "I can't wait to have a real adventure!$"

Ikitown_FestivalBattleOnStage2_Text_16:
# 477 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge Kukui spoke of…\p"
	.string "It is a journey to overcome your own\n"
	.string "limitations, as you travel the far\l"
	.string "corners of Alola and meet with\l"
	.string "others along the path.\p"
	.string "It's a great adventure that children\n"
	.string "in the Alola region embark upon,\l"
	.string "along with their Pokémon,\l"
	.string "once they reach 11 years of age!$"

Ikitown_FestivalBattleOnStage2_Text_17:
# 491 "data/maps/IkiTown/scripts.pory"
	.string "Allow me to give you both the island\n"
	.string "challenge amulets you will need.$"

Ikitown_FestivalBattleOnStage2_Text_18:
# 496 "data/maps/IkiTown/scripts.pory"
	.string "Awesome!\n"
	.string "Thanks, Tutu!\p"
	.string "I'm gonna make it through the island\n"
	.string "challenge to try to become an island\l"
	.string "challenge champion!$"

Ikitown_FestivalBattleOnStage2_Text_19:
# 505 "data/maps/IkiTown/scripts.pory"
	.string "There is one for you was well,\n"
	.string "{PLAYER}.\p"
	.string "Please do give the island challenge\n"
	.string "a try.$"

Ikitown_FestivalBattleOnStage2_Text_20:
# 512 "data/maps/IkiTown/scripts.pory"
	.string "You received the {COLOR RED}Island Challenge\n"
	.string "Amulet{COLOR DARK_GRAY}!{PAUSE 30}$"

Ikitown_FestivalBattleOnStage2_Text_21:
# 524 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, doing the island challenge is the\n"
	.string "best way to really get to know Alola!$"

Ikitown_LeavingIkitownFestival_Text_0:
# 552 "data/maps/IkiTown/scripts.pory"
	.string "Tapu Koko is amazing, isn't it?\p"
	.string "I hope I can meet it again someday\n"
	.string "and thank it for saving Nebby…$"

Ikitown_LeavingIkitownFestival_Text_1:
# 559 "data/maps/IkiTown/scripts.pory"
	.string "Pew!$"

Ikitown_LeavingIkitownFestival_Text_2:
# 563 "data/maps/IkiTown/scripts.pory"
	.string "Me, too$"

Ikitown_LeavingIkitownFestival_Text_3:
# 563 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah?$"

Ikitown_LeavingIkitownFestival_Text_4:
# 566 "data/maps/IkiTown/scripts.pory"
	.string "It saved you as well, didn't it?\n"
	.string "And left you with that Sparkling\l"
	.string "Stone…\l"
	.string "even though you're a stranger to\l"
	.string "this place.$"

Ikitown_LeavingIkitownFestival_Text_5:
# 574 "data/maps/IkiTown/scripts.pory"
	.string "You know, {PLAYER}…\n"
	.string "it did save your life, too.\p"
	.string "And it even gifted you that Sparkling\n"
	.string "Stone…\l"
	.string "even though you're a stranger to\l"
	.string "this place.$"

Ikitown_LeavingIkitownFestival_Text_6:
# 589 "data/maps/IkiTown/scripts.pory"
	.string "Suppose it's time we get you kids home,\n"
	.string "yeah?$"

Ikitown_LeavingIkitownFestival_Text_7:
# 592 "data/maps/IkiTown/scripts.pory"
	.string "Nebby…\n"
	.string "Alola is full of all kinds of wonders,\l"
	.string "isn't it?$"

Ikitown_LeavingIkitownFestival_Text_8:
# 607 "data/maps/IkiTown/scripts.pory"
	.string "???$"

Ikitown_LeavingIkitownFestival_Text_9:
# 608 "data/maps/IkiTown/scripts.pory"
	.string "Captain…\p"
	.string "I was able to detect high levels of\n"
	.string "aura at this full-powered festival.\p"
	.string "I suppose you would…\p"
	.string "According to our earlier research it\n"
	.string "seems that the Z-Power Ring and this\l"
	.string "Tapu Koko creature are bathed in a\l"
	.string "great deal of light.\p"
	.string "Alola overflows with the light that\n"
	.string "was released by the Blinding One…\l"
	.string "I find myself rather envious.$"

Ikitown_LeavingIkitownFestival_Text_10:
# 625 "data/maps/IkiTown/scripts.pory"
	.string "I wonder if we can't find some way\n"
	.string "to use the great power that fills\l"
	.string "Alola for ourselves…$"

Ikitown_LeavingIkitownFestival_Text_11:
# 630 "data/maps/IkiTown/scripts.pory"
	.string "That is precisely what we, the Ultra\n"
	.string "Recon Squad, are here to make clear.\p"
	.string "Onward! There is still so much of\n"
	.string "Alola we have not seen, and we must\l"
	.string "investigate it all!$"

Ikitown_trigger_WecomeToIkitown_Text_0:
# 787 "data/maps/IkiTown/scripts.pory"
	.string "And we're here!\n"
	.string "This right here is Iki Town!$"

Ikitown_trigger_WecomeToIkitown_Text_1:
# 795 "data/maps/IkiTown/scripts.pory"
	.string "This town is where folks come to\n"
	.string "worship the Pokemon that watches\l"
	.string "over Melemele Island.\p"
	.string "Tapu Koko keeps us all safe and\n"
	.string "happy, see!$"

Ikitown_trigger_WecomeToIkitown_Text_2:
# 809 "data/maps/IkiTown/scripts.pory"
	.string "Looks like the kahuna's nowhere to be\n"
	.string "found, though…\p"
	.string "I guess there must be some trouble\n"
	.string "somewhere on the island that needs\l"
	.string "fixing, yeah?$"

Ikitown_trigger_WecomeToIkitown_Text_3:
# 818 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, the kahuna wandered off without\n"
	.string "a word to anybody, singing a little\l"
	.string "ditty or something.$"

Ikitown_trigger_WecomeToIkitown_Text_4:
# 829 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Popplio!$"

Ikitown_trigger_WecomeToIkitown_Text_5:
# 833 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Rowlet!$"

Ikitown_trigger_WecomeToIkitown_Text_6:
# 837 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Litten!$"

Ikitown_trigger_WecomeToIkitown_Text_7:
# 847 "data/maps/IkiTown/scripts.pory"
	.string "Hey, I've got an idea for you,\n"
	.string "{PLAYER}.\p"
	.string "If you head through the village and\n"
	.string "up the hill, you can visit the ruins\l"
	.string "that belong to Tapu Koko.\p"
	.string "That's our island's guardian deity,\n"
	.string "yeah.\p"
	.string "Why don't you go and introduce\n"
	.string "yourself?$"

Ikitown_trigger_WecomeToIkitown_Text_8:
# 865 "data/maps/IkiTown/scripts.pory"
	.string "If you're really lucky, maybe you'll\n"
	.string "actually get a glimpse of the\l"
	.string "guardian deity yourself!\p"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_KukuiSeeTapuKoko_Text_0:
# 882 "data/maps/IkiTown/scripts.pory"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_MainSign_Text_0:
# 906 "data/maps/IkiTown/scripts.pory"
	.string "Iki Town\n"
	.string "“The place where we give thanks to\l"
	.string "Pokémon.”$"

Ikitown_LittleBoyWRockruff_Text_0:
# 917 "data/maps/IkiTown/scripts.pory"
	.string "Hey, you've got a Pokémon! I want one,\n"
	.string "too!\p"
	.string "Where'd you get yours?$"

Ikitown_Rockruff_Text_0:
# 930 "data/maps/IkiTown/scripts.pory"
	.string "Wroof!$"

Ikitown_LeftSideGuy_Text_0:
# 939 "data/maps/IkiTown/scripts.pory"
	.string "Welcome to Iki Town, the town watched\n"
	.string "over by Pokémon!$"

Ikitown_MomwithChild_Text_0:
# 949 "data/maps/IkiTown/scripts.pory"
	.string "If you treat your Pokémon wrong, the\n"
	.string "guardian deity will strike you down\l"
	.string "with lightning!\p"
	.string "But the children all laugh when I tell\n"
	.string "them that.$"

Ikitown_ChildwithMom_Text_0:
# 963 "data/maps/IkiTown/scripts.pory"
	.string "I want to meet the guardian deity!\p"
	.string "Maybe I should cause some mischief for\n"
	.string "a Pokémon…$"

Ikitown_DontForgetToSave_Text_0:
# 975 "data/maps/IkiTown/scripts.pory"
	.string "Don't forget to save!\p"
	.string "If you want to remember everything\n"
	.string "that's happened, you must not\l"
	.string "forget to save!$"

Ikitown_KahunaGivesWisdom_Text_0:
# 988 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna gives us wisdom and\n"
	.string "guidance and teaches us how to live\l"
	.string "with our Pokémon.$"

Ikitown_ManBlockingDoor_Text_0:
# 998 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala is the strongest Pokémon\n"
	.string "Trainer on all of Melemele!\p"
	.string "There must be some trouble going down\n"
	.string "somewhere on the island that needs\l"
	.string "a kahuna's touch, 'cause he said\l"
	.string "something about how it's “Time\l"
	.string "for old Hala!” and off he went…$"

Ikitown_Meowth_Text_0:
# 1014 "data/maps/IkiTown/scripts.pory"
	.string "Hsss!$"

Ikitown_sign_Ruinsofconflict_Text_0:
# 1022 "data/maps/IkiTown/scripts.pory"
	.string "Ruins of Conflict$"

Ikitown_GetPokedex_Text_0:
# 1038 "data/maps/IkiTown/scripts.pory"
	.string "Oh, {PLAYER}!\n"
	.string "You already met Lillie, huh?\p"
	.string "She's my assistant, yeah!$"

Ikitown_GetPokedex_Text_1:
# 1044 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, I thought you were with the\n"
	.string "kahuna?$"

Ikitown_GetPokedex_Text_2:
# 1049 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala? He said that he had\n"
	.string "something to attend to, so he left\l"
	.string "town on his own.\p"
	.string "I was just, um, taking a little stroll\n"
	.string "up Mahalo Trail while I waited for\l"
	.string "him to return…$"

Ikitown_GetPokedex_Text_3:
# 1059 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "He just got to Alola yesterday.\n"
	.string "Help him find his way around, yeah?$"

Ikitown_GetPokedex_Text_4:
# 1067 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "She just got to Alola yesterday.\n"
	.string "Help her find her way around, yeah?$"

Ikitown_GetPokedex_Text_5:
# 1076 "data/maps/IkiTown/scripts.pory"
	.string "So…you're also one of\n"
	.string "the professor's acquaintances?\p"
	.string "It's nice to meet you.$"

Ikitown_GetPokedex_Text_6:
# 1090 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna is back!\n"
	.string "Kahuna Hala has returned!\p"
	.string "Our guardian's chosen one is back!\p"
	.string "Only one of the strongest Pokémon\n"
	.string "users in all Alola, yeah!$"

Ikitown_GetPokedex_Text_7:
# 1102 "data/maps/IkiTown/scripts.pory"
	.string "Have I missed something?$"

Ikitown_GetPokedex_Text_8:
# 1108 "data/maps/IkiTown/scripts.pory"
	.string "There you are, Kahuna Hala!\n"
	.string "Was there some kind of trouble?$"

Ikitown_GetPokedex_Text_9:
# 1115 "data/maps/IkiTown/scripts.pory"
	.string "Ahaha! Just got caught up in the\n"
	.string "middle of some brawling Rockruff,\l"
	.string "that's all!\p"
	.string "Sorry, Lillie.\n"
	.string "What were you saying before?\p"
	.string "For some reason I thought I saw\n"
	.string "Tapu Koko flying about…$"

Ikitown_GetPokedex_Text_10:
# 1127 "data/maps/IkiTown/scripts.pory"
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

Ikitown_GetPokedex_Text_11:
# 1144 "data/maps/IkiTown/scripts.pory"
	.string "Woo! That's something you don't hear\n"
	.string "every day!$"

Ikitown_GetPokedex_Text_12:
# 1149 "data/maps/IkiTown/scripts.pory"
	.string "Ho! Although it is said to protect us,\n"
	.string "our Tapu Koko is a rather fickle\l"
	.string "creature.\l"
	.string "Yet our guardian was moved to save you.$"

Ikitown_GetPokedex_Text_13:
# 1155 "data/maps/IkiTown/scripts.pory"
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

Ikitown_GetPokedex_Text_14:
# 1175 "data/maps/IkiTown/scripts.pory"
	.string "All right, here's a lovely gift to\n"
	.string "help make today special {PLAYER}!$"

Ikitown_GetPokedex_Text_15:
# 1181 "data/maps/IkiTown/scripts.pory"
	.string "You obtained a {COLOR RED}Rotom Phone{COLOR DARK_GRAY}!$"

Ikitown_GetPokedex_Text_16:
# 1187 "data/maps/IkiTown/scripts.pory"
	.string "The Rotom Phone comes equipped with a\n"
	.string "Pokédex, which is a really high-tech\l"
	.string "kinda tool, that can automatically\l"
	.string "record facts about any Pokémon that\l"
	.string "you meet.\p"
	.string "Your new partner, {STR_VAR_1} is\n"
	.string "already registered, oh yeah, so\l"
	.string "check it out!$"

Ikitown_GetPokedex_Text_17:
# 1197 "data/maps/IkiTown/scripts.pory"
	.string "Well, you got to meet the kahuna\n"
	.string "at least.\p"
	.string "Ready to head home now, {PLAYER}?$"

ikitown_lilliedialog2_Text_0:
# 1254 "data/maps/IkiTown/scripts.pory"
	.string "I really, um, really appreciate what you\n"
	.string "did for us on the Plank Bridge.\p"
	.string "I won't forget you and {STR_VAR_1}…$"

ikitown_kukuidialog2_Text_0:
# 1267 "data/maps/IkiTown/scripts.pory"
	.string "Now that you met Tapu Koko, I can't\n"
	.string "wait to see how far you can go as a\l"
	.string "Pokémon Trainer!$"

ikitown_haladialog2_Text_0:
# 1279 "data/maps/IkiTown/scripts.pory"
	.string "If you two can work in harmony with\n"
	.string "each other, you can go anywhere\l"
	.string "together!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_0:
# 1291 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah! {PLAYER}!\n"
	.string "Hold up a sec!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_1:
# 1341 "data/maps/IkiTown/scripts.pory"
	.string "What is it Hau? Did you forget\n"
	.string "something?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_2:
# 1346 "data/maps/IkiTown/scripts.pory"
	.string "You're seriously asking me that?!\p"
	.string "Who's the one here who forgot to tell\n"
	.string "anyone before wandering off for a\l"
	.string "little stroll and a sing without a\l"
	.string "word, huh?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_3:
# 1364 "data/maps/IkiTown/scripts.pory"
	.string "Hm?\n"
	.string "{PLAYER}…\p"
	.string "Would you be so kind as to give me a\n"
	.string "look at that {COLOR RED}Sparkling Stone{COLOR DARK_GRAY} you\l"
	.string "have there?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_4:
# 1373 "data/maps/IkiTown/scripts.pory"
	.string "Could it be?!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_5:
# 1377 "data/maps/IkiTown/scripts.pory"
	.string "Tutu, isn't that…$"

Ikitown_trigger_GiveHalaSparklingStone_Text_6:
# 1381 "data/maps/IkiTown/scripts.pory"
	.string "You were rescued by Tapu Koko at the\n"
	.string "bridge-isn't that what I heard,\l"
	.string "{PLAYER}?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_7:
# 1384 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, it rescued me$"

Ikitown_trigger_GiveHalaSparklingStone_Text_8:
# 1384 "data/maps/IkiTown/scripts.pory"
	.string "It gave me a stone$"

Ikitown_trigger_GiveHalaSparklingStone_Text_9:
# 1387 "data/maps/IkiTown/scripts.pory"
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
# 1428 "data/maps/IkiTown/scripts.pory"
	.string "First I'll make sure you get back home\n"
	.string "safe today, though, {PLAYER}.$"

Ikitown_trigger_GiveHalaSparklingStone_Text_11:
# 1431 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, you two should come with us\n"
	.string "too, yeah.\p"
	.string "Wouldn't want to go losing you twice\n"
	.string "in one day.\l"
	.string "You or that precious Pokémon of yours!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_12:
# 1440 "data/maps/IkiTown/scripts.pory"
	.string "Yes…\n"
	.string "I will keep an eye on Nebby.$"

Ikitown_LittleBoyFestivalRockruffDialog_Text_0:
# 1480 "data/maps/IkiTown/scripts.pory"
	.string "Woo-hoo, A festival!\n"
	.string "I wish everyday was a festival!$"

Ikitown_LittleGirlFestivalRockruffDialog_Text_0:
# 1489 "data/maps/IkiTown/scripts.pory"
	.string "What kinds of Pokémon are going to\n"
	.string "battle? I'm so excited!$"

Ikitown_FestivalNPC3Dialog_Text_0:
# 1498 "data/maps/IkiTown/scripts.pory"
	.string "If anyone can have a good battle that\n"
	.string "makes the Pokémon happy, it's Hau!$"

Ikitown_FestivalNPC4Dialog_Text_0:
# 1507 "data/maps/IkiTown/scripts.pory"
	.string "I ate every last bite of my Alola\n"
	.string "yakisoba!$"

Ikitown_FestivalNPC5Dialog_Text_0:
# 1516 "data/maps/IkiTown/scripts.pory"
	.string "Sometimes, I get this feeling…\n"
	.string "this sense of being watched over by\l"
	.string "the guardian deity.$"

Ikitown_FestivalNPC6Dialog_Text_0:
# 1526 "data/maps/IkiTown/scripts.pory"
	.string "Tapu Koko just loves Pokémon battles.\n"
	.string "Watching them and having them!$"
