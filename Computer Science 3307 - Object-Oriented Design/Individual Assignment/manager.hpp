//==============================================================================
// File Name   : manager.hpp
// Author      : Philip Radojcic
// Description : A class that defines the functions of the manager_class.cpp
// Latest Edit : 10/4/2019 
//==============================================================================

#ifndef 
#define 

#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

class manager {
	
	// All the class variables to be used:
	string file_name;
	mode_t type;
	off_t size;
	uid_t owner_ID;
	string owner_username;
	gid_t group_ID;
	string group_name;
	string permissions;
	struct timespec access_time;
	struct timespec modification_time;
	struct timespec status_change_time;
	blksize_t block_size;
	vector children;
	int error_number;
	string error_string;

	//---------------------------------------------Base Functions----------------------------------------------------

	// Takes the file name and creates an instance of the class and initializes it.
	// Also initializes the error number, using the stat() function.
	void manager (string file_name);

	// Destroys and frees up rescources attached to the object the destructor was called on.
	void destroy_manager();
	~manager();

	// Takes a file stream as a paramater and dumps the contents of the named file into that file stream.
	// Should return and store an error code if the operation could not complete.
	int dump (fstream &stream_copy);

	// Changes the name of the file from it's existing name ot the new name provided as a param.
	// Should return and store an error code if the operation could not complete.
	int rename (string new_name);

	// Removes the file specified.
	// Should return and store an error code if the operation could not complete.
	string remove (string file_name);

	// Takes one of the file objects as a param and compares the contents to another file object.
	// Returns true if the files were the same.
	int compare (fstream &comparison_file);

	// Used to fill in the children of the file object this function was invoked upon by creating a new
	//   file object for each file in the directory.
	// Should return and store an error code if the operation could not complete.
	string expand();

	//---------------------------------------------Attribute Getters-------------------------------------------------

	// Gets the name of the file.
	string get_name();

	// Gets the type of the file (regular, directory and such).
	// I will be returning it as a string representation.
	mode_t get_type();

	// Gets the size of the file.
	off_t  get_size();

	// Gets the owner of the file.
	uid_t get_owner_ID();

	// Gets the owner of the file's user ID.
	string get_owner_username();

	// Gets the group of the file.
	gid_t get_group_ID();

	// Gets the group name of the file.
	string get_group_name();

	// Gets the read, write and execute permissions on the file.
	string get_permissions();

	// Gets the time the file was last accessed.
	struct timespec get_access_time();

	// Gets the time the file was last modified.
	struct timespec get_modification_time(); 

	// Gets the time the file had it's latest status change.
	struct timespec get_status_change_time();

	// Gets the block size of the file.
	blksize_t get_block_size();

	// If the file is a directory, this function gets the file objects within, and stores
	//   them using a vector object.
	vector get_children();

	// Gets the error number variable in the program if something goes wrong.
	// Initialized at 0 and set to 0 each time an operation succedes.
	int get_error_number();

	// Gets the error number as a string if something goes wrong.
	string get_error_string();

	// Gets all the print information cleanly like in my_stats.
	void manager:: get_print_info();

}

#endif
