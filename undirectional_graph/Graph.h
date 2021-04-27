#ifndef G_H
#define G_H 1

#include<vector>
#include "GraphNode.h"
#include "NodeRelation.h"

class Graph{
	std::vector<GraphNode*> nodes;
	
	GraphNode* getNode(NodeValue value);

  std::vector<NodeRelation*> runThroughGraph(std::vector<NodeRelation*> pastPath, GraphNode* currentNode);

  int numberOfRelations();
	
	public:
	NodeValue createNode(NodeValue value);
	
	void createRelation(NodeValue valueOne, NodeValue valueTwo);
	
	void removeRelation(NodeValue valueOne, NodeValue valueTwo);
	
	void removeNode(NodeValue value);
	
	bool isEulerian();
	
	bool isSemiEulerian();

  std::vector<NodeRelation*> tryToFindEulerianPath();

  std::vector<NodeRelation*> findBiggestPath();
	
	void printNodes();
	
	void printRelations();
	
	void printStatus();

  void printPath(std::vector<NodeRelation*> path);
};

#endif