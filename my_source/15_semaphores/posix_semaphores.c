/**********************************************************
*
* Example of posix semaphores usage in posix threads
* synchronisation.
*
* Single producer, produces resources and awakes one of
* the two consumers.
*
* Example output:
*   Consumer 0 awaken
*   Consumer 1 awaken
*   Consumer 0 awaken
*   Consumer 1 awaken
*   Consumer 0 awaken
*   Consumer 1 awaken
*   Consumer 0 awaken
*
***********************************************************/


#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>


#define ERROR(msg) do{printf("ERROR: %s\n", msg); return -1;}while(0)

/**
* Struct used to pass argument to consumer threads.
*/
typedef struct ConsumerArgs
{
    sem_t* semaphore;
    int id;
} ConsumerArgs;

/**
* Function that used in producer thread.
*/
void* producer(void* arg_semaphore)
{
    sem_t* semaphore = (sem_t*)arg_semaphore;
    while(1)
    {
        sleep(1);
        sem_post(semaphore);
    }
}

/**
* Function that used in consumer threads.
*/
void* consumer(void* args_void_ptr)
{
    ConsumerArgs* args_struct = (ConsumerArgs*)args_void_ptr;
    sem_t* semaphore = args_struct->semaphore;
    int id = args_struct->id;

    while(1)
    {
        sem_wait(semaphore);
        printf("Consumer %d awaken\n", id);
    }
}

int main()
{
    /* Create variables */
    int ret_val = 0;
    sem_t semaphore;
    pthread_t comsumer0_thread;
    pthread_t comsumer1_thread;
    pthread_t producer_thread;

    /* Initiate consumer threads arguments */
    ConsumerArgs consumer_0_args;
    consumer_0_args.semaphore = &semaphore;
    consumer_0_args.id = 0;

    ConsumerArgs consumer_1_args;
    consumer_1_args.semaphore = &semaphore;
    consumer_1_args.id = 1;

    /* Initiate semaphore */
    ret_val = sem_init(&semaphore, 0, 0);
    if(ret_val != 0)
    {
        ERROR("sem_init");
    }

    /* Create threads  */
    ret_val = pthread_create(&comsumer0_thread,
                             NULL,
                             consumer,
                             &consumer_0_args);
    if(ret_val != 0)
    {
        ERROR("pthread_create");
    }

    ret_val = pthread_create(&comsumer1_thread,
                             NULL,
                             consumer,
                             &consumer_1_args);
    if(ret_val != 0)
    {
        ERROR("pthread_create");
    }


    ret_val = pthread_create(&producer_thread,
                             NULL,
                             producer,
                             &semaphore);
    if(ret_val != 0)
    {
        ERROR("pthread_create");
    }

    /* Join all threads */
    pthread_join(comsumer0_thread, NULL);
    pthread_join(comsumer1_thread, NULL);
    pthread_join(producer_thread, NULL);

    return 0;
}



/*********************** End Of File ************************/
