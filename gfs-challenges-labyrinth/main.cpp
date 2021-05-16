#include "iostream"
#include "string"
#include "Graph.h"
#include "Node.h"
#include "utils.h"
#include "Labyrinth.h"
#include "Position.h"

int main(int filesCount, char** file){

    Labyrinth lab = Labyrinth();
    Graph result = lab.transformIntoGraphFromFile("L4.txt");

    Node* entrance = result.getNode(Position(4,1));
    Node* exit = result.getNode(Position(151,150));

    std::vector<Value> depthSearchResult = result.depthSearch(entrance, exit);
    std::cout << "Depth search size: " << depthSearchResult.size() << "\n\n";
    printPath(depthSearchResult);

    std::vector<Value> widthSearchResult = result.widthSearch(entrance, exit);
    std::cout << "Width search size: " << widthSearchResult.size() << "\n\n";
    printPath(widthSearchResult);

    return 1;
}
