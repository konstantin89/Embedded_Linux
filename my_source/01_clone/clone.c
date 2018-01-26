/**
       Unlike fork, clone() allows the child process to share parts of
       its execution context with the calling process, such as the virtual
       address space, the table of file descriptors, and the table of signal
       handlers.
*/

#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define errExit(msg)  do { perror(msg); exit(EXIT_FAILURE); \
                        } while (0)

/* Stack size for cloned child */
#define STACK_SIZE (1024 * 1024)   

/**
* Function used in child process.
*/
static int childFunc(void *arg)
{
	printf("Child process pid: %d, parent pid: %d.\n", getpid(), getppid());	
	sleep(1);
	
	/* Child terminates now */
	return 0;          
}



int main()
{
	char *stack;                    /* Start of stack buffer */
   	char *stackTop;                 /* End of stack buffer */
    pid_t pid;

    /* Allocate stack for child */
    stack = malloc(STACK_SIZE);
    if (stack == NULL)
	{
        errExit("malloc");
    }

	/* Assume stack grows downward */
	stackTop = stack + STACK_SIZE; 
    pid = clone(childFunc, stackTop, SIGCHLD , NULL);
    if (pid == -1)
    {
	    errExit("clone");
    }
	printf("clone() returned %ld\n", (long) pid);

    /* Parent falls through to here */
    sleep(1);  

	/* Wait for child */
    if (waitpid(pid, NULL, 0) == -1)
	{   
        errExit("waitpid");
    }
	printf("child has terminated\n");

    exit(EXIT_SUCCESS);
}
