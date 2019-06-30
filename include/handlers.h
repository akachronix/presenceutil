#pragma once

void handleDiscordReady(const DiscordUser* connectedUser);
void handleDiscordDisconnected(int errcode, const char* message);
void handleDiscordError(int errcode, const char* message);

void init();
void update(const char* state, const char* details, long startTimestamp, long endTimestamp, const char* partyId, int partySize, int partyMax);