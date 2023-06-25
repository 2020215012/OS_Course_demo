#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 1024

typedef struct msgbuf {
    long mtype;
    char mtext[MSG_SIZE];
} MsgBuf;   //消息结构体

int main() {
    key_t key;
    int msgid;
    MsgBuf msg;

    key = ftok(".", 'a');   //生成消息队列的键,点表示当前目录,a表示用于生成密钥的值
    msgid = msgget(key, IPC_CREAT | 0666);  // 创建一个消息队列。
    // 第一个参数是标识消息队列的键，第二个参数指定控制队列创建的标志。
    // IPC_CREAT标志用于创建队列(如果队列尚不存在),0666指定队列的权限。
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // 从控制台输入消息
    fgets(msg.mtext, MSG_SIZE, stdin);

    // 发送消息
    msg.mtype = 1;
    if (msgsnd(msgid, &msg, strlen(msg.mtext)+1, 0) == -1) {    //发送消息
        perror("msgsnd");
        exit(1);
    }

    return 0;
}
