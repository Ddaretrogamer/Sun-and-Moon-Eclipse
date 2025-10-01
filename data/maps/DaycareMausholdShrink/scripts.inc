DaycareMausholdShrink_MapScripts::
	.byte 0


FamilyofFour::
# 4 "data/maps/DaycareMausholdShrink/scripts.pory"
	lock
# 5 "data/maps/DaycareMausholdShrink/scripts.pory"
	faceplayer
# 6 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_unset FLAG_FAM_FOUR, FamilyofFour_1
# 103 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 104 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_MAUSHOLD4, EMOTE_NORMAL
# 105 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_9, MSGBOX_DEFAULT
# 106 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 107 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 108 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofFour_1:
# 8 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 9 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_MAUSHOLD4, EMOTE_NORMAL
# 10 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_1, MSGBOX_DEFAULT
# 11 "data/maps/DaycareMausholdShrink/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, FamilyofFour_Text_2, FamilyofFour_Text_3, FamilyofFour_Text_4
# 12 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FamilyofFour_5
# 70 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FamilyofFour_8
# 85 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq FamilyofFour_13
	return

FamilyofFour_5:
# 14 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_unset FLAG_FAMTHREE_WRONG, FamilyofFour_11
# 49 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 50 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 51 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, Common_Movement_ExclamationMark
# 52 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 53 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, FamilyofFour_Movement_0
# 54 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 55 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_6, MSGBOX_DEFAULT
# 56 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 57 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, FamilyofFour_Movement_1
# 58 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement
# 59 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_7, MSGBOX_DEFAULT
# 60 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 61 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 62 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 63 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_FOUR
# 64 "data/maps/DaycareMausholdShrink/scripts.pory"
	giveitem ITEM_POTION, 4
# 65 "data/maps/DaycareMausholdShrink/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 66 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 67 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofFour_8:
# 72 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 73 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 74 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, Common_Movement_ExclamationMark
# 75 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 76 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_8, MSGBOX_DEFAULT
# 77 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 78 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_FOUR
# 79 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAMFOUR_WRONG
# 80 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 81 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 82 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofFour_11:
# 16 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_set FLAG_FAM_THREE, FamilyofFour_16
# 28 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 29 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 30 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, Common_Movement_ExclamationMark
# 31 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 32 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, FamilyofFour_Movement_0
# 33 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 34 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_6, MSGBOX_DEFAULT
# 35 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 36 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, FamilyofFour_Movement_1
# 37 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement
# 38 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_7, MSGBOX_DEFAULT
# 39 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 40 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 41 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 42 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_FOUR
# 43 "data/maps/DaycareMausholdShrink/scripts.pory"
	giveitem ITEM_POTION, 4
# 44 "data/maps/DaycareMausholdShrink/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 45 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 46 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofFour_13:
# 87 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 88 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 89 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, Common_Movement_ExclamationMark
# 90 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 91 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_8, MSGBOX_DEFAULT
# 92 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 93 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_FOUR
# 94 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAMFOUR_WRONG
# 95 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 96 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 97 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofFour_16:
# 18 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 19 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 20 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, Common_Movement_ExclamationMark
# 21 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 22 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_5, MSGBOX_DEFAULT
# 23 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_FOUR
# 24 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 25 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end


FamilyofThree::
# 114 "data/maps/DaycareMausholdShrink/scripts.pory"
	lock
# 115 "data/maps/DaycareMausholdShrink/scripts.pory"
	faceplayer
# 116 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_unset FLAG_FAM_THREE, FamilyofThree_1
# 213 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 214 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_MAUSHOLD3, EMOTE_NORMAL
# 215 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofThree_Text_2, MSGBOX_DEFAULT
# 216 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 217 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 218 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofThree_1:
# 118 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 119 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_MAUSHOLD3, EMOTE_NORMAL
# 120 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_1, MSGBOX_DEFAULT
# 121 "data/maps/DaycareMausholdShrink/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, FamilyofFour_Text_2, FamilyofFour_Text_3, FamilyofFour_Text_4
# 122 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FamilyofThree_5
# 137 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FamilyofThree_8
# 195 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq FamilyofThree_10
	return

FamilyofThree_5:
# 124 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 125 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 126 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, Common_Movement_ExclamationMark
# 127 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 128 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_8, MSGBOX_DEFAULT
# 129 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 130 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_THREE
# 131 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAMTHREE_WRONG
# 132 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 133 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 134 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofThree_8:
# 139 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_set FLAG_FAM_FOUR, FamilyofThree_13
# 174 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 175 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 176 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, Common_Movement_ExclamationMark
# 177 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 178 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, FamilyofThree_Movement_0
# 179 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 180 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofThree_Text_0, MSGBOX_DEFAULT
# 181 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 182 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, FamilyofFour_Movement_1
# 183 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement
# 184 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofThree_Text_1, MSGBOX_DEFAULT
# 185 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 186 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 187 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 188 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_THREE
# 189 "data/maps/DaycareMausholdShrink/scripts.pory"
	giveitem ITEM_POTION, 3
# 190 "data/maps/DaycareMausholdShrink/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 191 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 192 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofThree_10:
# 197 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 198 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 199 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, Common_Movement_ExclamationMark
# 200 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 201 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_8, MSGBOX_DEFAULT
# 202 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 203 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_THREE
# 204 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAMTHREE_WRONG
# 205 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 206 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 207 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofThree_13:
# 141 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_unset FLAG_FAMFOUR_WRONG, FamilyofThree_16
# 153 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 154 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 155 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, Common_Movement_ExclamationMark
# 156 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 157 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, FamilyofThree_Movement_0
# 158 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 159 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofThree_Text_0, MSGBOX_DEFAULT
# 160 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 161 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, FamilyofFour_Movement_1
# 162 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement
# 163 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofThree_Text_1, MSGBOX_DEFAULT
# 164 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 165 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 166 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 167 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_THREE
# 168 "data/maps/DaycareMausholdShrink/scripts.pory"
	giveitem ITEM_POTION, 3
# 169 "data/maps/DaycareMausholdShrink/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 170 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 171 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofThree_16:
# 143 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 144 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 145 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, Common_Movement_ExclamationMark
# 146 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 147 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_5, MSGBOX_DEFAULT
# 148 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_THREE
# 149 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 150 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end


Familyoftwo::
# 224 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_unset FLAG_FAM_TWO, Familyoftwo_1
# 241 "data/maps/DaycareMausholdShrink/scripts.pory"
	lock
# 242 "data/maps/DaycareMausholdShrink/scripts.pory"
	faceplayer
# 243 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername Familyoftwo_Text_0
# 244 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_TANDEMAUS, EMOTE_NORMAL
# 245 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox Familyoftwo_Text_2, MSGBOX_DEFAULT
# 246 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 247 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 248 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

Familyoftwo_1:
# 226 "data/maps/DaycareMausholdShrink/scripts.pory"
	lock
# 227 "data/maps/DaycareMausholdShrink/scripts.pory"
	faceplayer
# 228 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername Familyoftwo_Text_0
# 229 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_TANDEMAUS, EMOTE_NORMAL
# 230 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox Familyoftwo_Text_1, MSGBOX_DEFAULT
# 231 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 232 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 233 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_TWO
# 234 "data/maps/DaycareMausholdShrink/scripts.pory"
	giveitem ITEM_LUCKY_EGG, 2
# 235 "data/maps/DaycareMausholdShrink/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 236 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 237 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end


ShrinkToPikachuCave5::
# 254 "data/maps/DaycareMausholdShrink/scripts.pory"
	lock
# 255 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq ShrinkToPikachuCave5_1
# 269 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, ShrinkToPikachuCave5_4
ShrinkToPikachuCave5_3:
# 298 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox ShrinkToPikachuCave5_Text_2, MSGBOX_DEFAULT
# 299 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 300 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

ShrinkToPikachuCave5_1:
# 257 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox ShrinkToPikachuCave5_Text_0, MSGBOX_YESNO
# 258 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave5_8
# 264 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 265 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

ShrinkToPikachuCave5_2:
# 271 "data/maps/DaycareMausholdShrink/scripts.pory"
	checkpartymove MOVE_STICKY_WEB
# 272 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne ShrinkToPikachuCave5_11
# 290 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox ShrinkToPikachuCave5_Text_2, MSGBOX_DEFAULT
# 291 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 292 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

ShrinkToPikachuCave5_4:
# 269 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_ne ShrinkToPikachuCave5_2
	goto ShrinkToPikachuCave5_3

ShrinkToPikachuCave5_8:
# 260 "data/maps/DaycareMausholdShrink/scripts.pory"
	warp MAP_DAYCAREBASE, 2
	return

ShrinkToPikachuCave5_11:
# 274 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox ShrinkToPikachuCave5_Text_1, MSGBOX_YESNO
# 275 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave5_14
# 283 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 284 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

ShrinkToPikachuCave5_14:
# 277 "data/maps/DaycareMausholdShrink/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 278 "data/maps/DaycareMausholdShrink/scripts.pory"
	delay 30
# 279 "data/maps/DaycareMausholdShrink/scripts.pory"
	warp MAP_DAYCAREBASE, 2
	return


# 32 "data/maps/DaycareMausholdShrink/scripts.pory"
FamilyofFour_Movement_0:
# 32 "data/maps/DaycareMausholdShrink/scripts.pory"
	face_left
	step_end

# 36 "data/maps/DaycareMausholdShrink/scripts.pory"
FamilyofFour_Movement_1:
# 36 "data/maps/DaycareMausholdShrink/scripts.pory"
	face_player
	step_end

# 157 "data/maps/DaycareMausholdShrink/scripts.pory"
FamilyofThree_Movement_0:
# 157 "data/maps/DaycareMausholdShrink/scripts.pory"
	face_right
	step_end

FamilyofFour_Text_0:
# 8 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Maushold$"

FamilyofFour_Text_1:
# 10 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "You!\pWelcome to our Maushold Haushold!\pWe've put in great work making\nthis haus a home.\pWe're in a bit of a dispute with\nthe neighbors over the proper\lhaushold size...\pWhat would you say the proper\nsize would be?$"

FamilyofFour_Text_2:
# 11 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Four$"

FamilyofFour_Text_3:
# 11 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Three$"

FamilyofFour_Text_4:
# 11 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Two$"

FamilyofFour_Text_5:
# 22 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Don't pander to us!\pWe heard the neighbors yell\nover to us!$"

FamilyofFour_Text_6:
# 34 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Aha!\pSee that!\nFour is the right number.$"

FamilyofFour_Text_7:
# 38 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Here. Take these four items.\n$"

FamilyofFour_Text_8:
# 76 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Hey!\pHow dare you insult my family!\n$"

FamilyofFour_Text_9:
# 105 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Things in fours just make sense!\n$"

FamilyofThree_Text_0:
# 159 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Aha!\pSee that!\nThree is the right number.$"

FamilyofThree_Text_1:
# 163 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Here. Take these three items.\n$"

FamilyofThree_Text_2:
# 215 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Things in threes just make sense!\n$"

Familyoftwo_Text_0:
# 228 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Tandemaus$"

Familyoftwo_Text_1:
# 230 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "The neighbors at the bottom of\nthe cliff are always feuding...\pWe decided not to have kids\nand we've been perfectly happy\lup here.\pHere. Take these two items.\n$"

Familyoftwo_Text_2:
# 245 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "We've been quite happy up here.\pWe've built a nice life for\nourselves.\pWe even have enough items\nleftover to afford to make\lfrequent trips around the Daycare!$"

ShrinkToPikachuCave5_Text_0:
# 257 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "There is a tiny hole that you can\nsqueeze through.\pWould you like to squeeze through it?$"

ShrinkToPikachuCave5_Text_1:
# 274 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "There is a tiny hole.\pA small Pokémon may be able to\nsqueeze through it.\pWould you like to transform into\nCutiefly to squeeze through it?$"

ShrinkToPikachuCave5_Text_2:
# 290 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "There is a tiny hole.\pA small Pokémon may be able to\nsqueeze through it.$"
