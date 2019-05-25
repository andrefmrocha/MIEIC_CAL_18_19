//
// Created by cajo on 15-05-2019.
//

#ifndef PROJECT_COORDINATES_H
#define PROJECT_COORDINATES_H


class Coordinates {
    double y;
    double x;
    unsigned long idNode;
public:
    Coordinates(double y, double x, unsigned long idNode);
    Coordinates(unsigned long idNode);
    double getY() const;
    double getX() const ;
    unsigned long getId() const;
    bool operator==(const Coordinates &right) const;
};


#endif //PROJECT_COORDINATES_H
