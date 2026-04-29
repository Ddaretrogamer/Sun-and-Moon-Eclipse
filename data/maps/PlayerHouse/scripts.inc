PlayerHouse_MapScripts::
# 2 "data/maps/PlayerHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 4 "data/maps/PlayerHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 2 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 2 "data/maps/PlayerHouse/scripts.pory"
	hideobjectat playerhousemom2, MAP_PLAYER_HOUSE
# 3 "data/maps/PlayerHouse/scripts.pory"
	hideobjectat playerhousemeowth2, MAP_PLAYER_HOUSE
	return

PlayerHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 VAR_MOM_IN_HOUSE_INTRO, 1, PlayerHouse_MomNewgame
# 5 "data/maps/PlayerHouse/scripts.pory"
	map_script_2 VAR_MOM_IN_HOUSE_INTRO, 3, PlayerHouse_GotRunningShoes
	.2byte 0


PlayerHouse_MomNewGoGetPokemon::
# 10 "data/maps/PlayerHouse/scripts.pory"
	lock
# 11 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 12 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 13 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewGoGetPokemon_Text_1
# 17 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_MomNewGameDialog::
# 22 "data/maps/PlayerHouse/scripts.pory"
	lock
# 23 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 24 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 25 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewGoGetPokemon_Text_1
# 29 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_MeowthNewGameDialog::
# 34 "data/maps/PlayerHouse/scripts.pory"
	lock
# 35 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 36 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 37 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MeowthNewGameDialog_Text_0, MSGBOX_AUTOCLOSE
# 38 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_MomNewgame::
# 43 "data/maps/PlayerHouse/scripts.pory"
	lock
# 44 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 1
	goto_if_eq PlayerHouse_MomNewgame_1
# 107 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, PlayerHouse_MomNewgame_Movement_1
# 108 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 109 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 110 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, Common_Movement_ExclamationMark
# 111 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 112 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 113 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_10
# 116 "data/maps/PlayerHouse/scripts.pory"
	release
	end

PlayerHouse_MomNewgame_1:
# 45 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 46 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, Common_Movement_ExclamationMark
# 47 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 48 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, PlayerHouse_MomNewgame_Movement_0
# 49 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 50 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 51 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_0
# 53 "data/maps/PlayerHouse/scripts.pory"
	gettimeofday
# 54 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq PlayerHouse_MomNewgame_5
# 54 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq PlayerHouse_MomNewgame_5
# 59 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_2
PlayerHouse_MomNewgame_4:
# 62 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_3
# 67 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_4
# 71 "data/maps/PlayerHouse/scripts.pory"
	dynmultichoice 19, 7, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, PlayerHouse_MomNewgame_Text_5, PlayerHouse_MomNewgame_Text_6
# 72 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq PlayerHouse_MomNewgame_11
# 77 "data/maps/PlayerHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PlayerHouse_MomNewgame_12
PlayerHouse_MomNewgame_10:
# 81 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_9
# 102 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 2
# 103 "data/maps/PlayerHouse/scripts.pory"
	release
	end

PlayerHouse_MomNewgame_5:
# 55 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_1
	goto PlayerHouse_MomNewgame_4

PlayerHouse_MomNewgame_11:
# 74 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_7
	goto PlayerHouse_MomNewgame_10

PlayerHouse_MomNewgame_12:
# 78 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_MomNewgame_Text_8
	goto PlayerHouse_MomNewgame_10


PlayerHouse_GotRunningShoes::
# 122 "data/maps/PlayerHouse/scripts.pory"
	lock
# 123 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerHouse_GotRunningShoes_Movement_0
# 124 "data/maps/PlayerHouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 125 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom2, PlayerHouse_GotRunningShoes_Movement_1
# 126 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom2
# 127 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 128 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_GotRunningShoes_Text_0
# 140 "data/maps/PlayerHouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 141 "data/maps/PlayerHouse/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 142 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_GotRunningShoes_Text_1, MSGBOX_AUTOCLOSE
# 143 "data/maps/PlayerHouse/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 4
# 144 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_TalkToMom::
# 149 "data/maps/PlayerHouse/scripts.pory"
	lock
# 150 "data/maps/PlayerHouse/scripts.pory"
	faceplayer
# 151 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 152 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_TalkToMom_Text_0
# 154 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_Trigger_TryingToLeaveWithoutShoes::
# 159 "data/maps/PlayerHouse/scripts.pory"
	lock
# 160 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 161 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 162 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Text_0, MSGBOX_AUTOCLOSE
# 167 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Movement_0
# 168 "data/maps/PlayerHouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 169 "data/maps/PlayerHouse/scripts.pory"
	release
	end


PlayerHouse_Trigger_TryingToLeaveWithoutShoes2::
# 174 "data/maps/PlayerHouse/scripts.pory"
	lock
# 175 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, PlayerHouse_GotRunningShoes_Movement_1
# 176 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 177 "data/maps/PlayerHouse/scripts.pory"
	playse SE_PIN
# 178 "data/maps/PlayerHouse/scripts.pory"
	applymovement playerhousemom1, Common_Movement_ExclamationMark
# 179 "data/maps/PlayerHouse/scripts.pory"
	waitmovement playerhousemom1
# 180 "data/maps/PlayerHouse/scripts.pory"
	speakername PlayerHouse_MomNewGoGetPokemon_Text_0
# 181 "data/maps/PlayerHouse/scripts.pory"
	msgbox PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Text_0
# 184 "data/maps/PlayerHouse/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Movement_0
# 185 "data/maps/PlayerHouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 186 "data/maps/PlayerHouse/scripts.pory"
	release
	end


# 48 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_MomNewgame_Movement_0:
# 48 "data/maps/PlayerHouse/scripts.pory"
	walk_left
# 48 "data/maps/PlayerHouse/scripts.pory"
	face_up
	step_end

# 107 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_MomNewgame_Movement_1:
# 107 "data/maps/PlayerHouse/scripts.pory"
	face_up
	step_end

# 123 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_GotRunningShoes_Movement_0:
# 123 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 123 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 123 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 123 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 123 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 123 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 123 "data/maps/PlayerHouse/scripts.pory"
	walk_down
# 123 "data/maps/PlayerHouse/scripts.pory"
	walk_left
	step_end

# 125 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_GotRunningShoes_Movement_1:
# 125 "data/maps/PlayerHouse/scripts.pory"
	face_player
	step_end

# 167 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Movement_0:
# 167 "data/maps/PlayerHouse/scripts.pory"
	walk_up
	step_end

# 184 "data/maps/PlayerHouse/scripts.pory"
PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Movement_0:
# 184 "data/maps/PlayerHouse/scripts.pory"
	walk_down
	step_end

PlayerHouse_MomNewGoGetPokemon_Text_0:
# 12 "data/maps/PlayerHouse/scripts.pory"
	.string "Mom$"

PlayerHouse_MomNewGoGetPokemon_Text_1:
# 13 "data/maps/PlayerHouse/scripts.pory"
	.string "Where are your shoes, {PLAYER}?\p"
	.string "You should probably unpack the box\n"
	.string "in your room to find them!$"

PlayerHouse_MeowthNewGameDialog_Text_0:
# 37 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrrowrr!$"

PlayerHouse_MomNewgame_Text_0:
# 51 "data/maps/PlayerHouse/scripts.pory"
	.string "You were out like a light, earlier!\n"
	.string "You ought to be full of energy by now!$"

PlayerHouse_MomNewgame_Text_1:
# 55 "data/maps/PlayerHouse/scripts.pory"
	.string "And just look!\n"
	.string "It's already night here!$"

PlayerHouse_MomNewgame_Text_2:
# 59 "data/maps/PlayerHouse/scripts.pory"
	.string "And just look!\n"
	.string "It's already daytime here!$"

PlayerHouse_MomNewgame_Text_3:
# 62 "data/maps/PlayerHouse/scripts.pory"
	.string "It's completely the opposite of Kanto.\p"
	.string "But then we are so far away here in\n"
	.string "Alola.$"

PlayerHouse_MomNewgame_Text_4:
# 67 "data/maps/PlayerHouse/scripts.pory"
	.string "So {PLAYER}!\p"
	.string "Are you excited to meet some Alolan\n"
	.string "Pokémon?$"

PlayerHouse_MomNewgame_Text_5:
# 71 "data/maps/PlayerHouse/scripts.pory"
	.string "Of course!$"

PlayerHouse_MomNewgame_Text_6:
# 71 "data/maps/PlayerHouse/scripts.pory"
	.string "I guess…$"

PlayerHouse_MomNewgame_Text_7:
# 74 "data/maps/PlayerHouse/scripts.pory"
	.string "That's right!\n"
	.string "I want to hurry up and meet some, too!$"

PlayerHouse_MomNewgame_Text_8:
# 78 "data/maps/PlayerHouse/scripts.pory"
	.string "Oh you! Someday you're going to learn\n"
	.string "to have a little wonder in your life!$"

PlayerHouse_MomNewgame_Text_9:
# 81 "data/maps/PlayerHouse/scripts.pory"
	.string "We're living in the Alola region now!\p"
	.string "The beautiful islands everyone wants\n"
	.string "to visit!\p"
	.string "I'm sure the Pokémon living in a place\n"
	.string "like this must be friendly, right?\p"
	.string "It might not be a bad idea to go out\n"
	.string "and see for yourself just how\l"
	.string "friendly Pokémon here are.\p"
	.string "Right {PLAYER}?\n"
	.string "Go and get ready for a bit of\l"
	.string "exploring!\p"
	.string "Your running shoes should be in the\n"
	.string "box in your room.\p"
	.string "And didn't you leave your copy of\n"
	.string "Adventure Rules on your desk, too?$"

PlayerHouse_MomNewgame_Text_10:
# 113 "data/maps/PlayerHouse/scripts.pory"
	.string "Where are your shoes, {PLAYER}?\n"
	.string "You should probably unpack the box in\l"
	.string "your room to find them!$"

PlayerHouse_GotRunningShoes_Text_0:
# 128 "data/maps/PlayerHouse/scripts.pory"
	.string "Now you look ready for anything!\p"
	.string "Oh, but even so, {PLAYER}…\p"
	.string "Try to be careful walking through the\n"
	.string "tall grass!\p"
	.string "Still, I have to admit that I'd love\n"
	.string "to have a new Pokémon around…\p"
	.string "Why don't you head up towards Iki Town\n"
	.string "and see what you discover in Alola?$"

PlayerHouse_GotRunningShoes_Text_1:
# 142 "data/maps/PlayerHouse/scripts.pory"
	.string "Mrowrr!$"

PlayerHouse_TalkToMom_Text_0:
# 152 "data/maps/PlayerHouse/scripts.pory"
	.string "Why don't you head up towards Iki Town\n"
	.string "and see what you discover in Alola?$"

PlayerHouse_Trigger_TryingToLeaveWithoutShoes_Text_0:
# 162 "data/maps/PlayerHouse/scripts.pory"
	.string "Are you leaving without your shoes, \n"
	.string "{PLAYER}?\p"
	.string "You should unpack the box in\n"
	.string "your room to find them!$"

PlayerHouse_Trigger_TryingToLeaveWithoutShoes2_Text_0:
# 181 "data/maps/PlayerHouse/scripts.pory"
	.string "Where are you going, {PLAYER}?\n"
	.string "You should probably unpack the box in\l"
	.string "your room to find them!$"
