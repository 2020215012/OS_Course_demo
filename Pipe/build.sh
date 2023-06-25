gcc -c -o mypipe.o mypipe.c
ar -rc libpipe.a mypipe.o
gcc -o test test.c -static -L./ -lpipe