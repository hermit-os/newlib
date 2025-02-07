#ifndef _SYS_DIRENT_H
#define _SYS_DIRENT_H

#include <sys/types.h>

typedef struct _dirdesc {
	int	dd_fd;
	long	dd_loc;
	long	dd_size;
	char	*dd_buf;
	int	dd_len;
	long	dd_seek;
} DIR;

# define __dirfd(dp)	((dp)->dd_fd)

DIR *opendir (const char *);
struct dirent *readdir (DIR *);
void rewinddir (DIR *);
int closedir (DIR *);
ssize_t getdents64(int fd, void *dirp, size_t count);

struct dirent {
	ino_t d_ino;
	off_t d_off;
	unsigned short d_reclen;
	unsigned char d_type;
	char d_name[];
};

#endif /* _SYS_DIRENT_H */
