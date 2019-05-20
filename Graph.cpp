//
// Created by andrefmrocha on 5/19/19.
//
#include <iostream>
#include "Graph.h"
#include <future>


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
    this->visited = vector<bool> (this->vertexSet.size(), false);
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

void Graph::dijkstraShortestPath(const Coordinates &origin, const Coordinates &dest, double & time_elapsed) {
    clock_t begin = clock();
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    while( ! q.empty() ) {
        auto v = q.extractMin();
        if(v->getInfo() == dest){
            break;
        }
        dijkstraStep(q, v);
    }
    clock_t end = clock();
    time_elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
}

void Graph::dijkstraStep(MutablePriorityQueue<Vertex> &q, Vertex *v) {
    this->visited[distance(this->vertexSet.end(), find(this->vertexSet.begin(), this->vertexSet.end(), v))] = true;
    for (auto e : v->adj) {
        auto oldDist = e.dest->weight;
        if (relax(v, e.dest, e.weight)) {
            if (oldDist == INF)
                q.insert(e.dest);
            else
                q.decreaseKey(e.dest);
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

void Graph::aStarShortestPath(const Coordinates &origin, const Coordinates &dest, double ( *heu)(Vertex *, Vertex *),
                              double & time_elapsed ) {
    clock_t begin = clock();
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    while( ! q.empty() ) {
        auto v = q.extractMin();
        if(v->getInfo() == dest){
            break;
        }
        aStarStep(heu, q, v);
    }
    clock_t end = clock();
    time_elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
}

void Graph::aStarStep(double (*heu)(Vertex *, Vertex *), MutablePriorityQueue<Vertex> &q, Vertex *v)  {
    this->visited[distance(this->vertexSet.end(), find(this->vertexSet.begin(), this->vertexSet.end(), v))] = true;
    for (auto e : v->adj) {
        auto oldDist = e.dest->weight;
        if (aStarRelax(v, e.dest, e.weight, heu)) {
            if (oldDist == INF)
                q.insert(e.dest);
            else
                q.decreaseKey(e.dest);
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

Transport Edge::getType() const {
    return type;
}

void Graph::biDirSearch(const Coordinates &origin, const Coordinates &destination,
double & time_elapsed) {
    clock_t begin = clock();
    Graph inverted = this->invertGraph();

    Vertex* orig = findVertex(origin);
    Vertex* dest = findVertex(destination);

    if(orig == nullptr || dest == nullptr) {
        cout << "Invalid points chosen." << endl;
        return;
    }

    this->initSingleSource(origin);
    inverted.initSingleSource(origin);

    MutablePriorityQueue<Vertex> originalQ, invertedQ;

    Vertex* intersectV;

    originalQ.insert(orig);
    orig->visited = true;
    orig->path = nullptr;

    invertedQ.insert(dest);
    dest->visited = true;
    dest->path = nullptr;

    while(!originalQ.empty() && !invertedQ.empty()) {

        //threads init and run searches
        auto f1 = async([this, &originalQ] {
            this->dijkstraStep(originalQ, originalQ.extractMin());
        });

        auto f2 = async([&inverted, &invertedQ]{
           inverted.dijkstraStep(invertedQ, invertedQ.extractMin());
        });

        //check if searches visited the same vertex
        f1.get();
        f2.get();

        intersectV = isIntersecting(this->getVisited(), inverted.getVisited());

        if(intersectV != nullptr) {
            // TODO: Rebuild the path

            break;
        }
    }
    clock_t end = clock();
    time_elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
}

void Graph::concateEdges(vector<Edge *> edges) {
    this->edgeSet.insert(this->edgeSet.end(), edges.begin(), edges.end());
}

void Graph::concateVertexs(vector<Vertex *> vertexs) {
    this->vertexSet.insert(this->vertexSet.end(), vertexs.begin(), vertexs.end());
}

Graph Graph::invertGraph() {
    Graph inverted;
    for(auto i: this->getVertexSet()){
        inverted.addVertex(i->getInfo());
    }
    for(auto i: this->getEdgeSet()){
        inverted.addEdge(i->getDest()->getInfo(), i->getOrig()->getInfo(), i->getWeight(), i->getType());
    }
    return inverted;
}

const vector<bool> &Graph::getVisited() const {
    return visited;
}

Vertex *Graph::isIntersecting(const vector<bool> &visited1, const vector<bool> &visited2) {
    for(int i = 0; i < visited1.size(); i++){
        if(visited1[i] && visited2[i])
            return this->vertexSet[i];
    }
    return nullptr;
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
