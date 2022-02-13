#ifndef __DICT_HEADER
#define __DICT_HEADER

#include "bintree.h"
#include "array_list.h"

typedef struct _Pair
{
	void *first;
	void *second;
}Pair;

typedef struct _Dictionary
{
	BinaryTree *tree;
}Dictionary;

Dictionary* dict_initialize(int(*)(void*, void*), void(*)(void*));
bool dict_insert(Dictionary*, void*, void*);
void* dict_get(Dictionary*, void*);
void* _dict_get_recursive(Dictionary*, BinaryTreeNode*, Pair*);
ArrayList* dict_key_list(Dictionary*, int);
ArrayList* _dict_key_list_recursive(Dictionary*, BinaryTreeNode*, ArrayList*);
bool dict_contains(Dictionary*, void*);

#endif
