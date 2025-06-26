#ifndef _SYS_VM_H
#define _SYS_VM_H

#include <sys/cdefs.h>
#include <sys/socket.h>

__BEGIN_DECLS

struct sockaddr_vm {
    uint8_t svm_len;
    sa_family_t svm_family;
    unsigned short svm_reserved1;
    unsigned int svm_port;
    unsigned int svm_cid;
    unsigned char svm_zero[4];
};

#define VMADDR_CID_ANY -1U
#define VMADDR_CID_HYPERVISOR 0
#define VMADDR_CID_LOCAL 1
#define VMADDR_CID_HOST 2

#define VMADDR_PORT_ANY -1U

__END_DECLS

#endif /* _SYS_VM_H */
