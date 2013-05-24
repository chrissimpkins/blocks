/* print.h 
*  Copyright 2013 Christopher Simpkins.  MIT License
*/
#ifndef PRINT_H
#define PRINT_H

#include <iostream>

/************************************
*   Standard Out functions
*************************************/
inline void flush(std::string msg){
	std::cout << msg << std::flush;
}

inline void print(std::string msg){
	std::cout << msg << std::endl;
}

inline void print_error(std::string msg){
	std::cerr << msg << std::endl;
}

#endif