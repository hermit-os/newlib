#include <time.h>

int sys_clock_nanosleep(clockid_t clock_id, int flags,
                        const struct timespec *rqtp, struct timespec *rmtp);

int clock_nanosleep(clockid_t clock_id, int flags, const struct timespec *rqtp,
                    struct timespec *rmtp) {
    return sys_clock_nanosleep(clock_id, flags, rqtp, rmtp);
}
