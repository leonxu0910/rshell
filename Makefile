CC = g++
FLAGS = -Wall -ansi -pedantic -std=c++11
BIN = bin
SRC = src
SOURCES = $(wildcard $(SRC)/*.cpp) 
OBJECTS = $(addprefix bin/, $(notdir $(SOURCES:.cpp=.o)))

all: rshell

rshell: $(BIN)/rshell

$(BIN)/rshell: $(BIN)/ $(OBJECTS)
	$(CC) $(FLAGS) -o $@ $(OBJECTS)

$(BIN)/%.o: $(SRC)/%.cpp 
	$(CC) -c $(FLAGS) $< -o $@

$(BIN)/:
	mkdir -p $@

clean:
	rm -r $(BIN)