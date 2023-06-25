## OS操作系统课程设计

### 小组成员
梁文豪 2020215012
李新康 2020211606

### 选题
41 进程通信

#### 要求
+ 编写两个进程，一进程负责发送字符串，另一进程负责接收字符串；
+ 分别支持 Unix/Liunx 的的共享存储区、消息队列、管道和 Socket；
+ 发送进程应可以从窗口或键盘上输入字符串；
+ 接收进程应可将字符串显示在窗口上；

#### 最终实现
+ 分别支持 Unix/Liunx 的的共享存储区、消息队列、管道、Socket、fifo和信号量；
+ 发送进程应可以从窗口或键盘上输入字符串，接收进程应可将字符串显示在窗口上；
+ 实现界面，在界面输入字符串，并展示接受到的字符串；
+ 支持静态链接库(.a文件)，封装内核代码，提供接口调用；
  
### 项目结构
```
.
├── Fifo
│   ├── build.sh
│   ├── Fifo
│   ├── Fifo.c
│   ├── libfifo.a
│   ├── myfifo
│   ├── myfifo.c
│   ├── myfifo.h
│   ├── myfifo.o
│   ├── test
│   └── test.c
├── Message_queue
│   ├── build.sh
│   ├── libmsg_queue.a
│   ├── Listener
│   ├── Listener.c
│   ├── msg_queue
│   ├── msg_queue.c
│   ├── msg_queue.h
│   ├── msg_queue.o
│   ├── Talker
│   ├── Talker.c
│   ├── test
│   └── test.c
├── Pipe
│   ├── build.sh
│   ├── libpipe.a
│   ├── Listener
│   ├── Listener.c
│   ├── mypipe
│   ├── mypipe.c
│   ├── mypipe.h
│   ├── mypipe.o
│   ├── pipe
│   ├── pipe.c
│   ├── Talker
│   ├── Talker.c
│   ├── test
│   └── test.c
├── README.md
├── Semaphore
│   ├── build.sh
│   ├── libsem.a
│   ├── mysem
│   ├── mysem.c
│   ├── mysem.h
│   ├── mysem.o
│   ├── Semaphore
│   ├── Semaphore.c
│   ├── Semaphore_new
│   ├── Semaphore_new.c
│   ├── test
│   └── test.c
├── Shared_storage
│   ├── build.sh
│   ├── libshared.a
│   ├── Listener
│   ├── Listener.c
│   ├── shared_storage
│   ├── shared_storage.c
│   ├── shared_storage.h
│   ├── shared_storage.o
│   ├── Talker
│   ├── Talker.c
│   ├── test
│   └── test.c
├── Socket
│   ├── build.sh
│   ├── Client
│   ├── Client.c
│   ├── libsocket.a
│   ├── Server
│   ├── Server.c
│   ├── socket
│   ├── socket.c
│   ├── socket.h
│   ├── socket.o
│   ├── test
│   ├── test1
│   ├── test1.c
│   ├── test2
│   ├── test2.c
│   ├── try
│   └── try.cc
├── try_pipe.py
└── ui0.py
```

1. Fifo
    fifo进程通信，使用方法，打开终端
    >cd ~/Fifo
    >sudo chmod +x ./build.sh
    >./build.sh
    >./test

    在终端输入要传输的字符串

2. Message_queue
    message_queue进程通信，使用方法，打开终端
    >cd ~/Fifo
    >sudo chmod +x ./build.sh
    >./build.sh
    >./test

    在终端输入要传输的字符串

3. Pipe
    pipe进程通信，使用方法，打开终端
    >cd ~/Fifo
    >sudo chmod +x ./build.sh
    >./build.sh
    >./test

4. Semaphore
    pipe进程通信，使用方法，打开终端
    >cd ~/Fifo
    >sudo chmod +x ./build.sh
    >./build.sh
    >./test

    在终端输入要传输的字符串

5. Shared_storage
    shared_storage进程通信，使用方法，打开终端
    >cd ~/Fifo
    >sudo chmod +x ./build.sh
    >./build.sh
    >./test

    在终端输入要传输的字符串

6. Socket
    Socket进程通信，使用方法，打开终端
    >cd ~/Fifo
    >sudo chmod +x ./build.sh
    >./build.sh
    >./test2

    开启另一个终端
    >./test1
    
    在test1终端输入要传输的字符串,test2终端会收到字符串

7. try_pipe.py
测试python多进程调用能否执行，是界面代码的基础

8. ui0.py
界面代码，在界面中可以直接调用六种进程通信方法