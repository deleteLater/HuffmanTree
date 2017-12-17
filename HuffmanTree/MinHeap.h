#pragma once
// MinHeap.h : the declaration of MinHeap

#include "HCNode.h"
class MinHeap {
public:
	MinHeap(){};
	MinHeap(HCNode nodes[], int nodesCount) {
		this->nodes = new HCNode[nodesCount+1]{};	//index 0 won't be used
		this->curInsertIndex = 1;
		this->nodesCount = nodesCount;
		for (int i = 1; i < nodesCount+1; i++) {
			insert(nodes[i - 1]);
		}
	}
	~MinHeap() {
		delete[] nodes;
	}
	void insert(HCNode& node) {
		nodes[curInsertIndex] = node;
		swim(curInsertIndex++);
	}
	HCNode* deleteMin() {
		HCNode* min = &nodes[1];
		std::swap(nodes[1], nodes[nodesCount--]);
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
	bool greater(int i, int j) {
		return (nodes[i].compareTo(nodes[j]) > 0);
	}
	HCNode* nodes;
	int nodesCount;
	int curInsertIndex;
};

