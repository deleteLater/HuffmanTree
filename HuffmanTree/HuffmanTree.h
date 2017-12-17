#pragma once

class MinHeap {
public:
	MinHeap(const char* chs);
	~MinHeap();

	char deleteMin();
private:
	void sink();
	void swim();
	char *data;
};