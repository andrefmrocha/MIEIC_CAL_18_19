//
// Created by andrefmrocha on 5/15/19.
//

#ifndef MIEIC_CAL_PROJ_HEURISTICS_H
#define MIEIC_CAL_PROJ_HEURISTICS_H

#include "Graph.h"

double euclidean_distance(const Vertex *v, const Coordinates &w);

double chebyshev_distance(const Vertex *v, const Coordinates &w);

double manhattan_distance(const Vertex *v, const Coordinates &w);


#endif //MIEIC_CAL_PROJ_HEURISTICS_H
