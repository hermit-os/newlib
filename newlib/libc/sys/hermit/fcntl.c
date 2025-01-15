#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/stat.h>

int sys_open(const char *path, int oflag, mode_t mode);

int open(const char *path, int oflag, ...) {
    mode_t mode = 0;

    int has_mode = (oflag & O_CREAT) == O_CREAT;
    if (has_mode) {
        va_list args;
        va_start(args, oflag);
        mode = va_arg(args, mode_t);
        va_end(args);
    }

    int ret = sys_open(path, oflag, mode);

    if (ret < 0) {
        errno = -ret;
        ret = -1;
    }

    return ret;
}
