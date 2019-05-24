//
// Created by andrefmrocha on 5/19/19.
//

#ifndef MIEIC_CAL_PROJ_GRAPHICALINTERFACE_H
#define MIEIC_CAL_PROJ_GRAPHICALINTERFACE_H

#include <deque>
#include "../Graph.h"
#include "graphviewer.h"

class GraphicalInterface {
    GraphViewer * gv;
    int width;
    int height;
    int id;

    double calculateX(double coord, double min, double med);
    double calculateY(double coord, double min, double med);
    int getEdgeId();
    void incrementEdgeId();
public:

    GraphicalInterface(int width, int height);

    void showPath(std::deque<Edge*> path);
};


#endif //MIEIC_CAL_PROJ_GRAPHICALINTERFACE_H
