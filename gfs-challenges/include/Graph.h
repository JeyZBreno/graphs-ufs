#ifndef GRAPH_H
#define GRAPH_H

#import "vector"
#import "Node.h"

class Graph{
    std::vector<Node*> nodes;

    std::vector<Node*> tryToFindBiggestPathFrom(Node* currentNode, std::vector<Node*> previousPath);

    public:
        Graph();
        virtual ~Graph();

        std::vector<Node*> getNodes();

        void removeNode(Value nodeValue);

        Node* createNode(Value nodeValue);

        Node* getNode(Value nodeValue);

        std::vector<Node*> findHamiltonianPath();
};

#endif
