#ifndef UTILS_H
#define UTILS_H 1

#include "vector"
#include "iostream"
#include "Graph.h"
#include "GraphNode.h"
#include "ValueTypes.h"

class Utils{
public:
    std::vector<GraphNode*> removeNodeFrom(std::vector<GraphNode*> from, GraphNode* node){
        std::vector<GraphNode*> toRemoveList = from;
        for(auto i = toRemoveList.begin(); i != toRemoveList.end(); i++){
            if((*i) == node){
                toRemoveList.erase(i);
                return toRemoveList;
            }
        }
        return toRemoveList;
    }

    bool nodeNotIn(std::vector<GraphNode*> nodes, GraphNode* node){
      for(auto i = nodes.begin(); i != nodes.end(); i++){
        if((*i) == node){
          return false;
        }
      }
      return true;
    }

    void printGraphNodes(std::vector<GraphNode*> nodes){
        std::cout << "Nodes:\n";
        for(auto n = nodes.begin(); n != nodes.end(); n++){
            GraphNode* node = *n;
            std::cout<< " - " << node->getValue();
        }
        std::cout << "\n\n";
    }

    void printGraphNodePath(std::vector<GraphNode*> path){
        std::cout << "Path:\n";
        for(auto n = path.begin(); n != path.end(); n++){
            GraphNode* node = *n;
            std::cout<< " -> " << node->getValue();
        }
        std::cout << "\n\n";
    }
};

#endif
