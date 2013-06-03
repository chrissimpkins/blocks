/* filemaker.h
*  Copyright 2013 Christopher Simpkins.  MIT License
*/

#ifndef FILEMAKER_H
#define FILEMAKER_H

class FileMaker {
public:
	//constructors
	FileMaker() = default;
	FileMaker(const int argnumber, const std::vector<std::string>& cvec) : argc(argnumber), cmdvec(cvec) { }

	//functions
	void make_write_outfile_string();

private:
	//variables
	int argc;                          //number of arguments on the command line
	const std::vector<std::string>& cmdvec; //holds the command line vector
	//functions
	inline void write_file(std::wstring&, std::string&);
	inline void write_stdout(std::wstring&);
};

#endif