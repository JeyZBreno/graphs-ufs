#include "iostream"
#include "string"
#include "Graph.h"
#include "Node.h"
#include "utils.h"
#include "ChessHorseHandler.h"

int main(int filesCount, char** file){

    ChessHorseHandler handler;

    Graph g = handler.getHorsePath();

    printNodes(g.getNodes());
    //printPath(g.findHamiltonianPath());

    std::cout << getPathInfo(g.findHamiltonianPath());

    return 1;
}
