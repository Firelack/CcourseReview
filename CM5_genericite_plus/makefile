CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -pedantic -ggdb

run : exec
	./exec

all: exec

exec: main.o personne.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o exec