#include "iostream"
#include "string"
#include "Graph.h"
#include "Node.h"
#include "utils.h"
#include "Labyrinth.h"
#include "Position.h"

int main(int filesCount, char** file){

    Labyrinth lab = Labyrinth();
    Graph result = lab.transformIntoGraphFromFile("L1.txt");

    Node* entrance = result.getNode(Position(2,1));
    Node* exit = result.getNode(Position(21,20));

    std::vector<std::string> resultFileContent;

    resultFileContent.push_back("Depth search result: \n\n");
    std::vector<Value> depthSearchResult = result.depthSearch(entrance, exit);
    std::cout << "Depth search size: " << depthSearchResult.size() << "\n\n";

    resultFileContent = joinVectors(resultFileContent, getPathInfo(depthSearchResult));

    resultFileContent.push_back("Width search result: \n\n");
    std::vector<Value> widthSearchResult = result.widthSearch(entrance, exit);
    std::cout << "Width search size: " << widthSearchResult.size() << "\n\n";

    resultFileContent = joinVectors(resultFileContent, getPathInfo(widthSearchResult));

    makeFile("L1-output", resultFileContent);

    return 1;
}
