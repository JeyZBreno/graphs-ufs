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

    if(previousPath.back()->getValue() == toNode->getValue()){
        return previousPath;
    }

    for(auto i = currentRelations.begin(); i != currentRelations.end(); i++){
        if(!(*i)->isInList(previousPath)){
            NodeVector result = tryToFindPath(*i, toNode, previousPath);
            if(result.size() != 0 && result.back()->getValue() == toNode->getValue()){
                return result;
            }
        }
    }

    return emptyVector;
}

NodeVector Graph::widthSearch(Node* from, Node* to){
    NodeVector pendingSearch;
    pendingSearch.push_back(from);
    int currentIndex = 0;

    Graph result;
    while(pendingSearch.size() > currentIndex){
        Node* current = pendingSearch[currentIndex];
        NodeVector currentRelations = current->retrieveRelations();
        Node* createdNode = result.createNode(current->getValue());

        if(current->getValue() == to->getValue()){
            break;
        }

        for(auto i = currentRelations.begin(); i != currentRelations.end(); i++){
            Node* currentChild = *i;

            if(result.getNode(currentChild->getValue()) == nullptr){
                pendingSearch.push_back(currentChild);
                Node* newChild = result.createNode(currentChild->getValue());
                createdNode->createRelation(newChild);
            }
        }
        currentIndex++;
    }

    return result.depthSearch(result.getNode(from->getValue()), result.getNode(to->getValue()));
}

NodeVector Graph::depthSearch(Node* from, Node* to){
    NodeVector emptyVector;
    return tryToFindPath(from, to, emptyVector);
}



































