#include "wait.h"

void wait(unsigned int ms)
{
	#if defined (__linux__) || defined (__APPLE__)
		usleep(ms * 1000);
	#elif _WIN32
		Sleep(ms);
	#endif
}
