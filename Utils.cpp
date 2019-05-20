//
// Created by andrefmrocha on 5/20/19.
//
#include "Utils.h"


void unifyGraphs(Graph &g1, Graph &g2, Graph &g3) {
    g1.concateEdges(g2.getEdgeSet());
    g1.concateEdges(g3.getEdgeSet());
    g1.concateVertexs(g2.getVertexSet());
    g1.concateVertexs(g3.getVertexSet());
}

