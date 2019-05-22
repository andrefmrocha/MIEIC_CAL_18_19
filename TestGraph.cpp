//
// Created by joaom on 15-05-2019.
//

#include "TestGraph.h"
#include "Utils.h"


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
//            g.addVertex(Coordinates(i,j+2,i*n+j+2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j+2,i*n+j+2),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i,j+2,i*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            j+=2;
        }
        else {
//            g.addVertex(Coordinates(i+2,j,(i+2)*n+j));
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
//            g.addVertex(Coordinates(i+2,j,(i+2)*n+j));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            i+=2;
        }
        if(i == n/10 || i == 3*n/10 || i == 5*n/10) {
//            g.addVertex(Coordinates(i,j+2,i*n+j+2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j+2,i*n+j+2),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i,j+2,i*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            j+=2;
        }
    }

    while(j!= 5*n/10) {

        if(j==7*n/10 && i != 9*n/10) {
//            g.addVertex(Coordinates(i+2,j,(i+2)*n+j));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            i+=2;
        }
        else {
//            g.addVertex(Coordinates(i,j-2, i*n+j-2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j-2,i*n+j-2),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i,j-2,i*n+j-2),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            j-=2;
        }
    }

    cout << "Generated Bus Route 2 " << endl;

    /*
    //Direction (1,5) -> (9,4)
    g.addEdge(Coordinates(1,5,15),Coordinates(1,7,17),dis(gen)*busF,bus);
    g.addEdge(Coordinates(1,7,17),Coordinates(2,8,28),dis(gen)*busF,bus);
    g.addEdge(Coordinates(2,8,28),Coordinates(3,8,38),dis(gen)*busF,bus);
    g.addEdge(Coordinates(3,8,38),Coordinates(5,8,58),dis(gen)*busF,bus);
    g.addEdge(Coordinates(5,8,58),Coordinates(7,8,78),dis(gen)*busF,bus);
    g.addEdge(Coordinates(7,8,78),Coordinates(9,8,98),dis(gen)*busF,bus);
    g.addEdge(Coordinates(9,8,98),Coordinates(9,6,96),dis(gen)*busF,bus);
    g.addEdge(Coordinates(9,6,96),Coordinates(9,4,94),dis(gen)*busF,bus);
    //Direction (9,4) -> (1,5)
    g.addEdge(Coordinates(9,4,94),Coordinates(9,6,96),dis(gen)*busF,bus);
    g.addEdge(Coordinates(9,6,96),Coordinates(9,8,98),dis(gen)*busF,bus);
    g.addEdge(Coordinates(9,8,98),Coordinates(7,8,78),dis(gen)*busF,bus);
    g.addEdge(Coordinates(7,8,78),Coordinates(5,8,58),dis(gen)*busF,bus);
    g.addEdge(Coordinates(5,8,58),Coordinates(3,8,38),dis(gen)*busF,bus);
    g.addEdge(Coordinates(3,8,38),Coordinates(2,8,28),dis(gen)*busF,bus);
    g.addEdge(Coordinates(2,8,28),Coordinates(1,7,17),dis(gen)*busF,bus);
    g.addEdge(Coordinates(1,7,17),Coordinates(1,5,15),dis(gen)*busF,bus);*/
}


void generateBusRoute3(Graph &g,int n) {

    int i = 4*n/10;
    int j = 0;
    g.addVertex(Coordinates(i,j,i*n+j));
    while(i!=0) {
        if(j==0 && i != 6*n/10) {
//            g.addVertex(Coordinates(i+2,j,(i+2)*n+j));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            i+=2;
        }
        else if((j==4*n/10 && i != 4*n/10) || j== 8*n/10) {
//            g.addVertex(Coordinates(i-2,j,(i-2)*n+j));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i-2,j,(i-2)*n+j),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i-2,j,(i-2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            i-=2;
        }
        else {
//            g.addVertex(Coordinates(i,j+2,i*n+j+2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j+2,i*n+j+2),dis(gen)*busF,bus);
            g.addEdge(Coordinates(i,j+2,i*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*busF,bus);
            j+=2;
        }
    }

    cout << "Generated Bus Route 3 " << endl;

    /*
    //Direction (1,3) -> (8,5)
    g.addEdge(Coordinates(1,3,13),Coordinates(2,3,23),dis(gen)*busF,bus);
    g.addEdge(Coordinates(2,3,23),Coordinates(4,4,44),dis(gen)*busF,bus);
    g.addEdge(Coordinates(4,4,44),Coordinates(5,5,55),dis(gen)*busF,bus);
    g.addEdge(Coordinates(5,5,55),Coordinates(4,6,46),dis(gen)*busF,bus);
    g.addEdge(Coordinates(4,6,46),Coordinates(4,7,47),dis(gen)*busF,bus);
    g.addEdge(Coordinates(4,7,47),Coordinates(6,7,67),dis(gen)*busF,bus);
    g.addEdge(Coordinates(6,7,67),Coordinates(7,6,76),dis(gen)*busF,bus);
    g.addEdge(Coordinates(7,6,76),Coordinates(8,5,85),dis(gen)*busF,bus);
    //Direction (8,5) -> (1,3)
    g.addEdge(Coordinates(8,5,85),Coordinates(7,6,76),dis(gen)*busF,bus);
    g.addEdge(Coordinates(7,6,76),Coordinates(6,7,67),dis(gen)*busF,bus);
    g.addEdge(Coordinates(6,7,67),Coordinates(4,7,47),dis(gen)*busF,bus);
    g.addEdge(Coordinates(4,7,47),Coordinates(4,6,46),dis(gen)*busF,bus);
    g.addEdge(Coordinates(4,6,46),Coordinates(5,5,55),dis(gen)*busF,bus);
    g.addEdge(Coordinates(5,5,55),Coordinates(4,4,44),dis(gen)*busF,bus);
    g.addEdge(Coordinates(4,4,44),Coordinates(2,3,23),dis(gen)*busF,bus);
    g.addEdge(Coordinates(2,3,23),Coordinates(1,3,13),dis(gen)*busF,bus);*/
}


void generateMetroLineA(Graph &g,int n) {

    int i = 9*n/10;
    int j = 0;
    g.addVertex(Coordinates(i,j,i*n+j));
    while(i != n/10) {
        if(j == 2*n/10 || j == 6*n/10) {
//            g.addVertex(Coordinates(i,j+2,i*n+j+2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j+2,i*n+j+2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i,j+2,i*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            j+=2;
        }
        else if((j == 4*n/10 && i != 5*n/10) || j == 8*n/10) {
//            g.addVertex(Coordinates(i-2,j,(i-2)*n+j));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i-2,j,(i-2)*n+j),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i-2,j,(i-2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i-=2;
        }
        else {
//            g.addVertex(Coordinates(i-2,j+2,(i-2)*n+j+2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i-2,j+2,(i-2)*n+j+2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i-2,j+2,(i-2)*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i-=2;
            j+=2;
        }
    }

    while(i != 9*n/10) {
        if(i == n/10 && j != 4*n/10) {
//            g.addVertex(Coordinates(i,j-2,i*n+j-2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j-2,i*n+j-2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i,j-2,i*n+j-2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            j-=2;
        }
        else if(j == 0) {
//            g.addVertex(Coordinates(i+2,j,(i+2)*n+j));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i+=2;
        }
        else {
//            g.addVertex(Coordinates(i+2,j-2,(i+2)*n+j-2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j-2,(i+2)*n+j-2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i+2,j-2,(i+2)*n+j-2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i+=2;
            j-=2;
        }
    }

    cout << "Generated Subway Line A " << endl;
    /*
    //Direction (0,2) -> (8,9)
    g.addEdge(Coordinates(0,2,2),Coordinates(2,2,22),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(2,2,22),Coordinates(3,3,33),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(3,3,33),Coordinates(5,4,54),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(5,4,54),Coordinates(7,6,76),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(7,6,76),Coordinates(8,7,87),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(8,7,87),Coordinates(8,9,89),dis(gen)*metroF,subway);
    //Direction (8,9) -> (0,2)
    g.addEdge(Coordinates(8,9,89),Coordinates(8,7,87),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(8,7,87),Coordinates(7,6,76),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(7,6,76),Coordinates(5,4,54),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(5,4,54),Coordinates(3,3,33),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(3,3,33),Coordinates(2,2,22),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(2,2,22),Coordinates(0,2,2),dis(gen)*metroF,subway);*/

}


void generateMetroLineB(Graph &g,int n) {

    int i = 0;
    int j = 0;
    g.addVertex(Coordinates(i,j,i*n+j));
    while(j != 8*n/10) {
        if((j==0 && i != 2*n/10) || (j == 6*n/10 && i != 8*n/10)) {
//            g.addVertex(Coordinates(i+2,j,(i+2)*n+j));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j,(i+2)*n+j),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i+2,j,(i+2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i+=2;
        }
        else if ((i==4*n/10 && j != 4*n/10) || (i==8*n/10 && j != 8*n/10)) {
//            g.addVertex(Coordinates(i,j+2,i*n+j+2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j+2,i*n+j+2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i,j+2,i*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            j+=2;
        }
        else {
//            g.addVertex(Coordinates(i+2,j+2,(i+2)*n+j+2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i+2,j+2,(i+2)*n+j+2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i+2,j+2,(i+2)*n+j+2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i+=2;
            j+=2;
        }
    }

    while( j !=0) {
        if(j == 8*n/10 && i != 4*n/10) {
//            g.addVertex(Coordinates(i-2,j,(i-2)*n+j));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i-2,j,(i-2)*n+j),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i-2,j,(i-2)*n+j),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i-=2;
        }
        else if((i == 2*n/10 && j != 4*n/10) || (i==0 && j!=0)) {
//            g.addVertex(Coordinates(i,j-2,i*n+j-2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i,j-2,i*n+j-2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i,j-2,i*n+j-2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            j-=2;
        }
        else {
//            g.addVertex(Coordinates(i-2,j-2,(i-2)*n+j-2));
            g.addEdge(Coordinates(i,j,i*n+j),Coordinates(i-2,j-2,(i-2)*n+j-2),dis(gen)*metroF,subway);
            g.addEdge(Coordinates(i-2,j-2,(i-2)*n+j-2),Coordinates(i,j,i*n+j),dis(gen)*metroF,subway);
            i-=2;
            j-=2;
        }
    }

    cout << "Generated Subway Line B " << endl;

    /*
    //Direction (9,0) -> (0,9)
    g.addEdge(Coordinates(9,0,90),Coordinates(9,2,92),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(9,2,92),Coordinates(8,3,83),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(8,3,83),Coordinates(7,5,75),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(7,5,75),Coordinates(6,6,66),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(6,6,66),Coordinates(4,6,46),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(4,6,46),Coordinates(3,7,37),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(3,7,37),Coordinates(2,8,28),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(2,8,28),Coordinates(2,9,29),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(2,9,29),Coordinates(0,9,9),dis(gen)*metroF,subway);
    //Direction (0,9) -> (9,0)
    g.addEdge(Coordinates(0,9,9),Coordinates(2,9,29),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(2,9,29),Coordinates(2,8,28),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(2,8,28),Coordinates(3,7,37),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(3,7,37),Coordinates(4,6,46),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(4,6,46),Coordinates(6,6,66),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(6,6,66),Coordinates(7,5,75),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(7,5,75),Coordinates(8,3,83),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(8,3,83),Coordinates(9,2,92),dis(gen)*metroF,subway);
    g.addEdge(Coordinates(9,2,92),Coordinates(9,0,90),dis(gen)*metroF,subway);*/
}


void generateBusRouteGraph(Graph &g, int n) {

    /*g.addVertex(Coordinates(0,9,9));
    g.addVertex(Coordinates(1,1,11));
    g.addVertex(Coordinates(1,5,15));
    g.addVertex(Coordinates(1,7,17));
    g.addVertex(Coordinates(2,1,21));
    g.addVertex(Coordinates(2,8,28));
    g.addVertex(Coordinates(2,9,29));
    g.addVertex(Coordinates(3,2,32));
    g.addVertex(Coordinates(3,7,37));
    g.addVertex(Coordinates(3,8,38));
    g.addVertex(Coordinates(4,6,46));
    g.addVertex(Coordinates(5,0,50));
    g.addVertex(Coordinates(5,2,52));
    g.addVertex(Coordinates(5,8,58));
    g.addVertex(Coordinates(6,6,66));
    g.addVertex(Coordinates(7,0,70));
    g.addVertex(Coordinates(7,5,75));
    g.addVertex(Coordinates(7,8,78));
    g.addVertex(Coordinates(8,1,81));
    g.addVertex(Coordinates(8,3,83));
    g.addVertex(Coordinates(8,5,85));
    g.addVertex(Coordinates(9,0,90));
    g.addVertex(Coordinates(9,2,92));
    g.addVertex(Coordinates(9,4,94));
    g.addVertex(Coordinates(9,6,96));
    g.addVertex(Coordinates(9,8,98));*/

    generateBusRoute1(g,n);
    generateBusRoute2(g,n);
    generateBusRoute3(g,n);

}


void generateMetroLinesGraph(Graph &g,int n) {
    /*g.addVertex(Coordinates(0,2,2));
    g.addVertex(Coordinates(0,9,9));
    g.addVertex(Coordinates(2,2,22));
    g.addVertex(Coordinates(2,8,28));
    g.addVertex(Coordinates(2,9,29));
    g.addVertex(Coordinates(3,3,33));
    g.addVertex(Coordinates(3,7,37));
    g.addVertex(Coordinates(4,6,46));
    g.addVertex(Coordinates(5,4,54));
    g.addVertex(Coordinates(6,6,66));
    g.addVertex(Coordinates(7,5,75));
    g.addVertex(Coordinates(7,6,76));
    g.addVertex(Coordinates(8,3,83));
    g.addVertex(Coordinates(8,7,87));
    g.addVertex(Coordinates(8,9,89));
    g.addVertex(Coordinates(9,0,90));
    g.addVertex(Coordinates(9,2,92));*/

    generateMetroLineA(g,n);
    generateMetroLineB(g,n);

}


void generateTransportGraph(int n, Graph &ped, Graph &bus, Graph &metro) {


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ped.addVertex(Coordinates(i,j,i*n+j));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int di = -1; di <= 1; di++)
                for (int dj = -1; dj <= 1; dj++)
                    if ((di != 0) != (dj != 0) && i+di >= 0 && i+di < n && j+dj >= 0 && j+dj < n)
                        ped.addEdge(Coordinates(i,j,i*n+j), Coordinates(i+di,j+dj,(i+di)*n+j+dj), dis(gen),foot);


    cout << "Generated Pedestrian routes " << endl;

    generateBusRouteGraph(bus,n);
    generateMetroLinesGraph(metro,n);
}

void runTests() {
    vector<pair<int, int>> djikstra, euclidean, chebyshev, manhattan;
    for(int i = 10; i < pow(10, 5); i += 10){
        Graph graph;
        generateTransportGraph(i, graph, graph, graph);
        double djisktraTime, euclideanTime, chebyshevTime, manhattanTime;
        graph.dijkstraShortestPath(Coordinates(0, 0, 0), Coordinates(i, i, i * i + i), djisktraTime);
        cout << "Finished djikstra. Elapsed Time: "<< djisktraTime << endl;
        graph.aStarShortestPath(Coordinates(0, 0, 0), Coordinates(i, i, i * i + i), euclidean_distance, euclideanTime);
        cout << "Finished euclidean. Elapsed Time: "<< djisktraTime << endl;
        graph.aStarShortestPath(Coordinates(0, 0, 0), Coordinates(i, i, i * i + i), chebyshev_distance, chebyshevTime);
        cout << "Finished chebyshev. Elapsed Time: "<< djisktraTime << endl;
        graph.aStarShortestPath(Coordinates(0, 0, 0), Coordinates(i, i, i * i + i), manhattan_distance, manhattanTime);
        cout << "Finished manhattan. Elapsed Time: "<< djisktraTime << endl;
        djikstra.push_back(make_pair(graph.getEdgeSet().size() + graph.getVertexSet().size(), djisktraTime));
        euclidean.push_back(make_pair(graph.getEdgeSet().size() + graph.getVertexSet().size(), euclideanTime));
        chebyshev.push_back(make_pair(graph.getEdgeSet().size() + graph.getVertexSet().size(), chebyshevTime));
        manhattan.push_back(make_pair(graph.getEdgeSet().size() + graph.getVertexSet().size(), manhattanTime));
    }
    csv_writer(djikstra, "djikstra.csv");
    csv_writer(euclidean, "euclidean.csv");
    csv_writer(chebyshev, "chebyshev.csv");
    csv_writer(manhattan, "manhattan.csv");

}


/*int main() {
    Graph pedestrian;
    Graph busRoutes;
    Graph metroLines;
    generateTransportGraph(30,pedestrian,pedestrian,pedestrian);
    GraphicalInterface interface = GraphicalInterface(800, 800);
    deque<Edge*> edges;
    for(Edge* e: pedestrian.getEdgeSet()) {
        edges.push_back(e);
    }
    double time;
    pedestrian.biDirAstar(Coordinates(3,0,30),Coordinates(8,9,89),euclidean_distance,time);
    cout << "Time elapsed: " << time << endl;
    interface.showPath(edges);

    return 0;
}*/
