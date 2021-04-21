#ifndef G_H
#define G_H 1

#include<vector>
#include "GraphNode.h"

class Graph{
	std::vector<GraphNode*> nodes;
	
	GraphNode* getNode(NodeValue value);
	
	public:
	NodeValue createNode(NodeValue value);
	
	void createRelation(NodeValue valueOne, NodeValue valueTwo);
	
	void removeRelation(NodeValue valueOne, NodeValue valueTwo);
	
	void removeNode(NodeValue value);
	
	bool isEulerian();
	
	bool isSemiEulerian();
	
	void printNodes();
	
	void printRelations();
	
	void printStatus();
};

#endif