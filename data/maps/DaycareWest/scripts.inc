DaycareWest_MapScripts::
# 2 "data/maps/DaycareWest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycareWest_OnTransition
	.byte 0


DaycareWest_OnTransition::
# 6 "data/maps/DaycareWest/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_WEST
	end


ChanseyDaycareWestHeal::
# 12 "data/maps/DaycareWest/scripts.pory"
	lock
# 13 "data/maps/DaycareWest/scripts.pory"
	faceplayer
# 14 "data/maps/DaycareWest/scripts.pory"
	speakername ChanseyDaycareWestHeal_Text_0
# 15 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 16 "data/maps/DaycareWest/scripts.pory"
	msgbox ChanseyDaycareWestHeal_Text_1, MSGBOX_DEFAULT
# 17 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 18 "data/maps/DaycareWest/scripts.pory"
	msgbox ChanseyDaycareWestHeal_Text_2, MSGBOX_YESNO
# 19 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 20 "data/maps/DaycareWest/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyDaycareWestHeal_1
# 50 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 51 "data/maps/DaycareWest/scripts.pory"
	msgbox ChanseyDaycareWestHeal_Text_5, MSGBOX_AUTOCLOSE
# 52 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 53 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 54 "data/maps/DaycareWest/scripts.pory"
	release
	end

ChanseyDaycareWestHeal_1:
# 22 "data/maps/DaycareWest/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 23 "data/maps/DaycareWest/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyDaycareWestHeal_4
# 40 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 41 "data/maps/DaycareWest/scripts.pory"
	msgbox ChanseyDaycareWestHeal_Text_4, MSGBOX_AUTOCLOSE
# 42 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 43 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 44 "data/maps/DaycareWest/scripts.pory"
	release
	end

ChanseyDaycareWestHeal_4:
# 25 "data/maps/DaycareWest/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 26 "data/maps/DaycareWest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 27 "data/maps/DaycareWest/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 28 "data/maps/DaycareWest/scripts.pory"
	playfanfare MUS_HEAL
# 29 "data/maps/DaycareWest/scripts.pory"
	waitfanfare
# 30 "data/maps/DaycareWest/scripts.pory"
	special HealPlayerParty
# 31 "data/maps/DaycareWest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 32 "data/maps/DaycareWest/scripts.pory"
	msgbox ChanseyDaycareWestHeal_Text_3, MSGBOX_AUTOCLOSE
# 33 "data/maps/DaycareWest/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 34 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 35 "data/maps/DaycareWest/scripts.pory"
	release
	end


DaycareWestDittoOpenXforms::
# 61 "data/maps/DaycareWest/scripts.pory"
	lock
# 62 "data/maps/DaycareWest/scripts.pory"
	faceplayer
# 63 "data/maps/DaycareWest/scripts.pory"
	goto_if_set FLAG_DITTO_INTRO, DaycareWestDittoOpenXforms_1
# 103 "data/maps/DaycareWest/scripts.pory"
	speakername DaycareWestDittoOpenXforms_Text_1
# 104 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 105 "data/maps/DaycareWest/scripts.pory"
	msgbox DaycareWestDittoOpenXforms_Text_4, MSGBOX_DEFAULT
# 106 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 107 "data/maps/DaycareWest/scripts.pory"
	setflag FLAG_DITTO_INTRO
# 108 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 109 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 110 "data/maps/DaycareWest/scripts.pory"
	release
	end

DaycareWestDittoOpenXforms_1:
# 65 "data/maps/DaycareWest/scripts.pory"
	goto_if_set FLAG_XFORMS_TALKED_TO_DITTO, DaycareWestDittoOpenXforms_4
# 91 "data/maps/DaycareWest/scripts.pory"
	speakername DaycareWestDittoOpenXforms_Text_1
# 92 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 93 "data/maps/DaycareWest/scripts.pory"
	msgbox DaycareWestDittoOpenXforms_Text_3, MSGBOX_DEFAULT
# 94 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 95 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 96 "data/maps/DaycareWest/scripts.pory"
	release
	end

DaycareWestDittoOpenXforms_4:
# 67 "data/maps/DaycareWest/scripts.pory"
	msgbox DaycareWestDittoOpenXforms_Text_0, MSGBOX_YESNO
# 68 "data/maps/DaycareWest/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DaycareWestDittoOpenXforms_7
# 79 "data/maps/DaycareWest/scripts.pory"
	speakername DaycareWestDittoOpenXforms_Text_1
# 80 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 81 "data/maps/DaycareWest/scripts.pory"
	msgbox DaycareWestDittoOpenXforms_Text_2, MSGBOX_AUTOCLOSE
# 82 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 83 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 84 "data/maps/DaycareWest/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 85 "data/maps/DaycareWest/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 86 "data/maps/DaycareWest/scripts.pory"
	release
	end

DaycareWestDittoOpenXforms_7:
# 70 "data/maps/DaycareWest/scripts.pory"
	dittotransform SPECIES_DITTO
# 71 "data/maps/DaycareWest/scripts.pory"
	special OpenPCMoveMons
# 72 "data/maps/DaycareWest/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 73 "data/maps/DaycareWest/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 74 "data/maps/DaycareWest/scripts.pory"
	release
	end


ApplinDialog::
# 118 "data/maps/DaycareWest/scripts.pory"
	lock
# 119 "data/maps/DaycareWest/scripts.pory"
	faceplayer
# 120 "data/maps/DaycareWest/scripts.pory"
	speakername ApplinDialog_Text_0
# 121 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_APPLIN, EMOTE_NORMAL
# 122 "data/maps/DaycareWest/scripts.pory"
	msgbox ApplinDialog_Text_1, MSGBOX_DEFAULT
# 123 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 124 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 125 "data/maps/DaycareWest/scripts.pory"
	release
	end


SurskitDialog::
# 130 "data/maps/DaycareWest/scripts.pory"
	lock
# 131 "data/maps/DaycareWest/scripts.pory"
	faceplayer
# 132 "data/maps/DaycareWest/scripts.pory"
	speakername SurskitDialog_Text_0
# 133 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_SURSKIT, EMOTE_HAPPY
# 134 "data/maps/DaycareWest/scripts.pory"
	msgbox SurskitDialog_Text_1, MSGBOX_NPC
# 135 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 136 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 137 "data/maps/DaycareWest/scripts.pory"
	release
	end


MasquerainDialog::
# 142 "data/maps/DaycareWest/scripts.pory"
	lock
# 143 "data/maps/DaycareWest/scripts.pory"
	faceplayer
# 144 "data/maps/DaycareWest/scripts.pory"
	speakername MasquerainDialog_Text_0
# 145 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_MASQUERAIN, EMOTE_NORMAL
# 146 "data/maps/DaycareWest/scripts.pory"
	msgbox MasquerainDialog_Text_1, MSGBOX_NPC
# 147 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 148 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 149 "data/maps/DaycareWest/scripts.pory"
	release
	end


BattleVsCutiefly::
# 154 "data/maps/DaycareWest/scripts.pory"
	lock
# 155 "data/maps/DaycareWest/scripts.pory"
	applymovement Cutiefly, BattleVsCutiefly_Movement_0
# 156 "data/maps/DaycareWest/scripts.pory"
	waitmovement Cutiefly
# 157 "data/maps/DaycareWest/scripts.pory"
	goto_if_unset FLAG_TRANS_RYHORN, BattleVsCutiefly_2
# 167 "data/maps/DaycareWest/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq BattleVsCutiefly_3
# 177 "data/maps/DaycareWest/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, BattleVsCutiefly_4
# 187 "data/maps/DaycareWest/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 188 "data/maps/DaycareWest/scripts.pory"
	playse SE_PIN
# 189 "data/maps/DaycareWest/scripts.pory"
	applymovement Cutiefly, Common_Movement_ExclamationMark
# 190 "data/maps/DaycareWest/scripts.pory"
	waitmovement Cutiefly
# 191 "data/maps/DaycareWest/scripts.pory"
	speakername BattleVsCutiefly_Text_0
# 192 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_CUTIEFLY, EMOTE_NORMAL
# 193 "data/maps/DaycareWest/scripts.pory"
	msgbox BattleVsCutiefly_Text_3, MSGBOX_AUTOCLOSE
# 194 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 195 "data/maps/DaycareWest/scripts.pory"
	setwildbattle SPECIES_CUTIEFLY, 25
# 196 "data/maps/DaycareWest/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 0, 0
# 197 "data/maps/DaycareWest/scripts.pory"
	dowildbattle
# 198 "data/maps/DaycareWest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 199 "data/maps/DaycareWest/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleVsCutiefly_8
	return

BattleVsCutiefly_2:
# 159 "data/maps/DaycareWest/scripts.pory"
	speakername BattleVsCutiefly_Text_0
# 160 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_CUTIEFLY, EMOTE_NORMAL
# 161 "data/maps/DaycareWest/scripts.pory"
	msgbox BattleVsCutiefly_Text_1, MSGBOX_DEFAULT
# 162 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 163 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 164 "data/maps/DaycareWest/scripts.pory"
	release
	end

BattleVsCutiefly_3:
# 169 "data/maps/DaycareWest/scripts.pory"
	speakername BattleVsCutiefly_Text_0
# 170 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_CUTIEFLY, EMOTE_NORMAL
# 171 "data/maps/DaycareWest/scripts.pory"
	msgbox BattleVsCutiefly_Text_1, MSGBOX_DEFAULT
# 172 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 173 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 174 "data/maps/DaycareWest/scripts.pory"
	release
	end

BattleVsCutiefly_4:
# 179 "data/maps/DaycareWest/scripts.pory"
	speakername BattleVsCutiefly_Text_0
# 180 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_CUTIEFLY, EMOTE_NORMAL
# 181 "data/maps/DaycareWest/scripts.pory"
	msgbox BattleVsCutiefly_Text_2, MSGBOX_DEFAULT
# 182 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 183 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 184 "data/maps/DaycareWest/scripts.pory"
	release
	end

BattleVsCutiefly_8:
# 201 "data/maps/DaycareWest/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 202 "data/maps/DaycareWest/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 203 "data/maps/DaycareWest/scripts.pory"
	setflag FLAG_TRANS_CUTIEFLY
# 204 "data/maps/DaycareWest/scripts.pory"
	delay 15
# 205 "data/maps/DaycareWest/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 206 "data/maps/DaycareWest/scripts.pory"
	playse MUS_LEVEL_UP
# 207 "data/maps/DaycareWest/scripts.pory"
	msgbox BattleVsCutiefly_Text_4, MSGBOX_DEFAULT
# 208 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 209 "data/maps/DaycareWest/scripts.pory"
	dittotransform VAR_TEMP_0
# 210 "data/maps/DaycareWest/scripts.pory"
	givemon SPECIES_CUTIEFLY, 25, move1 = MOVE_BUG_BUZZ, move2 = MOVE_DAZZLING_GLEAM, move3 = MOVE_STICKY_WEB, move4 = MOVE_PSYCHIC
# 211 "data/maps/DaycareWest/scripts.pory"
	speakername BattleVsCutiefly_Text_0
# 212 "data/maps/DaycareWest/scripts.pory"
	createfieldmugshot MUGSHOT_CUTIEFLY, EMOTE_HAPPY
# 213 "data/maps/DaycareWest/scripts.pory"
	msgbox BattleVsCutiefly_Text_2, MSGBOX_DEFAULT
# 214 "data/maps/DaycareWest/scripts.pory"
	waitmessage
# 215 "data/maps/DaycareWest/scripts.pory"
	removefieldmugshot
# 216 "data/maps/DaycareWest/scripts.pory"
	fadenewbgm MUS_PMD_HEARTWARMING
# 217 "data/maps/DaycareWest/scripts.pory"
	release
	end


# 155 "data/maps/DaycareWest/scripts.pory"
BattleVsCutiefly_Movement_0:
# 155 "data/maps/DaycareWest/scripts.pory"
	face_player
	step_end

ChanseyDaycareWestHeal_Text_0:
# 14 "data/maps/DaycareWest/scripts.pory"
	.string "Chansey$"

ChanseyDaycareWestHeal_Text_1:
# 16 "data/maps/DaycareWest/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyDaycareWestHeal_Text_2:
# 18 "data/maps/DaycareWest/scripts.pory"
	.string "Would you like to heal?$"

ChanseyDaycareWestHeal_Text_3:
# 32 "data/maps/DaycareWest/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyDaycareWestHeal_Text_4:
# 41 "data/maps/DaycareWest/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyDaycareWestHeal_Text_5:
# 51 "data/maps/DaycareWest/scripts.pory"
	.string "Oh, okay then.$"

DaycareWestDittoOpenXforms_Text_0:
# 67 "data/maps/DaycareWest/scripts.pory"
	.string "Would you like to change out your\ntransformation options?$"

DaycareWestDittoOpenXforms_Text_1:
# 79 "data/maps/DaycareWest/scripts.pory"
	.string "Ditto$"

DaycareWestDittoOpenXforms_Text_2:
# 81 "data/maps/DaycareWest/scripts.pory"
	.string "Come back anytime!$"

DaycareWestDittoOpenXforms_Text_3:
# 93 "data/maps/DaycareWest/scripts.pory"
	.string "Ditto!\pYou can transform into any\nPokémon you defeat in battle!\pThis only applies to Pokémon\nnot already using Transform...\lLike other Dittos in disguise.\pPress the{SELECT_BUTTON} button to\naccess your transformation menu.\pYou can also view more information\nabout your transformations from\lthe Xforms option on the {START_BUTTON} menu.\pTo swap out your transformation\noptions, press the {L_BUTTON} button!$"

DaycareWestDittoOpenXforms_Text_4:
# 105 "data/maps/DaycareWest/scripts.pory"
	.string "Hello there fellow Ditto!\pDaycare Man asked you to get an Egg\nfor him, did he?\pWell, you're about to learn the\nsecret of how we Dittos are\lalways found holding Eggs.\pIt'll be quite the adventure!\pTalk to any of the Dittos around\nthe Daycare for some control tips,\lincluding me!$"

ApplinDialog_Text_0:
# 120 "data/maps/DaycareWest/scripts.pory"
	.string "Applin$"

ApplinDialog_Text_1:
# 122 "data/maps/DaycareWest/scripts.pory"
	.string "The Daycare Woman is so kind.\pShe carried me around until I\nfound my favorite tree.\pNow I can hang out here all day!\n$"

SurskitDialog_Text_0:
# 132 "data/maps/DaycareWest/scripts.pory"
	.string "Surskit$"

SurskitDialog_Text_1:
# 134 "data/maps/DaycareWest/scripts.pory"
	.string "I'm not sure when my trainer is\ncoming back, but I don't mind!\pThe pondskipping here is radical!\n$"

MasquerainDialog_Text_0:
# 144 "data/maps/DaycareWest/scripts.pory"
	.string "Masquerain$"

MasquerainDialog_Text_1:
# 146 "data/maps/DaycareWest/scripts.pory"
	.string "Bro!\pI wish my trainer didn't evolve me\nbefore dropping me off.\pSurskit has been skipping up the\npond and I'm mad jealous.$"

BattleVsCutiefly_Text_0:
# 159 "data/maps/DaycareWest/scripts.pory"
	.string "Cutiefly$"

BattleVsCutiefly_Text_1:
# 161 "data/maps/DaycareWest/scripts.pory"
	.string "Being tiny is great!\p...Unless you visit a biome\nlike the desert.\pThe winds are a bit too harsh\nfor a Pokémon of my size.\pThat just makes me think of how\nI miss my friend Rhyhorn...$"

BattleVsCutiefly_Text_2:
# 181 "data/maps/DaycareWest/scripts.pory"
	.string "I'll stick to my flowers.\pBe on the lookout for places only a\ntiny Pokémon can squeeze through!$"

BattleVsCutiefly_Text_3:
# 193 "data/maps/DaycareWest/scripts.pory"
	.string "Welcome to the flower patch big\nfriend!\pSometimes it pays to be small!\pBeat me here on my home turf\nand you too can transform to be\lminiature.$"

BattleVsCutiefly_Text_4:
# 207 "data/maps/DaycareWest/scripts.pory"
	.string "You have gained the ability to\ntransform into Cutiefly!$"
