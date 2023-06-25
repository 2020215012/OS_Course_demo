gcc -c -o msg_queue.o msg_queue.c
ar -rc libmsg_queue.a msg_queue.o
gcc -o test test.c -static -L./ -lmsg_queue