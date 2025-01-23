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

typedef uint16_t in_port_t;

/** 255.255.255.255 */
#define IPADDR_NONE         ((uint32_t)0xffffffffUL)
/** 127.0.0.1 */
#define IPADDR_LOOPBACK     ((uint32_t)0x7f000001UL)
/** 0.0.0.0 */
#define IPADDR_ANY          ((uint32_t)0x00000000UL)
/** 255.255.255.255 */
#define IPADDR_BROADCAST    ((uint32_t)0xffffffffUL)

/** 255.255.255.255 */
#define INADDR_NONE         IPADDR_NONE
/** 127.0.0.1 */
#define INADDR_LOOPBACK     IPADDR_LOOPBACK
/** 0.0.0.0 */
#define INADDR_ANY          IPADDR_ANY
/** 255.255.255.255 */
#define INADDR_BROADCAST    IPADDR_BROADCAST

__END_DECLS

#endif /* _NETINET_IN_H */
