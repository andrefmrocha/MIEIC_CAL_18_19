#include <iostream>
#include "GraphViewer/GraphicalInterface.h"

int main() {
    GraphicalInterface interface = GraphicalInterface(600, 600);
    Vertex* v1 = new Vertex(Coordinates(10, 10, 0));
    Vertex* v2 = new Vertex(Coordinates(20, 10, 1));
    Vertex* v3 = new Vertex(Coordinates(10, 20, 2));
    Vertex* v4 = new Vertex(Coordinates(20, 20, 3));
    deque<Edge*> edges;
    edges.push_front(new Edge(v1, v2, 10,foot));
    edges.push_front(new Edge(v1, v3, 20,foot));
    edges.push_front(new Edge(v1, v3, 20,foot));
    edges.push_front(new Edge(v2, v3, 40,foot));
    edges.push_front(new Edge(v4, v3, 70,foot));
    edges.push_front(new Edge(v2, v4, 80,foot));
    interface.showPath(edges);
    return 0;
}