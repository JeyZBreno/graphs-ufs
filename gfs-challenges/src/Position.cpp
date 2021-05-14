#include "Position.h"

Position::Position(int xValue, int yValue){
    xPos = xValue;
    yPos = yValue;
}

Position::~Position(){
}

bool Position::operator==(Position otherValue){
    return this->xValue() == otherValue.xValue() && this->yValue() == otherValue.yValue();
}

int Position::xValue(){
    return xPos;
}

int Position::yValue(){
    return yPos;
}
