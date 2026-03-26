#ifndef GUARD_TITLE_SCREEN_H
#define GUARD_TITLE_SCREEN_H

extern const u16 gTitleScreenAlphaBlend[64];

void CB2_InitTitleScreen(void);
void CB2_InitTitleScreenFrlg(void);

// Assumes SaveBlock Values will be one of these values.
enum TitleScreenPokemon
{
    TSP_ULTRA_NECROZMA,
    TSP_SOLGALEO,
    TSP_LUNALA,
    TSP_COUNT_RANDOM,
    TSP_TIME,
};
#define DEFAULT_TITLE_SCREEN TSP_TIME

#endif // GUARD_TITLE_SCREEN_H
