/* io.cpp
*  Copyright 2013 Christopher Simpkins.  MIT License
*/

#include <string>
#include <iostream>
#include <fstream>

#include "io.h"
#include "print.h"
#include "cstdlib" //exit(int successflag)

using std::wstring;
using std::string;
using std::wifstream;
using std::wofstream;
using std::endl;
using std::flush;
using std::runtime_error;
using std::wifstream;

#define DEFAULT_OUTPATH "blocks.txt"

/**********************************
*  READ FUNCTIONS
**********************************/

//public function to read entire string from a file
wstring& IO::read_file(){
	//if the path variable is assigned in constructor
	if (!path.empty()){
		try{
			wifstream infile(path);
			if (infile.good()){
				// define the input string from the calling function with the reference that was passed in
				wifstream& inr = infile;
				get_string(inr);
				wstring& isr = inputstring;
				infile.close();
				return isr;
			}
			else{
				print_error("Unable to open the input file " + path);
				exit(EXIT_FAILURE);
			}
		}
		catch(...){
			print_error("Unable to open the input file " + path);
			exit(EXIT_FAILURE);
		}
	}
	//otherwise use the ipath from constructor
	else if (!ipath.empty()) {
		try{
			wifstream infile(ipath);
			if (infile.good()){
				// define the input string from the calling function with the reference that was passed in
				wifstream& inr = infile;
				get_string(inr);
				wstring& isr = inputstring;
				infile.close();
				return isr;
			}
			else{
				print_error("Unable to open the input file " + path);
				exit(EXIT_FAILURE);
			}
		}
		catch (...){
			print_error("Unable to open the input file " + path);
			exit(EXIT_FAILURE);
		}
	}
	else{
		print_error("Missing a file path for the input file.");
		exit(EXIT_FAILURE);
	}
}

//private function to get the entire string from a text file
void IO::get_string(wifstream& inputstream){
	while (inputstream.good()) {
		//load the input stream from the file into a string stream
		int next = inputstream.get();
		if (next == EOF){
			break;
		}
		//implicit conversion of the int char to a string
		inputstring += next;
	}
}

//private function to the get the input filestream
wifstream& IO::get_input_stream(wifstream& infilestream){
	if (!path.empty()){
		try{
			infilestream.open(path);
			if (infilestream.good()) {
				wifstream& inr = infilestream;
				return inr;
			}
			else{
				print_error("Input File Error");
				exit(EXIT_FAILURE);
			}
		}
		catch (...) {
			print_error("Unable to open the input file " + path);
			exit(EXIT_FAILURE);
		}
	}
	else if (!ipath.empty()){
		try{
			infilestream.open(ipath);
			if (infilestream.good()){
				wifstream& inr = infilestream;
				return inr;
			}
			else{
				print_error("Input File Error");
				exit(EXIT_FAILURE);
			}
		}
		catch (...){
			print_error("Unable to open the input file " + ipath);
			exit(EXIT_FAILURE);
		}
	}
}

/**********************************
*  WRITE FUNCTIONS
**********************************/

//public function to write a string to a file (uses private write_filestring() to write it)
void IO::write_file(wstring& outstring) {
	if (!path.empty()) {
		wofstream outfile(path);
		if (outfile.good()) {
			wofstream& outr = outfile;
			write_filestring(outr, outstring);
			outfile.close();
		}
		else{
			print_error("Unable to open the output file " + path);
			exit(EXIT_FAILURE);
		}
	}
	else if (!opath.empty()) {
		wofstream outfile(opath);
		if (outfile.good()) {
			wofstream& outr = outfile;
			write_filestring(outr, outstring);
			outfile.close();
		}
		else{
			print_error("Unable to open the output file " + opath);
			exit(EXIT_FAILURE);
		}
	}
	else{
		print_error("Missing a filepath for the output file.");
		exit(EXIT_FAILURE);
	}
}


//private function to get the output filestream
wofstream& IO::get_output_stream(wofstream& outfilestream){
	if (!path.empty()){
		try{
			outfilestream.open(path);
			if (outfilestream.good()) {
				wofstream& outr = outfilestream;
				return outr;
			}
			else{
				print_error("File Write Error");
				exit(EXIT_FAILURE);
			}
		}
		catch (...) {
			print_error("Unable to write to the output file " + path);
			exit(EXIT_FAILURE);
		}
	}
	else if (!opath.empty()){
		try{
			outfilestream.open(opath);
			if (outfilestream.good()) {
				wofstream& outr = outfilestream;
				return outr;
			}
			else{
				print_error("File Write Error");
				exit(EXIT_FAILURE);
			}
		}
		catch (...) {
			print_error("Unable to write to the output file " + opath);
			exit(EXIT_FAILURE);
		}
	}
}

// private function to write a string to a file
void IO::write_filestring(wofstream& ofs, wstring& outstring) {
	if (ofs.good()) {
		ofs << outstring << flush;
	}
}

// public function to write string to std out
void IO::write_stdout(wstring& outstring){
	flush(outstring);
}

