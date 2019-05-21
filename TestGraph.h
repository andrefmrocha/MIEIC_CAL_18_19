//
// Created by andrefmrocha on 5/20/19.
//

#ifndef MIEIC_CAL_PROJ_TESTGRAPH_H
#define MIEIC_CAL_PROJ_TESTGRAPH_H
#include <random>
#include "Graph.h"
#include "GraphViewer/GraphicalInterface.h"


void generateBusRoute1(Graph &g);

void generateBusRoute2(Graph &g);

void generateBusRoute3(Graph &g);

void generateMetroLineA(Graph &g);

void generateMetroLineB(Graph &g);

void generateBusRouteGraph(Graph &g,int n);

void generateMetroLinesGraph(Graph &g,int n);

void generateTransportGraph(int n, Graph &ped, Graph &bus, Graph &metro);


#endif //MIEIC_CAL_PROJ_TESTGRAPH_H
