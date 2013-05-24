/* main.cpp 
*  Copyright 2013 Christopher Simpkins.  MIT License 
*/ 

// Constant definitions
#define VERSION string("0.1.1")
#define APPLICATION string("Blocks")
#define COPYRIGHT string("Copyright 2013 Christopher Simpkins")
#define LICENSE string("MIT License")
#define TAGLINE string("- a text templating engine")
#define GITHUB_SRC string("https://github.com/chrissimpkins/blocks")

// Standard library headers
#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>

#include "main.h"
#include "io.h"
#include "opts.h"
#include "print.h"

// Standard library namespace
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::flush;
using std::string;
using std::vector;
using std::system;




/******************************************
*  Convert the CL character array to vector
*******************************************/

inline vector<string> create_CL_vector(int argc, char const *argv[]){
	vector<string> vs;
	for (int i = 0; i < argc; ++i){
		vs.push_back(argv[i]);
	}
	return vs;
}

/******************************************
*  Terminal view for help
*******************************************/

inline void show_help() {
	print(" ");
	print(APPLICATION + " " + TAGLINE);
	print("Version: " + VERSION);
	print(COPYRIGHT);
	print(LICENSE);
	print("Source: " + GITHUB_SRC);
	print("------------------------------------------------");
	print(" ");
	// SYNTAX HELP
	print("Usage:");
	print("\trx <command> [-shortoption] [--longoption] <last positional arg>");
	// HELP INFO
	print(" ");
	print("Help:");
	print("\trx <command> [-h | --help]");
	print(" ");
	print("Get help for any command with the -h or --help options.");
}

/******************************************
*  Terminal view for usage
*******************************************/

inline void show_usage() {
	print("Usage:");
	print("\trx <command> [-shortoption] [--longoption] <last positional arg>");
}

/******************************************
*  Terminal view for version
*******************************************/

inline void show_version(){
	print(" ");
	print(APPLICATION + " " + TAGLINE);
	print("Version: " + VERSION);
}
