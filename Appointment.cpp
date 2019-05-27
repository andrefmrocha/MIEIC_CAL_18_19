//
// Created by cajo on 19-05-2019.
//

#include "Appointment.h"

Appointment::Appointment(const Coordinates &coord, const std::string &start, int durationMinutes) :
        coord(coord), duration(durationMinutes) {
    this->path = deque<Edge *>();
    this->start = stringToTM(start);
}

struct tm Appointment::stringToTM(const std::string &input) {
    struct tm time;

    time.tm_year = stoi(input.substr(0, 4)) - 1900;
    time.tm_mon = stoi(input.substr(5, 2)) - 1;
    time.tm_mday = stoi(input.substr(9, 2));
    time.tm_hour = stoi(input.substr(11, 2));
    time.tm_min = stoi(input.substr(14, 2));
    time.tm_sec = stoi(input.substr(17, 2));
    time.tm_isdst = -1;

    return time;
}

Coordinates Appointment::getCoord() const {
    return coord;
}

struct tm &Appointment::getStart() {
    return start;
}

deque<Edge *> *Appointment::getPath() {
    return &path;
}

void Appointment::setPath(const deque<Edge *> &path) {
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
