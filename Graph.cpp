#include "GraphNode.h"
#include "NodeRelation.h"
#include "Graph.h"
#include "iostream"

// Private -----------------------------------

GraphNode* Graph::getNode(NodeValue value){
	for(int i = 0; i < nodes.size(); i++){
		if(nodes[i]->getValue() == value){
			return nodes[i];
		}
	}
	return nullptr;
}

// Public -----------------------------------

NodeValue Graph::createNode(NodeValue value){
	GraphNode* result = getNode(value);
	if(result == nullptr){
		nodes.push_back(new GraphNode(value));
		return nodes.back()->getValue();	
	}
	else{
		return result->getValue();
	}
}

void Graph::removeNode(NodeValue value){
	for(auto i = nodes.begin(); i != nodes.end(); i++){
		if((*i)->getValue() == value){
			delete(*i);
			nodes.erase(i);
			break;
		}
	}
}

void Graph::createRelation(NodeValue valueOne, NodeValue valueTwo){
	GraphNode* nodeOne = getNode(valueOne);
	GraphNode* nodeTwo = getNode(valueTwo);
	
	nodeOne->addRelation(nodeTwo);
}
	
void Graph::removeRelation(NodeValue valueOne, NodeValue valueTwo){
	GraphNode* nodeOne = getNode(valueOne);
	GraphNode* nodeTwo = getNode(valueTwo);
  NodeRelation* relation = nodeOne->getRelationWith(nodeTwo->getValue());
	
	nodeOne->endRelation(relation);
}

bool Graph::isEulerian(){
	for(auto i = nodes.begin(); i!= nodes.end(); i++){
		int relationsSize = (*i)->getRelations().size();
		if(relationsSize % 2 != 0 || relationsSize == 0){
			return false;
		}
	}
	return true;
}

bool Graph::isSemiEulerian(){
	int oddRelationsCount = 0;
	for(auto i = nodes.begin(); i!= nodes.end(); i++){
		int relationsSize = (*i)->getRelations().size();
		if(relationsSize % 2 != 0){
			oddRelationsCount++;
		}
		if(relationsSize == 0 || oddRelationsCount > 2){
			return false;
		}
	}
	return oddRelationsCount == 2;
}

void Graph::printNodes(){
	std::cout << "Nodes:";
	for(int i = 0; i < nodes.size(); i++){
		std::cout << " " << nodes[i]->getValue();
	}
	std::cout << "\n\n";
}

void Graph::printRelations(){
	for(int i = 0; i < nodes.size(); i++){
		GraphNode* currentNode = nodes[i];
		std::cout << "Node: " << currentNode->getValue() << "\n";
		std::vector<NodeRelation*> relations = currentNode->getRelations();
		
		for(auto i = relations.begin(); i != relations.end(); i++){
			std::cout << "Relation: " << (*i)->retrieveNodeOneValue() << " <-> " << (*i)->retrieveNodeTwoValue() << "\n"; 
		}
		std::cout << "\n";
	}
}

void Graph::printStatus(){
	if(isEulerian()){
		std::cout << "Is eulerian\n";
	}
	else if(isSemiEulerian()){
		std::cout << "Is semi eulerian\n";
	}
	else{
		std::cout << "Is not eulerian\n";
	}
}


























