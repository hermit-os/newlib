#ifndef _ARPA_INET_H
#define _ARPA_INET_H

#include <inttypes.h>
#include <netinet/in.h>
#include <sys/cdefs.h>
#include <sys/socket.h>

__BEGIN_DECLS

#define htonl __htonl
#define htons __htons
#define ntohl __ntohl
#define ntohs __ntohs

uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);

in_addr_t inet_addr(const char *cp);
char *inet_ntoa(struct in_addr in);
const char *inet_ntop(int af, const void *restrict src, char *restrict dst, socklen_t size);
int inet_pton(int af, const char *restrict src, void *restrict dst);

__END_DECLS

#endif /* _ARPA_INET_H */
