#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    char buf[1024]={'\0'};
    char* inbuf = "I am Soldier Boy\n";

    if (pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }

    if (fork() == 0) { /* child process */
        close(fd[0]); /* close the read end of the pipe */
        write(fd[1], inbuf, strlen(inbuf));
        exit(0);
    } 
    else { /* parent process */
        close(fd[1]); /* close the write end of the pipe */
        read(fd[0], buf, 1024);
        printf("%s", buf);
    }

    return 0;
}