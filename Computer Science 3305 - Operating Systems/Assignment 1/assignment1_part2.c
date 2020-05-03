//=================================================================================
// File Name   : assignment1_part2.c
// Author      : Philip Radojcic
// Description : Accepts 2 integers from command line prompts.
//				 The program creates a parent and child process, where the parent
//				 reads int 1, and the child reads int 2. The child sense #2 to the
//				 parent through a pipe, and the parent will add 1# to #2 and output
//				 the sum.
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

int main(int argc, char *argv[] ) {

	// Creates a fork of the main process, therefore creating a child for the parent process.
	pid_t fork_call;
	fork_call = fork();
	
	// If fork() fails and the child is not created.
	if (fork_call < 0)
	{
		printf ("The fork() process was unsuccessful and no child was created.");
		exit(1);
	}
	
	// Creates an int array for the pipe() call to store both integer inputs.
	int pipeline[2];
	// creating a pipe
	pipe(pipeline);
	
	// The current process running is the child.
	if (fork_call == 0) 
	{			
		// Allocates memory in a variable to store a string of the 2nd argument
        char* pipe_input = (char *) malloc(strlen(argv[2])+1);
        pipe_input = strcpy(pipe_input, argv[2]);
		printf("child (PID %d) is reading Y = %d from the user.\n", getpid(), pipe_input);
		
		// Writes the integer Y obtained from the user into the pipe for the parent to read.
		write(pipeline[1], pipe_input, strlen(pipe_input)+1);
		printf("child (PID %d) is writing Y into the pipe.\n", getpid());
		
		// Free the memory allocated for the pipe input after it is sent into the pipe.
		free(pipe_input);
	}
	
	// The current process running is the parent.
	if (fork_call > 0)
	{
		printf("A pipe is created for communication between parent (PID %d) and child.\n", getppid());
		printf("Parent process (PID %d) created a child (PID %d).\n", getppid(), getpid());			
					
		// Converts the string read from the command prompt into an integer.
		int X = atoi(argv[1]);
		printf("parent (PID %d) is reading X = %d from the user.\n", getppid(), X);
		
		// Creates an array to store the string integer obtained from the pipe.
		char pipe_input[strlen(argv[2])]; 

		// Waits for the child process to finish executing before continuing.
		wait(NULL);	
		
		// Reads converts the string read from the pipe into an integer.
		read(pipeline[1], pipe_input, strlen(argv[2]));
		// Store a termination character as the last digit of the array.
		pipe_input[strlen(argv[2])] = '\0';
		printf("parent (PID %d) is reading Y from the pipe (Y = %d).\n", getpid(), pipe_input);
		
		// Converts the string read from the pipe into an integer.
		int Y = atoi(pipe_input);
		// Calculate and output the sum obtained.
		int sum = X + Y;
		printf("parent (PID %d) is adding X + Y = %d.\n", getpid(), sum);
	}
}