HauoliOutskirts_MapScripts::
# 2 "data/maps/HauoliOutskirts/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 3 "data/maps/HauoliOutskirts/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 2 "data/maps/HauoliOutskirts/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 20, HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 2 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/HauoliOutskirts/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 20, HauoliOutskirts_ExitLabEclipse
	.2byte 0


HauoliOutskirts_ExitLabEclipse::
# 8 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 9 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat kukui_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 10 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_0
# 11 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement kukui_outside_lab
# 12 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 13 "data/maps/HauoliOutskirts/scripts.pory"
	startcutscene CUTSCENE_HAUOLI_OUTSKIRTS_EXIT_LAB_ECLIPSE
# 14 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 15 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_1
# 16 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 17 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 18 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_2
# 19 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_3
# 20 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 21 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 22 "data/maps/HauoliOutskirts/scripts.pory"
	opendoor 25, 12
# 23 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 24 "data/maps/HauoliOutskirts/scripts.pory"
	showobjectat kukui_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 25 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_4
# 26 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement kukui_outside_lab
# 27 "data/maps/HauoliOutskirts/scripts.pory"
	closedoor 25, 12
# 28 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 29 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_5
# 30 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
# 31 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 32 "data/maps/HauoliOutskirts/scripts.pory"
	delay 60
# 33 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_6
# 34 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
# 35 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 36 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 37 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_1
# 39 "data/maps/HauoliOutskirts/scripts.pory"
	setweather WEATHER_SHADE
# 40 "data/maps/HauoliOutskirts/scripts.pory"
	doweather
# 41 "data/maps/HauoliOutskirts/scripts.pory"
	special WaitWeather
# 42 "data/maps/HauoliOutskirts/scripts.pory"
	fadeoutbgm 1
# 43 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_2, MSGBOX_AUTOCLOSE
# 44 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 45 "data/maps/HauoliOutskirts/scripts.pory"
	endcutscene
# 46 "data/maps/HauoliOutskirts/scripts.pory"
	gettimeofday
# 47 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq HauoliOutskirts_ExitLabEclipse_2
# 47 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq HauoliOutskirts_ExitLabEclipse_2
# 51 "data/maps/HauoliOutskirts/scripts.pory"
	openscreenshot 5, 0
HauoliOutskirts_ExitLabEclipse_1:
# 53 "data/maps/HauoliOutskirts/scripts.pory"
	startcutscene CUTSCENE_HAUOLI_OUTSKIRTS_EXIT_LAB_ECLIPSE
# 54 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 55 "data/maps/HauoliOutskirts/scripts.pory"
	setweather WEATHER_NONE
# 56 "data/maps/HauoliOutskirts/scripts.pory"
	doweather
# 57 "data/maps/HauoliOutskirts/scripts.pory"
	special WaitWeather
# 58 "data/maps/HauoliOutskirts/scripts.pory"
	fadeinbgm 1
# 59 "data/maps/HauoliOutskirts/scripts.pory"
	delay 60
# 60 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 61 "data/maps/HauoliOutskirts/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 62 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_3
# 63 "data/maps/HauoliOutskirts/scripts.pory"
	waitmoncry
# 64 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 65 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 66 "data/maps/HauoliOutskirts/scripts.pory"
	gettimeofday
# 67 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq HauoliOutskirts_ExitLabEclipse_8
# 67 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq HauoliOutskirts_ExitLabEclipse_8
# 83 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_7
# 89 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_8
# 90 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 91 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_5
# 92 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_8
HauoliOutskirts_ExitLabEclipse_7:
# 97 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_5
# 98 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
# 99 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 100 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 101 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_9
# 103 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_9
# 104 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_LEDGE
# 105 "data/maps/HauoliOutskirts/scripts.pory"
	waitse
# 106 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_LEDGE
# 107 "data/maps/HauoliOutskirts/scripts.pory"
	waitse
# 108 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 109 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_5
# 110 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_10, MSGBOX_AUTOCLOSE
# 121 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_9
# 122 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_LEDGE
# 123 "data/maps/HauoliOutskirts/scripts.pory"
	waitse
# 124 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_LEDGE
# 125 "data/maps/HauoliOutskirts/scripts.pory"
	waitse
# 126 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 127 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_5
# 128 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_11
# 136 "data/maps/HauoliOutskirts/scripts.pory"
	checkplayergender
# 137 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq HauoliOutskirts_ExitLabEclipse_14
# 150 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 151 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_14
# 153 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_6
# 154 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
# 155 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 156 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_13, MSGBOX_AUTOCLOSE
HauoliOutskirts_ExitLabEclipse_13:
# 159 "data/maps/HauoliOutskirts/scripts.pory"
	endcutscene
# 160 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 161 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 162 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 163 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_10
# 164 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement kukui_outside_lab
# 165 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat kukui_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 166 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 167 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 168 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_IKITOWN_STATE, 21
# 169 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOutskirts_ExitLabEclipse_2:
# 48 "data/maps/HauoliOutskirts/scripts.pory"
	openscreenshot 4, 0
	goto HauoliOutskirts_ExitLabEclipse_1

HauoliOutskirts_ExitLabEclipse_8:
# 68 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_4
# 74 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_8
# 75 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 76 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_5
# 77 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_6
	goto HauoliOutskirts_ExitLabEclipse_7

HauoliOutskirts_ExitLabEclipse_14:
# 139 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 140 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_12
# 142 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_6
# 143 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
# 144 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 145 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_13, MSGBOX_AUTOCLOSE
	goto HauoliOutskirts_ExitLabEclipse_13


HauoliOutskirts_ExitLabEclipseSkip::
# 175 "data/maps/HauoliOutskirts/scripts.pory"
	closemessage
# 176 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 177 "data/maps/HauoliOutskirts/scripts.pory"
	setweather WEATHER_NONE
# 178 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 179 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 180 "data/maps/HauoliOutskirts/scripts.pory"
	setobjectxy kukui_outside_lab, 25, 10
# 181 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat kukui_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 182 "data/maps/HauoliOutskirts/scripts.pory"
	special StopAllObjectMovements
# 183 "data/maps/HauoliOutskirts/scripts.pory"
	special CloseScriptMenus
# 184 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_IKITOWN_STATE, 21
# 185 "data/maps/HauoliOutskirts/scripts.pory"
	doweather
# 186 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 187 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 188 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirts_LillieOutsideLab::
# 198 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 199 "data/maps/HauoliOutskirts/scripts.pory"
	startcutscene CUTSCENE_HAUOLI_OUTSKIRTS_LILLIE_OUTSIDE_LAB
# 200 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 201 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 202 "data/maps/HauoliOutskirts/scripts.pory"
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
# 203 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 204 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_0, MSGBOX_AUTOCLOSE
# 219 "data/maps/HauoliOutskirts/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 220 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_1
# 221 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 222 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_1, MSGBOX_AUTOCLOSE
# 223 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 224 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 225 "data/maps/HauoliOutskirts/scripts.pory"
	waitmessage
# 226 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 227 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_2, MSGBOX_AUTOCLOSE
# 246 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8004, 1
# 247 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8005, 1
# 248 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8006, 8
# 249 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8007, 5
# 250 "data/maps/HauoliOutskirts/scripts.pory"
	special ShakeCamera
# 251 "data/maps/HauoliOutskirts/scripts.pory"
	waitstate
# 252 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 253 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_2
# 254 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_2
# 255 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 256 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_5
# 257 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_3, MSGBOX_AUTOCLOSE
# 260 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 261 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 24
	goto_if_eq HauoliOutskirts_LillieOutsideLab_3
HauoliOutskirts_LillieOutsideLab_1:
# 264 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 25
	goto_if_eq HauoliOutskirts_LillieOutsideLab_9
HauoliOutskirts_LillieOutsideLab_8:
# 268 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
HauoliOutskirts_LillieOutsideLab_6:
# 270 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 271 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 272 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_4, MSGBOX_AUTOCLOSE
# 288 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8004, 1
# 289 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8005, 1
# 290 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8006, 8
# 291 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8007, 5
# 292 "data/maps/HauoliOutskirts/scripts.pory"
	special ShakeCamera
# 293 "data/maps/HauoliOutskirts/scripts.pory"
	waitstate
# 294 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 295 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_2
# 296 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_2
# 297 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 298 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 299 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_5, MSGBOX_AUTOCLOSE
# 300 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 301 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 302 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 24
	goto_if_eq HauoliOutskirts_LillieOutsideLab_14
HauoliOutskirts_LillieOutsideLab_12:
# 305 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 25
	goto_if_eq HauoliOutskirts_LillieOutsideLab_20
HauoliOutskirts_LillieOutsideLab_19:
# 309 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
HauoliOutskirts_LillieOutsideLab_17:
# 311 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 312 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 313 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_6, MSGBOX_AUTOCLOSE
# 330 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_3
# 331 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 332 "data/maps/HauoliOutskirts/scripts.pory"
	opendoor 25, 12
# 333 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 334 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_4
# 335 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 336 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat lillie_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 337 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 338 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 339 "data/maps/HauoliOutskirts/scripts.pory"
	closedoor 25, 12
# 340 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 341 "data/maps/HauoliOutskirts/scripts.pory"
	endcutscene
# 342 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOutskirts_LillieOutsideLab_2:
# 262 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_6
	goto HauoliOutskirts_LillieOutsideLab_1

HauoliOutskirts_LillieOutsideLab_3:
# 261 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 15
	goto_if_eq HauoliOutskirts_LillieOutsideLab_2
	goto HauoliOutskirts_LillieOutsideLab_1

HauoliOutskirts_LillieOutsideLab_7:
# 265 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
	goto HauoliOutskirts_LillieOutsideLab_6

HauoliOutskirts_LillieOutsideLab_9:
# 264 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 16
	goto_if_eq HauoliOutskirts_LillieOutsideLab_7
	goto HauoliOutskirts_LillieOutsideLab_8

HauoliOutskirts_LillieOutsideLab_13:
# 303 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_6
	goto HauoliOutskirts_LillieOutsideLab_12

HauoliOutskirts_LillieOutsideLab_14:
# 302 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 15
	goto_if_eq HauoliOutskirts_LillieOutsideLab_13
	goto HauoliOutskirts_LillieOutsideLab_12

HauoliOutskirts_LillieOutsideLab_18:
# 306 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
	goto HauoliOutskirts_LillieOutsideLab_17

HauoliOutskirts_LillieOutsideLab_20:
# 305 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 16
	goto_if_eq HauoliOutskirts_LillieOutsideLab_18
	goto HauoliOutskirts_LillieOutsideLab_19


HauoliOutskirts_LillieOutsideLabSkip::
# 347 "data/maps/HauoliOutskirts/scripts.pory"
	closemessage
# 348 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 349 "data/maps/HauoliOutskirts/scripts.pory"
	special StopAllObjectMovements
# 350 "data/maps/HauoliOutskirts/scripts.pory"
	special CloseScriptMenus
# 351 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 352 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 353 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 354 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


LabSign::
# 359 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 360 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox LabSign_Text_0
# 361 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


OutsideTenCarrotHill::
# 366 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 367 "data/maps/HauoliOutskirts/scripts.pory"
	faceplayer
# 368 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox OutsideTenCarrotHill_Text_0
# 369 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


TenCarrotHillSign::
# 373 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 374 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox TenCarrotHillSign_Text_0
# 375 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirtLittleGirlNPC::
# 379 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 380 "data/maps/HauoliOutskirts/scripts.pory"
	faceplayer
# 381 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirtLittleGirlNPC_Text_0
# 382 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOustkirtsTrainerTipsSign::
# 387 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 388 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsTrainerTipsSign_Text_0
# 389 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirtLassNPC::
# 394 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirtLassNPC_Text_0, MSGBOX_NPC
	end


HauoliOustkirtsFishingSpot1::
# 399 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 400 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_SURF_MON_SLOT, 0
	goto_if_eq HauoliOustkirtsFishingSpot1_2
# 421 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_2
HauoliOustkirtsFishingSpot1_1:
# 423 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOustkirtsFishingSpot1_2:
# 402 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_0, MSGBOX_YESNO
# 403 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HauoliOustkirtsFishingSpot1_5
# 415 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOustkirtsFishingSpot1_5:
# 405 "data/maps/HauoliOutskirts/scripts.pory"
	checkitem ITEM_SUPER_ROD
# 406 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HauoliOustkirtsFishingSpot1_8
# 411 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_1
	goto HauoliOustkirtsFishingSpot1_1

HauoliOustkirtsFishingSpot1_8:
# 408 "data/maps/HauoliOutskirts/scripts.pory"
	startfishing
	goto HauoliOustkirtsFishingSpot1_1


# 10 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_0:
# 10 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
# 10 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
	step_end

# 15 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_1:
# 15 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
# 15 "data/maps/HauoliOutskirts/scripts.pory"
	emote_exclamation_mark
	step_end

# 18 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_2:
# 18 "data/maps/HauoliOutskirts/scripts.pory"
	delay_8
# 18 "data/maps/HauoliOutskirts/scripts.pory"
	walk_left
# 18 "data/maps/HauoliOutskirts/scripts.pory"
	face_right
	step_end

# 19 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_3:
# 19 "data/maps/HauoliOutskirts/scripts.pory"
	delay_16
# 19 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
# 19 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
# 19 "data/maps/HauoliOutskirts/scripts.pory"
	face_left
	step_end

# 25 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_4:
# 25 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
	step_end

# 29 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_5:
# 29 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
	step_end

# 33 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_6:
# 33 "data/maps/HauoliOutskirts/scripts.pory"
	face_right
	step_end

# 34 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_7:
# 34 "data/maps/HauoliOutskirts/scripts.pory"
	face_left
	step_end

# 74 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_8:
# 74 "data/maps/HauoliOutskirts/scripts.pory"
	walk_in_place_down
# 74 "data/maps/HauoliOutskirts/scripts.pory"
	walk_in_place_down
	step_end

# 103 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_9:
# 103 "data/maps/HauoliOutskirts/scripts.pory"
	jump_in_place_down
# 103 "data/maps/HauoliOutskirts/scripts.pory"
	jump_in_place_down
	step_end

# 163 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_10:
# 163 "data/maps/HauoliOutskirts/scripts.pory"
	walk_faster_up
# 163 "data/maps/HauoliOutskirts/scripts.pory"
	walk_faster_up
# 163 "data/maps/HauoliOutskirts/scripts.pory"
	walk_faster_up
	step_end

# 200 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_0:
# 200 "data/maps/HauoliOutskirts/scripts.pory"
	face_player
	step_end

# 220 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_1:
# 220 "data/maps/HauoliOutskirts/scripts.pory"
	shake_horizontal
	step_end

# 253 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_2:
# 253 "data/maps/HauoliOutskirts/scripts.pory"
	emote_exclamation_mark
# 253 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
	step_end

# 330 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_3:
# 330 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
# 330 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
	step_end

# 334 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_4:
# 334 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
	step_end

HauoliOutskirts_ExitLabEclipse_Text_0:
# 36 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Lillie$"

HauoliOutskirts_ExitLabEclipse_Text_1:
# 37 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The Pokémon Center is practically right\n"
	.string "next to your house, isn't it?$"

HauoliOutskirts_ExitLabEclipse_Text_2:
# 43 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Ah…$"

HauoliOutskirts_ExitLabEclipse_Text_3:
# 62 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pew…$"

HauoliOutskirts_ExitLabEclipse_Text_4:
# 68 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Nebby…\n"
	.string "{PAUSE_UNTIL_PRESS}Don't worry-it's OK.\p"
	.string "This must be what they call a lunar\n"
	.string "eclipse. It happens when the moon\l"
	.string "gets covered up.$"

HauoliOutskirts_ExitLabEclipse_Text_5:
# 76 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Kukui$"

HauoliOutskirts_ExitLabEclipse_Text_6:
# 77 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Was a lunar eclipse forcast for today?\p"
	.string "Ah, well. It must be some kind of\n"
	.string "good omen, yeah!$"

HauoliOutskirts_ExitLabEclipse_Text_7:
# 83 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Nebby…\n"
	.string "{PAUSE_UNTIL_PRESS}Don't worry-it's OK.\p"
	.string "This must be what they call a solar\n"
	.string "eclipse. It happens when the sun\l"
	.string "gets covered up.$"

HauoliOutskirts_ExitLabEclipse_Text_8:
# 92 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Was a solar eclipse forcast for today?\p"
	.string "Ah, well. It must be some kind of\n"
	.string "good omen, yeah!$"

HauoliOutskirts_ExitLabEclipse_Text_9:
# 101 "data/maps/HauoliOutskirts/scripts.pory"
	.string "An omen?\n"
	.string "You think something good will happen?$"

HauoliOutskirts_ExitLabEclipse_Text_10:
# 110 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Sure! A long, long time ago, Alola was\n"
	.string "cloaked in darkness, yeah…\p"
	.string "But people say that's when Alola's\n"
	.string "people and Pokémon blasted all that\l"
	.string "darkness away with light!\p"
	.string "And they also say that was why people\n"
	.string "started gathering Z-Crystals, and\l"
	.string "that custom turned into the island\l"
	.string "challenge.$"

HauoliOutskirts_ExitLabEclipse_Text_11:
# 128 "data/maps/HauoliOutskirts/scripts.pory"
	.string "{PLAYER}!\p"
	.string "Now that you've got that Z-Power Ring,\n"
	.string "I hope you'll collect tons of\l"
	.string "Z-Crystals! Woo!\p"
	.string "That's exactly what a move researcher\n"
	.string "like me needs to uncover new secrets!$"

HauoliOutskirts_ExitLabEclipse_Text_12:
# 140 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Professor, that's not why he's supposed\n"
	.string "to be doing it…$"

HauoliOutskirts_ExitLabEclipse_Text_13:
# 145 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Come on, {PLAYER}.\n"
	.string "I'll show you to the Pokémon Center.$"

HauoliOutskirts_ExitLabEclipse_Text_14:
# 151 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Professor, that's not why she's\n"
	.string "supposed to be doing it…$"

HauoliOutskirts_LillieOutsideLab_Text_0:
# 204 "data/maps/HauoliOutskirts/scripts.pory"
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
# 222 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pew!$"

HauoliOutskirts_LillieOutsideLab_Text_2:
# 227 "data/maps/HauoliOutskirts/scripts.pory"
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
# 257 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Oh yeah, Rockruff! Lets go!\n"
	.string "Give it everything you've got!\l"
	.string "My body is ready. Woo!$"

HauoliOutskirts_LillieOutsideLab_Text_4:
# 272 "data/maps/HauoliOutskirts/scripts.pory"
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
# 299 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Raaaa-oooooohhh! Raff ruff!$"

HauoliOutskirts_LillieOutsideLab_Text_6:
# 313 "data/maps/HauoliOutskirts/scripts.pory"
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
# 360 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pokémon Research Lab$"

OutsideTenCarrotHill_Text_0:
# 368 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Wa ha ha!\n"
	.string "You're a strong Trainer, all right!\l"
	.string "Go on! You take on Ten Carrot Hill,\l"
	.string "friend!\p"
	.string "Even stronger Pokémon await you\n"
	.string "within!$"

TenCarrotHillSign_Text_0:
# 374 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Ten Carrot Hill$"

HauoliOutskirtLittleGirlNPC_Text_0:
# 381 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The Pokémon I've got with me are all\n"
	.string "Grass-type.\p"
	.string "I'm looking for Water-type Pokémon\l"
	.string "for my team so I can beat Fire types,\l"
	.string "too.$"

HauoliOustkirtsTrainerTipsSign_Text_0:
# 388 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Trainer Tips\p"
	.string "The Pokémon that will appear first in\n"
	.string "battle will be the one you've put in\l"
	.string "the left position in your Pokémon\l"
	.string "party.$"

HauoliOutskirtLassNPC_Text_0:
# 394 "data/maps/HauoliOutskirts/scripts.pory"
	.string "If you see a Pokémon Trainer, you've\ngotta show off the Pokémon you like!$"

HauoliOustkirtsFishingSpot1_Text_0:
# 402 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Would you like to fish here?$"

HauoliOustkirtsFishingSpot1_Text_1:
# 411 "data/maps/HauoliOutskirts/scripts.pory"
	.string "You don't have a Fishing Rod.$"

HauoliOustkirtsFishingSpot1_Text_2:
# 421 "data/maps/HauoliOutskirts/scripts.pory"
	.string "You can't fish while riding a Sharpedo!$"
