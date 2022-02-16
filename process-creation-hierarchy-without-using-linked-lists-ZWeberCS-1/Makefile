process_creation.exe: process_creation_hierarchy.o
	gcc process_creation_hierarchy.o -o process_creation.exe

process_creation_hierarchy.o: process_creation_hierarchy.c process_control_block.h
	gcc -Wall -c process_creation_hierarchy.c

clean:
	rm -f *.o

test: process_creation.exe
	bash test.sh