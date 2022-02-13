#include "stack.h"

Stack* stack_initialize(int dataSize, char* dataType)
{
    Stack *S = malloc(sizeof(Stack));

    if(S == NULL)
	    return NULL;

    S->LList = llist_initialize(dataSize, dataType);

    if(S->LList == NULL)
	    return NULL;

    return S;
}

bool stack_push(Stack *S, void *element)
{
    if(S == NULL)
	    return false;
    if(S->LList == NULL)
	    return false;
    if(element == NULL)
	    return false;

    if(stack_size == 0)
    {
	llist_add_first(S->LList, element);
    }

    
	llist_add_at(S->LList, stack_size(S), element);
    
}

void* stack_pop(Stack *S)
{
   if(S == NULL)
	   return NULL;
   if(S->LList == NULL)
	   return NULL;

   void *element = malloc((S->LList)->itemSize);

   element = llist_remove_last(S->LList);

   if(element == NULL)
	   return NULL;

   return element;
}

void* stack_peek(Stack *S)
{
   if(S == NULL)
	   return NULL;
   if(S->LList == NULL)
	   return NULL;

   void *element = malloc((S->LList)->itemSize);

   element = llist_get(S->LList, (stack_size(S))-1);

   if(element == NULL)
	   return NULL;

   return element;
}

int stack_size(Stack *S)
{
   if(S == NULL)
	   return 0;
   if(S->LList == NULL)
	   return 0;

   return (S->LList)->size;
}

bool stack_contains(Stack *S, void *element)
{
   if(S == NULL)
	   return false;
   if(S->LList == NULL)
	   return false;
   if(element == NULL)
	   return false;

   for(int i=0; i<stack_size(S); i++)
   {
      if((memcmp(llist_get(S->LList, i), element, (S->LList)->itemSize)) == 0)
      {
	      return true;
      }
   }
 return false;
}

bool stack_destroy(Stack *S)
{
   if(S == NULL)
	   return true;
   if(S->LList == NULL)
	   return false;

   llist_destroy(S->LList);
   free(S);
   
    return true;

}


