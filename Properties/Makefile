all: main.o
	gcc -o main $^
	
run: all
	./main 2> /dev/null
	
clean:
	rm *.o main
