//=======================================================================================
// File Name   : my_copy.cpp
// Author      : Philip Radojcic
// Description : Used to make a copy of a file from a source to the paramater destination.
// Latest Edit : 10/4/2019 
//========================================================================================

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

	// Correct argument and a copy file can be made
	if (argc == 3) {
		// Create a temporary instance of the file to be copied.
		string temp_instance = argv[1];
		manager file1 = manager(&temp_instance);
		// create a temporary copy going from output of one file to the input of the next.
		fstream temp_file;
		temp_file.open(argv[2], fstream::out|fstream::in);
		// Dump the file into another empty file container to create a copy.
		file.dump(&temp_file);
	}
	// Error Check.
	else {
		cout << "The argument was invalid and the file could not be copied over." << "\n";
	}
	
}	
