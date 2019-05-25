//
// Created by cajo on 15-05-2019.
//

#include "Coordinates.h"

Coordinates::Coordinates(double y, double x, unsigned long idNode)
        : y(y), x(x), idNode(idNode) {}

bool Coordinates::operator==(const Coordinates &right) const {
    return this->idNode==right.idNode;
}

double Coordinates::getY() const  {
    return this->y;
}

double Coordinates::getX() const {
    return this->x;
}

unsigned long Coordinates::getId() const  {
    return this->idNode;
}

Coordinates::Coordinates(unsigned long idNode) : Coordinates(0,0,idNode) {
}
