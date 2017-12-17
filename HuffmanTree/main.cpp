// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HCNode.h"
#include "MinHeap.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	//prepare HuffmanCoding nodes
	cin.rdbuf();
	HCNode node1('a',12);
	HCNode node2('b', 5);
	HCNode node3('c', 7);
	HCNode node4('d', 4);
	HCNode nodes[] = { node1 ,node2 ,node3 ,node4 };
	MinHeap mh(nodes, 4);
	while (!mh.empty()) {
		cout << mh.deleteMin()->nodeInfo() << endl;
	}
	system("pause");
    return 0;
}

