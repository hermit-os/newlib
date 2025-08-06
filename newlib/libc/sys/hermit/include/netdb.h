#ifndef _NETDB_H
#define _NETDB_H

#include <netinet/in.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/socket.h>

__BEGIN_DECLS

struct addrinfo {
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    socklen_t ai_addrlen;
    char *ai_canonname;
    struct sockaddr *ai_addr;
    struct addrinfo *ai_next;
};

#define AI_PASSIVE 0x001
#define AI_CANONNAME 0x002
#define AI_NUMERICHOST 0x004
#define AI_NUMERICSERV 0x008
#define AI_ALL 0x100
#define AI_ADDRCONFIG 0x400
#define AI_V4MAPPED 0x800

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
const char *gai_strerror(int ecode);
int getaddrinfo(const char *restrict nodename, const char *restrict servname,
                const struct addrinfo *restrict hints,
                struct addrinfo **restrict res);

__END_DECLS

#endif /* _NETDB_H */
