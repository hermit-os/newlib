#include <stdio.h>
#include <sys/stat.h>

__attribute__((weak)) mode_t sys_umask(mode_t cmask) {
    fprintf(stderr, "weak sys_umask() called. Symbol was not replaced!\n");
    return 0;
}

mode_t umask(mode_t cmask) {
    return sys_umask(cmask);
}
