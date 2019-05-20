//
// Created by andrefmrocha on 5/20/19.
//
#include <fstream>
#include "Utils.h"


void unifyGraphs(Graph &g1, Graph &g2, Graph &g3) {
    g1.concateEdges(g2.getEdgeSet());
    g1.concateEdges(g3.getEdgeSet());
    g1.concateVertexs(g2.getVertexSet());
    g1.concateVertexs(g3.getVertexSet());
}

void csv_writer(const vector<pair<int, int>> &values, const string& filename) {
    ofstream outfile(filename);
    outfile << "V+E" << "," << "time(ms)" << endl;
    for (auto i: values){
        outfile << i.first << "," << i.second << endl;
    }
    outfile.close();
}

