#include <unistd.h>

void sys_exit(int status);

void _exit(int status) {
	sys_exit(status);
}
