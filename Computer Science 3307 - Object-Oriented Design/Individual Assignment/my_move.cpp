//=================================================================================
// File Name   : my_move.cpp
// Author      : Philip Radojcic
// Description : This is used to move and rename files around.
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

void main (int argc, char *argv[]) {
	
	// Correct argument and both files exist and can be compared.
	if (argc == 3) {
		// Create a temporary instance of both files.
		string temp_instance = argv[1];
		manager file1 = manager(&temp_instance);
		string temp2_instance = argv[2];
		manager file2 = manager(&temp2_instance);
		// rename the file accordingly to the paramater.
		file1.rename_file(&file2);
	}
	// Error Check.
	else {
		cout << "The argument was invalid, the file could not be renamed." << "\n";
    }

    
}	
