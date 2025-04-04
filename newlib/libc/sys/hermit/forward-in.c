#include <dirent.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <time.h>
#include <unistd.h>

// dirent.h

ssize_t getdents64(int fd, void *dirp, size_t count);

// poll.h

int poll(struct pollfd *fds, nfds_t nfds, int timeout);

// sys/socket.h

int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
int bind(int socket, const struct sockaddr *address, socklen_t address_len);
int connect(int socket, const struct sockaddr *address, socklen_t address_len);
int getpeername(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
int getsockname(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
int getsockopt(int socket, int level, int option_name, void *restrict option_value, socklen_t *restrict option_len);
int listen(int socket, int backlog);
int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
int shutdown(int socket, int how);
int socket(int domain, int type, int protocol);
ssize_t recvfrom(int socket, void *restrict buffer, size_t length, int flags, struct sockaddr *restrict address, socklen_t *restrict address_len);
ssize_t recv(int socket, void *buffer, size_t length, int flags);
ssize_t send(int socket, const void *buffer, size_t length, int flags);
ssize_t sendto(int socket, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);

// sys/stat.h

int fstat(int fildes, struct stat *buf);
int lstat(const char *restrict path, struct stat *restrict buf);
int mkdir(const char *path, mode_t mode);
int stat(const char *restrict path, struct stat *restrict buf);

// sys/time.h

int gettimeofday(struct timeval *restrict tp, void *restrict tzp);

// sys/uio.h

ssize_t readv(int fildes, const struct iovec *iov, int iovcnt);
ssize_t writev(int fildes, const struct iovec *iov, int iovcnt);

// time.h

int clock_getres(clockid_t clock_id, struct timespec *res);
int clock_gettime(clockid_t clock_id, struct timespec *tp);
int clock_settime(clockid_t clock_id, const struct timespec *tp);
int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);

// unistd.h

int close(int fildes);
int dup(int fildes);
int dup2(int fildes, int fildes2);
off_t lseek(int fildes, off_t offset, int whence);
ssize_t read(int fildes, void *buf, size_t nbyte);
int rmdir(const char *path);
int unlink(const char *path);
ssize_t write(int fildes, const void *buf, size_t nbyte);
