//========================================================================================
// File Name   : my_diff.cpp
// Author      : Philip Radojcic
// Description : Compares 2 paramater files and reports if they are the same or different.
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
	
	// Correct argument and both files exist and can be compared.
	if (argc == 3) {
		// Create a temporary instance of both files.
		string temp_instance = argv[1];
		manager file1 = manager(&temp_instance);
		string temp2_instance = argv[2];
		manager file2 = manager(&temp2_instance);
		ifstream temp_string;
		// Compare both files.
		file1.compare(&file2);
	}
	// Error Check.
	else {
		cout << "The argument was invalid and the differences could not be checked." << "\n";
    }
    
}	
