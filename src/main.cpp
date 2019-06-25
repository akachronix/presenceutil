#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>

#include "client_id.h"
#include "discord_rpc.h"

static void handleDiscordReady(const DiscordUser* connectedUser) {
	return;
}

static void handleDiscordDisconnected(int errcode, const char* message) {
	return;
}

static void handleDiscordError(int errcode, const char* message) {
	return;
}

static void init() 
{
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	handlers.ready = handleDiscordReady;
	handlers.disconnected = handleDiscordDisconnected;
	handlers.errored = handleDiscordError;
	Discord_Initialize(CLIENT_ID, &handlers, 1, NULL);
}

static void update(const char* state, const char* details, long startTimestamp, long endTimestamp, const char* partyId, int partySize, int partyMax)
{
	DiscordRichPresence presence;
	memset(&presence, 0, sizeof(presence));
	presence.state = state;
	presence.details = details;
	presence.startTimestamp = startTimestamp;
	presence.endTimestamp = endTimestamp;
	presence.partyId = partyId;
	presence.partySize = partySize;
	presence.partyMax = partyMax;
	Discord_UpdatePresence(&presence);
}

int main(int argc, const char* argv[])
{
	std::cout << "\npresenceutil v1.0\n";
	std::cout << "by chronix\n";
	std::cout << "https://github.com/akachronix\n";
	std::cout << "Licensed under WTFPL. Do what the fuck you want.\n";

	init();

	bool running = true;
	while (running)
	{
		unsigned int presence_duration = 15;

		std::cout << "\n1) Clear Presence\n";
		std::cout << "2) Continue Presence\n";
		std::cout << "3) Set Presence\n";
		std::cout << "4) Exit\n";
		std::cout << '\n';

		unsigned int option = 0;
		std::cin >> option;

		std::cout << '\n';

		if (option == 1)
		{
			Discord_ClearPresence();
			presence_duration = 0;
		}

		else if (option == 2)
		{
			std::cout << "For how long? (seconds) ";
			std::cin >> presence_duration;
			std::cout << '\n';
		}

		else if (option == 3)
		{
			std::string state;
			std::cout << "Enter state: ";
			std::cin >> state;

			std::string details;
			std::cout << "Enter details: ";
			std::cin >> details;

			long startTimestamp;
			std::cout << "Enter start timestamp: ";
			std::cin >> startTimestamp;

			long endTimestamp;
			std::cout << "Enter end timestamp: ";
			std::cin >> endTimestamp;

			std::string partyId;
			std::cout << "Enter party ID: ";
			std::cin >> partyId;

			int partySize;
			std::cout << "Enter party size: ";
			std::cin >> partySize;

			int partyMax;
			std::cout << "Enter party max: ";
			std::cin >> partyMax;

			std::cout << "For how long? (seconds) ";
			std::cin >> presence_duration;
			std::cout << '\n';

			update(state.c_str(), details.c_str(), startTimestamp, endTimestamp, partyId.c_str(), partySize, partyMax);
		}

		else if (option == 4)
		{
			running = false;
			presence_duration = 0;
		}

		usleep(1000000 * presence_duration);
	}

	Discord_Shutdown();
}
