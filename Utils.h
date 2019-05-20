//
// Created by andrefmrocha on 5/20/19.
//

#ifndef MIEIC_CAL_PROJ_UTILS_H
#define MIEIC_CAL_PROJ_UTILS_H

#include "Graph.h"

/**
 * @brief Unification of three different graphs
 * @param g1 - first graph and where all information is stored
 * @param g2 - second graph
 * @param g3 - third graph
 */
void unifyGraphs(Graph &g1, Graph &g2, Graph &g3);

/**
 *
 *
 * @param values pair where the first value is the number of vertexs + edges of the graph used
 * @param filename - the name of the file to save this information
 */
void csv_writer(const vector<pair<int, int>> &values, const string& filename);


#endif //MIEIC_CAL_PROJ_UTILS_H
