#include <signal.h>

int sigaction(int sig, const struct sigaction *restrict act,
              struct sigaction *restrict oact) {
    if (oact != NULL) {
        oact->sa_handler = SIG_IGN;
    }

    return 0;
}

int sigaltstack(const stack_t *restrict ss, stack_t *restrict oss) {
    if (oss != NULL) {
        oss->ss_flags = SS_DISABLE;
    }

    return 0;
}
