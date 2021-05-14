#ifndef POSITION_H
#define POSITION_H


class Position
{
    int xPos;
    int yPos;

    public:
        Position(int xValue, int yValue);
        virtual ~Position();
        bool operator==(Position otherValue);

        int xValue();
        int yValue();
};

#endif
