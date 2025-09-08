#include <errno.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/ioctl.h>

__attribute__((weak)) int sys_ioctl(int fd, int op, void *argp) {
    fprintf(stderr, "weak sys_ioctl() called. Symbol was not replaced!\n");
    errno = ENOSYS;
    return -1;
}

int ioctl(int fd, int op, ...) {
    void *argp = NULL;

    int has_argp = op == FIONBIO;
    if (has_argp) {
        va_list args;
        va_start(args, op);
        argp = va_arg(args, void *);
        va_end(args);
    }

    int ret = sys_ioctl(fd, op, argp);

    if (ret < 0) {
        ret = -1;
    }

    return ret;
}
