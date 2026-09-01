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
	setvar VAR_IKITOWN_STATE, 22
# 17 "data/maps/Route1N/scripts.pory"
	applymovement LOCALID_PLAYER, TrainersSchool_Intro_Movement_0
# 18 "data/maps/Route1N/scripts.pory"
	waitmovement LOCALID_PLAYER
# 19 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_Intro_Movement_1
# 20 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_lillie
# 21 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_kukui, TrainersSchool_Intro_Movement_2
# 22 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_kukui
# 23 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 24 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_1
# 30 "data/maps/Route1N/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 31 "data/maps/Route1N/scripts.pory"
	playse SE_PIN
# 32 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_teacher, TrainersSchool_Intro_Movement_3
# 33 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_teacher
# 34 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_2
# 36 "data/maps/Route1N/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 37 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 38 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_3
# 40 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_kukui, TrainersSchool_Intro_Movement_4
# 41 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 42 "data/maps/Route1N/scripts.pory"
	waitse
# 43 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 44 "data/maps/Route1N/scripts.pory"
	waitse
# 45 "data/maps/Route1N/scripts.pory"
	waitmovement 0
# 46 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_4
# 56 "data/maps/Route1N/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 57 "data/maps/Route1N/scripts.pory"
	giveitem ITEM_EXP_SHARE, 1
# 58 "data/maps/Route1N/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 59 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 60 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_5
# 63 "data/maps/Route1N/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 64 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_teacher, TrainersSchool_Intro_Movement_2
# 65 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_6
# 73 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_kukui, TrainersSchool_Intro_Movement_4
# 74 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 75 "data/maps/Route1N/scripts.pory"
	waitse
# 76 "data/maps/Route1N/scripts.pory"
	playse SE_LEDGE
# 77 "data/maps/Route1N/scripts.pory"
	waitse
# 78 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_7
# 79 "data/maps/Route1N/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 80 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_teacher, TrainersSchool_Intro_Movement_5
# 81 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_teacher
# 82 "data/maps/Route1N/scripts.pory"
	removeobject trainerschool_teacher
# 83 "data/maps/Route1N/scripts.pory"
	setflag FLAG_HIDE_TRAINERSCHOOL_TEACHER
# 84 "data/maps/Route1N/scripts.pory"
	speakername TrainersSchool_Intro_Text_0
# 85 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_8
# 88 "data/maps/Route1N/scripts.pory"
	applymovement trainerschool_lillie, TrainersSchool_Intro_Movement_6
# 89 "data/maps/Route1N/scripts.pory"
	waitmovement trainerschool_lillie
# 90 "data/maps/Route1N/scripts.pory"
	msgbox TrainersSchool_Intro_Text_9
# 103 "data/maps/Route1N/scripts.pory"
	release
	end


# 17 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_0:
# 17 "data/maps/Route1N/scripts.pory"
	walk_up
	step_end

# 19 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_1:
# 19 "data/maps/Route1N/scripts.pory"
	face_left
	step_end

# 21 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_2:
# 21 "data/maps/Route1N/scripts.pory"
	walk_in_place_down
# 21 "data/maps/Route1N/scripts.pory"
	walk_in_place_down
	step_end

# 32 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_3:
# 32 "data/maps/Route1N/scripts.pory"
	emote_exclamation_mark
	step_end

# 40 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_4:
# 40 "data/maps/Route1N/scripts.pory"
	jump_in_place_down
# 40 "data/maps/Route1N/scripts.pory"
	jump_in_place_down
	step_end

# 80 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_5:
# 80 "data/maps/Route1N/scripts.pory"
	walk_up
# 80 "data/maps/Route1N/scripts.pory"
	walk_up
# 80 "data/maps/Route1N/scripts.pory"
	walk_up
# 80 "data/maps/Route1N/scripts.pory"
	walk_up
# 80 "data/maps/Route1N/scripts.pory"
	walk_up
	step_end

# 88 "data/maps/Route1N/scripts.pory"
TrainersSchool_Intro_Movement_6:
# 88 "data/maps/Route1N/scripts.pory"
	face_down
	step_end

TrainerSchoolSign_Text_0:
# 6 "data/maps/Route1N/scripts.pory"
	.string "Let's learn and grow.\n"
	.string "Let's grow and train.\l"
	.string "Unsullied, enjoyable, and academic.\l"
	.string "Everyone starts at the beginning!$"

TrainersSchool_Intro_Text_0:
# 23 "data/maps/Route1N/scripts.pory"
	.string "Kukui$"

TrainersSchool_Intro_Text_1:
# 24 "data/maps/Route1N/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "I must've passed you somehow, yeah?\p"
	.string "But welcome to the Trainers' School,\n"
	.string "the place to learn how to be a Pokémon\l"
	.string "Trainer!$"

TrainersSchool_Intro_Text_2:
# 34 "data/maps/Route1N/scripts.pory"
	.string "Professor Kukui!\n"
	.string "Is this the child you told me about?$"

TrainersSchool_Intro_Text_3:
# 38 "data/maps/Route1N/scripts.pory"
	.string "Yeah. {PLAYER}'s a tough one,too.\n"
	.string "Put em through the wringer good, Teach!$"

TrainersSchool_Intro_Text_4:
# 46 "data/maps/Route1N/scripts.pory"
	.string "Four Trainers!\p"
	.string "You've got to beat four Pokémon\n"
	.string "Trainers at the school, {PLAYER}!\p"
	.string "The experience will surely help you\n"
	.string "and your Pokemon grow stronger, yeah.\p"
	.string "Actually… Speaking of experience,\n"
	.string "why don't you take this.$"

TrainersSchool_Intro_Text_5:
# 60 "data/maps/Route1N/scripts.pory"
	.string "If you keep that Exp. Share on, yeah,\n"
	.string "all the Pokémon on your team can get\l"
	.string "Exp. Points from battle.$"

TrainersSchool_Intro_Text_6:
# 65 "data/maps/Route1N/scripts.pory"
	.string "The Trainers who will take part in this\n"
	.string "lesson may be in or outside the school.\p"
	.string "You may also want to visit our\n"
	.string "classrooms.\p"
	.string "You'll learn things there that will\n"
	.string "help on your journey, I'd say.$"

TrainersSchool_Intro_Text_7:
# 78 "data/maps/Route1N/scripts.pory"
	.string "All right. Let the lesson begin!$"

TrainersSchool_Intro_Text_8:
# 85 "data/maps/Route1N/scripts.pory"
	.string "She may not look all that tough, but\n"
	.string "that each trains her kids right!\l"
	.string "One of her students is even a captain!$"

TrainersSchool_Intro_Text_9:
# 90 "data/maps/Route1N/scripts.pory"
	.string "If you want a bit of advice from me,\n"
	.string "here's something that might help.\p"
	.string "Once you've fought a species of\n"
	.string "Pokémon once, You can easily see\l"
	.string "what types of moves will work best\l"
	.string "on it in your next battle.\p"
	.string "Wandering about in the tall grass to\n"
	.string "meet lots of different Pokémon'll\l"
	.string "help with that!\l"
	.string "Battle all the time, oh yeah!$"
