/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>
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
	vector<Edge*> adj;  // outgoing edges
	vector<Edge*> inc;  // incoming edges
	bool visited;          // auxiliary field
	double weight = 0;
	double dist = 0;
	Vertex *path = nullptr;
	Vertex *invPath = nullptr;
	int queueIndex = 0; 		// required by MutablePriorityQueue
	vector<Vertex* > disjSet;

	void addEdge(Vertex *dest, double w,Transport type);
	void addInvEdge(Vertex *dest, double w,Transport type);

    Edge *predecessor;
    Edge *invPredecessor;
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
	Vertex *dest;      // destination vertex
	double weight;         // edge weight

public:
	Edge(Vertex *o, Vertex *d, double w, Transport type);
	friend class Graph;
	friend class Vertex;
	bool operator<(Edge edge) const;
	bool operator==(Edge edge) const;

	double getWeight() const;
    Transport getType() const;
    bool isBus() const;
    bool isSubway() const;
    bool isOnFoot() const;
    Vertex *getOrig() const;
    Vertex *getDest() const;
    Edge* invertEdge();

};

/*************************** Graph  **************************/

class Graph {
	vector<Vertex *> vertexSet;    // vertex set
	vector<Edge*> edgeSet;
	unordered_map<unsigned long, bool> visited;
    unordered_map<unsigned long, bool> invertedVisited;

    Vertex * isIntersecting(const vector<bool> &visited1, const vector<bool> &visited2);
    void initDestination(const Coordinates & dest);

private:

    // Fp05
	Vertex * initSingleSource(const Coordinates &orig);
	bool relax(Vertex *v, Vertex *w, double weight);
    static bool aStarRelax(Vertex *v, Vertex *w, double weight, double ( *heu)(const Vertex *, const Coordinates &),
                           const Coordinates &dest);
    double ** W = nullptr;   // weight
	int **P = nullptr;   // path
	int findVertexIdx(const Coordinates &in) const;
    void aStarStep(double (*heu)(const Vertex *, const Coordinates &), MutablePriorityQueue<Vertex> &q, Vertex *origin,
                   const Coordinates &dest);
    void dijkstraStep(MutablePriorityQueue<Vertex> &q, Vertex *v);
    bool isInverted=false;
    bool isIntersecting(unordered_map<unsigned long, bool> &checking, Vertex * check);
public:
    Vertex *findVertex(const Coordinates &in) const;
    bool addVertex(const Coordinates &in);
    bool addEdge(const Coordinates &sourc, const Coordinates &dest, double w,Transport type);
    bool addInvEdge(const Coordinates &sourc, const Coordinates &dest, double w,Transport type);
    int getNumVertex() const;
    vector<Vertex *> getVertexSet() const;
    vector<Edge*> getEdgeSet() const;

	double getEdgeWeight(Edge e);
    void dijkstraShortestPath(const Coordinates &origin, const Coordinates &dest, double &time_elapsed);
    void dijkstraShortestPathBi(const Coordinates &origin, const Coordinates &dest);
    void dijkstraShortestPathBiInv(const Coordinates &origin, const Coordinates &dest);
    void aStarShortestPath(const Coordinates &origin, const Coordinates &dest, double ( *heu)(const Vertex *,
                                                                                              const Coordinates &),
                           double &time_elapsed);
    void aStarShortestPathBi(const Coordinates &origin, const Coordinates &dest, double ( *heu)(const Vertex *,
                                                                                              const Coordinates &));
    void aStarShortestPathBiInv(const Coordinates &origin, const Coordinates &dest, double ( *heu)(const Vertex *,
                                                                                              const Coordinates &));
    void getPath(const Coordinates &dest, vector<Coordinates> &coords, deque<Edge *> &edges) const;
    void getInvPath(const Coordinates &dest,vector<Coordinates> &coords,deque<Edge*> &edges) const;
    void getBiDirPath(const Coordinates &dest,vector<Coordinates> & coords, deque<Edge*> &edges) const ;

    void biDirDijkstra(const Coordinates &origin, const Coordinates &destination, double &time_elapsed);
    void biDirAstar(const Coordinates &origin, const Coordinates &destination,
                    double (*heu)(const Vertex *, const Coordinates &), double &time_elapsed);
    void concatenateEdges(const vector<Edge *>& edges);
    void printPath(vector<Coordinates> coords) const;
    void invertGraph();
};

#endif /* GRAPH_H_ */
