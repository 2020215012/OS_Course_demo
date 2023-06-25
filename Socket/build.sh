gcc -c -o socket.o socket.c
ar -rc libsocket.a socket.o
gcc -o test1 test1.c -static -L./ -lsocket
gcc -o test2 test2.c -static -L./ -lsocket