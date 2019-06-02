CC=g++
SOURCE1=src/main.cpp
SOURCE2=src/game.cpp
SOURCE3=src/painter.cpp
SOURCE4=src/field.cpp
CFLAGS=-c -Wall
OBJ1=build/main.o
OBJ2=build/game.o
OBJ3=build/painter.o
OBJ4=build/field.o
LIBDIR=bin build
EXE=bin/main

all: $(LIBDIR) $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
	$(CC) $^ -L OpenGL/lib -lglut -lGL -o $(EXE)

$(OBJ1): $(SOURCE1)
	$(CC) $(CFLAGS) $^ -I OpenGL/include -o $@

$(OBJ2): $(SOURCE2)
	$(CC) $(CFLAGS) $^ -I OpenGL/include -o $@

$(OBJ3): $(SOURCE3)
	$(CC) $(CFLAGS) $^ -I OpenGL/include -o $@

$(OBJ4): $(SOURCE4)
	$(CC) $(CFLAGS) $^ -I OpenGL/include -o $@

$(LIBDIR):
	mkdir $@ -p

launch:
	./bin/main

clean:
	rm -rf build/*.o
