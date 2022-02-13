all : bfs dfs search

bfs : search.o linked_list.o queue.o stack.o ../../CI/objects/search/bfsM.o
	gcc --std=c18 linked_list.o queue.o stack.o ../../CI/objects/search/bfsM.o search.o -o bfs	

dfs : search.o linked_list.o queue.o stack.o ../../CI/objects/search/dfsM.o
	gcc --std=c18 linked_list.o queue.o stack.o ../../CI/objects/search/dfsM.o search.o -o dfs

search : search.o linked_list.o queue.o stack.o ../../CI/objects/search/searchM.o
	gcc --std=c18 linked_list.o search.o queue.o stack.o ../../CI/objects/search/searchM.o -o search

search.o : bintree.c bintree.h
	gcc --std=c18 -Ilib -c bintree.c -o search.o	

stack.o : lib/stack.c lib/stack.h 
	gcc --std=c18 -Ilib -c lib/stack.c

queue.o : lib/queue.c lib/queue.h 
	gcc --std=c18 -Ilib -c lib/queue.c 

linked_list.o : lib/linked_list.c lib/linked_list.h
	gcc --std=c18 -Ilib -c lib/linked_list.c 

