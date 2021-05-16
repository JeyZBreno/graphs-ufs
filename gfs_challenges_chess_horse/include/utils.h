#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "vector"
#include "iostream"
#include "fstream"

static bool nodeListContains(std::vector<Node*> nodeList, Node* node){
    for(auto i = nodeList.begin(); i != nodeList.end(); i++){
        if((*i)->getValue() == node->getValue()){
            return true;
        }
    }
    return false;
}

static std::vector<std::string> getPathInfo(std::vector<Value> values){
    std::vector<std::string> infoLines;
    infoLines.push_back("Path:\n\n");

    std::string path;
    for(auto i = values.begin(); i != values.end(); i++){
        path = path + " -> " + (*i).toString();
    }
    path = path + "\n\n";
    infoLines.push_back(path);

    return infoLines;
}

static std::vector<std::string> getNodesInfo(std::vector<Node*> nodeList){
    std::vector<std::string> infoLines;

    for(auto i = nodeList.begin(); i != nodeList.end(); i++){
        infoLines.push_back("From:" + (*i)->getValue().toString() + "\n");

        std::vector<Node*> relations = (*i)->retrieveRelations();
        std::string relationStr;
        for(auto j = relations.begin(); j != relations.end(); j++ ){
            relationStr = relationStr + " -> " + (*j)->getValue().toString();
        }
        relationStr = relationStr + "\n\n";
        infoLines.push_back(relationStr);
    }

    return infoLines;
}

static void printLines(std::vector<std::string> content){
    for(auto i = content.begin(); i != content.end(); i++){
        std::cout << *i;
    }
}

static void makeFile(std::string title, std::vector<std::string> content){
    std::ofstream file(title + ".txt");
    for(auto i = content.begin(); i != content.end(); i++){
        file << (*i);
    }
    file.close();
}

template <typename T>
std::vector<T> joinVectors(std::vector<T> listOne, std::vector<T> listTwo){
    for(auto i = listTwo.begin(); i != listTwo.end(); i++){
        listOne.push_back(*i);
    }
    return listOne;
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
