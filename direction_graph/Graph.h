#ifndef G_H
#define G_H 1

#include<vector>
#include "GraphNode.h"

class Graph{
    std::vector<GraphNode*> nodes;
    std::vector<GraphNode*> retrieveNodesWithoutIncomingArrows();

    public:

    NodeValue createNode(NodeValue value);
    GraphNode* getNode(NodeValue value);

    std::vector<GraphNode*> applyKahnAlgorithm();
    std::vector<GraphNode*> retrieveNodes();
};

#endif
