gcc -DDEBUG=1 -c qsort.c
gcc -DDEBUG=1 -c client.c
gcc client.o qsort.o
./a.out
