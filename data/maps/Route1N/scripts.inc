Route1N_MapScripts::
	.byte 0


TrainerSchoolSign::
# 5 "data/maps/Route1N/scripts.pory"
	lock
# 6 "data/maps/Route1N/scripts.pory"
	msgbox TrainerSchoolSign_Text_0
# 10 "data/maps/Route1N/scripts.pory"
	release
	end


TrainersSchool_Intro::
# 15 "data/maps/Route1N/scripts.pory"
	lock
# 16 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_Intro_Movement_0
# 17 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 18 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_kukui, TrainersSchool_Intro_Movement_1
# 19 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_1
# 25 "data/maps/Route1N/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 26 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 27 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_teacher, TrainersSchool_Intro_Movement_2
# 28 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_2
# 30 "data/maps/Route1N/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 31 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 32 "data/maps/Route1N/scripts.pory"
	release
	end


# 16 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_0:
# 16 "data/maps/Route1N/scripts.pory"
	face_left
	step_end

# 18 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_1:
# 18 "data/maps/Route1N/scripts.pory"
	walk_in_place_down
# 18 "data/maps/Route1N/scripts.pory"
	walk_in_place_down
	step_end

# 27 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_2:
# 27 "data/maps/Route1N/scripts.pory"
	emote_exclamation_mark
	step_end

TrainerSchoolSign_Text_0:
# 6 "data/maps/Route1N/scripts.pory"
	.string "Let's learn and grow.\n"
	.string "Let's grow and train.\l"
	.string "Unsullied, enjoyable, and academic.\l"
	.string "Everyone starts at the beginning!$"

TrainersSchool_Intro_Text_0:
# 17 "data/maps/Route1N/scripts.pory"
	.string "Kukui$"

TrainersSchool_Intro_Text_1:
# 19 "data/maps/Route1N/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "I must've passed you two somehow, yeah?\p"
	.string "But welcome to the Trainers' School,\n"
	.string "the place to learn how to be a Pokémon\l"
	.string "Trainer!$"

TrainersSchool_Intro_Text_2:
# 28 "data/maps/Route1N/scripts.pory"
	.string "Professor Kukui!\n"
	.string "Is this the child you told me about?$"
