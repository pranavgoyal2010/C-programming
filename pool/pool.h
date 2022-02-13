#ifndef __POOL_HEADER
#define __POOL_HEADER

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"
#include "stack.h"
#include "array_list.h"
#include "heap.h"

typedef struct _Operation 
{
	int(*op)(int, int);
	int a;
	int b;
}Operation;

typedef struct _Args
{
	Operation* operation;
	bool is_complete;
}Args;

void* compute(void*);
bool read_operations(char*, Queue*);
ArrayList* execute_thread_pool(char*, int);
void print_sorted(ArrayList*);
int add(int, int);
int sub(int, int);
int mul(int, int);
int compareInt(void*, void*);
void printInt(void*);

#endif

