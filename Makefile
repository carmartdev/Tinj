CC = gcc
CFLAGS = -Wno-implicit-function-declaration

all: main.o 
	gcc $(CFLAGS) main.o -o tinj

main: main.o
	gcc $(CFLAGS) main.o -o tinj

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

clean:
	rm main.o hello.o main a.out shell.o tinj
