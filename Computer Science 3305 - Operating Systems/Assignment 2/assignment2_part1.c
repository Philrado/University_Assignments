//=================================================================================
// File Name   : assignment2_part1.c
// Author      : Philip Radojcic
// Description : Have a parent create variables x,y,z initialized to 10, 20 and 0.
//               The parent then creates a child to perform z = x+y, and the parent
//               prints out z. The parent then creates a thread, which will do the 
//               exact same thing.   
// Latest Edit : 10/30/2019
//=================================================================================

// Include List:
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>

int main(int argc, char *argv[] ) {

	// ----------------------------------------- Part 1.1 and 1.2 -----------------------------------------------

	printf("\n");	
	printf("Program STARTING:\n");
	printf("-------------------------------------------------------------------------------------------------\n");	

	// Inital parent program variables:
	int x = 10;
	int y = 20;
	int z = 0;
	
	// Creates a fork of the main process, therefore creating a child for the parent process.
	pid_t fork_call = fork();
	
	// If fork() fails and the child is not created.
	if (fork_call < 0)
	{
		printf ("The fork() process was unsuccessful and no child was created.");
		exit(1);
	}
	
	// The current process running is the child.
	if (fork_call == 0) 
	{	
		printf("Child process (PID %d) is calculating z = x + y.\n", getpid());
		z = x + y;
	}
	
	// The current process running is the parent.
	if (fork_call > 0)
	{
		printf("Parent process (PID %d) created a child (PID %d).\n", getppid(), getpid());
		wait(NULL);
		printf("Parent process (PID %d) is returning child (PID %d)'s calculation. z = %d.\n", getppid(), getpid(), z);
		printf("Note: z = 0, because the child does not share/update it's parent.\n");
		
	// --------------------------------------------- Part 1.3 ---------------------------------------------------
	
		printf("\n");
		printf("The program will now procede to duplicate the previous process using a thread instead of forking.");
		printf("\n");

		// reinitalize parent program variables:
		x = 10;
		y = 20;
		z = 0;	
		
		// Calculation function.
		void *calculate(int x, int y, int z) {
			z = x + y; 
			printf("The thread has calculated z=x+y, and z = %d.\n", z);
			return NULL;
		}	
		
		// The parent process will create attempt to create a thread.
		pthread_t thread;

		if (pthread_create(&thread, NULL, calculate(x, y, z), NULL)) 
		{
			printf("An error occured while creating the thread.\n");
			exit(1);
		}
		
		printf("\n");	
		printf("Program FINISHED:\n");
		printf("-------------------------------------------------------------------------------------------------\n");	
	}
}