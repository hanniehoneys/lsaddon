#pragma once
class ioPlayStage;
class ioDiscordManager : public Singleton< ioDiscordManager >
{
public:
	ioDiscordManager();
	~ioDiscordManager();
	
public:
	static ioDiscordManager& GetSingleton();
	void Initialize();
	void FisrtStageAndState();
	void GetStageAndState();

};

#define g_DiscordManager ioDiscordManager::GetSingleton()