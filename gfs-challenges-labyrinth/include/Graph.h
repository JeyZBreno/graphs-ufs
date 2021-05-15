#ifndef GRAPH_H
#define GRAPH_H

#include "vector"
#include "Node.h"

class Graph{
    std::vector<Node*> nodes;

    std::vector<Node*> tryToFindBiggestPathFrom(Node* currentNode, std::vector<Node*> previousPath);

    std::vector<Node*> tryToFindPath(Node* fromNode, Node* currentNode, std::vector<Node*> previousPath);

    Graph createSubGraph(std::vector<Node*> subGraphNodes);

    public:
        Graph();
        virtual ~Graph();

        std::vector<Node*> getNodes();

        void removeNode(Value nodeValue);

        Node* createNode(Value nodeValue);

        Node* getNode(Value nodeValue);

        std::vector<Node*> findHamiltonianPath();

        std::vector<Value> depthSearch(Node* from, Node* to);

        std::vector<Value> widthSearch(Node* from, Node* to);
};

#endif
