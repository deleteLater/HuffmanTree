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
	HCNode* node1 = new HCNode('a', 19);
	HCNode* node2 = new HCNode('b', 21);
	HCNode* node6 = new HCNode('f', 10);
	HCNode* node7 = new HCNode('g', 32);
	HCNode* node3 = new HCNode('c', 2);
	HCNode* node4 = new HCNode('d', 3);
	HCNode* node5 = new HCNode('e', 7);

	std::vector<HCNode*> nodes;
	nodes.push_back(node1);
	nodes.push_back(node2);
	nodes.push_back(node6);
	nodes.push_back(node7);
	nodes.push_back(node3);
	nodes.push_back(node4);
	nodes.push_back(node5);
	HuffmanCoding hc(nodes);
	for (auto node : nodes) {
		cout << node->info() << endl;
	}
	cout << hc.WPL();
	system("pause");
    return 0;
}

