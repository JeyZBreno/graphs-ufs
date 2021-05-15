#ifndef NODE_H
#define NODE_H

#include "stdio.h"
#include "vector"
#include "Typedef.h"

class Node{
    Value val;
    std::vector<Node*> relations;

    public:
        Node(Value val);
        virtual ~Node();

        Value getValue();

        void createRelation(Node* to);

        void notifyRelationCreated(Node* from);

        void notifyDeletion(Node* deletedNode);

        std::vector<Node*> retrieveRelations();

        bool isInList(std::vector<Node*> targed);
};

#endif
