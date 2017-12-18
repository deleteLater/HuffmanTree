// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HCNode.h"
#include "HuffmanCoding.h"
#include "MinHeap.h"
#include <iostream>

using std::cout;
using std::endl;

int& test(int arr[]){
	return arr[0];
}

int main()
{
	//prepare HuffmanCoding nodes
	HCNode node1('a',12);
	HCNode node2('b', 5);
	HCNode node3('c', 7);
	HCNode node4('d', 4);
	HCNode nodes[] = { node1 ,node2 ,node3 ,node4 };

	HuffmanCoding hc(nodes, 4);
	system("pause");
    return 0;
}

