//
// Created by andrefmrocha on 5/20/19.
//
#include "Utils.h"
#define MAX_ARGS 3
#define PI acos(-1)


void unifyGraphs(Graph &g1, Graph &g2, Graph &g3) {
    g1.concateEdges(g2.getEdgeSet());
    g1.concateEdges(g3.getEdgeSet());
    g1.concateVertexs(g2.getVertexSet());
    g1.concateVertexs(g3.getVertexSet());
}

void csv_writer(const pair<int, double> &values, ofstream & outfile) {
    outfile << "V+E" << "," << "time(ms)" << endl;
    outfile << values.first << "," << values.second << endl;
}

Graph loadGraph() {
    return Graph();
}

Graph loadPedestrian(std::string edgesPath, std::string nodesPath) {
    ifstream file(nodesPath);
    std::string line;
    std::string args[MAX_ARGS];
    int index = 0;
    bool firstLine = true;
    stringstream stream;
    Graph myGraph;

    //LOADING NODES
    if (!file.is_open()) {
        std::cerr << "Couldn't open pedestrian node file." << endl;
        return myGraph;
    }

    while (std::getline(file, line)) {
        if(firstLine){
            firstLine = false;
            continue;
        }
        line = line.substr(1, line.size() - 2);

        for(size_t i = 0; i < line.size(); i++){
            if(line[i] == ',') {
                args[index] = stream.str();
                index++;
                stream.str("");
                continue;
            } else if (line[i] == ' ')
                continue;
            stream << line[i];
        }

        args[index] = stream.str();
        index = 0;
        stream.str("");

        myGraph.addVertex(Coordinates(stod(args[2]), stod(args[1]), stod(args[0])));
    }

    file.close();

    //LOADING EDGES
    file.open(edgesPath);
    firstLine = true;

    if (!file.is_open()) {
        std::cerr << "Couldn't open pedestrian edge file." << endl;
        return myGraph;
    }

    while (std::getline(file, line)) {
        if(firstLine){
            firstLine = false;
            continue;
        }
        line = line.substr(1, line.size() - 2);

        for(size_t i = 0; i < line.size(); i++){
            if(line[i] == ',') {
                args[index] = stream.str();
                index++;
                stream.str("");
                continue;
            } else if (line[i] == ' ')
                continue;
            stream << line[i];
        }

        args[index] = stream.str();
        index = 0;
        stream.str("");

        Coordinates source(0, 0, stod(args[0])), dest(0, 0, stod(args[1]));
        myGraph.addEdge(source, dest, euclidean(source, dest, myGraph), foot);
    }

    return myGraph;
}

Graph loadBus(std::string filePath) {
    return Graph();
}

Graph loadSubway(std::string filePath) {
    return Graph();
}

double haversine(const Coordinates &source, const Coordinates &dest, const Graph &graph) {
    auto v1 = graph.findVertex(source);
    auto v2 = graph.findVertex(dest);

    if(v1 == nullptr || v2 == nullptr)
        return INF;

    double radius = 6371e3;
    double lat1 = toRadians(v1->getInfo().getY());
    double lat2 = toRadians(v2->getInfo().getY());
    double dLat = toRadians(v2->getInfo().getY() - v1->getInfo().getY());
    double dLon = toRadians(v2->getInfo().getX() - v1->getInfo().getX());

    double a = sin(dLat/2.0) * sin(dLat/2.0) + cos(lat1) * cos(lat2) * sin(dLon/2.0) * sin(dLon/2.0);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return radius * c;
}

double euclidean(const Coordinates &source, const Coordinates &dest, const Graph &graph){
    auto v1 = graph.findVertex(source);
    auto v2 = graph.findVertex(dest);

    if(v1 == nullptr || v2 == nullptr)
        return INF;

    return sqrt(pow(v1->getInfo().getX() - v2->getInfo().getX(), 2)
                + pow(v1->getInfo().getY() - v2->getInfo().getY(), 2));
}

double toRadians(double degrees) {
    return (degrees * PI) / 180;
}

