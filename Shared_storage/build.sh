gcc -c -o shared_storage.o shared_storage.c
ar -rc libshared.a shared_storage.o
gcc -o test test.c -static -L./ -lshared