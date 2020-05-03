//=================================================================================
// File Name   : assignment2_part2.c
// Author      : Philip Radojcic
// Description : a C program that creates ordered queues by CPU burst time and
//				 arrival and then executes them accordingly with output shown in an
//				 output file. 
// Latest Edit : 10/30/2019
//=================================================================================

// Include List:
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

// A variable to store the name of the output file.
char * output_file = "cpu_scheduling_output_file.txt";

// This structure holds the necessary information of a process.
typedef struct process {
	int process_ID;
	int cpu_burst_time;
};

// This structure holds the necessary information of a queue of processes.
typedef struct queue {
	int process_ID;
	int time_quantum;
	int longest_process;
	int active_process_count;
	// Used to hold an array of arguments in the queue.
	struct process *arr;
};

// This is a double pointer to an array of all queue structers, held in the queue holder.
struct queue** queue_holder;

// This structure holds the necessary information of the Queue -of type- Round Robin.
typedef struct Round_Robin {
	// A variable used in checks for whether the correct values in context are initialized.
	int intialization_check;
	int process_ID;
	int cpu_burst_time_remaining;
	// The instant the process finishes begin's execution.	
	int start;
	// The instant the process finishes it's execution.
	int end;
	// Completed is a signal for when the process is fully over.
	int completed;
};

/**
	First Come First Serve (FCFS) scheduling works by taking in a queue and performing a ready queue.
*/
void FCFS(struct queue *temporary_queue_param) {
	
	// Open the file, with permission to add onto, but not overwrite any progress.
	FILE * fp = fopen(output_file, "a+");
	// A temporary process variable will be used to keep track of the execution order.
	struct process * temporary_process = malloc(sizeof(struct process *) * temporary_queue_param -> active_process_count);
	
	// Output statements for the type of scheduling, CPU selection, and processes executed in order.
	printf("-------------------------------------------------------------------------\n");			
	fprintf(fp, "Ready Queue #%d Applying FCFS Scheduling: \n\n", temporary_queue_param -> process_ID);
	fprintf(fp, "Order of selection by CPU: \n", temporary_queue_param -> process_ID);
	for ( int current_queue_1 = 0; current_queue_1 < temporary_queue_param -> active_process_count; current_queue_1++)
	{
		temporary_process[current_queue_1] = temporary_queue_param -> arr[current_queue_1];
		if (current_queue_1 != temporary_queue_param -> active_process_count - 1)
		{
			fprintf(fp, "p%d ", current_queue_1 + 1);
		}
		else
		{
			fprintf(fp, "p%d \n", current_queue_1 + 1);
		}
	}

	// This loop iterates through each item in the queue, printing the wait time, increments, total time, and finally the average.
	fprintf(fp, "\nIndividual waiting times for each process: \n");
	int time_waiting = 0;
	int total_wait_time = 0;
	for (int current_queue_2 = 0; current_queue_2 < temporary_queue_param -> active_process_count; current_queue_2++){
		fprintf(fp, "p%d = %d\n", temporary_process[current_queue_2].process_ID, time_waiting);
		time_waiting += temporary_process[current_queue_2].cpu_burst_time;
		total_wait_time += time_waiting;
	}
	// Calculations for the average, with output.
	float computed_waiting_average = (float) total_wait_time / (float) temporary_queue_param -> active_process_count;
	fprintf(fp, "\nAverage waiting time = %.2f \n\n", computed_waiting_average);
	fclose(fp);
}

/**
	Shortest Job First (SJF) scheduling works by storing processes in order of shortest calculated execution length.
*/
void SJF(struct queue *temporary_queue_param){
	
	// Open the file, with permission to add onto, but not overwrite any progress.
	FILE * fp = fopen(output_file, "a+");
	struct process * temporary_process = malloc(sizeof(struct process) * temporary_queue_param -> active_process_count);
	int process_checker_array[temporary_queue_param -> active_process_count];
	// Output statements for the type of scheduling, CPU selection, and processes executed in order.
	printf("-------------------------------------------------------------------------\n");		
	fprintf(fp, "Ready Queue #%d Applying SJF Scheduling: \n\n", temporary_queue_param -> process_ID);
	fprintf(fp, "Order of selection by CPU: \n", temporary_queue_param -> process_ID);
	// Internal variable to keep track of progress.
	int current_process = 1;
	int current_value = 0;
	int current_position = 0;
	int potential_position = 0;

	// Functions to order the items in the queue properly.
	while (potential_position != temporary_queue_param -> active_process_count)
	{
		// Reset the track variables used in the loop.
		current_value = 0;
		char start_signal = 's';
		int current_queue_2 = 0;
		// Functions to check which items in the queue have not been added, 
		// and if the item viewed is smaller then the current one.
		for (; current_queue_2 < temporary_queue_param -> active_process_count; current_queue_2++)
		{
			// Was the value already added? If so continue.
			if (process_checker_array[current_queue_2] == 1)
			{
				continue;
			}
			// Change the initial burst time to the smallest value.
			if (start_signal == 's') 
			{
				current_value = temporary_queue_param -> arr[current_queue_2].cpu_burst_time;
				current_position = current_queue_2;
				start_signal = 'f';
				continue;
			}
			// Use the smallest value if applicable.
			if (temporary_queue_param -> arr[current_queue_2].cpu_burst_time < current_value)
			{
				current_position = current_queue_2;
				current_value = temporary_queue_param -> arr[current_queue_2].cpu_burst_time;
			}
		}
		// Values added in order of their increasing burst time, and then check off the process as added.
		temporary_process[potential_position].process_ID = temporary_queue_param -> arr[current_position].process_ID;
		temporary_process[potential_position].cpu_burst_time = temporary_queue_param -> arr[current_position].cpu_burst_time;
		process_checker_array[current_position] = 1;
		potential_position++;
	}

	// This loop iterates through each item in the queue, printing the wait time, increments, total time, and finally the average.
	fprintf(fp, "\nIndividual waiting times for each process: \n");
	int time_waiting = 0;
	int total_wait_time = 0;
	for (int current_queue_2 = 0; current_queue_2 < temporary_queue_param -> active_process_count; current_queue_2++)
	{
		fprintf(fp, "p%d = %d\n", temporary_process[current_queue_2].process_ID, time_waiting);
		time_waiting += temporary_process[current_queue_2].cpu_burst_time;
		total_wait_time += time_waiting;
	}
	// Calculations for the average, with output.
	float computed_waiting_average = (float) total_wait_time / (float) temporary_queue_param->active_process_count;
	fprintf(fp, "\nAverage waiting time = %.2f \n\n", computed_waiting_average);
	fclose(fp);
}

/**
	Round Robin (RR) scheduling functions by using a set alloted time given to each process, and 
	the processes are then cycled through till completed.
*/
void RR(struct queue *temporary_queue_param){

	// Open the file, with permission to add onto, but not overwrite any progress.	
	FILE * fp = fopen(output_file, "a+");
	int current_process = 0;
	// Queue 1 is for completed processes in order, Queue 2 is for processes, being processed currently.
	struct Round_Robin* Round_Robin_Queue_1 = malloc(sizeof(struct Round_Robin) * temporary_queue_param -> active_process_count);
	struct Round_Robin* Round_Robin_Queue_2 = malloc(sizeof(struct Round_Robin) * temporary_queue_param -> active_process_count);
	struct process * temporary_process = malloc(sizeof(struct process) * temporary_queue_param -> active_process_count * temporary_queue_param -> longest_process);
	// Output statements for the type of scheduling, CPU selection, and processes executed in order.
	printf("-------------------------------------------------------------------------\n");		
	fprintf(fp, "Ready Queue 1 Applying RR Scheduling: \n\n", temporary_queue_param -> process_ID);
	fprintf(fp, "Order of selection by CPU: \n", temporary_queue_param -> process_ID);
	// Internal variable to keep track of progress.
	int completed_process_count = 0;
	int time_of_execution = 0;
	int current_position = 0;
	int update = 0;
	int time_available = 0;

	// Simulates Round Robin scheduling:
	while (completed_process_count != temporary_queue_param -> active_process_count)
	{
		// Iterates through each value till all values are processed.
		for (int current_queue_1 = 0; current_queue_1 < temporary_queue_param -> active_process_count; current_queue_1++)
		{
			// Make sure the process doesn't execute again if complete.
			if (Round_Robin_Queue_2[current_queue_1].completed == 1)
			{
				continue;
			}
			// Error check for if the process is not initialized.
			if (Round_Robin_Queue_2[current_queue_1].intialization_check != 1 )
			{
				Round_Robin_Queue_2[current_queue_1].process_ID = current_queue_1 + 1;
				Round_Robin_Queue_2[current_queue_1].intialization_check = 1;
				Round_Robin_Queue_2[current_queue_1].end = 0;
				Round_Robin_Queue_2[current_queue_1].completed = 0;
				Round_Robin_Queue_2[current_queue_1].cpu_burst_time_remaining = temporary_queue_param -> arr[current_queue_1].cpu_burst_time;
				Round_Robin_Queue_2[current_queue_1].start = time_of_execution;
			}
			// Execution and storage of processes, adding them to one queue and then dumping contents in the second queue.
			if (Round_Robin_Queue_2[current_queue_1].cpu_burst_time_remaining <= temporary_queue_param->time_quantum)
			{
				Round_Robin_Queue_2[current_queue_1].end = Round_Robin_Queue_2[current_queue_1].cpu_burst_time_remaining + time_of_execution;
				temporary_process[current_position].process_ID = temporary_queue_param -> arr[current_queue_1].process_ID;
				temporary_process[current_position].cpu_burst_time = temporary_queue_param -> arr[current_queue_1].cpu_burst_time;
				Round_Robin_Queue_1[completed_process_count].end = Round_Robin_Queue_2[current_queue_1].end;
				Round_Robin_Queue_1[completed_process_count].cpu_burst_time_remaining = 0;
				Round_Robin_Queue_1[completed_process_count].intialization_check = Round_Robin_Queue_2[current_queue_1].intialization_check;
				Round_Robin_Queue_1[completed_process_count].process_ID = Round_Robin_Queue_2[current_queue_1].process_ID;
				Round_Robin_Queue_1[completed_process_count].start = Round_Robin_Queue_2[current_queue_1].start;
				current_position++;
				completed_process_count++;
				time_available = Round_Robin_Queue_2[current_queue_1].cpu_burst_time_remaining;
				// Only add these processes as completed if there is still available time, therefore they finished early.
				if (time_available >= 0)
				{
					Round_Robin_Queue_2[current_queue_1].completed = 1;
					Round_Robin_Queue_1[completed_process_count].completed = 1;
				}
			}
			// However once the alloted time is complete, if a process is not finished it is relocated back into the queue. 
			// Then time of execution is updated to be kept track of.
			else if (Round_Robin_Queue_2[current_queue_1].cpu_burst_time_remaining > temporary_queue_param -> time_quantum)
			{
				Round_Robin_Queue_2[current_queue_1].cpu_burst_time_remaining -= temporary_queue_param -> time_quantum;
				temporary_process[current_position] = temporary_queue_param -> arr[current_queue_1];
				current_position++;
				time_available = temporary_queue_param -> time_quantum;
			}
			time_of_execution += time_available;
		}
	}

	// Output statements for processes executed in order.	
	for (int current_queue_1 = 0; current_queue_1 < current_position; current_queue_1++)
	{
		if (current_queue_1 != current_position - 1)
		{
			fprintf(fp, "p%d ", temporary_process[current_queue_1].process_ID);
		}
		else
		{
			fprintf(fp, "p%d \n", temporary_process[current_queue_1].process_ID);
		}
	}

	// Output statements for turnaround time.
	fprintf(fp, "\nThe turnaround time for each process is: \n");
	int total_wait_time = 0;
	for (int current_queue_2 = 0; current_queue_2 < completed_process_count; current_queue_2++)
	{
		fprintf(fp, "p%d = %d\n", Round_Robin_Queue_1[current_queue_2].process_ID, Round_Robin_Queue_1[current_queue_2].end-Round_Robin_Queue_1[current_queue_2].start);
	}
	fprintf(fp, "\n");
	fclose(fp);
}

/**
	The main function of the program:
	Opens the files necessary, creates process, queue and array strcutures to be stored in a queue holder array.
	Simulates CPU scheduling algorithms FCFS, SJF and RR, and outputs them.
*/
int main(int argc, char* argv){
	
	printf("\n");	
	printf("Program STARTING:\n");
	printf("-------------------------------------------------------------------------------------------------\n");	
	
	// Makes sure the output file is clean before being used.
	FILE * file = fopen("cpu_scheduling_output_file.txt", "w");
	fclose(file);
	
	// Opens the file to be read in.
	file = fopen("cpu_scheduling_input_file.txt", "r");
	// Intializes internal variable to keep track of progress.
	int line_total = 0;	
	char *line = NULL;	
	ssize_t line_character_total = 0;
	size_t line_length = 0;	
	ssize_t read;

	// Count the total amount of lines in the input file, reperesentative of queues.
	while (read = getline(&line, &line_length, file) != -1)
	{
		line_total++;
		if (line_character_total < line_length)
		{
			// Total amount of characters in a line.
			line_character_total = line_length;
		}
	}
	
	// Where all the queues will be stored and a pointer to it.
	queue_holder = (struct queue**) malloc(line_total * sizeof(struct queue*));
	struct queue** current_queue = queue_holder;

	// Allocates space for the process array, and stores the array pointer appropriately.
	for (int current_char = 0; current_char < line_total; current_char++)
	{
		struct process* temporary_process_array = (struct process*) malloc(line_character_total*sizeof(struct process));
		struct queue* temporary_queue = malloc(sizeof(struct queue));
		temporary_queue -> process_ID = current_char + 1;
		temporary_queue -> arr = temporary_process_array;
		*current_queue = temporary_queue;
		current_queue++;
	}

	// Rewind the file, and store all the temprarily read values from the file.
	char* temporary_number = malloc (read  *sizeof(char));
	rewind(file);
	char* temporary_string = malloc(sizeof(char)*3);
	char temporary_char;
	int temporary_digit;
	struct queue* queue_1 = *queue_holder;
	struct queue* queue_2 = *queue_holder;
	int track = 0;
	int first = 0;
	int current_line = 0;

	// Reads the file and stores information into the queue holder.
	while (current_line != line_total) 
	{
		fscanf(file,"%c", &temporary_char);
		if ( track == 0 && temporary_char == 'q') 
		{
			track = 1;
		}
		
		// Compare strings to allow for reading time quantum.
		fscanf(file,"%d", &temporary_digit); 
		fscanf(file,"%s", temporary_string);
		int compare = strcmp(temporary_string,"tq");

		if (track == 1 && !compare) 
		{
			if (fscanf(file, "%d", &temporary_digit) == 1)
			{
				queue_holder[current_line] -> time_quantum = temporary_digit;
			}
			track =2;
		}

		// Store the processes and pull them out when read at end of line.
		if (track == 2)
		{
			while (fscanf(file, "%c", &temporary_char) == 1 && temporary_char != '\n')
			{
				if (fscanf(file, "%c", &temporary_char) == 1 && temporary_char == 'p')
				{
					fscanf(file, "%d", &temporary_digit);
					struct process *current_process = malloc(sizeof(struct process));
					current_process -> process_ID = temporary_digit;
					int temporary_ID = temporary_digit;
					queue_holder[current_line] -> active_process_count = temporary_ID;
					fscanf(file, "%d", &temporary_digit);
					current_process -> cpu_burst_time = temporary_digit;
					if (first || queue_holder[current_line] -> longest_process < temporary_digit)
					{
						first = 0;
						queue_holder[current_line]->longest_process = temporary_digit;
					}
					queue_holder[current_line] -> arr[temporary_ID - 1].process_ID = current_process -> process_ID;
                    queue_holder[current_line] -> arr[temporary_ID - 1].cpu_burst_time = current_process -> cpu_burst_time;
				}
			}
			// Reset variables and update.
			first = 1;
			track = 0;
			current_line++;
		}
	}
    fclose(file);

	// Then applies each algorithm to each of the queues, and stores them appropriately.
	int current_queue_1 = 0;
	for (; current_queue_1 < line_total; current_queue_1++)
	{
		FCFS(queue_holder[current_queue_1]);
		SJF(queue_holder[current_queue_1]);
		RR(queue_holder[current_queue_1]);
	}

	// Open and output file contents. Then close the file.
	FILE * fp = fopen(output_file, "r");
	char current_char = '\0';
	while ((current_char = fgetc(fp)) != EOF)
	{
      		printf("%c", current_char);
	}
	fclose(fp);
		
	printf("Program FINISHED:\n");
	printf("-------------------------------------------------------------------------------------------------\n");	
}
