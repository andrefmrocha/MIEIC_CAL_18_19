//
// Created by andrefmrocha on 5/19/19.
//

#include "GraphicalInterface.h"

#define MAP_BACKGROUND "T11/Porto/map.png"


GraphicalInterface::GraphicalInterface(int width, int height) {
    this->width = width;
    this->height = height;
    this->maxX = 0;
    this->maxY = 0;
    this->minX = 0;
    this->minY = 0;
    this->id = 0;
}

void GraphicalInterface::setMapBounds(const Coordinates &maxCoord, const Coordinates &minCoord) {
    this->maxX = maxCoord.getX();
    this->maxY = maxCoord.getY();
    this->minX = minCoord.getX();
    this->minY = minCoord.getY();
}

double GraphicalInterface::calculateX(double coord) {
    if ((maxX - minX) == 0)
        return coord * PRECISION;
    else
        return (coord * PRECISION - minX * PRECISION) / ((maxX - minX) * PRECISION / width);
}

double GraphicalInterface::calculateY(double coord) {
    if ((maxY - minY) == 0)
        return -coord * PRECISION;
    else
        return ((-coord * PRECISION + minY * PRECISION) + (maxY - minY) * PRECISION) /
               ((maxY - minY) * PRECISION / height);
}


int GraphicalInterface::getEdgeId() {
    return id;
}


void GraphicalInterface::showPath(std::deque<Edge *> path) {
    this->gv = new GraphViewer(width, height, false);
    gv->setBackground(MAP_BACKGROUND);
    gv->createWindow(this->width, this->height);

    for (Edge *edge: path) {
        Vertex *ori = edge->getOrig();
        this->gv->addNode(ori->getInfo().getId(),
                          calculateX(ori->getInfo().getX()),
                          calculateY(ori->getInfo().getY())
        );
        Vertex *dest = edge->getDest();
        this->gv->addNode(dest->getInfo().getId(),
                          calculateX(ori->getInfo().getX()),
                          calculateY(ori->getInfo().getY())
        );
        // TODO: Hashing the ID's?
        this->gv->addEdge(this->getEdgeId(),
                          ori->getInfo().getId(),
                          dest->getInfo().getId(),
                          EdgeType::DIRECTED);


        if (ori->isStartPoint()) {
            this->gv->setVertexColor(ori->getInfo().getId(), WHITE);
        }
        if (dest->isEndPoint()) {
            this->gv->setVertexColor(dest->getInfo().getId(), BLACK);
        }
        if (ori->isMiddlePoint()) {
            this->gv->setVertexColor(ori->getInfo().getId(), RED);
        }
        if (dest->isMiddlePoint()) {
            this->gv->setVertexColor(dest->getInfo().getId(), RED);
        }

        if (edge->isBus()) {
            if(!ori->isCheckpoint())
                this->gv->setVertexColor(ori->getInfo().getId(), BLUE);
            if(!dest->isCheckpoint())
                this->gv->setVertexColor(dest->getInfo().getId(), BLUE);
            this->gv->setEdgeColor(this->getEdgeId(), BLUE);
        } else if (edge->isSubway()) {
            if(!ori->isCheckpoint())
                this->gv->setVertexColor(ori->getInfo().getId(), YELLOW);
            if(!dest->isCheckpoint())
                this->gv->setVertexColor(dest->getInfo().getId(), YELLOW);
            this->gv->setEdgeColor(this->getEdgeId(), YELLOW);
        } else {
            if(!ori->isCheckpoint())
                this->gv->setVertexColor(ori->getInfo().getId(), GREEN);
            if(!dest->isCheckpoint())
                this->gv->setVertexColor(dest->getInfo().getId(), GREEN);
            this->gv->setEdgeColor(this->getEdgeId(), GREEN);
        }

        this->gv->rearrange();
        this->incrementEdgeId();
        //sleep(1);
    }

}

void GraphicalInterface::incrementEdgeId() {
    this->id++;
}
