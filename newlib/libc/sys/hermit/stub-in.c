#include <sched.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>

// sched.h

int sched_getparam(pid_t pid, struct sched_param *param);
int sched_getscheduler(pid_t pid);
int sched_setparam(pid_t pid, const struct sched_param *param);
int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param);

// signal.h

int kill(pid_t pid, int sig);
int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);

// sys/select.h

int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, struct timeval *restrict timeout);

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
pid_t waitpid(pid_t pid, int *stat_loc, int options);

// unistd.h

int _execve(const char *path, char *const argv[], char *const envp[]);
int execvpe(const char *file, char *const argv[], char *const envp[]);
pid_t fork(void);
int link(const char *path1, const char *path2);
int pipe(int fildes[2]);
int pipe2(int fildes[2], int flag);
ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize);
int symlink(const char *path1, const char *path2);
pid_t vfork(void);
