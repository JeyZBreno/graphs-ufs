#include "iostream"
#include "string"
#include "Graph.h"
#include "Node.h"
#include "utils.h"
#include "ChessHorseHandler.h"

int main(int filesCount, char** file){

    ChessHorseHandler handler;

    Graph g = handler.getHorsePath();

    printLines(getNodesInfo(g.getNodes()));
    printLines(getPathInfo(g.findHamiltonianPath()));


    return 1;
}
