//
// Created by cajo on 19-05-2019.
//

#include "Appointment.h"

Appointment::Appointment(const Coordinates &coord, const std::string &start, int duration) :
        coord(coord), duration(duration) {
    this->path = deque<Edge>();
    this->start = stringToTM(start);
}

struct tm Appointment::stringToTM(const std::string &input) {
    struct tm time;

    time.tm_year = stoi(input.substr(0, 4)) - 1900;
    time.tm_mon = stoi(input.substr(5, 2)) - 1;
    time.tm_mday = stoi(input.substr(9, 2));
    time.tm_hour = stoi(input.substr(12, 2));
    time.tm_min = stoi(input.substr(15, 2));
    time.tm_sec = stoi(input.substr(18, 2));
    time.tm_isdst = -1;

    return time;
}

const Coordinates &Appointment::getCoord() const {
    return coord;
}

const tm &Appointment::getStart() const {
    return start;
}

const deque<Edge> &Appointment::getPath() const {
    return path;
}

void Appointment::setPath(const deque<Edge> &path) {
    Appointment::path = path;
}

bool Appointment::operator<(Appointment &right) {
    time_t thisTime = mktime(&start);
    time_t rightTime = mktime(&(right.start));

    return thisTime < rightTime;
}

bool Appointment::operator==(Appointment &right) {
    time_t thisTime = mktime(&start);
    time_t rightTime = mktime(&(right.start));

    return coord == right.coord && thisTime == rightTime && duration == right.duration;
}

bool Appointment::overlaps(Appointment &right) {
    time_t thisTime = mktime(&start);
    time_t rightTime = mktime(&(right.start));

    thisTime += (duration * 60);

    return thisTime > rightTime;
}
