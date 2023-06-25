#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // 共享存储区大小

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // 创建共享存储区
    key = ftok(".", 's'); // 生成key
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); // 创建共享存储区
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // 将共享存储区映射到进程地址空间
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // 从键盘读取输入
    printf("Enter a message: ");
    fgets(shm, SHM_SIZE, stdin);

    // 将输入字符串传输到共享存储区
    s = shm;
    s += strlen(shm);
    *s = '\0';

    // 等待接收进程读取共享存储区内容
//    while (*shm != '*')
//        sleep(1);

    // 解除共享存储区映射
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // 删除共享存储区
//    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
