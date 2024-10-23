CC = gcc
CFLAGS = -Wno-implicit-function-declaration

all: main.o shell.o
	gcc $(CFLAGS) main.o shell.o -o tinj

main: main.o
	gcc $(CFLAGS) main.o -o tinj

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c

clean:
	rm main.o hello.o main a.out shell.o tinj
