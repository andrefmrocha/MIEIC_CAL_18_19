//
// Created by cajo on 15-05-2019.
//

#ifndef PROJECT_COORDINATES_H
#define PROJECT_COORDINATES_H


class Coordinates {
    double latitude;
    double longitude;
    unsigned long idNode;
public:
    Coordinates(double latitude, double longitude, unsigned long idNode);
    double getLat();
    double getLong();
    unsigned long getId();
    bool operator==(const Coordinates &right) const;
};


#endif //PROJECT_COORDINATES_H
