#ifndef _SYS_SOCKET_H
#define _SYS_SOCKET_H

#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

typedef __socklen_t socklen_t;
typedef __sa_family_t sa_family_t;

struct sockaddr {
  uint8_t sa_len;
  sa_family_t sa_family;
  char sa_data[14];
};

// Define socket API functions
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

// Defines from librs
#define AF_INET 0
#define AF_INET6 1

#define IPPROTO_IP 0
#define IPPROTO_IPV6 41
#define IPPROTO_TCP 6
#define IPPROTO_UDP 17

#define IPV6_ADD_MEMBERSHIP 12
#define IPV6_DROP_MEMBERSHIP 13
#define IPV6_MULTICAST_LOOP 19
#define IPV6_V6ONLY 27

#define IP_TTL 2
#define IP_MULTICAST_TTL 5
#define IP_MULTICAST_LOOP 7
#define IP_ADD_MEMBERSHIP 3
#define IP_DROP_MEMBERSHIP 4

#define SHUT_RD 0
#define SHUT_WR 1
#define SHUT_RDWR 2

#define SOCK_DGRAM 2
#define SOCK_STREAM 1
#define SOCK_NONBLOCK O_NONBLOCK

#define SOL_SOCKET 4095

#define SO_REUSEADDR 0x0004
#define SO_KEEPALIVE 0x0008
#define SO_BROADCAST 0x0020
#define SO_LINGER 0x0080
#define SO_SNDBUF 0x1001
#define SO_RCVBUF 0x1002
#define SO_SNDTIMEO 0x1005
#define SO_RCVTIMEO 0x1006
#define SO_ERROR 0x1007

#define TCP_NODELAY 1
#define MSG_PEEK 1
#define FIONBIO (int32_t)2148034174u

// Seperate defines
#define SO_SNDBUF       0x1001
#define SO_RCVBUF       0x1002

__END_DECLS

#endif /* _SYS_SOCKET_H */
