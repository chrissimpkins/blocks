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

#define DEFAULT_OUTPATH string("blocks.txt")  //default out filepath if not specified by user is blocks.txt file

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
	// OPTION s : write to standard out
	if (opt.contains("-s") || opt.contains("--stdout")){
		write_stdout(outstring_r);
	}
	// OPTION o : write to file
	else if (opt.contains("-o")){
		string outpath = opt.get_output();
		string& out_r = outpath;
		write_file(outstring_r, out_r);
	}
	// DEFAULT FILE WRITE
	else {
		//write to default filepath
		string outpath = DEFAULT_OUTPATH;
		string& out_r = outpath;
		write_file(outstring_r, out_r);
	}

}

inline void FileMaker::write_file(wstring& outstring_ref, string& outpath) {
	IO out = IO(outpath);
	out.write_file(outstring_ref);
}

inline void FileMaker::write_stdout(wstring& outstring_ref) {
	flush(outstring_ref);
}
