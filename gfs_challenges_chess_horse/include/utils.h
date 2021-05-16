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

static void printNodes(std::vector<Node*> nodeList){
    for(auto i = nodeList.begin(); i != nodeList.end(); i++){
        std::cout << "From:" << (*i)->getValue().toString() << "\n";
        std::vector<Node*> relations = (*i)->retrieveRelations();
        for(auto j = relations.begin(); j != relations.end(); j++ ){
            std::cout << " -> " << (*j)->getValue().toString();
        }
        std::cout << "\n\n";
    }
}

static void printPath(std::vector<Node*> nodeList){
    std::cout << "Path:\n\n";
    for(auto i = nodeList.begin(); i != nodeList.end(); i++){
        std::cout << " -> " << (*i)->getValue().toString();
    }
    std::cout << "\n\n";
}

static std::string getPathInfo(std::vector<Node*> nodeList){
    std::string path;
    path = path + "Path:\n\n";
    for(auto i = nodeList.begin(); i != nodeList.end(); i++){
        path = path + " -> " + (*i)->getValue().toString();
    }
    path = path + "\n\n";
}

static std::string getNodesInfo(std::vector<Node*> nodeList){
    std::string info;
    for(auto i = nodeList.begin(); i != nodeList.end(); i++){
        info = info + "From:" + (*i)->getValue().toString() + "\n";
        std::vector<Node*> relations = (*i)->retrieveRelations();
        for(auto j = relations.begin(); j != relations.end(); j++ ){
            info = info + " -> " + (*j)->getValue().toString();
        }
        info = info + "\n\n";
    }
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
