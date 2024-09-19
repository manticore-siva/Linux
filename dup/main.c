#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

    int fd, new_fd;
    

    // Open a file 
    if(( 0 > (fd=open(argv[1], O_RDWR)))){
        perror("file open");
        return -1;
    }

    /* think like every process  have a three fd STANDRD IN , STANDRD OUT, and STANDRD ERROR it maintain like a array  ( boolin file path  /include/linux/fs.h)
    ex :   
        new process  process[0] -> standrd in 
                     process[1] -> standrd out
                     process[2] -> standrd error
                     process[3] -> file discriptor
                     process[4] -> duplicate file discriptor ( note it always give lowest-numbered unused file descriptor )
     */                   
    // make a copy of file discriptor via dup system call
    if( 0 > (new_fd=dup(fd))){
        perror("dup operation");
        close(fd);
        return -2;

    }

    printf(" Old file discriptor : %d\n New file discriptor : %d\n",fd, new_fd);

    close(fd);
    close(new_fd);

}