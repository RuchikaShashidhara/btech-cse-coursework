gcc -DDEBUG=0 -c qsort.c
gcc -DDEBUG=0 -c client.c
gcc client.o qsort.o
./a.out
