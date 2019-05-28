//
// Created by joaom on 22-05-2019.
//

#include "UImain.h"

static TripMate tripMate;
static GraphicalInterface interface(1920, 1080);

void route1(){
    Schedule sched1(Coordinates(445439258), Coordinates(430006682));
    deque<Edge *> path;

    //Calculate paths
    tripMate.addSchedule(sched1);
    path = tripMate.proccessSchedule();

    //Display
    interface.showPath(path);
    tripMate.clearCheckpoints();
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
    tripMate.clearCheckpoints();
    cout << "Route 2 demonstration finished" << endl;
}

void route3(){
    Schedule schedule(Coordinates(445439258), Coordinates(112686789));
    deque<Edge *> path;

    //Preparing Schedule
    schedule.addAppointment(Appointment(Coordinates(285948656), "2019-06-03 10:30:00", 180));
    schedule.addAppointment(Appointment(Coordinates(475413943), "2019-06-03 14:00:00", 45));
    schedule.addAppointment(Appointment(Coordinates(128677717), "2019-06-03 15:00:00", 180));
    schedule.addAppointment(Appointment(Coordinates(1279864321), "2019-06-03 18:15:00", 90));

    //Calculate paths
    tripMate.addSchedule(schedule);
    path = tripMate.proccessSchedule();

    //Display
    interface.showPath(path);
    tripMate.clearCheckpoints();
    cout << "Route 3 demonstration finished" << endl;
}

void route4(){
    Schedule schedule(Coordinates(445439258), Coordinates(445439258));
    deque<Edge *> path;

    //Preparing Schedule
    schedule.addAppointment(Appointment(Coordinates(125384237), "2019-06-02 10:00:00", 120));
    schedule.addAppointment(Appointment(Coordinates(285948656), "2019-06-02 13:00:00", 60));
    schedule.addAppointment(Appointment(Coordinates(135837695), "2019-06-02 15:00:00", 210));
    schedule.addAppointment(Appointment(Coordinates(111648004), "2019-06-02 19:00:00", 90));
    schedule.addAppointment(Appointment(Coordinates(112651995), "2019-06-02 21:00:00", 180));

    //Calculate paths
    tripMate.addSchedule(schedule);
    path = tripMate.proccessSchedule();

    //Display
    interface.showPath(path);
    tripMate.clearCheckpoints();
    cout << "Route 4 demonstration finished" << endl;
}

void showOptions() {
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Please choose the route desired: (1-4)" << endl;
    cout << "1 - From home to FEUP." << endl;
    cout << "2 - Attending a class." << endl;
    cout << "3 - Students also wander." << endl;
    cout << "4 - Going further away." << endl;
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
    signal(SIGINT, SIG_IGN);

    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Welcome to our Scheduling Planning Demo" << endl;
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