#include "bintree.h"

BinaryTree* bintree_initialize(int size, char* dataType, int (*Compare)(void*, void*), void (*Print)(void*))
{
	BinaryTree *BTree = malloc(sizeof(BinaryTree));

	if(BTree == NULL || dataType == NULL)
	  return NULL;

	BTree->top = NULL;
	BTree->itemSize = size;
	BTree->type = malloc(strlen(dataType) + 1);

	if(BTree->type == NULL)
		return NULL;

	strcpy(BTree->type, dataType);
	BTree->compare = Compare;
	
	if(BTree->compare == NULL)
		return NULL;

	BTree->print = Print;

	if(BTree->print == NULL)
		return NULL;

	return BTree;
}

BinaryTreeNode* bintree_create_node(int dataSize, void *element)
{
	BinaryTreeNode *newNode = malloc(sizeof(BinaryTreeNode));
	
	if(newNode == NULL)
		return NULL;

	newNode->data = malloc(dataSize);

	if(newNode->data == NULL)
		return NULL;
	if(element == NULL)
		return NULL;

	newNode->data = element;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}	

bool bintree_insert(BinaryTree *BTree, void *element)
{
	if(BTree == NULL || element == NULL)
		return false;

	if(BTree->top == NULL)
	{
	     BTree->top = bintree_create_node(BTree->itemSize, element);

	     if(BTree->top == NULL)
		     return false;

	     return true;
	}	

	
	return _bintree_insert_recursive(BTree, (BTree->top), element);
}

bool bintree_search(BinaryTree *BTree, void *element)
{
	if(BTree == NULL || element == NULL)
		return false;

	return _bintree_search_recursive(BTree, BTree->top, element);
}

void bintree_print_in_order(BinaryTree *BTree)
{
	if(BTree != NULL)
	_bintree_in_order_recursive(BTree, BTree->top);
}

void bintree_print_pre_order(BinaryTree *BTree)
{
	if(BTree != NULL)
	_bintree_pre_order_recursive(BTree, BTree->top);
}

void bintree_print_post_order(BinaryTree *BTree)
{
	if(BTree != NULL)
	_bintree_post_order_recursive(BTree, BTree->top);
}

void bintree_print_reverse_order(BinaryTree *BTree)
{
	if(BTree != NULL)
	_bintree_reverse_order_recursive(BTree, BTree->top);
}

bool _bintree_insert_recursive(BinaryTree *BTree, BinaryTreeNode *Node, void *element)
{
        int c = BTree->compare(Node->data, element);

        if(c<0)
        {
                if(Node->left == NULL)
                {
		    Node->left = bintree_create_node(BTree->itemSize, element);

	           	if(Node->left == NULL)
        	     	   return false;

          	    return true;
	
                }
                else
                {
		    _bintree_insert_recursive(BTree, Node->left, element);
                }
        }
        else
        {
                if(Node->right == NULL)
                {
		    Node->right = bintree_create_node(BTree->itemSize, element);

		    if(Node->right == NULL)
                        return false;

		    return true;
                }
                else
                {
                    _bintree_insert_recursive(BTree, Node->right,  element);
                }
        }

}

bool _bintree_search_recursive(BinaryTree *BTree, BinaryTreeNode *Node, void *element)
{
	if(Node == NULL || element == NULL || BTree == NULL)
		return false;

	int c = BTree->compare(Node->data, element);

	if(c == 0)
	{
		return true;
	}

	else
	{

		if(c<0)
		{
		     if(Node->left != NULL)
			_bintree_search_recursive(BTree, Node->left, element);
		     else
			 return false;
		}

		else
		{
		     if(Node->right != NULL)
			_bintree_search_recursive(BTree, Node->right, element);
		     else
			 return false;
		}

	}
}

void _bintree_in_order_recursive(BinaryTree *BTree, BinaryTreeNode *Node)
{

	if(Node->left != NULL)
	{
		_bintree_in_order_recursive(BTree, Node->left);
	}

		BTree->print(Node->data);
	

	if(Node->right != NULL)
	{
		_bintree_in_order_recursive(BTree, Node->right);
	}

}

void _bintree_reverse_order_recursive(BinaryTree *BTree, BinaryTreeNode *Node)
{
	if(Node->right != NULL)
		_bintree_reverse_order_recursive(BTree, Node->right);

	BTree->print(Node->data);

	if(Node->left != NULL)
		_bintree_reverse_order_recursive(BTree, Node->left);
}

void _bintree_post_order_recursive(BinaryTree *BTree, BinaryTreeNode *Node)
{
	if(Node->left != NULL)
		_bintree_post_order_recursive(BTree, Node->left);
	if(Node->right != NULL)
		_bintree_post_order_recursive(BTree, Node->right);
	BTree->print(Node->data);
}

void _bintree_pre_order_recursive(BinaryTree *BTree, BinaryTreeNode *Node)
{
	BTree->print(Node->data);
	if(Node->left != NULL)
		_bintree_pre_order_recursive(BTree, Node->left);
	if(Node->right != NULL)
		_bintree_pre_order_recursive(BTree, Node->right);
}

void bintree_print_breadth_first(BinaryTree *BTree)
{
	if(BTree == NULL || BTree->top == NULL)
		return;

	Queue *queue = queue_initialize(sizeof(BinaryTreeNode), BTree->type);

	queue_enqueue(queue, BTree->top);
	//printf("%d\n", queue_size(queue));
	_print_breadth_first_recursive(BTree, queue);
}

void bintree_print_depth_first(BinaryTree *BTree)
{
	if(BTree == NULL || BTree->top == NULL)
		return;
	
	Stack *stack = stack_initialize(sizeof(BinaryTreeNode), BTree->type);

	stack_push(stack, BTree->top);

	_print_depth_first_recursive(BTree, stack);
}

void _print_breadth_first_recursive(BinaryTree *BTree, Queue *queue)
{
	//printf("%d\n", queue_size(queue));
	if(queue_size(queue) != 0)
	{
		BinaryTreeNode *Node = queue_dequeue(queue);
		BTree->print(Node->data);

		if(Node->left != NULL)
			queue_enqueue(queue, Node->left);
		if(Node->right != NULL)
			queue_enqueue(queue, Node->right);

		_print_breadth_first_recursive(BTree, queue);
	}
}

void _print_depth_first_recursive(BinaryTree *BTree, Stack *stack)
{
	if(stack_size(stack) != 0)
	{
		BinaryTreeNode *Node = stack_pop(stack);
		BTree->print(Node->data);

		if(Node->right != NULL)
			stack_push(stack, Node->right);

		if(Node->left != NULL)
			stack_push(stack, Node->left);


		//if(stack_size(stack) != 0)
	        	_print_depth_first_recursive(BTree, stack);

	}


}

bool bintree_insert_replace(BinaryTree *BTree, void *element)
{
	if(BTree == NULL || element == NULL)
			return false;

	if(BTree->top == NULL)
	{
		BTree->top = bintree_create_node(BTree->itemSize, element);

		if(BTree->top == NULL)
			return false;

		return true;
	}	
		
		return _bintree_insert_replace_recursive(BTree, (BTree->top), element);

}

bool _bintree_insert_replace_recursive(BinaryTree *BTree, BinaryTreeNode *Node, void *element)
{
	 int c = BTree->compare(Node->data, element);

         if(c<0)
	 {
		 if(Node->left == NULL)
		 { 
			 Node->left = bintree_create_node(BTree->itemSize, element);
			 
			 if(Node->left == NULL)
				 return false;


                     	    return true;
																	    	
	          }
		  else
		  {
			 _bintree_insert_replace_recursive(BTree, Node->left, element);
		 
	       	  }
	 }
	 else if(c>0)
	 {
		 if(Node->right == NULL)
		 {
			 Node->right = bintree_create_node(BTree->itemSize, element);

			 if(Node->right == NULL)
                            return false;

    		    return true;
                 }
                 else
                 {
                       _bintree_insert_replace_recursive(BTree, Node->right,  element);
                 }
         }
	else
	{
		void *temp = Node->data;
		 Node->data = element;

        	int c_again = BTree->compare(Node->data, temp);

		if(c_again == 0)
	        	return true;
		else
		  //_bintree_insert_replace_recursive(BTree, Node, element);
		  return false;
	}

}
