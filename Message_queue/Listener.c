
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

int main() {
  key_t key;
  int msgid;
  MsgBuf msg;

  // 获取消息队列
  key = ftok(".", 'a');         //为消息队列生成唯一键
  msgid = msgget(key, 0666);    //用于获取先前创建的消息队列的标识符
  if (msgid == -1) {            //没有获取到
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

  return 0;
}


