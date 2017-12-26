#pragma once
#include "MinHeapForHC.h"
#include "HCNode.h"
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <Algorithm>

class HuffmanCoding {
public:
	HuffmanCoding() {}
	HuffmanCoding(std::vector<HCNode*> nodes) :mh(nodes) {
		encode();
		//caculate WPL
		wpl = 0;
		for (auto node : nodes) {
			codingLens.push_back(node->coding.length());
			nodes_map.insert(std::pair<char, string>(node->value, node->coding));
			wpl += (node->weight * node->coding.length());
		}
		//deal with vector(codingLen)
		//vector deweighting
		std::sort(codingLens.begin(), codingLens.end());
		codingLens.erase(std::unique(codingLens.begin(), codingLens.end()), codingLens.end());
		//adjust size
		codingLens.shrink_to_fit();
	}
	~HuffmanCoding() {
		for (size_t i = 0; i < space_reclaimer.size(); i++) {
			delete space_reclaimer[i];
		}
		space_reclaimer.clear();
		space_reclaimer.shrink_to_fit();
		mh.~MinHeapForHC();
	}
	void encode() {
		//build HuffmanTree
		while (mh.size() > 1) {
			HCNode* lchild = mh.deleteMin();
			HCNode* rchild = mh.deleteMin();
			HCNode* newNode = new HCNode('&', lchild->weight + rchild->weight, lchild, rchild);
			space_reclaimer.push_back(newNode);
			mh.insert(newNode);
		}
		//Set Codings (Use PreOrderTrversal's Thought)
		HCNode* pre = mh.deleteMin();
		pre->coding = "";
		root = pre->lchild;
		std::stack<HCNode*> s;
		s.push(pre);
		while (root || !s.empty()) {
			while (root) {
				s.push(root);
				if (root != pre)  root->coding = pre->coding + "0";
				pre = root;
				root = root->lchild;
			}
			if (!s.empty()) {
				root = s.top()->rchild;
				s.pop();
				if (root) {
					root->coding = pre->coding + "1";
					pre = root;
				}
				else if (!s.empty()) {
					pre = s.top();
				}
			}
		}
	}
	string decode(string binary_str) {
		string ret("");
		string cmpstr("");
		char ch;
		for (size_t i = 0; i < binary_str.length(); ) {
			for (size_t j = 0; j < codingLens.size(); j++) {
				cmpstr = binary_str.substr(i, codingLens[j]);
				ch = searchMap(cmpstr);
				if (ch == ' ') {
					if (j == codingLens.size() - 1) {
						std::cout << "WrongCoding!" << std::endl;
						return string();
					}
					continue;
				}
				else {
					i += codingLens[j];
					ret.append(string(1, ch));
					break;
				}
			}
		}
		return ret;
	}
	size_t WPL() {
		return wpl;
	}
private:
	HCNode * root;
	MinHeapForHC mh;
	std::vector<HCNode*> space_reclaimer;
	size_t wpl;
	std::vector<size_t> codingLens;
	std::map<char, string> nodes_map;
	char searchMap(string str) {
		for (auto x : nodes_map) {
			if (x.second == str) {
				return x.first;
			}
		}
		return ' ';
	}
};