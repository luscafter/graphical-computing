CC=gcc
OPTIONS=-I. -lglut -lGLU -lGLEW -lGL
OBJECT=main.o

all: $(OBJECT)
	gcc -o main $^ $(OPTIONS)

run: all
	./main 2> /dev/null

clean:
	rm *.o main
