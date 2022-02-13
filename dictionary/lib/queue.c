#include "queue.h"

Queue* queue_initialize(int itemSize, char *dataTypeStored)
{
  Queue *Q = malloc(sizeof(Queue));

  if(Q == NULL)
     return NULL;

  Q->LList = llist_initialize(itemSize, dataTypeStored);

  if(Q->LList == NULL)
     return NULL;

  return Q;
}

bool queue_enqueue(Queue *Q, void *element)
{
  if(Q == NULL)
	  return false;
  if(Q->LList == NULL)
	  return false;

  if((Q->LList)->size == 0)
  {
     if(element !=NULL)
	  llist_add_first((Q->LList), element);
     else 
	  return false;
  }

  else
  {
      if(element !=NULL)
	  llist_add_at((Q->LList), (Q->LList)->size, element);
      else
	  return false;
  }
}

void* queue_dequeue(Queue *Q)
{
   if(Q == NULL)
	   return NULL;
   if(Q->LList == NULL)
	   return NULL;

   void *element = malloc(sizeof((Q->LList)->itemSize));

   if(queue_size(Q) != 0)
   {
	  element = llist_remove_first(Q->LList);

	  if(element != NULL)
	   return element;
   

        return NULL;
   }

   return NULL;
}

void* queue_peek(Queue *Q)
{

    if(Q == NULL)
	    return NULL;
    if(Q->LList == NULL)
	    return NULL;

     void *element = malloc(sizeof((Q->LList)->itemSize));


    if((Q->LList)->size !=0)
    {
	    element = llist_get(Q->LList, 0);   
	    return element;     
    }

    return NULL;
   
}

int queue_size(Queue *Q)
{
   if(Q == NULL)
	   return 0;
   if(Q->LList == NULL)
	   return 0;

   return (Q->LList)->size;
}

bool queue_contains(Queue *Q, void *element)
{
   if(Q == NULL)
	   return false;
   if(Q->LList == NULL)
	   return false;
   if(element == NULL)
	   return false;

   for(int i=0; i<queue_size(Q); i++)
   {
	   if(memcmp(llist_get((Q->LList), i), element, (Q->LList)->itemSize) == 0)
	   {
		   return true;
	   }
   }

  return false; 
}

bool queue_destroy(Queue *Q)
{

	if(Q == NULL)
	   return false;
	if(Q->LList == NULL)
	   return false;

	llist_destroy(Q->LList);

	free(Q);
	
	 return true;

	
}

