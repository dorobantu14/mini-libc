#include "time.h"

unsigned int sleep(unsigned int seconds)
{
    struct timespec req;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    struct timespec rem;

    while (nanosleep(&req, &rem) == -1)
    {
        req = rem;
    }

    return 0;
}
