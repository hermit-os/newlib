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

#define FD_CLOEXEC 1

int fcntl(int fildes, int cmd, ...);

#define O_RDONLY    00000000
#define O_WRONLY    00000001
#define O_RDWR      00000002
#define O_CREAT     00000100
#define O_EXCL      00000200
#define O_TRUNC     00001000
#define O_APPEND    00002000
#define O_NONBLOCK  00004000
#define O_DIRECT    00040000
#define O_DIRECTORY 00200000
#define O_CLOEXEC   02000000

#define O_ACCMODE (O_RDONLY|O_WRONLY|O_RDWR)

int open(const char *path, int oflag, ...);

#endif /* _SYS_FCNTL_H */
