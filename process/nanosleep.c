#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

struct timespec;
int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int ret = -1;

    do
    {
        ret = syscall(__NR_nanosleep, req, rem);
        req = rem;
    } while (ret == -1);

    return ret;
}