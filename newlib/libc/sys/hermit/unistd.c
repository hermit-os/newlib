#include <unistd.h>

void sys_exit(int status);

void _exit(int status) {
	sys_exit(status);
}

pid_t sys_getpid(void);

pid_t getpid(void) {
	return sys_getpid();
}
