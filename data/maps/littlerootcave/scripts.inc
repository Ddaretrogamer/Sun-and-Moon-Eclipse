littlerootcave_MapScripts::
	.byte 0


littlerootcave_eventscript_cyndaquil_gift::
# 5 "data/maps/littlerootcave/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x020, littlerootcave_eventscript_cyndaquil_gift_4
littlerootcave_eventscript_cyndaquil_gift_3:
# 36 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_cyndaquil_gift_Text_3
littlerootcave_eventscript_cyndaquil_gift_1:
# 39 "data/maps/littlerootcave/scripts.pory"
	waitmessage
# 40 "data/maps/littlerootcave/scripts.pory"
	releaseall
	end

littlerootcave_eventscript_cyndaquil_gift_2:
# 6 "data/maps/littlerootcave/scripts.pory"
	lockall
# 7 "data/maps/littlerootcave/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 8 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_cyndaquil_gift_Text_0, MSGBOX_YESNO
# 9 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq littlerootcave_eventscript_cyndaquil_gift_9
# 31 "data/maps/littlerootcave/scripts.pory"
	hidemonpic
# 32 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_NotChosen
	goto littlerootcave_eventscript_cyndaquil_gift_1

littlerootcave_eventscript_cyndaquil_gift_4:
# 5 "data/maps/littlerootcave/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x021, littlerootcave_eventscript_cyndaquil_gift_6
	goto littlerootcave_eventscript_cyndaquil_gift_3

littlerootcave_eventscript_cyndaquil_gift_6:
# 5 "data/maps/littlerootcave/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x022, littlerootcave_eventscript_cyndaquil_gift_2
	goto littlerootcave_eventscript_cyndaquil_gift_3

littlerootcave_eventscript_cyndaquil_gift_9:
# 10 "data/maps/littlerootcave/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5, ITEM_MASTER_BALL
# 11 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq littlerootcave_eventscript_cyndaquil_gift_12
# 18 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq littlerootcave_eventscript_cyndaquil_gift_13
# 26 "data/maps/littlerootcave/scripts.pory"
	hidemonpic
# 27 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_cyndaquil_gift_Text_2
	goto littlerootcave_eventscript_cyndaquil_gift_1

littlerootcave_eventscript_cyndaquil_gift_12:
# 12 "data/maps/littlerootcave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 13 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_cyndaquil_gift_Text_1
# 14 "data/maps/littlerootcave/scripts.pory"
	removeobject 1
# 15 "data/maps/littlerootcave/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 16 "data/maps/littlerootcave/scripts.pory"
	call NicknamePartyMon
	goto littlerootcave_eventscript_cyndaquil_gift_1

littlerootcave_eventscript_cyndaquil_gift_13:
# 19 "data/maps/littlerootcave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 20 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_cyndaquil_gift_Text_1
# 21 "data/maps/littlerootcave/scripts.pory"
	removeobject 1
# 22 "data/maps/littlerootcave/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 23 "data/maps/littlerootcave/scripts.pory"
	Call NicknameBoxMon
	goto littlerootcave_eventscript_cyndaquil_gift_1


littlerootcave_eventscript_totodile_gift::
# 45 "data/maps/littlerootcave/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x020, littlerootcave_eventscript_totodile_gift_4
littlerootcave_eventscript_totodile_gift_3:
# 76 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_cyndaquil_gift_Text_3
littlerootcave_eventscript_totodile_gift_1:
# 79 "data/maps/littlerootcave/scripts.pory"
	waitmessage
# 80 "data/maps/littlerootcave/scripts.pory"
	releaseall
	end

littlerootcave_eventscript_totodile_gift_2:
# 46 "data/maps/littlerootcave/scripts.pory"
	lockall
# 47 "data/maps/littlerootcave/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 48 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_totodile_gift_Text_0, MSGBOX_YESNO
# 49 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq littlerootcave_eventscript_totodile_gift_9
# 71 "data/maps/littlerootcave/scripts.pory"
	hidemonpic
# 72 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_NotChosen
	goto littlerootcave_eventscript_totodile_gift_1

littlerootcave_eventscript_totodile_gift_4:
# 45 "data/maps/littlerootcave/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x021, littlerootcave_eventscript_totodile_gift_6
	goto littlerootcave_eventscript_totodile_gift_3

littlerootcave_eventscript_totodile_gift_6:
# 45 "data/maps/littlerootcave/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x022, littlerootcave_eventscript_totodile_gift_2
	goto littlerootcave_eventscript_totodile_gift_3

littlerootcave_eventscript_totodile_gift_9:
# 50 "data/maps/littlerootcave/scripts.pory"
	givemon SPECIES_TOTODILE, 5, ITEM_MASTER_BALL
# 51 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq littlerootcave_eventscript_totodile_gift_12
# 58 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq littlerootcave_eventscript_totodile_gift_13
# 66 "data/maps/littlerootcave/scripts.pory"
	hidemonpic
# 67 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_cyndaquil_gift_Text_2
	goto littlerootcave_eventscript_totodile_gift_1

littlerootcave_eventscript_totodile_gift_12:
# 52 "data/maps/littlerootcave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 53 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_totodile_gift_Text_1
# 54 "data/maps/littlerootcave/scripts.pory"
	removeobject 3
# 55 "data/maps/littlerootcave/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 56 "data/maps/littlerootcave/scripts.pory"
	call NicknamePartyMon
	goto littlerootcave_eventscript_totodile_gift_1

littlerootcave_eventscript_totodile_gift_13:
# 59 "data/maps/littlerootcave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 60 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_totodile_gift_Text_1
# 61 "data/maps/littlerootcave/scripts.pory"
	removeobject 3
# 62 "data/maps/littlerootcave/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 63 "data/maps/littlerootcave/scripts.pory"
	Call NicknameBoxMon
	goto littlerootcave_eventscript_totodile_gift_1


littlerootcave_eventscript_chikorita_gift::
# 85 "data/maps/littlerootcave/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x020, littlerootcave_eventscript_chikorita_gift_4
littlerootcave_eventscript_chikorita_gift_3:
# 116 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_cyndaquil_gift_Text_3
littlerootcave_eventscript_chikorita_gift_1:
# 119 "data/maps/littlerootcave/scripts.pory"
	waitmessage
# 120 "data/maps/littlerootcave/scripts.pory"
	releaseall
	end

littlerootcave_eventscript_chikorita_gift_2:
# 86 "data/maps/littlerootcave/scripts.pory"
	lockall
# 87 "data/maps/littlerootcave/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 88 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_chikorita_gift_Text_0, MSGBOX_YESNO
# 89 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq littlerootcave_eventscript_chikorita_gift_9
# 111 "data/maps/littlerootcave/scripts.pory"
	hidemonpic
# 112 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_NotChosen
	goto littlerootcave_eventscript_chikorita_gift_1

littlerootcave_eventscript_chikorita_gift_4:
# 85 "data/maps/littlerootcave/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x021, littlerootcave_eventscript_chikorita_gift_6
	goto littlerootcave_eventscript_chikorita_gift_3

littlerootcave_eventscript_chikorita_gift_6:
# 85 "data/maps/littlerootcave/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x022, littlerootcave_eventscript_chikorita_gift_2
	goto littlerootcave_eventscript_chikorita_gift_3

littlerootcave_eventscript_chikorita_gift_9:
# 90 "data/maps/littlerootcave/scripts.pory"
	givemon SPECIES_CHIKORITA, 5, ITEM_MASTER_BALL
# 91 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq littlerootcave_eventscript_chikorita_gift_12
# 98 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq littlerootcave_eventscript_chikorita_gift_13
# 106 "data/maps/littlerootcave/scripts.pory"
	hidemonpic
# 107 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_cyndaquil_gift_Text_2
	goto littlerootcave_eventscript_chikorita_gift_1

littlerootcave_eventscript_chikorita_gift_12:
# 92 "data/maps/littlerootcave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 93 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_chikorita_gift_Text_1
# 94 "data/maps/littlerootcave/scripts.pory"
	removeobject 2
# 95 "data/maps/littlerootcave/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 96 "data/maps/littlerootcave/scripts.pory"
	call NicknamePartyMon
	goto littlerootcave_eventscript_chikorita_gift_1

littlerootcave_eventscript_chikorita_gift_13:
# 99 "data/maps/littlerootcave/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 100 "data/maps/littlerootcave/scripts.pory"
	msgbox littlerootcave_eventscript_chikorita_gift_Text_1
# 101 "data/maps/littlerootcave/scripts.pory"
	removeobject 2
# 102 "data/maps/littlerootcave/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 103 "data/maps/littlerootcave/scripts.pory"
	Call NicknameBoxMon
	goto littlerootcave_eventscript_chikorita_gift_1


Give_EXP_Share::
# 126 "data/maps/littlerootcave/scripts.pory"
	lock
# 127 "data/maps/littlerootcave/scripts.pory"
	faceplayer
# 128 "data/maps/littlerootcave/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x264, Give_EXP_Share_2
# 140 "data/maps/littlerootcave/scripts.pory"
	msgbox Give_EXP_Share_Text_3
Give_EXP_Share_1:
# 142 "data/maps/littlerootcave/scripts.pory"
	waitmessage
# 143 "data/maps/littlerootcave/scripts.pory"
	release
	end

Give_EXP_Share_2:
# 129 "data/maps/littlerootcave/scripts.pory"
	msgbox Give_EXP_Share_Text_0, MSGBOX_YESNO
# 130 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Give_EXP_Share_5
# 136 "data/maps/littlerootcave/scripts.pory"
	msgbox Give_EXP_Share_Text_2
	goto Give_EXP_Share_1

Give_EXP_Share_5:
# 131 "data/maps/littlerootcave/scripts.pory"
	giveitem ITEM_EXP_SHARE, 1
# 132 "data/maps/littlerootcave/scripts.pory"
	setflag FLAG_UNUSED_0x264
# 133 "data/maps/littlerootcave/scripts.pory"
	msgbox Give_EXP_Share_Text_1
	goto Give_EXP_Share_1


NicknamePartyMon::
# 148 "data/maps/littlerootcave/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 149 "data/maps/littlerootcave/scripts.pory"
	hidemonpic
# 150 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 151 "data/maps/littlerootcave/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 152 "data/maps/littlerootcave/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 157 "data/maps/littlerootcave/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 158 "data/maps/littlerootcave/scripts.pory"
	hidemonpic
# 159 "data/maps/littlerootcave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 162 "data/maps/littlerootcave/scripts.pory"
	msgbox NicknameBoxMon_Text_0
	return

NicknameBoxMon_2:
# 160 "data/maps/littlerootcave/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


littlerootcave_eventscript_cyndaquil_gift_Text_0:
# 8 "data/maps/littlerootcave/scripts.pory"
	.string "Do you want Cyndaquil?$"

littlerootcave_eventscript_cyndaquil_gift_Text_1:
# 13 "data/maps/littlerootcave/scripts.pory"
	.string "Received Cyndaquil.$"

littlerootcave_eventscript_cyndaquil_gift_Text_2:
# 27 "data/maps/littlerootcave/scripts.pory"
	.string "No more room.$"

littlerootcave_eventscript_cyndaquil_gift_Text_3:
# 36 "data/maps/littlerootcave/scripts.pory"
	.string "You can only choose one!$"

littlerootcave_eventscript_totodile_gift_Text_0:
# 48 "data/maps/littlerootcave/scripts.pory"
	.string "Do you want Totodile?$"

littlerootcave_eventscript_totodile_gift_Text_1:
# 53 "data/maps/littlerootcave/scripts.pory"
	.string "Received Totodile.$"

littlerootcave_eventscript_chikorita_gift_Text_0:
# 88 "data/maps/littlerootcave/scripts.pory"
	.string "Do you want Chikorita?$"

littlerootcave_eventscript_chikorita_gift_Text_1:
# 93 "data/maps/littlerootcave/scripts.pory"
	.string "Received Chikorita.$"

Give_EXP_Share_Text_0:
# 129 "data/maps/littlerootcave/scripts.pory"
	.string "Would you like the EXP Share?\n"
	.string "I've got an extra.$"

Give_EXP_Share_Text_1:
# 133 "data/maps/littlerootcave/scripts.pory"
	.string "Now you on easy mode.$"

Give_EXP_Share_Text_2:
# 136 "data/maps/littlerootcave/scripts.pory"
	.string "Alright big dawg.$"

Give_EXP_Share_Text_3:
# 140 "data/maps/littlerootcave/scripts.pory"
	.string "Dude that was my last one.$"

NicknamePartyMon_Text_0:
# 148 "data/maps/littlerootcave/scripts.pory"
	.string "Give it a nickname?$"

NicknameBoxMon_Text_0:
# 162 "data/maps/littlerootcave/scripts.pory"
	.string "Transferred to PC$"

littlerootcave_NotChosen::
# 164 "data/maps/littlerootcave/scripts.pory"
	.string "You did not choose the Pokemon.$"
