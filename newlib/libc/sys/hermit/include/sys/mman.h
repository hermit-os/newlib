#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H

#include <fcntl.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

#define PROT_NONE (0)
#define PROT_READ (1 << 0)
#define PROT_WRITE (1 << 1)
#define PROT_EXEC (1 << 2)

// TODO: The `MAP_*` constants are placeholders.
// The kernel does not have any such constants yet.
#define MAP_ANON (1 << 0)
#define MAP_ANONYMOUS (1 << 1)
#define MAP_SHARED (1 << 2)
#define MAP_PRIVATE (1 << 3)
#define MAP_FIXED (1 << 4)
#define MAP_FAILED ((void *)-1)

void *mmap(void *addr, size_t len, int prot, int flags, int fildes, off_t off);
int munmap(void *addr, size_t len);
int mprotect(void *addr, size_t len, int prot);

__END_DECLS

#endif /* _SYS_MMAN_H */
