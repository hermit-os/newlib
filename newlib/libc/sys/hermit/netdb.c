#include <netdb.h>

void sys_freeaddrinfo(struct addrinfo *ai);

void freeaddrinfo(struct addrinfo *ai) {
    return sys_freeaddrinfo(ai);
}

int sys_getaddrinfo(const char *restrict nodename, const char *restrict servname, const struct addrinfo *restrict hints, struct addrinfo **restrict res);

int getaddrinfo(const char *restrict nodename, const char *restrict servname, const struct addrinfo *restrict hints, struct addrinfo **restrict res) {
    return sys_getaddrinfo(nodename, servname, hints, res);
}
