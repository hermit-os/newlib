#include <sys/stat.h>

mode_t sys_umask(mode_t cmask);

mode_t umask(mode_t cmask) {
    return sys_umask(cmask);
}
