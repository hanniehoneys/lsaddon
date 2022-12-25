#include "StdAfx.h"
#include "ioDiscordManager.h"


template<> ioDiscordManager* Singleton< ioDiscordManager >::ms_Singleton = 0;

ioDiscordManager::ioDiscordManager()
{
}

ioDiscordManager::~ioDiscordManager()
{
}

ioDiscordManager& ioDiscordManager::GetSingleton()
{
	return Singleton< ioDiscordManager >::GetSingleton();
}

void ioDiscordManager::Initialize() {
}

void ioDiscordManager::FisrtStageAndState() {
	UpdateLostRPC("Opening Game", "Loading");
}

void ioDiscordManager::GetStageAndState()
{
	char gamestage[MAX_PATH];
	char gamestate[MAX_PATH];
	
	switch (ioPlayMode::GetModeType())
	{
	case MT_MYROOM:
	{
		switch (ioMyRoomMode::GetMyRoomType())
		{
		case MRT_LOBBY:
		{
			SafeSprintf(gamestage, sizeof(gamestage), "Idle");
			SafeSprintf(gamestate, sizeof(gamestate), "Lobby");
		}
		break;
		case MRT_BATTLE:
		case MRT_SHUFFLE:
		case MRT_FIND_MODE:
		{
			SafeSprintf(gamestage, sizeof(gamestage), "In Room");
			SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		}
		break;
		case MRT_LADDER:
		{
			SafeSprintf(gamestage, sizeof(gamestage), "In Room");
			SafeSprintf(gamestate, sizeof(gamestate), "Faction");
		}
		break;
		default:
			SafeSprintf(gamestage, sizeof(gamestage), "NONE");
			break;
		}
		break;
	case MT_SYMBOL:
		SafeSprintf(gamestage, sizeof(gamestage), "Power Stone Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_CATCH:
		SafeSprintf(gamestage, sizeof(gamestage), "Prisoners Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_KING:
		SafeSprintf(gamestage, sizeof(gamestage), "Prisoners Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_TRAINING:
		switch (g_App.GetPlazaModeType() )
		{
		case PT_COMMUNITY:
			SafeSprintf(gamestage, sizeof(gamestage), "Plaza Chat Mode");
			SafeSprintf(gamestate, sizeof(gamestate), "Plaza");
			break;
		case PT_GUILD:
			SafeSprintf(gamestage, sizeof(gamestage), "Plaza Guild Mode");
			SafeSprintf(gamestate, sizeof(gamestate), "Plaza");
			break;
		case PT_BATTLE:
			SafeSprintf(gamestage, sizeof(gamestage), "Plaza Battle Mode");
			SafeSprintf(gamestate, sizeof(gamestate), "Plaza");
			break;
		default:
			SafeSprintf(gamestage, sizeof(gamestage), "NONE");
			SafeSprintf(gamestate, sizeof(gamestate), "NONE");
			break;
		}
		
		break;
	case MT_SURVIVAL:
		SafeSprintf(gamestage, sizeof(gamestage), "Deathmatch Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_TEAM_SURVIVAL:
		SafeSprintf(gamestage, sizeof(gamestage), "Team Deathatch Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_BOSS:
		SafeSprintf(gamestage, sizeof(gamestage), "Boss Raid Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_MONSTER_SURVIVAL:
		SafeSprintf(gamestage, sizeof(gamestage), "Crussade Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_FOOTBALL:
		SafeSprintf(gamestage, sizeof(gamestage), "Soccer Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_GANGSI:
		SafeSprintf(gamestage, sizeof(gamestage), "Zombie Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_DUNGEON_A:
		SafeSprintf(gamestage, sizeof(gamestage), "Deep Forest Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_HEADQUARTERS:
		SafeSprintf(gamestage, sizeof(gamestage), "Training");
		SafeSprintf(gamestate, sizeof(gamestate), "HQ");
		break;
	case MT_CATCH_RUNNINGMAN:
		SafeSprintf(gamestage, sizeof(gamestage), "Panties Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_FIGHT_CLUB:
		SafeSprintf(gamestage, sizeof(gamestage), "Champion Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_TOWER_DEFENSE:
		SafeSprintf(gamestage, sizeof(gamestage), "Deep Forest Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_DARK_XMAS:
		SafeSprintf(gamestage, sizeof(gamestage), "SnowTown Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_FIRE_TEMPLE:
		SafeSprintf(gamestage, sizeof(gamestage), "FireTemple Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_DOUBLE_CROWN:
		SafeSprintf(gamestage, sizeof(gamestage), "Double Crown Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_SHUFFLE_BONUS:
		SafeSprintf(gamestage, sizeof(gamestage), "Daily Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_FACTORY:
		SafeSprintf(gamestage, sizeof(gamestage), "Secret Factory Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_TEAM_SURVIVAL_AI:
		SafeSprintf(gamestage, sizeof(gamestage), "AITeam Deathmatch Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_HOUSE:
		SafeSprintf(gamestage, sizeof(gamestage), "House Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "HQ");
		break;
	case MT_UNDERWEAR:
		SafeSprintf(gamestage, sizeof(gamestage), "Panties Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_CBT:
		SafeSprintf(gamestage, sizeof(gamestage), "Classic Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	case MT_RAID:
		SafeSprintf(gamestage, sizeof(gamestage), "Raid Mode");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
		break;
	
	default:
		SafeSprintf(gamestage, sizeof(gamestage), "NONE");
		SafeSprintf(gamestate, sizeof(gamestate), "NONE");
		break;
	}
	
	}

	//TotalResultMainWnd* pTotalResultMainWnd = dynamic_cast<TotalResultMainWnd*>(g_GUIMgr.FindWnd(TOTAL_RESULT_MAIN_WND));
	
	if (g_GUIMgr.IsShow(NEW_SHOP_WND)) {
		SafeSprintf(gamestage, sizeof(gamestage), "Opening Shop");
	}
	else if (g_GUIMgr.IsShow(MY_INVENTORY_WND)) {
		SafeSprintf(gamestage, sizeof(gamestage), "Opening Inventory");
	}
	else if (g_GUIMgr.IsShow(PET_WND)) {
		SafeSprintf(gamestage, sizeof(gamestage), "Opening Pet Inventory");
	}
	else if (g_GUIMgr.IsShow(PRIATE_RULLET_RENEWAL_WND)) {
		SafeSprintf(gamestage, sizeof(gamestage), "Playing Oak Barel");
	}
	else if (g_GUIMgr.IsShow(TOTAL_RESULT_MAIN_WND)) {
		SafeSprintf(gamestage, sizeof(gamestage), "Showing Result");
	}else if (g_GUIMgr.IsShow(PARTY_SHAM_BATTLE_WND)) {
		SafeSprintf(gamestage, sizeof(gamestage), "In Room");
		SafeSprintf(gamestate, sizeof(gamestate), "Battle");
	}
	/*else if (pTotalResultMainWnd && pTotalResultMainWnd->IsShow()) {
		SafeSprintf(gamestage, sizeof(gamestage), "Showing Result");
	}*/

	UpdateLostRPC(gamestage, gamestate);
	
}

