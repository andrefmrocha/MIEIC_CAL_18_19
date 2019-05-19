//
// Created by cajo on 19-05-2019.
//

#ifndef PROJECT_SCHEDULE_H
#define PROJECT_SCHEDULE_H

#include <list>
#include "Coordinates.h"
#include "Appointment.h"

class Schedule {
    Coordinates start;
    Coordinates end;
    std::list<Appointment> appointments;
public:
    Schedule(const Coordinates &start, const Coordinates &end);

    const std::list<Appointment> &getAppointments() const;

    void setAppointments(const std::list<Appointment> &appointments);

    /**
     * @brief Adds an appointment to the list of appointments.
     * @param appointment Appointment to be added.
     * @return True if the insertion was successful and False otherwise.
     */
    bool addAppointment(Appointment &appointment);

    /**
     * @brief Removes an appointment from the list of appointments.
     * @param appointment Appointment to be removed.
     * @return True if the deletion was successful and False otherwise.
     */
    bool removeAppointment(Appointment &appointment);
};


#endif //PROJECT_SCHEDULE_H
