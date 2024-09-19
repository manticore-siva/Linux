#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



// ANSI escape codes for colors
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#define OPEN_ERROR  1
#define READ_ERROR  2
#define WRITE_ERROR 3

char buf[1024]   = {0};
char input[1024] = {0};
int f_data[1024] = {0};

int file_close(int , int );

int file_read(int fd){

        ssize_t count = 0;
        int n_line = 1;

        lseek(fd, 0, SEEK_SET);

        if ( 0 > (count = read(fd, buf, 1024))){

               file_close(fd, READ_ERROR); 
        }

        for(int i=0; i< strlen(buf); i++)
        {
                if(buf[i] == '\n'){
                        f_data[n_line] = ++i;
                        printf("l no : %d\n",i);
                        n_line++;
                }
        }

        printf(YELLOW"******** Your File Data *************\n");
        printf(CYAN"%s\n",buf);
        printf(BLUE"Total line number : %d\n", n_line);
        printf(YELLOW"*************************************\n");
}

int file_write(int fd){

        file_read(fd);

        int line = 0;

        printf(WHITE"Enter line number\n");
        scanf("%d",&line);
        getchar();

        printf(WHITE"Enter yout message\n");
        scanf("%s",input);
        getchar();

        line = f_data[--line];

        lseek(fd, line, SEEK_SET);

        if( 0 > (write(fd, input, strlen(input)))){

                file_close(fd, WRITE_ERROR);
        }

}

int file_close(int fd, int code){

        close(fd);

        switch(code){
        case OPEN_ERROR:
                perror(RED"open\n");
                break;
        case READ_ERROR:
                perror(RED"read\n");
                break;
        case WRITE_ERROR:
                perror(RED"write\n");
                break;
        case 4:
                printf(GREEN"bye bye ...\n");
                break;
        }

        exit(EXIT_SUCCESS);
}

int main(){

        char f_name[20], quit=0, input;
        int fd;

        printf(YELLOW"Enter the file name \n");
        scanf("%s",f_name);
        getchar();

        if(0 > (fd = open(f_name, O_RDWR | O_CREAT , 0644))){
                perror(RED"file open");
                return -1;
        }

        while(1){

                printf(BLUE"Enter the options\n R ---> Read\n W ---> Write\n C ---> Close\n");
                scanf("%c",&input);
                getchar();

                switch(input){

                        case 'R':
                        case 'r':
                                file_read(fd);
                                break;
                        case 'W':
                        case 'w':
                                file_write(fd);
                                break;
                        case 'C':
                        case 'c':
                                file_close(fd, 4);
                                break;
                        default:
                                printf("Enter the valid input\n");
                }

        }
}
