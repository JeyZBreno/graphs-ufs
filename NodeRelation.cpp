#include "NodeRelation.h"
#include "GraphNode.h"
#include "iostream"

NodeRelation::NodeRelation(GraphNode* one, GraphNode* two){
		nodeOne = one;
		nodeTwo = two;
};
	
NodeRelation::~NodeRelation(){
		nodeOne->endRelation(this);
		nodeTwo->endRelation(this);
}

NodeValue NodeRelation::retrieveNodeOneValue(){
		return nodeOne->getValue();
}

NodeValue NodeRelation::retrieveNodeTwoValue(){
		return nodeTwo->getValue();
}

bool NodeRelation::isRelationBetween(NodeValue valueOne, NodeValue valueTwo){
  return (nodeOne->getValue() == valueOne && nodeTwo->getValue() == valueTwo) || (nodeOne->getValue() == valueTwo && nodeTwo->getValue() == valueOne);
}

bool NodeRelation::notIn(std::vector<NodeRelation*> relations){
  for(auto i = relations.begin(); i != relations.end(); i++){
    if((*i) == this){
      return false;
    }
  }
  return true;
}

GraphNode* NodeRelation::getOtherNode(GraphNode* current){
  if(current == nodeOne){
    return nodeTwo;
  }
  else if(current == nodeTwo){
    return nodeOne;
  }
  else{
    return nullptr;
  }
}

void NodeRelation::printRelation(GraphNode* currentNode){
    std::cout << currentNode->getValue() << " -> "  << getOtherNode(currentNode)->getValue();
}