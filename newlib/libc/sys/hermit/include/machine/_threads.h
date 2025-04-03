#ifndef _MACHINE__THREADS_H_
#define _MACHINE__THREADS_H_

#include <pthread.h>

typedef pthread_cond_t cnd_t;

typedef pthread_mutex_t mtx_t;

typedef pthread_t thrd_t;

typedef pthread_key_t tss_t;

typedef pthread_once_t once_flag;

#define	ONCE_FLAG_INIT PTHREAD_ONCE_INIT

#define	TSS_DTOR_ITERATIONS PTHREAD_DESTRUCTOR_ITERATIONS

#endif /* _MACHINE__THREADS_H_ */
