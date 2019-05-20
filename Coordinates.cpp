//
// Created by cajo on 15-05-2019.
//

#include "Coordinates.h"

Coordinates::Coordinates(double latitude, double longitude, unsigned long idNode)
        : latitude(latitude), longitude(longitude), idNode(idNode) {}

bool Coordinates::operator==(const Coordinates &right) const {
    return this->idNode==right.idNode;
}

double Coordinates::getLat() {
    return this->latitude;
}

double Coordinates::getLong() {
    return this->longitude;
}

unsigned long Coordinates::getId() {
    return this->idNode;
}
