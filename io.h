/* io.h
*  Copyright 2013 Christopher Simpkins.  MIT License
*/

#ifndef IO_H
#define IO_H

class IO {

	public:
		//contructors
		IO() = default;
		// constructor with single path
		IO(std::string userpath) : path(userpath) { }
		// constructor with input and output paths
		IO(std::string inpath, std::string outpath) : ipath(inpath), opath(outpath) { }

		//functions
		std::wstring& read_file();
		void write_file(std::wstring& outstring);
		void write_stdout(std::wstring& outstring);

	private:
		//variables
		std::string path; //generic filepath when single path used in constructor
		std::string ipath; //in filepath
		std::string opath;  //out filepath
		std::wstring inputstring; //defined with the appropriate string from the file, returned as reference from public functions
		std::wstring tempstring; //temporary string to hold parts of the text from file
		//functions
		void get_string(std::wifstream& filestream);
		void write_filestring(std::wofstream& filestream, std::wstring& outstring);
		std::wifstream& get_input_stream(std::wifstream& inr);
		std::wofstream& get_output_stream(std::wofstream& outr);
};

#endif