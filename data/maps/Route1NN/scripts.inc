Route1NN_MapScripts::
	.byte 0


Route1NN_Trigger_GetStarters::
	return


Route1NN_Rockruff::
# 10 "data/maps/Route1NN/scripts.pory"
	lock
# 11 "data/maps/Route1NN/scripts.pory"
	faceplayer
# 12 "data/maps/Route1NN/scripts.pory"
	emote_heart
# 13 "data/maps/Route1NN/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 14 "data/maps/Route1NN/scripts.pory"
	playse SE_PIN
# 15 "data/maps/Route1NN/scripts.pory"
	applymovement route1nnrockruff, Route1NN_Rockruff_Movement_0
# 16 "data/maps/Route1NN/scripts.pory"
	waitmovement route1nnrockruff
# 17 "data/maps/Route1NN/scripts.pory"
	msgbox Route1NN_Rockruff_Text_0, MSGBOX_AUTOCLOSE
# 18 "data/maps/Route1NN/scripts.pory"
	release
	end


# 15 "data/maps/Route1NN/scripts.pory"
Route1NN_Rockruff_Movement_0:
# 15 "data/maps/Route1NN/scripts.pory"
	emote_heart
	step_end

Route1NN_Rockruff_Text_0:
# 17 "data/maps/Route1NN/scripts.pory"
	.string "Ruff!$"
