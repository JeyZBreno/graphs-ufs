#include "Labyrinth.h"
#include "Position.h"
#include "Node.h"
#include "utils.h"
#include "string"
#include "fstream"
#include "iostream"

Labyrinth::Labyrinth(){
}

Labyrinth::~Labyrinth(){
}

Graph Labyrinth::transformIntoGraphFromFile(std::string fileName){
    return transformIntoGraphFromText(retrieveStringFromFile(fileName));
}

std::string Labyrinth::retrieveStringFromFile(std::string fileName){
    std::string labyrinthText;
    std::ifstream labyrinthFile(fileName);

    if (labyrinthFile.is_open()){
        std::string line;
        while (std::getline(labyrinthFile,line)){
            labyrinthText = labyrinthText + "\n" + line;
        }
        labyrinthFile.close();
    }

    return labyrinthText;
}

std::string Labyrinth::retrieveResolvedLabyrinthString(std::string fileName, std::vector<Value> resolvedPath){
    std::string file = retrieveStringFromFile(fileName);

    int line = 0;
    int column = 0;
    for(int letterIndex = 0; letterIndex < file.length(); letterIndex++){
        char currentChar = file[letterIndex];

        for(auto i = resolvedPath.begin(); i != resolvedPath.end(); i++){
            if((*i).xValue() == column && (*i).yValue() == line){
                file[letterIndex] = '+';
            }
        }

        if(currentChar == '\n'){
            line++;
            column = 0;
        }
        column++;
    }

    return file;
}

Graph Labyrinth::transformIntoGraphFromText(std::string text){
    Graph result;

    int line = 0;
    int column = 0;
    for(int letterIndex = 0; letterIndex < text.length(); letterIndex++){
        char currentChar = text[letterIndex];

        if(currentChar == '\n'){
            line++;
            column = 0;
        }
        if(currentChar == clearWay){
            result.createNode(Position(column,line));
        }
        column++;
    }

    connectGraphNodes(result);

    return result;
}

void Labyrinth::connectGraphNodes(Graph& graph){
    std::vector<Node*> nodes = graph.getNodes();
    for(auto i = nodes.begin(); i != nodes.end(); i++){
        Node* currentNode = *i;
        std::vector<Node*> currentNodeRelations = currentNode->retrieveRelations();

        std::vector<Node*> neighbors = getNeighbors(graph, currentNode->getValue());
        for(auto j = neighbors.begin(); j != neighbors.end(); j++){
            Node* neighbor = *j;
            if(neighbor != nullptr && !neighbor->isInList(currentNodeRelations)){
                currentNode->createRelation(neighbor);
            }
        }
    }
}

std::vector<Node*> Labyrinth::getNeighbors(Graph& graph, Position currentPosition){
    Node* topNode = graph.getNode(Position(currentPosition.xValue(), currentPosition.yValue() - 1));
    Node* bottomNode = graph.getNode(Position(currentPosition.xValue(), currentPosition.yValue() + 1));
    Node* leftNode = graph.getNode(Position(currentPosition.xValue() - 1, currentPosition.yValue()));
    Node* rightNode = graph.getNode(Position(currentPosition.xValue() + 1, currentPosition.yValue()));
    std::vector<Node*> result = {topNode, bottomNode, leftNode, rightNode};
    return result;
}







