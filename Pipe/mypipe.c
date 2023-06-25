#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void mypipe(char s[1024])
{
    int fd[2];
    int pid;
    char buf[1024]={'\0'};

    // 创建管道
    if (pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }

    // 创建子进程
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    // 子进程
    if (pid == 0) {
        close(fd[1]);  // 关闭写端
        read(fd[0], buf, sizeof(buf));  // 从管道读取数据
        printf("Pipe Child process received: \n%s", buf);
        close(fd[0]);  // 关闭读端
    }
    // 父进程
    else {
        close(fd[0]);  // 关闭读端
        write(fd[1], s, strlen(s));  // 向管道写入数据
        close(fd[1]);  // 关闭写端
    }
}

// int main()
// {
//     char s[1024];
//     fgets(s,1024,stdin);
//     mypipe(s);
//     return 0;
// }