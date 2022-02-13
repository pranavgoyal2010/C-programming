
pool : pool.c pool.h lib/poolM.o array_list.o linked_list.o queue.o heap.o stack.o
	gcc --std=c18 -g -Ilib pool.c lib/poolM.o array_list.o linked_list.o queue.o stack.o heap.o -lpthread -o pool

heap.o : lib/heap.c lib/heap.h 
	gcc --std=c18 -g -c -Ilib lib/heap.c 

queue.o : lib/queue.c lib/queue.h
	gcc --std=c18 -g -c -Ilib lib/queue.c

stack.o : lib/stack.c lib/stack.h
	gcc --std=c18 -g -c -Ilib lib/stack.c 

linked_list.o : lib/linked_list.c lib/linked_list.h
	gcc --std=c18 -g -c -Ilib lib/linked_list.c 

array_list.o : lib/array_list.c lib/array_list.h
	gcc --std=c18 -g -c -Ilib lib/array_list.c


