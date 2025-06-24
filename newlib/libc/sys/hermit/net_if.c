#include <errno.h>
#include <net/if.h>

void if_freenameindex(struct if_nameindex *ptr) {}

char *if_indextoname(unsigned ifindex, char *ifname) {
    errno = ENXIO;
    return NULL;
}

struct if_nameindex *if_nameindex(void) {
    errno = ENOSYS;
    return NULL;
}

unsigned if_nametoindex(const char *ifname) {
    return 0;
}
