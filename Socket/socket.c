#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<errno.h>  
#include<sys/types.h>  
#include<sys/socket.h>  
#include<netinet/in.h>  
  
#define MAXLINE 1024  
  
void server()  
{  
    int    listenfd, connfd;  
    struct sockaddr_in     servaddr;  
    char    buff[1024];  
    int     n;  
  
    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){  
    printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);  
    exit(0);  
    }  
  
    memset(&servaddr, 0, sizeof(servaddr));  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  
    servaddr.sin_port = htons(6666);  
  
    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){  
    printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);  
    exit(0);  
    }  
  
    if( listen(listenfd, 10) == -1){  
    printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);  
    exit(0);  
    }  
  
    // printf("======waiting for client's request======\n");  
    while(1){  
    if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){  
        printf("accept socket error: %s(errno: %d)",strerror(errno),errno);  
        continue;  
    }  
    n = recv(connfd, buff, MAXLINE, 0);  
    buff[n] = '\0';  
    printf("receive message from client: \n%s", buff);  
    close(connfd);
    break;  
    }  
  
    close(listenfd);  
}  

  
void client(char msg[1024])  
{  
    int    sockfd, n;  
    char    recvline[1024], sendline[1024];  
    struct sockaddr_in    servaddr;  
    
    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){  
    printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);  
    exit(0);  
    }  
  
    memset(&servaddr, 0, sizeof(servaddr));  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_port = htons(6666);  
    if( inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0){  
    printf("inet_pton error for %s\n","127.0.0.1");  
    exit(0);  
    }  
  
    if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){  
    printf("connect error: %s(errno: %d)\n",strerror(errno),errno);  
    exit(0);  
    }  
  
    printf("send msg to server: \n");  
    // fgets(sendline, 1024, stdin);  
    for (int i=0;i<1024;++i)
    {
        sendline[i] = msg[i];
    }
    if( send(sockfd, sendline, strlen(sendline), 0) < 0)  
    {  
    printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);  
    exit(0);  
    }  
  
    close(sockfd);  
}

// int main()
// {
//     char s[1024];
//     fgets(s,1024,stdin);
//     server();
//     client(s);
//     return 0;
// }