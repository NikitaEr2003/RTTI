#ifndef CUSTOMSLEEP_H
#define CUSTOMSLEEP_H
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
void CustomSleep();
#endif