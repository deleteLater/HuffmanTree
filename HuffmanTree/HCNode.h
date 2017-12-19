#pragma once

#include <sstream>
#include <string>
using std::string;
using std::ostringstream;

class HCNode {
public:
	HCNode(){
		this->value = ' ';
		this->weight = NULL;
		this->lchild = nullptr;
		this->rchild = nullptr;
	}
	HCNode(char value, size_t weight,
		HCNode* lchild = nullptr, HCNode* rchild = nullptr) {
		this->value = value;
		this->weight = weight;
		this->lchild = lchild;
		this->rchild = rchild;
	}
	void setCoding(string coding) {
		this->coding = coding;
	}
	string getCoding() {
		return coding;
	}
	size_t getWeight() {
		return weight;
	}
	char getValue() {
		return value;
	}
	string info() const{
		ostringstream oss;
		oss << "Value: " << this->value << " | Weight: " << this->weight;
		return oss.str();
	}
	int compareTo(HCNode* &that) {
		return (this->weight > that->weight ? 1 : -1);
	}
public:
	HCNode* lchild;
	HCNode* rchild;
private:
	char value;
	size_t weight;
	string coding;
};