/* print.h
*  Copyright 2013 Christopher Simpkins.  MIT License
*/
#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>

/************************************
*   Standard Out functions
*************************************/

/************************************
*   Flush to stdout as is (no newline)
*************************************/
inline void flush(std::string msg){
	std::cout << msg << std::flush;
}
// for wide strings
inline void flush(std::wstring msg){
	std::wcout << msg << std::flush;
}

/************************************
*   Print to stdout with newline
*************************************/
inline void print(std::string msg){
	std::cout << msg << std::endl;
}
// for wide strings
inline void print(std::wstring msg){
	std::wcout << msg << std::endl;
}

/************************************
*   Print to stderr with newline
*************************************/
inline void print_error(std::string msg){
	std::cerr << msg << std::endl;
}
// for wide strings
inline void print_error(std::wstring msg){
	std::wcerr << msg << std::endl;
}

#endif