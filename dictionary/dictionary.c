#include "dictionary.h"

Dictionary* dict_initialize(int(*Compare)(void*, void*), void(*Print)(void*))
{
	Dictionary *D = malloc(sizeof(Dictionary));
	char *type = "Pair";
	D->tree = bintree_initialize(sizeof(Pair), type, Compare, Print);

	return D;
}

bool dict_insert(Dictionary *D, void *key, void *value)
{
	if(D == NULL)
		return false;

	Pair *P = malloc(sizeof(Pair));

	P->first = key;
	P->second = value;

	return bintree_insert_replace(D->tree, P);
}

void* dict_get(Dictionary *D, void *key)
{
	if(D == NULL || key == NULL)
		return NULL;
	
	Pair *P = malloc(sizeof(Pair));

	P->first = key;

	_dict_get_recursive(D, D->tree->top, P);

}

void* _dict_get_recursive(Dictionary *D, BinaryTreeNode *Node, Pair *P)
{
	if(Node == NULL || P == NULL)
		return NULL;

	int c = D->tree->compare(Node->data, P);

	if(c == 0)
	{
		return ((Pair*)(Node->data))->second;
	}
	else if(c > 0)
	{
		if(Node->right == NULL)
			return NULL;

		_dict_get_recursive(D, Node->right, P);
	}
	else
	{
		if(Node->left == NULL)
			return NULL;

		_dict_get_recursive(D, Node->left, P);
	}
}

ArrayList* dict_key_list(Dictionary *D, int size)
{
	ArrayList *AList = alist_initialize(10, size, "void");
	
	if(D == NULL || AList == NULL)
		return NULL;
	if(D->tree->top == NULL)
		return NULL;

	return _dict_key_list_recursive(D, D->tree->top, AList);

}

ArrayList* _dict_key_list_recursive(Dictionary *D, BinaryTreeNode *Node, ArrayList *AList)
{
	if(Node->data == NULL)
		return NULL;


	if(Node->left != NULL)
		_dict_key_list_recursive(D, Node->left, AList);

	alist_add(AList, ((Pair*)(Node->data))->first);
			
	if(Node->right != NULL)
		_dict_key_list_recursive(D, Node->right, AList);
	
		return AList;
}

bool dict_contains(Dictionary *D, void *key)
{
	Pair *P = malloc(sizeof(Pair));

	P->first = key;

	return bintree_search(D->tree, P);
}

 

