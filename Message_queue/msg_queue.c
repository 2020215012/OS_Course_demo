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
} MsgBuf;

void listener() {
  key_t key;
  int msgid;
  MsgBuf msg;

  // 获取消息队列
  key = ftok(".", 'a'); //为消息队列生成唯一键
  msgid = msgget(key, 0666);    //用于获取先前创建的消息队列的标识符
  if (msgid == -1) {    //没有获取到
    perror("msgget");
    exit(1);
  }

 if (msgrcv(msgid, &msg, MSG_SIZE, 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }
    printf("Received message:\n%s", msg.mtext);
    memset(&msg, 0, sizeof(msg)); // 将msg结构体清零，以便下次使用时可以重新接收消息


  // 删除队列
  if (msgctl(msgid, IPC_RMID, NULL) == -1) {
    perror("msgctl");}

}

void talker(char s[1024]) {
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
    // *(msg.mtext) = s;
    for (int i=0;i<1024;++i)
    {
        msg.mtext[i] = s[i];
    }
    // 发送消息
    msg.mtype = 1;
    if (msgsnd(msgid, &msg, strlen(msg.mtext)+1, 0) == -1) {    //发送消息
        perror("msgsnd");
        exit(1);
    }
}

// int main()
// {
//     char s[1024];
//     fgets(s,1024,stdin);
//     talker(s);
//     listener();
// }