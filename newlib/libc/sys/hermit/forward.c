#include <sys/socket.h>

int sys_socket(int domain, int type, int protocol);

int socket(int domain, int type, int protocol) {
    return sys_socket(domain, type, protocol);
}

int sys_accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);

int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len) {
    return sys_accept(socket, address, address_len);
}

int sys_listen(int socket, int backlog);

int listen(int socket, int backlog) {
    return sys_listen(socket, backlog);
}

int sys_bind(int socket, const struct sockaddr *address, socklen_t address_len);

int bind(int socket, const struct sockaddr *address, socklen_t address_len) {
    return sys_bind(socket, address, address_len);
}

int sys_connect(int socket, const struct sockaddr *address, socklen_t address_len);

int connect(int socket, const struct sockaddr *address, socklen_t address_len) {
    return sys_connect(socket, address, address_len);
}

int sys_getsockname(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);

int getsockname(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len) {
    return sys_getsockname(socket, address, address_len);
}

int sys_setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);

int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len) {
    return sys_setsockopt(socket, level, option_name, option_value, option_len);
}

int sys_getsockopt(int socket, int level, int option_name, void *restrict option_value, socklen_t *restrict option_len);

int getsockopt(int socket, int level, int option_name, void *restrict option_value, socklen_t *restrict option_len) {
    return sys_getsockopt(socket, level, option_name, option_value, option_len);
}

int sys_getpeername(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);

int getpeername(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len) {
    return sys_getpeername(socket, address, address_len);
}

void sys_freeaddrinfo(struct addrinfo *ai);

void freeaddrinfo(struct addrinfo *ai) {
    return sys_freeaddrinfo(ai);
}

int sys_getaddrinfo(const char *restrict nodename, const char *restrict servname, const struct addrinfo *restrict hints, struct addrinfo **restrict res);

int getaddrinfo(const char *restrict nodename, const char *restrict servname, const struct addrinfo *restrict hints, struct addrinfo **restrict res) {
    return sys_getaddrinfo(nodename, servname, hints, res);
}

ssize_t sys_send(int socket, const void *buffer, size_t length, int flags);

ssize_t send(int socket, const void *buffer, size_t length, int flags) {
    return sys_send(socket, buffer, length, flags);
}

int sys_shutdown(int socket, int how);

int shutdown(int socket, int how) {
    return sys_shutdown(socket, how);
}

ssize_t sys_recv(int socket, void *buffer, size_t length, int flags);

ssize_t recv(int socket, void *buffer, size_t length, int flags) {
    return sys_recv(socket, buffer, length, flags);
}

ssize_t sys_sendto(int socket, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);

ssize_t sendto(int socket, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len) {
    return sys_sendto(socket, message, length, flags, dest_addr, dest_len);
}

ssize_t sys_recvfrom(int socket, void *restrict buffer, size_t length, int flags, struct sockaddr *restrict address, socklen_t *restrict address_len);

ssize_t recvfrom(int socket, void *restrict buffer, size_t length, int flags, struct sockaddr *restrict address, socklen_t *restrict address_len) {
    return sys_recvfrom(socket, buffer, length, flags, address, address_len);
}
