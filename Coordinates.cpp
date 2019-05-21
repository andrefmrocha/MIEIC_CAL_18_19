//
// Created by cajo on 15-05-2019.
//

#include "Coordinates.h"

Coordinates::Coordinates(double y, double x, unsigned long idNode)
        : y(y), x(x), idNode(idNode) {}

bool Coordinates::operator==(const Coordinates &right) const {
    return this->idNode==right.idNode;
}

double Coordinates::getY() {
    return this->y;
}

double Coordinates::getX() {
    return this->x;
}

unsigned long Coordinates::getId() {
    return this->idNode;
}
