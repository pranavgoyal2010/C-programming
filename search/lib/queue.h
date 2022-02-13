#ifndef __QUEUE_HEADER
#define __QUEUE_HEADER

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

typedef struct _Queue 
{ 
   LinkedList *LList;   
}Queue;

Queue* queue_initialize(int, char*);
bool queue_enqueue(Queue*, void*);
void* queue_dequeue(Queue*);
void* queue_peek(Queue*);
int queue_size(Queue*);
bool queue_contains(Queue*, void*);
bool queue_destroy(Queue*);

#endif
