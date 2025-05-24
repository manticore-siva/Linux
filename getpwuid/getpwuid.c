#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{

    uid_t uid;

    uid = getuid();

    struct passwd *demo = getpwuid(uid);

    printf("%s\n",demo->pw_name);
    printf("%s\n",demo->pw_passwd);
    printf("%d\n",demo->pw_uid);
    printf("%d\n",demo->pw_gid);
    printf("%s\n",demo->pw_gecos);
    printf("%s\n",demo->pw_dir);
    printf("%s\n",demo->pw_shell);

}
