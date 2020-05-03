//=================================================================================
// File Name   : my_remove.cpp
// Author      : Philip Radojcic
// Description : This removes the given files listed as paramaters to this command.
// Latest Edit : 10/4/2019 
//=================================================================================

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

int main (int argc, char *argv[]) {

	// Create a temporary instance of the file to be copied.
	string temp_instance = argv[1];
	manager file = manager(&temp_instance);
	int file_to_remove = file.remove();
	// If there was a file successfuly removed.
	if (file_to_remove == 0) {
		cout << "The file was successfully removed" << "\n";
	}
	// Error Check.
	else {
		cout << "An error occured when attempting to remove the file." << "\n";
		cout << "Only regular files can be removed successfully." << "\n";
	}
	
}	
