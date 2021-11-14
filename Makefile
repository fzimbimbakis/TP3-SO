GCC_FLAGS= -Wall -g -Wextra -I./include -std=c99

all: client server

client: client.c
	gcc $(GCC_FLAGS) client.c -o client

server: server.c desafios.c
	gcc $(GCC_FLAGS) -lm server.c desafios.c -o server2

clean:
	rm -f *.o

.PHONY: all clean server client