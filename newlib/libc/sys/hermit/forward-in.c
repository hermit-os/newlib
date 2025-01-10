#include <poll.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

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

// time.h

int clock_getres(clockid_t clock_id, struct timespec *res);
int clock_gettime(clockid_t clock_id, struct timespec *tp);
int clock_settime(clockid_t clock_id, const struct timespec *tp);

// unistd.h

int close(int fildes);
off_t lseek(int fildes, off_t offset, int whence);
ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);
