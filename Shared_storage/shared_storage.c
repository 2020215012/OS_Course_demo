#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // 共享存储区大小

void listener() {
    int shmid;
    key_t key;
    char *shm, *s;

    // 获取共享存储区
    key = ftok(".", 's'); // 生成key
    shmid = shmget(key, SHM_SIZE, 0666); // 获取共享存储区
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

    // 读取共享存储区内容并显示在窗口上
    printf("Shared_storage received message:\n");
    for (s = shm; *s != '\0'; s++)
        putchar(*s);
    putchar('\n');

    // 标记共享存储区已读取完毕
    *shm = '*';

    // 解除共享存储区映射
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    shmctl(shmid, IPC_RMID, NULL);  // 删除共享存储区
}

void talker(char msg[1024]) {
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

    for (int i=0;i<SHM_SIZE;++i)
    {
        shm[i] = msg[i];
    }

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

}

// int main()
// {
//     char s[1024];
//     fgets(s,1024,stdin);
//     talker(s);
//     listener();
//     return 0;
// }