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

vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex *Graph::findVertex(const Coordinates &in) const {
    for (auto v : vertexSet)
        if (v->info == in) //TODO overload operator==
            return v;
    return nullptr;
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
bool Graph::addEdge(const Coordinates &sourc, const Coordinates &dest, double w, Transport type) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w, type);
    edgeSet.push_back(v1->adj[v1->adj.size() - 1]);
    return true;
}

bool Graph::addInvEdge(const Coordinates &sourc, const Coordinates &dest, double w, Transport type) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addInvEdge(v2, w, type);
//    edgeSet.push_back(v1->adj[v1->adj.size()-1]);
    return true;
}


/**
 * Initializes single source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
 */
Vertex *Graph::initSingleSource(const Coordinates &origin) {
    this->visited.clear();
    this->invertedVisited.clear();
    for (auto v : vertexSet) {
        v->weight = INF;
        v->path = nullptr;
        v->dist = INF;
        v->predecessor = nullptr;
        this->visited[v->info.getId()] = false;
        this->invertedVisited[v->info.getId()] = false;
    }
    auto s = findVertex(origin);
    s->weight = 0;
    s->visited = true;

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

        w->visited = true;

        return true;
    } else
        return false;
}

void Graph::dijkstraShortestPath(const Coordinates &origin, const Coordinates &dest, double &time_elapsed) {
    auto start = chrono::steady_clock::now();
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    int i = 0;
    while (!q.empty()) {
        auto v = q.extractMin();
        if (v->getInfo() == dest) {
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
    if (isInverted) {
        v = findVertex(v->getInfo()); // do this only if its inverted graph
    }

    this->visited[v->info.getId()] = true;
    for (auto e : v->adj) {
        if (relax(v, e->dest, e->weight)) {
            e->dest->path = v;
            e->dest->predecessor = e;
            if (!q.find(e->dest))
                q.insert(e->dest);
            else
                q.decreaseKey(e->dest);
        }
    }
}

void Graph::getPath(const Coordinates &dest, vector<Coordinates> &coords, deque<Edge *> &edges) const {
    vector<Coordinates> c;
    auto v = findVertex(dest);
    if (v == nullptr || v->weight == INF) // missing or disconnected
        return;

    for (; v != nullptr && v->predecessor != nullptr; v = v->path) {
        c.push_back(v->info);
        edges.push_front(v->predecessor);
    }
    c.push_back(v->info);
    reverse(c.begin(), c.end());
    coords.insert(coords.end(), c.begin(), c.end());
}

void Graph::getInvPath(const Coordinates &dest, vector<Coordinates> &coords, deque<Edge *> &edges) const {

    auto v = findVertex(dest);
    if (v == nullptr || v->weight == INF) // missing or disconnected
        return;
    for (; v != nullptr && v->invPredecessor != nullptr; v = v->invPath) {
        edges.push_back(v->invPredecessor);
        if(v->getInfo() == dest) {
            continue;
        }
        coords.push_back(v->info);
    }
    coords.push_back(v->info);
}

void Graph::getBiDirPath(const Coordinates &dest, vector<Coordinates> &coords, deque<Edge *> &edges) const  {
    long intID = -1 ;
    for(auto itr =this->visited.begin() ; itr != this->visited.end(); itr++) {
        auto it2 = this->invertedVisited.find(itr->first);
        if( itr->second && it2 != this->invertedVisited.end() && it2->second) {
            intID = itr->first;
            break;
        }
    }

    if(intID == -1) {
        return;
    }

    Vertex* intV = findVertex(Coordinates(0,0,intID));
    getPath(intV->getInfo(),coords,edges);
    getInvPath(intV->getInfo(),coords,edges);
}

/**************** Single Source Shortest Path algorithms ************/

void Graph::aStarShortestPath(const Coordinates &origin, const Coordinates &dest,
                              double ( *heu)(const Vertex *, const Coordinates &), double &time_elapsed) {
    auto start = chrono::steady_clock::now();
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    int i = 0;
    while (!q.empty()) {
        auto v = q.extractMin();
        v->visited = true;
        if (v->getInfo() == dest) {
            //cout << "Num of iterations " << i << " " << this->vertexSet.size() << endl;
            break;
        }
        aStarStep(heu, q, v, dest);
        i++;
    }
    auto end = chrono::steady_clock::now();
    time_elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void Graph::aStarStep(double (*heu)(const Vertex *, const Coordinates &), MutablePriorityQueue<Vertex> &q,
                      Vertex *origin, const Coordinates &dest) {
    if (isInverted) {
        origin = findVertex(origin->getInfo()); // do this only if its inverted graph
    }

    this->visited[origin->info.getId()] = true;
    for (auto e : origin->adj) {
        if (aStarRelax(origin, e->dest, e->weight, heu, dest)) {
            e->dest->path = origin;
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
    if (v->weight + weight + heu(w, dest) < w->weight) {
        w->weight = v->weight + weight + heu(w, dest);
        w->dist = v->weight + weight;

        return true;
    } else
        return false;
}

vector<Edge *> Graph::getEdgeSet() const {
    return edgeSet;
}


Edge::Edge(Vertex *o, Vertex *d, double w, Transport type) : orig(o), dest(d), weight(w), type(type) {}

double Edge::getWeight() const {
    return weight;
}

Transport Edge::getType() const {
    return type;
}

void Graph::biDirDijkstra(const Coordinates &origin, const Coordinates &destination, double &time_elapsed) {
    this->invertGraph();

    Vertex *orig = findVertex(origin);
    Vertex *dest = findVertex(destination);

    if (orig == nullptr || dest == nullptr) {
        cout << "Invalid points chosen." << endl;
        return;
    }

    this->initSingleSource(origin);
    this->initDestination(destination);


    auto start = chrono::steady_clock::now();
    //threads init and run searches
    auto f1 = thread([this, origin, destination] {
        this->dijkstraShortestPathBi(origin, destination);
    });

    this->dijkstraShortestPathBiInv(origin, destination);
    f1.join();
    auto end = chrono::steady_clock::now();
    time_elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void Graph::biDirAstar(const Coordinates &origin, const Coordinates &destination,
                       double (*heu)(const Vertex *, const Coordinates &), double &time_elapsed) {
    this->invertGraph();
    Vertex *orig = findVertex(origin);
    Vertex *dest = findVertex(destination);

    if (orig == nullptr || dest == nullptr) {
        cout << "Invalid points chosen." << endl;
        return;
    }

    this->initSingleSource(origin);
    this->initDestination(destination);
    auto start = chrono::steady_clock::now();
    auto f1 = thread([this, origin, heu, destination] {
        this->aStarShortestPathBi(origin, destination, heu);
    });
    this->aStarShortestPathBiInv(origin, destination, heu);

    f1.join();
    auto end = chrono::steady_clock::now();
    time_elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void Graph::concatenateEdges(const vector<Edge *> &edges) {
    for (Edge *edge : edges) {
        addEdge(edge->getOrig()->getInfo(), edge->getDest()->getInfo(), edge->getWeight(), edge->getType());
    }
}

void Graph::invertGraph() {
    for (auto i: this->getEdgeSet()) {
        this->addInvEdge(i->getDest()->getInfo(), i->getOrig()->getInfo(), i->getWeight(), i->getType());
    }
}

bool Graph::isIntersecting(unordered_map<unsigned long, bool> &checking, Vertex *check) {
    return checking[check->info.getId()];
}

void Graph::printPath(vector<Coordinates> coords) const {
    for (Coordinates c: coords)
        cout << c.getId() << " -> ";
    cout << "NULL" << endl;
}

void Graph::dijkstraShortestPathBi(const Coordinates &origin, const Coordinates &dest) {
    auto s = findVertex(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    int i = 0;
    while (!q.empty()) {
        auto v = q.extractMin();
        v->visited = true;
        this->visited[v->info.getId()] = true;
        if (this->isIntersecting(this->invertedVisited, v)) {
            cout << "Num of iterations " << i << " " << this->vertexSet.size() << endl;
            break;
        }
        dijkstraStep(q, v);
        i++;
    }
}

void Graph::dijkstraShortestPathBiInv(const Coordinates &origin, const Coordinates &dest) {
    auto s = findVertex(dest);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    int i = 0;
    while (!q.empty()) {
        auto v = q.extractMin();
        v->visited = true;
        this->invertedVisited[v->info.getId()] = true;
        if (this->isIntersecting(this->visited, v)) {
            cout << "Num of iterations " << i << " " << this->vertexSet.size() << endl;
            break;
        }
        for (auto e : v->inc) {
            if (relax(v, e->dest, e->weight)) {
                e->dest->invPath = v;
                e->dest->invPredecessor = e;
                if (!q.find(e->dest))
                    q.insert(e->dest);
                else
                    q.decreaseKey(e->dest);
            }
        }
        i++;
    }
}

void Graph::aStarShortestPathBi(const Coordinates &origin, const Coordinates &dest,
                                double (*heu)(const Vertex *, const Coordinates &)) {
    auto s = findVertex(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    int i = 0;
    while (!q.empty()) {
        auto v = q.extractMin();
        this->visited[v->info.getId()] = true;
        v->visited = true;
        if (this->isIntersecting(this->invertedVisited, v)) {
            cout << "Num of iterations " << i << " " << this->vertexSet.size() << endl;
            break;
        }
        aStarStep(heu, q, v, dest);
        i++;
    }
}

void Graph::aStarShortestPathBiInv(const Coordinates &origin, const Coordinates &dest,
                                   double (*heu)(const Vertex *, const Coordinates &)) {

    auto s = findVertex(dest);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    int i = 0;
    while (!q.empty()) {
        auto v = q.extractMin();
        v->visited = true;
        this->invertedVisited[v->info.getId()] = true;
        if (this->isIntersecting(this->visited, v)) {
            cout << "Num of iterations " << i << " " << this->vertexSet.size() << endl;
            break;
        }
        for (auto e : v->inc) {
            if (aStarRelax(v, e->dest, e->weight, heu, origin)) {
                e->dest->invPath = v;
                e->dest->invPredecessor = e;
                if (!q.find(e->dest))
                    q.insert(e->dest);
                else
                    q.decreaseKey(e->dest);
            }
        }
        i++;
    }
}

void Graph::initDestination(const Coordinates &dest) {
    Vertex *destination = this->findVertex(dest);
    destination->weight = 0;
}

void Graph::clearCheckpoints() {
    for(auto v : vertexSet) {
        v->checkpoint = none;
    }
}


//////////////////Vertex Method/////////////////////////////////////////
/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
void Vertex::addEdge(Vertex *d, double w, Transport type) {
    adj.push_back(new Edge(this, d, w, type));
}

void Vertex::addInvEdge(Vertex *d, double w, Transport type) {
    inc.push_back(new Edge(this, d, w, type));
}

Vertex::Vertex(Coordinates in) : info(in), checkpoint(none) {}


bool Vertex::operator<(Vertex &vertex) const {
    return this->weight < vertex.weight;
}

Coordinates Vertex::getInfo() const {
    return this->info;
}

void Vertex::setCheckpoint(Checkpoint t) {
    this->checkpoint = t;
}

bool Vertex::isStartPoint() {
    return checkpoint == startPoint;
}

bool Vertex::isMiddlePoint() {
    return checkpoint == middlePoint;
}

bool Vertex::isEndPoint() {
    return checkpoint == endPoint;
}

bool Vertex::isCheckpoint() {
    return checkpoint != none;
}

