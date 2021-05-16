#ifndef CHESSHORSEHANDLER_H
#define CHESSHORSEHANDLER_H

#include "Graph.h"

class ChessHorseHandler
{
    Graph getChessNodes();

    void applyHorseRelationsOnNode(Graph& targetGraph, Node* currentNode);

    public:
        ChessHorseHandler();
        virtual ~ChessHorseHandler();

        Graph getHorsePath();
};

#endif
