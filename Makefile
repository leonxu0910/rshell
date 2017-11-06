CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic -std=c++11

all: rshell
	mkdir -p bin
	$(CC) $(CC_FLAGS) *.o -o ./bin/rshell

rshell:
	$(CC) $(CC_FLAGS) -c ./src/*.cpp

clean:
	rm -f *.o
	rm -rf bin