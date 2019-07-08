#pragma once

#include "discord_rpc.h"

namespace discord_rpc
{
	void handleDiscordReady(const DiscordUser* connectedUser);
	void handleDiscordDisconnected(int errcode, const char* message);
	void handleDiscordError(int errcode, const char* message);

	void init();
	void update(const char* state, const char* details);
}
