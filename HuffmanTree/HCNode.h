#pragma once

#include <sstream>
#include <string>
using std::string;
using std::ostringstream;

class HCNode {
public:
	HCNode() {
		//empty Node
		this->value = ' ';
		this->weight = NULL;
		this->lchild = nullptr;
		this->rchild = nullptr;
	}
	HCNode(char value, size_t weight,
	HCNode* lchild = nullptr, HCNode* rchild = nullptr) {
		//specify a node
		this->value = value;
		this->weight = weight;
		this->lchild = lchild;
		this->rchild = rchild;
	}
	string info() const {
		//return node's info
		ostringstream oss;
		oss << "Value: " << this->value << " | Weight: " << this->weight << "  |  Coding: " << this->coding;
		return oss.str();
	}
	int compareTo(HCNode* &that) {
		//compare two nodes
		return (this->weight > that->weight ? 1 : -1);
	}
public:
	//let all data public
	HCNode * lchild;
	HCNode* rchild;
	char value;
	size_t weight;
	string coding;
};