#ifndef _SYS_UTSNAME_H
#define _SYS_UTSNAME_H

#include <sys/cdefs.h>

__BEGIN_DECLS

#define SYS_NMLN 65

struct utsname {
    char sysname[SYS_NMLN];
    char nodename[SYS_NMLN];
    char release[SYS_NMLN];
    char version[SYS_NMLN];
    char machine[SYS_NMLN];
};

int uname(struct utsname *name);

__END_DECLS

#endif /* _SYS_UTSNAME_H */
