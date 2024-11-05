#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

#define SIZE 50


int main(){

    int pipe_fd[2];

    // Create pipe 
    if( pipe(pipe_fd) == -1){
	perror("pipe creation \n");
    }

    
    pid_t ret = fork();

    if( ret == 0 ){
	// Child process 
	char msg[] = "this is sample message from child\n";

	// close read end 
//	close(pipe_fd[0]);

	// Write to write end of the pipe
	if ( write(pipe_fd[1], msg, sizeof(msg)) == -1){

	    perror("Write error\n");
	}

	// close write end 
//	close(pipe_fd[1]);	
    }

    else if(ret > 0 ){

	//Parent process
	char buffer[SIZE];
//	close(pipe_fd[1]);
	read(pipe_fd[0], buffer, sizeof(buffer));
//	close(pipe_fd[0]);
	printf("%s\n",buffer);

    }
}

