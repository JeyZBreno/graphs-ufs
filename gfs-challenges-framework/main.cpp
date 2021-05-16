#include "iostream"
#include "string"
#include "Graph.h"
#include "Node.h"
#include "utils.h"

int main(int filesCount, char** file){

    // The kite graph
    Graph g = Graph();
    Node* n1 = g.createNode(1);
    Node* n2 = g.createNode(2);
    Node* n3 = g.createNode(3);
    Node* n4 = g.createNode(4);
    Node* n5 = g.createNode(5);
    Node* n6 = g.createNode(6);
    Node* n7 = g.createNode(7);
    Node* n8 = g.createNode(8);

    n1->createRelation(n7);
    n1->createRelation(n6);
    n7->createRelation(n2);
    n6->createRelation(n2);
    n7->createRelation(n5);
    n6->createRelation(n5);
    n5->createRelation(n4);
    n4->createRelation(n3);
    n2->createRelation(n8);

    printLines(getPathInfo(g.findHamiltonianPath()));
    printLines(getPathInfo(g.widthSearch(n1, n8)));

    return 1;
}
