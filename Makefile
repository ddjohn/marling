CC = g++ 
CFLAGS = -std=c++11 -g -Wall -Werror

OBJS = main.o Alsa.o AlsaS.o Trace.o

all: main

main: $(OBJS)
	$(CC) -o $@ $^ -lasound

.cc.o:
	$(CC) $(CFLAGS) -o $@ -c $<

valgrind: main
	valgrind -v --leak-check=full --gen-suppressions=all --log-file=valgrind.out --suppressions=valgrind.supp  ./main 

gdb: main
	gdb ./main

clean:
	rm -f  $(OBJS)
	rm -f main
	rm -f valgrind.out
