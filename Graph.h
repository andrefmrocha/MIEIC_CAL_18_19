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

//type of transportation
enum Transport  {
    foot,
    bus,
    subway
};
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

	void addEdge(Vertex *dest, double w,Transport type);


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

/********************** Edge  ****************************/

class Edge {



    Vertex *orig;

	Transport type;
public:
    bool isBus() const;

    bool isSubway() const;

    bool isOnFoot() const;

    Vertex *getOrig() const;

    Vertex *getDest() const;

private:
    // Fp07
	Vertex *dest;      // destination vertex
	double weight;         // edge weight

	bool selected; // Fp07

public:
	Edge(Vertex *o, Vertex *d, double w, Transport type);
	friend class Graph;
	friend class Vertex;
	bool operator<(Edge edge) const;
	bool operator==(Edge edge) const;

	// Fp07
	double getWeight() const;

};

/*************************** Graph  **************************/

class Graph {
	vector<Vertex *> vertexSet;    // vertex set
	vector<Edge*> edgeSet;

	// Fp05
	Vertex * initSingleSource(const Coordinates &orig);
	bool relax(Vertex *v, Vertex *w, double weight);
    static bool aStarRelax(Vertex *v, Vertex *w, double weight, double ( *heu)(Vertex *, Vertex *));
    double ** W = nullptr;   // weight
	int **P = nullptr;   // path
	int findVertexIdx(const Coordinates &in) const;



public:
	Vertex *findVertex(const Coordinates &in) const;
	bool addVertex(const Coordinates &in);
	bool addEdge(const Coordinates &sourc, const Coordinates &dest, double w,Transport type);
	int getNumVertex() const;
	vector<Vertex *> getVertexSet() const;
	vector<Edge*> getEdgeSet() const;
	double getEdgeWeight(Edge e);

	// Fp05 - single source
	void dijkstraShortestPath(const Coordinates &s, const Coordinates &dest);
    void aStarShortestPath(const Coordinates &origin, const Coordinates &dest, double ( *heu)(Vertex *, Vertex *) );
	vector<Coordinates> getPath(const Coordinates &origin, const Coordinates &dest) const;
    void biDirSearch(const Coordinates & origin, const Coordinates &destination);
    void concateEdges(vector<Edge *> edges);
    void concateVertexs(vector<Vertex *> vertexs);
	//~Graph();
};

#endif /* GRAPH_H_ */
