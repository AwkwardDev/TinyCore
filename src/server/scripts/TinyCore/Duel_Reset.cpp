#include "ScriptPCH.h"
 
class Duel_Reset : public PlayerScript
{
        public:
                Duel_Reset() : PlayerScript("Duel_Reset"){}
 
                void OnDuelEnd(Player* Plr, Player* Plr2, DuelCompleteType /*type*/)
                {
                        Plr->SetHealth(Plr->GetMaxHealth());
                        Plr->RemoveArenaSpellCooldowns();
                        Plr->ResetAllPowers();
                        Plr2->SetHealth(Plr2->GetMaxHealth());
                        Plr2->RemoveArenaSpellCooldowns();
                        Plr2->ResetAllPowers();
                }
};
 
void AddSC_Duel_Reset()
{
        new Duel_Reset();
}