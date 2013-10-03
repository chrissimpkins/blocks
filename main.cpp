/* main.cpp
*  Copyright 2013 Christopher Simpkins.  MIT License
*/

// Constant definitions
#define VERSION string("0.1.5")
#define APPLICATION string("Blocks")
#define COPYRIGHT string("Copyright 2013 Christopher Simpkins")
#define LICENSE string("MIT License")
#define TAGLINE string("- a text file template compiler")
#define GITHUB_SRC string("https://github.com/chrissimpkins/blocks")

// Standard library headers
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>

// Blocks headers
#include "main.h"
#include "filemaker.h"
#include "io.h"
#include "opts.h"
#include "print.h"
#include "pyc.h"

// Standard library namespace
using std::wstring;
using std::string;
using std::vector;
using std::cout;
using std::wcout;
using std::endl;

/*
*  Options:
*		-o : specify out file path (filemaker.cpp)
*		-s : write to standard out (filemaker.cpp)
*
*
*  Defaults:
*		Out file path : 'blocks.txt' (specified in filemaker.cpp define)
*/

/******************************************
*  G'day, I'm main()
*******************************************/

int main(int argc, char const *argv[]) {
	string teststring = "";
	//user did not enter enough arguments in the command
	if (argc < 2) {
		print("You didn't enter a command");
		show_usage();
		return 1;
	}
	else{
		//create the command line vector
		const vector<string> clv = create_CL_vector(argc, argv);
		//create reference to the CL vector (used to pass the CL vector by reference)
		const vector<string>& clvr = clv;
		// create a string for the main user entered command at vector position 1
		const string cmd = clv.at(1);
		// HELP ---------------------------------------------------------
		if (cmd == "help" || cmd == "-h" | cmd == "--help"){
			show_help();
		}
		// VERSION ------------------------------------------------------
		else if (cmd == "version" || cmd == "-v" | cmd == "--version"){
			show_version();
		}
		// MAKE ---------------------------------------------------------
		else if (cmd == "make") {
			if (argc < 3) {
				print_error("Please include text blocks to compile your file");
				return 1;
			}
			else {
				FileMaker fm = FileMaker(argc, clvr);
				fm.make_write_outfile_string();
			}
		}
		// READ ---------------------------------------------------------
		else if (cmd == "read") {
			Options opt = Options(argc, clvr);
			string inpath = opt.get_last_positional();
			IO io = IO(inpath);
			wstring infile = io.read_file();
			cout << "The text block '" << inpath << "':" << endl << endl;
			wcout << infile << endl;
		}
		else if (cmd == "test") {
			PyObject* compress_func;
			python_Initialize();
			compress_func = get_PyCallable_From_PyModule("lib.py.network", "print_html");
			const char* filepath = "http://www.google.com";
			int i = python_Call(compress_func, "(s)", filepath);
			if (i == 0)
				cout << "completed compression" << endl;
			Py_DECREF(compress_func);
			python_Finalize();
		}
		else{
			print_error("The blocks command that you submitted was not recognized.  Type 'blocks help' to view the available commands.\n");
			show_usage();
		}
	}

} //end main

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
*  Display help
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
	print("\tblocks <command> <argument(s)> [-shortoption] [--longoption]\n");
	// HELP INFO
	print("Help:");
	print("\tblocks <command> [-h | --help]\n");
	print("Get help for any command with the -h or --help options.\n");
	print("Available Commands:");
	print("\tmake : compile a text file from multiple text block templates");
	print("\tread : stream a text block to standard output\n");
}

/******************************************
*  Display usage
*******************************************/

inline void show_usage() {
	print("Usage:");
	print("\tblocks <command> [-shortoption] [--longoption] <last positional arg>");
}

/******************************************
*  Display version
*******************************************/

inline void show_version(){
	print(" ");
	print(APPLICATION + " " + TAGLINE);
	print("Version: " + VERSION);
}
