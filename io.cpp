/* io.cpp
*  Copyright 2013 Christopher Simpkins.  MIT License
*/

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iterator>

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

/**********************************
*  READ FUNCTIONS
**********************************/

//public function to read entire string from a file
wstring IO::read_file(){
	//if the path variable is assigned in constructor
	if (!path.empty()){
		try{
			wifstream infile(path);
			if (infile.good()){
				// define the input string from the calling function with the reference that was passed in
				wifstream& inr = infile;
				get_string(inr);
				infile.close();
				return inputstring;
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
void IO::get_string(wifstream& is){
	if (is.good()){
		//get length of file
		//is.seekg(0, is.end);
		//size_t length = is.tellg();
		//is.seekg(0, is.beg);
		//allocate memory for strings
		//wchar_t* buffer = new wchar_t [length];
		//if (buffer) {
			// read data as a block into buffer


			wstring tempstring;
			while(getline(is, tempstring)){
				if (is.eof()){
					print("Yep, hit EOF");
					//if it is the end of the file, check the char at the last position in the stream
					//if it is a newline char, replace it, otherwise done
					is.seekg(0, is.end);
					long end = is.tellg();
					long last_char = end - 1;
					is.seekg(last_char);
					wchar_t c;
					wchar_t& c_r = c;
					if ((wchar_t)is.get(c_r) == '\n'){
						tempstring += '\n';
					}
					std::cout << c << std::endl;
				}
				else{
					//add the newline character that was removed by getline call
					tempstring += '\n';
				}
				//concatenate temp string with the existing input string
				inputstring += tempstring;
			}
			//inputstring = buffer;
			is.close();
			//delete[] buffer;
		//}
		//else {
		//	print_error("Unable to allocate memory for input string");
		//	exit(EXIT_FAILURE);
		//}
	}
	else{
		print_error("Unable to open input file path");
		exit(EXIT_FAILURE);
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

