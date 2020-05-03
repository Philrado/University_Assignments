//==============================================================================
// File Name   : manager.cpp
// Author      : Philip Radojcic
// Description : A class to help manage files on the Raspberry Pi Desktop system
// Latest Edit : 10/4/2019 
//==============================================================================

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <string>
#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "manager.hpp"

using namespace std;

	// Constructor function that takes the file name and creates an instance of the class and 
	// initializes it. Also initializes the error number, using the stat() function.
	manager:: manager (string *file_name) {
		// Create a temporary stat holder to obtain the relevant data from, and copy the file.
		struct stat value_placeholder;
		string file_name_copy = file_name -> c_str();
		stat(file_name_copy, &value_placeholder);
		// Shifts 9 digits left, to get the 10th digit, the type.
		this -> type = value_placeholder.st_mode >> (9);
		this -> size = value_placeholder.st_size;
		this -> owner_ID = value_placeholder.st_uid;
		this -> owner_username = getpwuid(this -> owner_ID) -> pw_name; 
		this -> group_ID = value_placeholder.st_gid;
		this -> group_name = getgrgid(this -> roup_ID) -> gr_name; 
		// Obtains the first 9 digits.
		this -> permissions = value_placeholder.st_mode & (1023);
		this -> access_time = value_placeholder.st_atim;
		this -> modification_time = value_placeholder.st_mtim;
		this -> status_change_time = value_placeholder.st_ctim;
		this -> block_size = value_placeholder.st_blksize;
		// Just set to exist but not given children.
		this -> children;
		// Always starts at 0.
		this -> error_number = 0;
	}

	// Deconstructor function destroys and frees up rescources attached to the object 
	// the destructor was called on.
	manager:: destroy_manager () {
		manager::~manager() = default;
	}

	// Takes a file stream as a paramater and dumps the contents of the named file into that file stream.
	// Should return and store an error code if the operation could not complete.
	int manager:: dump (fstream &stream_copy) {
		// Attempt to open, and obtain file data.
		try {
			// Open the new file with read and write capabilities.
			ifstream file.open(file_name);
			// Get the type to check.
			mode_t file_type = this -> get_type();
			// Check to see if the file type is regular.
			if (file_type == 0) {
				// Obtains the block size to read the file in by.
				off_t file_block_size = this -> get_size();
				// Creates a character array.
				char *temp = new char[file_block_size];
				// From the beginning of the file to the end:
				while (!file.eof()) {
					// Read into the file block by block.
					file.read(temp, file_block_size);
					stream_copy.write(temp, file.gcount());
				}
				*stream_copy.write("\n");
				file.close();
			}
			// If the file type is not regular, give this specific error.
			else {
				this -> error_number = ENOTSUP;
				return this -> error_number;	
			}
		} 
		// If there is no file to open, then give a generic error.
		catch (const std:: runtime_error& e) {
			this -> error_number = e;
			return this -> error_number;	
		}
	}

	// Changes the name of the file from it's existing name ot the new name provided as a param.
	// Should return and store an error code if the operation could not complete.
	string manager:: rename_file (string new_name) {
		// Attempt to rename.
		try {
			rename(this -> file_name, new_name);
		// If there is nothing to rename or this fails.
		catch (const std:: runtime_error& e) {
			this -> error_number = e;
			return this -> error_number;	
		}
	}

	// Removes the file specified.
	// Should return and store an error code if the operation could not complete.
	int manager:: remove (string file_name) {
		// Attempt to remove.
		try {
			unlink(file_name);
			destroy_manager();
		// If there is nothing to remove or this fails.
		catch (const std:: runtime_error& e) {
			this -> error_number = e;
			return this -> error_number;	
		}
	}
	
	// Takes one of the file objects as a param and compares the contents to another file object.
	// Returns 0 if the files are the same, returns 1 if the files are different, and error otherwise.
	int manager:: compare (manager manager_object) {
		// Attempt to open, and obtain file data.
		try {
			// Open the new file with read and write capabilities.
			ifstream file.open(file_name);
			ifstream comp_file.open(manager_object.get_name());
			// Get the type to check.
			mode_t file_type = this -> get_type(); {
			// Obtains the block size to read the file in by.
			off_t file_block_size = this -> get_size();
			// Creates a character array.
			char *temp = new char[file_block_size];
				// Creates a character array.
			char *temp2 = new char[file_block_size];
			// From the beginning of the file to the end:
			while (!file.eof()) {
				// Read into the file block by block.
				file.read(temp, file_block_size);
				comp_file.read(temp2, file_block_size);
				int check = strncmp(temp1, temp2, file.gcount());
				if (check != 0) {
					return 1;
				}
			}
			// Close both files.
			file.close;
			comp_file.close();
			return 0;
		// If there is no file to open, then give a generic error.
		catch (const std:: runtime_error& e) {
			this -> error_number = e;
			return this -> error_number;	
		}
	}

	// Used to fill in the children of the file object this function was invoked upon by creating a new
	//   file object for each file in the directory.
	// Should return and store an error code if the operation could not complete.
	// Returns 0 if successful, returns 1 if the directory is empty, and error otherwise.
	string manager:: expand () {
		mode_t file_type = this -> get_type();
		// The file type is not regular,theremore must be a directory.
		if (this -> file_type == 1){
			// Create a pointer to the current directory for searching purposes.
			struct dirent * available_directory;
			DIR *directory_pointer = opendir(this -> file_name_copy);
			// If the pointer fails to find a directory, there is no directory and it returns
			if (directory_pointer == NULL) {
				return 1;
			}
			// Read through the avaialable directories while there are still directories to go through.
			while ((available_directory = readdir(directory_pointer)) != NULL) {
				this -> children.push_back(available_directory -> d_name);
			}
			// Close the directory as located by the pointer.
			closedir(directory_pointer);
			// Return 0 to show it was successful.
			return 0;
		}
		// If the file type is not a directory, give this specific error.	
		else {	
            this -> error_number = ENOTSUP;
            return error_number;
		}
	}

	//---------------------------------------------Attribute Getters-------------------------------------------------

	// Gets the name of the file.
	string manager:: get_name() {
		return this -> file_name();
	}

	// Gets the type of the file (regular, directory and such).
	// I will be returning it as a string representation.
	mode_t manager:: get_type() {
		return this -> type();
	}

	// Gets the size of the file.
	off_t manager:: get_size() {
		return this -> size();
	}

	// Gets the owner of the file.
	uid_t manager:: get_owner_ID() {
		return this -> owner_ID();
	}
	
	// Gets the owner of the file's user ID.
	string manager:: get_owner_username() {
		return this -> owner_username();
	}

	// Gets the group of the file.
	gid_t manager:: get_group_ID() {
		return this -> group_ID();
	}
	
	// Gets the group name of the file.
	string manager:: get_group_name() {
		return this -> group_name();
	}

	// Gets the read, write and execute permissions on the file.
	string manager:: get_permissions() {
		return this -> permissions();
	}

	// Gets the time the file was last accessed.
	struct timespec manager:: get_access_time() {
		return this -> access_time();
	}

	// Gets the time the file was last modified.
	struct timespec manager:: get_modification_time() {
		return this -> modification_time();
	}

	// Gets the time the file had it's latest status change.
	struct timespec manager:: get_status_change_time() {
		return this -> status_change_time();
	}

	// Gets the block size of the file.
	blksize_t manager:: get_block_size() {
		return this -> block_size();
	}

	// If the file is a directory, this function gets the file objects within, and stores
	//   them using a vector object.
	vector manager:: get_children() {
		return this -> children();
	}

	// Gets the error number variable in the program if something goes wrong.
	// Initialized at 0 and set to 0 each time an operation succedes.
	int manager:: get_error_number() {
		return this -> error_number();
	}
	
	// Gets the error number as a string if something goes wrong.
	string manager:: get_error_string() {
		return this -> strerror();
	}
	
	// Gets all the print information cleanly like in my_stats.
	void manager:: get_print_info() {
		cout << "File Name: " << name << "\n";
		cout << "File Type: " << type << "\n";
		cout << "File Size: " << size << "\n";
		cout << "File Owner: " << owner << "\n";
		cout << "File Group: " << group << "\n";
		cout << "File Permissions: " << permissions << "\n";
		cout << "File Access Time: " << access_time << "\n";
		cout << "File Modification Time : " << modification_time << "\n";
		cout << "File Status_change Time: " << status_change_time << "\n";
		cout << "File Block Size: " << block_size << "\n";
		cout << "File Children: " << children << "\n";
	}
