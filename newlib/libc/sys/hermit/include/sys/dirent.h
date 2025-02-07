#ifndef _SYS_DIRENT_H
#define _SYS_DIRENT_H

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

#include <sys/types.h>

typedef struct dirent {
	long	d_ino;
	off_t	d_off;
	unsigned short	d_reclen;
	/* we need better syntax for variable-sized arrays */
	char	d_name[256];
} dirent_t;

#endif /* _SYS_DIRENT_H */
