#ifndef _NETDB_H
#define _NETDB_H

#include <stdint.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

#define socklen_t __socklen_t

struct addrinfo {
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    socklen_t ai_addrlen;
    struct sockaddr *ai_addr;
    char *ai_canonname;
    struct addrinfo *ai_next;
};

struct in_addr {
    uint32_t s_addr;
};

struct sockaddr_in {
    uint8_t sin_len;
    uint8_t sin_family;
    uint16_t sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};

#define EAI_AGAIN 2
#define EAI_BADFLAGS 3
#define EAI_FAIL 4
#define EAI_FAMILY 5
#define EAI_MEMORY 6
#define EAI_NODATA 7
#define EAI_NONAME 8
#define EAI_SERVICE 9
#define EAI_SOCKTYPE 10
#define EAI_SYSTEM 11
#define EAI_OVERFLOW 14

void freeaddrinfo(struct addrinfo *ai);
int getaddrinfo(const char *restrict nodename, const char *restrict servname, const struct addrinfo *restrict hints, struct addrinfo **restrict res);

__END_DECLS

#endif /* _NETDB_H */
