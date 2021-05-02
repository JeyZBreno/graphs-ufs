#include "GraphNode.h"
#include "Graph.h"
#include "vector"
#include "iostream"
#include "utils.h"

std::vector<GraphNode*> Graph::retrieveNodes(){
    return nodes;
}

GraphNode* Graph::getNode(NodeValue value){
	for(int i = 0; i < nodes.size(); i++){
		if(nodes[i]->getValue() == value){
			return nodes[i];
		}
	}
	return nullptr;
}

NodeValue Graph::createNode(NodeValue value){
	GraphNode* result = getNode(value);
	if(result == nullptr){
		nodes.push_back(new GraphNode(value));
		return nodes.back()->getValue();
	}
	else{
		return result->getValue();
	}
}

std::vector<GraphNode*> Graph::retrieveNodesWithoutIncomingArrows(){
    std::vector<GraphNode*> noInboundNodes;
    for(auto i = nodes.begin(); i!= nodes.end(); i++){
        GraphNode* node = *i;

        if(node->inboundNodes().size() == 0){
            noInboundNodes.push_back(node);
        }
    }
    return noInboundNodes;
}

std::vector<GraphNode*> Graph::applyKahnAlgorithm(){
    Utils utils;
    std::vector<GraphNode*> remainingNodes = retrieveNodesWithoutIncomingArrows();
    std::vector<GraphNode*> nodePath;

    while(remainingNodes.size() != 0){
        GraphNode* retrievedNode = remainingNodes[0];
        remainingNodes = utils.removeNodeFrom(remainingNodes, retrievedNode);
        nodePath.push_back(retrievedNode);

        std::vector<GraphNode*> oubound = retrievedNode->outboundNodes();
        for(auto a = oubound.begin(); a != oubound.end(); a++){
            GraphNode* targetNode = *a;
            retrievedNode->removeOutboundArrow(targetNode);
            std::vector<GraphNode*> inbound = targetNode->inboundNodes();

            if(inbound.empty()){
                remainingNodes.push_back(targetNode);
            }
        }
    }

    if(remainingNodes.size() != 0){
        std::cout << "Error - Has a cycle\n";
    }
    else{
        return nodePath;
    }
}


























