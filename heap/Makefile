all : heap rheap

heap : heap.o array_list.o lib/heapM.o
	gcc --std=c11 -g heap.o array_list.o lib/heapM.o -o heap

rheap : heap.o array_list.o lib/rheapM.o
	gcc --std=c11 -g heap.o array_list.o lib/rheapM.o -o rheap

heap.o : heap.h heap.c 
	gcc --std=c11 -g -Ilib -c heap.c  

array_list.o : lib/array_list.c lib/array_list.h
	gcc --std=c11 -g -Ilib -c lib/array_list.c
