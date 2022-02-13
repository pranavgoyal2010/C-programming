all : threads safe unsafe

threads : threads.h threads.c lib/threadsM.o
	gcc --std=c18 -Ilib threads.c lib/threadsM.o -lpthread -o threads

safe : safe.h safe.c lib/safeM.o
	gcc --std=c18 -Ilib safe.c lib/safeM.o -lpthread -o safe

unsafe : unsafe.h unsafe.c lib/unsafeM.o
	gcc --std=c18 -Ilib unsafe.c lib/unsafeM.o -lpthread -o unsafe
