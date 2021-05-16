#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "Graph.h"
#include "Node.h"
#include "string"


class Labyrinth
{
    static const char clearWay = ' ', wall = '#';

    void connectGraphNodes(Graph& graph);

    std::vector<Node*> getNeighbors(Graph& graph, Position currentPosition);

    public:
        Labyrinth();
        virtual ~Labyrinth();

        Graph transformIntoGraphFromFile(std::string fileName);

        Graph transformIntoGraphFromText(std::string text);
};

#endif
