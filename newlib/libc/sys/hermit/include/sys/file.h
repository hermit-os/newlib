#ifndef _SYS_FILE_H
#define _SYS_FILE_H

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

#warning "sys/file.h is not required by POSIX but is provided for Linux compatibility. Don't use sys/file.h if possible."

// See https://www.man7.org/linux/man-pages/man2/flock.2.html
#define LOCK_SH	1
#define LOCK_EX	2
#define LOCK_NB	4
#define LOCK_UN	8

static inline int flock(int fd, int op) {
    // Stubbed
    return 0;
}

__END_DECLS

#endif /* _SYS_FILE_H */
