#ifndef _SYS_UIO_H
#define _SYS_UIO_H

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

struct iovec {
    void *iov_base;
    size_t iov_len;
};

ssize_t readv(int fildes, const struct iovec *iov, int iovcnt);
ssize_t writev(int fildes, const struct iovec *iov, int iovcnt);

__END_DECLS

#endif /* _SYS_UIO_H */
