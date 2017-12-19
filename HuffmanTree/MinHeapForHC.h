#pragma once
// A BinaryMinheap_ptr for HC(HuffmanCoding)

#include "HCNode.h"
#include <vector>

class MinHeapForHC {
public:
	MinHeapForHC() :heap_ptr(nullptr), counter(NULL) {};
	MinHeapForHC(std::vector<HCNode*>& heap_ptr) {
		//build BinaryMinheap_ptr
		this->heap_ptr = new HCNode*[heap_ptr.size() + 1]{};
		this->counter = 0;
		for (size_t i = 1; i <= heap_ptr.size(); i++) {
			insert(heap_ptr[i - 1]);
		}
	}
	~MinHeapForHC() {
		//free memory 
		if (heap_ptr) {
			delete heap_ptr;
			heap_ptr = nullptr;
		}
	}
	void insert(HCNode* node) {
		//insert value rearly,then let it swim
		heap_ptr[++counter] = node;
		swim(counter);
	}
	HCNode* deleteMin() {
		//'hide' MinValue and return it
		std::swap(heap_ptr[1], heap_ptr[counter]);
		counter--;												
		sink(1);
		return heap_ptr[counter + 1];
	}
	bool greater(int i, int j) {
		//if elements[i] > elements[j]
		return (heap_ptr[i]->compareTo(heap_ptr[j]) > 0);
	}
	bool empty() {
		//judge if heap is empty
		return counter == 0;
	}
	size_t size() {
		//returns heap's size
		return counter;
	}
private:
	void sink(int pos) {
		//node 'sink' from pos
		while (2 * pos <= counter) {
			int child = 2 * pos;
			if (child < counter && greater(child, child + 1)) child++;//取孩子中的较小者
			if (!greater(pos, child)) break;
			std::swap(heap_ptr[pos], heap_ptr[child]);
			pos = child;
		}
	}
	void swim(int pos) {
		//node 'swim' from pos
		while (pos > 1 && greater(pos / 2, pos)) {
			std::swap(heap_ptr[pos / 2], heap_ptr[pos]);
			pos /= 2;
		}
	}
	HCNode** heap_ptr;
	int counter;
};
