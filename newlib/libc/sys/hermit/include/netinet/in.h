#ifndef _NETINET_IN_H
#define _NETINET_IN_H

#include <stddef.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <netdb.h>

__BEGIN_DECLS

// Functions for converting between string and network addresses
int inet_pton(int af, const char *src, void *dst);
const char *inet_ntop(int af, const void *src, char *dst, __socklen_t size);
char *inet_ntoa(struct in_addr in);
in_addr_t inet_addr(const char *cp);

typedef uint16_t in_port_t;
#define htons __htons
#define htonl __htonl
#define ntohl __ntohl
#define ntohs __ntohs

// Functions for converting between host and network byte order
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);

int inet_pton(int af, const char *src, void *dst);

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
