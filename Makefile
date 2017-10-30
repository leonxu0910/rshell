CC = g++
CC_FLAGS = -Wall -ansi -pedantic -std=c++11
all: ExecShell Bin And Semicolon Or Exit
	mkdir -p bin
	$(CC) $(CC_FLAGS) ./src/main.cpp ExecShell.o Bin.o And.o Semicolon.o Or.o Exit.o -o ./bin/rshell

rshell: ExecShell Bin And Semicolon Or Exit
	mkdir -p bin
	$(CC) $(CC_FLAGS) ./src/main.cpp ExecShell.o Bin.o And.o Semicolon.o Or.o Exit.o -o ./bin/rshell

ExecShell:
	$(CC) $(CC_FLAGS) -c ./src/ExecShell.cpp

Bin: 
	$(CC) $(CC_FLAGS) -c ./src/Bin.cpp

And:
	$(CC) $(CC_FLAGS) -c ./src/And.cpp

Semicolon:
	$(CC) $(CC_FLAGS) -c ./src/Semicolon.cpp

Or:
	$(CC) $(CC_FLAGS) -c ./src/Or.cpp

Exit:
	$(CC) $(CC_FLAGS) -c ./src/Exit.cpp

clean:
	rm -f *.o
	rm -f *.cpp~
	rm -f *.h~
	rm -f src/*.o
	rm -f *.out
	rm -rf bin