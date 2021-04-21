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

  std::cout << "Eulerian path:\n";
  notEulerianGraph.printPath(notEulerianGraph.tryToFindEulerianPath()); 
  std::cout << "Biggest path:\n";
  notEulerianGraph.printPath(notEulerianGraph.tryToFindEulerianPath()); 
	
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
  
  std::cout << "Eulerian path:\n";
  eulerianGraph.printPath(eulerianGraph.tryToFindEulerianPath()); 
  std::cout << "Biggest path:\n";
  eulerianGraph.printPath(eulerianGraph.tryToFindEulerianPath()); 
	
	std::cout << "---------------------------\n\n";

  std::cout << "---------------------------\n\n";
	
	Graph challenge = Graph();
  NodeValue n1 = challenge.createNode(1);
  NodeValue n2 = challenge.createNode(2);
  NodeValue n3 = challenge.createNode(3);
  NodeValue n4 = challenge.createNode(4);
  NodeValue n5 = challenge.createNode(5);
  NodeValue n6 = challenge.createNode(6);
  NodeValue n7 = challenge.createNode(7);
  NodeValue n8 = challenge.createNode(8);
  NodeValue n9 = challenge.createNode(9);

	challenge.printNodes();
	
	challenge.createRelation(n1, n2);
	challenge.createRelation(n1, n3);
	challenge.createRelation(n2, n4);
	challenge.createRelation(n3, n4);
  challenge.createRelation(n4, n5);
  challenge.createRelation(n5, n6);
  challenge.createRelation(n5, n7);
  challenge.createRelation(n6, n8);
  challenge.createRelation(n7, n9);
  challenge.createRelation(n8, n9);
	challenge.printRelations();
	
	challenge.printStatus();
  
  std::cout << "Eulerian path:\n";
  challenge.printPath(challenge.tryToFindEulerianPath()); 
  std::cout << "Biggest path:\n";
  challenge.printPath(challenge.tryToFindEulerianPath()); 
	
	std::cout << "---------------------------\n\n";
	
	return 0;
}