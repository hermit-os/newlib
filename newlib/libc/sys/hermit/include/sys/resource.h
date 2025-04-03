#ifndef _SYS_RESOURCE_H
#define _SYS_RESOURCE_H

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

#define RLIMIT_CPU     0
#define RLIMIT_FSIZE   1
#define RLIMIT_DATA    2
#define RLIMIT_STACK   3
#define RLIMIT_CORE    4
#define RLIMIT_RSS     5
#define RLIMIT_MEMLOCK 6
#define RLIMIT_NPROC   7
#define RLIMIT_NOFILE  8
#define RLIMIT_SBSIZE  9
#define RLIMIT_VMEM    10
#define RLIMIT_AS      RLIMIT_VMEM

#define RLIM_INFINITY  0x7fffffffffffffff
#define RLIM_SAVED_MAX RLIM_INFINITY
#define RLIM_SAVED_CUR RLIM_INFINITY

typedef long long rlim_t;

struct rlimit {
    rlim_t rlim_cur;
    rlim_t rlim_max;
};

int getrlimit(int resource, struct rlimit *rlp);
int setrlimit(int resource, const struct rlimit *rlp);

#define PRIO_PROCESS 0
#define PRIO_PGRP 1
#define PRIO_USER 2

int getpriority(int which, id_t who);
int setpriority(int which, id_t who, int value);

// This belongs into `limits.h`, but gcc overrides that with `include-fixed/limits.h`
#define NZERO 20

__END_DECLS

#endif /* _SYS_RESOURCE_H */
