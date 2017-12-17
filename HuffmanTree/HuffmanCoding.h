#pragma once
#include "MinHeap.h"
#include "HCNode.h"

class HuffmanCoding {
public:
	HuffmanCoding(){}
	HuffmanCoding(HCNode nodes[],int nodesCount) :mh(nodes,nodesCount){
		//build HuffmanTree
		while (mh.size() > 1) {
			HCNode* lchild = mh.deleteMin();
			HCNode* rchild = mh.deleteMin();
			mh.insert(new HCNode
			('&',lchild->getWeight()+rchild->getWeight(),lchild,rchild)
			);
		}
	}
private:
	MinHeap mh;
};