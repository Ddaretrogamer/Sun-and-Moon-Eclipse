HauoliOutskirts_MapScripts::
# 2 "data/maps/HauoliOutskirts/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 5 "data/maps/HauoliOutskirts/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 2 "data/maps/HauoliOutskirts/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 20, HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 3 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 4 "data/maps/HauoliOutskirts/scripts.pory"
	fwdtime DAY_HOUR_BEGIN, 0
	return

HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 5 "data/maps/HauoliOutskirts/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 20, HauoliOutskirts_ExitLabEclipse
	.2byte 0


HauoliOutskirts_ExitLabEclipse::
# 10 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 11 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat kukui_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 12 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_0
# 13 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement kukui_outside_lab
# 14 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 15 "data/maps/HauoliOutskirts/scripts.pory"
	startcutscene CUTSCENE_HAUOLI_OUTSKIRTS_EXIT_LAB_ECLIPSE
# 16 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 17 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_1
# 18 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 19 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 20 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_2
# 21 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_3
# 22 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 23 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 24 "data/maps/HauoliOutskirts/scripts.pory"
	opendoor 25, 12
# 25 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 26 "data/maps/HauoliOutskirts/scripts.pory"
	showobjectat kukui_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 27 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_4
# 28 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement kukui_outside_lab
# 29 "data/maps/HauoliOutskirts/scripts.pory"
	closedoor 25, 12
# 30 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 31 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_5
# 32 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
# 33 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 34 "data/maps/HauoliOutskirts/scripts.pory"
	delay 60
# 35 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_6
# 36 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
# 37 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 38 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 39 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_1
# 41 "data/maps/HauoliOutskirts/scripts.pory"
	setweather WEATHER_SHADE
# 42 "data/maps/HauoliOutskirts/scripts.pory"
	doweather
# 43 "data/maps/HauoliOutskirts/scripts.pory"
	special WaitWeather
# 44 "data/maps/HauoliOutskirts/scripts.pory"
	fadeoutbgm 1
# 45 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_2, MSGBOX_AUTOCLOSE
# 46 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 47 "data/maps/HauoliOutskirts/scripts.pory"
	endcutscene
# 48 "data/maps/HauoliOutskirts/scripts.pory"
	openscreenshot 4, 0
# 49 "data/maps/HauoliOutskirts/scripts.pory"
	waitstate
# 50 "data/maps/HauoliOutskirts/scripts.pory"
	startcutscene CUTSCENE_HAUOLI_OUTSKIRTS_EXIT_LAB_ECLIPSE
# 51 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 52 "data/maps/HauoliOutskirts/scripts.pory"
	setweather WEATHER_NONE
# 53 "data/maps/HauoliOutskirts/scripts.pory"
	doweather
# 54 "data/maps/HauoliOutskirts/scripts.pory"
	special WaitWeather
# 55 "data/maps/HauoliOutskirts/scripts.pory"
	fadeinbgm 1
# 56 "data/maps/HauoliOutskirts/scripts.pory"
	delay 60
# 57 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 58 "data/maps/HauoliOutskirts/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 59 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_3
# 60 "data/maps/HauoliOutskirts/scripts.pory"
	waitmoncry
# 61 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 62 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 63 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_4
# 69 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_8
# 70 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 71 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_5
# 72 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_6
# 76 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_5
# 77 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
# 78 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 79 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 80 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_7
# 82 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_9
# 83 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_LEDGE
# 84 "data/maps/HauoliOutskirts/scripts.pory"
	waitse
# 85 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_LEDGE
# 86 "data/maps/HauoliOutskirts/scripts.pory"
	waitse
# 87 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 88 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_5
# 89 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_8, MSGBOX_AUTOCLOSE
# 100 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_9
# 101 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_LEDGE
# 102 "data/maps/HauoliOutskirts/scripts.pory"
	waitse
# 103 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_LEDGE
# 104 "data/maps/HauoliOutskirts/scripts.pory"
	waitse
# 105 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 106 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_5
# 107 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_9, MSGBOX_AUTOCLOSE
# 115 "data/maps/HauoliOutskirts/scripts.pory"
	checkplayergender
# 116 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq HauoliOutskirts_ExitLabEclipse_2
# 129 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 130 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_12
# 132 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_6
# 133 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
# 134 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 135 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_11, MSGBOX_AUTOCLOSE
HauoliOutskirts_ExitLabEclipse_1:
# 138 "data/maps/HauoliOutskirts/scripts.pory"
	endcutscene
# 139 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 140 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 141 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 142 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_10
# 143 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement kukui_outside_lab
# 144 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat kukui_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 145 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 146 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 147 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_IKITOWN_STATE, 21
# 148 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOutskirts_ExitLabEclipse_2:
# 118 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 119 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_10
# 121 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_6
# 122 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
# 123 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 124 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_11, MSGBOX_AUTOCLOSE
	goto HauoliOutskirts_ExitLabEclipse_1


HauoliOutskirts_ExitLabEclipseSkip::
# 154 "data/maps/HauoliOutskirts/scripts.pory"
	closemessage
# 155 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 156 "data/maps/HauoliOutskirts/scripts.pory"
	setweather WEATHER_NONE
# 157 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 158 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 159 "data/maps/HauoliOutskirts/scripts.pory"
	setobjectxy kukui_outside_lab, 25, 10
# 160 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat kukui_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 161 "data/maps/HauoliOutskirts/scripts.pory"
	special StopAllObjectMovements
# 162 "data/maps/HauoliOutskirts/scripts.pory"
	special CloseScriptMenus
# 163 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_IKITOWN_STATE, 21
# 164 "data/maps/HauoliOutskirts/scripts.pory"
	doweather
# 165 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 166 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 167 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirts_LillieOutsideLab::
# 177 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 178 "data/maps/HauoliOutskirts/scripts.pory"
	startcutscene CUTSCENE_HAUOLI_OUTSKIRTS_LILLIE_OUTSIDE_LAB
# 179 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 180 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 181 "data/maps/HauoliOutskirts/scripts.pory"
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
# 182 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 183 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_0, MSGBOX_AUTOCLOSE
# 198 "data/maps/HauoliOutskirts/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 199 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_1
# 200 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 201 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_1, MSGBOX_AUTOCLOSE
# 202 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 203 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 204 "data/maps/HauoliOutskirts/scripts.pory"
	waitmessage
# 205 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 206 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_2, MSGBOX_AUTOCLOSE
# 225 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8004, 1
# 226 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8005, 1
# 227 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8006, 8
# 228 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8007, 5
# 229 "data/maps/HauoliOutskirts/scripts.pory"
	special ShakeCamera
# 230 "data/maps/HauoliOutskirts/scripts.pory"
	waitstate
# 231 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 232 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_2
# 233 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_2
# 234 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 235 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_5
# 236 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_3, MSGBOX_AUTOCLOSE
# 239 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 240 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 24
	goto_if_eq HauoliOutskirts_LillieOutsideLab_3
HauoliOutskirts_LillieOutsideLab_1:
# 243 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 25
	goto_if_eq HauoliOutskirts_LillieOutsideLab_9
HauoliOutskirts_LillieOutsideLab_8:
# 247 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
HauoliOutskirts_LillieOutsideLab_6:
# 249 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 250 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 251 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_4, MSGBOX_AUTOCLOSE
# 267 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8004, 1
# 268 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8005, 1
# 269 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8006, 8
# 270 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8007, 5
# 271 "data/maps/HauoliOutskirts/scripts.pory"
	special ShakeCamera
# 272 "data/maps/HauoliOutskirts/scripts.pory"
	waitstate
# 273 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 274 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_2
# 275 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_2
# 276 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 277 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 278 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_5, MSGBOX_AUTOCLOSE
# 279 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 280 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 281 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 24
	goto_if_eq HauoliOutskirts_LillieOutsideLab_14
HauoliOutskirts_LillieOutsideLab_12:
# 284 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 25
	goto_if_eq HauoliOutskirts_LillieOutsideLab_20
HauoliOutskirts_LillieOutsideLab_19:
# 288 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
HauoliOutskirts_LillieOutsideLab_17:
# 290 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 291 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 292 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_6, MSGBOX_AUTOCLOSE
# 309 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_3
# 310 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 311 "data/maps/HauoliOutskirts/scripts.pory"
	opendoor 25, 12
# 312 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 313 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_4
# 314 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 315 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat lillie_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 316 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 317 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 318 "data/maps/HauoliOutskirts/scripts.pory"
	closedoor 25, 12
# 319 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 320 "data/maps/HauoliOutskirts/scripts.pory"
	endcutscene
# 321 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOutskirts_LillieOutsideLab_2:
# 241 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_6
	goto HauoliOutskirts_LillieOutsideLab_1

HauoliOutskirts_LillieOutsideLab_3:
# 240 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 15
	goto_if_eq HauoliOutskirts_LillieOutsideLab_2
	goto HauoliOutskirts_LillieOutsideLab_1

HauoliOutskirts_LillieOutsideLab_7:
# 244 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
	goto HauoliOutskirts_LillieOutsideLab_6

HauoliOutskirts_LillieOutsideLab_9:
# 243 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 16
	goto_if_eq HauoliOutskirts_LillieOutsideLab_7
	goto HauoliOutskirts_LillieOutsideLab_8

HauoliOutskirts_LillieOutsideLab_13:
# 282 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_6
	goto HauoliOutskirts_LillieOutsideLab_12

HauoliOutskirts_LillieOutsideLab_14:
# 281 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 15
	goto_if_eq HauoliOutskirts_LillieOutsideLab_13
	goto HauoliOutskirts_LillieOutsideLab_12

HauoliOutskirts_LillieOutsideLab_18:
# 285 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
	goto HauoliOutskirts_LillieOutsideLab_17

HauoliOutskirts_LillieOutsideLab_20:
# 284 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 16
	goto_if_eq HauoliOutskirts_LillieOutsideLab_18
	goto HauoliOutskirts_LillieOutsideLab_19


HauoliOutskirts_LillieOutsideLabSkip::
# 326 "data/maps/HauoliOutskirts/scripts.pory"
	closemessage
# 327 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 328 "data/maps/HauoliOutskirts/scripts.pory"
	special StopAllObjectMovements
# 329 "data/maps/HauoliOutskirts/scripts.pory"
	special CloseScriptMenus
# 330 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 331 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 332 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 333 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


LabSign::
# 338 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 339 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox LabSign_Text_0
# 340 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


OutsideTenCarrotHill::
# 345 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 346 "data/maps/HauoliOutskirts/scripts.pory"
	faceplayer
# 347 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox OutsideTenCarrotHill_Text_0
# 348 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


TenCarrotHillSign::
# 352 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 353 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox TenCarrotHillSign_Text_0
# 354 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirtLittleGirlNPC::
# 358 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 359 "data/maps/HauoliOutskirts/scripts.pory"
	faceplayer
# 360 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirtLittleGirlNPC_Text_0
# 361 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOustkirtsTrainerTipsSign::
# 366 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 367 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsTrainerTipsSign_Text_0
# 368 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirtLassNPC::
# 373 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirtLassNPC_Text_0, MSGBOX_NPC
	end


HauoliOustkirtsFishingSpot1::
# 378 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 379 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_SURF_MON_SLOT, 0
	goto_if_eq HauoliOustkirtsFishingSpot1_2
# 400 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_2
HauoliOustkirtsFishingSpot1_1:
# 402 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOustkirtsFishingSpot1_2:
# 381 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_0, MSGBOX_YESNO
# 382 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HauoliOustkirtsFishingSpot1_5
# 394 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOustkirtsFishingSpot1_5:
# 384 "data/maps/HauoliOutskirts/scripts.pory"
	checkitem ITEM_SUPER_ROD
# 385 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HauoliOustkirtsFishingSpot1_8
# 390 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_1
	goto HauoliOustkirtsFishingSpot1_1

HauoliOustkirtsFishingSpot1_8:
# 387 "data/maps/HauoliOutskirts/scripts.pory"
	startfishing
	goto HauoliOustkirtsFishingSpot1_1


# 12 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_0:
# 12 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
# 12 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
	step_end

# 17 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_1:
# 17 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
# 17 "data/maps/HauoliOutskirts/scripts.pory"
	emote_exclamation_mark
	step_end

# 20 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_2:
# 20 "data/maps/HauoliOutskirts/scripts.pory"
	delay_8
# 20 "data/maps/HauoliOutskirts/scripts.pory"
	walk_left
# 20 "data/maps/HauoliOutskirts/scripts.pory"
	face_right
	step_end

# 21 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_3:
# 21 "data/maps/HauoliOutskirts/scripts.pory"
	delay_16
# 21 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
# 21 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
# 21 "data/maps/HauoliOutskirts/scripts.pory"
	face_left
	step_end

# 27 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_4:
# 27 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
	step_end

# 31 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_5:
# 31 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
	step_end

# 35 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_6:
# 35 "data/maps/HauoliOutskirts/scripts.pory"
	face_right
	step_end

# 36 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_7:
# 36 "data/maps/HauoliOutskirts/scripts.pory"
	face_left
	step_end

# 69 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_8:
# 69 "data/maps/HauoliOutskirts/scripts.pory"
	walk_in_place_down
# 69 "data/maps/HauoliOutskirts/scripts.pory"
	walk_in_place_down
	step_end

# 82 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_9:
# 82 "data/maps/HauoliOutskirts/scripts.pory"
	jump_in_place_down
# 82 "data/maps/HauoliOutskirts/scripts.pory"
	jump_in_place_down
	step_end

# 142 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_10:
# 142 "data/maps/HauoliOutskirts/scripts.pory"
	walk_faster_up
# 142 "data/maps/HauoliOutskirts/scripts.pory"
	walk_faster_up
# 142 "data/maps/HauoliOutskirts/scripts.pory"
	walk_faster_up
	step_end

# 179 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_0:
# 179 "data/maps/HauoliOutskirts/scripts.pory"
	face_player
	step_end

# 199 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_1:
# 199 "data/maps/HauoliOutskirts/scripts.pory"
	shake_horizontal
	step_end

# 232 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_2:
# 232 "data/maps/HauoliOutskirts/scripts.pory"
	emote_exclamation_mark
# 232 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
	step_end

# 309 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_3:
# 309 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
# 309 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
	step_end

# 313 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_4:
# 313 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
	step_end

HauoliOutskirts_ExitLabEclipse_Text_0:
# 38 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Lillie$"

HauoliOutskirts_ExitLabEclipse_Text_1:
# 39 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The Pokémon Center is practically right\n"
	.string "next to your house, isn't it?$"

HauoliOutskirts_ExitLabEclipse_Text_2:
# 45 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Ah…$"

HauoliOutskirts_ExitLabEclipse_Text_3:
# 59 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pew…$"

HauoliOutskirts_ExitLabEclipse_Text_4:
# 63 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Nebby…\n"
	.string "{PAUSE_UNTIL_PRESS}Don't worry-it's OK.\p"
	.string "This must be what they call a solar\n"
	.string "eclipse. It happens when the sun\l"
	.string "gets covered up.$"

HauoliOutskirts_ExitLabEclipse_Text_5:
# 71 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Kukui$"

HauoliOutskirts_ExitLabEclipse_Text_6:
# 72 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Was a solar eclipse forcast for today?\p"
	.string "Ah, well. It must be some kind of\n"
	.string "good omen, yeah!$"

HauoliOutskirts_ExitLabEclipse_Text_7:
# 80 "data/maps/HauoliOutskirts/scripts.pory"
	.string "An omen?\n"
	.string "You think something good will happen?$"

HauoliOutskirts_ExitLabEclipse_Text_8:
# 89 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Sure! A long, long time ago, Alola was\n"
	.string "cloaked in darkness, yeah…\p"
	.string "But people say that's when Alola's\n"
	.string "people and Pokémon blasted all that\l"
	.string "darkness away with light!\p"
	.string "And they also say that was why people\n"
	.string "started gathering Z-Crystals, and\l"
	.string "that custom turned into the island\l"
	.string "challenge.$"

HauoliOutskirts_ExitLabEclipse_Text_9:
# 107 "data/maps/HauoliOutskirts/scripts.pory"
	.string "{PLAYER}!\p"
	.string "Now that you've got that Z-Power Ring,\n"
	.string "I hope you'll collect tons of\l"
	.string "Z-Crystals! Woo!\p"
	.string "That's exactly what a move researcher\n"
	.string "like me needs to uncover new secrets!$"

HauoliOutskirts_ExitLabEclipse_Text_10:
# 119 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Professor, that's not why he's supposed\n"
	.string "to be doing it…$"

HauoliOutskirts_ExitLabEclipse_Text_11:
# 124 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Come on, {PLAYER}.\n"
	.string "I'll show you to the Pokémon Center.$"

HauoliOutskirts_ExitLabEclipse_Text_12:
# 130 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Professor, that's not why she's\n"
	.string "supposed to be doing it…$"

HauoliOutskirts_LillieOutsideLab_Text_0:
# 183 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Hey {PLAYER}.\n"
	.string "You made it.\p"
	.string "Since I'm not a Trainer, I have to rely\n"
	.string "on using Repels all the time.\p"
	.string "You do know that using a Repel keeps\n"
	.string "Pokémon from attacking, right?\p"
	.string "A-and about Nebby…\p"
	.string "Oh. I mean…Cosmog.\p"
	.string "Cosmog seems to be a very rare Pokémon.\n"
	.string "It came from far, far away.$"

HauoliOutskirts_LillieOutsideLab_Text_1:
# 201 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pew!$"

HauoliOutskirts_LillieOutsideLab_Text_2:
# 206 "data/maps/HauoliOutskirts/scripts.pory"
	.string "It seems to have a very strange power…\p"
	.string "It used that power to save me once\n"
	.string "when I was in danger.\p"
	.string "But some…other people want Cosmog for\n"
	.string "themselves, to use that power.\p"
	.string "That's why only the professor and\n"
	.string "Kahuna Hala and other people I can\l"
	.string "trust know about it…\p"
	.string "Can you keep a secret?\p"
	.string "Can you not tell anyone else about\n"
	.string "Nebby or what happened on that\l"
	.string "Bridge?\p"
	.string "Please…$"

HauoliOutskirts_LillieOutsideLab_Text_3:
# 236 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Oh yeah, Rockruff! Lets go!\n"
	.string "Give it everything you've got!\l"
	.string "My body is ready. Woo!$"

HauoliOutskirts_LillieOutsideLab_Text_4:
# 251 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Ah…\n"
	.string "There they go again…\p"
	.string "The Pokémon Research Lab has its own\n"
	.string "unique charm, as you might agree.\p"
	.string "I've actually been, um, imposing on\n"
	.string "the professor here for the last few\l"
	.string "months.\p"
	.string "I'm not much of an assistant, but it's\n"
	.string "the least I can do to pay him back\l"
	.string "for letting me stay.\p"
	.string "Maybe I'd be more help if I were a real\n"
	.string "Pokémon Trainer, too.$"

HauoliOutskirts_LillieOutsideLab_Text_5:
# 278 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Raaaa-oooooohhh! Raff ruff!$"

HauoliOutskirts_LillieOutsideLab_Text_6:
# 292 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The professor…\p"
	.string "He never stops researching moves.\n"
	.string "Not even…{PAUSE 30}inside the lab itself.\p"
	.string "Looks like we'll have to patch up\n"
	.string "the roof again…  \p"
	.string "And I had just washed his lab coat\n"
	.string "and finally gotten it clean, too.\l"
	.string "Now it'll be in shreds…\l"
	.string "and I'm no good at mending clothes…\p"
	.string "He'll just have to buy another new one…\p"
	.string "We should probably go in before he does\n"
	.string "any more damage…$"

LabSign_Text_0:
# 339 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pokémon Research Lab$"

OutsideTenCarrotHill_Text_0:
# 347 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Wa ha ha!\n"
	.string "You're a strong Trainer, all right!\l"
	.string "Go on! You take on Ten Carrot Hill,\l"
	.string "friend!\p"
	.string "Even stronger Pokémon await you\n"
	.string "within!$"

TenCarrotHillSign_Text_0:
# 353 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Ten Carrot Hill$"

HauoliOutskirtLittleGirlNPC_Text_0:
# 360 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The Pokémon I've got with me are all\n"
	.string "Grass-type.\p"
	.string "I'm looking for Water-type Pokémon\l"
	.string "for my team so I can beat Fire types,\l"
	.string "too.$"

HauoliOustkirtsTrainerTipsSign_Text_0:
# 367 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Trainer Tips\p"
	.string "The Pokémon that will appear first in\n"
	.string "battle will be the one you've put in\l"
	.string "the left position in your Pokémon\l"
	.string "party.$"

HauoliOutskirtLassNPC_Text_0:
# 373 "data/maps/HauoliOutskirts/scripts.pory"
	.string "If you see a Pokémon Trainer, you've\ngotta show off the Pokémon you like!$"

HauoliOustkirtsFishingSpot1_Text_0:
# 381 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Would you like to fish here?$"

HauoliOustkirtsFishingSpot1_Text_1:
# 390 "data/maps/HauoliOutskirts/scripts.pory"
	.string "You don't have a Fishing Rod.$"

HauoliOustkirtsFishingSpot1_Text_2:
# 400 "data/maps/HauoliOutskirts/scripts.pory"
	.string "You can't fish while riding a Sharpedo!$"
