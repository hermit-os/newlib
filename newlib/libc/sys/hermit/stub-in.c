#include <unistd.h>

// unistd.h

int chown(const char *path, uid_t owner, gid_t group);
int execve(const char *path, char *const argv[], char *const envp[]);
