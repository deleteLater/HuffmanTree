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
	void setChilds(HCNode* lchild, HCNode* rchild) {
		this->lchild = lchild;
		this->rchild = rchild;
	}
	inline void setCoding(string coding) {
		this->coding = coding;
	}
	inline string getCoding() {
		return coding;
	}
	inline size_t getWeight() {
		return weight;
	}
	inline char getValue() {
		return value;
	}
	string info() {
		ostringstream oss;
		oss << "Value: " << this->value << " | Weight: " << this->weight;
		return oss.str();
	}
	inline int compareTo(const HCNode &that) {
		return (this->weight > that.weight ? 1 : -1);
	}
public:
	HCNode* lchild;
	HCNode* rchild;
private:
	char value;
	size_t weight;
	string coding;
};