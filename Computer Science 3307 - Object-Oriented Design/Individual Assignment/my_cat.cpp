//==========================================================================================
// File Name   : my_cat.cpp
// Author      : Philip Radojcic
// Description : Displays the contents of the files given as parameters to the command line.
// Latest Edit : 10/4/2019 
//===========================================================================================

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

int main(int argc, char *argv[]) {
	
	// Correct argument and file can begin being copied.
	if (argc == 3) {
		// Create a temporary instance using the param in order to leave the main file uneditted.
		string temp_instance = argv[1];
		manager file = manager(temp_instance);
		ifstream temp_string;
		temp_string.open(argv[2],ofstream::out);
		// Copies over the temp instance files.
		file.dump(&temp_string);
	}
	// Error Check.
	else {
		cout << "The argument was invalid and the file was unable to be copied properly." << "\n";
    }
 
}
