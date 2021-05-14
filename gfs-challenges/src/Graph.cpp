#include "Graph.h"
#include "utils.h"

typedef std::vector<Node*> NodeVector;

Graph::Graph(){}

Graph::~Graph(){
    for(auto i = nodes.begin(); i != nodes.end(); i ++){
        delete(*i);
    }
}

std::vector<Node*> Graph::getNodes(){
   return nodes;
}

Node* Graph::createNode(Value nodeValue){
    nodes.push_back(new Node(nodeValue));
    return nodes.back();
}

Node* Graph::getNode(Value nodeValue){
    for(auto i = nodes.begin(); i != nodes.end(); i ++){
        (*i)->getValue() == nodeValue;
        return *i;
    }
    return nullptr;
}

void Graph::removeNode(Value nodeValue){
    Node* node = getNode(nodeValue);
    removeFromVector(nodes, node);
    delete(node);
}

NodeVector Graph::findHamiltonianPath(){
    NodeVector emptyVector;
    NodeVector biggestPath;

    for(auto i = nodes.begin(); i != nodes.end(); i++){
        NodeVector foundPath = tryToFindBiggestPathFrom(*i, emptyVector);
        if(foundPath.size() >= biggestPath.size()){
            biggestPath = foundPath;
        }
    }

    if(biggestPath.size() == nodes.size()){
        return biggestPath;
    }
    else {
        return emptyVector;
    }
}

NodeVector Graph::tryToFindBiggestPathFrom(Node* currentNode, NodeVector previousPath){
    previousPath.push_back(currentNode);
    NodeVector currentNodeRelations = currentNode->retrieveRelations();

    NodeVector biggestPath = previousPath;
    for(auto i = currentNodeRelations.begin(); i != currentNodeRelations.end(); i++){
        if(!(*i)->isInList(previousPath)){
            NodeVector result = tryToFindBiggestPathFrom(*i, previousPath);

            if(result.size() >= biggestPath.size()){
                biggestPath = result;
            }
        }
    }
    return biggestPath;
}





































