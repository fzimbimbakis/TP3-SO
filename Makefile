GCC_FLAGS= -Wall -g -Wextra -I./include

all: client server

client: client.c
	gcc $(GCC_FLAGS) client.c -o client

server: server.c
	gcc $(GCC_FLAGS) server.c -o server


clean:
	rm -f *.o

.PHONY: all clean server client