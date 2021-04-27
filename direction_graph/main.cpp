#include "Graph.h"
#include "GraphNode.h"
#include "Utils.h"
#include "ValueTypes.h"
#include "iostream"

int main(){
    Utils utils;

    Graph graph;

    GraphNode* i1 = graph.getNode(graph.createNode("Cueca"));
    GraphNode* i2 = graph.getNode(graph.createNode("Calca"));
    GraphNode* i3 = graph.getNode(graph.createNode("Cinto"));
    GraphNode* i4 = graph.getNode(graph.createNode("Camisa"));
    GraphNode* i5 = graph.getNode(graph.createNode("Gravata"));
    GraphNode* i6 = graph.getNode(graph.createNode("Paleto"));
    GraphNode* i7 = graph.getNode(graph.createNode("Meia"));
    GraphNode* i8 = graph.getNode(graph.createNode("Sapato"));
    GraphNode* i9 = graph.getNode(graph.createNode("Relogio"));

    i1->outboundTo(i2);
    i2->outboundTo(i3);
    i1->outboundTo(i8);
    i4->outboundTo(i5);
    i5->outboundTo(i6);
    i3->outboundTo(i6);
    i4->outboundTo(i3);
    i1->outboundTo(i8);
    i2->outboundTo(i8);
    i7->outboundTo(i8);

    utils.printGraphNodes(graph.retrieveNodes());
    utils.printGraphNodePath(graph.applyKahnAlgorithm());

	return 0;
}
