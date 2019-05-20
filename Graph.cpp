//
// Created by andrefmrocha on 5/19/19.
//
#include <iostream>
#include "Graph.h"


bool Vertex::operator==(Vertex v) const {
    return this->getInfo() == v.getInfo();
}

bool Edge::operator<(Edge edge) const {
    return this->getWeight() > edge.getWeight();
}

bool Edge::operator==(Edge edge) const {
    return this->orig == edge.orig && this->dest == edge.dest && this->weight == edge.getWeight();
}

Vertex *Edge::getOrig() const {
    return orig;
}

Vertex *Edge::getDest() const {
    return dest;
}

bool Edge::isBus() const {
    return type == bus;
}

bool Edge::isSubway() const {
    return type == subway;
}

bool Edge::isOnFoot() const {
    return type == foot;
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}

vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(const Coordinates &in) const {
    for (auto v : vertexSet)
        if (v->info == in) //TODO overload operator==
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const Coordinates &in) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->info == in)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const Coordinates &in) {
    if (findVertex(in) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(in));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w) and transportation type.
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const Coordinates &sourc, const Coordinates &dest, double w,Transport type) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w,type);
    edgeSet.push_back(new Edge(v1,v2,w,type));
    return true;
}


/**************** Single Source Shortest Path algorithms ************/

/**
 * Initializes single source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
 */
Vertex * Graph::initSingleSource(const Coordinates &origin) {
    for(auto v : vertexSet) {
        v->weight = INF;
        v->path = nullptr;
        v->dist = INF;
    }
    auto s = findVertex(origin);
    s->weight = 0;
    return s;
}

/**
 * Analyzes an edge in single source shortest path algorithm.
 * Returns true if the target vertex was relaxed (dist, path).
 * Used by all single-source shortest path algorithms.
 */
inline bool Graph::relax(Vertex *v, Vertex *w, double weight) {
    if (v->weight + weight < w->weight) {
        w->weight = v->weight + weight;
        w->path = v;
        return true;
    }
    else
        return false;
}

void Graph::dijkstraShortestPath(const Coordinates &origin, const Coordinates &dest) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    while( ! q.empty() ) {
        auto v = q.extractMin();
        if(v->getInfo() == dest){
            break;
        }
        for(auto e : v->adj) {
            auto oldDist = e.dest->weight;
            if (relax(v, e.dest, e.weight)) {
                if (oldDist == INF)
                    q.insert(e.dest);
                else
                    q.decreaseKey(e.dest);
            }
        }
    }
}

vector<Coordinates> Graph::getPath(const Coordinates &origin, const Coordinates &dest) const{
    vector<Coordinates> res;
    auto v = findVertex(dest);
    if (v == nullptr || v->weight == INF) // missing or disconnected
        return res;
    for ( ; v != nullptr; v = v->path)
        res.push_back(v->info);
    reverse(res.begin(), res.end());
    return res;
}

void Graph::aStarShortestPath(const Coordinates &origin, const Coordinates &dest, double ( *heu)(Vertex *, Vertex *) ) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    while( ! q.empty() ) {
        auto v = q.extractMin();
        if(v->getInfo() == dest){
            break;
        }
        for(auto e : v->adj) {
            auto oldDist = e.dest->weight;
            if (aStarRelax(v, e.dest, e.weight, heu)) {
                if (oldDist == INF)
                    q.insert(e.dest);
                else
                    q.decreaseKey(e.dest);
            }
        }
    }
}

inline bool Graph::aStarRelax(Vertex *v, Vertex *w, double weight, double (*heu)(Vertex *, Vertex *)) {
    if (v->weight + weight + heu(v, w)< w->weight) {
        w->weight = v->weight + weight + heu(v, w);
        w->dist = v->weight + weight;
        w->path = v;
        return true;
    }
    else
        return false;
}

double Graph::getEdgeWeight(Edge e) {
    for(Edge* edge: edgeSet) {
        if(edge->getWeight()== e.getWeight() && edge->orig == e.orig && edge->dest == e.dest) {
            return e.getWeight();
        }
    }
    return -1;
}

vector<Edge*> Graph::getEdgeSet() const {
    return edgeSet;
}

Edge::Edge(Vertex *o, Vertex *d, double w,Transport type): orig(o), dest(d), weight(w), type(type) {}


double Edge::getWeight() const {
    return weight;
}

void Graph::biDirSearch(const Coordinates &origin, const Coordinates &destination) {

    Vertex* orig = findVertex(origin);
    Vertex* dest = findVertex(destination);

    if(orig == nullptr || dest == nullptr) {
        cout << "Invalid points chosen." << endl;
        return;
    }

    //may not be sufficient to check nodes visited in both searches
    for(Vertex* v: vertexSet) {
        v->visited = false;
    }

    MutablePriorityQueue<Vertex> o_que, d_que;

    Vertex* intersectV;

    o_que.insert(orig);
    orig->visited = true;
    orig->path = nullptr;

    d_que.insert(dest);
    dest->visited = true;
    dest->path = nullptr;

    while(!o_que.empty() && !d_que.empty()) {

        //threads init and run searches

        //check if searches visited the same vertex

        if(intersectV != nullptr) {

            //the path exists

        }
        break;
    }
}

void Graph::concateEdges(vector<Edge *> edges) {
    this->edgeSet.insert(this->edgeSet.end(), edges.begin(), edges.end());
}

void Graph::concateVertexs(vector<Vertex *> vertexs) {
    this->vertexSet.insert(this->vertexSet.end(), vertexs.begin(), vertexs.end());
}



//////////////////Vertex Method/////////////////////////////////////////
//Added here because compilation errors
/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
void Vertex::addEdge(Vertex *d, double w,Transport type) {
    adj.push_back(Edge(this, d, w,type));
}

Vertex::Vertex(Coordinates in): info(in) {}



bool Vertex::operator<(Vertex & vertex) const {
    return this->weight < vertex.weight;
}

Coordinates Vertex::getInfo() const {
    return this->info;
}

double Vertex::getWeight() const {
    return this->weight;
}

Vertex *Vertex::getPath() const {
    return this->path;
}
