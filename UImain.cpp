//
// Created by joaom on 22-05-2019.
//

#include "UImain.h"

TripMate tripMate;
GraphicalInterface interface(1920, 1080);

void route1(){
    Schedule sched1(Coordinates(445439258), Coordinates(430006683));
    deque<Edge *> path;

    //Calculate paths
    tripMate.addSchedule(sched1);
    path = tripMate.proccessSchedule();

    //Display
    interface.showPath(path);
    cout << "Route 1 demonstration finished" << endl;
}

void route2(){
    Schedule schedule(Coordinates(445439258), Coordinates(445439258));
    deque<Edge *> path;

    //Preparing Schedule
    schedule.addAppointment(Appointment(Coordinates(430006683), "2019-05-29 11:30:00", 120));

    //Calculate path
    tripMate.addSchedule(schedule);
    path = tripMate.proccessSchedule();

    //Display
    interface.showPath(path);
    cout << "Route 2 demonstration finished" << endl;
}

void route3(){

    //Calculate paths
    //Processing view of path
    //Display
    cout << "Route 3 demonstration finished" << endl;
}

void route4(){
    deque<Edge *> path;
    for(Edge * edge: tripMate.getCity().getEdgeSet()){
        path.push_back(edge);
    }
    interface.showPath(path);
    //Load graph
    //Calculate paths
    //Processing view of path
    //Display
    cout << "Route 4 demonstration finished" << endl;
}

void showOptions() {
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Please choose the route desired: (1-4)" << endl;
    cout << "1 - Path between two points." << endl;
    cout << "2 - Path from one point to another, with a middle point." << endl;
    cout << "3 - Path from one point to another, with 3 middle points." << endl;
    cout << "4 - Path from one point to another, with 5 middle points and return to the origin." << endl;
    cout << "0 - Exit." << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}

void configureInterface() {
    double maxX = 0, maxY = 0;
    double minX = INF, minY = INF;

    for(Vertex* vertex: tripMate.getCity().getVertexSet()){
        if(vertex->getInfo().getY() < minY){
            minY = vertex->getInfo().getY();
        }
        if(vertex->getInfo().getX() < minX){
            minX = vertex->getInfo().getX();
        }
        if(vertex->getInfo().getY() > maxY){
            maxY = vertex->getInfo().getY();
        }
        if(vertex->getInfo().getX() > maxX){
            maxX = vertex->getInfo().getX();
        }
    }


    interface.setMapBounds(Coordinates(maxY, maxX, 0), Coordinates(minY, minX, 0));
}

int main () {
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Welcome to our Scheduling Planning app" << endl;
    cout << "Loading Map..." << endl;
    tripMate.loadCity("Porto");
    configureInterface();
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