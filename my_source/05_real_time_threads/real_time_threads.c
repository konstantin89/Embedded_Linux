/**
* Example of Linux real time threading.
* Setting thread to maximum priority.
*
* RUN AS SUDO!
*/

#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <errno.h>

void printPolicyVals()
{
	printf("SCHED_RR:    %d.\n", SCHED_RR);
	printf("SCHED_FIFO:  %d.\n", SCHED_FIFO);
	printf("SCHED_OTHER: %d.\n", SCHED_OTHER);
	printf("\n");
}

int main(void)
{	
	printPolicyVals();

	int ret;

    /* Get current running thread. */
    pthread_t this_thread = pthread_self();

	/* struct sched_param is used to store the scheduling priority */
    struct sched_param params;
   	int policy;
 
	/* Check with what priority thread is started by default. */
	ret = pthread_getschedparam(this_thread, &policy, &params);
    if (ret != 0) 
	{
        printf("Failed to get thread priority params.\n");
		return -1;
    }
    printf("Thread priority  before setting RT is: %d.\n" ,params.sched_priority); 
    printf("Default scheduling policy is: %d. \n\n", policy); 
	
	/* Set the priority to the maximum. */
    params.sched_priority = sched_get_priority_max(SCHED_FIFO);
    
	// Attempt to set thread real-time priority to the SCHED_FIFO policy
    ret = pthread_setschedparam(this_thread, SCHED_FIFO, &params);
    if (ret != 0) {
        printf("Failed to set thread as RealTime priority with errno: %d.\n", errno);
        return -1;     
    }


 	/* Now verify the change in thread priority */
    policy = 0;
    ret = pthread_getschedparam(this_thread, &policy, &params);
    if (ret != 0) 
	{
        printf("Failed to get thread priority params.\n");
		return -1;
    }
 
    // Check the correct policy was applied
    if(policy != SCHED_FIFO) 
	{
    	printf("Thread priority is not SCHED_FIFO.\n");
    } 
	else 
	{
        printf("Thread priority is SCHED_FIFO.\n"); 
    }
    printf("Thread priority is: %d.\n" ,params.sched_priority); 
	return 0;
}





/***************************** End Of File ******************************/
