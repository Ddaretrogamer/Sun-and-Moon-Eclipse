TrainerSchool1CR_MapScripts::
	.byte 0


TrainerSchool1CR_PPkid::
# 4 "data/maps/TrainerSchool1CR/scripts.pory"
	lock
# 5 "data/maps/TrainerSchool1CR/scripts.pory"
	faceplayer
# 6 "data/maps/TrainerSchool1CR/scripts.pory"
	msgbox TrainerSchool1CR_PPkid_Text_0, MSGBOX_AUTOCLOSE
# 16 "data/maps/TrainerSchool1CR/scripts.pory"
	release
	end


TrainerSchool1CR_PokeballsKid::
# 21 "data/maps/TrainerSchool1CR/scripts.pory"
	lock
# 22 "data/maps/TrainerSchool1CR/scripts.pory"
	faceplayer
# 23 "data/maps/TrainerSchool1CR/scripts.pory"
	msgbox TrainerSchool1CR_PokeballsKid_Text_0, MSGBOX_AUTOCLOSE
# 25 "data/maps/TrainerSchool1CR/scripts.pory"
	release
	end


TrainerSchool1CR_PetPokemonKid::
# 30 "data/maps/TrainerSchool1CR/scripts.pory"
	lock
# 31 "data/maps/TrainerSchool1CR/scripts.pory"
	faceplayer
# 32 "data/maps/TrainerSchool1CR/scripts.pory"
	msgbox TrainerSchool1CR_PetPokemonKid_Text_0, MSGBOX_AUTOCLOSE
# 34 "data/maps/TrainerSchool1CR/scripts.pory"
	release
	end


TrainerSchool1CR_ICanRead::
# 39 "data/maps/TrainerSchool1CR/scripts.pory"
	lock
# 40 "data/maps/TrainerSchool1CR/scripts.pory"
	faceplayer
# 41 "data/maps/TrainerSchool1CR/scripts.pory"
	msgbox TrainerSchool1CR_ICanRead_Text_0, MSGBOX_AUTOCLOSE
# 47 "data/maps/TrainerSchool1CR/scripts.pory"
	release
	end


TrainerSchool1CR_TypeMatchupSign::
# 52 "data/maps/TrainerSchool1CR/scripts.pory"
	msgbox TrainerSchool1CR_TypeMatchupSign_Text_0, MSGBOX_SIGN
	return


TrainerSchool1CR_Teacher::
# 65 "data/maps/TrainerSchool1CR/scripts.pory"
	lock
# 66 "data/maps/TrainerSchool1CR/scripts.pory"
	faceplayer
# 67 "data/maps/TrainerSchool1CR/scripts.pory"
	msgbox TrainerSchool1CR_Teacher_Text_0, MSGBOX_AUTOCLOSE
# 72 "data/maps/TrainerSchool1CR/scripts.pory"
	release
	end


TrainerSchool1CR_BattleVs_Mia::
# 77 "data/maps/TrainerSchool1CR/scripts.pory"
	lock
# 78 "data/maps/TrainerSchool1CR/scripts.pory"
	goto_if_not_defeated TRAINER_SCHOOLKID_MIA, TrainersSchool_BattleVS_Mia2
# 79 "data/maps/TrainerSchool1CR/scripts.pory"
	msgbox TrainerSchool1CR_BattleVs_Mia_Text_0, MSGBOX_AUTOCLOSE
# 81 "data/maps/TrainerSchool1CR/scripts.pory"
	release
	end


TrainersSchool_BattleVS_Mia2::
# 86 "data/maps/TrainerSchool1CR/scripts.pory"
	playse SE_PIN
# 87 "data/maps/TrainerSchool1CR/scripts.pory"
	applymovement trainerschool_mia, TrainersSchool_BattleVS_Mia2_Movement_0
# 88 "data/maps/TrainerSchool1CR/scripts.pory"
	waitmovement trainerschool_mia
# 89 "data/maps/TrainerSchool1CR/scripts.pory"
	waitse
# 90 "data/maps/TrainerSchool1CR/scripts.pory"
	trainerbattle_single TRAINER_SCHOOLKID_MIA, TrainersSchool_BattleVS_Mia2_Text_0, TrainersSchool_BattleVS_Mia2_Text_1
# 92 "data/maps/TrainerSchool1CR/scripts.pory"
	msgbox TrainersSchool_BattleVS_Mia2_Text_2, MSGBOX_AUTOCLOSE
# 95 "data/maps/TrainerSchool1CR/scripts.pory"
	giveitem ITEM_ORAN_BERRY, 3
# 96 "data/maps/TrainerSchool1CR/scripts.pory"
	msgbox TrainerSchool1CR_BattleVs_Mia_Text_0, MSGBOX_AUTOCLOSE
# 98 "data/maps/TrainerSchool1CR/scripts.pory"
	release
	end


# 87 "data/maps/TrainerSchool1CR/scripts.pory"
TrainersSchool_BattleVS_Mia2_Movement_0:
# 87 "data/maps/TrainerSchool1CR/scripts.pory"
	emote_exclamation_mark
# 87 "data/maps/TrainerSchool1CR/scripts.pory"
	face_player
	step_end

TrainerSchool1CR_PPkid_Text_0:
# 6 "data/maps/TrainerSchool1CR/scripts.pory"
	.string "Pokemon moves have PP. Um.\n"
	.string "Power Points.\p"
	.string "If the PP for a move runs out, your\n"
	.string "Pokémon won't be able to use it\l"
	.string "anymore.\p"
	.string "Not till you get it restored, I mean.\n"
	.string "And you can just take it to a\l"
	.string "Pokémon Center for that!$"

TrainerSchool1CR_PokeballsKid_Text_0:
# 23 "data/maps/TrainerSchool1CR/scripts.pory"
	.string "Who do you think picks up the Poké Balls\n"
	.string "you throw that don't catch a Pokémon?$"

TrainerSchool1CR_PetPokemonKid_Text_0:
# 32 "data/maps/TrainerSchool1CR/scripts.pory"
	.string "Petting my Pokémon makes me happy,\n"
	.string "too!$"

TrainerSchool1CR_ICanRead_Text_0:
# 41 "data/maps/TrainerSchool1CR/scripts.pory"
	.string "I can read! Here, watch.\p"
	.string "“Moves have types, just like Pokémon…\n"
	.string "If you use a move that's the same\l"
	.string "type as your Pokémon, it will get a\l"
	.string "special boost in power!”$"

TrainerSchool1CR_TypeMatchupSign_Text_0:
# 52 "data/maps/TrainerSchool1CR/scripts.pory"
	.string "There is writing on the blackboard.\n"
	.string "It describes how types match up.\p"
	.string "Grass is weak to Fire.\n"
	.string "Water is weak to Grass.\l"
	.string "Fire is weak to Water.\p"
	.string "There are many more types, too, and\n"
	.string "they have their own weaknesses,\l"
	.string "just like these three.$"

TrainerSchool1CR_Teacher_Text_0:
# 67 "data/maps/TrainerSchool1CR/scripts.pory"
	.string "We occasionally ask Professor Kukui to\n"
	.string "run a special class for our school.\p"
	.string "He's done a great deal of research into\n"
	.string "Pokémon moves, after all.$"

TrainerSchool1CR_BattleVs_Mia_Text_0:
# 79 "data/maps/TrainerSchool1CR/scripts.pory"
	.string "Metapod looks so cute munching down an\n"
	.string "Oran Berry in the middle of battle!$"

TrainersSchool_BattleVS_Mia2_Text_0:
# 90 "data/maps/TrainerSchool1CR/scripts.pory"
	.string "Look at my Metapod!\nIt's got an Oran Berry!$"

TrainersSchool_BattleVS_Mia2_Text_1:
# 91 "data/maps/TrainerSchool1CR/scripts.pory"
	.string "Metapod…here, have a Berry.$"

TrainersSchool_BattleVS_Mia2_Text_2:
# 92 "data/maps/TrainerSchool1CR/scripts.pory"
	.string "I'll give you some Oran Berries, too!\n"
	.string "They're great to have your Pokémon\l"
	.string "hold!$"
