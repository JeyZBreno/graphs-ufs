#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "vector"
#include "iostream"

static bool nodeListContains(std::vector<Node*> nodeList, Node* node){
    for(auto i = nodeList.begin(); i != nodeList.end(); i++){
        if((*i)->getValue() == node->getValue()){
            return true;
        }
    }
    return false;
}

static bool printNodes(std::vector<Node*> nodeList){
    std::cout << "Nodes:\n\n";
    for(auto i = nodeList.begin(); i != nodeList.end(); i++){
        std::cout << " -> " << (*i)->getValue();
    }
    std::cout << "\n\n";
}

static bool printPath(std::vector<Node*> nodeList){
    std::cout << "Path:\n\n";
    for(auto i = nodeList.begin(); i != nodeList.end(); i++){
        std::cout << " -> " << (*i)->getValue();
    }
    std::cout << "\n\n";
}

template <typename T>
void removeFromVector(std::vector<T>& tList, T toRemove){
    for(auto i = tList.begin(); i != tList.end(); i++){
        if((*i) == toRemove){
            tList.erase(i);
        }
    }
}

#endif
