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

int GraphicalInterface::calculateCoord(int maxScreen, double maxCoords, double coord){
    return (int)((maxScreen * coord)/(double)maxCoords);
}

int GraphicalInterface::getEdgeId() {
    return id;
}


void GraphicalInterface::showPath(std::deque<Edge*> path) {
    gv->createWindow(this->width, this->height);
    double lat = 0;
    double longi = 0;
    for(Edge* edge: path){
        if(edge->getOrig()->getInfo().getLat() > lat){
            lat = edge->getOrig()->getInfo().getLat();
        }
        if(edge->getOrig()->getInfo().getLong() > longi){
            longi = edge->getOrig()->getInfo().getLong();
        }
    }

    for(Edge* edge: path){
        Vertex * ori = edge->getOrig();
        this->gv->addNode(ori->getInfo().getId(),
                this->calculateCoord(this->width, longi, ori->getInfo().getLong()),
                this->calculateCoord(this->height, lat, ori->getInfo().getLat())
                        );
        Vertex * dest = edge->getDest();
        this->gv->addNode(dest->getInfo().getId(),
                          this->calculateCoord(this->width, longi, dest->getInfo().getLong()),
                          this->calculateCoord(this->height, lat, dest->getInfo().getLat())
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
        sleep(1);
    }

}

void GraphicalInterface::incrementEdgeId() {
    this->id++;
}
