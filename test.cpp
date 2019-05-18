//
// Created by joaom on 15-05-2019.
//

#include <random>
#include "Graph.h"

void generateRandomGridGraph(int n, Graph & g) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g.addVertex(Coordinates(i,j,i*n+j));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int di = -1; di <= 1; di++)
                for (int dj = -1; dj <= 1; dj++)
                    if ((di != 0) != (dj != 0) && i+di >= 0 && i+di < n && j+dj >= 0 && j+dj < n)
                        g.addEdge(Coordinates(i,j,i*n+j), Coordinates(i+di,j+dj,i*n+j), dis(gen));
}

int main() {
    Graph myGraph;
    generateRandomGridGraph(10,myGraph);

    return 0;
}