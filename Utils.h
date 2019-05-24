//
// Created by andrefmrocha on 5/20/19.
//

#ifndef MIEIC_CAL_PROJ_UTILS_H
#define MIEIC_CAL_PROJ_UTILS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstring>
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
 * @param outfile stream where the information will be outputted
 */
void csv_writer(const pair<int, double> &values, ofstream & outfile);

Graph loadGraph(std::string city);

Graph loadPedestrian(std::string edgesPath, std::string nodesPath);
Graph loadBus(std::string edgesPath, std::string nodesPath, const Graph &pedGraph);
Graph loadSubway(std::string edgesPath, std::string nodesPath, const Graph &pedGraph);

double haversine(const Coordinates &source, const Coordinates &dest, const Graph &graph);
double euclidean(const Coordinates &source, const Coordinates &dest, const Graph &graph);
double toRadians(double degrees);


#endif //MIEIC_CAL_PROJ_UTILS_H
