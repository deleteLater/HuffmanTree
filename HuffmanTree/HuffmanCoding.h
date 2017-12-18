#pragma once
#include "MinHeap.h"
#include "HCNode.h"
#include <iostream>
#include <stack>

class HuffmanCoding {
public:
	HuffmanCoding(){}
	HuffmanCoding(HCNode nodes[],int nodesCount) {
		MinHeap mh(nodes,nodesCount);
		cout << "初始化:" << endl;
		mh.printElem();
		cout << endl << endl;
		//build HuffmanTree
		while (mh.size() > 1) {
			HCNode* lret = mh.deleteMin();
			HCNode* rret = mh.deleteMin();
			HCNode* lchild = new HCNode(lret->getValue(),lret->getWeight());
			HCNode* rchild = new HCNode(rret->getValue(),rret->getWeight());
			cout << lchild->info() << rchild->info() << endl;
			HCNode* newNode = new HCNode('&', lchild->getWeight() + rchild->getWeight(), lchild, rchild);
			cout << newNode->lchild->info() << newNode->rchild->info() << endl;
			mh.insert(newNode);
			cout << "现在堆中的元素为:\n";
			mh.printElem();
			cout << endl << endl;
		}

		//Traversal
		root = mh.deleteMin();
		std::stack<HCNode*> s;
		while (root || !s.empty()) {
			while (root) {
				cout << root->getValue();
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
	HCNode* root;
	void destroy() {

	}
};