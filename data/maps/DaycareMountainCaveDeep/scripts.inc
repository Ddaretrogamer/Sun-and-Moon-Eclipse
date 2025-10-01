DaycareMountainCaveDeep_MapScripts::
# 2 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycareMCD_OnTransition
	.byte 0


DaycareMCD_OnTransition::
# 6 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_MOUNTAIN_CAVE_DEEP
	end


Daycaremountaincavedeep_FindSuperPotion::
# 11 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	lock
# 12 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removeobject mcdpotion
# 13 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	giveitem ITEM_SUPER_POTION
# 14 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 15 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_ITEM_DAYCARE_MCD2
# 16 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end


DaycareMCD_FindLuckyEgg::
# 21 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	lock
# 22 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removeobject mcdegg
# 23 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 24 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 25 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_ITEM_DAYCARE_MCD1
# 26 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end


SphealDialog::
# 31 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_MARILL
	goto_if_ne SphealDialog_1
# 44 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	lock
# 45 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	faceplayer
# 46 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername SphealDialog_Text_0
# 47 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_SPHEAL, EMOTE_ELATED
# 48 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox SphealDialog_Text_2, MSGBOX_DEFAULT
# 48 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 49 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
# 50 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
	end

SphealDialog_1:
# 33 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	lock
# 34 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	faceplayer
# 35 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername SphealDialog_Text_0
# 36 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_SPHEAL, EMOTE_NORMAL
# 37 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox SphealDialog_Text_1, MSGBOX_DEFAULT
# 38 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 39 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 40 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end


EiscueDialog::
# 57 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	goto_if_unset FLAG_HIDE_EISCUE, EiscueDialog_1
	return

EiscueDialog_1:
# 59 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_RHYHORN
	goto_if_eq EiscueDialog_3
# 109 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	lock
# 110 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	faceplayer
# 111 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername EiscueDialog_Text_0
# 112 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_EISCUE, EMOTE_SAD
# 113 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox EiscueDialog_Text_1, MSGBOX_DEFAULT
# 114 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 115 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 116 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 117 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox EiscueDialog_Text_5, MSGBOX_DEFAULT
# 118 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 119 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 120 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end

EiscueDialog_3:
# 60 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	lock
# 61 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	faceplayer
# 62 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername EiscueDialog_Text_0
# 63 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_EISCUE, EMOTE_SAD
# 64 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox EiscueDialog_Text_1, MSGBOX_DEFAULT
# 65 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 66 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 67 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 68 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox EiscueDialog_Text_2, MSGBOX_YESNO
# 69 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 70 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EiscueDialog_6
# 103 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 104 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end

EiscueDialog_6:
# 72 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	fadenewbgm MUS_PMD_MOUNTAIN
# 73 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 74 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removeobject Eiscue
# 75 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_HIDE_EISCUE
# 76 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	playse SE_M_BRICK_BREAK
# 77 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	clearflag FLAG_SHOW_NOICE
# 78 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitse
# 79 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	addobject NoIce
# 80 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	applymovement NoIce, EiscueDialog_Movement_0
# 81 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmovement NoIce
# 82 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 83 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	playse SE_PIN
# 84 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	applymovement NoIce, Common_Movement_ExclamationMark
# 85 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmovement NoIce
# 86 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername EiscueDialog_Text_0
# 87 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_EISCUENOICE, EMOTE_NORMAL
# 88 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox EiscueDialog_Text_3, MSGBOX_DEFAULT
# 89 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 90 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 91 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 92 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 93 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername EiscueDialog_Text_0
# 94 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_EISCUENOICE, EMOTE_NORMAL
# 95 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox EiscueDialog_Text_4, MSGBOX_DEFAULT
# 96 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 97 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 98 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end


FreedEicscue::
# 128 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	lock
# 129 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	faceplayer
# 130 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername EiscueDialog_Text_0
# 131 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_EISCUENOICE, EMOTE_NORMAL
# 132 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox FreedEicscue_Text_0, MSGBOX_DEFAULT
# 133 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 134 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 135 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end


AlolanSandshrewDialog::
# 140 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	lock
# 141 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	faceplayer
# 142 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername AlolanSandshrewDialog_Text_0
# 143 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_ALOLANSANDSLASH, EMOTE_NORMAL
# 144 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox AlolanSandshrewDialog_Text_1, MSGBOX_DEFAULT
# 145 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 146 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 147 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end


DaycareMCDDittoOpenXforms::
# 154 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	lock
# 155 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	faceplayer
# 156 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	goto_if_set FLAG_DITTO_INTRO, DaycareMCDDittoOpenXforms_1
# 218 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername DaycareMCDDittoOpenXforms_Text_1
# 219 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 220 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox DaycareMCDDittoOpenXforms_Text_4, MSGBOX_DEFAULT
# 220 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 221 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_DITTO_INTRO
# 222 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 223 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 224 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end

DaycareMCDDittoOpenXforms_1:
# 158 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	goto_if_set FLAG_XFORMS_TALKED_TO_DITTO, DaycareMCDDittoOpenXforms_4
# 185 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername DaycareMCDDittoOpenXforms_Text_1
# 186 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 187 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox DaycareMCDDittoOpenXforms_Text_3, MSGBOX_DEFAULT
# 187 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 188 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_XFORMS_TALKED_TO_DITTO
# 189 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 190 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 191 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 192 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox DaycareMCDDittoOpenXforms_Text_0, MSGBOX_YESNO
# 193 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DaycareMCDDittoOpenXforms_10
# 203 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername DaycareMCDDittoOpenXforms_Text_1
# 204 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 205 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox DaycareMCDDittoOpenXforms_Text_2, MSGBOX_AUTOCLOSE
# 206 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 207 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 208 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 209 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 210 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end

DaycareMCDDittoOpenXforms_4:
# 160 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox DaycareMCDDittoOpenXforms_Text_0, MSGBOX_YESNO
# 161 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DaycareMCDDittoOpenXforms_7
# 173 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername DaycareMCDDittoOpenXforms_Text_1
# 174 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 175 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox DaycareMCDDittoOpenXforms_Text_2, MSGBOX_AUTOCLOSE
# 176 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 177 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 178 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 179 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 180 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end

DaycareMCDDittoOpenXforms_7:
# 163 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	dittotransform SPECIES_DITTO
# 164 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	special OpenPCMoveMons
# 165 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitstate
# 166 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 167 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 168 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end

DaycareMCDDittoOpenXforms_10:
# 195 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	dittotransform SPECIES_DITTO
# 196 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	special OpenPCMoveMons
# 197 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitstate
# 198 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end


ChanseyDaycareMCD::
# 231 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	lock
# 232 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	faceplayer
# 233 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	speakername ChanseyDaycareMCD_Text_0
# 234 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 235 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox ChanseyDaycareMCD_Text_1, MSGBOX_DEFAULT
# 236 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 237 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox ChanseyDaycareMCD_Text_2, MSGBOX_YESNO
# 238 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 239 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyDaycareMCD_1
# 269 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 270 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox ChanseyDaycareMCD_Text_5, MSGBOX_AUTOCLOSE
# 271 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 272 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 273 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end

ChanseyDaycareMCD_1:
# 241 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 242 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyDaycareMCD_4
# 259 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 260 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox ChanseyDaycareMCD_Text_4, MSGBOX_AUTOCLOSE
# 261 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 262 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removefieldmugshot
# 263 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end

ChanseyDaycareMCD_4:
# 244 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 245 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 246 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 247 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	playfanfare MUS_HEAL
# 248 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitfanfare
# 249 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	special HealPlayerParty
# 250 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 251 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	msgbox ChanseyDaycareMCD_Text_3, MSGBOX_AUTOCLOSE
# 252 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 253 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	waitmessage
# 254 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	release
	end


# 80 "data/maps/DaycareMountainCaveDeep/scripts.pory"
EiscueDialog_Movement_0:
# 80 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	face_player
	step_end

SphealDialog_Text_0:
# 35 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Spheal$"

SphealDialog_Text_1:
# 37 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "The water is much colder down here!\pThe beaches on the surface are too\nwarm for my taste.\pI just wish there were more round\nPokémon around here though...$"

SphealDialog_Text_2:
# 48 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Wow!\nYou're really round!\pJust like me!\pCan I tell you a secret?\pI once saw a Ditto carrying an\nEgg away from the beach in the\lOceanfront biome!\pThey must have gotten the Egg\nsomewhere around there!$"

EiscueDialog_Text_0:
# 62 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Eiscue$"

EiscueDialog_Text_1:
# 64 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Mmmmffff!\n$"

EiscueDialog_Text_2:
# 68 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "This Eiscue is having trouble\ncommunicating through the giant\lice cube on its head.\pWould you like to use Rock Smash?\n$"

EiscueDialog_Text_3:
# 88 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Goodness!\nThank you.\pI have been trying to get that\nice cube off my head forever!\pTake this as a token of my\nappreciation.$"

EiscueDialog_Text_4:
# 95 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "I think I might go for a swim now!\n$"

EiscueDialog_Text_5:
# 117 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "This Eiscue is having trouble\ncommunicating through the giant\lice cube on its head.$"

FreedEicscue_Text_0:
# 132 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Thank you again!\pI feel like I'm finally able\nto regain my balance.$"

AlolanSandshrewDialog_Text_0:
# 142 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Sandslash$"

AlolanSandshrewDialog_Text_1:
# 144 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "That Eiscue seems to be\nstruggling.\pI'm sure a Pokémon who can\nsmash rocks could smash that\lice cube.$"

DaycareMCDDittoOpenXforms_Text_0:
# 160 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Would you like to change out your\ntransformation options?$"

DaycareMCDDittoOpenXforms_Text_1:
# 173 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Ditto$"

DaycareMCDDittoOpenXforms_Text_2:
# 175 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Come back anytime!$"

DaycareMCDDittoOpenXforms_Text_3:
# 187 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Ditto!\pYou can only remember four\ntransformations at a time.\pWe Dittos can act as a way to\nswap out which transformations\lyou have active at anytime!\pYou'll find us scattered around\nthe Daycare.\pNow...\n$"

DaycareMCDDittoOpenXforms_Text_4:
# 220 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Hello there fellow Ditto!\pDaycare Man asked you to get an Egg\nfor him, did he?\pWell, you're about to learn the\nsecret of how we Dittos are\lalways found holding Eggs.\pIt'll be quite the adventure!\pDon't forget, you are a Ditto,\nso you can transform into any\lPokémon you defeat in battle!\pThis does only apply to Pokémon\nwho are not already using\lTransform...\pPress the {SELECT_BUTTON} button to\nopen your transformation menu.\pIf you open your Transformation\nParty, you'll see which Pokémon\lyou can transform into!$"

ChanseyDaycareMCD_Text_0:
# 233 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Chansey$"

ChanseyDaycareMCD_Text_1:
# 235 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyDaycareMCD_Text_2:
# 237 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Would you like to heal?$"

ChanseyDaycareMCD_Text_3:
# 251 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyDaycareMCD_Text_4:
# 260 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyDaycareMCD_Text_5:
# 270 "data/maps/DaycareMountainCaveDeep/scripts.pory"
	.string "Oh, okay then.$"
