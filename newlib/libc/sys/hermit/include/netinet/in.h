#ifndef _NETINET_IN_H
#define _NETINET_IN_H

#include <arpa/inet.h>
#include <inttypes.h>
#include <netdb.h>
#include <sys/cdefs.h>
#include <sys/types.h>

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

#define IPPROTO_IP 0
#define IPPROTO_TCP 6
#define IPPROTO_UDP 17
#define IPPROTO_IPV6 41

#define IP_TOS 1
#define IP_TTL 2
#define IP_ADD_MEMBERSHIP 3
#define IP_DROP_MEMBERSHIP 4
#define IP_MULTICAST_TTL 5
#define IP_MULTICAST_LOOP 7

#define IPV6_ADD_MEMBERSHIP 12
#define IPV6_DROP_MEMBERSHIP 13
#define IPV6_MULTICAST_LOOP 19
#define IPV6_V6ONLY 27

__END_DECLS

#endif /* _NETINET_IN_H */
