#include<vector>
#include "NodeRelation.h"
#include "ValueTypes.h"

GraphNode::GraphNode(NodeValue value){
  this->value = value;
}

GraphNode::~GraphNode(){
  for(auto i = relations.begin(); i != relations.end(); i++){
    delete(*i);
  }
}

bool GraphNode::addRelation(GraphNode* toNode){
  for(auto i = relations.begin(); i != relations.end(); i++){
    if((*i)->isRelationBetween(getValue(), toNode->getValue())){
      return false;
    }
  }
  
  NodeRelation* newRelation = new NodeRelation(this, toNode);
  toNode->notifyRelationAdded(newRelation);
  relations.push_back(newRelation);
  
  return true;
}

bool GraphNode::endRelation(NodeRelation* target){
  for(auto i = relations.begin(); i != relations.end(); i++){
    if(*i == target){
      relations.erase(i);
      return true;
    }
  }
  return false;
}

void GraphNode::notifyRelationAdded(NodeRelation* relation){
  relations.push_back(relation);
}

NodeValue GraphNode::getValue(){
  return value;
}

std::vector<NodeRelation*> GraphNode::getRelations(){
  return relations;
}

NodeRelation* GraphNode::getRelationWith(NodeValue value){
  for(auto i = relations.begin(); i != relations.end(); i++){
    if((*i)->isRelationBetween(getValue(), value)){
      return *i;
    }
  }
}