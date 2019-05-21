//
// Created by andrefmrocha on 5/15/19.
//
#include "Heuristics.h"
#include <cmath>
#include <algorithm>

double euclidean_distance(Vertex *v, Vertex *w) {
    return sqrt(pow(v->getInfo().getLong() - w->getInfo().getLong(), 2)
    + pow(v->getInfo().getLat() - w->getInfo().getLat(), 2));
}

double chebyshev_distance(Vertex *v, Vertex *w) {
    return std::max((v->getInfo().getLong() - w->getInfo().getLong()),
    (v->getInfo().getLat() - w->getInfo().getLat()));
}

double manhattan_distance(Vertex *v, Vertex *w) {
    return (abs(v->getInfo().getLong() - w->getInfo().getLong()) +
    abs(v->getInfo().getLat() - w->getInfo().getLat()));
}


