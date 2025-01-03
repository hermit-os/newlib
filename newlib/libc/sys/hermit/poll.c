#include <poll.h>

int sys_poll(struct pollfd fds[], nfds_t nfds, int timeout);

int poll(struct pollfd fds[], nfds_t nfds, int timeout) {
    return sys_poll(fds, nfds, timeout);
}
