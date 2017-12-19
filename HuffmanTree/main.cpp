// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HCNode.h"
#include "HuffmanCoding.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main()
{
	//prepare HuffmanCoding nodes
	HCNode* node1 = new HCNode('a', 4);
	HCNode* node2 = new HCNode('b', 4);
	HCNode* node3 = new HCNode('c', 4);
	HCNode* node4 = new HCNode('d', 4);
	HCNode* node5 = new HCNode('e', 4);
	std::vector<HCNode*> nodes;
	nodes.push_back(node1);
	nodes.push_back(node2);
	nodes.push_back(node3);
	nodes.push_back(node4);
	nodes.push_back(node5);
	HuffmanCoding hc(nodes);
	for (auto node : nodes) {
		cout << node->info() << endl;
	}
	system("pause");
    return 0;
}

