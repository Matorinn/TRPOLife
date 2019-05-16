CC=g++
SOURCE=src/main.cpp
CFLAGS=-c -Wall
OBJ=build/main.o
LIBDIR=bin build
EXE=bin/main

all: $(LIBDIR) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -L OpenGL/lib/ -lglut -lGL -lGLX -lGLdispatch -o $(EXE)

$(OBJ): $(SOURCE)
	$(CC) $(CFLAGS) $^ -I OpenGL/include -o $@

$(LIBDIR):
	mkdir $@ -p

launch:
	./bin/main

clean:
	rm -rf build/*.o
