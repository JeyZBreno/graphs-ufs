#ifndef GR_H
#define GR_H 1

#include "GraphNode.h"
#include "ValueTypes.h"

class GraphNode;

class NodeRelation{
	int weight = 1;
	GraphNode* nodeOne;
	GraphNode* nodeTwo;
	
public:
	NodeRelation(GraphNode* one, GraphNode* two);
	
	~NodeRelation();
	
	NodeValue retrieveNodeOneValue();
	
	NodeValue retrieveNodeTwoValue();
	
	bool isRelationBetween(NodeValue valueOne, NodeValue valueTwo);
};

#endif