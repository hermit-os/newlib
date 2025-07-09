#include <errno.h>
#include <poll.h>
#include <sys/select.h>

int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds,
           fd_set *restrict errorfds, struct timeval *restrict timeout) {
    if (nfds < 0 || nfds > FD_SETSIZE) {
        errno = EINVAL;
        return -1;
    }

    struct pollfd *pollfds = calloc(nfds, sizeof(struct pollfd));
    if (pollfds == NULL) {
        errno = ENOMEM;
        return -1;
    }

    nfds_t poll_nfds = 0;

    for (int fd = 0; fd < nfds; ++fd) {
        struct pollfd poll_spec = {.fd = fd, .events = 0};

        if (readfds != NULL && FD_ISSET(fd, readfds)) {
            poll_spec.events |= POLLIN;
        }

        if (writefds != NULL && FD_ISSET(fd, writefds)) {
            poll_spec.events |= POLLOUT;
        }

        if (errorfds != NULL && FD_ISSET(fd, errorfds)) {
            poll_spec.events |= POLLERR;
        }

        if (poll_spec.events != 0) {
            pollfds[poll_nfds] = poll_spec;
            poll_nfds += 1;
        }
    }

    int poll_timeout = -1;
    if (timeout != NULL) {
        poll_timeout = timeout->tv_sec * 1000 + timeout->tv_usec / 1000;
    }

    int ret = poll(pollfds, poll_nfds, poll_timeout);
    if (ret == -1) {
        free(pollfds);
        return ret;
    }

    if (readfds != NULL) {
        FD_ZERO(readfds);
    }

    if (writefds != NULL) {
        FD_ZERO(writefds);
    }

    if (errorfds != NULL) {
        FD_ZERO(errorfds);
    }

    for (int i = 0; i < poll_nfds; ++i) {
        struct pollfd poll_spec = pollfds[i];

        if (readfds != NULL && (poll_spec.revents & POLLIN) == POLLIN) {
            FD_SET(poll_spec.fd, readfds);
        }

        if (writefds != NULL && (poll_spec.revents & POLLOUT) == POLLOUT) {
            FD_SET(poll_spec.fd, writefds);
        }

        if (errorfds != NULL && (poll_spec.revents & POLLERR) == POLLERR) {
            FD_SET(poll_spec.fd, errorfds);
        }
    }

    free(pollfds);
    return ret;
}
