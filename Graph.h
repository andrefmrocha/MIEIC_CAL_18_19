/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include "MutablePriorityQueue.h"
#include "Coordinates.h"

using namespace std;

class Edge;
class Graph;
class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

class Vertex {
	Coordinates info;                // contents
	vector<Edge> adj;  // outgoing edges
	bool visited;          // auxiliary field
	double weight = 0;
	double dist = 0;
	Vertex *path = nullptr;
	int queueIndex = 0; 		// required by MutablePriorityQueue
	vector<Vertex* > disjSet;

	void addEdge(Vertex *dest, double w);


public:
	Vertex(Coordinates in);
	bool operator<(Vertex& vertex) const; // // required by MutablePriorityQueue
	bool operator==(Vertex v) const;
	Coordinates getInfo() const;
	double getWeight() const;
	Vertex *getPath() const;
	friend class Graph;
	friend class MutablePriorityQueue<Vertex>;
};

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

/********************** Edge  ****************************/

class Edge {
	Vertex *orig; 	// Fp07
	Vertex *dest;      // destination vertex
	double weight;         // edge weight

	bool selected; // Fp07

public:
	Edge(Vertex *o, Vertex *d, double w);
	friend class Graph;
	friend class Vertex;
	bool operator<(Edge edge) const;
	bool operator==(Edge edge) const;

	// Fp07
	double getWeight() const;

};

Edge::Edge(Vertex *o, Vertex *d, double w): orig(o), dest(d), weight(w) {}

double Edge::getWeight() const {
	return weight;
}

//////////////////Vertex Method/////////////////////////////////////////
//Added here because compilation errors
/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
void Vertex::addEdge(Vertex *d, double w) {
    adj.push_back(Edge(this, d, w));
}

/*************************** Graph  **************************/

class Graph {
	vector<Vertex *> vertexSet;    // vertex set
	vector<Edge> edgeSet;

	// Fp05
	Vertex * initSingleSource(const Coordinates &orig);
	bool relax(Vertex *v, Vertex *w, double weight);
    static bool aStarRelax(Vertex *v, Vertex *w, double weight, bool ( *heu)(Vertex *, Vertex *, double));
    double ** W = nullptr;   // weight
	int **P = nullptr;   // path
	int findVertexIdx(const Coordinates &in) const;


public:
	Vertex *findVertex(const Coordinates &in) const;
	bool addVertex(const Coordinates &in);
	bool addEdge(const Coordinates &sourc, const Coordinates &dest, double w);
	int getNumVertex() const;
	vector<Vertex *> getVertexSet() const;
	double getEdgeWeight(Edge e);

	// Fp05 - single source
	void dijkstraShortestPath(const Coordinates &s);
    void aStarShortestPath(const Coordinates &origin, bool ( *heu)(Vertex *, Vertex *, double) );
	vector<Coordinates> getPath(const Coordinates &origin, const Coordinates &dest) const;

	//~Graph();
};

bool Vertex::operator==(Vertex v) const {
    return this->getInfo() == v.getInfo();
}

bool Edge::operator<(Edge edge) const {
    return this->getWeight() > edge.getWeight();
}

bool Edge::operator==(Edge edge) const {
    return this->orig == edge.orig && this->dest == edge.dest && this->weight == edge.getWeight();
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
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const Coordinates &sourc, const Coordinates &dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == nullptr || v2 == nullptr)
		return false;
	v1->addEdge(v2, w);
	edgeSet.push_back(Edge(v1,v2,w));
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

void Graph::dijkstraShortestPath(const Coordinates &origin) {
	auto s = initSingleSource(origin);
	MutablePriorityQueue<Vertex> q;
	q.insert(s);
	while( ! q.empty() ) {
		auto v = q.extractMin();
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

void Graph::aStarShortestPath(const Coordinates &origin, bool ( *heu)(Vertex *, Vertex *, double) ) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    while( ! q.empty() ) {
        auto v = q.extractMin();
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

inline bool Graph::aStarRelax(Vertex *v, Vertex *w, double weight, bool (*heu)(Vertex *, Vertex *, double)) {
    if (v->weight + weight + heu(v, w, weight)< w->weight) {
        w->weight = v->weight + weight + heu(v, w, weight);
        w->dist = v->weight + weight;
        w->path = v;
        return true;
    }
    else
        return false;
}

double Graph::getEdgeWeight(Edge e) {
    vector<Edge>::iterator it = find(edgeSet.begin(),edgeSet.end(),e);
    if(it != edgeSet.end()) {
        return it->getWeight();
    }
    else
        return -1;
}

#endif /* GRAPH_H_ */
