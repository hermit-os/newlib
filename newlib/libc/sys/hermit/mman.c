#include <errno.h>
#include <sys/mman.h>

void *mmap(void *addr, size_t len, int prot, int flags, int fildes, off_t off) {
    errno = ENOSYS;
    return MAP_FAILED;
}

int munmap(void *addr, size_t len) {
    errno = ENOSYS;
    return -1;
}

int mprotect(void *addr, size_t len, int prot) {
    errno = ENOSYS;
    return -1;
}
