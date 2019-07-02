#pragma once

#if defined (__linux__) || defined (__APPLE__)
	#include <unistd.h>
#elif _WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
#endif

void wait(unsigned int ms);