#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main ()
{
    char buffer[30] = "hello world\n", buf[30];
    int pipe_fd[2];

    pipe(pipe_fd);

    ssize_t c = write(pipe_fd[1], buffer, strlen(buffer));

    read(pipe_fd[0], buf, strlen(buffer));
    printf("%s\n",buf);

    close(pipe_fd[0]);
    close(pipe_fd[1]);

    return 0;
}

