//
// Created by cajo on 24-05-2019.
//

#ifndef PROJECT_TRIPMATE_H
#define PROJECT_TRIPMATE_H

//#include <list>
#include "Graph.h"
#include "Schedule.h"
#include "Utils.h"
#include "Heuristics.h"

class TripMate {
    Graph city;
public:
    const Graph &getCity() const;

private:
    list<Schedule> schedules;
public:
    TripMate();
    TripMate(std::string cityName);
    TripMate(std::string cityName, const list<Schedule> &schedule);
    void loadCity(std::string cityName);
    void addSchedule(const Schedule &sched);
    void removeSchedule(const Schedule &sched);
    deque<Edge *> proccessSchedule();
};


#endif //PROJECT_TRIPMATE_H
