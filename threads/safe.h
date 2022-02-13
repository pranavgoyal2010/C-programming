#ifndef __SAFE_HEADER
#define __SAFE_HEADER

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

typedef struct _Count
{
	int counter;
}Count;

void* counting(void*);
void count_variable(int);

#endif
