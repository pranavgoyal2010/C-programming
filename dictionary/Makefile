dictionary : bintree.o array_list.o linked_list.o queue.o stack.o dictionary.o ../../CI/objects/dictionary/dictM.o
	gcc --std=c18 array_list.o linked_list.o bintree.o queue.o stack.o dictionary.o ../../CI/objects/dictionary/dictM.o -o dictionary

dictionary.o : dictionary.c dictionary.h
	gcc --std=c18 -c -Ilib dictionary.c 

bintree.o : lib/bintree.c lib/bintree.h
	gcc --std=c18 -c lib/bintree.c

stack.o : lib/stack.c lib/stack.h 
	gcc --std=c18 -c lib/stack.c

queue.o : lib/queue.c lib/queue.h 
	gcc --std=c18 -c lib/queue.c 

linked_list.o : lib/linked_list.c lib/linked_list.h
	gcc --std=c18 -c lib/linked_list.c 

array_list.o : lib/array_list.c lib/array_list.h
	gcc --std=c18 -c lib/array_list.c

