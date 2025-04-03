#include <time.h>

int sys_clock_nanosleep(clockid_t clock_id, int flags,
                        const struct timespec *rqtp, struct timespec *rmtp);

int clock_nanosleep(clockid_t clock_id, int flags, const struct timespec *rqtp,
                    struct timespec *rmtp) {
    return sys_clock_nanosleep(clock_id, flags, rqtp, rmtp);
}

time_t time(time_t *tloc) {
    struct timespec tp;
    int res = clock_gettime(CLOCK_REALTIME, &tp);
    if (res == -1) {
        return (time_t)-1;
    }

    if (tloc != NULL) {
        *tloc = tp.tv_sec;
    }

    return tp.tv_sec;
}
