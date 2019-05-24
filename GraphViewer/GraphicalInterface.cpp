//
// Created by andrefmrocha on 5/19/19.
//

#include "GraphicalInterface.h"


GraphicalInterface::GraphicalInterface(int width, int height) {
    this->gv = new GraphViewer(width, height, false);
    this->width = width;
    this->height = width;
    this->id = 0;
}

double GraphicalInterface::calculateX(double coord, double min, double med) {
    return coord - min - med + this->width/2;
}

double GraphicalInterface::calculateY(double coord, double min, double med) {
    return -coord + min + med + this->height/2;
}


int GraphicalInterface::getEdgeId() {
    return id;
}


void GraphicalInterface::showPath(std::deque<Edge*> path) {
    gv->createWindow(this->width, this->height);
    double minY = INF;
    double minX = INF;
    double maxY = 0;
    double maxX = 0;
    for(Edge* edge: path){
        if(edge->getOrig()->getInfo().getY() < minY){
            minY = edge->getOrig()->getInfo().getY();
        }
        if(edge->getOrig()->getInfo().getX() < minX){
            minX = edge->getOrig()->getInfo().getX();
        }
        if(edge->getOrig()->getInfo().getY() > maxY){
            maxY = edge->getOrig()->getInfo().getY();
        }
        if(edge->getOrig()->getInfo().getX() > maxX){
            maxX = edge->getOrig()->getInfo().getX();
        }
    }

    double medY = (maxY - minY) / 2.0;
    double medX = (maxX - minX) / 2.0;
    for(Edge* edge: path){
        Vertex * ori = edge->getOrig();
        this->gv->addNode(ori->getInfo().getId(),
                          calculateX(ori->getInfo().getX(), minX, medX),
                          calculateY(ori->getInfo().getY(), minY, medY)
                        );
        Vertex * dest = edge->getDest();
        this->gv->addNode(dest->getInfo().getId(),
                          calculateX(ori->getInfo().getX(), minX, medX),
                          calculateY(ori->getInfo().getY(), minY, medY)
                          );
        // TODO: Hashing the ID's?
        this->gv->addEdge(this->getEdgeId(),
                ori->getInfo().getId(),
                dest->getInfo().getId(),
                EdgeType::DIRECTED);
        if(edge->isBus()){
            this->gv->setVertexColor(ori->getInfo().getId(), BLUE);
            this->gv->setVertexColor(dest->getInfo().getId(), BLUE);
            this->gv->setEdgeColor(this->getEdgeId(), BLUE);
        } else if(edge->isSubway()){
            this->gv->setVertexColor(ori->getInfo().getId(), YELLOW);
            this->gv->setVertexColor(dest->getInfo().getId(), YELLOW);
            this->gv->setEdgeColor(this->getEdgeId(), YELLOW);
        } else {
            this->gv->setVertexColor(ori->getInfo().getId(), GREEN);
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
