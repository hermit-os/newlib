#include "syscall.h"
#include <errno.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>

void sys_exit(int status);

void _exit(int status) {
	sys_exit(status);
}

pid_t sys_getpid(void);

pid_t getpid(void) {
	return sys_getpid();
}

int isatty(int fildes) {
	return fildes < 3;
}

long sysconf(int name) {
	switch (name) {
		case _SC_ARG_MAX: return ARG_MAX;
		case _SC_CLK_TCK: return CLK_TCK;
		case _SC_NPROCESSORS_CONF: return sys_get_processor_count();
		case _SC_NPROCESSORS_ONLN: return sys_get_processor_count();
		case _SC_PAGESIZE: return sys_getpagesize();
		case _SC_PRIORITY_SCHEDULING: return 1;
		case _SC_THREAD_DESTRUCTOR_ITERATIONS: return PTHREAD_DESTRUCTOR_ITERATIONS;
		case _SC_THREAD_KEYS_MAX: return PTHREAD_KEYS_MAX;
		case _SC_THREAD_STACK_MIN: return PTHREAD_STACK_MIN;
		case _SC_THREAD_THREADS_MAX: return PTHREAD_THREADS_MAX;
		case _SC_THREADS: return 1;
		case _SC_TIMERS: return 1;
		case _SC_THREAD_ATTR_STACKADDR: return -1;
		case _SC_THREAD_ATTR_STACKSIZE: return 1;
		case _SC_THREAD_PRIORITY_SCHEDULING: return -1;
		case _SC_THREAD_PRIO_INHERIT: return -1;
		case _SC_THREAD_PRIO_PROTECT: return -1;
		case _SC_THREAD_PROCESS_SHARED: return -1;
		case _SC_THREAD_SAFE_FUNCTIONS: return 1;
		case _SC_VERSION: return _POSIX_VERSION;
		default:
			errno = EINVAL;
			return -1;
	}
}
