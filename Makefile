CC=g++
SOURCE=src/main.cpp
CFLAGS=-c -Wall
OBJ=build/main.o

all: createDir main

main: $(OBJ)
	$(CC) $(OBJ) -L$$PWD/../OpenGL/lib/ -lglut -lGL -o bin/main

$(OBJ): $(SOURCE)
	$(CC) $(CFLAGS) $^ -I$$PWD/../OpenGL/include -o $@

createDir:
	mkdir bin build -p

launch:
	./bin/main

clean:
	rm -rf build/*.o
