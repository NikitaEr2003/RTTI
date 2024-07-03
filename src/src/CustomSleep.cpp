#include "CustomSleep.h"
#ifdef _WIN32

void CustomSleep()
{
	Sleep(3500);
}

#else
void CustomSleep()
{
	sleep(2);
}
#endif