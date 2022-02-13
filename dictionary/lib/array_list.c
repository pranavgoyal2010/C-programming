#include "array_list.h"

ArrayList* alist_initialize(int max_size, int data_type_size, char* dataType)
{
     ArrayList *AList = malloc(sizeof(ArrayList));

     if(AList == NULL)
	    return NULL;

     AList->arr =  malloc(sizeof(void*) * max_size);
     AList->size = 0;
     AList->type = dataType;
     AList->maxSize = max_size;
     AList->itemSize = data_type_size;

     return AList;
}

bool alist_add(ArrayList *a, void *element)
{
  if(element != NULL)
  {   
     if(a->size == a->maxSize)
     {
	_alist_resize(a);
     }
    
     a->arr[a->size] = malloc(a->itemSize);
     memcpy(a->arr[a->size], element, a->itemSize); 

     a->size++;
     
     if(a->arr[(a->size)-1] == NULL)
     {
	return 0;
     }
     
     return 1;
  }
  return 0;
}

bool alist_add_at(ArrayList* a, int index, void *element)
{
  if(element != NULL)
  {

   if(index >=0 && index <= (a->size))
   {
     if((a->size) == (a->maxSize))
     {
       _alist_resize(a);
     }
     
       a->arr[a->size] = malloc(a->itemSize);
      
     for(int i=(a->size); i>index; i--)
     {
	a->arr[i] = a->arr[i-1]; 
     }
     
     a->arr[index] = malloc(a->itemSize); 
    
     memcpy(a->arr[index], element, a->itemSize);
     a->size++;
     if(a->arr[index] == NULL)
     {
	return 0;
     }

     return 1;
   }

   return 0;
  }

  return 0;
}

void alist_clear(ArrayList *a)
{
     for(int i=0; i<(a->size); i++)
     {
        free(a->arr[i]);
     }

     a->size = 0;
}

void *alist_get(ArrayList *a, int index)
{
     if(index < 0 && index > a->size)
       return NULL;


     return (a->arr[index]); 
}

int alist_index_of(ArrayList *a, void *element)
{
  if(element != NULL)
  {
     for(int i=0; i<(a->size); i++)
     {
	 if(memcmp(element, a->arr[i], a->itemSize) == 0)
         {
            return i;
	 }
     }

     return -1;
  }
  return -1;
}

void* alist_remove(ArrayList *a, int index)
{
  if(a != NULL)
  {
    if(index >=0 && index <(a->size))
    {
	 void *dest;
	 void *element = memcpy(dest, a->arr[index], a->itemSize);
	 free(a->arr[index]);

	 for(int i=index; i<(a->size)-1; i++)
	 {
	     a->arr[i] = a->arr[i+1];
	 }

	 a->size--;
	 return element;

    }

   return NULL;
  }
}

bool alist_destroy(ArrayList *a)
{
   for(int i=0; i<(a->size); i++)
   {
     free(a->arr[i]);
   }

    free(a->arr);
    return 1;
}

bool _alist_resize(ArrayList *a)
{
    a->maxSize *= 2;

    a->arr = realloc(a->arr, sizeof(void*) * a->maxSize);

    if(a->arr[(a->maxSize)-1] == 0)
    {
      return 0;
    }

    return 1;
}


