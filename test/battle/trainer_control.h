//
// DO NOT MODIFY THIS FILE! It is auto-generated from test/battle/trainer_control.party
//
// If you want to modify this file see expansion PR #7154
//

#line 1 "test/battle/trainer_control.party"

#line 1
    [DIFFICULTY_NORMAL][TRAINER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_PIC_FRONT_HIKER,
#line 5
        .gender = TRAINER_GENDER_MALE,
#line 6
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_HIKER,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 9
    [DIFFICULTY_NORMAL][1] =
    {
#line 10
        .trainerName = _("RED"),
#line 11
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 12
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 13
        .gender = TRAINER_GENDER_MALE,
#line 14
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 17
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 19
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 18
            .lvl = 5,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 21
    [DIFFICULTY_NORMAL][2] =
    {
#line 22
        .trainerName = _("LEAF"),
#line 23
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 24
        .trainerPic = TRAINER_PIC_FRONT_LEAF,
#line 25
        .gender = TRAINER_GENDER_FEMALE,
#line 26
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 27
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_LEAF,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 29
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 31
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 30
            .lvl = 5,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 34
    [DIFFICULTY_NORMAL][3] =
    {
#line 35
        .trainerName = _("Test1"),
#line 36
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 37
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 38
        .gender = TRAINER_GENDER_MALE,
#line 39
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 40
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 42
            .nickname = COMPOUND_STRING("Bubbles"),
#line 42
            .species = SPECIES_WOBBUFFET,
#line 42
            .gender = TRAINER_MON_FEMALE,
#line 42
            .heldItem = ITEM_ASSAULT_VEST,
#line 47
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 252, 4, 0),
#line 46
            .iv = TRAINER_PARTY_IVS(25, 26, 27, 28, 29, 30),
#line 45
            .ability = ABILITY_TELEPATHY,
#line 44
            .lvl = 67,
#line 50
            .ball = BALL_MASTER,
#line 48
            .friendship = 42,
#line 43
            .nature = NATURE_HASTY,
#line 49
            .isShiny = TRUE,
#line 51
            .dynamaxLevel = 5,
            .shouldUseDynamax = TRUE,
            .moves = {
#line 52
                MOVE_AIR_SLASH,
                MOVE_BARRIER,
                MOVE_SOLAR_BEAM,
                MOVE_EXPLOSION,
            },
            },
            {
#line 57
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 60
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 59
            .ability = ABILITY_SHADOW_TAG,
#line 58
            .lvl = 5,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 62
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 64
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 63
            .lvl = 5,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 66
#line 73
    [DIFFICULTY_NORMAL][4] =
    {
#line 67
        .trainerName = _("Test2"),
#line 68
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 69
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 70
        .gender = TRAINER_GENDER_MALE,
#line 71
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 72
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 75
            .species = SPECIES_MEWTWO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 77
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 76
            .lvl = 5,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 78
#line 85
    [DIFFICULTY_NORMAL][5] =
    {
#line 79
        .trainerName = _("Test2"),
#line 80
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 81
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 82
        .gender = TRAINER_GENDER_MALE,
#line 83
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 84
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 87
            .species = SPECIES_MEWTWO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 89
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 88
            .lvl = 50,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 90
#line 97
    [DIFFICULTY_EASY][5] =
    {
#line 91
        .trainerName = _("Test2"),
#line 92
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 93
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 94
        .gender = TRAINER_GENDER_MALE,
#line 95
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 96
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 99
            .species = SPECIES_METAPOD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 101
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 100
            .lvl = 1,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 102
#line 109
    [DIFFICULTY_HARD][5] =
    {
#line 103
        .trainerName = _("Test2"),
#line 104
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 105
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 106
        .gender = TRAINER_GENDER_MALE,
#line 107
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 108
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 111
            .species = SPECIES_ARCEUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 113
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 112
            .lvl = 99,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 114
    [DIFFICULTY_NORMAL][6] =
    {
#line 115
        .trainerName = _("Test3"),
#line 116
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 117
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 118
        .gender = TRAINER_GENDER_MALE,
#line 119
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 120
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
#line 121
        .partySize = 1,
        .poolSize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 123
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 124
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 124
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 125
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 126
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 126
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 127
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 128
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 128
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 129
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 130
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 130
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 131
    [DIFFICULTY_NORMAL][7] =
    {
#line 132
        .trainerName = _("Test4"),
#line 133
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 134
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 135
        .gender = TRAINER_GENDER_MALE,
#line 136
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 137
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
#line 138
        .partySize = 3,
        .poolSize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 140
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 141
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 141
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 142
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 144
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 144
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 143
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 145
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 147
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 147
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 146
            .tags = MON_POOL_TAG_ACE,
            },
            {
#line 148
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 149
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 149
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 150
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 152
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 152
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 151
            .tags = MON_POOL_TAG_ACE,
            },
            {
#line 153
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 155
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 155
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 154
            .tags = MON_POOL_TAG_LEAD,
            },
        },
    },
#line 156
    [DIFFICULTY_NORMAL][8] =
    {
#line 157
        .trainerName = _("Test5"),
#line 158
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 159
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 160
        .gender = TRAINER_GENDER_MALE,
#line 161
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 162
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 164
        .poolRuleIndex = POOL_RULESET_WEATHER_DOUBLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
#line 163
        .partySize = 3,
        .poolSize = 10,
        .party = (const struct TrainerMon[])
        {
            {
#line 166
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 168
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 168
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 167
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 169
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 171
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 171
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 170
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 172
            .species = SPECIES_VULPIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 174
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 174
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 173
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_SETTER,
            },
            {
#line 175
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 177
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 177
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 176
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_ABUSER,
            },
            {
#line 178
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 180
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 180
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 179
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_SETTER,
            },
            {
#line 181
            .species = SPECIES_CHERRIM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 183
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 183
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 182
            .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_WEATHER_ABUSER,
            },
            {
#line 184
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 186
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 186
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 185
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 187
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 189
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 189
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 188
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 190
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 191
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 191
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 192
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 193
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 193
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 194
    [DIFFICULTY_NORMAL][9] =
    {
#line 195
        .trainerName = _("Test6"),
#line 196
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 197
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 198
        .gender = TRAINER_GENDER_MALE,
#line 199
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 200
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 202
        .poolRuleIndex = POOL_RULESET_BASIC,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
#line 201
        .partySize = 2,
        .poolSize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 204
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 206
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 206
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 205
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 207
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 209
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 209
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 208
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 210
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 212
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 212
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 211
            .tags = MON_POOL_TAG_LEAD,
            },
        },
    },
#line 213
    [DIFFICULTY_NORMAL][10] =
    {
#line 214
        .trainerName = _("Test1"),
#line 215
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 216
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 217
        .gender = TRAINER_GENDER_MALE,
#line 218
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 219
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 221
        .poolRuleIndex = POOL_RULESET_BASIC,
#line 222
        .poolPruneIndex = POOL_PRUNE_TEST,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
#line 220
        .partySize = 2,
        .poolSize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 224
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 225
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 225
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 226
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 228
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 228
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 227
            .tags = MON_POOL_TAG_LEAD,
            },
            {
#line 229
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 230
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 230
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 231
    [DIFFICULTY_NORMAL][11] =
    {
#line 232
        .trainerName = _("Test1"),
#line 233
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 234
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 235
        .gender = TRAINER_GENDER_MALE,
#line 236
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 237
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 239
        .poolRuleIndex = POOL_RULESET_BASIC,
#line 240
        .poolPickIndex = POOL_PICK_LOWEST,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
#line 238
        .partySize = 2,
        .poolSize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 242
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 244
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 244
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 243
            .tags = MON_POOL_TAG_ACE,
            },
            {
#line 245
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 246
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 246
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 247
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 249
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 249
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 248
            .tags = MON_POOL_TAG_LEAD,
            },
        },
    },
#line 250
    [DIFFICULTY_NORMAL][12] =
    {
#line 251
        .trainerName = _("Test9"),
#line 252
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 253
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 254
        .gender = TRAINER_GENDER_MALE,
#line 255
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 256
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
#line 257
        .partySize = 2,
        .poolSize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 259
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 260
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 260
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 261
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 262
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 262
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 263
    [DIFFICULTY_NORMAL][13] =
    {
#line 264
        .trainerName = _("Test10"),
#line 265
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 266
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 267
        .gender = TRAINER_GENDER_MALE,
#line 268
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 269
        .battleType = TRAINER_BATTLE_TYPE_DOUBLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
#line 270
        .partySize = 2,
        .poolSize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 272
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 273
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 273
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 274
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 275
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 275
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 276
    [DIFFICULTY_NORMAL][14] =
    {
#line 277
        .trainerName = _("Test11"),
#line 278
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 279
        .trainerPic = TRAINER_PIC_FRONT_RED,
#line 280
        .gender = TRAINER_GENDER_MALE,
#line 281
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 282
        .battleType = TRAINER_BATTLE_TYPE_SINGLES,
#line 0
        .trainerBackPic = TRAINER_PIC_FRONT_RED,
#line 283
        .partySize = 6,
        .poolSize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 285
            .species = SPECIES_WYNAUT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 286
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 286
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 287
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 288
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 288
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 289
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 290
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 290
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 291
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 292
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 292
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 293
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 294
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 294
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 295
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 296
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 296
            .lvl = 100,
            .ball = POKEBALL_COUNT,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
