//
// Created by andrefmrocha on 5/15/19.
//
#include "Heuristics.h"
#include <cmath>
#include <algorithm>

double euclidean_distance(Vertex *v, Vertex *w) {
    return sqrt(pow(v->getInfo().getX() - w->getInfo().getX(), 2)
    + pow(v->getInfo().getY() - w->getInfo().getY(), 2));
}

double chebyshev_distance(Vertex *v, Vertex *w) {
    return std::max((v->getInfo().getX() - w->getInfo().getX()),
    (v->getInfo().getY() - w->getInfo().getY()));
}

double manhattan_distance(Vertex *v, Vertex *w) {
    return (abs(v->getInfo().getX() - w->getInfo().getX()) +
    abs(v->getInfo().getY() - w->getInfo().getY()));
}


