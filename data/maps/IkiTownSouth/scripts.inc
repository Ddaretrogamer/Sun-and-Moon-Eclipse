IkiTownSouth_MapScripts::
# 2 "data/maps/IkiTownSouth/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 17 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 31 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
# 8 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( POPPLIO )
IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 10 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_KUKUI_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_20
# 14 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LITTEN )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 18 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_13
# 22 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( ROWLET )
IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_12:
# 24 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_KUKUI_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_23
# 28 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( POPPLIO )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 32 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_17
# 36 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( LITTEN )
IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 38 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_KUKUI_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_26
# 42 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( ROWLET )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
# 5 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( POPPLIO )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_8

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_13:
# 19 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( ROWLET )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_12

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_17:
# 33 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( LITTEN )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_16

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 11 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( LITTEN )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_23:
# 25 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( POPPLIO )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_26:
# 39 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( ROWLET )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1


IkiTown_Trigger_HauGetStarter::
# 50 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 51 "data/maps/IkiTownSouth/scripts.pory"
	startcutscene CUTSCENE_HAU_GET_STARTER
# 52 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownmon1
# 53 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownmon2
# 54 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownhau
# 55 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownkukui
# 56 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_KUKUI_STARTERS
# 57 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 58 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 59 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 60 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_0
# 61 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_1
# 62 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 63 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 64 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_2
# 65 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 66 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_3
# 67 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 68 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_0
# 69 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_1
# 73 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 74 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 75 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_4
# 76 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 77 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_3
# 82 "data/maps/IkiTownSouth/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 83 "data/maps/IkiTownSouth/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, IkiTown_Trigger_HauGetStarter_Text_4, IkiTown_Trigger_HauGetStarter_Text_5
# 84 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_2
# 92 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq IkiTown_Trigger_HauGetStarter_3
IkiTown_Trigger_HauGetStarter_1:
# 98 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_6
# 99 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_6
# 100 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_6
# 101 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 102 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 103 "data/maps/IkiTownSouth/scripts.pory"
	checkplayergender
# 104 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_7
# 112 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_10
IkiTown_Trigger_HauGetStarter_6:
# 118 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 119 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 120 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 121 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_11
# 125 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 126 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownkukui
# 127 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 128 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_12
# 130 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_8
# 131 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 132 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 133 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 134 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_11
# 197 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq IkiTown_Trigger_HauGetStarter_12
# 260 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq IkiTown_Trigger_HauGetStarter_13
IkiTown_Trigger_HauGetStarter_10:
# 322 "data/maps/IkiTownSouth/scripts.pory"
	endcutscene
# 323 "data/maps/IkiTownSouth/scripts.pory"
	release
	end

IkiTown_Trigger_HauGetStarter_2:
# 85 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_5
# 86 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 87 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_6
	goto IkiTown_Trigger_HauGetStarter_1

IkiTown_Trigger_HauGetStarter_3:
# 93 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_5
# 94 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 95 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_7
	goto IkiTown_Trigger_HauGetStarter_1

IkiTown_Trigger_HauGetStarter_7:
# 105 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_9
	goto IkiTown_Trigger_HauGetStarter_6

IkiTown_Trigger_HauGetStarter_11:
# 135 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 136 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_9
# 137 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 138 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13
# 139 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 140 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 141 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 142 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 143 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14
# 144 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 145 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 146 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_15
# 148 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 149 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 150 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 151 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 152 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14, MSGBOX_AUTOCLOSE
# 153 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 154 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 155 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 156 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 157 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 158 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 168 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 169 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_10
# 170 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 171 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 172 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_11
# 173 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 174 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_17
# 176 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 177 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 178 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 179 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 180 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 181 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 182 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 183 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_13
# 184 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 185 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_19
# 187 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 188 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 189 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 190 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 191 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_20
# 193 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 194 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 195 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10

IkiTown_Trigger_HauGetStarter_12:
# 198 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 199 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21
# 200 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 201 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 202 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 203 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 204 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14
# 205 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 206 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 207 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 208 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 209 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_22
# 211 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 212 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 213 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21, MSGBOX_AUTOCLOSE
# 214 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 215 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 216 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 217 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_8
# 218 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 219 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 220 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 230 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 231 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_10
# 232 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 233 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 234 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_11
# 235 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 236 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_23
# 238 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 239 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 240 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 241 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 242 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 243 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 244 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 245 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_16
# 246 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 247 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_24
# 249 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 250 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 251 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 252 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 253 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_25
# 255 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 256 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 257 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10

IkiTown_Trigger_HauGetStarter_13:
# 261 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 262 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21
# 263 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 264 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 265 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 266 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 267 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13
# 268 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 269 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 270 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 271 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 272 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_26
# 274 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 275 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 276 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13, MSGBOX_AUTOCLOSE
# 277 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 278 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 279 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 280 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 281 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 282 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 283 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 293 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 294 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_10
# 295 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 296 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 297 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_11
# 298 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 299 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_27
# 301 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 302 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 303 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 304 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 305 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 306 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 307 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 308 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_13
# 309 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 310 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_28
# 312 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 313 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 314 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 315 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 316 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_29
# 318 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 319 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 320 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10


IkiTown_Trigger_HauGetStarterSkip::
# 328 "data/maps/IkiTownSouth/scripts.pory"
	closemessage
# 329 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 330 "data/maps/IkiTownSouth/scripts.pory"
	special StopAllObjectMovements
# 331 "data/maps/IkiTownSouth/scripts.pory"
	special CloseScriptMenus
# 332 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownhau
# 333 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownkukui
# 334 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownmon1
# 335 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownmon2
# 336 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_KUKUI_STARTERS
# 337 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 338 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 339 "data/maps/IkiTownSouth/scripts.pory"
	setobjectxy ikitownhau, 35, 3
# 340 "data/maps/IkiTownSouth/scripts.pory"
	setobjectxy ikitownkukui, 39, 3
# 341 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq IkiTown_Trigger_HauGetStarterSkip_2
# 341 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq IkiTown_Trigger_HauGetStarterSkip_2
# 348 "data/maps/IkiTownSouth/scripts.pory"
	setobjectxy ikitownmon1, 36, 2
# 349 "data/maps/IkiTownSouth/scripts.pory"
	setobjectxy ikitownmon2, 40, 4
# 350 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarterSkip_Movement_0
# 351 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarterSkip_Movement_1
IkiTown_Trigger_HauGetStarterSkip_1:
# 353 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarterSkip_Movement_1
# 354 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarterSkip_Movement_0
# 355 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 356 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 357 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	return

IkiTown_Trigger_HauGetStarterSkip_2:
# 342 "data/maps/IkiTownSouth/scripts.pory"
	setobjectxy ikitownmon1, 40, 2
# 343 "data/maps/IkiTownSouth/scripts.pory"
	setobjectxy ikitownmon2, 36, 4
# 344 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarterSkip_Movement_0
# 345 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarterSkip_Movement_1
	goto IkiTown_Trigger_HauGetStarterSkip_1


Ikitown_RivalBattleYesNo::
# 362 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 363 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_RivalBattleYesNo_Text_0, MSGBOX_YESNO
# 365 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_eq VAR_RESULT, YES, IkiTown_StartRivalBattle
# 366 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RivalBattleNo
	end


RivalBattleNo::
# 371 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 372 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 373 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 374 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 375 "data/maps/IkiTownSouth/scripts.pory"
	msgbox RivalBattleNo_Text_0
# 377 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	return


IkiTown_StartRivalBattle::
# 380 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 381 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 382 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownkukui
# 383 "data/maps/IkiTownSouth/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 384 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_0
# 389 "data/maps/IkiTownSouth/scripts.pory"
	special HealPlayerParty
# 390 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 391 "data/maps/IkiTownSouth/scripts.pory"
	playfanfare MUS_HEAL
# 392 "data/maps/IkiTownSouth/scripts.pory"
	waitfanfare
# 393 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 394 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 395 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_1
# 397 "data/maps/IkiTownSouth/scripts.pory"
	switch VAR_STARTER_MON
# 398 "data/maps/IkiTownSouth/scripts.pory"
	case 0, IkiTown_StartRivalBattle_3
# 406 "data/maps/IkiTownSouth/scripts.pory"
	case 1, IkiTown_StartRivalBattle_4
# 414 "data/maps/IkiTownSouth/scripts.pory"
	case 2, IkiTown_StartRivalBattle_5
IkiTown_StartRivalBattle_1:
# 423 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 424 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_BALL_OPEN
# 425 "data/maps/IkiTownSouth/scripts.pory"
	special HealPlayerParty
# 426 "data/maps/IkiTownSouth/scripts.pory"
	delay 60
# 427 "data/maps/IkiTownSouth/scripts.pory"
	removeobject ikitownmon1
# 428 "data/maps/IkiTownSouth/scripts.pory"
	removeobject ikitownmon2
# 429 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 430 "data/maps/IkiTownSouth/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 431 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_0
# 432 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 433 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 434 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 435 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 436 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 437 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_8
# 447 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 448 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownkukui
# 449 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 450 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_9, MSGBOX_AUTOCLOSE
# 458 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_1
# 459 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 460 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_2
# 461 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 462 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 463 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 464 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 465 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 466 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_10
# 467 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_IKITOWN_STATE, 1
# 468 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 469 "data/maps/IkiTownSouth/scripts.pory"
	release
	end

IkiTown_StartRivalBattle_3:
# 399 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_7
# 403 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_POPPLIO, 3, IkiTown_StartRivalBattle_Text_2, IkiTown_StartRivalBattle_Text_3
IkiTown_StartRivalBattle_6:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_4:
# 407 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_11
# 411 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_ROWLET, 3, IkiTown_StartRivalBattle_Text_4, IkiTown_StartRivalBattle_Text_5
IkiTown_StartRivalBattle_10:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_5:
# 415 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_15
# 419 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_LITTEN, 3, IkiTown_StartRivalBattle_Text_6, IkiTown_StartRivalBattle_Text_7
IkiTown_StartRivalBattle_14:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_7:
# 400 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_POPPLIOSHINY, 3, IkiTown_StartRivalBattle_Text_2, IkiTown_StartRivalBattle_Text_3
	goto IkiTown_StartRivalBattle_6

IkiTown_StartRivalBattle_11:
# 408 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_ROWLETSHINY, 3, IkiTown_StartRivalBattle_Text_4, IkiTown_StartRivalBattle_Text_5
	goto IkiTown_StartRivalBattle_10

IkiTown_StartRivalBattle_15:
# 416 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_LITTENSHINY, 3, IkiTown_StartRivalBattle_Text_6, IkiTown_StartRivalBattle_Text_7
	goto IkiTown_StartRivalBattle_14


IkiTown_Trigger_BottomGetStarters::
# 474 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 475 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_BottomGetStarters_Movement_0
# 476 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 477 "data/maps/IkiTownSouth/scripts.pory"
	call IkiTown_Trigger_HauGetStarter
	return


IkiTown_Trigger_TopGetStarters::
# 480 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 481 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_TopGetStarters_Movement_0
# 482 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 483 "data/maps/IkiTownSouth/scripts.pory"
	call IkiTown_Trigger_HauGetStarter
	return


Ikitown_HauAfterBattle::
# 487 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 488 "data/maps/IkiTownSouth/scripts.pory"
	faceplayer
# 489 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 490 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_10
# 491 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_KukuiAfterBattle::
# 496 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 497 "data/maps/IkiTownSouth/scripts.pory"
	faceplayer
# 498 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 499 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_KukuiAfterBattle_Text_0
# 501 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_Trigger_LeaveIkitownEarly::
# 506 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 507 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 508 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, Ikitown_Trigger_LeaveIkitownEarly_Movement_0
# 509 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarterSkip_Movement_0
# 510 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 511 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 512 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_KukuiAfterBattle_Text_0
# 514 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_LeaveIkitownEarly_Movement_1
# 515 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 516 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_Trigger_LeaveIkitownEarly_left::
# 521 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 522 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 523 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, Ikitown_Trigger_LeaveIkitownEarly_left_Movement_0
# 524 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarterSkip_Movement_1
# 525 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 526 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 527 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_KukuiAfterBattle_Text_0
# 529 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_LeaveIkitownEarly_left_Movement_1
# 530 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 531 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_TrainerTipsSign::
# 536 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 537 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_TrainerTipsSign_Text_0
# 546 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_lassNPC::
# 551 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 552 "data/maps/IkiTownSouth/scripts.pory"
	faceplayer
# 553 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_lassNPC_Text_0
# 558 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_Battle_VsYoungster::
# 563 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_single TRAINER_PRESCHOOLER_OLIVER, Ikitown_Battle_VsYoungster_Text_0, Ikitown_Battle_VsYoungster_Text_1
# 564 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_Battle_VsYoungster_Text_2
# 567 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_Trigger_UltraReconIntroTop::
# 572 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 573 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_UltraReconIntroTop_Movement_0
# 574 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 575 "data/maps/IkiTownSouth/scripts.pory"
	call Ikitown_Trigger_UltraReconIntroScript
	return


Ikitown_Trigger_UltraReconIntroBottom::
# 579 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 580 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_UltraReconIntroBottom_Movement_0
# 581 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 582 "data/maps/IkiTownSouth/scripts.pory"
	call Ikitown_Trigger_UltraReconIntroScript
	return


Ikitown_Trigger_UltraReconIntro::
# 586 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 587 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_UltraReconIntro_Movement_0
# 588 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 589 "data/maps/IkiTownSouth/scripts.pory"
	call Ikitown_Trigger_UltraReconIntroScript
	return


Ikitown_Trigger_UltraReconIntroSkip::
# 593 "data/maps/IkiTownSouth/scripts.pory"
	closemessage
# 594 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 595 "data/maps/IkiTownSouth/scripts.pory"
	special CloseScriptMenus
# 596 "data/maps/IkiTownSouth/scripts.pory"
	removeobject ikitown_south_UR1
# 597 "data/maps/IkiTownSouth/scripts.pory"
	removeobject ikitown_south_UR4
# 598 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_INTRO_UR
# 599 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_IKITOWN_MAN_BLOCKING_DOOR
# 600 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_IKITOWN_STATE, 13
# 601 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 602 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 603 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_Trigger_UltraReconIntroScript::
# 608 "data/maps/IkiTownSouth/scripts.pory"
	startcutscene CUTSCENE_ULTRARECON_INTRO
# 609 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 610 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 611 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_0
# 612 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_Trigger_UltraReconIntroScript_Text_0, MSGBOX_AUTOCLOSE
# 616 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitown_south_UR4, Ikitown_Trigger_UltraReconIntroScript_Movement_0
# 617 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitown_south_UR4
# 618 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_0
# 619 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_Trigger_UltraReconIntroScript_Text_1
# 624 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitown_south_UR4, IkiTown_Trigger_HauGetStarter_Movement_5
# 625 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitown_south_UR4
# 626 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_Trigger_UltraReconIntroScript_Text_2
# 638 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitown_south_UR1, IkiTown_Trigger_HauGetStarter_Movement_7
# 639 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitown_south_UR1
# 640 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_Trigger_UltraReconIntroScript_Text_3
# 642 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitown_south_UR4, IkiTown_Trigger_HauGetStarter_Movement_5
# 643 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitown_south_UR4
# 644 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_Trigger_UltraReconIntroScript_Text_4
# 649 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 650 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitown_south_UR1, Ikitown_Trigger_UltraReconIntroScript_Movement_1
# 651 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitown_south_UR4, Ikitown_Trigger_UltraReconIntroScript_Movement_2
# 652 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 653 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_Trigger_UltraReconIntroScript_Text_5, MSGBOX_AUTOCLOSE
# 656 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitown_south_UR1, Ikitown_Trigger_UltraReconIntroScript_Movement_3
# 657 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitown_south_UR4, Ikitown_Trigger_UltraReconIntroScript_Movement_4
# 658 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 659 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 660 "data/maps/IkiTownSouth/scripts.pory"
	removeobject ikitown_south_UR1
# 661 "data/maps/IkiTownSouth/scripts.pory"
	removeobject ikitown_south_UR4
# 662 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_INTRO_UR
# 663 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_IKITOWN_MAN_BLOCKING_DOOR
# 664 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_IKITOWN_STATE, 13
# 665 "data/maps/IkiTownSouth/scripts.pory"
	endcutscene
# 666 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


# 60 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_0:
# 60 "data/maps/IkiTownSouth/scripts.pory"
	emote_question_mark
	step_end

# 61 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_1:
# 61 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 61 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 61 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 61 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 61 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 61 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 61 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 61 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 61 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 61 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 61 "data/maps/IkiTownSouth/scripts.pory"
	face_left
# 61 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 61 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 61 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 61 "data/maps/IkiTownSouth/scripts.pory"
	face_right
	step_end

# 64 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_2:
# 64 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
# 64 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
	step_end

# 66 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_3:
# 66 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_right
# 66 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_right
# 66 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_right
	step_end

# 75 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_4:
# 75 "data/maps/IkiTownSouth/scripts.pory"
	emote_x
	step_end

# 85 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_5:
# 85 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_left
# 85 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_left
	step_end

# 98 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_6:
# 98 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_left
# 98 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 98 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 98 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 98 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 98 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 98 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
	step_end

# 118 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_7:
# 118 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_right
# 118 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_right
	step_end

# 130 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_8:
# 130 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 130 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
	step_end

# 136 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_9:
# 136 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_left
	step_end

# 169 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_10:
# 169 "data/maps/IkiTownSouth/scripts.pory"
	emote_heart
	step_end

# 172 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_11:
# 172 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 172 "data/maps/IkiTownSouth/scripts.pory"
	face_right
	step_end

# 176 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_12:
# 176 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_left
# 176 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_left
	step_end

# 183 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_13:
# 183 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 183 "data/maps/IkiTownSouth/scripts.pory"
	face_down
	step_end

# 188 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_14:
# 188 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
	step_end

# 200 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_15:
# 200 "data/maps/IkiTownSouth/scripts.pory"
	face_up
# 200 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 200 "data/maps/IkiTownSouth/scripts.pory"
	face_right
# 200 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 200 "data/maps/IkiTownSouth/scripts.pory"
	face_down
# 200 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 200 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 245 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_16:
# 245 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 245 "data/maps/IkiTownSouth/scripts.pory"
	face_up
	step_end

# 344 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarterSkip_Movement_0:
# 344 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 345 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarterSkip_Movement_1:
# 345 "data/maps/IkiTownSouth/scripts.pory"
	face_right
	step_end

# 431 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_StartRivalBattle_Movement_0:
# 431 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_right
# 431 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_right
	step_end

# 458 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_StartRivalBattle_Movement_1:
# 458 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 458 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 458 "data/maps/IkiTownSouth/scripts.pory"
	walk_up
# 458 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 458 "data/maps/IkiTownSouth/scripts.pory"
	face_down
# 458 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 458 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
	step_end

# 460 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_StartRivalBattle_Movement_2:
# 460 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_down
# 460 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_down
	step_end

# 475 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_BottomGetStarters_Movement_0:
# 475 "data/maps/IkiTownSouth/scripts.pory"
	walk_up
# 475 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 481 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_TopGetStarters_Movement_0:
# 481 "data/maps/IkiTownSouth/scripts.pory"
	walk_down
# 481 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 508 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_0:
# 508 "data/maps/IkiTownSouth/scripts.pory"
	face_right
# 508 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
	step_end

# 514 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_1:
# 514 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
	step_end

# 523 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_left_Movement_0:
# 523 "data/maps/IkiTownSouth/scripts.pory"
	face_left
# 523 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
	step_end

# 529 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_left_Movement_1:
# 529 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
	step_end

# 573 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_UltraReconIntroTop_Movement_0:
# 573 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 573 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 573 "data/maps/IkiTownSouth/scripts.pory"
	walk_down
# 573 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 573 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 573 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 573 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 573 "data/maps/IkiTownSouth/scripts.pory"
	face_up
	step_end

# 580 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_UltraReconIntroBottom_Movement_0:
# 580 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 580 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 580 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 580 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 580 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 580 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 580 "data/maps/IkiTownSouth/scripts.pory"
	walk_up
	step_end

# 587 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_UltraReconIntro_Movement_0:
# 587 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 587 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 587 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 587 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 587 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 587 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 587 "data/maps/IkiTownSouth/scripts.pory"
	face_up
	step_end

# 616 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_UltraReconIntroScript_Movement_0:
# 616 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
# 616 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 650 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_UltraReconIntroScript_Movement_1:
# 650 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
# 650 "data/maps/IkiTownSouth/scripts.pory"
	face_down
	step_end

# 651 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_UltraReconIntroScript_Movement_2:
# 651 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 651 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 651 "data/maps/IkiTownSouth/scripts.pory"
	face_down
	step_end

# 656 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_UltraReconIntroScript_Movement_3:
# 656 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 656 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_down
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 656 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
	step_end

# 657 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_UltraReconIntroScript_Movement_4:
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_down
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 657 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
	step_end

IkiTown_Trigger_HauGetStarter_Text_0:
# 68 "data/maps/IkiTownSouth/scripts.pory"
	.string "???$"

IkiTown_Trigger_HauGetStarter_Text_1:
# 69 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hey, hey!\p"
	.string "Which Pokémon are you gonna choose as\n"
	.string "your partner? {PAUSE 30} Have you decided?$"

IkiTown_Trigger_HauGetStarter_Text_2:
# 73 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hau$"

IkiTown_Trigger_HauGetStarter_Text_3:
# 77 "data/maps/IkiTownSouth/scripts.pory"
	.string "Oh yeah! I'm Hau!\p"
	.string "I couldn't wait for us to pick our\n"
	.string "partners together, so I came to find\l"
	.string "you myself!$"

IkiTown_Trigger_HauGetStarter_Text_4:
# 83 "data/maps/IkiTownSouth/scripts.pory"
	.string "I chose {STR_VAR_1}!$"

IkiTown_Trigger_HauGetStarter_Text_5:
# 83 "data/maps/IkiTownSouth/scripts.pory"
	.string "You're too late.$"

IkiTown_Trigger_HauGetStarter_Text_6:
# 87 "data/maps/IkiTownSouth/scripts.pory"
	.string "Whoa! {STR_VAR_1} is so cool!\p"
	.string "Hey wait!\n"
	.string "You already picked your Pokémon?!$"

IkiTown_Trigger_HauGetStarter_Text_7:
# 95 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hey wait!\n"
	.string "You already picked your Pokémon?!$"

IkiTown_Trigger_HauGetStarter_Text_8:
# 102 "data/maps/IkiTownSouth/scripts.pory"
	.string "Kukui$"

IkiTown_Trigger_HauGetStarter_Text_9:
# 105 "data/maps/IkiTownSouth/scripts.pory"
	.string "Sorry about that, Hau.\p"
	.string "We had a little accident on the way\n"
	.string "here, so I ended up letting {PLAYER}\l"
	.string "choose his partner first without you.$"

IkiTown_Trigger_HauGetStarter_Text_10:
# 112 "data/maps/IkiTownSouth/scripts.pory"
	.string "Sorry about that, Hau.\p"
	.string "We had a little accident on the way\n"
	.string "here, so I ended up letting {PLAYER}\l"
	.string "choose her partner first without you.$"

IkiTown_Trigger_HauGetStarter_Text_11:
# 121 "data/maps/IkiTownSouth/scripts.pory"
	.string "Fair enough.\p"
	.string "I guess it was just fate for you guys\n"
	.string "to meet!$"

IkiTown_Trigger_HauGetStarter_Text_12:
# 128 "data/maps/IkiTownSouth/scripts.pory"
	.string "But you can choose one of the\n"
	.string "remaining two, Hau!$"

IkiTown_Trigger_HauGetStarter_Text_13:
# 138 "data/maps/IkiTownSouth/scripts.pory"
	.string "Mrawr!$"

IkiTown_Trigger_HauGetStarter_Text_14:
# 143 "data/maps/IkiTownSouth/scripts.pory"
	.string "Bwark!$"

IkiTown_Trigger_HauGetStarter_Text_15:
# 146 "data/maps/IkiTownSouth/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Popplio! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_16:
# 158 "data/maps/IkiTownSouth/scripts.pory"
	.string "Alola, friend!\p"
	.string "I decided ages ago that you're the\n"
	.string "one I wanted to have an adventure\l"
	.string "with!\p"
	.string "We're gonna do so much awesome stuff\n"
	.string "together!\p"
	.string "Just you wait and see!$"

IkiTown_Trigger_HauGetStarter_Text_17:
# 174 "data/maps/IkiTownSouth/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Litten, right?$"

IkiTown_Trigger_HauGetStarter_Text_18:
# 182 "data/maps/IkiTownSouth/scripts.pory"
	.string "You better believe I will, Hau!$"

IkiTown_Trigger_HauGetStarter_Text_19:
# 185 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right then. Litten! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_20:
# 191 "data/maps/IkiTownSouth/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Popplio have a favor to ask.$"

IkiTown_Trigger_HauGetStarter_Text_21:
# 199 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hoo!$"

IkiTown_Trigger_HauGetStarter_Text_22:
# 209 "data/maps/IkiTownSouth/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Rowlet! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_23:
# 236 "data/maps/IkiTownSouth/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Popplio, right?$"

IkiTown_Trigger_HauGetStarter_Text_24:
# 247 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right then. Popplio! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_25:
# 253 "data/maps/IkiTownSouth/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Rowlet have a favor to ask.$"

IkiTown_Trigger_HauGetStarter_Text_26:
# 272 "data/maps/IkiTownSouth/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Litten! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_27:
# 299 "data/maps/IkiTownSouth/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Rowlet, right?$"

IkiTown_Trigger_HauGetStarter_Text_28:
# 310 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right then. Rowlet! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_29:
# 316 "data/maps/IkiTownSouth/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Litten have a favor to ask.$"

Ikitown_RivalBattleYesNo_Text_0:
# 363 "data/maps/IkiTownSouth/scripts.pory"
	.string "Be our opponents in our first ever\n"
	.string "Pokémon battle together!$"

RivalBattleNo_Text_0:
# 375 "data/maps/IkiTownSouth/scripts.pory"
	.string "Come on, don't be like that!\n"
	.string "It'll be fun!$"

IkiTown_StartRivalBattle_Text_0:
# 384 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hold on!\p"
	.string "Before you two step into the ring,\n"
	.string "let's make sure little {STR_VAR_1} is up\l"
	.string "to it!$"

IkiTown_StartRivalBattle_Text_1:
# 395 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right, I'm surely going to enjoy\n"
	.string "this!$"

IkiTown_StartRivalBattle_Text_2:
# 400 "data/maps/IkiTownSouth/scripts.pory"
	.string "Our first defeat! Sorry, Popplio!$"

IkiTown_StartRivalBattle_Text_3:
# 400 "data/maps/IkiTownSouth/scripts.pory"
	.string "Alola! Way to go, Popplio!$"

IkiTown_StartRivalBattle_Text_4:
# 408 "data/maps/IkiTownSouth/scripts.pory"
	.string "Our first defeat! Sorry, Rowlet!$"

IkiTown_StartRivalBattle_Text_5:
# 408 "data/maps/IkiTownSouth/scripts.pory"
	.string "Alola! Way to go, Rowlet!$"

IkiTown_StartRivalBattle_Text_6:
# 416 "data/maps/IkiTownSouth/scripts.pory"
	.string "Our first defeat! Sorry, Litten!$"

IkiTown_StartRivalBattle_Text_7:
# 416 "data/maps/IkiTownSouth/scripts.pory"
	.string "Alola! Way to go, Litten!$"

IkiTown_StartRivalBattle_Text_8:
# 437 "data/maps/IkiTownSouth/scripts.pory"
	.string "Whoa! That was awesome, {PLAYER}!\p"
	.string "You and {STR_VAR_1} were both so\n"
	.string "cool!\p"
	.string "You've gotta have the kinda battles\n"
	.string "where everyone has fun.\p"
	.string "You and your partner Pokémon, too,\n"
	.string "you know?$"

IkiTown_StartRivalBattle_Text_9:
# 450 "data/maps/IkiTownSouth/scripts.pory"
	.string "Right on {PLAYER}!\p"
	.string "You and Hau both brought out the\n"
	.string "best in your partners and pulled\l"
	.string "off some spectacular moves, yeah!\p"
	.string "Iki Town is right up those stairs.\n"
	.string "Come on, {PLAYER}!$"

IkiTown_StartRivalBattle_Text_10:
# 466 "data/maps/IkiTownSouth/scripts.pory"
	.string "You should totally check out Iki Town!$"

Ikitown_KukuiAfterBattle_Text_0:
# 499 "data/maps/IkiTownSouth/scripts.pory"
	.string "Iki Town is right up those stairs.\n"
	.string "Come on, {PLAYER}!$"

Ikitown_TrainerTipsSign_Text_0:
# 537 "data/maps/IkiTownSouth/scripts.pory"
	.string "Trainer Tips\p"
	.string "Pokémon can gain Exp. Points by\n"
	.string "battling other Pokémon.\p"
	.string "Exp. Points help them grow stronger.\n"
	.string "And your Pokémon will still get Exp.\l"
	.string "Points even if you catch a Pokémon\l"
	.string "you are battling against!$"

Ikitown_lassNPC_Text_0:
# 553 "data/maps/IkiTownSouth/scripts.pory"
	.string "If you happen to pick up a Potion\n"
	.string "anywhere, use it on your Pokémon\l"
	.string "when it's low on HP…\l"
	.string "and it'll be feeling better before\l"
	.string "you know it!$"

Ikitown_Battle_VsYoungster_Text_0:
# 563 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hey! Please battle me!$"

Ikitown_Battle_VsYoungster_Text_1:
# 563 "data/maps/IkiTownSouth/scripts.pory"
	.string "If you're strong, please go away!$"

Ikitown_Battle_VsYoungster_Text_2:
# 564 "data/maps/IkiTownSouth/scripts.pory"
	.string "Great Trainers can sense promise in\n"
	.string "other Trainers!\l"
	.string "Did you pick up on anything?$"

Ikitown_Trigger_UltraReconIntroScript_Text_0:
# 612 "data/maps/IkiTownSouth/scripts.pory"
	.string "Measuring the aura readings here…\n"
	.string "the numbers appear to be a bit high.\p"
	.string "What do you think, Captain?$"

Ikitown_Trigger_UltraReconIntroScript_Text_1:
# 619 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hm?! What was what?\n"
	.string "Did you say something? I was…\p"
	.string "Well, I was certainly not distracted\n"
	.string "by this foolish display of festivity!$"

Ikitown_Trigger_UltraReconIntroScript_Text_2:
# 626 "data/maps/IkiTownSouth/scripts.pory"
	.string "There are aura readings in this place…\n"
	.string "Perhaps it may be the effects of\l"
	.string "that one they call the island kahuna.\p"
	.string "But everything is so bright here in\n"
	.string "Alola…\p"
	.string "Far brighter than we had been told it\n"
	.string "would be.\p"
	.string "I find it loathsome.\n"
	.string "This awful brightness.$"

Ikitown_Trigger_UltraReconIntroScript_Text_3:
# 640 "data/maps/IkiTownSouth/scripts.pory"
	.string "Even though this is the light we have\n"
	.string "sought for so long?$"

Ikitown_Trigger_UltraReconIntroScript_Text_4:
# 644 "data/maps/IkiTownSouth/scripts.pory"
	.string "Y-yes, I suppose you are right.\p"
	.string "We must carry out our investigations to\n"
	.string "return the light to our own world.\l"
	.string "Before the Blinding One can awaken…$"

Ikitown_Trigger_UltraReconIntroScript_Text_5:
# 653 "data/maps/IkiTownSouth/scripts.pory"
	.string "You- You are not native to Alola either,\n"
	.string "are you?\l"
	.string "You seem to have come from far away{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"
