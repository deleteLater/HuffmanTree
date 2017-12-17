#pragma once
// MinHeap.h : the declaration of MinHeap

#include "HCNode.h"
#include <iostream>

using std::cout;
using std::endl;
class MinHeap {
public:
	MinHeap(){};
	MinHeap(HCNode nodes[], int nodesCount) {
		this->nodes = new HCNode[nodesCount+1]{};	//index 0 won't be used
		this->nodesCount = 0;
		for (int i = 1; i < nodesCount+1; i++) {
			insert(&nodes[i - 1]);
		}
	}
	~MinHeap() {
		delete[] nodes;
	}
	void insert(HCNode* node) {
		nodes[++nodesCount] = *node;
		swim(nodesCount);
	}
	HCNode* deleteMin() {
		//"hide" lastMin
		std::swap(nodes[1], nodes[nodesCount--]);
		HCNode* min = &nodes[nodesCount + 1];
		sink(1);
		return min;
	}
	bool greater(int i, int j) {
		return (nodes[i].compareTo(nodes[j]) > 0);
	}
	bool empty() {
		return nodesCount == 0;
	}
	size_t size() {
		return nodesCount;
	}
	void destory() {
		delete[] nodes;
	}
private:
	//sink() and swim() make Heap always Ordered
	void sink(int pos) {
		while (2 * pos <= nodesCount) {
			int child = 2 * pos;
			if (child < nodesCount && greater(child, child + 1)) child++;//取孩子中的较小者
			if (!greater(pos, child)) break;
			std::swap(nodes[pos], nodes[child]);
			pos = child;
		}
	}
	void swim(int pos) {
		while (pos > 1 && greater(pos/2,pos)) {
			std::swap(nodes[pos / 2], nodes[pos]);
			pos /= 2;
		}
	}
	HCNode* nodes;
	int nodesCount;
};

