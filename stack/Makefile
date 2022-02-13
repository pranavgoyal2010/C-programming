stack : stack.o linked_list.o ../../CI/objects/stack/stackM.o
	gcc --std=c18 stack.o linked_list.o ../../CI/objects/stack/stackM.o -o stack

stack.o : stack.c stack.h
	gcc --std=c18 -c stack.c

linked_list.o : linked_list.c linked_list.h
	gcc --std=c18 -c linked_list.c
