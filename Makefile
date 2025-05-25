CC=gcc
CFLAGS=-Iinclude -Wall

SRC=src/main.c src/parser.c src/executor.c src/builtins.c
OBJ=$(SRC:.c=.o)

mysh: $(SRC)
	$(CC) $(CFLAGS) -o mysh $(SRC)

clean:
	rm -f mysh *.o
