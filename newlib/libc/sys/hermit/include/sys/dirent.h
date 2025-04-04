#ifndef _SYS_DIRENT_H
#define _SYS_DIRENT_H

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

#define DT_UNKNOWN 0
#define DT_FIFO 1
#define DT_CHR 2
#define DT_DIR 4
#define DT_BLK 6
#define DT_REG 8
#define DT_LNK 10
#define DT_SOCK 12
#define DT_WHT 14

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
void _seekdir(DIR *dirp, long loc);

struct dirent {
	ino_t d_ino;
	off_t d_off;
	unsigned short d_reclen;
	unsigned char d_type;
	char d_name[];
};

__END_DECLS

#endif /* _SYS_DIRENT_H */
