#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <error.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    
    uid_t uid;

    uid = atoi(argv[1]);

    if(setuid(uid) < 0)
    {
	perror("faild setuid");
	exit(-1);
    }
    else
    {
	perror("set uuid");

    	printf("New UID %d\n", getuid());
    }

    return 0;
}

