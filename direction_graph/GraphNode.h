#ifndef GN_H
#define GN_H 1

#include<vector>
#include "ValueTypes.h"

class GraphNode{
	NodeValue value;
	std::vector<GraphNode*> inbound;
	std::vector<GraphNode*> outbound;


public:
    GraphNode(NodeValue passedValue){
	    value = passedValue;
	}

	~GraphNode(){
	    for(auto i = outbound.begin(); i != outbound.end(); i++){
            removeOutboundArrow(*i);
	    }
	    for(auto i = inbound.begin(); i != inbound.end(); i++){
            (*i)->removeOutboundArrow(this);
	    }
	}

	NodeValue getValue();

	void notifyInbound(GraphNode* from);

	void outboundTo(GraphNode* to);

	void removeOutboundArrow(GraphNode* to);

	void notifyRemoval(GraphNode* from);

	std::vector<GraphNode*> inboundNodes();

	std::vector<GraphNode*> outboundNodes();
};

#endif
