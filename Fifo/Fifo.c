#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    pid_t pid;
    int status;
    char buffer[1024]={'\0'};
    char s[1024];
    int pipefd[2];
    if (pipe(pipefd) == -1) {   // 创建一个pipe
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid = fork();   // 创建一个子进程
    if (pid == 0) { // pid = 0 表示子进程
        close(pipefd[0]); // 读到尾关闭pipe
        fgets(s, 1024, stdin);
        write(pipefd[1], s, strlen(s)); // 将数据写入到pipe
        close(pipefd[1]); // 写到尾关闭pipe
        wait(&status); // 等待父进程执行完成，读取状态码
    } else if (pid > 0) { // pid > 0 表示父进程
        close(pipefd[1]); // 写到尾关闭pipe
        read(pipefd[0], buffer, sizeof(buffer)); // 从pipe中读取数据
        printf("Fifo received message: \n%s\n", buffer);
        close(pipefd[0]); // 读到尾关闭pipe
    } else { // 创建子进程出错
        perror("fork"); //将错误消息打印到stderr流
        exit(EXIT_FAILURE); //终止进程
    }
    return 0;
}
