#include <errno.h>
#include <netdb.h>
#include <stdio.h>

__attribute__((weak)) void sys_freeaddrinfo(struct addrinfo *ai) {
    fprintf(stderr,
            "weak sys_freeaddrinfo() called. Symbol was not replaced!\n");
}

void freeaddrinfo(struct addrinfo *ai) {
    return sys_freeaddrinfo(ai);
}

__attribute__((weak)) const char *sys_gai_strerror(int ecode) {
    const char *msg =
        "weak sys_gai_strerror() called. Symbol was not replaced!\n";
    fprintf(stderr, msg);
    return msg;
}

const char *gai_strerror(int ecode) {
    return sys_gai_strerror(ecode);
}

__attribute__((weak)) int sys_getaddrinfo(const char *restrict nodename,
                                          const char *restrict servname,
                                          const struct addrinfo *restrict hints,
                                          struct addrinfo **restrict res) {
    fprintf(stderr,
            "weak sys_getaddrinfo() called. Symbol was not replaced!\n");
    errno = ENOSYS;
    return EAI_SYSTEM;
}

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
