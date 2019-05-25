//
// Created by cajo on 24-05-2019.
//

#include "TripMate.h"

TripMate::TripMate() {
}

TripMate::TripMate(std::string cityName, const list<Schedule> &schedule) {
    this->city = loadGraph(cityName);
    this->schedules = schedule;
}

TripMate::TripMate(std::string cityName) {
    this->city = loadGraph(cityName);
}

void TripMate::loadCity(std::string cityName) {
    this->city = loadGraph(cityName);
}

void TripMate::addSchedule(const Schedule &sched) {
    schedules.push_back(sched);
}

void TripMate::removeSchedule(const Schedule &sched) {
    schedules.pop_back();
}

deque<Edge *> TripMate::proccessSchedule() {
    Schedule schedule = schedules.front();
    list<Appointment> appointments = schedule.getAppointments();
    vector<Coordinates> coords;
    deque<Edge *> path;

    if(appointments.empty()){
        double timeElapsed;
        city.aStarShortestPath(schedule.getStart(), schedule.getEnd(), euclidean_distance, timeElapsed);
        city.getPath(schedule.getEnd(), coords, path);
        city.printPath(coords);
    }

    schedules.pop_front();
    return path;
}

const Graph &TripMate::getCity() const {
    return city;
}
