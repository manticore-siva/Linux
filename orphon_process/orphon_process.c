#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    
    int ret = fork();

    if ( ret == 0)
    {
	printf("Child process running\n");
	printf("Curent Child ID   : %d\n", getpid());
	printf("PPID              : %d\n", getppid());
	sleep(15);
	printf("Curent Child PID : %d\n", getpid());
	printf("PPID              : %d\n", getppid());
    }

    else if (ret > 0 )
    {
	printf("Praent process running\n");
	printf("Parent ID   : %d\n", getpid());
//	exit(0);
    }
}
