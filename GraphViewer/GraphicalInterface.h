//
// Created by andrefmrocha on 5/19/19.
//

#ifndef MIEIC_CAL_PROJ_GRAPHICALINTERFACE_H
#define MIEIC_CAL_PROJ_GRAPHICALINTERFACE_H

#include <deque>
#include "../Graph.h"
#include "graphviewer.h"
#define PRECISION 10e9

class GraphicalInterface {
    GraphViewer *gv;
    int width;
    int height;
    int id;
    double maxX;
    double maxY;
    double minX;
    double minY;

    double calculateX(double coord);

    double calculateY(double coord);

    int getEdgeId();

    void incrementEdgeId();

public:
    GraphicalInterface(int width, int height);
    void setMapBounds(const Coordinates &maxCoord , const Coordinates &minCoord);

    void showPath(std::deque<Edge *> path);
};


#endif //MIEIC_CAL_PROJ_GRAPHICALINTERFACE_H
