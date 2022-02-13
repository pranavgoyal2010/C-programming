#include "unsafe.h"

void* counting(void* C)
{
	Count* count = C;
	
	//if(count == NULL)
	//	return NULL;
	
	while(count->counter < 1000)
	{
//	if(count->counter < 1000)
		count->counter++;
	
		printf("%d\n", count->counter);
	}
	return NULL;	
}

void count_variable(int N)
{
	pthread_t thread[N];

	Count count;
	
	count.counter = 0;

	for(int i = 0; i<N; i++)
	{
	    pthread_create(&thread[i], NULL, counting, &count);
	}

	for(int i=0; i<N; i++)
	{
	   pthread_join(thread[i], NULL);
	}

}
