#ifndef GN_H
#define GN_H 1

#include<vector>
#include "NodeRelation.h"
#include "ValueTypes.h"

class NodeRelation;

class GraphNode{
	NodeValue value;
	std::vector<NodeRelation*> relations;
	
	public:	
	GraphNode(NodeValue value);
	
	~GraphNode();
	
	bool addRelation(GraphNode* toNode);
	
	bool endRelation(NodeRelation* target);
	
	void notifyRelationAdded(NodeRelation* relation);

	NodeValue getValue();
	
	std::vector<NodeRelation*> getRelations();

  NodeRelation* getRelationWith(NodeValue value);
};

#endif