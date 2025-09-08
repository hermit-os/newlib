#ifndef _SYS_UN_H
#define _SYS_UN_H

#include <sys/cdefs.h>
#include <sys/socket.h>
#include <sys/types.h>

__BEGIN_DECLS

struct sockaddr_un {
    uint8_t sun_len;
    sa_family_t sun_family;
    char sun_path[104];
};

__END_DECLS

#endif /* _SYS_UN_H */
