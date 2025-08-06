#include <errno.h>
#include <netdb.h>

void sys_freeaddrinfo(struct addrinfo *ai);

void freeaddrinfo(struct addrinfo *ai) {
    return sys_freeaddrinfo(ai);
}

const char *sys_gai_strerror(int ecode);

const char *gai_strerror(int ecode) {
    return sys_gai_strerror(ecode);
}

int sys_getaddrinfo(const char *restrict nodename,
                    const char *restrict servname,
                    const struct addrinfo *restrict hints,
                    struct addrinfo **restrict res);

int getaddrinfo(const char *restrict nodename, const char *restrict servname,
                const struct addrinfo *restrict hints,
                struct addrinfo **restrict res) {
    return sys_getaddrinfo(nodename, servname, hints, res);
}

int getnameinfo(const struct sockaddr *restrict sa, socklen_t salen,
                char *restrict node, socklen_t nodelen, char *restrict service,
                socklen_t servicelen, int flags) {
    errno = ENOSYS;
    return EAI_SYSTEM;
}
