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
	addobject ikitownmon1
# 52 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownmon2
# 53 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownhau
# 54 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownkukui
# 55 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_KUKUI_STARTERS
# 56 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 57 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 58 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 59 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_0
# 60 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_1
# 61 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 62 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 63 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_2
# 64 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 65 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_3
# 66 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 67 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_0
# 68 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_1
# 72 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 73 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 74 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_4
# 75 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 76 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_3
# 81 "data/maps/IkiTownSouth/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 82 "data/maps/IkiTownSouth/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, IkiTown_Trigger_HauGetStarter_Text_4, IkiTown_Trigger_HauGetStarter_Text_5
# 83 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_2
# 91 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq IkiTown_Trigger_HauGetStarter_3
IkiTown_Trigger_HauGetStarter_1:
# 97 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_6
# 98 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_6
# 99 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_6
# 100 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 101 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 102 "data/maps/IkiTownSouth/scripts.pory"
	checkplayergender
# 103 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_7
# 111 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_10
IkiTown_Trigger_HauGetStarter_6:
# 117 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 118 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 119 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 120 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_11
# 124 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 125 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownkukui
# 126 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 127 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_12
# 129 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_8
# 130 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 131 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 132 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 133 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_11
# 196 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq IkiTown_Trigger_HauGetStarter_12
# 259 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq IkiTown_Trigger_HauGetStarter_13
IkiTown_Trigger_HauGetStarter_10:
# 321 "data/maps/IkiTownSouth/scripts.pory"
	release
	end

IkiTown_Trigger_HauGetStarter_2:
# 84 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_5
# 85 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 86 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_6
	goto IkiTown_Trigger_HauGetStarter_1

IkiTown_Trigger_HauGetStarter_3:
# 92 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_5
# 93 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 94 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_7
	goto IkiTown_Trigger_HauGetStarter_1

IkiTown_Trigger_HauGetStarter_7:
# 104 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_9
	goto IkiTown_Trigger_HauGetStarter_6

IkiTown_Trigger_HauGetStarter_11:
# 134 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 135 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_9
# 136 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 137 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13
# 138 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 139 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 140 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 141 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 142 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14
# 143 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 144 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 145 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_15
# 147 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 148 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 149 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 150 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 151 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14, MSGBOX_AUTOCLOSE
# 152 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 153 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 154 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 155 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 156 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 157 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 167 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 168 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_10
# 169 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 170 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 171 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_11
# 172 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 173 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_17
# 175 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 176 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 177 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 178 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 179 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 180 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 181 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 182 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_13
# 183 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 184 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_19
# 186 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 187 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 188 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 189 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 190 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_20
# 192 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 193 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 194 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10

IkiTown_Trigger_HauGetStarter_12:
# 197 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 198 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21
# 199 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 200 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 201 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 202 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 203 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14
# 204 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 205 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 206 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 207 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 208 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_22
# 210 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 211 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 212 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21, MSGBOX_AUTOCLOSE
# 213 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 214 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 215 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 216 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_8
# 217 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 218 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 219 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 229 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 230 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_10
# 231 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 232 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 233 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_11
# 234 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 235 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_23
# 237 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 238 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 239 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 240 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 241 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 242 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 243 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 244 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_16
# 245 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 246 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_24
# 248 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 249 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 250 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 251 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 252 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_25
# 254 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 255 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 256 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10

IkiTown_Trigger_HauGetStarter_13:
# 260 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 261 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21
# 262 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 263 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 264 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 265 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 266 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13
# 267 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 268 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 269 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 270 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 271 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_26
# 273 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 274 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 275 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13, MSGBOX_AUTOCLOSE
# 276 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 277 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 278 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 279 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 280 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 281 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 282 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 292 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 293 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_10
# 294 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 295 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 296 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_11
# 297 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 298 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_27
# 300 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 301 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 302 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 303 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 304 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 305 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 306 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 307 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_13
# 308 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 309 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_28
# 311 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 312 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 313 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 314 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 315 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_29
# 317 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 318 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 319 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10


Ikitown_RivalBattleYesNo::
# 326 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 327 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_RivalBattleYesNo_Text_0, MSGBOX_YESNO
# 329 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_eq VAR_RESULT, YES, IkiTown_StartRivalBattle
# 330 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RivalBattleNo
	end


RivalBattleNo::
# 335 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 336 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 337 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 338 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 339 "data/maps/IkiTownSouth/scripts.pory"
	msgbox RivalBattleNo_Text_0
# 341 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	return


IkiTown_StartRivalBattle::
# 344 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 345 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 346 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownkukui
# 347 "data/maps/IkiTownSouth/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 348 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_0
# 353 "data/maps/IkiTownSouth/scripts.pory"
	special HealPlayerParty
# 354 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 355 "data/maps/IkiTownSouth/scripts.pory"
	playfanfare MUS_HEAL
# 356 "data/maps/IkiTownSouth/scripts.pory"
	waitfanfare
# 357 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 358 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 359 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_1
# 361 "data/maps/IkiTownSouth/scripts.pory"
	switch VAR_STARTER_MON
# 362 "data/maps/IkiTownSouth/scripts.pory"
	case 0, IkiTown_StartRivalBattle_3
# 370 "data/maps/IkiTownSouth/scripts.pory"
	case 1, IkiTown_StartRivalBattle_4
# 378 "data/maps/IkiTownSouth/scripts.pory"
	case 2, IkiTown_StartRivalBattle_5
IkiTown_StartRivalBattle_1:
# 387 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 388 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_BALL_OPEN
# 389 "data/maps/IkiTownSouth/scripts.pory"
	special HealPlayerParty
# 390 "data/maps/IkiTownSouth/scripts.pory"
	delay 60
# 391 "data/maps/IkiTownSouth/scripts.pory"
	removeobject ikitownmon1
# 392 "data/maps/IkiTownSouth/scripts.pory"
	removeobject ikitownmon2
# 393 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 394 "data/maps/IkiTownSouth/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 395 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_0
# 396 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 397 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 398 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 399 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 400 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 401 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_8
# 411 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 412 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownkukui
# 413 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 414 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_9, MSGBOX_AUTOCLOSE
# 422 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_1
# 423 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 424 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_2
# 425 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 426 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 427 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 428 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 429 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 430 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_10
# 431 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_IKITOWN_STATE, 1
# 432 "data/maps/IkiTownSouth/scripts.pory"
	release
	end

IkiTown_StartRivalBattle_3:
# 363 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_7
# 367 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_POPPLIO, 3, IkiTown_StartRivalBattle_Text_2, IkiTown_StartRivalBattle_Text_3
IkiTown_StartRivalBattle_6:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_4:
# 371 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_11
# 375 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_ROWLET, 3, IkiTown_StartRivalBattle_Text_4, IkiTown_StartRivalBattle_Text_5
IkiTown_StartRivalBattle_10:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_5:
# 379 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_15
# 383 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_LITTEN, 3, IkiTown_StartRivalBattle_Text_6, IkiTown_StartRivalBattle_Text_7
IkiTown_StartRivalBattle_14:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_7:
# 364 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_POPPLIOSHINY, 3, IkiTown_StartRivalBattle_Text_2, IkiTown_StartRivalBattle_Text_3
	goto IkiTown_StartRivalBattle_6

IkiTown_StartRivalBattle_11:
# 372 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_ROWLETSHINY, 3, IkiTown_StartRivalBattle_Text_4, IkiTown_StartRivalBattle_Text_5
	goto IkiTown_StartRivalBattle_10

IkiTown_StartRivalBattle_15:
# 380 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_earlyrival TRAINER_HAU_IKITOWN1_LITTENSHINY, 3, IkiTown_StartRivalBattle_Text_6, IkiTown_StartRivalBattle_Text_7
	goto IkiTown_StartRivalBattle_14


IkiTown_Trigger_BottomGetStarters::
# 437 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 438 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_BottomGetStarters_Movement_0
# 439 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 440 "data/maps/IkiTownSouth/scripts.pory"
	call IkiTown_Trigger_HauGetStarter
	return


IkiTown_Trigger_TopGetStarters::
# 443 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 444 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_TopGetStarters_Movement_0
# 445 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 446 "data/maps/IkiTownSouth/scripts.pory"
	call IkiTown_Trigger_HauGetStarter
	return


Ikitown_HauAfterBattle::
# 450 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 451 "data/maps/IkiTownSouth/scripts.pory"
	faceplayer
# 452 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 453 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_10
# 454 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_KukuiAfterBattle::
# 459 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 460 "data/maps/IkiTownSouth/scripts.pory"
	faceplayer
# 461 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 462 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_KukuiAfterBattle_Text_0
# 464 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_Trigger_LeaveIkitownEarly::
# 469 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 470 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 471 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, Ikitown_Trigger_LeaveIkitownEarly_Movement_0
# 472 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_LeaveIkitownEarly_Movement_1
# 473 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 474 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 475 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_KukuiAfterBattle_Text_0
# 477 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_LeaveIkitownEarly_Movement_2
# 478 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 479 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_Trigger_LeaveIkitownEarly_left::
# 484 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 485 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 486 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, Ikitown_Trigger_LeaveIkitownEarly_Movement_0
# 487 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_LeaveIkitownEarly_left_Movement_0
# 488 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 489 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 490 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_KukuiAfterBattle_Text_0
# 492 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_LeaveIkitownEarly_left_Movement_1
# 493 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 494 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_TrainerTipsSign::
# 499 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 500 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_TrainerTipsSign_Text_0
# 509 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_lassNPC::
# 514 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 515 "data/maps/IkiTownSouth/scripts.pory"
	faceplayer
# 516 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_lassNPC_Text_0
# 521 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


# 59 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_0:
# 59 "data/maps/IkiTownSouth/scripts.pory"
	emote_question_mark
	step_end

# 60 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_1:
# 60 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 60 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 60 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 60 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 60 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 60 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 60 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 60 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 60 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 60 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 60 "data/maps/IkiTownSouth/scripts.pory"
	face_left
# 60 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 60 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 60 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 60 "data/maps/IkiTownSouth/scripts.pory"
	face_right
	step_end

# 63 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_2:
# 63 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
# 63 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
	step_end

# 65 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_3:
# 65 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_right
# 65 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_right
# 65 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_right
	step_end

# 74 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_4:
# 74 "data/maps/IkiTownSouth/scripts.pory"
	emote_x
	step_end

# 84 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_5:
# 84 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_left
# 84 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_left
	step_end

# 97 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_6:
# 97 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_left
# 97 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 97 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 97 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 97 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 97 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 97 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
	step_end

# 117 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_7:
# 117 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_right
# 117 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_right
	step_end

# 129 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_8:
# 129 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 129 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
	step_end

# 135 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_9:
# 135 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_left
	step_end

# 168 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_10:
# 168 "data/maps/IkiTownSouth/scripts.pory"
	emote_heart
	step_end

# 171 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_11:
# 171 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 171 "data/maps/IkiTownSouth/scripts.pory"
	face_right
	step_end

# 175 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_12:
# 175 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_left
# 175 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_left
	step_end

# 182 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_13:
# 182 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 182 "data/maps/IkiTownSouth/scripts.pory"
	face_down
	step_end

# 187 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_14:
# 187 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
	step_end

# 199 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_15:
# 199 "data/maps/IkiTownSouth/scripts.pory"
	face_up
# 199 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 199 "data/maps/IkiTownSouth/scripts.pory"
	face_right
# 199 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 199 "data/maps/IkiTownSouth/scripts.pory"
	face_down
# 199 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 199 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 244 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_16:
# 244 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 244 "data/maps/IkiTownSouth/scripts.pory"
	face_up
	step_end

# 395 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_StartRivalBattle_Movement_0:
# 395 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_right
# 395 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_right
	step_end

# 422 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_StartRivalBattle_Movement_1:
# 422 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 422 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 422 "data/maps/IkiTownSouth/scripts.pory"
	walk_up
# 422 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 422 "data/maps/IkiTownSouth/scripts.pory"
	face_down
# 422 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 422 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
	step_end

# 424 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_StartRivalBattle_Movement_2:
# 424 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_down
# 424 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_down
	step_end

# 438 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_BottomGetStarters_Movement_0:
# 438 "data/maps/IkiTownSouth/scripts.pory"
	walk_up
# 438 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 444 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_TopGetStarters_Movement_0:
# 444 "data/maps/IkiTownSouth/scripts.pory"
	walk_down
# 444 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 471 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_0:
# 471 "data/maps/IkiTownSouth/scripts.pory"
	face_right
# 471 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
	step_end

# 472 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_1:
# 472 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 477 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_2:
# 477 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
	step_end

# 487 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_left_Movement_0:
# 487 "data/maps/IkiTownSouth/scripts.pory"
	face_right
	step_end

# 492 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_left_Movement_1:
# 492 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
	step_end

IkiTown_Trigger_HauGetStarter_Text_0:
# 67 "data/maps/IkiTownSouth/scripts.pory"
	.string "???$"

IkiTown_Trigger_HauGetStarter_Text_1:
# 68 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hey, hey!\p"
	.string "Which Pokémon are you gonna choose as\n"
	.string "your partner? {PAUSE 30} Have you decided?$"

IkiTown_Trigger_HauGetStarter_Text_2:
# 72 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hau$"

IkiTown_Trigger_HauGetStarter_Text_3:
# 76 "data/maps/IkiTownSouth/scripts.pory"
	.string "Oh yeah! I'm Hau!\p"
	.string "I couldn't wait for us to pick our\n"
	.string "partners together, so I came to find\l"
	.string "you myself!$"

IkiTown_Trigger_HauGetStarter_Text_4:
# 82 "data/maps/IkiTownSouth/scripts.pory"
	.string "I chose {STR_VAR_1}!$"

IkiTown_Trigger_HauGetStarter_Text_5:
# 82 "data/maps/IkiTownSouth/scripts.pory"
	.string "You're too late.$"

IkiTown_Trigger_HauGetStarter_Text_6:
# 86 "data/maps/IkiTownSouth/scripts.pory"
	.string "Whoa! {STR_VAR_1} is so cool!\p"
	.string "Hey wait!\n"
	.string "You already picked your Pokémon?!$"

IkiTown_Trigger_HauGetStarter_Text_7:
# 94 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hey wait!\n"
	.string "You already picked your Pokémon?!$"

IkiTown_Trigger_HauGetStarter_Text_8:
# 101 "data/maps/IkiTownSouth/scripts.pory"
	.string "Kukui$"

IkiTown_Trigger_HauGetStarter_Text_9:
# 104 "data/maps/IkiTownSouth/scripts.pory"
	.string "Sorry about that, Hau.\p"
	.string "We had a little accident on the way\n"
	.string "here, so I ended up letting {PLAYER}\l"
	.string "choose his partner first without you.$"

IkiTown_Trigger_HauGetStarter_Text_10:
# 111 "data/maps/IkiTownSouth/scripts.pory"
	.string "Sorry about that, Hau.\p"
	.string "We had a little accident on the way\n"
	.string "here, so I ended up letting {PLAYER}\l"
	.string "choose her partner first without you.$"

IkiTown_Trigger_HauGetStarter_Text_11:
# 120 "data/maps/IkiTownSouth/scripts.pory"
	.string "Fair enough.\p"
	.string "I guess it was just fate for you guys\n"
	.string "to meet!$"

IkiTown_Trigger_HauGetStarter_Text_12:
# 127 "data/maps/IkiTownSouth/scripts.pory"
	.string "But you can choose one of the\n"
	.string "remaining two, Hau!$"

IkiTown_Trigger_HauGetStarter_Text_13:
# 137 "data/maps/IkiTownSouth/scripts.pory"
	.string "Mrawr!$"

IkiTown_Trigger_HauGetStarter_Text_14:
# 142 "data/maps/IkiTownSouth/scripts.pory"
	.string "Bwark!$"

IkiTown_Trigger_HauGetStarter_Text_15:
# 145 "data/maps/IkiTownSouth/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Popplio! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_16:
# 157 "data/maps/IkiTownSouth/scripts.pory"
	.string "Alola, friend!\p"
	.string "I decided ages ago that you're the\n"
	.string "one I wanted to have an adventure\l"
	.string "with!\p"
	.string "We're gonna do so much awesome stuff\n"
	.string "together!\p"
	.string "Just you wait and see!$"

IkiTown_Trigger_HauGetStarter_Text_17:
# 173 "data/maps/IkiTownSouth/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Litten, right?$"

IkiTown_Trigger_HauGetStarter_Text_18:
# 181 "data/maps/IkiTownSouth/scripts.pory"
	.string "You better believe I will, Hau!$"

IkiTown_Trigger_HauGetStarter_Text_19:
# 184 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right then. Litten! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_20:
# 190 "data/maps/IkiTownSouth/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Popplio have a favor to ask.$"

IkiTown_Trigger_HauGetStarter_Text_21:
# 198 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hoo!$"

IkiTown_Trigger_HauGetStarter_Text_22:
# 208 "data/maps/IkiTownSouth/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Rowlet! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_23:
# 235 "data/maps/IkiTownSouth/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Popplio, right?$"

IkiTown_Trigger_HauGetStarter_Text_24:
# 246 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right then. Popplio! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_25:
# 252 "data/maps/IkiTownSouth/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Rowlet have a favor to ask.$"

IkiTown_Trigger_HauGetStarter_Text_26:
# 271 "data/maps/IkiTownSouth/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Litten! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_27:
# 298 "data/maps/IkiTownSouth/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Rowlet, right?$"

IkiTown_Trigger_HauGetStarter_Text_28:
# 309 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right then. Rowlet! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_29:
# 315 "data/maps/IkiTownSouth/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Litten have a favor to ask.$"

Ikitown_RivalBattleYesNo_Text_0:
# 327 "data/maps/IkiTownSouth/scripts.pory"
	.string "Be our opponents in our first ever\n"
	.string "Pokémon battle together!$"

RivalBattleNo_Text_0:
# 339 "data/maps/IkiTownSouth/scripts.pory"
	.string "Come on, don't be like that!\n"
	.string "It'll be fun!$"

IkiTown_StartRivalBattle_Text_0:
# 348 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hold on!\p"
	.string "Before you two step into the ring,\n"
	.string "let's make sure little {STR_VAR_1} is up\l"
	.string "to it!$"

IkiTown_StartRivalBattle_Text_1:
# 359 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right, I'm surely going to enjoy\n"
	.string "this!$"

IkiTown_StartRivalBattle_Text_2:
# 364 "data/maps/IkiTownSouth/scripts.pory"
	.string "Our first defeat! Sorry, Popplio!$"

IkiTown_StartRivalBattle_Text_3:
# 364 "data/maps/IkiTownSouth/scripts.pory"
	.string "Alola! Way to go, Popplio!$"

IkiTown_StartRivalBattle_Text_4:
# 372 "data/maps/IkiTownSouth/scripts.pory"
	.string "Our first defeat! Sorry, Rowlet!$"

IkiTown_StartRivalBattle_Text_5:
# 372 "data/maps/IkiTownSouth/scripts.pory"
	.string "Alola! Way to go, Rowlet!$"

IkiTown_StartRivalBattle_Text_6:
# 380 "data/maps/IkiTownSouth/scripts.pory"
	.string "Our first defeat! Sorry, Litten!$"

IkiTown_StartRivalBattle_Text_7:
# 380 "data/maps/IkiTownSouth/scripts.pory"
	.string "Alola! Way to go, Litten!$"

IkiTown_StartRivalBattle_Text_8:
# 401 "data/maps/IkiTownSouth/scripts.pory"
	.string "Whoa! That was awesome, {PLAYER}!\p"
	.string "You and {STR_VAR_1} were both so\n"
	.string "cool!\p"
	.string "You've gotta have the kinda battles\n"
	.string "where everyone has fun.\p"
	.string "You and your partner Pokémon, too,\n"
	.string "you know?$"

IkiTown_StartRivalBattle_Text_9:
# 414 "data/maps/IkiTownSouth/scripts.pory"
	.string "Right on {PLAYER}!\p"
	.string "You and Hau both brought out the\n"
	.string "best in your partners and pulled\l"
	.string "off some spectacular moves, yeah!\p"
	.string "Iki Town is right up those stairs.\n"
	.string "Come on, {PLAYER}!$"

IkiTown_StartRivalBattle_Text_10:
# 430 "data/maps/IkiTownSouth/scripts.pory"
	.string "You should totally check out Iki Town!$"

Ikitown_KukuiAfterBattle_Text_0:
# 462 "data/maps/IkiTownSouth/scripts.pory"
	.string "Iki Town is right up those stairs.\n"
	.string "Come on, {PLAYER}!$"

Ikitown_TrainerTipsSign_Text_0:
# 500 "data/maps/IkiTownSouth/scripts.pory"
	.string "Trainer Tips\p"
	.string "Pokémon can gain Exp. Points by\n"
	.string "battling other Pokémon.\p"
	.string "Exp. Points help them grow stronger.\n"
	.string "And your Pokémon will still get Exp.\l"
	.string "Points even if you catch a Pokémon\l"
	.string "you are battling against!$"

Ikitown_lassNPC_Text_0:
# 516 "data/maps/IkiTownSouth/scripts.pory"
	.string "If you happen to pick up a Potion\n"
	.string "anywhere, use it on your Pokémon\l"
	.string "when it's low on HP…\l"
	.string "and it'll be feeling better before\l"
	.string "you know it!$"
