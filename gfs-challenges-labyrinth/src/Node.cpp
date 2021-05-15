#include "Node.h"
#include "Typedef.h"
#include "utils.h"
#include "Position.h"

Node::Node(Value value){
    val = value;
}

Node::~Node(){
    for(auto i = relations.begin(); i != relations.end(); i++){
        (*i)->notifyDeletion(this);
    }
}

Value Node::getValue(){
    return val;
}

void Node::notifyDeletion(Node* deleted){
    for(auto i = relations.begin(); i != relations.end(); i++){
        if((*i)->getValue() == deleted->getValue()){
            relations.erase(i);
            break;
        }
    }
}

void Node::createRelation(Node* to){
    relations.push_back(to);
    to->notifyRelationCreated(this);
}
std::vector<Node*> Node::retrieveRelations(){
    return relations;
}

void Node::notifyRelationCreated(Node* from){
    relations.push_back(from);
}

bool Node::isInList(std::vector<Node*> target){
    return nodeListContains(target, this);
}

































