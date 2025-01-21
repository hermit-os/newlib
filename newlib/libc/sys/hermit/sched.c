#include <sched.h>

void sys_yield(void);

int sched_yield(void) {
    sys_yield();
    return 0;
}
