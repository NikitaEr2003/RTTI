#include "CustomClear.h"
#include <cstdlib>

void CustomClear()
{
#ifdef _WIN32
    system ("cls");
#else
    system ("clear");
#endif
}
