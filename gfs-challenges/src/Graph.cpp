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
    Node* node = getNode(nodeValue);
    if(node == nullptr){
        nodes.push_back(new Node(nodeValue));
        return nodes.back();
    }
    else{
        return node;
    }
}

Node* Graph::getNode(Value nodeValue){
    for(auto i = nodes.begin(); i != nodes.end(); i ++){
        if((*i)->getValue() == nodeValue){
           return *i;
        }
    }
    return nullptr;
}

void Graph::removeNode(Value nodeValue){
    Node* node = getNode(nodeValue);
    if(node != nullptr){
        removeFromVector(nodes, node);
        delete(node);
    }
}

Graph Graph::createSubGraph(NodeVector subGraphNodes){
    Graph subGraph;
    for(auto i = subGraphNodes.begin(); i != subGraphNodes.end(); i++){
        NodeVector currentNodeRelations = (*i)->retrieveRelations();
        Node* node = subGraph.createNode((*i)->getValue());

        for(auto j = currentNodeRelations.begin(); j != currentNodeRelations.end(); j++){
            if((*j)->isInList(subGraphNodes)){
                Node* relatedNode = subGraph.createNode((*j)->getValue());
                node->createRelation(relatedNode);
            }
        }
    }
    return subGraph;
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

NodeVector Graph::tryToFindPath(Node* currentNode, Node* toNode, NodeVector previousPath){
    previousPath.push_back(currentNode);
    NodeVector emptyVector;
    NodeVector currentRelations = currentNode->retrieveRelations();

    if(previousPath.back() == toNode){
        return previousPath;
    }

    for(auto i = currentRelations.begin(); i != currentRelations.end(); i++){
        NodeVector result = tryToFindPath(toNode, *i, previousPath);
        if(result.back() == toNode){
            return result;
        }
    }

    return emptyVector;
}

NodeVector Graph::findPath(Graph targetGraph, Node* from, Node* to){
    return targetGraph.depthSearch(from, to);
}

NodeVector Graph::widthSearch(Node* from, Node* to){
    NodeVector toBeSearched = from->retrieveRelations();
    NodeVector alreadySearched = {from};

    for(auto i = toBeSearched.begin(); i != toBeSearched.end(); i++){
        alreadySearched.push_back(*i);

        if((*i)->getValue() == to->getValue()){
            break;
        }

        NodeVector newRelations = (*i)->retrieveRelations();
        for(auto j = newRelations.begin(); j != newRelations.end(); j++){
            if(!(*j)->isInList(alreadySearched)){
                toBeSearched.push_back(*j);
            }
        }
    }

    return findPath(createSubGraph(alreadySearched), from, to);
}

NodeVector Graph::depthSearch(Node* from, Node* to){
    NodeVector emptyVector;
    return tryToFindPath(from, to, emptyVector);
}



































