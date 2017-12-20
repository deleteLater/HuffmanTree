// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HCNode.h"
#include "HuffmanCoding.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using std::vector;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

string trim(string src) {
	string ret(src);
	size_t index = 0;
	if (!ret.empty()) {
		while ((index = ret.find(' ', index)) != string::npos) {
			ret.erase(index, 1);
		}
	}
	ret.shrink_to_fit();
	return ret;
}

vector<HCNode*> dataInit() {
	ifstream in("data.txt", std::ios::in);
	//read datas
	string line;
	vector<HCNode*> nodes;
	vector<string> lines;
	std::getline(in, line);//ignore first Line
	while (std::getline(in, line)) {
		string str = trim(line);
		istringstream iss(str.substr(1, str.size() - 1));
		char ch = str[0];
		size_t weight;
		iss >> weight;
		nodes.push_back(new HCNode(ch, weight));
	}
	return nodes;
}

int main()
{
	//prepare HuffmanCoding nodes
	vector<HCNode*> nodes = dataInit();
	HuffmanCoding hc(nodes);
	string binary_coding;
	for (auto node : nodes) {
		cout << node->info() << endl;
		binary_coding.append(node->coding);
	}
	cout << "WPL:" << hc.WPL() << endl;
	cout << endl;
	//decode test
	cout << hc.decode(binary_coding) << endl;
	system("pause");
    return 0;
}

