#include <iostream>
#include "GraphViewer/GraphicalInterface.h"
#include "TestGraph.h"
#include "Utils.h"
#include "Heuristics.h"

int main() {
    vector<pair<int,int>> pairs;
    for(int i = 0; i < 50; i++){
        pairs.push_back(make_pair(i, i*20));
    }
    csv_writer(pairs, "teste.csv");
    return 0;
}