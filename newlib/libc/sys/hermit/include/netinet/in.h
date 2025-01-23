#ifndef _NETINET_IN_H
#define _NETINET_IN_H

#include <arpa/inet.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <netdb.h>

__BEGIN_DECLS

struct in_addr {
    in_addr_t s_addr;
};

struct sockaddr_in {
    uint8_t sin_len;
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};

#define INADDR_LOOPBACK  ((in_addr_t)0x7f000001)
#define INADDR_ANY       ((in_addr_t)0x00000000)
#define INADDR_BROADCAST ((in_addr_t)0xffffffff)
#define INADDR_NONE      ((in_addr_t)0xffffffff)

__END_DECLS

#endif /* _NETINET_IN_H */
