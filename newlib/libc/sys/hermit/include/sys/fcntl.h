#ifndef _SYS_FCNTL_H
#define _SYS_FCNTL_H

#include <sys/types.h>

#define F_DUPFD  0
#define F_GETFD  1
#define F_SETFD  2
#define F_GETFL  3
#define F_SETFL  4
#define F_GETLK  5
#define F_SETLK  6
#define F_SETLKW 7

int fcntl(int fildes, int cmd, ...);

#define O_RDONLY    0000000
#define O_WRONLY    0000001
#define O_RDWR      0000002
#define O_CREAT     0000100
#define O_EXCL      0000200
#define O_TRUNC     0001000
#define O_APPEND    0002000
#define O_NONBLOCK  0004000
#define O_DIRECT    0040000
#define O_DIRECTORY 0200000

#define O_ACCMODE (O_RDONLY|O_WRONLY|O_RDWR)

int open(const char *path, int oflag, ...);

#endif /* _SYS_FCNTL_H */
