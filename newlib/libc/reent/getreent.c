/* default reentrant pointer when multithread enabled */

#ifdef GETREENT_PROVIDED

int _dummy_getreent;

#else

#include <_ansi.h>
#include <reent.h>

#ifndef _REENT_THREAD_LOCAL

#ifdef __getreent
#undef __getreent
#endif

struct _reent * __attribute__((weak))
__getreent (void)
{
  return _impure_ptr;
}

#endif /* !_REENT_THREAD_LOCAL */

#endif
