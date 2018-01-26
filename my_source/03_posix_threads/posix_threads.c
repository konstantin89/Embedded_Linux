/**
* Example of pthreads usage in linux.
*/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t lock;

/**
* Simple thread safe function that will
* run in created threads.
*/
void* threadSafeTask(void *arg)
{
    
	pthread_mutex_lock(&lock);
    printf("Running thread.\n");
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void)
{

	int numberOfThreads = 0;
	printf("Enter number of threads to create: ");
	scanf("%d", &numberOfThreads);
	if(numberOfThreads < 0)
	{
		printf("Invalid number of threads.\n");
		return -1;
	}
	
	pthread_t* threadArr = NULL;

    int i = 0;
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return -1;
    }

	threadArr = malloc(sizeof(pthread_t) * numberOfThreads);
	if(threadArr == NULL)
	{
		printf("malloc() failed.\n");
		return -1;
	}	

    while(i < numberOfThreads)
    {
        err = pthread_create(&(threadArr[i]), NULL,  &threadSafeTask, NULL);
        if (err != 0)
		{
            printf("Can't create thread :[%s]", strerror(err));
    	}    
		i++;
    }
	
	i = 0;
	while(i < numberOfThreads)
	{
		/* join() waits until the given thread returns. */
		pthread_join(threadArr[i], NULL);
		i++;
	}
    pthread_mutex_destroy(&lock);
	free(threadArr);	

    return 0;
}



/************************************* End Of File ************************************/
