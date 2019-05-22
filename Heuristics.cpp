//
// Created by andrefmrocha on 5/15/19.
//
#include "Heuristics.h"
#include <cmath>
#include <algorithm>

double euclidean_distance(Vertex *v, Coordinates &w) {
    return sqrt(pow(v->getInfo().getX() - w.getX(), 2)
    + pow(v->getInfo().getY() - w.getY(), 2));
}

double chebyshev_distance(Vertex *v, Coordinates &w) {
    return std::max((v->getInfo().getX() - w.getX()),
    (v->getInfo().getY() - w.getY()));
}

double manhattan_distance(Vertex *v, Coordinates &w) {
    return (abs(v->getInfo().getX() - w.getX()) +
    abs(v->getInfo().getY() - w.getY()));
}


