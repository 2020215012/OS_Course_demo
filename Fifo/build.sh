gcc -c -o myfifo.o myfifo.c
ar -rc libfifo.a myfifo.o
gcc -o test test.c -static -L./ -lfifo