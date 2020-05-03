//=================================================================================
// File Name   : my_stat.cpp
// Author      : Philip Radojcic
// Description : This obtains all the formatiuon on the file given as a parameter.
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
	
	// Correct argument and a copy file can be made
	if (argc == 2) {
		// construct an instance from the given file.
		manager manager_instance = manager(argv[1]);
		// obtain the file information.
		string name = manager_instance.get_name();
		string type = manager_instance.get_type(); 
		int size = manager_instance.get_size(); 
		string owner = manager_instance.get_owner(); 
		string group = manager_instance.get_group(); 
		string permissions = manager_instance.get_permissions(); 
		int access_time = manager_instance.get_access_time(); 
		int modification_time = manager_instance.get_modification_time();
		int status_change_time = manager_instance.get_status_change_time ();
		int block_size = manager_instance.get_block_size();
		vector children = manager_instance.get_children();
		int error_number = manager_instance.get_error_number(); 
		int error_string = manager_instance.get_error_string();
		// Output all the data.
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
	// Error Check.
	else {
		cout << "The argument was invalid and the file could not be copied over." << "\n";
	}
}	
