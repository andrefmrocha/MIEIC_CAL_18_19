//
// Created by andrefmrocha on 5/15/19.
//
#include "Heuristics.h"
#include <cmath>
#include <algorithm>

double euclidean_distance(const Vertex *v, const Coordinates &w) {
    return sqrt(pow(v->getInfo().getX() - w.getX(), 2)
    + pow(v->getInfo().getY() - w.getY(), 2));
}

double chebyshev_distance(const Vertex *v, const Coordinates &w) {
    return std::max((v->getInfo().getX() - w.getX()),
    (v->getInfo().getY() - w.getY()));
}

double manhattan_distance(const Vertex *v, const Coordinates &w) {
    return (abs(v->getInfo().getX() - w.getX()) +
    abs(v->getInfo().getY() - w.getY()));
}


