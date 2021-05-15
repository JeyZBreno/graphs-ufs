#ifndef POSITION_H
#define POSITION_H

#include "string"


class Position
{
    int xPos;
    int yPos;

    public:
        // contructors
        Position();
        Position(int xValue, int yValue);
        Position(const Position& toCopy);

        virtual ~Position();
        bool operator==(Position otherValue);

        int xValue();
        int yValue();

        std::string toString();
};

#endif
