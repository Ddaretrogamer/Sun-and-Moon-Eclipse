DaycareMewFinale_MapScripts::
	.byte 0


MewFinalBattleTrigger::
# 4 "data/maps/DaycareMewFinale/scripts.pory"
	goto_if_unset FLAG_BEAT_MEW, MewFinalBattleTrigger_1
	end

MewFinalBattleTrigger_1:
# 6 "data/maps/DaycareMewFinale/scripts.pory"
	lock
# 7 "data/maps/DaycareMewFinale/scripts.pory"
	dittotransform SPECIES_DITTO
# 8 "data/maps/DaycareMewFinale/scripts.pory"
	applymovement LOCALID_PLAYER, MewFinalBattleTrigger_Movement_0
# 9 "data/maps/DaycareMewFinale/scripts.pory"
	waitmovement LOCALID_PLAYER
# 10 "data/maps/DaycareMewFinale/scripts.pory"
	playse SE_PIN
# 11 "data/maps/DaycareMewFinale/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 12 "data/maps/DaycareMewFinale/scripts.pory"
	waitmovement LOCALID_PLAYER
# 13 "data/maps/DaycareMewFinale/scripts.pory"
	delay 45
# 14 "data/maps/DaycareMewFinale/scripts.pory"
	applymovement LOCALID_PLAYER, MewFinalBattleTrigger_Movement_1
# 15 "data/maps/DaycareMewFinale/scripts.pory"
	waitmovement LOCALID_PLAYER
# 16 "data/maps/DaycareMewFinale/scripts.pory"
	playbgm MUS_PMD_TITLE, FALSE
# 17 "data/maps/DaycareMewFinale/scripts.pory"
	speakername MewFinalBattleTrigger_Text_0
# 18 "data/maps/DaycareMewFinale/scripts.pory"
	createfieldmugshot MUGSHOT_MEW, EMOTE_NORMAL
# 19 "data/maps/DaycareMewFinale/scripts.pory"
	msgbox MewFinalBattleTrigger_Text_1, MSGBOX_AUTOCLOSE
# 20 "data/maps/DaycareMewFinale/scripts.pory"
	removefieldmugshot
# 21 "data/maps/DaycareMewFinale/scripts.pory"
	setwildbattle SPECIES_MEW, 25, IsShiny = TRUE, move1 = MOVE_SOFT_BOILED, move2 = MOVE_NASTY_PLOT, move3 = MOVE_PSYCHIC, move4 = MOVE_FIRE_BLAST
# 22 "data/maps/DaycareMewFinale/scripts.pory"
	settotemboost B_POSITION_PLAYER_LEFT, 3, 3, 3, 3, 3, 3, 0
# 23 "data/maps/DaycareMewFinale/scripts.pory"
	dowildbattle
# 24 "data/maps/DaycareMewFinale/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 25 "data/maps/DaycareMewFinale/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MewFinalBattleTrigger_4
	return

MewFinalBattleTrigger_4:
# 27 "data/maps/DaycareMewFinale/scripts.pory"
	playbgm MUS_PMD_TITLE, FALSE
# 28 "data/maps/DaycareMewFinale/scripts.pory"
	speakername MewFinalBattleTrigger_Text_0
# 29 "data/maps/DaycareMewFinale/scripts.pory"
	createfieldmugshot MUGSHOT_MEW, EMOTE_HAPPY
# 30 "data/maps/DaycareMewFinale/scripts.pory"
	msgbox MewFinalBattleTrigger_Text_2, MSGBOX_DEFAULT
# 31 "data/maps/DaycareMewFinale/scripts.pory"
	removefieldmugshot
# 32 "data/maps/DaycareMewFinale/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 33 "data/maps/DaycareMewFinale/scripts.pory"
	giveitem ITEM_AIR_BALLOON
# 34 "data/maps/DaycareMewFinale/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 35 "data/maps/DaycareMewFinale/scripts.pory"
	msgbox MewFinalBattleTrigger_Text_3, MSGBOX_DEFAULT
# 36 "data/maps/DaycareMewFinale/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 37 "data/maps/DaycareMewFinale/scripts.pory"
	waitfanfare
# 38 "data/maps/DaycareMewFinale/scripts.pory"
	waitmessage
# 39 "data/maps/DaycareMewFinale/scripts.pory"
	speakername MewFinalBattleTrigger_Text_0
# 40 "data/maps/DaycareMewFinale/scripts.pory"
	createfieldmugshot MUGSHOT_MEW, EMOTE_HAPPY
# 41 "data/maps/DaycareMewFinale/scripts.pory"
	msgbox MewFinalBattleTrigger_Text_4, MSGBOX_DEFAULT
# 42 "data/maps/DaycareMewFinale/scripts.pory"
	removefieldmugshot
# 43 "data/maps/DaycareMewFinale/scripts.pory"
	waitmessage
# 44 "data/maps/DaycareMewFinale/scripts.pory"
	playse SE_M_TELEPORT
# 45 "data/maps/DaycareMewFinale/scripts.pory"
	applymovement Mew, MewFinalBattleTrigger_Movement_2
# 46 "data/maps/DaycareMewFinale/scripts.pory"
	waitmovement Mew
# 47 "data/maps/DaycareMewFinale/scripts.pory"
	removeobject Mew
# 48 "data/maps/DaycareMewFinale/scripts.pory"
	fadenewbgm MUS_PMD_MEW
# 49 "data/maps/DaycareMewFinale/scripts.pory"
	setflag FLAG_BEAT_MEW
# 50 "data/maps/DaycareMewFinale/scripts.pory"
	release
	end


# 8 "data/maps/DaycareMewFinale/scripts.pory"
MewFinalBattleTrigger_Movement_0:
# 8 "data/maps/DaycareMewFinale/scripts.pory"
	walk_up
# 8 "data/maps/DaycareMewFinale/scripts.pory"
	walk_up
# 8 "data/maps/DaycareMewFinale/scripts.pory"
	walk_up
	step_end

# 14 "data/maps/DaycareMewFinale/scripts.pory"
MewFinalBattleTrigger_Movement_1:
# 14 "data/maps/DaycareMewFinale/scripts.pory"
	walk_fast_up
# 14 "data/maps/DaycareMewFinale/scripts.pory"
	walk_fast_up
# 14 "data/maps/DaycareMewFinale/scripts.pory"
	walk_fast_up
	step_end

# 45 "data/maps/DaycareMewFinale/scripts.pory"
MewFinalBattleTrigger_Movement_2:
# 45 "data/maps/DaycareMewFinale/scripts.pory"
	slide_up
# 45 "data/maps/DaycareMewFinale/scripts.pory"
	slide_up
# 45 "data/maps/DaycareMewFinale/scripts.pory"
	slide_up
# 45 "data/maps/DaycareMewFinale/scripts.pory"
	slide_up
# 45 "data/maps/DaycareMewFinale/scripts.pory"
	slide_up
# 45 "data/maps/DaycareMewFinale/scripts.pory"
	slide_up
# 45 "data/maps/DaycareMewFinale/scripts.pory"
	slide_up
# 45 "data/maps/DaycareMewFinale/scripts.pory"
	slide_up
	step_end

MewFinalBattleTrigger_Text_0:
# 17 "data/maps/DaycareMewFinale/scripts.pory"
	.string "Mew$"

MewFinalBattleTrigger_Text_1:
# 19 "data/maps/DaycareMewFinale/scripts.pory"
	.string "Welcome Ditto.\pYou've had quite the adventure\nhaven't you?\pI see you've gathered many\ndiverse transformations.\pYou'd have to travel far and wide\nto accomplish such a feat.\pI think you are ready to receive\nyour Egg.\pConsider me your final challenge.\n$"

MewFinalBattleTrigger_Text_2:
# 30 "data/maps/DaycareMewFinale/scripts.pory"
	.string "Congratulations for overcoming\nthis tremendous challenge.\pYou have earned this.\n$"

MewFinalBattleTrigger_Text_3:
# 35 "data/maps/DaycareMewFinale/scripts.pory"
	.string "Ditto learned the secret of\nwhere Eggs come from!$"

MewFinalBattleTrigger_Text_4:
# 41 "data/maps/DaycareMewFinale/scripts.pory"
	.string "Now go on.\pDeliver that Egg to fulfill your\npurpose.$"
