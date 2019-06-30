#include "wait.h"

void wait(unsigned int ms)
{
	#ifdef __linux__
		usleep(ms * 1000);
	#elif _WIN32
		Sleep(ms);
	#endif
}
