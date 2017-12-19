#pragma once
#include "MinHeap.h"
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
		//set Nodes' Coding
		HCNode* pre = mh.deleteMin();
		pre->setCoding("");
		root = pre->lchild;
		std::stack<HCNode*> s;
		s.push(pre);
		while (root || !s.empty()) {
			while (root) {
				root->setCoding(pre->getCoding() + "0");
				s.push(root);
				root = root->lchild;
				pre = root;
			}
			if (!s.empty()) {
				root = s.top()->rchild;	
				if (root) {
					root->setCoding(pre->getCoding() + "1");
					pre = root;
				}
				s.pop();
			}
		}
	}
	~HuffmanCoding() {
		if (!newNodes.empty())
			destroy();
	}
	void destroy() {
		root = nullptr;
		newNodes.clear();
		newNodes.shrink_to_fit();//vector<HCNode*>().swap(newNodes)
		mh.destory();
	}
private:
	HCNode* root;
	MinHeap mh;
	std::vector<HCNode*> newNodes;
};