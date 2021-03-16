binary: main.o libworld.so
	gcc -o binary main.o -L. -lworld -Wl,-rpath,.

main.o: main.c
	gcc -c main.c

libworld.so: list.o 
	gcc -shared -o libworld.so list.o 

list.o: list.c
	gcc -c -fPIC list.c

clean:
	rm -f *.o *.so binary