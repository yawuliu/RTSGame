#include "log.h"

#include <iostream>

std::fstream* Log::fout = new std::fstream("./log.txt", std::fstream::out);

Log::Log() {

}

Log::~Log() {
	*fout << std::endl;
}

std::fstream* Log::outStream() {
	return fout;
}
