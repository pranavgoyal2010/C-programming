queue : linked_list.o queue.o ../../CI/objects/queue/queueM.o
	gcc --std=c18 linked_list.o queue.o ../../CI/objects/queue/queueM.o -o queue

queue.o : queue.c queue.h
	gcc --std=c18 -c queue.c queue.h 

linked_list.o : linked_list.c linked_list.h
	gcc --std=c18 -c linked_list.c linked_list.h


