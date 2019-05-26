//
// Created by cajo on 19-05-2019.
//

#include "Schedule.h"

Schedule::Schedule(const Coordinates &start, const Coordinates &end) :
        start(start), end(end){
        this->appointments = std::list<Appointment>();
}

const Coordinates &Schedule::getStart() const {
    return start;
}

const Coordinates &Schedule::getEnd() const {
    return end;
}

const std::list<Appointment> &Schedule::getAppointments() const {
    return appointments;
}

void Schedule::setAppointments(const std::list<Appointment> &appointments) {
    Schedule::appointments = appointments;
}

bool Schedule::addAppointment(Appointment appointment) {
    std::list<Appointment>::iterator it;
    for(it = appointments.begin(); it != appointments.end(); it++){
        if(appointment == *it){
            return false;
        }
        else if(appointment < *it){
            if(appointment.overlaps(*it))
                return false;

            appointments.insert(it, appointment);
            return true;
        }
    }

    appointments.push_back(appointment);
    return true;
}

bool Schedule::removeAppointment(Appointment &appointment) {
    std::list<Appointment>::iterator it;
    for(it = appointments.begin(); it != appointments.end(); it++){
        if(appointment == *it){
            appointments.erase(it);
            return true;
        }
    }

    return false;
}
