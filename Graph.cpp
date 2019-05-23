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
    edgeSet.push_back(v1->adj[v1->adj.size()-1]);
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
        v->predecessor = nullptr;
    }
    auto s = findVertex(origin);
    s->weight = 0;
    s->visited = true;
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
        w->visited = true;

        return true;
    }
    else
        return false;
}

void Graph::dijkstraShortestPath(const Coordinates &origin, const Coordinates &dest, double &time_elapsed) {
    auto start = chrono::steady_clock::now();
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    int i = 0;
    while( ! q.empty() ) {
        auto v = q.extractMin();
        if(v->getInfo() == dest){
            cout << "Num of iterations " << i << " " << this->vertexSet.size() << endl;
            break;
        }
        dijkstraStep(q, v);
        i++;
    }
    auto end = chrono::steady_clock::now();
    time_elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void Graph::dijkstraStep(MutablePriorityQueue<Vertex> &q, Vertex *v) {
    if(isInverted) {
        v = findVertex(v->getInfo()); // do this only if its inverted graph
    }

    this->visited[distance(this->vertexSet.begin(),find(this->vertexSet.begin(), this->vertexSet.end(), v))] = true;
    for (auto e : v->adj) {
        if (relax(v, e->dest, e->weight)) {
            e->dest->predecessor = e;
            if (!q.find(e->dest))
                q.insert(e->dest);
            else
                q.decreaseKey(e->dest);
        }
    }
}

void Graph::getPath(const Coordinates &origin, const Coordinates &dest, vector<Coordinates> &coords, deque<Edge *> &edges, bool isInverted) const{
    vector<Coordinates> c;
    auto v = findVertex(dest);
    if (v == nullptr || v->weight == INF) // missing or disconnected
        return;
    if( isInverted) {
        for( ; v != nullptr && v->predecessor != nullptr; v = v->path) {
            coords.push_back(v->info);
            edges.push_back(v->predecessor->invertEdge());
        }
        coords.push_back(v->info);
    }
    else {
        for( ; v != nullptr && v->predecessor != nullptr; v = v->path) {
            c.push_back(v->info);
            edges.push_front(v->predecessor);
        }
        c.push_back(v->info);
        reverse(c.begin(), c.end());
        coords.insert(coords.end(),c.begin(),c.end());
    }
}

void Graph::aStarShortestPath(const Coordinates &origin, const Coordinates &dest, double ( *heu)(const Vertex *, const Coordinates &), double &time_elapsed) {
    auto start = chrono::steady_clock::now();
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    int i = 0;
    while( ! q.empty() ) {
        auto v = q.extractMin();
        v->visited = true;
        if(v->getInfo() == dest){
            cout << "Num of iterations " << i << " " << this->vertexSet.size() << endl;
            break;
        }
        aStarStep(heu, q, v, dest);
        i++;
    }
    auto end = chrono::steady_clock::now();
    time_elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void Graph::aStarStep(double (*heu)(const Vertex *, const Coordinates &), MutablePriorityQueue<Vertex> &q,
                      Vertex *origin, const Coordinates &dest)  {
    if(isInverted) {
        origin = findVertex(origin->getInfo()); // do this only if its inverted graph
    }

    this->visited[distance(this->vertexSet.begin(), find(this->vertexSet.begin(), this->vertexSet.end(), origin))] = true;
    for (auto e : origin->adj) {
        if (aStarRelax(origin, e->dest, e->weight, heu, dest)) {
            e->dest->predecessor = e;
            if (!q.find(e->dest))
                q.insert(e->dest);
            else
                q.decreaseKey(e->dest);
        }
    }
}

inline bool Graph::aStarRelax(Vertex *v, Vertex *w, double weight, double (*heu)(const Vertex *, const Coordinates &),
                              const Coordinates &dest) {
    if (v->weight + weight + heu(w, dest)< w->weight) {
        w->weight = v->weight + weight + heu(v, dest);
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

Edge *Edge::invertEdge() {
    return new Edge(this->dest,this->orig,this->weight,this->type);
}

void Graph::biDirDijkstra(const Coordinates &origin, const Coordinates &destination, double &time_elapsed,
                          vector<Coordinates> &coordsPath, deque<Edge *> &edgesPath) {
    auto start = chrono::steady_clock::now();
    Graph inverted = this->invertGraph();

    Vertex* orig = findVertex(origin);
    Vertex* dest = findVertex(destination);

    if(orig == nullptr || dest == nullptr) {
        cout << "Invalid points chosen." << endl;
        return;
    }

    this->initSingleSource(origin);
    inverted.initSingleSource(destination);

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
            this->getPath(origin, intersectV->getInfo(), coordsPath, edgesPath, false);
            inverted.getPath(destination, intersectV->getInfo(), coordsPath, edgesPath, true);
            break;
        }
    }
    auto end = chrono::steady_clock::now();
    time_elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void Graph::biDirAstar(const Coordinates &origin, const Coordinates &destination,
                       double (*heu)(const Vertex *, const Coordinates &), double &time_elapsed,
                       vector<Coordinates> &coordsPath,
                       deque<Edge *> &edgePath) {
                           auto start = chrono::steady_clock::now();
    Graph inverted = this->invertGraph();

    Vertex* orig = findVertex(origin);
    Vertex* dest = findVertex(destination);

    if(orig == nullptr || dest == nullptr) {
        cout << "Invalid points chosen." << endl;
        return;
    }

    this->initSingleSource(origin);
    inverted.initSingleSource(destination);

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
        auto f1 = async([this, &originalQ,heu, destination] {
            Coordinates dest = destination;
            aStarStep(heu,originalQ,originalQ.extractMin(), dest);
        });

        auto f2 = async([&inverted, &invertedQ,&heu, destination]{
            Coordinates dest = destination;
            inverted.aStarStep(heu,invertedQ,invertedQ.extractMin(), dest);
        });

        //check if searches visited the same vertex
        f1.get();
        f2.get();

        intersectV = isIntersecting(this->getVisited(), inverted.getVisited());

        if(intersectV != nullptr) {
            this->getPath(origin, intersectV->getInfo(), coordsPath, edgePath, false);
            inverted.getPath(destination, intersectV->getInfo(),coordsPath,edgePath, true);
            break;
        }
    }
    auto end = chrono::steady_clock::now();
    time_elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
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
    inverted.isInverted = true;
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

void Graph::printPath(vector<Coordinates> coords) const {
    for( Coordinates c: coords)
        cout << c.getId() << " -> ";
    cout << "NULL" << endl;
}



//////////////////Vertex Method/////////////////////////////////////////
//Added here because compilation errors
/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
void Vertex::addEdge(Vertex *d, double w,Transport type) {
    adj.push_back(new Edge(this, d, w,type));
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
