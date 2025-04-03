#include <errno.h>
#include <stdlib.h>
#include <string.h>

char *realpath(const char *restrict file_name, char *restrict resolved_name) {
    if (resolved_name != NULL) {
        errno = ENAMETOOLONG;
        return NULL;
    }

    size_t len = strlen(file_name);

    char *ret = malloc(len);
    if (ret == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    strcpy(ret, file_name);

    return ret;
}
