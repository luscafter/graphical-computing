CC=gcc
OPTIONS=-I. -lglut -lGLU -lGLEW -lGL
OBJECT=main.o

all: $(OBJECT)
	gcc -o main $^ $(OPTIONS)

run: export vblank_mode=0
run: export __GL_SYNC_TO_VBLANK=0
run: all
	./main 2> /dev/null

clean:
	rm *.o main
