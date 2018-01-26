/**
* Zombie process is process in "terminated" state.
* Terminated process is zombie until its parent process
* doesn't calls wait() to get its terminated child exit 
* code.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int pid;
	int waitRetVal;	

    /* let's create a child process */
    pid = fork();
    if (!pid) {
        /* this is a child: dies immediately and becomes zombie */
        exit(0);
    }

    /* parent process: just asks for the user input */
    printf("Please, press enter after looking at the zombie process...");
    (void)getchar();
	
	waitRetVal = waitpid(pid, NULL, 0);
	printf("Child process with %d pid terminated.\n", waitRetVal);
}


/************************** End Of File ******************************/
