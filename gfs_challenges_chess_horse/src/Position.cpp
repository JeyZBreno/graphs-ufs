#include "Position.h"
#include "string"

Position::Position(){
    xPos = 0;
    yPos = 0;
}

Position::Position(int xValue, int yValue){
    xPos = xValue;
    yPos = yValue;
}

Position::Position(const Position& toCopy){
    xPos = toCopy.xPos;
    yPos = toCopy.yPos;
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

std::string Position::toString(){
    std::string formatted = "[" + std::to_string(xPos) + "," + std::to_string(yPos) + "]";
    return formatted;
}
