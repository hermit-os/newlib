#include <signal.h>

int sigaction(int sig, const struct sigaction *restrict act,
              struct sigaction *restrict oact) {
    if (oact != NULL) {
        oact->sa_handler = SIG_IGN;
    }

    return 0;
}
