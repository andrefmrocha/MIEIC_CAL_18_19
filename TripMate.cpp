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
    list<Appointment> calculatedApps;
    vector<Coordinates> coords;
    deque<Edge *> result;

    if(appointments.empty()){
        double timeElapsed;
        city.aStarShortestPath(schedule.getStart(), schedule.getEnd(), euclidean_distance, timeElapsed);
        city.getPath(schedule.getEnd(), coords, result);
        city.printPath(coords);
    }
    else {
        double timeElapsed;
        Coordinates source(0);
        deque<Edge *>* path = appointments.front().getPath();

        //From beginning to first appointment
        city.aStarShortestPath(schedule.getStart(), appointments.front().getCoord(), euclidean_distance, timeElapsed);
        city.getPath(appointments.front().getCoord(), coords, *path);
        result.insert(result.end(), path->begin(), path->end());
        city.printPath(coords);
        //Between appointments
        for(Appointment appointment : appointments) {
            source = appointments.front().getCoord();
            calculatedApps.push_back(appointments.front());
            appointments.pop_front();
            path = appointments.front().getPath();
            city.aStarShortestPath(source, appointments.front().getCoord(), euclidean_distance, timeElapsed);
            city.getPath(appointments.front().getCoord(), coords, *path);
            result.insert(result.end(), path->begin(), path->end());
            city.printPath(coords);
        }
        //From last appointment to ending
        source = appointments.front().getCoord();
        calculatedApps.push_back(appointments.front());
        appointments.pop_front();
        deque<Edge *> lastPath;
        city.aStarShortestPath(source, schedule.getEnd(), euclidean_distance, timeElapsed);
        city.getPath(schedule.getEnd(), coords, lastPath);
        result.insert(result.end(), lastPath.begin(), lastPath.end());
        city.printPath(coords);
    }

    schedules.front().setAppointments(calculatedApps);
    schedules.pop_front();
    return result;
}

const Graph &TripMate::getCity() const {
    return city;
}
