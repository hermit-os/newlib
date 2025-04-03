#ifndef _SYS_IOCTL_H
#define _SYS_IOCTL_H

#include <sys/cdefs.h>

__BEGIN_DECLS

#define FIONBIO 0x8008667e

int ioctl(int fd, int op, ...);

__END_DECLS

#endif /* _SYS_IOCTL_H */
