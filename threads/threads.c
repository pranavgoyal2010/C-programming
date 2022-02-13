#include "threads.h"

void* fill(void *arg)
{
	Args* args = arg;

	int *array = args->arr;

	for(int i=(args->start); i<(args->end); i++)
	{
		args->arr[i]= (args->arr[i]) * (args->arr[i]);
	}	
   return NULL;
}

void fill_memory(int* array, int N)
{
	//if(array == NULL)
	//	return;

	pthread_t thread[N];

	Args args[N];

	//int size = sizeof(array)/sizeof(array[0]);
	
	int size = 10000000;

	int range = size/N;

	for(int i=0; i<N; i++)
	{
		args[i].arr = array;
		args[i].start = i*range;
		args[i].end = (i+1)*range;
	}

	args[N-1].end = size;

	for(int i=0; i<N; i++)
	{
		pthread_create(&thread[i], NULL, fill, &args[i]);
	}

	for(int i=0; i<N; i++)
	{
		pthread_join(thread[i], NULL);
	}
}
