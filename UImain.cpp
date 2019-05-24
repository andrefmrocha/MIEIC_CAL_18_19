//
// Created by joaom on 22-05-2019.
//

#include "UImain.h"

Graph porto;
GraphicalInterface interface(1920, 1080);

void route1(){
    deque<Edge *> path;
    for(Edge * edge: porto.getEdgeSet()){
        path.push_back(edge);
    }
    interface.showPath(path);
    //Calculate paths
    //Processing view of path
    //Display
    cout << "Route 1 demonstration finished" << endl;
}

void route2(){
    displayTest();
    //Load graph
    //Calculate paths
    //Processing view of path
    //Display
    cout << "Route 2 demonstration finished" << endl;
}

void route3(){
    //Load graph
    //Calculate paths
    //Processing view of path
    //Display
    cout << "Route 3 demonstration finished" << endl;
}

void route4(){
    //Load graph
    //Calculate paths
    //Processing view of path
    //Display
    cout << "Route 4 demonstration finished" << endl;
}

void showOptions() {
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Please choose the route desired: (1-4)" << endl;
    cout << "1 - Path between two points, one way and the other." << endl;
    cout << "2 - Path from one point to another, with a middle point." << endl;
    cout << "3 - Path from one point to another, with 3 middle points." << endl;
    cout << "4 - Path from one point to another, with 5 middle points and return to the origin." << endl;
    cout << "0 - Exit." << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}

int main () {
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Welcome to our Scheduling Planning app" << endl;
    cout << "Loading Map..." << endl;
    porto = loadGraph("Porto");
    cout << "We have prepared some examples to demonstrate schedule planning in the beautiful city of Porto. " << endl;
    showOptions();
    char opt;
    while(1) {
        cout << "Option: ";
        cin >> opt;
        switch(opt) {
            case '0':
                return 0;
            case '1' :
                route1();
                break;
            case '2' :
                route2();
                break;
            case '3':
                route3();
                break;
            case '4':
                route4();
                break;
            case '5':
                showOptions();
                break;
            default:
                cout << endl << "Invalid option, try again." << endl;
                continue;
        }
        cout << endl <<  "Choose another route to view or exit. Press 5 to view the options again." << endl;
    }
}