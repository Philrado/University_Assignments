//=================================================================================
// File Name   : my_list.cpp
// Author      : Philip Radojcic
// Description : Lists the contents of the directory just as ls would normally do.
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
	
	// initialize the file,and temp placeholder for the name information.
	manager *file = new manager (&temp);
	string name_placeholder = argv[1];
    vector<string> directory_children = file -> get_children();
	// Argument 1 path:
	if (argc == 1) {
        name_placeholder = ".";
		if (name_placeholder.size() != 0) {
			for (string initial : directory_children ) {
				manager * temp_file = new manager (&initial);
				cout << temp_file -> get_print_info()  << "\n";
			}
			return 0;
		}
		// Error Check.
		else {
			cout << "This operation can only be used on non directory files." << "\n";
		}
	}
	// Argument 2 path:
	else if (argc == 2) {
		// Implementing an -l option for this command:
		if (name_placeholder == "-l" ) {
            name_placeholder = ".";
			if (name_placeholder.size() != 0) {
				for (string initial : directory_children ) {
					manager * temp_file = new manager (&initial);
					cout << temp_file -> get_print_info()  << "\n";
				}
			}
		// Error Check.
		else {
			cout << "This operation can only be used on non directory files." << "\n";
		}
	// Error Check.
	else {
		cout << "The argument was invalid and the directory contents could not be listed." << "\n";
	}
}	
