binary: main.o libworld.a
	gcc -o binary main.o -L. -lworld

main.o: main.c
	gcc -c main.c

libworld.a: list.o 
	ar cr libworld.a list.o 

list.o: list.c
	gcc -c list.c

clean:
	rm -f *.o *.a binary