#include <iostream>
#include "GraphViewer/GraphicalInterface.h"
#include "TestGraph.h"
#include "Utils.h"
#include "Heuristics.h"

int main() {
    Graph pedestrian;
    Graph busRoutes;
    Graph metroLines;
    generateRandomGridGraph(10,pedestrian);
    generateBusRouteGraph(busRoutes);
    generateMetroLinesGraph(metroLines);
    unifyGraphs(pedestrian, busRoutes, metroLines);
    Coordinates ori = Coordinates(0,2,2);
    Coordinates dest = Coordinates(6,6,66);
    pedestrian.dijkstraShortestPath(ori, dest);
    vector<Coordinates> coordsdji = pedestrian.getPath(ori, dest);
    pedestrian.aStarShortestPath(ori, dest, euclidean_distance);
    vector<Coordinates> coordsast = pedestrian.getPath(ori, dest);
    return 0;
}