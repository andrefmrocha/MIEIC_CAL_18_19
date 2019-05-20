#include <iostream>
#include "GraphViewer/GraphicalInterface.h"
#include "TestGraph.h"

int main() {
    Graph pedestrian;
    Graph busRoutes;
    Graph metroLines;
    generateRandomGridGraph(10,pedestrian);
    generateBusRouteGraph(busRoutes);
    generateMetroLinesGraph(metroLines);
    return 0;
}