#pragma once

#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
#endif

void wait(unsigned int ms);