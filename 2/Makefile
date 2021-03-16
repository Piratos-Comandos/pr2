all: main unit runtests clean

main:	list.o main.o
	gcc -omain list.o main.o
list.o:	list.c
	gcc -c list.c
main.o:	main.c list.h
	gcc -c main.c
unit.o: unit.c list.h
	gcc -c unit.c
unit: unit.o list.o
	gcc -ounit unit.o list.o Unity/src/unity.c
runtests:unit
	./unit
clean:
	rm list.o main.o unit.o unit 
