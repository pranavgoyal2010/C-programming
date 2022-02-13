#ifndef __UNSAFE_HEADER
#define __UNSAFE_HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct _Count
{
	int counter;
}Count;

void* counting(void*);
void count_variable(int);

#endif
