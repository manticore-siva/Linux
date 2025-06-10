#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>

#define KEY_VAL 12345;

int main()
{
    int shmid, shmflag;
    key_t key = KEY_VAL;
    shmflag = 0666;
    size_t size = 1024;

    if( ( shmid = shmget(key, size, shmflag)) < 0 ){
	
	perror("Create shared memory");
    }

    else if( shmid > 0) {

	perror("Create shared memory");
	printf("%d\n",key);

	//void *shmat(int shmid, const void *shmaddr, int shmflg);

	char *data = (char *)shmat(shmid, NULL, 0);
	perror("shmat memory");


	printf("Read data from shared mem : %s\n", data);

	shmdt(data);

	shmctl(shmid, IPC_RMID, NULL); // remove

    }

    else if( shmid < 0)
    {
    	perror("Faild to create shared memory");
	exit(-1);
    }

    return 0;

}

