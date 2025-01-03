#ifndef SOCKET_H
#define SOCKET_H

#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

/* Protocol families, same as address families. */
#define PF_INET AF_INET

// Define socket address structure
#define sa_family_t __sa_family_t

typedef struct sockaddr {
  uint8_t sa_len;
  uint8_t sa_family;
  uint8_t sa_data[14];
};

// Define socket API functions
int socket(int domain, int type, int protocol);
int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
int listen(int socket, int backlog);
int bind(int socket, const struct sockaddr *address, socklen_t address_len);
int connect(int socket, const struct sockaddr *address, socklen_t address_len);
int getsockname(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
int getsockopt(int socket, int level, int option_name, void *restrict option_value, socklen_t *restrict option_len);
int getpeername(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
void freeaddrinfo(struct addrinfo *ai);
int getaddrinfo(const char *restrict nodename, const char *restrict servname, const struct addrinfo *restrict hints, struct addrinfo **restrict res);
ssize_t send(int socket, const void *buffer, size_t length, int flags);
int shutdown(int socket, int how);
ssize_t recv(int socket, void *buffer, size_t length, int flags);
ssize_t sendto(int socket, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);
ssize_t recvfrom(int socket, void *restrict buffer, size_t length, int flags, struct sockaddr *restrict address, socklen_t *restrict address_len);

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

#define EAI_NONAME -2200
#define EAI_SERVICE -2201
#define EAI_FAIL -2202
#define EAI_MEMORY -2203
#define EAI_FAMILY -2204

// Seperate defines
#define SO_SNDBUF       0x1001
#define SO_RCVBUF       0x1002


#define FD_BIT	      (1 << 30)
#define FD_SETSIZE    32
#define FD_SET(n, p)  ((p)->fd_bits[((n) & ~FD_BIT)/8] |=  (1 << (((n) & ~FD_BIT) & 7)))
#define FD_CLR(n, p)  ((p)->fd_bits[((n) & ~FD_BIT)/8] &= ~(1 << (((n) & ~FD_BIT) & 7)))
#define FD_ISSET(n,p) ((p)->fd_bits[((n) & ~FD_BIT)/8] &   (1 << (((n) & ~FD_BIT) & 7)))
#define FD_ZERO(p)    memset((void*)(p),0,sizeof(*(p)))

typedef struct fd_set {
	unsigned char fd_bits [(FD_SETSIZE+7)/8];
} fd_set;

__END_DECLS

#endif /* SOCKET_H */