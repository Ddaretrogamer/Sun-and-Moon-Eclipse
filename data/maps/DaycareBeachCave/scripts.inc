DaycareBeachCave_MapScripts::
	.byte 0


WiggletDialog::
# 6 "data/maps/DaycareBeachCave/scripts.pory"
	lock
# 7 "data/maps/DaycareBeachCave/scripts.pory"
	faceplayer
# 8 "data/maps/DaycareBeachCave/scripts.pory"
	speakername WiggletDialog_Text_0
# 9 "data/maps/DaycareBeachCave/scripts.pory"
	createfieldmugshot MUGSHOT_WIGGLET, EMOTE_NORMAL
# 10 "data/maps/DaycareBeachCave/scripts.pory"
	msgbox WiggletDialog_Text_1, MSGBOX_DEFAULT
# 11 "data/maps/DaycareBeachCave/scripts.pory"
	waitmessage
# 12 "data/maps/DaycareBeachCave/scripts.pory"
	removefieldmugshot
# 13 "data/maps/DaycareBeachCave/scripts.pory"
	release
	end


TotodiileDialog::
# 18 "data/maps/DaycareBeachCave/scripts.pory"
	lock
# 19 "data/maps/DaycareBeachCave/scripts.pory"
	applymovement Totodile, TotodiileDialog_Movement_0
# 20 "data/maps/DaycareBeachCave/scripts.pory"
	waitmovement Totodile
# 21 "data/maps/DaycareBeachCave/scripts.pory"
	playse SE_PIN
# 22 "data/maps/DaycareBeachCave/scripts.pory"
	applymovement Totodile, Common_Movement_ExclamationMark
# 23 "data/maps/DaycareBeachCave/scripts.pory"
	waitmovement Totodile
# 24 "data/maps/DaycareBeachCave/scripts.pory"
	speakername TotodiileDialog_Text_0
# 25 "data/maps/DaycareBeachCave/scripts.pory"
	createfieldmugshot MUGSHOT_TOTODILE, EMOTE_NORMAL
# 26 "data/maps/DaycareBeachCave/scripts.pory"
	msgbox TotodiileDialog_Text_1, MSGBOX_DEFAULT
# 27 "data/maps/DaycareBeachCave/scripts.pory"
	playse SE_PIN
# 28 "data/maps/DaycareBeachCave/scripts.pory"
	applymovement Totodile, Common_Movement_ExclamationMark
# 29 "data/maps/DaycareBeachCave/scripts.pory"
	waitmovement Totodile
# 30 "data/maps/DaycareBeachCave/scripts.pory"
	msgbox TotodiileDialog_Text_2, MSGBOX_DEFAULT
# 31 "data/maps/DaycareBeachCave/scripts.pory"
	waitmessage
# 32 "data/maps/DaycareBeachCave/scripts.pory"
	removefieldmugshot
# 33 "data/maps/DaycareBeachCave/scripts.pory"
	release
	end


ChinchouDialog::
# 39 "data/maps/DaycareBeachCave/scripts.pory"
	lock
# 40 "data/maps/DaycareBeachCave/scripts.pory"
	faceplayer
# 41 "data/maps/DaycareBeachCave/scripts.pory"
	goto_if_set FLAG_TRANS_CHINCHOU, ChinchouDialog_1
# 53 "data/maps/DaycareBeachCave/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 54 "data/maps/DaycareBeachCave/scripts.pory"
	applymovement Chinchou, TotodiileDialog_Movement_0
# 55 "data/maps/DaycareBeachCave/scripts.pory"
	waitmovement Chinchou
# 56 "data/maps/DaycareBeachCave/scripts.pory"
	playse SE_PIN
# 57 "data/maps/DaycareBeachCave/scripts.pory"
	applymovement Chinchou, Common_Movement_ExclamationMark
# 58 "data/maps/DaycareBeachCave/scripts.pory"
	waitmovement Chinchou
# 59 "data/maps/DaycareBeachCave/scripts.pory"
	speakername ChinchouDialog_Text_0
# 60 "data/maps/DaycareBeachCave/scripts.pory"
	createfieldmugshot MUGSHOT_CHINCHOU, EMOTE_HAPPY
# 61 "data/maps/DaycareBeachCave/scripts.pory"
	msgbox ChinchouDialog_Text_2, MSGBOX_DEFAULT
# 62 "data/maps/DaycareBeachCave/scripts.pory"
	waitmessage
# 63 "data/maps/DaycareBeachCave/scripts.pory"
	removefieldmugshot
# 64 "data/maps/DaycareBeachCave/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 65 "data/maps/DaycareBeachCave/scripts.pory"
	setflag FLAG_TRANS_CHINCHOU
# 66 "data/maps/DaycareBeachCave/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 67 "data/maps/DaycareBeachCave/scripts.pory"
	dittotransform SPECIES_CHINCHOU
# 68 "data/maps/DaycareBeachCave/scripts.pory"
	playse MUS_LEVEL_UP
# 69 "data/maps/DaycareBeachCave/scripts.pory"
	msgbox ChinchouDialog_Text_3, MSGBOX_DEFAULT
# 70 "data/maps/DaycareBeachCave/scripts.pory"
	waitmessage
# 71 "data/maps/DaycareBeachCave/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 72 "data/maps/DaycareBeachCave/scripts.pory"
	speakername ChinchouDialog_Text_0
# 73 "data/maps/DaycareBeachCave/scripts.pory"
	createfieldmugshot MUGSHOT_CHINCHOU, EMOTE_ELATED
# 74 "data/maps/DaycareBeachCave/scripts.pory"
	msgbox ChinchouDialog_Text_4, MSGBOX_AUTOCLOSE
# 75 "data/maps/DaycareBeachCave/scripts.pory"
	givemon SPECIES_CHINCHOU, 25, move1 = MOVE_THUNDER_WAVE, move2 = MOVE_DISCHARGE, move3 = MOVE_DIVE, move4 = MOVE_DAZZLING_GLEAM
# 76 "data/maps/DaycareBeachCave/scripts.pory"
	waitmessage
# 77 "data/maps/DaycareBeachCave/scripts.pory"
	dittotransform VAR_TEMP_0
# 78 "data/maps/DaycareBeachCave/scripts.pory"
	delay 30
# 79 "data/maps/DaycareBeachCave/scripts.pory"
	release
	end

ChinchouDialog_1:
# 43 "data/maps/DaycareBeachCave/scripts.pory"
	speakername ChinchouDialog_Text_0
# 44 "data/maps/DaycareBeachCave/scripts.pory"
	createfieldmugshot MUGSHOT_CHINCHOU, EMOTE_HAPPY
# 45 "data/maps/DaycareBeachCave/scripts.pory"
	msgbox ChinchouDialog_Text_1, MSGBOX_DEFAULT
# 46 "data/maps/DaycareBeachCave/scripts.pory"
	waitmessage
# 47 "data/maps/DaycareBeachCave/scripts.pory"
	removefieldmugshot
# 48 "data/maps/DaycareBeachCave/scripts.pory"
	release
	end


ChinchouTransformTrigger::
# 85 "data/maps/DaycareBeachCave/scripts.pory"
	goto_if_set FLAG_CHINCHOU_TRIGGER, ChinchouTransformTrigger_1
# 91 "data/maps/DaycareBeachCave/scripts.pory"
	goto_if_set FLAG_TRANS_CHINCHOU, ChinchouTransformTrigger_4
	return

ChinchouTransformTrigger_1:
	end

ChinchouTransformTrigger_4:
# 93 "data/maps/DaycareBeachCave/scripts.pory"
	lock
# 94 "data/maps/DaycareBeachCave/scripts.pory"
	special SpawnCameraObject
# 95 "data/maps/DaycareBeachCave/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 96 "data/maps/DaycareBeachCave/scripts.pory"
	dittotransform SPECIES_CHINCHOU
# 97 "data/maps/DaycareBeachCave/scripts.pory"
	delay 60
# 98 "data/maps/DaycareBeachCave/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, ChinchouTransformTrigger_Movement_0
# 99 "data/maps/DaycareBeachCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 100 "data/maps/DaycareBeachCave/scripts.pory"
	playse SE_PIN
# 101 "data/maps/DaycareBeachCave/scripts.pory"
	applymovement Chinchou, ChinchouTransformTrigger_Movement_1
# 102 "data/maps/DaycareBeachCave/scripts.pory"
	waitmovement Chinchou
# 103 "data/maps/DaycareBeachCave/scripts.pory"
	applymovement Chinchou, Common_Movement_ExclamationMark
# 104 "data/maps/DaycareBeachCave/scripts.pory"
	waitmovement Chinchou
# 105 "data/maps/DaycareBeachCave/scripts.pory"
	createfieldmugshot MUGSHOT_CHINCHOU, EMOTE_ELATED
# 106 "data/maps/DaycareBeachCave/scripts.pory"
	speakername ChinchouDialog_Text_0
# 107 "data/maps/DaycareBeachCave/scripts.pory"
	msgbox ChinchouTransformTrigger_Text_0, MSGBOX_AUTOCLOSE
# 108 "data/maps/DaycareBeachCave/scripts.pory"
	waitmessage
# 109 "data/maps/DaycareBeachCave/scripts.pory"
	removefieldmugshot
# 110 "data/maps/DaycareBeachCave/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, ChinchouTransformTrigger_Movement_2
# 111 "data/maps/DaycareBeachCave/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 112 "data/maps/DaycareBeachCave/scripts.pory"
	special RemoveCameraObject
# 113 "data/maps/DaycareBeachCave/scripts.pory"
	delay 30
# 114 "data/maps/DaycareBeachCave/scripts.pory"
	dittotransform VAR_TEMP_0
# 115 "data/maps/DaycareBeachCave/scripts.pory"
	setflag FLAG_CHINCHOU_TRIGGER
# 116 "data/maps/DaycareBeachCave/scripts.pory"
	release
	end


# 19 "data/maps/DaycareBeachCave/scripts.pory"
TotodiileDialog_Movement_0:
# 19 "data/maps/DaycareBeachCave/scripts.pory"
	face_player
	step_end

# 98 "data/maps/DaycareBeachCave/scripts.pory"
ChinchouTransformTrigger_Movement_0:
# 98 "data/maps/DaycareBeachCave/scripts.pory"
	walk_down
# 98 "data/maps/DaycareBeachCave/scripts.pory"
	walk_down
# 98 "data/maps/DaycareBeachCave/scripts.pory"
	walk_down
# 98 "data/maps/DaycareBeachCave/scripts.pory"
	walk_down
# 98 "data/maps/DaycareBeachCave/scripts.pory"
	walk_down
# 98 "data/maps/DaycareBeachCave/scripts.pory"
	walk_down
# 98 "data/maps/DaycareBeachCave/scripts.pory"
	walk_down
# 98 "data/maps/DaycareBeachCave/scripts.pory"
	walk_down
# 98 "data/maps/DaycareBeachCave/scripts.pory"
	walk_down
	step_end

# 101 "data/maps/DaycareBeachCave/scripts.pory"
ChinchouTransformTrigger_Movement_1:
# 101 "data/maps/DaycareBeachCave/scripts.pory"
	face_up
	step_end

# 110 "data/maps/DaycareBeachCave/scripts.pory"
ChinchouTransformTrigger_Movement_2:
# 110 "data/maps/DaycareBeachCave/scripts.pory"
	walk_up
# 110 "data/maps/DaycareBeachCave/scripts.pory"
	walk_up
# 110 "data/maps/DaycareBeachCave/scripts.pory"
	walk_up
# 110 "data/maps/DaycareBeachCave/scripts.pory"
	walk_up
# 110 "data/maps/DaycareBeachCave/scripts.pory"
	walk_up
# 110 "data/maps/DaycareBeachCave/scripts.pory"
	walk_up
# 110 "data/maps/DaycareBeachCave/scripts.pory"
	walk_up
# 110 "data/maps/DaycareBeachCave/scripts.pory"
	walk_up
# 110 "data/maps/DaycareBeachCave/scripts.pory"
	walk_up
	step_end

WiggletDialog_Text_0:
# 8 "data/maps/DaycareBeachCave/scripts.pory"
	.string "Wiglett$"

WiggletDialog_Text_1:
# 10 "data/maps/DaycareBeachCave/scripts.pory"
	.string "Pst!\nListen closely.\pYou're looking for an Egg, right?\pI've heard there's another\ntransforming Pokémon just like you\lwho holds the key to finding that\lEgg!$"

TotodiileDialog_Text_0:
# 24 "data/maps/DaycareBeachCave/scripts.pory"
	.string "Totodile$"

TotodiileDialog_Text_1:
# 26 "data/maps/DaycareBeachCave/scripts.pory"
	.string "Wah!\pHow'd you find this cave?\p...$"

TotodiileDialog_Text_2:
# 30 "data/maps/DaycareBeachCave/scripts.pory"
	.string "Did that Baltoy tip you off?\nI've been pretty good about\lsneaking in here.\pIt's been my private getaway...\nplease don't tell anyone about\lthis place.$"

ChinchouDialog_Text_0:
# 43 "data/maps/DaycareBeachCave/scripts.pory"
	.string "Chinchou$"

ChinchouDialog_Text_1:
# 45 "data/maps/DaycareBeachCave/scripts.pory"
	.string "As you near your goal, you\nbest prepare yourself.\pAn opponent much like yourself\nawaits.\pThis blue Pokémon has also\nmastered transformation.$"

ChinchouDialog_Text_2:
# 61 "data/maps/DaycareBeachCave/scripts.pory"
	.string "You must be the new Ditto.\pGreat job finding this cave!\pNo need to fear. I am not looking\nfor a fight.\pI think I could help on your\nadventure by lending you my diving\lablities.\pGo on, Ditto, use Transform!\n$"

ChinchouDialog_Text_3:
# 69 "data/maps/DaycareBeachCave/scripts.pory"
	.string "You have gained the ability to\ntransform into Chinchou!$"

ChinchouDialog_Text_4:
# 74 "data/maps/DaycareBeachCave/scripts.pory"
	.string "Wow!\pLooking more electric already!$"

ChinchouTransformTrigger_Text_0:
# 107 "data/maps/DaycareBeachCave/scripts.pory"
	.string "There it is!\pLooking more electric already!\n$"
