#include "Graph.h"
#include "iostream"

int main(){
	Graph notEulerianGraph = Graph();
	NodeValue one = notEulerianGraph.createNode(1);
	NodeValue two = notEulerianGraph.createNode(2);
	NodeValue three = notEulerianGraph.createNode(4);
	NodeValue four = notEulerianGraph.createNode(8);
	NodeValue five = notEulerianGraph.createNode(16);
	notEulerianGraph.printNodes();
	
	notEulerianGraph.createRelation(one, five);
	notEulerianGraph.createRelation(two, five);
	notEulerianGraph.createRelation(three, five);
	notEulerianGraph.createRelation(four, five);
	notEulerianGraph.printRelations();
	
	notEulerianGraph.printStatus();
	
	std::cout << "---------------------------\n\n";
	
	Graph eulerianGraph = Graph();
	NodeValue eulerNodeOne = eulerianGraph.createNode(1);
	NodeValue eulerNodeTwo = eulerianGraph.createNode(2);
	NodeValue eulerNodeThree = eulerianGraph.createNode(4);
	NodeValue eulerNodeFour = eulerianGraph.createNode(8);
	eulerianGraph.printNodes();
	
	eulerianGraph.createRelation(eulerNodeOne, eulerNodeTwo);
	eulerianGraph.createRelation(eulerNodeOne, eulerNodeThree);
	eulerianGraph.createRelation(eulerNodeTwo, eulerNodeFour);
	eulerianGraph.createRelation(eulerNodeThree, eulerNodeFour);
	eulerianGraph.printRelations();
	
	eulerianGraph.printStatus();
	
	std::cout << "---------------------------\n\n";
	
	return 0;
}