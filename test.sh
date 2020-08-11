
gcc main.c libftprintf.a -g
valgrind --track-origins=yes ./a.out
./a.out
