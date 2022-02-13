#include "linked_list.h"

LinkedList* llist_initialize(int data_type_size, char* dataType)
{
   LinkedList *LList = malloc(sizeof(LinkedList));
   
   if(LList == NULL || dataType == NULL)
     return NULL;

   LList->first = NULL;
   LList->last = NULL;
   LList->size = 0;
   LList->itemSize = data_type_size;
   LList->type = malloc(strlen(dataType) + 1);
   strcpy(LList->type, dataType);
   
   return LList;
}

bool llist_add_at(LinkedList *LList, int index, void *element)
{
 if(element != NULL && LList != NULL)
 {
   
   Node *newNode = malloc(sizeof(Node));
    
   if(newNode == NULL)
       return false;

   newNode->data = malloc(LList->itemSize);
   
   if(newNode->data == NULL)
       return false;

     if(index>0 && index<((LList->size)))
     {
     
       Node *currentNode = LList->first;

       if(currentNode == NULL)
	   return false;

       for(int i=0; i<index; i++)
       {
	   currentNode = currentNode->next;
       }

        if(currentNode == NULL)
	  return false;

          memcpy(newNode->data, element, LList->itemSize);
    
          (currentNode->prev)->next = newNode;
	  newNode->next = currentNode;
          newNode->prev = currentNode->prev;
          currentNode->prev = newNode;
          
          LList->size++;
	  if(LList->first !=NULL && LList->last !=NULL && newNode->prev !=NULL && newNode->next !=NULL && currentNode->prev !=NULL && (currentNode->prev)->next !=NULL)
           return true;
	  else
           return false;
     }

     else if(LList->size == 0)
     {
	memcpy(newNode->data, element, LList->itemSize);
	LList->first = newNode;
	LList->last = newNode;
	newNode->next = NULL;
	newNode->prev = NULL;
	LList->size++;
	if(LList->first !=NULL && LList->last !=NULL)
	 return true;
	else
	 return false;
     }

     else if(index == 0)
     {
	memcpy(newNode->data, element, LList->itemSize);
        Node *currentNode = LList->first;
        
	if(currentNode == NULL)
	  return false;

	currentNode->prev = newNode;
	newNode->prev = NULL;
	newNode->next = currentNode;
	LList->first = newNode;

	LList->size++;
	if(LList->first !=NULL && newNode->next !=NULL && currentNode->prev !=NULL)
	 return true;
	else
	 return false;
     }

     else if(index == (LList->size))
     {
	memcpy(newNode->data, element, LList->itemSize);
	Node *currentNode = LList->last;
        
	if(currentNode == NULL)
	  return false;

	newNode->next = NULL;
	newNode->prev = currentNode;
	currentNode->next = newNode;
	LList->last = newNode;
	
	LList->size++;
	if(LList->last != NULL && newNode->prev !=NULL && currentNode->next !=NULL)
          return true;
	else
	  return false;
     }

     else
       return false;  
 }
 return false;
  
}

bool llist_add_first(LinkedList *LList, void *element)
{
  if(element != NULL && LList != NULL)
    llist_add_at(LList, 0, element);
  else
    return false;
}

bool llist_add_last(LinkedList *LList, void *element)
{
  if(element != NULL && LList != NULL)
    llist_add_at(LList, (LList->size), element);
  else
    return false;
}

void* llist_get(LinkedList *LList, int index)
{
 if(LList != NULL)
 {
   if(index>=0 && index<(LList->size))
   {
    void *element = malloc(LList->itemSize);
    Node *currentNode = LList->first;
    
    if(currentNode == NULL)
      return NULL;

    for(int i=0; i<index; i++)
    {
	currentNode = currentNode->next;
    }

    if(currentNode == NULL)
      return NULL;
    
    memcpy(element, currentNode->data, LList->itemSize);
    
    if(element != NULL)
     return element;
   }

   return NULL;
 }
  return NULL;
}

int llist_index_of(LinkedList *LList, void *element)
{
 if(element != NULL && LList != NULL)
 {
   Node *currentNode = LList->first;

   if(currentNode == NULL)
     return -1;

   for(int i=0; i<(LList->size); i++)
   {
      if(currentNode == NULL || currentNode->data == NULL)
	  return -1;

      if(memcmp(element, currentNode->data, LList->itemSize) == 0)
      {
         return i;
      }

      currentNode = currentNode->next;
   }

   return -1;
 }   

   return -1;
}

void* llist_remove(LinkedList *LList, int index)
{
 if(LList != NULL)
 {
  	if(index>0 && index<(LList->size)-1)
  	{
    		void *element = malloc(LList->itemSize);
                
		if(element == NULL)
		  return NULL;

    		Node *currentNode = LList->first;
                
		if(currentNode == NULL)
		  return NULL;


    		for(int i=0; i<index; i++)
    		{
      		   currentNode = currentNode->next;
    		}
		
		if(currentNode == NULL || currentNode->data == NULL)
		  return NULL;

     		memcpy(element, currentNode->data, LList->itemSize);

     		(currentNode->prev)->next = currentNode->next;
     		(currentNode->next)->prev = currentNode->prev;

                if((currentNode->prev)->next == NULL || (currentNode->next)->prev == NULL)
		   return NULL;

     		free(currentNode->data);
     		free(currentNode);
     		LList->size--;

     		if(element != NULL)
       		  return element;
                else
		  return NULL;
  	}

  	else if(index == 0)
  	{
		 if(LList->size == 1)
                {
                     Node *currentNode = LList->first;

                     if(currentNode == NULL)
                           return NULL;

                     void *element = malloc(LList->itemSize);

                     if(element == NULL)
                        return NULL;

                     memcpy(element, currentNode->data, LList->itemSize);

                     LList->first = NULL;
                     currentNode->next = NULL;
                     currentNode->prev = NULL;

                     free(currentNode->data);
                     free(currentNode);
                     LList->size--;

                     if(element != NULL)
                        return element;
                     else
                        return NULL;
                }

     		Node *currentNode = LList->first;
                
		if(currentNode == NULL)
			return NULL;

     		void *element = malloc(LList->itemSize);
		
		if(element == NULL)
		   return NULL;

    		memcpy(element, currentNode->data, LList->itemSize);

     		LList->first = currentNode->next;

		if(LList->first == NULL)
			return NULL;

     		(currentNode->next)->prev = NULL;
     
     		currentNode->next = NULL;
     		free(currentNode->data);
     		free(currentNode);
     		LList->size--;

     		if(element != NULL)
     		  return element;
                else
		   return NULL;
  	}

  	else if(index == (LList->size)-1)
  	{
     		Node *currentNode = LList->last;
                
	       	if(currentNode == NULL)
			return NULL;

     		void *element = malloc(LList->itemSize);

		if(element == NULL)
		    return NULL;

     		memcpy(element, currentNode->data, LList->itemSize);

     		LList->last = currentNode->prev;

		if(LList->last == NULL)
			return NULL;

     		(currentNode->prev)->next = NULL;
     
     		currentNode->prev = NULL;

     		free(currentNode->data);
     		free(currentNode);
     		LList->size--;

     		if(element != NULL)
       		  return element;
		else
		  return NULL;
  	}

  	else
    	 return NULL;
 }
 
 else
  return NULL;

}

void* llist_remove_first(LinkedList *LList)
{
  if(LList != NULL)
    llist_remove(LList, 0);
  else
   return false;
}

void* llist_remove_last(LinkedList *LList)
{
  if(LList != NULL)
   llist_remove(LList, (LList->size)-1);
  else
    return false;
}

bool llist_destroy(LinkedList *LList)
{
  if(LList != NULL)
  {
   Node *currentNode = LList->first;

   for(int i=0; i<(LList->size); i++)
   {
      Node *temp = currentNode->next;
      free(currentNode->data);
      
      free(currentNode);
      currentNode = temp;
   }

   free(LList->type);

   free(LList);

   return 1;
  }

  return 0;
}
