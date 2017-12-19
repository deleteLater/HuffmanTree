#pragma once
#include "MinHeap.h"
#include "HCNode.h"
#include <iostream>
#include <vector>
#include <stack>

class HuffmanCoding {
public:
	HuffmanCoding(){}
	HuffmanCoding(HCNode nodes[], int nodesCount) {
		MinHeap mh(nodes, nodesCount);
		//build HuffmanTree
		while (mh.size() > 1) {
			oldNodes.push_back(mh.deleteMin());
			oldNodes.push_back(mh.deleteMin());
			HCNode lchild = oldNodes[oldNodes.size() - 2];
			HCNode rchild = oldNodes[oldNodes.size() - 1];
			HCNode* newNode = new HCNode('&', lchild.getWeight() + rchild.getWeight(),&lchild,&rchild);
			mh.insert(newNode);
		}
		//Traversal
		root = &mh.deleteMin();
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
	std::vector<HCNode> oldNodes;
};