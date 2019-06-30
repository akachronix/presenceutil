#include <iostream>
#include <string>
#include <cstring>

#include "wait.h"
#include "handlers.h"

#include "discord_rpc.h"

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
			std::cout << "Enter state (string): ";
			std::cin.ignore();
			std::getline(std::cin, state);

			std::string details;
			std::cout << "Enter details (string): ";
			std::cin.ignore();
			std::getline(std::cin, state);

			long startTimestamp;
			std::cout << "Enter start timestamp (number): ";
			std::cin >> startTimestamp;

			long endTimestamp;
			std::cout << "Enter end timestamp (number): ";
			std::cin >> endTimestamp;

			std::string partyId;
			std::cout << "Enter party ID (string): ";
			std::cin >> partyId;

			int partySize;
			std::cout << "Enter party size (number): ";
			std::cin >> partySize;

			int partyMax;
			std::cout << "Enter party max (number): ";
			std::cin >> partyMax;

			std::cout << '\n';

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

		wait(1000 * presence_duration);
	}

	Discord_Shutdown();
}
