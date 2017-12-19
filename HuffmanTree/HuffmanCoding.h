#pragma once
#include "MinHeapForHC.h"
#include "HCNode.h"
#include <iostream>
#include <stack>
#include <vector>

class HuffmanCoding {
public:
	HuffmanCoding(){}
	HuffmanCoding(std::vector<HCNode*> nodes) :mh(nodes) {
		//build HuffmanTree
		while (mh.size() > 1) {
			HCNode* lchild = mh.deleteMin();
			HCNode* rchild = mh.deleteMin();
			HCNode* newNode = new HCNode('&', lchild->weight + rchild->weight, lchild, rchild);
			space_reclaimer.push_back(newNode);
			mh.insert(newNode);
		}
		//Set Codings (Use PreOrderTrversal)
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
				else if(!s.empty()){
					pre = s.top();
				}
			}
		}
		//caculate WPL
		wpl = 0;
		for (auto node : nodes) {
			wpl += (node->weight * node->coding.length());
		}
	}
	~HuffmanCoding() {
		for (size_t i = 0; i < space_reclaimer.size(); i++) {
			delete space_reclaimer[i];
		}
		space_reclaimer.clear();
		space_reclaimer.shrink_to_fit();
		mh.~MinHeapForHC();
	}
	size_t WPL() {
		return wpl;
	}
private:
	HCNode* root;
	MinHeapForHC mh;
	std::vector<HCNode*> space_reclaimer;
	size_t wpl;
};