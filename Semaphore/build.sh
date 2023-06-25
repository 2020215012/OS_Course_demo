gcc -c -o mysem.o mysem.c
ar -rc libsem.a mysem.o
gcc -o test test.c -static -L./ -lsem