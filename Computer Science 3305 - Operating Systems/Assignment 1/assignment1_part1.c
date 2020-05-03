//=================================================================================
// File Name   : assignment1_part1.c
// Author      : Philip Radojcic
// Description : Creates a parent and child process in a specific sequence.
// Latest Edit : 10/7/2019
//=================================================================================

// Include List:
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main () {

	// Creates a fork of the main process, therefore creating a child for the parent process.
	pid_t fork_call, fork_call_2;
	fork_call = fork();
	
	// If fork() fails and the child is not created.
	if (fork_call < 0)
	{
		printf ("The fork() process was unsuccessful and no child was created.");
		exit(1);
	}
	
	// The current process running is the parent.
	if (fork_call > 0)
	{
		printf("Parent process (PID %d) created child_1 (PID %d).\n",  getppid(), getpid());
		printf("Parent process (PID %d) is waiting for child_1 (PID %d) to complete before creating child_2.\n", getppid(), getpid());
		// Wait for the child process to finish being created.
		wait(NULL);
	}
	
	// The current process running is the child.
	if (fork_call == 0) 
	{
		printf("child_1 (PID %d) created child_1.1(PID %d).\n", getppid(), getpid());
		printf("child_1 (PID %d) is now completed.\n", getpid());
		
		// Creates a second fork of the main process, therefore creating a child2 for the parent process.
		fork_call_2 = fork();
			
		// If fork() fails and the child is not created.
		if (fork_call_2 < 0)
		{
			printf ("The second fork() process was unsuccessful and child 2 was not created.");
			exit(1);
		}
		
		// The current process running is the parent.
		if (fork_call_2 > 0)
		{
			// Wait for the child process to finish being created.
			wait(NULL);
		}
		
		// The current process running is the child.
		if (fork_call_2 == 0) 
		{
			printf("Parent process (PID %d) created child_2 (PID %d).\n",  getppid(), getpid());
			printf("child_2 (PID %d) is calling an external program external_program.out and leaving child_2 ...\n", getpid());
			execl("external_program.out", NULL);
		}
	}
}
