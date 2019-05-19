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

    static int calculateCoord(int maxScreen, double maxCoords, double coord);
    static int getEdgeId(int oriID, int destID);
public:
    GraphicalInterface(int width, int height);

    void showPath(std::deque<Edge*> path);
};


#endif //MIEIC_CAL_PROJ_GRAPHICALINTERFACE_H
