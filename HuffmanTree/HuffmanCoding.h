#pragma once
#include "MinHeap.h"
#include "HCNode.h"
#include <iostream>
#include <stack>
#include <vector>

class HuffmanCoding {
public:
	HuffmanCoding(){}
	HuffmanCoding(const std::vector<HCNode*>& nodes) {
		MinHeap mh(nodes);
		//build HuffmanTree
		while (mh.size() > 1) {
			HCNode* lchild = mh.deleteMin();
			HCNode* rchild = mh.deleteMin();
			mh.insert(new HCNode('&',lchild->getWeight()+rchild->getWeight(),lchild,rchild));
		}
		//Traversal
		root = mh.deleteMin();
		std::stack<const HCNode*> s;
		while (root || !s.empty()) {
			while (root) {
				cout << root->info() << endl;
				s.push(root);
				root = root->lchild;
			}
			if (!s.empty()) {
				root = s.top()->rchild;
				s.pop();
			}
		}
	}
private:
	const HCNode* root;
};