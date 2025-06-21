#ifndef _NET_IF_H
#define _NET_IF_H

#include <sys/cdefs.h>

__BEGIN_DECLS

struct if_nameindex {
    unsigned if_index;
    char *if_name;
};

#define IF_NAMESIZE 16

void if_freenameindex(struct if_nameindex *ptr);
char *if_indextoname(unsigned ifindex, char *ifname);
struct if_nameindex *if_nameindex(void);
unsigned if_nametoindex(const char *ifname);

__END_DECLS

#endif /* _NET_IF_H */
