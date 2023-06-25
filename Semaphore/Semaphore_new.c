#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

  sem_t sem;
  struct Semaphore_new
  {
    sem_t* s;
    char msg[1024];
  };
  struct Semaphore_new Sem; 
  
  void func1(void* arg)
  {
      sem_wait(Sem.s);  // 等待信号量
      printf("Semaphore received message:\n%s",Sem.msg);
  }

  void func2(void* arg)
  {
      fgets(Sem.msg, 1024, stdin);
      sem_post(Sem.s);  // 释放信号量
  }

  int main()
  {
      Sem.s = &sem;
      sem_init(Sem.s,0,0);  //  初始化信号量
      pthread_t thread[2];  // 线程组
      int a=5;
      pthread_create(&(thread[0]),NULL,(void*)func1,(void*)&a); // 创建线程
      pthread_create(&(thread[1]),NULL,(void*)func2,(void*)&a);
      pthread_join(thread[0],NULL); // 等待线程结束
      pthread_join(thread[1],NULL);
      sem_destroy(Sem.s);   // 删除信号量

      return 0;
  }
