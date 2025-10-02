DaycareMew_MapScripts::
# 2 "data/maps/DaycareMew/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycareMew_OnTransition
	.byte 0


DaycareMew_OnTransition::
# 6 "data/maps/DaycareMew/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_MEW
	end


DittoEnd::
# 12 "data/maps/DaycareMew/scripts.pory"
	goto_if_unset FLAG_BEAT_MEW, DittoEnd_1
# 46 "data/maps/DaycareMew/scripts.pory"
	lock
# 47 "data/maps/DaycareMew/scripts.pory"
	faceplayer
# 48 "data/maps/DaycareMew/scripts.pory"
	speakername DittoEnd_Text_0
# 49 "data/maps/DaycareMew/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_HAPPY
# 50 "data/maps/DaycareMew/scripts.pory"
	msgbox DittoEnd_Text_3, MSGBOX_DEFAULT
# 51 "data/maps/DaycareMew/scripts.pory"
	waitmessage
# 52 "data/maps/DaycareMew/scripts.pory"
	removefieldmugshot
# 53 "data/maps/DaycareMew/scripts.pory"
	release
	end

DittoEnd_1:
# 14 "data/maps/DaycareMew/scripts.pory"
	goto_if_unset FLAG_DITTO_SITRUS, DittoEnd_4
# 32 "data/maps/DaycareMew/scripts.pory"
	lock
# 33 "data/maps/DaycareMew/scripts.pory"
	faceplayer
# 34 "data/maps/DaycareMew/scripts.pory"
	speakername DittoEnd_Text_0
# 35 "data/maps/DaycareMew/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 36 "data/maps/DaycareMew/scripts.pory"
	msgbox DittoEnd_Text_2, MSGBOX_AUTOCLOSE
# 37 "data/maps/DaycareMew/scripts.pory"
	removefieldmugshot
# 38 "data/maps/DaycareMew/scripts.pory"
	waitmessage
# 39 "data/maps/DaycareMew/scripts.pory"
	release
	end

DittoEnd_4:
# 16 "data/maps/DaycareMew/scripts.pory"
	lock
# 17 "data/maps/DaycareMew/scripts.pory"
	faceplayer
# 18 "data/maps/DaycareMew/scripts.pory"
	speakername DittoEnd_Text_0
# 19 "data/maps/DaycareMew/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 20 "data/maps/DaycareMew/scripts.pory"
	msgbox DittoEnd_Text_1, MSGBOX_DEFAULT
# 21 "data/maps/DaycareMew/scripts.pory"
	removefieldmugshot
# 22 "data/maps/DaycareMew/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 23 "data/maps/DaycareMew/scripts.pory"
	giveitem ITEM_SUPER_POTION, 5
# 24 "data/maps/DaycareMew/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 25 "data/maps/DaycareMew/scripts.pory"
	setflag FLAG_DITTO_SITRUS
# 26 "data/maps/DaycareMew/scripts.pory"
	waitmessage
# 27 "data/maps/DaycareMew/scripts.pory"
	release
	end


DittoEndTrigger::
# 61 "data/maps/DaycareMew/scripts.pory"
	goto_if_unset FLAG_DITTO_SITRUS, DittoEndTrigger_1
	end

DittoEndTrigger_1:
# 63 "data/maps/DaycareMew/scripts.pory"
	lock
# 64 "data/maps/DaycareMew/scripts.pory"
	playse SE_PIN
# 65 "data/maps/DaycareMew/scripts.pory"
	applymovement DittoFinale, Common_Movement_ExclamationMark
# 66 "data/maps/DaycareMew/scripts.pory"
	waitmovement DittoFinale
# 67 "data/maps/DaycareMew/scripts.pory"
	applymovement DittoFinale, DittoEndTrigger_Movement_0
# 68 "data/maps/DaycareMew/scripts.pory"
	waitmovement DittoFinale
# 69 "data/maps/DaycareMew/scripts.pory"
	applymovement DittoFinale, DittoEndTrigger_Movement_1
# 70 "data/maps/DaycareMew/scripts.pory"
	waitmovement DittoFinale
# 71 "data/maps/DaycareMew/scripts.pory"
	speakername DittoEnd_Text_0
# 72 "data/maps/DaycareMew/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 73 "data/maps/DaycareMew/scripts.pory"
	msgbox DittoEnd_Text_1, MSGBOX_DEFAULT
# 74 "data/maps/DaycareMew/scripts.pory"
	removefieldmugshot
# 75 "data/maps/DaycareMew/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 76 "data/maps/DaycareMew/scripts.pory"
	giveitem ITEM_SUPER_POTION, 5
# 77 "data/maps/DaycareMew/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 78 "data/maps/DaycareMew/scripts.pory"
	setflag FLAG_DITTO_SITRUS
# 79 "data/maps/DaycareMew/scripts.pory"
	speakername DittoEnd_Text_0
# 80 "data/maps/DaycareMew/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 81 "data/maps/DaycareMew/scripts.pory"
	msgbox DittoEnd_Text_2, MSGBOX_AUTOCLOSE
# 82 "data/maps/DaycareMew/scripts.pory"
	removefieldmugshot
# 83 "data/maps/DaycareMew/scripts.pory"
	applymovement DittoFinale, DittoEndTrigger_Movement_2
# 84 "data/maps/DaycareMew/scripts.pory"
	waitmovement DittoFinale
# 85 "data/maps/DaycareMew/scripts.pory"
	applymovement DittoFinale, DittoEndTrigger_Movement_3
# 86 "data/maps/DaycareMew/scripts.pory"
	waitmovement DittoFinale
# 87 "data/maps/DaycareMew/scripts.pory"
	applymovement DittoFinale, DittoEndTrigger_Movement_4
# 88 "data/maps/DaycareMew/scripts.pory"
	waitmovement DittoFinale
# 89 "data/maps/DaycareMew/scripts.pory"
	waitmessage
# 90 "data/maps/DaycareMew/scripts.pory"
	release
	end


DittoEndTriggerTwo::
# 102 "data/maps/DaycareMew/scripts.pory"
	goto_if_set FLAG_BEAT_MEW, DittoEndTriggerTwo_1
	end

DittoEndTriggerTwo_1:
# 104 "data/maps/DaycareMew/scripts.pory"
	goto_if_unset FLAG_DITTO_END_TRIGGER, DittoEndTriggerTwo_4
	end

DittoEndTriggerTwo_4:
# 106 "data/maps/DaycareMew/scripts.pory"
	lock
# 107 "data/maps/DaycareMew/scripts.pory"
	playse SE_PIN
# 108 "data/maps/DaycareMew/scripts.pory"
	applymovement DittoFinale, Common_Movement_ExclamationMark
# 109 "data/maps/DaycareMew/scripts.pory"
	waitmovement DittoFinale
# 110 "data/maps/DaycareMew/scripts.pory"
	applymovement DittoFinale, DittoEndTriggerTwo_Movement_0
# 111 "data/maps/DaycareMew/scripts.pory"
	waitmovement DittoFinale
# 112 "data/maps/DaycareMew/scripts.pory"
	speakername DittoEnd_Text_0
# 113 "data/maps/DaycareMew/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_HAPPY
# 114 "data/maps/DaycareMew/scripts.pory"
	msgbox DittoEndTriggerTwo_Text_0, MSGBOX_DEFAULT
# 115 "data/maps/DaycareMew/scripts.pory"
	waitmessage
# 116 "data/maps/DaycareMew/scripts.pory"
	removefieldmugshot
# 117 "data/maps/DaycareMew/scripts.pory"
	setflag FLAG_DITTO_END_TRIGGER
# 118 "data/maps/DaycareMew/scripts.pory"
	release
	end


ChanseyHealMew::
# 134 "data/maps/DaycareMew/scripts.pory"
	lock
# 135 "data/maps/DaycareMew/scripts.pory"
	faceplayer
# 136 "data/maps/DaycareMew/scripts.pory"
	speakername ChanseyHealMew_Text_0
# 137 "data/maps/DaycareMew/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 138 "data/maps/DaycareMew/scripts.pory"
	msgbox ChanseyHealMew_Text_1, MSGBOX_DEFAULT
# 139 "data/maps/DaycareMew/scripts.pory"
	removefieldmugshot
# 140 "data/maps/DaycareMew/scripts.pory"
	msgbox ChanseyHealMew_Text_2, MSGBOX_YESNO
# 141 "data/maps/DaycareMew/scripts.pory"
	waitmessage
# 142 "data/maps/DaycareMew/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyHealMew_1
# 172 "data/maps/DaycareMew/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 173 "data/maps/DaycareMew/scripts.pory"
	msgbox ChanseyHealMew_Text_5, MSGBOX_AUTOCLOSE
# 174 "data/maps/DaycareMew/scripts.pory"
	waitmessage
# 175 "data/maps/DaycareMew/scripts.pory"
	removefieldmugshot
# 176 "data/maps/DaycareMew/scripts.pory"
	release
	end

ChanseyHealMew_1:
# 144 "data/maps/DaycareMew/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 145 "data/maps/DaycareMew/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyHealMew_4
# 162 "data/maps/DaycareMew/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 163 "data/maps/DaycareMew/scripts.pory"
	msgbox ChanseyHealMew_Text_4, MSGBOX_AUTOCLOSE
# 164 "data/maps/DaycareMew/scripts.pory"
	waitmessage
# 165 "data/maps/DaycareMew/scripts.pory"
	removefieldmugshot
# 166 "data/maps/DaycareMew/scripts.pory"
	release
	end

ChanseyHealMew_4:
# 147 "data/maps/DaycareMew/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 148 "data/maps/DaycareMew/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 149 "data/maps/DaycareMew/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 150 "data/maps/DaycareMew/scripts.pory"
	playfanfare MUS_HEAL
# 151 "data/maps/DaycareMew/scripts.pory"
	waitfanfare
# 152 "data/maps/DaycareMew/scripts.pory"
	special HealPlayerParty
# 153 "data/maps/DaycareMew/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 154 "data/maps/DaycareMew/scripts.pory"
	msgbox ChanseyHealMew_Text_3, MSGBOX_AUTOCLOSE
# 155 "data/maps/DaycareMew/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 156 "data/maps/DaycareMew/scripts.pory"
	waitmessage
# 157 "data/maps/DaycareMew/scripts.pory"
	release
	end


# 67 "data/maps/DaycareMew/scripts.pory"
DittoEndTrigger_Movement_0:
# 67 "data/maps/DaycareMew/scripts.pory"
	walk_left
# 67 "data/maps/DaycareMew/scripts.pory"
	walk_left
	step_end

# 69 "data/maps/DaycareMew/scripts.pory"
DittoEndTrigger_Movement_1:
# 69 "data/maps/DaycareMew/scripts.pory"
	walk_down
	step_end

# 83 "data/maps/DaycareMew/scripts.pory"
DittoEndTrigger_Movement_2:
# 83 "data/maps/DaycareMew/scripts.pory"
	walk_up
	step_end

# 85 "data/maps/DaycareMew/scripts.pory"
DittoEndTrigger_Movement_3:
# 85 "data/maps/DaycareMew/scripts.pory"
	walk_right
# 85 "data/maps/DaycareMew/scripts.pory"
	walk_right
	step_end

# 87 "data/maps/DaycareMew/scripts.pory"
DittoEndTrigger_Movement_4:
# 87 "data/maps/DaycareMew/scripts.pory"
	walk_in_place_down
	step_end

# 110 "data/maps/DaycareMew/scripts.pory"
DittoEndTriggerTwo_Movement_0:
# 110 "data/maps/DaycareMew/scripts.pory"
	face_player
	step_end

DittoEnd_Text_0:
# 18 "data/maps/DaycareMew/scripts.pory"
	.string "Ditto$"

DittoEnd_Text_1:
# 20 "data/maps/DaycareMew/scripts.pory"
	.string "This is it.\pAfter you walk through this\ndoorway, you will learn the\lsecret of how we Dittos get\lour Eggs.\pTake these.\nThey'll come in handy.$"

DittoEnd_Text_2:
# 36 "data/maps/DaycareMew/scripts.pory"
	.string "You'll want to be at full health.\nTrust me.$"

DittoEnd_Text_3:
# 50 "data/maps/DaycareMew/scripts.pory"
	.string "Congratulations!\pNow you know how we Dittos\nget our Eggs!\pThis knowledge is sacred amonst\nthe Daycare Dittos, so keep this\lto yourself.\pComplete your obligation and hand\nthat Egg off to the Daycare Man.$"

DittoEndTriggerTwo_Text_0:
# 114 "data/maps/DaycareMew/scripts.pory"
	.string "Congratulations!\pNow you know how we Dittos\nget our Eggs!\pThis knowledge is sacred amongst\nthe Daycare Dittos, so keep this\lto yourself.\pComplete your obligation and hand\nthat Egg off to the Daycare Man.$"

ChanseyHealMew_Text_0:
# 136 "data/maps/DaycareMew/scripts.pory"
	.string "Chansey$"

ChanseyHealMew_Text_1:
# 138 "data/maps/DaycareMew/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyHealMew_Text_2:
# 140 "data/maps/DaycareMew/scripts.pory"
	.string "Would you like to heal?$"

ChanseyHealMew_Text_3:
# 154 "data/maps/DaycareMew/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyHealMew_Text_4:
# 163 "data/maps/DaycareMew/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyHealMew_Text_5:
# 173 "data/maps/DaycareMew/scripts.pory"
	.string "Oh, okay then.$"
