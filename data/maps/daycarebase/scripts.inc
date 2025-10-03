daycarebase_MapScripts::
# 2 "data/maps/daycarebase/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Daycare_OnTransition
# 3 "data/maps/daycarebase/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, daycarebase_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

daycarebase_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/daycarebase/scripts.pory"
	map_script_2 VAR_INTRO_PLAYED, 0, DaycareIntro
	.2byte 0


DaycareIntro::
# 7 "data/maps/daycarebase/scripts.pory"
	lock
# 8 "data/maps/daycarebase/scripts.pory"
	special EnableNationalPokedex
# 9 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 10 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareIntro_Text_1, MSGBOX_AUTOCLOSE
# 11 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 12 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_OLDMAN_INTRO
# 13 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareManIntro, DaycareIntro_Movement_0
# 14 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareManIntro
# 15 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareManIntro, DaycareIntro_Movement_1
# 16 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareManIntro
# 17 "data/maps/daycarebase/scripts.pory"
	removeobject DaycareManIntro
# 18 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_HIDE_INTRO_DAYCAREMAN
# 19 "data/maps/daycarebase/scripts.pory"
	applymovement LOCALID_PLAYER, DaycareIntro_Movement_2
# 20 "data/maps/daycarebase/scripts.pory"
	applymovement VaporeonIntro, DaycareIntro_Movement_3
# 21 "data/maps/daycarebase/scripts.pory"
	waitmovement LOCALID_PLAYER
# 22 "data/maps/daycarebase/scripts.pory"
	waitmovement VaporeonIntro
# 23 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_VAPOREON, EMOTE_ANGRY
# 24 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_2
# 25 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareIntro_Text_3, MSGBOX_AUTOCLOSE
# 25 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 26 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 27 "data/maps/daycarebase/scripts.pory"
	applymovement VaporeonIntro, DaycareIntro_Movement_4
# 28 "data/maps/daycarebase/scripts.pory"
	playse SE_FLEE
# 29 "data/maps/daycarebase/scripts.pory"
	waitmovement VaporeonIntro
# 30 "data/maps/daycarebase/scripts.pory"
	waitse
# 31 "data/maps/daycarebase/scripts.pory"
	removeobject VaporeonIntro
# 32 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_HIDE_VAPOREON_INTRO
# 33 "data/maps/daycarebase/scripts.pory"
	setvar VAR_INTRO_PLAYED, 1
# 34 "data/maps/daycarebase/scripts.pory"
	release
	end


Daycare_OnTransition::
# 39 "data/maps/daycarebase/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCAREBASE
	end


ShrinkToPikachuCave::
# 44 "data/maps/daycarebase/scripts.pory"
	lock
# 45 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq ShrinkToPikachuCave_1
# 59 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, ShrinkToPikachuCave_4
ShrinkToPikachuCave_3:
# 88 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 89 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 90 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave_1:
# 47 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_0, MSGBOX_YESNO
# 48 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave_8
# 54 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 55 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave_2:
# 61 "data/maps/daycarebase/scripts.pory"
	checkpartymove MOVE_STICKY_WEB
# 62 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne ShrinkToPikachuCave_11
# 80 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 81 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 82 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave_4:
# 59 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_ne ShrinkToPikachuCave_2
	goto ShrinkToPikachuCave_3

ShrinkToPikachuCave_8:
# 50 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_PIKACHU_SHRINK_CAVE, 0
	return

ShrinkToPikachuCave_11:
# 64 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_1, MSGBOX_YESNO
# 65 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave_14
# 73 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 74 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave_14:
# 67 "data/maps/daycarebase/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 68 "data/maps/daycarebase/scripts.pory"
	delay 30
# 69 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_PIKACHU_SHRINK_CAVE, 0
	return


ShrinkToPikachuCave2::
# 96 "data/maps/daycarebase/scripts.pory"
	lock
# 97 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq ShrinkToPikachuCave2_1
# 111 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, ShrinkToPikachuCave2_4
ShrinkToPikachuCave2_3:
# 140 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 141 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 142 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave2_1:
# 99 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_0, MSGBOX_YESNO
# 100 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave2_8
# 106 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 107 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave2_2:
# 113 "data/maps/daycarebase/scripts.pory"
	checkpartymove MOVE_STICKY_WEB
# 114 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne ShrinkToPikachuCave2_11
# 132 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 133 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 134 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave2_4:
# 111 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_ne ShrinkToPikachuCave2_2
	goto ShrinkToPikachuCave2_3

ShrinkToPikachuCave2_8:
# 102 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_PIKACHU_SHRINK_CAVE, 1
	return

ShrinkToPikachuCave2_11:
# 116 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_1, MSGBOX_YESNO
# 117 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave2_14
# 125 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 126 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave2_14:
# 119 "data/maps/daycarebase/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 120 "data/maps/daycarebase/scripts.pory"
	delay 30
# 121 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_PIKACHU_SHRINK_CAVE, 1
	return


ShrinktoMausholdCave::
# 148 "data/maps/daycarebase/scripts.pory"
	lock
# 149 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq ShrinktoMausholdCave_1
# 163 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, ShrinktoMausholdCave_4
ShrinktoMausholdCave_3:
# 192 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 193 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 194 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinktoMausholdCave_1:
# 151 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_0, MSGBOX_YESNO
# 152 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinktoMausholdCave_8
# 158 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 159 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinktoMausholdCave_2:
# 165 "data/maps/daycarebase/scripts.pory"
	checkpartymove MOVE_DAZZLING_GLEAM
# 166 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne ShrinktoMausholdCave_11
# 184 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 185 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 186 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinktoMausholdCave_4:
# 163 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_ne ShrinktoMausholdCave_2
	goto ShrinktoMausholdCave_3

ShrinktoMausholdCave_8:
# 154 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_MAUSHOLD_SHRINK, 0
	return

ShrinktoMausholdCave_11:
# 168 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_1, MSGBOX_YESNO
# 169 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinktoMausholdCave_14
# 177 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 178 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinktoMausholdCave_14:
# 171 "data/maps/daycarebase/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 172 "data/maps/daycarebase/scripts.pory"
	delay 30
# 173 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_MAUSHOLD_SHRINK, 0
	return


MimikyuDialog::
# 200 "data/maps/daycarebase/scripts.pory"
	lock
# 201 "data/maps/daycarebase/scripts.pory"
	applymovement mimikyu, MimikyuDialog_Movement_0
# 202 "data/maps/daycarebase/scripts.pory"
	waitmovement mimikyu
# 203 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq MimikyuDialog_1
# 220 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_PIKACHU
	goto_if_eq MimikyuDialog_2
# 256 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 257 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYUTOP, EMOTE_NORMAL
# 258 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_1, MSGBOX_DEFAULT
# 259 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 260 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 261 "data/maps/daycarebase/scripts.pory"
	release
	end

MimikyuDialog_1:
# 205 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 206 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYUTOP, EMOTE_NORMAL
# 207 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_1, MSGBOX_DEFAULT
# 208 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 209 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 210 "data/maps/daycarebase/scripts.pory"
	applymovement mimikyu, Common_Movement_ExclamationMark
# 211 "data/maps/daycarebase/scripts.pory"
	waitmovement mimikyu
# 212 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_2
# 213 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYU, EMOTE_ANGRY
# 214 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_3, MSGBOX_DEFAULT
# 215 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 216 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 217 "data/maps/daycarebase/scripts.pory"
	release
	end

MimikyuDialog_2:
# 222 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_MIMIKYU_LUCKYEGG, MimikyuDialog_6
# 234 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 235 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYUTOP, EMOTE_NORMAL
# 236 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_1, MSGBOX_DEFAULT
# 237 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 238 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 239 "data/maps/daycarebase/scripts.pory"
	applymovement mimikyu, Common_Movement_ExclamationMark
# 240 "data/maps/daycarebase/scripts.pory"
	waitmovement mimikyu
# 241 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_2
# 242 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYU, EMOTE_ANGRY
# 243 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_5, MSGBOX_DEFAULT
# 244 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 245 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 246 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 247 "data/maps/daycarebase/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 248 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_MIMIKYU_LUCKYEGG
# 249 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 250 "data/maps/daycarebase/scripts.pory"
	release
	end

MimikyuDialog_6:
# 224 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_2
# 225 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYU, EMOTE_ANGRY
# 226 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_4, MSGBOX_DEFAULT
# 227 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 228 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 229 "data/maps/daycarebase/scripts.pory"
	release
	end


KecleonDialog::
# 266 "data/maps/daycarebase/scripts.pory"
	lock
# 267 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 268 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq KecleonDialog_1
# 280 "data/maps/daycarebase/scripts.pory"
	speakername KecleonDialog_Text_0
# 281 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_KECLEON, EMOTE_NORMAL
# 282 "data/maps/daycarebase/scripts.pory"
	msgbox KecleonDialog_Text_2, MSGBOX_DEFAULT
# 283 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 284 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 285 "data/maps/daycarebase/scripts.pory"
	release
	end

KecleonDialog_1:
# 270 "data/maps/daycarebase/scripts.pory"
	speakername KecleonDialog_Text_0
# 271 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_KECLEON, EMOTE_NORMAL
# 272 "data/maps/daycarebase/scripts.pory"
	msgbox KecleonDialog_Text_1, MSGBOX_DEFAULT
# 273 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 274 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 275 "data/maps/daycarebase/scripts.pory"
	release
	end


AzumarillDialog::
# 292 "data/maps/daycarebase/scripts.pory"
	lock
# 293 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 294 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq AzumarillDialog_1
# 306 "data/maps/daycarebase/scripts.pory"
	speakername AzumarillDialog_Text_0
# 307 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_AZUMARILL, EMOTE_ANGRY
# 308 "data/maps/daycarebase/scripts.pory"
	msgbox AzumarillDialog_Text_2, MSGBOX_DEFAULT
# 309 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 310 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 311 "data/maps/daycarebase/scripts.pory"
	release
	end

AzumarillDialog_1:
# 296 "data/maps/daycarebase/scripts.pory"
	speakername AzumarillDialog_Text_0
# 297 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_AZUMARILL, EMOTE_NORMAL
# 298 "data/maps/daycarebase/scripts.pory"
	msgbox AzumarillDialog_Text_1, MSGBOX_DEFAULT
# 299 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 300 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 301 "data/maps/daycarebase/scripts.pory"
	release
	end


DaycareOldManDialog::
# 317 "data/maps/daycarebase/scripts.pory"
	lock
# 318 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 319 "data/maps/daycarebase/scripts.pory"
	goto_if_unset FLAG_BEAT_MEW, DaycareOldManDialog_1
# 351 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq DaycareOldManDialog_7
# 579 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 580 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_1, MSGBOX_DEFAULT
# 581 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 582 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_1:
# 321 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_OLDMAN_INTRO, DaycareOldManDialog_4
# 341 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 342 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_2, MSGBOX_DEFAULT
# 343 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 344 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_OLDMAN_INTRO
# 345 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_4:
# 323 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq DaycareOldManDialog_10
# 332 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 333 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_1, MSGBOX_DEFAULT
# 334 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 335 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_7:
# 353 "data/maps/daycarebase/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 354 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 355 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, MimikyuDialog_Movement_0
# 356 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 357 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, Common_Movement_ExclamationMark
# 358 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 359 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 360 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_3, MSGBOX_YESNO
# 361 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 362 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DaycareOldManDialog_13
# 471 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 472 "data/maps/daycarebase/scripts.pory"
	playse SE_M_SCRATCH
# 473 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_15, MSGBOX_DEFAULT
# 474 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 475 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 476 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 477 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_5, MSGBOX_DEFAULT
# 478 "data/maps/daycarebase/scripts.pory"
	removeobject BrendanBiking
# 479 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_HIDE_BRENDAN_BIKE
# 480 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 481 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 482 "data/maps/daycarebase/scripts.pory"
	playse SE_EXP
# 483 "data/maps/daycarebase/scripts.pory"
	waitse
# 484 "data/maps/daycarebase/scripts.pory"
	playse SE_EXP_MAX
# 485 "data/maps/daycarebase/scripts.pory"
	waitse
# 486 "data/maps/daycarebase/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 487 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_6, MSGBOX_DEFAULT
# 488 "data/maps/daycarebase/scripts.pory"
	waitfanfare
# 489 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 490 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 491 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_7, MSGBOX_AUTOCLOSE
# 492 "data/maps/daycarebase/scripts.pory"
	special SpawnCameraObject
# 493 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, DaycareOldManDialog_Movement_0
# 494 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 495 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, DaycareOldManDialog_Movement_1
# 496 "data/maps/daycarebase/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, DaycareOldManDialog_Movement_1
# 497 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 498 "data/maps/daycarebase/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 499 "data/maps/daycarebase/scripts.pory"
	delay 60
# 500 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK, 24
# 501 "data/maps/daycarebase/scripts.pory"
	delay 60
# 502 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SHOW_BRENDAN_OUTRO
# 503 "data/maps/daycarebase/scripts.pory"
	addobject Brendan
# 504 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK, 24
# 505 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_2
# 506 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 507 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 508 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, Common_Movement_ExclamationMark
# 509 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 510 "data/maps/daycarebase/scripts.pory"
	delay 30
# 511 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_3
# 512 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 513 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_4
# 514 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 515 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 516 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_8, MSGBOX_DEFAULT
# 517 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 518 "data/maps/daycarebase/scripts.pory"
	delay 30
# 519 "data/maps/daycarebase/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 520 "data/maps/daycarebase/scripts.pory"
	delay 60
# 521 "data/maps/daycarebase/scripts.pory"
	special CountLuckyEggs
# 522 "data/maps/daycarebase/scripts.pory"
	special GetWhiteoutCount
# 523 "data/maps/daycarebase/scripts.pory"
	copyvar VAR_TEMP_0, VAR_WHITEOUT_COUNT
# 524 "data/maps/daycarebase/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_0
# 525 "data/maps/daycarebase/scripts.pory"
	copyvar VAR_TEMP_1, VAR_LUCKYEGG_COUNT
# 526 "data/maps/daycarebase/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_1
# 527 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_61
DaycareOldManDialog_58:
# 541 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_57
DaycareOldManDialog_54:
# 547 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_53
DaycareOldManDialog_51:
# 553 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_ne DaycareOldManDialog_50
DaycareOldManDialog_48:
# 559 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_ne DaycareOldManDialog_47
DaycareOldManDialog_46:
# 567 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_14, MSGBOX_DEFAULT
# 568 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 569 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
DaycareOldManDialog_40:
# 571 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 572 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_BEAT_MEW
# 573 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SHOW_BRENDAN_OUTRO
# 574 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_HIDE_BRENDAN_BIKE
# 575 "data/maps/daycarebase/scripts.pory"
	special GameClear
	return

DaycareOldManDialog_10:
# 325 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 326 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_0, MSGBOX_DEFAULT
# 327 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 328 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_13:
# 364 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 365 "data/maps/daycarebase/scripts.pory"
	playse SE_ITEMFINDER
# 366 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_4, MSGBOX_DEFAULT
# 367 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 368 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 369 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 370 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_5, MSGBOX_DEFAULT
# 371 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 372 "data/maps/daycarebase/scripts.pory"
	removeobject BrendanBiking
# 373 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_HIDE_BRENDAN_BIKE
# 374 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 375 "data/maps/daycarebase/scripts.pory"
	playse SE_EXP
# 376 "data/maps/daycarebase/scripts.pory"
	waitse
# 377 "data/maps/daycarebase/scripts.pory"
	playse SE_EXP_MAX
# 378 "data/maps/daycarebase/scripts.pory"
	waitse
# 379 "data/maps/daycarebase/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 380 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_6, MSGBOX_DEFAULT
# 381 "data/maps/daycarebase/scripts.pory"
	waitfanfare
# 382 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 383 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 384 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_7, MSGBOX_AUTOCLOSE
# 385 "data/maps/daycarebase/scripts.pory"
	special SpawnCameraObject
# 386 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, DaycareOldManDialog_Movement_0
# 387 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 388 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, DaycareOldManDialog_Movement_1
# 389 "data/maps/daycarebase/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, DaycareOldManDialog_Movement_1
# 390 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 391 "data/maps/daycarebase/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 392 "data/maps/daycarebase/scripts.pory"
	delay 60
# 393 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK, 24
# 394 "data/maps/daycarebase/scripts.pory"
	delay 60
# 395 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SHOW_BRENDAN_OUTRO
# 396 "data/maps/daycarebase/scripts.pory"
	addobject Brendan
# 397 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK, 24
# 398 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_2
# 399 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 400 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 401 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, Common_Movement_ExclamationMark
# 402 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 403 "data/maps/daycarebase/scripts.pory"
	delay 30
# 404 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_3
# 405 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 406 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_4
# 407 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 408 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 409 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_8, MSGBOX_DEFAULT
# 410 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 411 "data/maps/daycarebase/scripts.pory"
	delay 30
# 412 "data/maps/daycarebase/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 413 "data/maps/daycarebase/scripts.pory"
	delay 60
# 414 "data/maps/daycarebase/scripts.pory"
	special CountLuckyEggs
# 415 "data/maps/daycarebase/scripts.pory"
	special GetWhiteoutCount
# 416 "data/maps/daycarebase/scripts.pory"
	copyvar VAR_TEMP_0, VAR_WHITEOUT_COUNT
# 417 "data/maps/daycarebase/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_0
# 418 "data/maps/daycarebase/scripts.pory"
	copyvar VAR_TEMP_1, VAR_LUCKYEGG_COUNT
# 419 "data/maps/daycarebase/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_1
# 420 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_37
DaycareOldManDialog_34:
# 434 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_33
DaycareOldManDialog_30:
# 440 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_29
DaycareOldManDialog_27:
# 446 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_ne DaycareOldManDialog_26
DaycareOldManDialog_24:
# 452 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_ne DaycareOldManDialog_23
DaycareOldManDialog_22:
# 460 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_14, MSGBOX_DEFAULT
# 461 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 462 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
DaycareOldManDialog_16:
# 464 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 465 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_BEAT_MEW
# 466 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SHOW_BRENDAN_OUTRO
# 467 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_HIDE_BRENDAN_BIKE
# 468 "data/maps/daycarebase/scripts.pory"
	special GameClear
	return

DaycareOldManDialog_17:
# 422 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_9, MSGBOX_DEFAULT
# 423 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 424 "data/maps/daycarebase/scripts.pory"
	special ForceShinyDitto
# 425 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 426 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_BEAT_MEW
# 427 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SHOW_BRENDAN_OUTRO
# 428 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_HIDE_BRENDAN_BIKE
# 429 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SPAWN_INVISIBLE
# 430 "data/maps/daycarebase/scripts.pory"
	warp MAP_ROUTE117, 14, 27
# 431 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_18:
# 436 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_10, MSGBOX_DEFAULT
# 437 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 438 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_16

DaycareOldManDialog_19:
# 442 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_11, MSGBOX_DEFAULT
# 443 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 444 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_16

DaycareOldManDialog_20:
# 448 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_12, MSGBOX_DEFAULT
# 449 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 450 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_16

DaycareOldManDialog_21:
# 454 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_13, MSGBOX_DEFAULT
# 455 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 456 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_16

DaycareOldManDialog_23:
# 452 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_eq DaycareOldManDialog_21
	goto DaycareOldManDialog_22

DaycareOldManDialog_26:
# 446 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_eq DaycareOldManDialog_20
	goto DaycareOldManDialog_24

DaycareOldManDialog_29:
# 440 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_eq DaycareOldManDialog_19
	goto DaycareOldManDialog_27

DaycareOldManDialog_32:
# 434 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_gt DaycareOldManDialog_18
	goto DaycareOldManDialog_30

DaycareOldManDialog_33:
# 434 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_ne DaycareOldManDialog_32
	goto DaycareOldManDialog_30

DaycareOldManDialog_37:
# 420 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_eq DaycareOldManDialog_17
	goto DaycareOldManDialog_34

DaycareOldManDialog_41:
# 529 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_9, MSGBOX_DEFAULT
# 530 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 531 "data/maps/daycarebase/scripts.pory"
	special ForceShinyDitto
# 532 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 533 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_BEAT_MEW
# 534 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SHOW_BRENDAN_OUTRO
# 535 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_HIDE_BRENDAN_BIKE
# 536 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SPAWN_INVISIBLE
# 537 "data/maps/daycarebase/scripts.pory"
	warp MAP_ROUTE117, 14, 27
# 538 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_42:
# 543 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_10, MSGBOX_DEFAULT
# 544 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 545 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_40

DaycareOldManDialog_43:
# 549 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_11, MSGBOX_DEFAULT
# 550 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 551 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_40

DaycareOldManDialog_44:
# 555 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_12, MSGBOX_DEFAULT
# 556 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 557 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_40

DaycareOldManDialog_45:
# 561 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_13, MSGBOX_DEFAULT
# 562 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 563 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_40

DaycareOldManDialog_47:
# 559 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_eq DaycareOldManDialog_45
	goto DaycareOldManDialog_46

DaycareOldManDialog_50:
# 553 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_eq DaycareOldManDialog_44
	goto DaycareOldManDialog_48

DaycareOldManDialog_53:
# 547 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_eq DaycareOldManDialog_43
	goto DaycareOldManDialog_51

DaycareOldManDialog_56:
# 541 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_gt DaycareOldManDialog_42
	goto DaycareOldManDialog_54

DaycareOldManDialog_57:
# 541 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_ne DaycareOldManDialog_56
	goto DaycareOldManDialog_54

DaycareOldManDialog_61:
# 527 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_eq DaycareOldManDialog_41
	goto DaycareOldManDialog_58


VaporeonDialog::
# 593 "data/maps/daycarebase/scripts.pory"
	lock
# 594 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 595 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_2
# 596 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_VAPOREON, EMOTE_ANGRY
# 597 "data/maps/daycarebase/scripts.pory"
	msgbox VaporeonDialog_Text_0, MSGBOX_NPC
# 598 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 599 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 600 "data/maps/daycarebase/scripts.pory"
	release
	end


LaprasDialog::
# 606 "data/maps/daycarebase/scripts.pory"
	lock
# 607 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 608 "data/maps/daycarebase/scripts.pory"
	speakername LaprasDialog_Text_0
# 609 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_LAPRAS, EMOTE_HAPPY
# 610 "data/maps/daycarebase/scripts.pory"
	msgbox LaprasDialog_Text_1, MSGBOX_DEFAULT
# 611 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 612 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 613 "data/maps/daycarebase/scripts.pory"
	release
	end


LinooneDialog::
# 618 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq LinooneDialog_1
# 632 "data/maps/daycarebase/scripts.pory"
	lock
# 633 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 634 "data/maps/daycarebase/scripts.pory"
	speakername LinooneDialog_Text_0
# 635 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_LINOONE, EMOTE_NORMAL
# 636 "data/maps/daycarebase/scripts.pory"
	msgbox LinooneDialog_Text_2
# 637 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 638 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 639 "data/maps/daycarebase/scripts.pory"
	release
	end

LinooneDialog_1:
# 620 "data/maps/daycarebase/scripts.pory"
	lock
# 621 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 622 "data/maps/daycarebase/scripts.pory"
	speakername LinooneDialog_Text_0
# 623 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_LINOONE, EMOTE_NORMAL
# 624 "data/maps/daycarebase/scripts.pory"
	msgbox LinooneDialog_Text_1
# 625 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 626 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 627 "data/maps/daycarebase/scripts.pory"
	release
	end


BulbsaurDialog::
# 645 "data/maps/daycarebase/scripts.pory"
	lock
# 646 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 647 "data/maps/daycarebase/scripts.pory"
	speakername BulbsaurDialog_Text_0
# 648 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_BULBASAUR, EMOTE_NORMAL
# 649 "data/maps/daycarebase/scripts.pory"
	msgbox BulbsaurDialog_Text_1, MSGBOX_NPC
# 650 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 651 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 652 "data/maps/daycarebase/scripts.pory"
	release
	end


CombeeDialog::
# 657 "data/maps/daycarebase/scripts.pory"
	lock
# 658 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 659 "data/maps/daycarebase/scripts.pory"
	speakername CombeeDialog_Text_0
# 660 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_COMBEE, EMOTE_NORMAL
# 661 "data/maps/daycarebase/scripts.pory"
	msgbox CombeeDialog_Text_1, MSGBOX_NPC
# 662 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 663 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 664 "data/maps/daycarebase/scripts.pory"
	release
	end


Porygon2Dialog::
# 669 "data/maps/daycarebase/scripts.pory"
	lock
# 670 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 671 "data/maps/daycarebase/scripts.pory"
	speakername Porygon2Dialog_Text_0
# 672 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_PORYGON2, EMOTE_NORMAL
# 673 "data/maps/daycarebase/scripts.pory"
	msgbox Porygon2Dialog_Text_1, MSGBOX_NPC
# 674 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 675 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 676 "data/maps/daycarebase/scripts.pory"
	release
	end


ScytherDialog::
# 681 "data/maps/daycarebase/scripts.pory"
	lock
# 682 "data/maps/daycarebase/scripts.pory"
	applymovement scyther, MimikyuDialog_Movement_0
# 683 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_DITTO_IS_SHINY, ScytherDialog_3
ScytherDialog_2:
# 699 "data/maps/daycarebase/scripts.pory"
	speakername ScytherDialog_Text_0
# 700 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_SCYTHER, EMOTE_NORMAL
# 701 "data/maps/daycarebase/scripts.pory"
	msgbox ScytherDialog_Text_3, MSGBOX_DEFAULT
# 702 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 703 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 704 "data/maps/daycarebase/scripts.pory"
	release
	end

ScytherDialog_1:
# 685 "data/maps/daycarebase/scripts.pory"
	speakername ScytherDialog_Text_0
# 686 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_SCYTHER, EMOTE_NORMAL
# 687 "data/maps/daycarebase/scripts.pory"
	msgbox ScytherDialog_Text_1, MSGBOX_DEFAULT
# 688 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 689 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 690 "data/maps/daycarebase/scripts.pory"
	applymovement scyther, Common_Movement_ExclamationMark
# 691 "data/maps/daycarebase/scripts.pory"
	waitmovement scyther
# 692 "data/maps/daycarebase/scripts.pory"
	msgbox ScytherDialog_Text_2
# 693 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 694 "data/maps/daycarebase/scripts.pory"
	release
	end

ScytherDialog_3:
# 683 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq ScytherDialog_1
	goto ScytherDialog_2


RioluDialog::
# 710 "data/maps/daycarebase/scripts.pory"
	lock
# 711 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 712 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_RIOLU_INTRO, RioluDialog_1
# 847 "data/maps/daycarebase/scripts.pory"
	speakername RioluDialog_Text_0
# 848 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 849 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_28, MSGBOX_DEFAULT
# 850 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_RIOLU_INTRO
# 851 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 852 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 853 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_1:
# 714 "data/maps/daycarebase/scripts.pory"
	lock
# 715 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 716 "data/maps/daycarebase/scripts.pory"
	speakername RioluDialog_Text_0
# 717 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 718 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_1, MSGBOX_DEFAULT
# 719 "data/maps/daycarebase/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 720 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 721 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RioluDialog_4
# 834 "data/maps/daycarebase/scripts.pory"
	lock
# 835 "data/maps/daycarebase/scripts.pory"
	speakername RioluDialog_Text_0
# 836 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 837 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_27, MSGBOX_AUTOCLOSE
# 838 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 839 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 840 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_4:
# 723 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 724 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_2, MSGBOX_DEFAULT
# 725 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 726 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_3, MSGBOX_YESNO
# 727 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RioluDialog_7
# 824 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 825 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_26
# 826 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 827 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 828 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_7:
# 729 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 730 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_4, MSGBOX_DEFAULT
# 731 "data/maps/daycarebase/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 732 "data/maps/daycarebase/scripts.pory"
	dynmultichoice 0, 0, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, RioluDialog_Text_5, RioluDialog_Text_6, RioluDialog_Text_7, RioluDialog_Text_8, RioluDialog_Text_9, RioluDialog_Text_10, RioluDialog_Text_11, MimikyuDialog_Text_0, RioluDialog_Text_12, RioluDialog_Text_13, RioluDialog_Text_14
# 733 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq RioluDialog_10
# 741 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq RioluDialog_11
# 749 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq RioluDialog_12
# 757 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq RioluDialog_13
# 765 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq RioluDialog_14
# 773 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq RioluDialog_15
# 781 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq RioluDialog_16
# 789 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq RioluDialog_17
# 797 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq RioluDialog_18
# 805 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq RioluDialog_19
# 813 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq RioluDialog_20
	return

RioluDialog_10:
# 735 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_15, MSGBOX_DEFAULT
# 736 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 737 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 738 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_11:
# 743 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_16, MSGBOX_DEFAULT
# 744 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 745 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 746 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_12:
# 751 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_17, MSGBOX_DEFAULT
# 752 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 753 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 754 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_13:
# 759 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_18, MSGBOX_DEFAULT
# 760 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 761 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 762 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_14:
# 767 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_19, MSGBOX_DEFAULT
# 768 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 769 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 770 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_15:
# 775 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_20, MSGBOX_DEFAULT
# 776 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 777 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 778 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_16:
# 783 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_21, MSGBOX_DEFAULT
# 784 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 785 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 786 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_17:
# 791 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_22, MSGBOX_DEFAULT
# 792 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 793 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 794 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_18:
# 799 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_23, MSGBOX_DEFAULT
# 800 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 801 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 802 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_19:
# 807 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_24, MSGBOX_DEFAULT
# 808 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 809 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 810 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_20:
# 815 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_25, MSGBOX_DEFAULT
# 816 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 817 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 818 "data/maps/daycarebase/scripts.pory"
	release
	end


BattleVsPikachu::
# 860 "data/maps/daycarebase/scripts.pory"
	lock
# 862 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_TRANS_PIKACHU, BattleVsPikachu_2
# 874 "data/maps/daycarebase/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 875 "data/maps/daycarebase/scripts.pory"
	applymovement Pikachu, MimikyuDialog_Movement_0
# 876 "data/maps/daycarebase/scripts.pory"
	waitmovement Pikachu
# 877 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 878 "data/maps/daycarebase/scripts.pory"
	applymovement Pikachu, Common_Movement_ExclamationMark
# 879 "data/maps/daycarebase/scripts.pory"
	waitmovement Pikachu
# 880 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 881 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_PIKACHU, EMOTE_NORMAL
# 882 "data/maps/daycarebase/scripts.pory"
	msgbox BattleVsPikachu_Text_1, MSGBOX_AUTOCLOSE
# 883 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 884 "data/maps/daycarebase/scripts.pory"
	setwildbattle SPECIES_PIKACHU, 25
# 885 "data/maps/daycarebase/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 0, 0
# 886 "data/maps/daycarebase/scripts.pory"
	dowildbattle
# 887 "data/maps/daycarebase/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 888 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleVsPikachu_4
	return

BattleVsPikachu_2:
# 864 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 865 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 866 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_PIKACHU, EMOTE_NORMAL
# 867 "data/maps/daycarebase/scripts.pory"
	msgbox BattleVsPikachu_Text_0, MSGBOX_DEFAULT
# 868 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 869 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 870 "data/maps/daycarebase/scripts.pory"
	release
	end

BattleVsPikachu_4:
# 890 "data/maps/daycarebase/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 891 "data/maps/daycarebase/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 892 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_TRANS_PIKACHU
# 893 "data/maps/daycarebase/scripts.pory"
	delay 15
# 894 "data/maps/daycarebase/scripts.pory"
	dittotransform SPECIES_PIKACHU
# 895 "data/maps/daycarebase/scripts.pory"
	playse MUS_LEVEL_UP
# 896 "data/maps/daycarebase/scripts.pory"
	msgbox BattleVsPikachu_Text_2, MSGBOX_DEFAULT
# 897 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 898 "data/maps/daycarebase/scripts.pory"
	dittotransform VAR_TEMP_0
# 899 "data/maps/daycarebase/scripts.pory"
	givemon SPECIES_PIKACHU, 25, move1 = MOVE_NUZZLE, move2 = MOVE_IRON_TAIL, move3 = MOVE_SPARK, move4 = MOVE_FLASH
# 900 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 901 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_PIKACHU, EMOTE_HAPPY
# 902 "data/maps/daycarebase/scripts.pory"
	msgbox BattleVsPikachu_Text_3, MSGBOX_DEFAULT
# 903 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 904 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 905 "data/maps/daycarebase/scripts.pory"
	fadenewbgm MUS_PMD_HEARTWARMING
# 906 "data/maps/daycarebase/scripts.pory"
	release
	end


ChanseyHeal::
# 912 "data/maps/daycarebase/scripts.pory"
	lock
# 913 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 914 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_CHANSEY_INTRO, ChanseyHeal_1
# 962 "data/maps/daycarebase/scripts.pory"
	lock
# 963 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 964 "data/maps/daycarebase/scripts.pory"
	speakername ChanseyHeal_Text_0
# 965 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 966 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_6, MSGBOX_DEFAULT
# 967 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 968 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_CHANSEY_INTRO
# 969 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 970 "data/maps/daycarebase/scripts.pory"
	release
	end

ChanseyHeal_1:
# 916 "data/maps/daycarebase/scripts.pory"
	speakername ChanseyHeal_Text_0
# 917 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 918 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_1, MSGBOX_DEFAULT
# 919 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 920 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_2, MSGBOX_YESNO
# 921 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 922 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyHeal_4
# 952 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 953 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_5, MSGBOX_AUTOCLOSE
# 954 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 955 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 956 "data/maps/daycarebase/scripts.pory"
	release
	end

ChanseyHeal_4:
# 924 "data/maps/daycarebase/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 925 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyHeal_7
# 942 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 943 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_4, MSGBOX_AUTOCLOSE
# 944 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 945 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 946 "data/maps/daycarebase/scripts.pory"
	release
	end

ChanseyHeal_7:
# 927 "data/maps/daycarebase/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 928 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 929 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 930 "data/maps/daycarebase/scripts.pory"
	playfanfare MUS_HEAL
# 931 "data/maps/daycarebase/scripts.pory"
	waitfanfare
# 932 "data/maps/daycarebase/scripts.pory"
	special HealPlayerParty
# 933 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 934 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_3, MSGBOX_AUTOCLOSE
# 935 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 936 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 937 "data/maps/daycarebase/scripts.pory"
	release
	end


DaycareBase_Ditto::
# 977 "data/maps/daycarebase/scripts.pory"
	lock
# 978 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 979 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_DITTO_INTRO, DaycareBase_Ditto_1
# 1019 "data/maps/daycarebase/scripts.pory"
	speakername DaycareBase_Ditto_Text_1
# 1020 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 1021 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareBase_Ditto_Text_4, MSGBOX_DEFAULT
# 1022 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1023 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_DITTO_INTRO
# 1024 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1025 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 1026 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareBase_Ditto_1:
# 981 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_XFORMS_TALKED_TO_DITTO, DaycareBase_Ditto_4
# 1007 "data/maps/daycarebase/scripts.pory"
	speakername DaycareBase_Ditto_Text_1
# 1008 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 1009 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareBase_Ditto_Text_3, MSGBOX_DEFAULT
# 1010 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1011 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 1012 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareBase_Ditto_4:
# 983 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareBase_Ditto_Text_0, MSGBOX_YESNO
# 984 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DaycareBase_Ditto_7
# 995 "data/maps/daycarebase/scripts.pory"
	speakername DaycareBase_Ditto_Text_1
# 996 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 997 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareBase_Ditto_Text_2, MSGBOX_AUTOCLOSE
# 998 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 999 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 1000 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1001 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1002 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareBase_Ditto_7:
# 986 "data/maps/daycarebase/scripts.pory"
	dittotransform SPECIES_DITTO
# 987 "data/maps/daycarebase/scripts.pory"
	special OpenPCMoveMons
# 988 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 989 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 990 "data/maps/daycarebase/scripts.pory"
	release
	end


DaycarebaseDitto_intro_trigger::
# 1033 "data/maps/daycarebase/scripts.pory"
	goto_if_unset FLAG_DITTO_INTRO, DaycarebaseDitto_intro_trigger_1
	end

DaycarebaseDitto_intro_trigger_1:
# 1035 "data/maps/daycarebase/scripts.pory"
	lock
# 1036 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 1037 "data/maps/daycarebase/scripts.pory"
	applymovement DittoIntro, Common_Movement_ExclamationMark
# 1038 "data/maps/daycarebase/scripts.pory"
	waitmovement DittoIntro
# 1039 "data/maps/daycarebase/scripts.pory"
	applymovement DittoIntro, DaycareIntro_Movement_2
# 1040 "data/maps/daycarebase/scripts.pory"
	waitmovement DittoIntro
# 1041 "data/maps/daycarebase/scripts.pory"
	applymovement LOCALID_PLAYER, DaycareIntro_Movement_3
# 1042 "data/maps/daycarebase/scripts.pory"
	waitmovement LOCALID_PLAYER
# 1043 "data/maps/daycarebase/scripts.pory"
	speakername DaycareBase_Ditto_Text_1
# 1044 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 1045 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareBase_Ditto_Text_4, MSGBOX_DEFAULT
# 1046 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1047 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 1048 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_DITTO_INTRO
# 1049 "data/maps/daycarebase/scripts.pory"
	release
	end


DaycareBase_FindLuckyEgg::
# 1059 "data/maps/daycarebase/scripts.pory"
	finditem ITEM_LUCKY_EGG
	return


DaycareBase_FindLuckyEgg1::
# 1063 "data/maps/daycarebase/scripts.pory"
	lock
# 1064 "data/maps/daycarebase/scripts.pory"
	removeobject luckyegg1
# 1065 "data/maps/daycarebase/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 1066 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1067 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_ITEM_DAYCARE_BASE1
# 1068 "data/maps/daycarebase/scripts.pory"
	release
	end


DaycareBase_FindLuckyEgg2::
# 1073 "data/maps/daycarebase/scripts.pory"
	lock
# 1074 "data/maps/daycarebase/scripts.pory"
	removeobject luckyegg2
# 1075 "data/maps/daycarebase/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 1076 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1077 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_ITEM_DAYCARE_EAST1
# 1078 "data/maps/daycarebase/scripts.pory"
	release
	end


# 13 "data/maps/daycarebase/scripts.pory"
DaycareIntro_Movement_0:
# 13 "data/maps/daycarebase/scripts.pory"
	walk_right
	step_end

# 15 "data/maps/daycarebase/scripts.pory"
DaycareIntro_Movement_1:
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
	step_end

# 19 "data/maps/daycarebase/scripts.pory"
DaycareIntro_Movement_2:
# 19 "data/maps/daycarebase/scripts.pory"
	face_right
	step_end

# 20 "data/maps/daycarebase/scripts.pory"
DaycareIntro_Movement_3:
# 20 "data/maps/daycarebase/scripts.pory"
	face_left
	step_end

# 27 "data/maps/daycarebase/scripts.pory"
DaycareIntro_Movement_4:
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
	step_end

# 201 "data/maps/daycarebase/scripts.pory"
MimikyuDialog_Movement_0:
# 201 "data/maps/daycarebase/scripts.pory"
	face_player
	step_end

# 386 "data/maps/daycarebase/scripts.pory"
DaycareOldManDialog_Movement_0:
# 386 "data/maps/daycarebase/scripts.pory"
	face_down
	step_end

# 388 "data/maps/daycarebase/scripts.pory"
DaycareOldManDialog_Movement_1:
# 388 "data/maps/daycarebase/scripts.pory"
	walk_down
# 388 "data/maps/daycarebase/scripts.pory"
	walk_down
	step_end

# 398 "data/maps/daycarebase/scripts.pory"
DaycareOldManDialog_Movement_2:
# 398 "data/maps/daycarebase/scripts.pory"
	walk_right
# 398 "data/maps/daycarebase/scripts.pory"
	walk_right
# 398 "data/maps/daycarebase/scripts.pory"
	walk_right
# 398 "data/maps/daycarebase/scripts.pory"
	walk_right
# 398 "data/maps/daycarebase/scripts.pory"
	walk_right
	step_end

# 404 "data/maps/daycarebase/scripts.pory"
DaycareOldManDialog_Movement_3:
# 404 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 404 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 404 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 404 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 404 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
	step_end

# 406 "data/maps/daycarebase/scripts.pory"
DaycareOldManDialog_Movement_4:
# 406 "data/maps/daycarebase/scripts.pory"
	walk_fast_up
	step_end

DaycareIntro_Text_0:
# 9 "data/maps/daycarebase/scripts.pory"
	.string "Daycare Man$"

DaycareIntro_Text_1:
# 10 "data/maps/daycarebase/scripts.pory"
	.string "Welcome to the Daycare!\pDespite what trainers may see from\nRoute 117, the Daycare is a vast\larea filled with biomes for nearly\levery type of Pokémon!\pExplore the Daycare and interact\nwith many of the Pokémon we are\lraising.\pYou never know what friends you\nwill make along the way!\pNow, I do expect you to be holding\nan Egg at some point... Every Ditto\lI've raised has produced one.\pNow you two, run along and do what\nyou need to do to get that Egg!\pWhen you're holding an Egg,\ncome back and talk to me and\lwe can get it to your trainer.$"

DaycareIntro_Text_2:
# 24 "data/maps/daycarebase/scripts.pory"
	.string "Vaporeon$"

DaycareIntro_Text_3:
# 25 "data/maps/daycarebase/scripts.pory"
	.string "I don't care what the Daycare Man\nsays, I'm not interested in going on\lan Egg hunt.\pJust because Brendan put us in here\ntogether doesn't mean I have to\lhelp you.\pI'm going for a swim.\pYou'll just have to find that Egg\non your own.$"

ShrinkToPikachuCave_Text_0:
# 47 "data/maps/daycarebase/scripts.pory"
	.string "There is a tiny hole that you can\nsqueeze through.\pWould you like to squeeze through it?$"

ShrinkToPikachuCave_Text_1:
# 64 "data/maps/daycarebase/scripts.pory"
	.string "There is a tiny hole.\pA small Pokémon may be able to\nsqueeze through it.\pWould you like to transform into\nCutiefly to squeeze through it?$"

ShrinkToPikachuCave_Text_2:
# 80 "data/maps/daycarebase/scripts.pory"
	.string "There is a tiny hole.\pA small Pokémon may be able to\nsqueeze through it.$"

MimikyuDialog_Text_0:
# 205 "data/maps/daycarebase/scripts.pory"
	.string "Pikachu$"

MimikyuDialog_Text_1:
# 207 "data/maps/daycarebase/scripts.pory"
	.string "Hey!\pI'm just a normal Pikachu in my usual\nspot!$"

MimikyuDialog_Text_2:
# 212 "data/maps/daycarebase/scripts.pory"
	.string "Mimikyu$"

MimikyuDialog_Text_3:
# 214 "data/maps/daycarebase/scripts.pory"
	.string "Oh...\nYou caught me.\pI wish I could disguise myself as\nwell as you can...\pMaybe then people would like me more...$"

MimikyuDialog_Text_4:
# 226 "data/maps/daycarebase/scripts.pory"
	.string "I've always looked up to you\nPikachu.\pI hope my disguise doesn't insult\nyou..$"

MimikyuDialog_Text_5:
# 243 "data/maps/daycarebase/scripts.pory"
	.string "Oh!\nA real life Pikachu!\pYou are my idol.\pPlease take this.\n$"

KecleonDialog_Text_0:
# 270 "data/maps/daycarebase/scripts.pory"
	.string "Kecleon$"

KecleonDialog_Text_1:
# 272 "data/maps/daycarebase/scripts.pory"
	.string "Where do Eggs come from?\pMy trainer left me here a long time\nago and I've yet to find one.\pDo you know?\pI've always heard of Dittos\nholding onto Eggs...$"

KecleonDialog_Text_2:
# 282 "data/maps/daycarebase/scripts.pory"
	.string "Where do Eggs come from?\pMy trainer left me here a long time\nago and I've yet to find one.$"

AzumarillDialog_Text_0:
# 296 "data/maps/daycarebase/scripts.pory"
	.string "Azumarill$"

AzumarillDialog_Text_1:
# 298 "data/maps/daycarebase/scripts.pory"
	.string "Welcome to the Daycare!\pYou'll fit in well here.$"

AzumarillDialog_Text_2:
# 308 "data/maps/daycarebase/scripts.pory"
	.string "Oh!\nThank goodness you aren't a Ditto...\pMy trainer keeps putting me in here\nwith Dittos hoping we'll find an\lEgg.\pThey gave me this Sea Incense,\nbut I'm not sure how that would\lhelp us on our hunt...$"

DaycareOldManDialog_Text_0:
# 326 "data/maps/daycarebase/scripts.pory"
	.string "Back from exploring the Daycare?\pAh!\nBut where is your Egg?\pKeep doing whatever it is you\nDittos do and come back when\lyou have one!$"

DaycareOldManDialog_Text_1:
# 333 "data/maps/daycarebase/scripts.pory"
	.string "Why, who are you?\pI'm looking for a Ditto.\n$"

DaycareOldManDialog_Text_2:
# 342 "data/maps/daycarebase/scripts.pory"
	.string "Welcome to the Daycare!\pDespite what trainers may see from\nRoute 117, the Daycare is a vast\larea filled with biomes for nearly\levery type of Pokémon!\pExplore the Daycare and interact\nwith many of the Pokémon we are\lraising.\pYou never know what friends you\nwill make along the way!\pNow, I do expect you to be holding\nan Egg at some point... Every Ditto\lI've raised has produced one.\pWhen you're holding an Egg,\ncome back and talk to me and\lwe can get it to your trainer.$"

DaycareOldManDialog_Text_3:
# 360 "data/maps/daycarebase/scripts.pory"
	.string "Why what do we have here?\nGoodness!\pYou're holding an Egg!\pWherever did you get this?\pIt's the darndest thing.\pYou Pokémon always seem to find\nthese Eggs, but I can never figure\lout where they come from.\pWould you like to give me the Egg\nso that I may give it to your\lTrainer?$"

DaycareOldManDialog_Text_4:
# 366 "data/maps/daycarebase/scripts.pory"
	.string "Ditto handed over the Egg.\n$"

DaycareOldManDialog_Text_5:
# 370 "data/maps/daycarebase/scripts.pory"
	.string "Thank you for the Egg!\pAs a reward, take this EXP!\n$"

DaycareOldManDialog_Text_6:
# 380 "data/maps/daycarebase/scripts.pory"
	.string "Ditto grew to level 26.\n$"

DaycareOldManDialog_Text_7:
# 384 "data/maps/daycarebase/scripts.pory"
	.string "With this Egg, I can now fulfill\nmy duties.$"

DaycareOldManDialog_Text_8:
# 409 "data/maps/daycarebase/scripts.pory"
	.string "Ah, it's you!\pWe were raising your Pokémon\nand my goodness, were we surprised!\pYour Pokémon had an Egg!\pWe don't know how it got there,\nbut your Pokémon had it.\pYou do want it, yes?\n$"

DaycareOldManDialog_Text_9:
# 422 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR BLUE}{SHADOW LIGHT_BLUE}0\n{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Lucky Eggs found: {COLOR BLUE}{SHADOW LIGHT_BLUE}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pAmazing!\pYou beat the game with 0 whiteouts\nand found all of the Lucky Eggs!\pCongratulations!$"

DaycareOldManDialog_Text_10:
# 436 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR BLUE}{SHADOW LIGHT_BLUE}0{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\nLucky Eggs found: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pAmazing!\pYou beat the game with 0 whiteouts!\pKeep searching for the remaining\nLucky Eggs and defeat Mew again to\l100% the game!$"

DaycareOldManDialog_Text_11:
# 442 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR BLUE}{SHADOW LIGHT_BLUE}0{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\nLucky Eggs found: {COLOR RED}{SHADOW LIGHT_RED}0{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pAmazing!\pYou beat the game with 0 whiteouts!\pKeep searching for the remaining\nLucky Eggs and defeat Mew again to\l100% the game!$"

DaycareOldManDialog_Text_12:
# 448 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\nLucky Eggs found: {COLOR RED}{SHADOW LIGHT_RED}0{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pGreat job!\pYou can continue this save and\nfind the remaining Lucky eggs.\pChallenge Mew again and speak\nto the Daycare Man.\pStart a new run to try to win\nwithout whiting out.$"

DaycareOldManDialog_Text_13:
# 454 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\nLucky Eggs found: {COLOR BLUE}{SHADOW LIGHT_BLUE}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pGreat Job!\nYou found all of the Lucky Eggs!\pStart a new run to try to win\nwithout whiting out.$"

DaycareOldManDialog_Text_14:
# 460 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\nLucky Eggs found: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pGreat job!\pYou can continue this save and\nfind the remaining Lucky eggs.\pChallenge Mew again and speak\nto the Daycare Man.\pStart a new run to try to win\nwithout whiting out.$"

DaycareOldManDialog_Text_15:
# 473 "data/maps/daycarebase/scripts.pory"
	.string "The Daycare Man ripped the Egg\nfrom Ditto's clutches.$"

VaporeonDialog_Text_0:
# 597 "data/maps/daycarebase/scripts.pory"
	.string "Ugh!\nYou again.\pEveryone here keeps asking me to\nhelp them search for Eggs.\pCan't a Vaporeon just relax?$"

LaprasDialog_Text_0:
# 608 "data/maps/daycarebase/scripts.pory"
	.string "Lapras$"

LaprasDialog_Text_1:
# 610 "data/maps/daycarebase/scripts.pory"
	.string "I love the Daycare!\pIt's so peaceful and quiet here.\pI can just float around all day\nand relax.\pThose waterfalls are pretty\nvicious, I won't go near them.\pI've heard that Dragonair can\neasily scale even the largest\lof waterfalls!$"

LinooneDialog_Text_0:
# 622 "data/maps/daycarebase/scripts.pory"
	.string "Linoone$"

LinooneDialog_Text_1:
# 624 "data/maps/daycarebase/scripts.pory"
	.string "The Daycare is huge!\pIt's a bit scary to explore,\nso I stay up here.\pRiolu is way more brave than I\nam and has explored the entirety\lof the Daycare.\pYou should talk with Riolu if\nyou get lost!\pI'm sure they can help!\n$"

LinooneDialog_Text_2:
# 636 "data/maps/daycarebase/scripts.pory"
	.string "Those Dittos really freak me out.\pThey could be any one of us right\nnow...\pEven you!... or me!\n$"

BulbsaurDialog_Text_0:
# 647 "data/maps/daycarebase/scripts.pory"
	.string "Bulbasaur$"

BulbsaurDialog_Text_1:
# 649 "data/maps/daycarebase/scripts.pory"
	.string "You want to know where Eggs\ncome from?\pI heard that a Pokémon needs\nto go on a great adventure to\lmeet a shapeshifting Pokémon.\pIf you can best them, they will\ngive you an egg!\pAt least, that's what Venusaur\ntold me...$"

CombeeDialog_Text_0:
# 659 "data/maps/daycarebase/scripts.pory"
	.string "Combee$"

CombeeDialog_Text_1:
# 661 "data/maps/daycarebase/scripts.pory"
	.string "I've been in this Daycare\nfor ages!\pI've flown all around and\npollenated so many flowers\lbut I still haven't gained a\lsingle level.\pI'm beginning to believe gaining\nEXP here is nothing more\lthan a big ole myth!$"

Porygon2Dialog_Text_0:
# 671 "data/maps/daycarebase/scripts.pory"
	.string "Porygon2$"

Porygon2Dialog_Text_1:
# 673 "data/maps/daycarebase/scripts.pory"
	.string "Another Ditto...\pI'm actually a Ditto too,\nI just prefer this look.\pThe Daycare population must be at\nleast 75 percent Dittos!\pMost Dittos will take on different\nforms.\pYou won't be able to transform\ninto a form that another Ditto has\ltaken on though.$"

ScytherDialog_Text_0:
# 685 "data/maps/daycarebase/scripts.pory"
	.string "Scyther$"

ScytherDialog_Text_1:
# 687 "data/maps/daycarebase/scripts.pory"
	.string "One in every {COLOR BLUE}{SHADOW LIGHT_BLUE}fifty {COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Dittos that I\nsee here are blue.$"

ScytherDialog_Text_2:
# 692 "data/maps/daycarebase/scripts.pory"
	.string "Oh hey!\pYou're one of the blue ones!\pYou must've gotten really lucky!$"

ScytherDialog_Text_3:
# 701 "data/maps/daycarebase/scripts.pory"
	.string "One in every {COLOR BLUE}{SHADOW LIGHT_BLUE}fifty {COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Dittos that I\nsee here are blue.\pThere must be some reason trainers\nput so many in here...$"

RioluDialog_Text_0:
# 716 "data/maps/daycarebase/scripts.pory"
	.string "Riolu$"

RioluDialog_Text_1:
# 718 "data/maps/daycarebase/scripts.pory"
	.string "Back with a Lucky Egg?\n$"

RioluDialog_Text_2:
# 724 "data/maps/daycarebase/scripts.pory"
	.string "Great!\pI can tell about the habitat and\nability of a Pokémon in the Daycare.$"

RioluDialog_Text_3:
# 726 "data/maps/daycarebase/scripts.pory"
	.string "Would you like to exchange a\nLucky Egg?$"

RioluDialog_Text_4:
# 730 "data/maps/daycarebase/scripts.pory"
	.string "Which Pokémon would you like to\nknow more about?$"

RioluDialog_Text_5:
# 732 "data/maps/daycarebase/scripts.pory"
	.string "Arcanine$"

RioluDialog_Text_6:
# 732 "data/maps/daycarebase/scripts.pory"
	.string "Chinchou$"

RioluDialog_Text_7:
# 732 "data/maps/daycarebase/scripts.pory"
	.string "Cutiefly$"

RioluDialog_Text_8:
# 732 "data/maps/daycarebase/scripts.pory"
	.string "Dragonair$"

RioluDialog_Text_9:
# 732 "data/maps/daycarebase/scripts.pory"
	.string "Marill$"

RioluDialog_Text_10:
# 732 "data/maps/daycarebase/scripts.pory"
	.string "Machamp$"

RioluDialog_Text_11:
# 732 "data/maps/daycarebase/scripts.pory"
	.string "Noivern$"

RioluDialog_Text_12:
# 732 "data/maps/daycarebase/scripts.pory"
	.string "Rhyhorn$"

RioluDialog_Text_13:
# 732 "data/maps/daycarebase/scripts.pory"
	.string "Lurantis$"

RioluDialog_Text_14:
# 732 "data/maps/daycarebase/scripts.pory"
	.string "Weavile$"

RioluDialog_Text_15:
# 735 "data/maps/daycarebase/scripts.pory"
	.string "Arcanine can be found deep in the\nVolcano.\pIt can run really fast and scale\nhills that would normally be too\lslippery to climb!$"

RioluDialog_Text_16:
# 743 "data/maps/daycarebase/scripts.pory"
	.string "Chinchou can be found in a cave\non the water in the desert.\pIt can dive deep underwater.\n$"

RioluDialog_Text_17:
# 751 "data/maps/daycarebase/scripts.pory"
	.string "Cutiefly can be found in the\nDaycare's flowers to the west.\pIt's a tiny Pokémon that can\nfit through small openings.$"

RioluDialog_Text_18:
# 759 "data/maps/daycarebase/scripts.pory"
	.string "Dragonair can be found at the lake.\pIt can be a bit cryptic so it\nmay be difficult to reach.\pIt can scale large waterfalls\nwith ease.$"

RioluDialog_Text_19:
# 767 "data/maps/daycarebase/scripts.pory"
	.string "Marill can be found at the lake,\nusually by the shore.\pIt's a bit shy so it may be hiding.\pIt can float in any body of water.\n$"

RioluDialog_Text_20:
# 775 "data/maps/daycarebase/scripts.pory"
	.string "Machamp likes to train deep in\nthe mountains.\pIt is a very tough and solitary\nPokémon.\pIts strength can move large\nboulders.$"

RioluDialog_Text_21:
# 783 "data/maps/daycarebase/scripts.pory"
	.string "Noivern hangs out in a dark\ncave above the Daycare Falls.\pIt's quite a powerful Pokémon,\nso be prepared for a fight.\pIt can soar through the air,\nreaching places unreachable by\lnon_flying types.$"

RioluDialog_Text_22:
# 791 "data/maps/daycarebase/scripts.pory"
	.string "Pikachu is standing on that cliff\nright over there.\pIts electricity can light up even\nthe darkest of caves.$"

RioluDialog_Text_23:
# 799 "data/maps/daycarebase/scripts.pory"
	.string "Rhyhorn lives in the desert.\pIt's quite a friendly Pokémon,\nbut don't upset it!\pIt is strong enough to smash\nsolid rocks!$"

RioluDialog_Text_24:
# 807 "data/maps/daycarebase/scripts.pory"
	.string "Lurantis has been spending time\nacross the water in the mountains.\pIts sharp limbs can cut through\nsmall trees.$"

RioluDialog_Text_25:
# 815 "data/maps/daycarebase/scripts.pory"
	.string "Weavile is quite the ninja.\pIt spends time in the tall trees\nin the jungle.\pIt demands a fierce challenger\nto battle it.\pIts agility allows it to cross\neven the smallest of walkways.$"

RioluDialog_Text_26:
# 825 "data/maps/daycarebase/scripts.pory"
	.string "Oh.\pWhat else are you gonna do\nwith that egg?$"

RioluDialog_Text_27:
# 837 "data/maps/daycarebase/scripts.pory"
	.string "No?\nCome back when you do!$"

RioluDialog_Text_28:
# 849 "data/maps/daycarebase/scripts.pory"
	.string "Hiya!\pI'm Riolu!\pI've visited every biome the\nDaycare has to offer.\lI know it like the back of my paw!\pIf you need guidance on where a\ncertain Pokémon might be,\lI'm your Pokémon!\pAlthough I won't do it for free...\pBring me Lucky Eggs, and I'll tell\nyou what I know.$"

BattleVsPikachu_Text_0:
# 867 "data/maps/daycarebase/scripts.pory"
	.string "You really lit me up.\pBest of luck on your journey!\n$"

BattleVsPikachu_Text_1:
# 882 "data/maps/daycarebase/scripts.pory"
	.string "A Ditto!\pYou must be on your quest to obtain\nyour egg.\pDefeat me in battle and I'll allow\nyou to transform into me!$"

BattleVsPikachu_Text_2:
# 896 "data/maps/daycarebase/scripts.pory"
	.string "You have gained the ability to\ntransform into Pikachu!$"

BattleVsPikachu_Text_3:
# 902 "data/maps/daycarebase/scripts.pory"
	.string "How electrifying!\pElectric_type moves are powerful\nagainst Water_type Pokémon.\pThey typically spend their time in\nthe Lake Biome here.$"

ChanseyHeal_Text_0:
# 916 "data/maps/daycarebase/scripts.pory"
	.string "Chansey$"

ChanseyHeal_Text_1:
# 918 "data/maps/daycarebase/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyHeal_Text_2:
# 920 "data/maps/daycarebase/scripts.pory"
	.string "Would you like to heal?$"

ChanseyHeal_Text_3:
# 934 "data/maps/daycarebase/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyHeal_Text_4:
# 943 "data/maps/daycarebase/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyHeal_Text_5:
# 953 "data/maps/daycarebase/scripts.pory"
	.string "Oh, okay then.$"

ChanseyHeal_Text_6:
# 966 "data/maps/daycarebase/scripts.pory"
	.string "You look new!\pHave you found any Lucky Eggs yet?\pThey aren't quite the Mythical Egg\nyou are in search of, but many\lPokémon around the daycare will\loffer trades or services for them!\pDon't be afraid to use them!\pI'll offer to bring you back to\nfull health for just one!$"

DaycareBase_Ditto_Text_0:
# 983 "data/maps/daycarebase/scripts.pory"
	.string "Would you like to change out your\ntransformation options?$"

DaycareBase_Ditto_Text_1:
# 995 "data/maps/daycarebase/scripts.pory"
	.string "Ditto$"

DaycareBase_Ditto_Text_2:
# 997 "data/maps/daycarebase/scripts.pory"
	.string "Come back anytime!$"

DaycareBase_Ditto_Text_3:
# 1009 "data/maps/daycarebase/scripts.pory"
	.string "Ditto!\pYou can transform into any\nPokémon you defeat in battle!\pThis only applies to Pokémon\nnot already using Transform...\lLike other Dittos in disguise.\pPress the{SELECT_BUTTON} button to\naccess your transformation menu.\pYou can also view more information\nabout your transformations from\lthe Xforms option on the {START_BUTTON} menu.\pTo swap out your transformation\noptions, press the {L_BUTTON} button!$"

DaycareBase_Ditto_Text_4:
# 1021 "data/maps/daycarebase/scripts.pory"
	.string "Hello there fellow Ditto!\pDaycare Man asked you to get an Egg\nfor him, did he?\pWell, you're about to learn the\nsecret of how we Dittos are\lalways found holding Eggs.\pIt'll be quite the adventure!\pTalk to any of the Dittos around\nthe Daycare for some control tips,\lincluding me!$"
