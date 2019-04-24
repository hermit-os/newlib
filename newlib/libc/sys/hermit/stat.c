/*
 * Copyright (c) 2011, Stefan Lankes, RWTH Aachen University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the University nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * Stub version of stat.
 */

#include "config.h"
#include <reent.h>
#include <_ansi.h>
#include <_syslist.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "syscall.h"
#include "warning.h"

int _DEFUN (stat, (file, st),
        const char  *file _AND
        struct stat *st)
{
    return _stat_r(_REENT, file, st);
}

int _DEFUN (_stat_r, (ptr, file, st),
    struct _reent *ptr _AND
    const char  *file _AND
    struct stat *st)
{
    int ret;

    if (!file && ! st) {
        ptr->_errno = EINVAL;
        return -1;
    }

    ret = sys_stat(file, st);
    if (ret < 0) {
        ptr->_errno = -ret;
        return -1;
    }
}


int chmod(const char *path, mode_t mode) {
  // TODO
  return -1;
}

int fchmod(int filedes, mode_t mode) {
  // TODO
  return -1;
}


int _DEFUN (fstat, (filedes, st),
        int filedes _AND
        struct stat *st)
{
    return _fstat_r(_REENT, filedes, st);
}

int _DEFUN (_fstat_r, (ptr, filedes, st),
    struct _reent *ptr _AND
    int filedes _AND
    struct stat *st)
{
    int ret;

    if (!file && ! st) {
        ptr->_errno = EINVAL;
        return -1;
    }

    ret = sys_fstat(filedes, st);
    if (ret < 0) {
        ptr->_errno = -ret;
        return -1;
    }
}


int lstat(const char *path, struct stat *buf) {
  // TODO
  return -1;
}

int mkdir(const char *path, mode_t mode) {
  // TODO
  return -1;
}

int mkfifo(const char *path, mode_t mode) {
  // TODO
  return -1;
}

int stat(const char *path, struct stat *buf) {
  // TODO
  return -1;
}

mode_t umask(mode_t mode) {
  // TODO
  return -1;
}
