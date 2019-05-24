//
// Created by cajo on 19-05-2019.
//

#ifndef PROJECT_APPOINTMENT_H
#define PROJECT_APPOINTMENT_H

#include <string>
#include <ctime>
#include <deque>
#include "Coordinates.h"
#include "Graph.h"

class Appointment {
    Coordinates coord;
    struct tm start;
    int duration; //in minutes
    std::deque<Edge *> path;

    /**
    * @brief Converts a string in format "YYYY-MM-DD hh:mm:ss" into a struct tm type.
    * @param input String to be converted.
    * @return Corresponding date in a struct tm.
    */
    struct tm stringToTM(const std::string &input);

public:
    Appointment(const Coordinates &coord, const std::string &start, int duration);

    Coordinates getCoord() const;

    const tm &getStart() const;

    const deque<Edge *> &getPath() const;

    void setPath(const deque<Edge *> &path);

    /**
    * @brief Checks if THIS appointment overlaps the one passed as argument.
    * @param right Possible overlapped appointment.
    * @return True if there is overlapping, False otherwise.
    */
    bool overlaps(Appointment &right);

    bool operator <(Appointment &right);

    bool operator ==(Appointment &right);
};


#endif //PROJECT_APPOINTMENT_H
