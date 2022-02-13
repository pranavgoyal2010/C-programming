#include "safe.h"

sem_t wait_here;

void *counting(void* C)
{
	    Count* count = C;

	while(count->counter < 1000)
	{
	    	sem_wait(&wait_here);

		if(count->counter >= 1000)

		{

			sem_post(&wait_here);

			break;

		}
      		count->counter++;

		printf("%d\n", count->counter);

	        sem_post(&wait_here);
	
	}
}

void count_variable(int N)
{
	sem_init(&wait_here, 0, 1);

	pthread_t thread[N];
	Count count;

	
	count.counter = 0;


	for(int i=0; i<N; i++)
	{
		pthread_create(&thread[i], NULL, counting, &count);
	}

	for(int i=0; i<N; i++)
	{
		pthread_join(thread[i], NULL);
	}

}
