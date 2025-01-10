#include <errno.h>
#include <unistd.h>

int chown(const char *path, uid_t owner, gid_t group) {
    errno = ENOSYS;
    return -1;
}
