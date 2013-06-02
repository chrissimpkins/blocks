/* filemaker.cpp
*  Copyright 2013 Christopher Simpkins.  MIT License
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "filemaker.h"
#include "print.h"
#include "opts.h"
#include "io.h"
#include "cstdlib"

using std::string;
using std::wstring;
using std::vector;


void FileMaker::make_write_outfile_string() {
	vector<string> file_vec;
	vector<string>& filevec_r = file_vec;
	std::wstring tempstring;
	std::wstring outstring;
	Options opt = Options(argc, cmdvec);
	// get the filepaths listed by user
	opt.fill_arg_vector(filevec_r);
	//iterate through the filepaths, get each string and concatenate into outstring
	for (auto filepath : file_vec){
		IO io = IO(filepath);
		tempstring = io.read_file();
		outstring += tempstring;
	}
	wstring& outstring_r = outstring;
	write_stdout(outstring_r);

	//TO DO: unable to obtain strings from multiple files - fix
}

void FileMaker::write_file(wstring& outstring_ref) {

}

void FileMaker::write_stdout(wstring& outstring_ref) {
	flush(outstring_ref);
}