#pragma once

#include <iostream>
#include <fstream>
using std::cin;;
using std::cout;
using std::streambuf;
using std::ofstream;
using std::ifstream;

void prepare() {
	streambuf* default_in = cin.rdbuf();
	streambuf* default_out = cout.rdbuf();

}