#ifndef _MACHINE__TYPES_H
#define _MACHINE__TYPES_H

#include <machine/_default_types.h>

typedef __int64_t __blkcnt_t;
#define __machine_blkcnt_t_defined

typedef __int64_t __blksize_t;
#define __machine_blksize_t_defined

typedef __int64_t _off_t;
#define __machine_off_t_defined

typedef __int64_t _off64_t;
#define __machine_off64_t_defined

typedef __uint64_t __dev_t;
#define __machine_dev_t_defined

typedef __uint32_t __uid_t;
#define __machine_uid_t_defined

typedef __uint32_t __gid_t;
#define __machine_gid_t_defined

typedef __uint32_t __id_t;
#define __machine_id_t_defined

typedef __uint64_t __ino_t;
#define __machine_ino_t_defined

typedef __uint64_t __ino64_t;
#define __machine_ino64_t_defined

typedef __uint32_t __mode_t;
#define __machine_mode_t_defined

#define _CLOCKID_T_ __int32_t
#define __machine_clockid_t_defined

typedef __uint8_t __sa_family_t;
#define __machine_sa_family_t_defined

typedef __uint32_t __socklen_t;
#define __machine_socklen_t_defined

typedef __uint64_t __nlink_t;
#define __machine_nlink_t_defined

typedef __int32_t __suseconds_t;
#define __machine_suseconds_t_defined

typedef __uint32_t __useconds_t;
#define __machine_useconds_t_defined

typedef __ino64_t ino64_t;
typedef _off64_t off64_t;

#endif /* _MACHINE__TYPES_H */
