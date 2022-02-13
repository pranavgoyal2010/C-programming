#include "heap.h"

Heap* heap_initialize(int dataSize, char *dataType, int(*Compare)(void*, void*), void(*Print)(void*))
{
	Heap *H = malloc(sizeof(Heap));

	if(H == NULL)
		return NULL;

	H->list = alist_initialize(10, dataSize, dataType);
	H->compare = Compare;
	H->print = Print;

	return H;
}

bool heap_insert(Heap *H, void *element)
{
	if(H == NULL || element == NULL)
		return false;
	if(H->list == NULL)
		return false;

	alist_add(H->list, element);

	return _heapify_up(H, heap_size(H)-1);
}

void* heap_remove(Heap *H)
{
	if(H == NULL)
		return NULL;
	if(H->list == NULL)
		return NULL;

	alist_swap(H->list, 0, heap_size(H)-1);

	void* element = alist_remove(H->list, heap_size(H)-1);

	_heapify(H, 0);

	return element;
}

void* heap_peek(Heap *H)
{
	return alist_get(H->list, 0);
}

int heap_size(Heap *H)
{
	if(H == NULL)
		return -1;
	if(H->list == NULL)
		return -1;

	return H->list->size;
}

bool heap_contains(Heap *H, void *element)
{
	if(H == NULL || element == NULL)
		return false;
	if(H->list == NULL)
		return false;

	int i = alist_index_of(H->list, element);

	if(i == -1)
		return false;
	
	return true;
}

bool _heapify(Heap *H, int index)
{
	if(index < 0 || index > heap_size(H)-1)
		return false;

	int top = index;
	
	if(alist_get(H->list, top) != NULL && alist_get(H->list, (2*index)+1) != NULL)
	{
		int c = H->compare(alist_get(H->list, top), alist_get(H->list, (2*index)+1));

		if(c < 0)
		   top = (2*index) + 1;
	}

	if(alist_get(H->list, top) != NULL && alist_get(H->list, 2*(index + 1)) != NULL)
	{
		int c = H->compare(alist_get(H->list, top), alist_get(H->list, 2*(index + 1)));

		if(c < 0)
	 	   top = 2*(index + 1);
	}

	if(top != index)
	{
		alist_swap(H->list, top, index);
		_heapify(H, top);
	}

	return true;
}

bool _heapify_up(Heap *H, int index)
{
	if(index < 0 || index > heap_size(H)-1)
		return false;

	int parentIndex = (index-1)/2;

	if(parentIndex < 0)
		return false;

	int c = H->compare(alist_get(H->list, parentIndex), alist_get(H->list, index));

	if(c < 0)
	{
		alist_swap(H->list, parentIndex, index);
		_heapify_up(H, parentIndex);
	}

	return true;
}	
