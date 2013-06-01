/* opts.cpp
*  Copyright 2013 Christopher Simpkins.  MIT License
*/

#include <vector>
#include <string>

#include "opts.h"
#include "print.h"

using std::string;
using std::vector;
using std::runtime_error;

// returns a vector of all options entered on the command line
vector<string> Options::get_options() {
	vector<string> return_opts;
	for (int i = 2; i < argc; ++i){
		if (!optionvec[i].empty()){
			string oi = optionvec[i];
			if (oi.substr(0,1) == "-" || oi.substr(0,2) == "--"){
				//it is an option, so load it into the vector
				return_opts.push_back(oi);
			}
		}

	}
	return return_opts;
}

// returns the string in position immediately following an option flag
string Options::get_positional_option(string optionflag){
	string positional = "";
	for (auto iter = optionvec.begin(); iter < optionvec.end(); ++iter){
		if (*iter == optionflag){
			try{
				positional = *(iter + 1);
				return positional;
			}
			catch (...){
				print_error("Unable to read the positional argument for the " + optionflag + " option.  Did you include one?");
				return "";
			}
		}
	}
	return positional;
}

// returns a string with the input file entered after the -i flag
string Options::get_input(){
	string inputflag = "-i";
	string inputfile = "";
	for (auto iter = optionvec.begin(); iter < optionvec.end(); ++iter){
		if (*iter == inputflag){
			inputfile = *(iter + 1);
			return inputfile;
		}
	}
	return inputfile;
}

// returns a string with the output file entered after the -o flag
string Options::get_output(){
	string outputflag = "-o";
	string outputfile = "";
	for (auto iter = optionvec.begin(); iter < optionvec.end(); ++iter){
		if (*iter == outputflag){
			outputfile = *(iter + 1);
			return outputfile;
		}
	}
	return outputfile;
}

// returns the string in the last position on the CL, this has command specific applications
string Options::get_last_positional(){
	auto iter_end = optionvec.end();
	//return the last argument on the command line
	string laststring = *(iter_end - 1);
	return laststring;
}

// returns boolean for check on optionflag inclusion in the options vector (which is vector of each string submitted by user)
bool Options::contains(string optionflag){
	vector<string> optv = get_options();
	int i = 0;
	//check the options vector and determine whether it contains the requested optionflag
	for (auto s : optv){
		if (s == optionflag){
			i = 1;
		}
	}
	if (i){
		return true;
	}
	else{
		return false;
	}
}

