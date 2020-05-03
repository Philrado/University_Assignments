//=================================================================================
// File Name   : assignment3.c
// Author      : Philip Radojcic
// Description : A mutual exclusion algorithm allowing for only one client to access
//               critical sections of code at any given time.         
//               Specifically this will be applied to a bank account scenario.                          
// Latest Edit : 11/29/2019
//=================================================================================

// Include List:
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>

// This structure holds the necessary information of a bank account.
typedef struct bank_account 
{	
	// Total amount of bank accounts.
	int bank_accounts_count;
	// Can be either a personal or business bank account.
	char* account_type;
	// Stores the account number.
	int account_ID;
	int account_balance;
	int deposit_fee;
	int withdrawal_fee;
	int transfer_fee;
	// After a specified amount of transactions, there is an additional fee applied.
	int transaction_counter;
	int transaction_additional_fee;
	// If an account has overdraft protection, a specified fee will be charged for every $500 dollars
	// that an account borrows to complete a transaction, up until $5000.
	int overdraft_fee;
};

// An array to hold bank account data.
struct bank_account** bank_account_holder;

// This structure holds the necessary information of a transaction.
typedef struct depositor_transaction 
{
	
	// Total amount of depositors.
	int depositors_count;		
	// Amount of a specific depositors's interactions.
	int depositors_total;		
	// Store's the depositor number.
	int user_ID;
	// The account the transaction is depositing in.
	int account_ID [1000];
	// An array for the amount of interactions the depositor is doing, example 2 deposits.
	// In order to sort the interactions by number.
	int interaction_number [1000];
	// Store the interaction type.
	char interaction_type [1000];
	int balance_change [1000];
};

// An array to hold the transaction data.
struct depositor_transaction** depositor_transaction_holder;

// This structure holds the necessary information of a transaction.
typedef struct client_transaction 
{
	
	// Total amount of clients.
	int clients_count;
	// Amount of a specific client's interactions.
	int clients_total;	
	// Store's the client number.
	int user_ID;
	// The accounts the transaction is using.
	int first_account_ID [1000];
	int second_account_ID [1000];
	// An array for the amount of interactions the client is doing, example 2 deposits.
	// In order to sort the interactions by number.
	int interaction_number [1000];
	// Store the interaction type.
	char interaction_type [1000];
	int balance_change [1000];
};

// An array to hold the transaction data.
struct client_transaction** client_transaction_holder;

void depositor_deposit(struct bank_account_holder *accounts, struct depositor_transaction_holder *depositors) 
{
	
	// Deposit money into the selected bank account.
	// From 0 till the total amount of depositor interactions.	
	for (int i = 0; i < depositors -> depositors_count; i++)
	{	
		// From 0 till the total amount of a specific depositor's interactions.
		for (int a = 0; a < depositors -> user_ID = i -> depositors_total; a++)
		{	
			// For the current depositor ID in the depoistory holder array,
			// Get the depositor account to deposit in.
			// The receiving account = the account ID at the current user ID/current depositor.
			int receiving_account = depositors[i] -> account_ID[a];
			// Get the amount to deposit.
			int receiving_amount = depositors[i] -> balance_change[a];
			// Deposit the amount.
			accounts[receiving_account] -> account_balance += receiving_amount;
		}
	}
}

int overdraft_procedure(struct bank_account *account, int balance_after_withdrawing, int amount_withdrawing) 
{
	
	// Check if the account has overdaft protection.
	int overdraft_amount = account[overdraft_fee];
	if (overdraft_amount > 0)
	{	
		int return_amount;
		
		// If it does, check if the balance is less then zero.
		if (balance_after_withdrawing < 0)
		{
			// If it is, check if they would reach the $5000 dollar overdraft limit.
			if (balance_after_withdrawing < -5000)
			{
				return_amount = balance_after_withdrawing + 5000;
				return return_amount;
			}
			// If it is, and they wouldn't reach the limit, charge overdraft fee 
			else
			{
				// for every $500 the client is below 0 after attempting their transaction.
				int fee_multiplier = balance_after_withdrawing / 500;
				return_amount = balance_after_withdrawing + (overdraft_amount*fee_multiplier);
				
				// Check again if they reached the -5000.
				if (balance_after_withdrawing < -5000)
				{
					return_amount = balance_after_withdrawing + 5000;
					return return_amount;
				}
				return return_amount;
			}		
		}
	}
	// If not, deny the procedure and return the money.
	else
	{
		// If it does, check if the balance is less then zero.
		if (balance_after_withdrawing < 0)
		{
			// Return the money.
			account -> account_balance += amount_withdrawing;
			return -5001;
		}			
	}
	// If not, just end the procedure.
	return 0;
}

void client_transactions(struct bank_account_holder *accounts, struct client_transaction_holder *clients) 
{
	
	// From 0 till the total amount of client interactions.
	for (int i = 0; i < clients -> clients_count; i++)
	{	
		// From 0 till the total amount of a specific client's interactions.
		for (int a = 0; a < clients -> user_ID = a -> clients_total; a++)	
		{	
			// Obtain the type of transaction.
			char transaction_type = clients[i] -> interaction_type[a];
			
			// Deposit money into the selected bank account.
			if (transaction_type == 'd') 
			{	
				// Depositing Transaction:
				// For the current client ID in the depoistory holder array,
				// Get the client account to deposit in.
				// The receiving account = the account ID at the current user ID/current client.
				int receiving_account = clients[i] -> first_account_ID[a];
				// Get the amount to deposit.
				int receiving_amount = clients[i] -> balance_change[a];
				// Deposit the amount.
				accounts[receiving_account] -> account_balance += receiving_amount;
			}
			// Withdraw money from the selected bank account.
			else if (transaction_type == 'w') 
			{
				// For the current client ID in the depoistory holder array,
				// Get the client account to deposit in.
				// The receiving account = the account ID at the current user ID/current client.
				int account_withdrawing_from = clients[i] -> first_account_ID[a];
				// Get the amount to withdraw.
				int withdrawal_amount = clients[i] -> balance_change[a];
				// Overdraft check and repair.
				int check = overdraft_procedure(accounts[account_withdrawing_from], accounts[account_withdrawing_from] -> account_balance, withdrawal_amount)
				// If the account has an overdraft, but did not go over the limit.
				if ( check > -5000 && check <= 0)
				{	
					// Withdraw the amount.
					accounts[account_losing_money] -> account_balance -= transfer_amount;	
					// Apply overdraft to the account.
					accounts[account_losing_money] -> account_balance += check;
					
				}
				// If the account has an overdraft but did go over the limit.
				else if (check > 0)
				{
					// Withdraw the amount.
					accounts[account_losing_money] -> account_balance -= transfer_amount;	
					// Apply overdraft to the account.
					accounts[account_losing_money] -> account_balance == -5000;				
				}
			}
			// Take money from the selected bank account.	
			// Transfer the money into another account.
			else if (transaction_type == 't') 
			{
				// For the current client ID in the depoistory holder array,
				// Get the client accounts to transfer with.
				// The account losing money = the account ID at the current user ID/current client.
				int account_losing_money = clients[i] -> first_account_ID[a];
				// The account receiving money = the account ID at the current user ID/current client.
				int account_receiving_money = clients[i] -> second_account_ID[a];			
				// Get the amount to deposit.
				int transfer_amount = clients[i] -> balance_change[a];
				// Overdraft check and repair.
				int check = overdraft_procedure(accounts[account_withdrawing_from], accounts[account_withdrawing_from] -> account_balance, withdrawal_amount)
				// If the account has an overdraft, but did not go over the limit.
				if ( check > -5000 && check <= 0)
				{	
					// Withdraw the amount.
					accounts[account_losing_money] -> account_balance -= transfer_amount;	
					// Apply overdraft to the account.
					accounts[account_losing_money] -> account_balance += check;
					// Deposit the amount.				
					accounts[account_receiving_money] -> account_balance += transfer_amount;
					
				}
				// If the account has an overdraft but did go over the limit.
				else if (check > 0)
				{
					// Withdraw the amount.
					accounts[account_losing_money] -> account_balance -= transfer_amount;	
					// Apply overdraft to the account.
					accounts[account_losing_money] -> account_balance == -5000;
					// Deposit the amount.				
					accounts[account_receiving_money] -> account_balance += check;					
				}
			}			
		}
	}
}

int main(int argc, char *argv[] ) 
{

	// ----------------------------------- READING IN AND SORTING THE INPUT FILE -------------------------------------------

	// Makes sure the output file is clean before being used.
	FILE * file = fopen("assignment_3_output_file.txt", "w");
	fclose(file);
	
	// Opens the file to be read in.
	file = fopen("assignment_3_input_file.txt", "r");
	
	// Intializes internal variable to keep track of progress.
	int line = 0;	
	char *line = NULL;	
	ssize_t line_total = 0;
	size_t line_length = 0;	
	ssize_t read;

	// Count the total amount of lines in the input file, to find the maximum possible interactions for a general size.
	while (read = getline(&line, &line_length, file) != -1)
	{
		line++;
		if (line_total < line_length)
		{
			// Total amount of characters in a line.
			line_character_total = line_length;
		}
	}
    fclose(file);
	
	// Rewind the file.
	rewind(file);
	int line = 0;
	
	// Holds an array for all the bank accounts that will be interacted upon.
	bank_account_holder = (struct bank_account**) malloc(line_total * sizeof(struct bank_account*));
	struct bank_account** bank_account = bank_account_holder;
	// Holds an array for all the client transactions that will be undertaken.
	client_transaction_holder = (struct client_transaction**) malloc(line_total * sizeof(struct client_transaction*));
	struct client_transaction** client_transaction = client_transaction_holder;
	// Holds an array for all the depositor transactions that will be undertaken.
	depositor_transaction_holder = (struct depositor_transaction**) malloc(line_total * sizeof(struct depositor_transaction*));
	struct depositor_transaction** depositor_transaction = depositor_transaction_holder;

	// Read through the file and take and sort the data it holds.
	while (read = getline(&line, &line_length, file) != -1)
	{
		// Used to store the current values of an account or transaction.
		// And to reset them.
		char current_char;
		char* current_string;
		int current_number;
		char* current_account_type;
		char* next_transaction;
		int current_account_ID = 0;
		int current_account_balance = 0;
		int current_deposit_fee = 0;
		int current_withdrawal_fee = 0;
		int current_transfer_fee = 0;
		int current_transaction_counter = 0;
		int current_transaction_additional_fee = 0;
		char current_overdraft_check;		
		int current_overdraft_fee = 0;
		int current_user_ID = 0;
		int current_interaction_number = 0;
		char current_interaction_type;
		int current_balance_change;		
		int current_first_account_ID = 0;
		int current_second_account_ID = 0;	
		int all_added = 0;		
		
		fscanf(file, "%c", &current_char);
		// On the current line:
		// ----------------------------		
		// If the first character is 'a', then it is an account to be added:
		if (current_char == 'a')
		// Example = a1 type business d 0 w 5 t 10 transactions 20 2 overdraft Y 40
		{	
			// Go to the next character for the account number.
			// Add the account ID to array [x] where x is the account number.
			current_account_ID = fscanf(file, "%d", &current_number);
			bank_account_holder[current_account_ID] -> account_ID = current_account_ID;
			// Add to the amount of interactions.
			bank_account_holder -> bank_accounts_count = bank_accounts_count + 1;
			// Go forward characters till the next next space (skip type).
			fscanf(file, "%s", &current_string);
			// Add the account type.
			current_account_type = fscanf(file, "%s", &current_string);
			bank_account_holder[current_account_ID] -> account_type = current_account_type;
			// Go 4 characters ahead to the type of deposit fee.
			current_account_ID = fscanf(file, "%c", &current_char);
			// Add the deposit fee.
			current_deposit_fee = fscanf(file, "%d", &current_number);
			bank_account_holder[current_account_ID] -> deposit_fee = current_deposit_fee;
			// Go 4 characters ahead to the type of withdraw fee.
			current_account_ID = fscanf(file, "%c", &current_char);
			// Add the withdraw fee.
			current_withdrawal_fee = fscanf(file, "%d", &current_number);
			bank_account_holder[current_account_ID] -> withdrawal_fee = current_withdrawal_fee;
			// Go 4 characters ahead to the type of transfer fee.
			current_account_ID = fscanf(file, "%c", &current_char);	
			// Add the transfer fee.
			current_transfer_fee = fscanf(file, "%d", &current_number);
			bank_account_holder[current_account_ID] -> transfer_fee = current_transfer_fee;
			// Go 15 characters ahead to the transaction counter amount.
			fscanf(file, "%s", &current_string);
			// Add the transaction counter.
			current_transaction_counter = fscanf(file, "%d", &current_number);
			bank_account_holder[current_account_ID] -> transaction_counter  = current_transaction_counter;			
			// Go 2 characters ahead to the transaction fee.			
			// Add the transaction fee.
			current_transaction_additional_fee = fscanf(file, "%d", &current_number);
			bank_account_holder[current_account_ID] -> transaction_additional_fee  = current_transaction_additional_fee;			
			// Go 12 characters ahead to the overdraft check.
			fscanf(file, "%s", &current_string);			
			// If 'Y'
			current_overdraft_check = fscanf(file, "%c", &current_char);			
			if (current_overdraft_check == 'Y')
			{
				// Add the overdraft fee.
				current_overdraft_fee = fscanf(file, "%d", &current_number);
				bank_account_holder[current_account_ID] ->  overdraft_fee  =  current_overdraft_fee;					
			}
			// Else if 'N' go to the next line.
			line++;
		}
		// If the first character is 'c', then it is a client transaction to be added:
		else if (current_char == 'c')
		// Example = c1 d a1 100 w a2 500 t a1 a2 25			
		{	
			// Add to the amount of total clients.
			client_transaction_holder -> clients_count = clients_count + 1;		
			// Go to the next character for the client number.
			// Add the client ID to array [x] where x is the client number.
			current_user_ID  = fscanf(file, "%d", &current_number);
			client_transaction_holder[current_user_ID ] -> user_ID  = current_user_ID;
			// Add to the amount of this clients total interactions.
			client_transaction_holder -> clients_total = clients_total + 1;					
			// Count and store the number of transactions this client is taking.
			current_interaction_number++;
			client_transaction_holder[current_user_ID ] -> user_ID  = current_interaction_number;
			
			// After adding the specific client, then this will continue adding that clients interactions.
			while (int all_added != 1)
			{
				// Go forward characters till the next next space.
				// Add the transaction type. 
				current_interaction_type = fscanf(file, "%c", &current_char);
				client_transaction_holder[current_user_ID ] -> interaction_type = current_interaction_type;				
				// If the transaction type = 'w' or 'd'
				// go 3 characters forward to the account ID.
				// add the first account ID.
				current_first_account_ID = fscanf(file, "%d", &current_number);
				client_transaction_holder[current_user_ID ] -> first_account_ID  = current_first_account_ID;
				// Else If the transaction = 't'
				if (current_interaction_type == 't')
				{									
					// go 3 characters forward to the second account ID.
					// add the second account ID.
					current_second_account_ID = fscanf(file, "%d", &current_number);
					client_transaction_holder[current_user_ID ] -> second__account_ID  = current_second_account_ID;										
				}				
				// Go 2 characters forward to add the balance change amount.
				// Add the balance change.	
				current_balance_change = fscanf(file, "%d", &current_number);
				client_transaction_holder[current_user_ID ] -> balance_change  = current_balance_change;				
				// Go 2 characters forward.
				// If there is only NULL or a space
				next_transaction = fscanf(file, "%c", &current_char);	
				if (next_transaction != 'd' || next_transaction != 'w' || next_transaction != 't')
				{
					all_added = 1;
				}
				// Otherwise go to the next transaction that the current client desires to do.
			}
		}
		// If the first character is 'd', then it is a depositor transaction to be added:
		else
		// Example = dep1 d a1 1000 d a2 3000		
		{		
			// Add to the amount of total clients.
			depositor_transaction_holder -> depositors_count = depositors_count + 1;			
			// Go 3 characters ahead for the depositor number and skip "dep".
			fscanf(file, "%c", &current_char);
			fscanf(file, "%c", &current_char);
			fscanf(file, "%c", &current_char);
			// Add the depositor ID to array [x] where x is the client number.
			current_user_ID  = fscanf(file, "%d", &current_number);
			depositor_transaction_holder[current_user_ID ] -> user_ID  = current_user_ID;
			// Add to the amount of a specific depositors interactions.
			depositor_transaction_holder -> depositors_total = depositors_total + 1;	
			// Count and store the number of transactions this client is taking.
			current_interaction_number++;
			depositor_transaction_holder[current_user_ID ] -> user_ID  = current_interaction_number;

			// After adding the specific depositor, then this will continue adding that depositors interactions.			
			while (int all_added != 1)
			{
				// Go forward characters till the next next space.		
				// Add the transaction type (which will have to be d). 
				current_interaction_type = fscanf(file, "%c", &current_char);
				depositor_transaction_holder[current_user_ID ] -> interaction_type = current_interaction_type;					
				// go 3 characters forward to the account ID.
				// add the account ID.
				current_account_ID = fscanf(file, "%d", &current_number);
				depositor_transaction_holder[current_user_ID ] -> account_ID  = current_account_ID;				
				// Go 2 characters forward to add the balance change amount.
				// Add to the balance change.
				current_balance_change = fscanf(file, "%d", &current_number);
				depositor_transaction_holder[current_user_ID ] -> balance_change  = current_balance_change;					
				// Go 2 characters forward.
				// If there is only NULL or a space
				next_transaction = fscanf(file, "%c", &current_schar);	
				if (next_transaction != 'd')
				{
					all_added = 1;
				}
				// Otherwise go to the next transaction that the current client desires to do.
			}
		}
		// -----------------------------
		// If you reach the end of the line, go to the next interaction.
		line++;		
	}	
	
	// Open and output file contents. Then close the file.
	FILE * fp = fopen(output_file, "r");
	char current_char = '\0';
	while ((current_char = fgetc(fp)) != EOF)
	{
      		printf("%c", current_char);
	}
	fclose(fp);	
	
	// ------------------------------------------ ACCOUNT INTERACTIONS -------------------------------------------------

	// Do the Depositor Interactions first.
	// -------------------------------------
	depositor_deposit(bank_account_holder, depositor_transaction_holder);	
	
	// Then do the client interactions.
	// -------------------------------------
	client_transactions(bank_account_holder, client_transaction_holder);
	
}