#include <errno.h>
#include <reent.h>

int *sys_errno_location(void) {
	return &_REENT->_errno;
}
