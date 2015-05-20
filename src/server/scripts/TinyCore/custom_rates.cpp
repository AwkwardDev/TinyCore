#include "ScriptMgr.h"
#include "Chat.h"
#include "Language.h"

class CustomRates
{
public:

	static int32 GetLootRateForVip(const Player *player)
	{
		uint32 LootRate = 1;
		switch(player->GetSession()->GetVipLevel())
		{
		case 1:
			LootRate = sWorld->getIntConfig(CONFIG_VIP_LOOT_RATE_LEVEL);
			break;
		default:
			LootRate = sWorld->getIntConfig(CONFIG_VIP_LOOT_RATE_LEVEL);
			break;
		}
		return LootRate;
	}
};

class add_del_rates : public PlayerScript
{
public:
	add_del_rates() : PlayerScript("add_del_rates") { }

	void OnLogin(Player* player, bool /*loginFirst*/)
	{

		// set custom loot rate for player on login
		uint32 rateLoot = CustomRates::GetLootRateForVip(player);
		player->SetCustomLootRate(static_cast<uint32>(rateLoot));

		ChatHandler(player->GetSession()).PSendSysMessage("Your loot rate is : %u", rateLoot);
	}
};

void AddSC_Custom_Rates()
{
	new add_del_rates();
}