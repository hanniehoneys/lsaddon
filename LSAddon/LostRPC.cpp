#include "stdafx.h"
#include "LostRPC.h"


static const char* APPLICATION_ID = ""; //https://discord.com/developers/applications
static int64_t StartTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();


LSAddon_API void SetDiscordID(const char* szDiscordID) {
	//APPLICATION_ID = szDiscordID;
}

void SetupDiscord() {
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize(APPLICATION_ID, &handlers, 1, NULL);
}

LSAddon_API void UpdateLostRPC(const char* szDetail, const char* szState) {

	SetupDiscord();
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = szState;
	discordPresence.details = szDetail;
	discordPresence.startTimestamp = StartTime;
	discordPresence.endTimestamp = NULL;
	discordPresence.largeImageKey = "main_logo"; //name images from discord developer
	discordPresence.largeImageText = "Lost Saga";
	discordPresence.smallImageKey = "second_logo"; //name images from discord developer
	discordPresence.smallImageText = "Private Server";

	Discord_UpdatePresence(&discordPresence);
}


LostRPC::LostRPC()
{
}

LostRPC::~LostRPC()
{
}

LSAddon_API LostRPC LSAddon;

