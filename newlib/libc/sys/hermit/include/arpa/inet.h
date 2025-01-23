#ifndef _ARPA_INET_H
#define _ARPA_INET_H

#include <inttypes.h>
#include <netinet/in.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

#define htonl __htonl
#define htons __htons
#define ntohl __ntohl
#define ntohs __ntohs

uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);

__END_DECLS

#endif /* _ARPA_INET_H */
