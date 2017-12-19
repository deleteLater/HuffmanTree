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
			HCNode* newNode = new HCNode('&', lchild->getWeight() + rchild->getWeight(), lchild, rchild);
			newNodes.push_back(newNode);	//for destroy
			mh.insert(newNode);
		}
		//set Nodes' Coding(PreOrderTrversal)
		HCNode* pre = mh.deleteMin();
		pre->setCoding("");
		root = pre->lchild;
		std::stack<HCNode*> s;
		s.push(pre);
		while (root || !s.empty()) {
			while (root) {
				s.push(root);
				if (root != pre)  root->setCoding(pre->getCoding() + "0");
				pre = root;
				root = root->lchild;
			}
			if (!s.empty()) {
				root = s.top()->rchild;
				s.pop();
				if (root) {
					root->setCoding(pre->getCoding() + "1");
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
			wpl += (node->getWeight() * node->getCoding().length());
		}
	}
	~HuffmanCoding() {
		root = nullptr;
	}
	size_t WPL() {
		return wpl;
	}
private:
	HCNode* root;
	MinHeapForHC mh;
	std::vector<HCNode*> newNodes;
	size_t wpl;
};