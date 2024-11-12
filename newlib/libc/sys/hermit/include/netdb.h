#ifndef NETDB_H
#define NETDB_H

#include <stdint.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

#define socklen_t __socklen_t

typedef struct addrinfo_t {
    int32_t ai_flags;
    int32_t ai_family;
    int32_t ai_socktype;
    int32_t ai_protocol;
    socklen_t ai_addrlen;
    struct sockaddr *ai_addr;
    uint8_t *ai_canonname;
    struct addrinfo_t *ai_next;
} addrinfo;

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

__END_DECLS

#endif /* NETDB_H */