#include "vector"
#include "GraphNode.h"
#include "ValueTypes.h"
#include "Utils.h"


NodeValue GraphNode::getValue(){
    return value;
}

void GraphNode::notifyInbound(GraphNode* from){
    Utils utils;
    if(utils.nodeNotIn(inbound, this)){
        inbound.push_back(from);
    }
}

void GraphNode::outboundTo(GraphNode* to){
    to->notifyInbound(this);
    outbound.push_back(to);
}

void GraphNode::removeOutboundArrow(GraphNode* to){
    Utils utils;
    to->notifyRemoval(this);
    utils.removeNodeFrom(outbound, to);
}

void GraphNode::notifyRemoval(GraphNode* from){
    Utils utils;
    utils.removeNodeFrom(inbound, from);
}

std::vector<GraphNode*> GraphNode::inboundNodes(){
    return inbound;
}

std::vector<GraphNode*> GraphNode::outboundNodes(){
    return outbound;
}
