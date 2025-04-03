#include <stdarg.h>
#include <stddef.h>
#include <sys/ioctl.h>

int sys_ioctl(int fd, int op, void *argp);

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
