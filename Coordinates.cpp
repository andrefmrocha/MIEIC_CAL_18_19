//
// Created by cajo on 15-05-2019.
//

#include "Coordinates.h"

Coordinates::Coordinates(double latitude, double longitude, unsigned long idNode)
        : latitude(latitude), longitude(longitude), idNode(idNode) {}

bool Coordinates::operator==(Coordinates right) {
    return this->latitude==right.latitude && this->longitude==right.longitude;
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
