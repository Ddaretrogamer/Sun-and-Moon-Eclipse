#ifndef GUARD_SWSH_STORAGE_SYSTEM_H
#define GUARD_SWSH_STORAGE_SYSTEM_H

#include "constants/form_change_types.h"

#define SWSH_STORAGE_SYSTEM TRUE

void ShowPokemonStorageSystemPC_SwSh(void);
void ChooseMonFromStorage_SwSh(void);
void SetMonFormPSS_SwSh(struct BoxPokemon *boxMon, enum FormChanges method);
void SetMonFormPSS_ItemHold_SwSh(struct BoxPokemon *boxMon);
void UpdateSpeciesSpritePSS_SwSh(struct BoxPokemon *boxMon);

#endif // GUARD_SWSH_STORAGE_SYSTEM_H
