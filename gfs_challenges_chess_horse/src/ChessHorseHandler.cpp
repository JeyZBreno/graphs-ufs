#include "ChessHorseHandler.h"
#include "Graph.h"
#include "Position.h"
#include "vector"

ChessHorseHandler::ChessHorseHandler(){
}

ChessHorseHandler::~ChessHorseHandler(){
}

Graph ChessHorseHandler::getChessNodes(){
    int tableSize = 5;

    Graph tableGraph;
    for(int i = 0; i < tableSize; i++){
        for(int j = 0; j < tableSize; j++){
            tableGraph.createNode(Position(i, j));
        }
    }
    return tableGraph;
}

void ChessHorseHandler::applyHorseRelationsOnNode(Graph& targetGraph, Node* currentNode){
    int currentXValue = currentNode->getValue().xValue();
    int currentYValue = currentNode->getValue().yValue();

    Node* topLeftMove = targetGraph.getNode(Position(currentXValue - 1, currentYValue + 2));
    Node* topRightMove = targetGraph.getNode(Position(currentXValue + 1, currentYValue + 2));
    Node* leftTopMove = targetGraph.getNode(Position(currentXValue - 2, currentYValue + 1));
    Node* leftBottomMove = targetGraph.getNode(Position(currentXValue - 2, currentYValue - 1));
    Node* bottomLeftMove = targetGraph.getNode(Position(currentXValue - 1 , currentYValue - 2));
    Node* bottomRightMove = targetGraph.getNode(Position(currentXValue + 1, currentYValue - 2));
    Node* rightBottomMove = targetGraph.getNode(Position(currentXValue + 2, currentYValue - 1));
    Node* rightTopMove = targetGraph.getNode(Position(currentXValue + 2, currentYValue + 1));

    std::vector<Node*> relations = {topLeftMove, topRightMove, leftTopMove, leftBottomMove, bottomLeftMove, bottomRightMove, rightBottomMove, rightTopMove};
    for(auto i = relations.begin(); i != relations.end(); i++){
        if((*i) != nullptr){
            currentNode->createRelation(*i);
        }
    }
}

Graph ChessHorseHandler::getHorsePath(){
   Graph horseGraph = getChessNodes();

   std::vector<Node*> horseNodes = horseGraph.getNodes();
   for(auto i = horseNodes.begin(); i != horseNodes.end(); i++){
        applyHorseRelationsOnNode(horseGraph, *i);
   }

   return horseGraph;
}
