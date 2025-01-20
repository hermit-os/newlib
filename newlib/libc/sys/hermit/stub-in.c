#include <signal.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>

// signal.h

int kill(pid_t pid, int sig);

// sys/time.h

int setitimer(int which, const struct itimerval *restrict value, struct itimerval *restrict ovalue);

// sys/times.h

clock_t times(struct tms *buffer);

// sys/wait.h

pid_t wait(int *stat_loc);

// unistd.h

int chown(const char *path, uid_t owner, gid_t group);
int execl(const char *path, const char *arg0, ... /*, (char *)0 */);
int execle(const char *path, const char *arg0, ... /*, (char *)0, char *const envp[]*/);
int execlp(const char *file, const char *arg0, ... /*, (char *)0 */);
int execv(const char *path, char *const argv[]);
int execve(const char *path, char *const argv[], char *const envp[]);
int execvp(const char *file, char *const argv[]);
int fexecve(int fd, char *const argv[], char *const envp[]);
pid_t fork(void);
int link(const char *path1, const char *path2);
ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize);
int symlink(const char *path1, const char *path2);
int unlink(const char *path);
