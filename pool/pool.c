#include "pool.h"


void* compute(void* arguments)
{
	Args* args = arguments;

	Operation* opera = args->operation;

	int* result = malloc(sizeof(int));
	       
	*result = opera->op(opera->a, opera->b);	

	args->is_complete = true;
	
	return result;	
}

bool read_operations(char* name, Queue* Q)
{
	if(name == NULL || Q == NULL)
		return false;

	Operation *opera = malloc(sizeof(Operation));
	
	FILE* filepointer = fopen(name, "r");
	
	if(filepointer == NULL || opera == NULL)
		return false;

	int i =0;
	int operand, para1, para2;

	while(fscanf(filepointer, "%d %d %d", &operand, &para1, &para2) == 3)
	{

		if(operand == 0)
			opera->op = add;

		if(operand == 1)
			opera->op = sub;

		if(operand == 2)
			opera->op = mul;

		opera->a = para1;
		opera->b = para2;
		
		(void*)opera;
		queue_enqueue(Q, opera);

		i++;
	}

	if(i == queue_size(Q))
		return true;
	else
		return false;

}

ArrayList* execute_thread_pool(char* fileName, int N)
{
	Queue *queue = queue_initialize(sizeof(Operation), "Operation");

	if(queue == NULL)
		return NULL;

	pthread_t thread[N];

	read_operations(fileName, queue);
		
	Args args[N];

	for(int i=0; i<N; i++)
	{
		args[i].operation = queue_dequeue(queue);
		args[i].is_complete = false;
		pthread_create(&thread[i], NULL, compute, &args[i]);
	}
	
	int j = 0;
	int* value = NULL;
	
	ArrayList* AList =  alist_initialize(10, sizeof(int), "int");
	
	if(AList == NULL)
		return NULL;
		
        while(queue_size(queue)>0)
	{
		if(args[j].is_complete == true)
		{
			
			pthread_join(thread[j], (void**) &value);
			
			alist_add(AList, value);

			args[j].operation = queue_dequeue(queue);
			args[j].is_complete = false;
			pthread_create(&thread[j], NULL, compute, &args[j]);
		}

		j = (j+1) % N;

	}

	for(int i=0; i<N; i++)
	{
		pthread_join(thread[i], (void**) &value);

		alist_add(AList, value);
	}	

	return AList;
}

void print_sorted(ArrayList* AList)
{
	Heap* heap = heap_initialize(sizeof(4), "int", compareInt, printInt);
	
	if(heap == NULL)
		return;

	for(int i=0; i<AList->size; i++)
	{
		heap_insert(heap, (int*)alist_get(AList, i));

	}

	for(int i=0; i<10000; i++)
	{

		printf("%d\n", *((int*)heap_remove(heap)));
	}
}

int add(int a, int b)
{
	return (a+b);
}

int sub(int a, int b)
{
	return (a-b);
}

int mul(int a, int b)
{
	return (a*b);
}

int compareInt(void* a, void* b)
{
	return *((int*)b) - *((int*)a);
}

void printInt(void* a)
{
	printf("%d", *((int*)a));
}
