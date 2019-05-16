CC=g++
SOURCE1=src/main.cpp
SOURCE2=src/game.cpp
CFLAGS=-c -Wall
OBJ1=build/main.o
OBJ2=build/game.o
LIBDIR=bin build
EXE=bin/main

all: $(LIBDIR) $(EXE)

$(EXE): $(OBJ1) $(OBJ2)
	$(CC) $(OBJ1) $(OBJ2) -L OpenGL/lib/ -lglut -lGL -o $(EXE)

$(OBJ1): $(SOURCE1)
	$(CC) $(CFLAGS) $^ -I OpenGL/include -o $@

$(OBJ2): $(SOURCE2)
	$(CC) $(CFLAGS) $^ -I OpenGL/include -o $@
	
$(LIBDIR):
	mkdir $@ -p

launch:
	./bin/main

clean:
	rm -rf build/*.o
