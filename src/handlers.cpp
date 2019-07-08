#include "handlers.h"

#include "client_id.h"
#include "discord_rpc.h"

#include <string.h>

namespace discord_rpc
{
	void handleDiscordReady(const DiscordUser* connectedUser) {
		return;
	}

	void handleDiscordDisconnected(int errcode, const char* message) {
		return;
	}

	void handleDiscordError(int errcode, const char* message) {
		return;
	}

	void init() 
	{
		DiscordEventHandlers handlers;
		memset(&handlers, 0, sizeof(handlers));
		handlers.ready = handleDiscordReady;
		handlers.disconnected = handleDiscordDisconnected;
		handlers.errored = handleDiscordError;
		Discord_Initialize(CLIENT_ID, &handlers, 1, NULL);
	}

	void update(const char* state, const char* details)
	{
		DiscordRichPresence presence;
		memset(&presence, 0, sizeof(presence));
		presence.state = state;
		presence.details = details;
		Discord_UpdatePresence(&presence);
	}
}
