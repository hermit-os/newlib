#include <sys/resource.h>

int getrlimit(int resource, struct rlimit *rlp) {
    rlp->rlim_cur = RLIM_INFINITY;
    rlp->rlim_max = RLIM_INFINITY;
    return 0;
}

int setrlimit(int resource, const struct rlimit *rlp) {
    return 0;
}

int getpriority(int which, id_t who) {
    return 0;
}

int setpriority(int which, id_t who, int value) {
    return 0;
}
