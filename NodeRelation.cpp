#include "NodeRelation.h"
#include "GraphNode.h"

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