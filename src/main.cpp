#include <iostream>
#include <string>

#include "discord_rpc.h"

#include "client_id.h"
#include "handlers.h"
#include "wait.h"

int main(int argc, const char* argv[])
{
	discord_rpc::init();
	discord_rpc::update("hello, world", "");
	wait(60000);
}
