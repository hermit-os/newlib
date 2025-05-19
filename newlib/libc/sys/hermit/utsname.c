#include <string.h>
#include <sys/utsname.h>

int uname(struct utsname *name) {
    strncpy(name->sysname, "Hermit", SYS_NMLN);
    strncpy(name->nodename, "localhost", SYS_NMLN);
    strncpy(name->release, "unknown", SYS_NMLN);
    strncpy(name->version, "unknown", SYS_NMLN);
    strncpy(name->machine, "unknown", SYS_NMLN);

    return 0;
}
