//
// Created by joaom on 15-05-2019.
//

#include "TestGraph.h"
#include "Utils.h"
#include <iomanip>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(10, 15); //walking weight variation

double busF = 0.6; //bus weight factor
double metroF = 0.4; //metro weight factor

//Coords: (lat,long)


void generateBusRoute1(Graph &g,int n) {
    int i = n/10;
    int j = n/10;
    g.addVertex(Coordinates(i,j,i*n+j));
    while(j!= 5*n/10) {
        if((i == n/10 && j != 3*n/10) || i==9*n/10 ) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j+2,i*n+j+2),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i,j+2,i*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            j+=2;
        }
        else {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            i+=2;
        }

    }

    cout << "Generated Bus Route 1 " << endl;

    /*
    //Direction (1,1) -> (9,4)
    g.addEdge(Coordinates(1,1,11),Coordinates(2,1,21),dis(gen)*busF,bus);
    g.addEdge(Coordinates(2,1,21),Coordinates(3,2,32),dis(gen)*busF,bus);
    g.addEdge(Coordinates(3,2,32),Coordinates(5,2,52),dis(gen)*busF,bus);
    g.addEdge(Coordinates(5,2,52),Coordinates(5,0,50),dis(gen)*busF,bus);
    g.addEdge(Coordinates(5,0,50),Coordinates(7,0,70),dis(gen)*busF,bus);
    g.addEdge(Coordinates(7,0,70),Coordinates(8,1,81),dis(gen)*busF,bus);
    g.addEdge(Coordinates(8,1,81),Coordinates(8,3,83),dis(gen)*busF,bus);
    g.addEdge(Coordinates(8,3,83),Coordinates(9,4,94),dis(gen)*busF,bus);
    //Direction (9,4) -> (1,1)
    g.addEdge(Coordinates(9,4,94),Coordinates(8,3,83),dis(gen)*busF,bus);
    g.addEdge(Coordinates(8,3,83),Coordinates(8,1,81),dis(gen)*busF,bus);
    g.addEdge(Coordinates(8,1,81),Coordinates(7,0,70),dis(gen)*busF,bus);
    g.addEdge(Coordinates(7,0,70),Coordinates(5,0,50),dis(gen)*busF,bus);
    g.addEdge(Coordinates(5,0,50),Coordinates(5,2,52),dis(gen)*busF,bus);
    g.addEdge(Coordinates(5,2,52),Coordinates(3,2,32),dis(gen)*busF,bus);
    g.addEdge(Coordinates(3,2,32),Coordinates(2,1,21),dis(gen)*busF,bus);
    g.addEdge(Coordinates(2,1,21),Coordinates(1,1,11),dis(gen)*busF,bus);*/
}


void generateBusRoute2(Graph &g,int n) {
    int i = n/10;
    int j = 3*n/10;
    g.addVertex(Coordinates(i,j,i*n+j));
    while(i != 7*n/10) {
        if(j == 5*n/10|| j == 7*n/10 || j == 9*n/10) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            i+=2;
        }
        if(i == n/10 || i == 3*n/10 || i == 5*n/10) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j+2,i*n+j+2),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i,j+2,i*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            j+=2;
        }
    }

    while(j!= 5*n/10) {

        if(j==7*n/10 && i != 9*n/10) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            i+=2;
        }
        else {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j-2,i*n+j-2),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i,j-2,i*n+j-2),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            j-=2;
        }
    }

    cout << "Generated Bus Route 2 " << endl;
}


void generateBusRoute3(Graph &g,int n) {
    int i = 4*n/10;
    int j = 0;
    g.addVertex(Coordinates(i,j,i*n+j));
    while(i!=0) {
        if(j==0 && i != 6*n/10) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            i+=2;
        }
        else if((j==4*n/10 && i != 4*n/10) || j== 8*n/10) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i-2,j,(i-2)*n+j),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i-2,j,(i-2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            i-=2;
        }
        else {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j+2,i*n+j+2),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i,j+2,i*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            j+=2;
        }
    }

    cout << "Generated Bus Route 3 " << endl;
}


void generateMetroLineA(Graph &g,int n) {
    int i = 9*n/10;
    int j = 0;
    g.addVertex(Coordinates(i,j,i*n+j));
    while(i != n/10) {
        if(j == 2*n/10 || j == 6*n/10) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j+2,i*n+j+2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i,j+2,i*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            j+=2;
        }
        else if((j == 4*n/10 && i != 5*n/10) || j == 8*n/10) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i-2,j,(i-2)*n+j),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i-2,j,(i-2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i-=2;
        }
        else {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i-2,j+2,(i-2)*n+j+2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i-2,j+2,(i-2)*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i-=2;
            j+=2;
        }
    }

    while(i != 9*n/10) {
        if(i == n/10 && j != 4*n/10) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j-2,i*n+j-2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i,j-2,i*n+j-2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            j-=2;
        }
        else if(j == 0) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i+=2;
        }
        else {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j-2,(i+2)*n+j-2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i+2,j-2,(i+2)*n+j-2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i+=2;
            j-=2;
        }
    }

    cout << "Generated Subway Line A " << endl;
}

void generateMetroLineB(Graph &g,int n) {
    int i = 0;
    int j = 0;
    g.addVertex(Coordinates(i,j,i*n+j));
    while(j != 8*n/10) {
        if((j==0 && i != 2*n/10) || (j == 6*n/10 && i != 8*n/10)) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i+=2;
        }
        else if ((i==4*n/10 && j != 4*n/10) || (i==8*n/10 && j != 8*n/10)) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j+2,i*n+j+2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i,j+2,i*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            j+=2;
        }
        else {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j+2,(i+2)*n+j+2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i+2,j+2,(i+2)*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i+=2;
            j+=2;
        }
    }

    while( j !=0) {
        if(j == 8*n/10 && i != 4*n/10) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i-2,j,(i-2)*n+j),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i-2,j,(i-2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i-=2;
        }
        else if((i == 2*n/10 && j != 4*n/10) || (i==0 && j!=0)) {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j-2,i*n+j-2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i,j-2,i*n+j-2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            j-=2;
        }
        else {
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i-2,j-2,(i-2)*n+j-2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i-2,j-2,(i-2)*n+j-2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i-=2;
            j-=2;
        }
    }

    cout << "Generated Subway Line B " << endl;
}


void generateBusRouteGraph(Graph &g, int n) {
    generateBusRoute1(g,n);
    generateBusRoute2(g,n);
    generateBusRoute3(g,n);
}


void generateMetroLinesGraph(Graph &g,int n) {
    generateMetroLineA(g,n);
    generateMetroLineB(g,n);
}


void generatePedestrianGraph(Graph &ped, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ped.addVertex(Coordinates(i, j, i * n + j));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int di = -1; di <= 1; di++)
                for (int dj = -1; dj <= 1; dj++)
                    if ((di != 0) != (dj != 0) && i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < n)
                        ped.addEdge(Coordinates(i, j, i * n + j), Coordinates(i + di, j + dj, (i + di) * n + j + dj),
                                    dis(gen), foot);

    cout << "Generated Pedestrian routes " << endl;
}

void generateTransportGraph(int n, Graph &ped, Graph &bus, Graph &metro) {
    generatePedestrianGraph(ped, n);
    generateBusRouteGraph(bus,n);
    generateMetroLinesGraph(metro,n);
}

void runTests() {
    ofstream dijkstra("djikstra.csv"), euclidean("euclidean.csv"), chebyshev("chebyshev.csv"), manhattan("manhattan.csv");
    ofstream bidijkstra("bidjikstra.csv"), bieuclidean("bieuclidean.csv"), bichebyshev("bichebyshev.csv"), bimanhattan("bimanhattan.csv");
    vector<Coordinates> dummyVec;
    deque<Edge*> dummyDeque;
    for(int i = 10; i < pow(10, 2) * 4 ; i += 10){
        cout << "Generating grid graph: " << i << "x" << i << endl;
        Graph graph;
        generateTransportGraph(i, graph, graph, graph);
        int numVE = graph.getVertexSet().size() + graph.getEdgeSet().size();
        double djisktraTime, euclideanTime, chebyshevTime, manhattanTime,
        bidjisktraTime, bieuclideanTime, bichebyshevTime, bimanhattanTime;
        Coordinates origin = Coordinates(0, 0, 0);
        Coordinates dest = Coordinates(0, i - 1, (i - 1) * i + i - 1);
        graph.dijkstraShortestPath(origin, dest, djisktraTime);
        cout << "Finished djikstra. Elapsed Time: "<< djisktraTime << endl;
        graph.aStarShortestPath(origin, dest, euclidean_distance, euclideanTime);
        cout << "Finished euclidean. Elapsed Time: "<< euclideanTime << endl;
        graph.aStarShortestPath(origin, dest, chebyshev_distance, chebyshevTime);
        cout << "Finished chebyshev. Elapsed Time: "<< chebyshevTime << endl;
        graph.aStarShortestPath(origin, dest, manhattan_distance, manhattanTime);
        cout << "Finished manhattan. Elapsed Time: "<< manhattanTime << endl;
        graph.biDirDijkstra(origin, dest, bidjisktraTime, dummyVec, dummyDeque);
        cout << "Finished bidjikstra. Elapsed Time: " << bidjisktraTime << endl;
        graph.biDirAstar(origin, dest, euclidean_distance, bieuclideanTime, dummyVec, dummyDeque);
        cout << "Finished bieuclidean. Elapsed Time: " << bieuclideanTime << endl;
        graph.biDirAstar(origin, dest, chebyshev_distance, bichebyshevTime, dummyVec, dummyDeque);
        cout << "Finished bichebyshev. Elapsed Time: " << bichebyshevTime << endl;
        graph.biDirAstar(origin, dest, manhattan_distance, bimanhattanTime, dummyVec, dummyDeque);
        cout << "Finished bimanhattan. Elapsed Time: " << bimanhattanTime << endl;
        csv_writer(make_pair(numVE, djisktraTime), dijkstra);
        csv_writer(make_pair(numVE, euclideanTime), euclidean);
        csv_writer(make_pair(numVE, chebyshevTime), chebyshev);
        csv_writer(make_pair(numVE, manhattanTime), manhattan);
        csv_writer(make_pair(numVE, bidjisktraTime), bidijkstra);
        csv_writer(make_pair(numVE, bieuclideanTime), bieuclidean);
        csv_writer(make_pair(numVE, bichebyshevTime), bichebyshev);
        csv_writer(make_pair(numVE, bimanhattanTime), bimanhattan);
    }
}

void displayTest() {
    Graph pedestrian;
    Graph busRoutes;
    Graph metroLines;
    generateTransportGraph(100,pedestrian,pedestrian,pedestrian);
    GraphicalInterface interface = GraphicalInterface(800, 800);
    deque<Edge*> edges;
    double time;
    vector<Coordinates> coords;
    //pedestrian.biDirAstar(Coordinates(3, 0, 150), Coordinates(8, 9, 409), euclidean_distance, time, coords, edges); // careful selecting coordinate id. id = y*n+x -> where n is the width/height of the grid
    pedestrian.aStarShortestPath(Coordinates(3, 0, 300), Coordinates(8, 9, 809), manhattan_distance, time);
    pedestrian.getPath(Coordinates(3, 0, 300), Coordinates(8, 9, 809),coords,edges,false);
    cout << "Time elapsed: " << time << endl;
    pedestrian.printPath(coords);
    interface.showPath(edges);
}
