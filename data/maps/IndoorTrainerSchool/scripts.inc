IndoorTrainerSchool_MapScripts::
	.byte 0


TrainerSchool1FDoor::
# 4 "data/maps/IndoorTrainerSchool/scripts.pory"
	playse SE_DOOR
# 5 "data/maps/IndoorTrainerSchool/scripts.pory"
	warp MAP_TRAINER_SCHOOL1CR, 0
	end


TrainerSchool1F_GiveQuickClaw::
# 10 "data/maps/IndoorTrainerSchool/scripts.pory"
	lock
# 11 "data/maps/IndoorTrainerSchool/scripts.pory"
	faceplayer
# 12 "data/maps/IndoorTrainerSchool/scripts.pory"
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, TrainerSchool1F_GiveQuickClaw_2
# 26 "data/maps/IndoorTrainerSchool/scripts.pory"
	msgbox TrainerSchool1F_GiveQuickClaw_Text_1, MSGBOX_AUTOCLOSE
# 30 "data/maps/IndoorTrainerSchool/scripts.pory"
	giveitem ITEM_QUICK_CLAW
# 31 "data/maps/IndoorTrainerSchool/scripts.pory"
	msgbox TrainerSchool1F_GiveQuickClaw_Text_0, MSGBOX_AUTOCLOSE
TrainerSchool1F_GiveQuickClaw_1:
# 41 "data/maps/IndoorTrainerSchool/scripts.pory"
	release
	end

TrainerSchool1F_GiveQuickClaw_2:
# 14 "data/maps/IndoorTrainerSchool/scripts.pory"
	msgbox TrainerSchool1F_GiveQuickClaw_Text_0, MSGBOX_AUTOCLOSE
	goto TrainerSchool1F_GiveQuickClaw_1


TrainerSchool1F_LittleBoyAtTable::
# 46 "data/maps/IndoorTrainerSchool/scripts.pory"
	lock
# 47 "data/maps/IndoorTrainerSchool/scripts.pory"
	faceplayer
# 48 "data/maps/IndoorTrainerSchool/scripts.pory"
	msgbox TrainerSchool1F_LittleBoyAtTable_Text_0, MSGBOX_AUTOCLOSE
# 50 "data/maps/IndoorTrainerSchool/scripts.pory"
	release
	end


TrainerSchool1F_LittleBoyBlockingStairs::
# 55 "data/maps/IndoorTrainerSchool/scripts.pory"
	lock
# 56 "data/maps/IndoorTrainerSchool/scripts.pory"
	msgbox TrainerSchool1F_LittleBoyBlockingStairs_Text_0, MSGBOX_AUTOCLOSE
# 60 "data/maps/IndoorTrainerSchool/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 61 "data/maps/IndoorTrainerSchool/scripts.pory"
	msgbox TrainerSchool1F_LittleBoyBlockingStairs_Text_1
# 62 "data/maps/IndoorTrainerSchool/scripts.pory"
	waitmoncry
# 63 "data/maps/IndoorTrainerSchool/scripts.pory"
	release
	end


TrainerSchool1F_GiveQuickClaw_Text_0:
# 14 "data/maps/IndoorTrainerSchool/scripts.pory"
	.string "In Pokémon battles, the Pokémon with\n"
	.string "the highest Speed stat acts first.\p"
	.string "But with a Quick Claw, your Pokémon\n"
	.string "should be able to attack first,\l"
	.string "regardless of its Speed.\p"
	.string "Or sometimes, anyway.\n"
	.string "{PAUSE 30}It's better than nothing!$"

TrainerSchool1F_GiveQuickClaw_Text_1:
# 26 "data/maps/IndoorTrainerSchool/scripts.pory"
	.string "Look at your Pokémon…\p"
	.string "Whether it has any claws or not now, it\n"
	.string "would likely get a kick out of this one.$"

TrainerSchool1F_LittleBoyAtTable_Text_0:
# 48 "data/maps/IndoorTrainerSchool/scripts.pory"
	.string "Some items don't do anything unless you\n"
	.string "give them to a Pokémon to hold.$"

TrainerSchool1F_LittleBoyBlockingStairs_Text_0:
# 56 "data/maps/IndoorTrainerSchool/scripts.pory"
	.string "Ohhh, you stinkin' Meowth!\p"
	.string "Why do you always love to park right\n"
	.string "at the base of the stairs?!$"

TrainerSchool1F_LittleBoyBlockingStairs_Text_1:
# 61 "data/maps/IndoorTrainerSchool/scripts.pory"
	.string "Mrawrr!$"
