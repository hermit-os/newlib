#include <errno.h>
#include <pwd.h>
#include <stddef.h>
#include <string.h>

static struct passwd static_pwd = {
    .pw_name = "root",
    .pw_passwd = "",
    .pw_uid = 0,
    .pw_gid = 0,
    .pw_comment = "",
    .pw_gecos = "root",
    .pw_dir = "/",
    .pw_shell = "",
};

struct passwd *getpwnam(const char *name) {
    if (name == NULL) {
        return NULL;
    }

    if (strcmp(name, static_pwd.pw_name)) {
        return NULL;
    }

    return &static_pwd;
}

struct passwd *getpwuid(uid_t uid) {
    if (uid != static_pwd.pw_uid) {
        return NULL;
    }

    return &static_pwd;
}

static int getpw_r(const struct passwd *input, struct passwd *pwd, char *buffer,
                   size_t bufsize, struct passwd **result) {
    if (input == NULL) {
        *result = NULL;
        return 0;
    }

    size_t name_len = strlen(input->pw_name) + 1;
    size_t passwd_len = strlen(input->pw_passwd) + 1;
    size_t comment_len = strlen(input->pw_comment) + 1;
    size_t gecos_len = strlen(input->pw_gecos) + 1;
    size_t dir_len = strlen(input->pw_dir) + 1;
    size_t shell_len = strlen(input->pw_shell) + 1;

    size_t len =
        name_len + passwd_len + comment_len + gecos_len + dir_len + shell_len;

    if (len > bufsize) {
        *result = NULL;
        return ERANGE;
    }

    memcpy(buffer, input->pw_name, name_len);
    pwd->pw_name = buffer;
    buffer += name_len;

    memcpy(buffer, input->pw_passwd, passwd_len);
    pwd->pw_passwd = buffer;
    buffer += passwd_len;

    pwd->pw_uid = input->pw_uid;
    pwd->pw_gid = input->pw_gid;

    memcpy(buffer, input->pw_comment, comment_len);
    pwd->pw_comment = buffer;
    buffer += comment_len;

    memcpy(buffer, input->pw_gecos, gecos_len);
    pwd->pw_gecos = buffer;
    buffer += gecos_len;

    memcpy(buffer, input->pw_dir, dir_len);
    pwd->pw_dir = buffer;
    buffer += dir_len;

    memcpy(buffer, input->pw_shell, shell_len);
    pwd->pw_shell = buffer;
    buffer += shell_len;

    *result = pwd;
    return 0;
}

int getpwnam_r(const char *name, struct passwd *pwd, char *buffer,
               size_t bufsize, struct passwd **result) {
    struct passwd *input = getpwnam(name);
    return getpw_r(input, pwd, buffer, bufsize, result);
}

int getpwuid_r(uid_t uid, struct passwd *pwd, char *buffer, size_t bufsize,
               struct passwd **result) {
    struct passwd *input = getpwuid(uid);
    return getpw_r(input, pwd, buffer, bufsize, result);
}
