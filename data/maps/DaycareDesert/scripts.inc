DaycareDesert_MapScripts::
	.byte 0


CacneaDialog::
# 4 "data/maps/DaycareDesert/scripts.pory"
	lock
# 5 "data/maps/DaycareDesert/scripts.pory"
	speakername CacneaDialog_Text_0
# 6 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_CACNEA, EMOTE_NORMAL
# 7 "data/maps/DaycareDesert/scripts.pory"
	msgbox CacneaDialog_Text_1, MSGBOX_DEFAULT
# 8 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 9 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 10 "data/maps/DaycareDesert/scripts.pory"
	release
	end


TrapinchDialog::
# 15 "data/maps/DaycareDesert/scripts.pory"
	lock
# 16 "data/maps/DaycareDesert/scripts.pory"
	faceplayer
# 17 "data/maps/DaycareDesert/scripts.pory"
	goto_if_set FLAG_TRAPINCH_EGG, TrapinchDialog_2
# 40 "data/maps/DaycareDesert/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_RHYHORN
	goto_if_eq TrapinchDialog_4
# 56 "data/maps/DaycareDesert/scripts.pory"
	speakername TrapinchDialog_Text_0
# 57 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_TRAPINCH, EMOTE_NORMAL
# 58 "data/maps/DaycareDesert/scripts.pory"
	msgbox TrapinchDialog_Text_2, MSGBOX_DEFAULT
# 59 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 60 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 61 "data/maps/DaycareDesert/scripts.pory"
	release
	end

TrapinchDialog_2:
# 19 "data/maps/DaycareDesert/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_RHYHORN
	goto_if_eq TrapinchDialog_7
# 31 "data/maps/DaycareDesert/scripts.pory"
	speakername TrapinchDialog_Text_0
# 32 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_TRAPINCH, EMOTE_NORMAL
# 33 "data/maps/DaycareDesert/scripts.pory"
	msgbox TrapinchDialog_Text_2, MSGBOX_DEFAULT
# 34 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 35 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 36 "data/maps/DaycareDesert/scripts.pory"
	release
	end

TrapinchDialog_4:
# 42 "data/maps/DaycareDesert/scripts.pory"
	speakername TrapinchDialog_Text_0
# 43 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_TRAPINCH, EMOTE_HAPPY
# 44 "data/maps/DaycareDesert/scripts.pory"
	msgbox TrapinchDialog_Text_3, MSGBOX_DEFAULT
# 45 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 46 "data/maps/DaycareDesert/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 47 "data/maps/DaycareDesert/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 48 "data/maps/DaycareDesert/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 49 "data/maps/DaycareDesert/scripts.pory"
	setflag FLAG_TRAPINCH_EGG
# 50 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 51 "data/maps/DaycareDesert/scripts.pory"
	release
	end

TrapinchDialog_7:
# 21 "data/maps/DaycareDesert/scripts.pory"
	speakername TrapinchDialog_Text_0
# 22 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_TRAPINCH, EMOTE_HAPPY
# 23 "data/maps/DaycareDesert/scripts.pory"
	msgbox TrapinchDialog_Text_1, MSGBOX_DEFAULT
# 24 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 25 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 26 "data/maps/DaycareDesert/scripts.pory"
	release
	end


StunfiskDialog::
# 68 "data/maps/DaycareDesert/scripts.pory"
	goto_if_unset FLAG_STUNFISK_EGG, StunfiskDialog_1
# 90 "data/maps/DaycareDesert/scripts.pory"
	lock
# 91 "data/maps/DaycareDesert/scripts.pory"
	faceplayer
# 92 "data/maps/DaycareDesert/scripts.pory"
	speakername StunfiskDialog_Text_0
# 93 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_STUNFISH, EMOTE_NORMAL
# 94 "data/maps/DaycareDesert/scripts.pory"
	msgbox StunfiskDialog_Text_2, MSGBOX_DEFAULT
# 95 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 96 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 97 "data/maps/DaycareDesert/scripts.pory"
	release
	end

StunfiskDialog_1:
# 70 "data/maps/DaycareDesert/scripts.pory"
	lock
# 71 "data/maps/DaycareDesert/scripts.pory"
	faceplayer
# 72 "data/maps/DaycareDesert/scripts.pory"
	speakername StunfiskDialog_Text_0
# 73 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_STUNFISH, EMOTE_NORMAL
# 74 "data/maps/DaycareDesert/scripts.pory"
	msgbox StunfiskDialog_Text_1, MSGBOX_DEFAULT
# 75 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 76 "data/maps/DaycareDesert/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 77 "data/maps/DaycareDesert/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 78 "data/maps/DaycareDesert/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 79 "data/maps/DaycareDesert/scripts.pory"
	speakername StunfiskDialog_Text_0
# 80 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_STUNFISH, EMOTE_NORMAL
# 81 "data/maps/DaycareDesert/scripts.pory"
	msgbox StunfiskDialog_Text_2, MSGBOX_DEFAULT
# 82 "data/maps/DaycareDesert/scripts.pory"
	setflag FLAG_STUNFISK_EGG
# 83 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 84 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 85 "data/maps/DaycareDesert/scripts.pory"
	release
	end


BaltoyDialog::
# 103 "data/maps/DaycareDesert/scripts.pory"
	lock
# 104 "data/maps/DaycareDesert/scripts.pory"
	faceplayer
# 105 "data/maps/DaycareDesert/scripts.pory"
	speakername BaltoyDialog_Text_0
# 106 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_BALTOY, EMOTE_NORMAL
# 107 "data/maps/DaycareDesert/scripts.pory"
	msgbox BaltoyDialog_Text_1, MSGBOX_DEFAULT
# 108 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 109 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 110 "data/maps/DaycareDesert/scripts.pory"
	release
	end


SandshrewDialog::
# 115 "data/maps/DaycareDesert/scripts.pory"
	lock
# 116 "data/maps/DaycareDesert/scripts.pory"
	faceplayer
# 117 "data/maps/DaycareDesert/scripts.pory"
	speakername SandshrewDialog_Text_0
# 118 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_SANDSHREW, EMOTE_NORMAL
# 119 "data/maps/DaycareDesert/scripts.pory"
	msgbox SandshrewDialog_Text_1, MSGBOX_DEFAULT
# 120 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 121 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 122 "data/maps/DaycareDesert/scripts.pory"
	release
	end


VibravaDialog::
# 127 "data/maps/DaycareDesert/scripts.pory"
	lock
# 128 "data/maps/DaycareDesert/scripts.pory"
	faceplayer
# 129 "data/maps/DaycareDesert/scripts.pory"
	speakername VibravaDialog_Text_0
# 130 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_VIBRAVA, EMOTE_NORMAL
# 131 "data/maps/DaycareDesert/scripts.pory"
	msgbox VibravaDialog_Text_1, MSGBOX_NPC
# 132 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 133 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 134 "data/maps/DaycareDesert/scripts.pory"
	release
	end


RhyhornDialog::
# 139 "data/maps/DaycareDesert/scripts.pory"
	lock
# 140 "data/maps/DaycareDesert/scripts.pory"
	faceplayer
# 141 "data/maps/DaycareDesert/scripts.pory"
	goto_if_set FLAG_TRANS_RYHORN, RhyhornDialog_1
# 153 "data/maps/DaycareDesert/scripts.pory"
	lock
# 154 "data/maps/DaycareDesert/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 155 "data/maps/DaycareDesert/scripts.pory"
	applymovement Rhyhorn, RhyhornDialog_Movement_0
# 156 "data/maps/DaycareDesert/scripts.pory"
	waitmovement Rhyhorn
# 157 "data/maps/DaycareDesert/scripts.pory"
	playse SE_PIN
# 158 "data/maps/DaycareDesert/scripts.pory"
	applymovement Rhyhorn, Common_Movement_ExclamationMark
# 159 "data/maps/DaycareDesert/scripts.pory"
	waitmovement Rhyhorn
# 160 "data/maps/DaycareDesert/scripts.pory"
	speakername RhyhornDialog_Text_0
# 161 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_RHYHORN, EMOTE_HAPPY
# 162 "data/maps/DaycareDesert/scripts.pory"
	msgbox RhyhornDialog_Text_2, MSGBOX_DEFAULT
# 163 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 164 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 165 "data/maps/DaycareDesert/scripts.pory"
	lock
# 166 "data/maps/DaycareDesert/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 167 "data/maps/DaycareDesert/scripts.pory"
	setflag FLAG_TRANS_RYHORN
# 168 "data/maps/DaycareDesert/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 169 "data/maps/DaycareDesert/scripts.pory"
	dittotransform SPECIES_RHYHORN
# 170 "data/maps/DaycareDesert/scripts.pory"
	playse MUS_LEVEL_UP
# 171 "data/maps/DaycareDesert/scripts.pory"
	msgbox RhyhornDialog_Text_3, MSGBOX_DEFAULT
# 172 "data/maps/DaycareDesert/scripts.pory"
	waitse
# 173 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 174 "data/maps/DaycareDesert/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 175 "data/maps/DaycareDesert/scripts.pory"
	speakername RhyhornDialog_Text_0
# 176 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_RHYHORN, EMOTE_ELATED
# 177 "data/maps/DaycareDesert/scripts.pory"
	msgbox RhyhornDialog_Text_4, MSGBOX_DEFAULT
# 178 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 179 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 180 "data/maps/DaycareDesert/scripts.pory"
	lock
# 181 "data/maps/DaycareDesert/scripts.pory"
	dittotransform VAR_TEMP_0
# 182 "data/maps/DaycareDesert/scripts.pory"
	givemon SPECIES_RHYHORN, 25, move1 = MOVE_ROCK_THROW, move2 = MOVE_HORN_ATTACK, move3 = MOVE_ROCK_POLISH, move4 = MOVE_ROCK_SMASH
# 183 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 184 "data/maps/DaycareDesert/scripts.pory"
	fadenewbgm MUS_PMD_DESERT
# 185 "data/maps/DaycareDesert/scripts.pory"
	delay 30
# 186 "data/maps/DaycareDesert/scripts.pory"
	speakername RhyhornDialog_Text_0
# 187 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_RHYHORN, EMOTE_NORMAL
# 188 "data/maps/DaycareDesert/scripts.pory"
	msgbox RhyhornDialog_Text_1, MSGBOX_DEFAULT
# 189 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 190 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 191 "data/maps/DaycareDesert/scripts.pory"
	release
	end

RhyhornDialog_1:
# 143 "data/maps/DaycareDesert/scripts.pory"
	speakername RhyhornDialog_Text_0
# 144 "data/maps/DaycareDesert/scripts.pory"
	createfieldmugshot MUGSHOT_RHYHORN, EMOTE_NORMAL
# 145 "data/maps/DaycareDesert/scripts.pory"
	msgbox RhyhornDialog_Text_1, MSGBOX_DEFAULT
# 146 "data/maps/DaycareDesert/scripts.pory"
	waitmessage
# 147 "data/maps/DaycareDesert/scripts.pory"
	removefieldmugshot
# 148 "data/maps/DaycareDesert/scripts.pory"
	release
	end


# 155 "data/maps/DaycareDesert/scripts.pory"
RhyhornDialog_Movement_0:
# 155 "data/maps/DaycareDesert/scripts.pory"
	face_player
	step_end

CacneaDialog_Text_0:
# 5 "data/maps/DaycareDesert/scripts.pory"
	.string "Cacnea$"

CacneaDialog_Text_1:
# 7 "data/maps/DaycareDesert/scripts.pory"
	.string "Don't blow my cover.\pThey totally think I'm a plant.\n$"

TrapinchDialog_Text_0:
# 21 "data/maps/DaycareDesert/scripts.pory"
	.string "Trapinch$"

TrapinchDialog_Text_1:
# 23 "data/maps/DaycareDesert/scripts.pory"
	.string "Oh, hey Rhyhorn!\pBeautiful weather today isn't it?$"

TrapinchDialog_Text_2:
# 33 "data/maps/DaycareDesert/scripts.pory"
	.string "Don't even think about coming near\nmy sand pit!$"

TrapinchDialog_Text_3:
# 44 "data/maps/DaycareDesert/scripts.pory"
	.string "Oh, hey Rhyhorn!\pBeautiful weather today isn't it?\pThis fell into my sandtrap the\nother day...\pWhy don't you take it?\n$"

StunfiskDialog_Text_0:
# 72 "data/maps/DaycareDesert/scripts.pory"
	.string "Stunfisk$"

StunfiskDialog_Text_1:
# 74 "data/maps/DaycareDesert/scripts.pory"
	.string "You found me!\pHere, take this.\n$"

StunfiskDialog_Text_2:
# 81 "data/maps/DaycareDesert/scripts.pory"
	.string "Not many Pokémon know how to\nsurf in the desert.$"

BaltoyDialog_Text_0:
# 105 "data/maps/DaycareDesert/scripts.pory"
	.string "Baltoy$"

BaltoyDialog_Text_1:
# 107 "data/maps/DaycareDesert/scripts.pory"
	.string "I've heard there is a secret cave\nsomewhere here in the desert.\pRumor has it that a Pokémon\nneeds to know a move not many\ldesert Pokémon can learn...$"

SandshrewDialog_Text_0:
# 117 "data/maps/DaycareDesert/scripts.pory"
	.string "Sandshrew$"

SandshrewDialog_Text_1:
# 119 "data/maps/DaycareDesert/scripts.pory"
	.string "Rhyhorn may have a tough exterior,\nbut he is the nicest Pokémon in\lthe desert!\pHe's a pacifist and doesn't like\nto battle.\pHe's great friends with Trapinch\nwho can be feisty.$"

VibravaDialog_Text_0:
# 129 "data/maps/DaycareDesert/scripts.pory"
	.string "Vibrava$"

VibravaDialog_Text_1:
# 131 "data/maps/DaycareDesert/scripts.pory"
	.string "Surf?\pNever heard of it.\pI just fly over water.\n$"

RhyhornDialog_Text_0:
# 143 "data/maps/DaycareDesert/scripts.pory"
	.string "Rhyhorn$"

RhyhornDialog_Text_1:
# 145 "data/maps/DaycareDesert/scripts.pory"
	.string "Keep on trucking little Ditto!\pHead over and see my old friend\nCutiefly.\pShe loves flowers.\n$"

RhyhornDialog_Text_2:
# 162 "data/maps/DaycareDesert/scripts.pory"
	.string "Hey there little Ditto!\pI'm not much of a fighter, but\nI can see that you're determined!\pYou could probaby get some use out\nof my armor plated exterior...\pTell you what.\pWhy don't you transform into me,\nthat way you make use of my\lstrength!$"

RhyhornDialog_Text_3:
# 171 "data/maps/DaycareDesert/scripts.pory"
	.string "You have gained the ability to\ntransform into Rhyhorn!$"

RhyhornDialog_Text_4:
# 177 "data/maps/DaycareDesert/scripts.pory"
	.string "Ho_ho!\pLooking tougher already!\n$"
