#include <signal.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>

// signal.h

int kill(pid_t pid, int sig);

// sys/socket.h

ssize_t recvmsg(int socket, struct msghdr *message, int flags);
ssize_t sendmsg(int socket, const struct msghdr *message, int flags);

// sys/stat.h

int chmod(const char *path, mode_t mode);

// sys/time.h

int setitimer(int which, const struct itimerval *restrict value, struct itimerval *restrict ovalue);

// sys/times.h

clock_t times(struct tms *buffer);

// sys/wait.h

pid_t wait(int *stat_loc);

// unistd.h

int chown(const char *path, uid_t owner, gid_t group);
int dup2(int fildes, int fildes2);
int _execve(const char *path, char *const argv[], char *const envp[]);
pid_t fork(void);
int link(const char *path1, const char *path2);
ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize);
int symlink(const char *path1, const char *path2);
int unlink(const char *path);
