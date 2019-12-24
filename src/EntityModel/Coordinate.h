//
// Created by arno on 17/12/2019.
//

#ifndef SPACEINVADERS_COORDINATE_H
#define SPACEINVADERS_COORDINATE_H


namespace spaceinvaders {
    class Coordinate {
    public:
        Coordinate(double x, double y);

        double getX() const;

        double getY() const;

        Coordinate operator+(const Coordinate &rhs);

        Coordinate operator-(const Coordinate &rhs);

        Coordinate operator*(const int &k);

        Coordinate operator+=(const Coordinate &rhs);

        Coordinate operator-=(const Coordinate &rhs);

        Coordinate operator*=(const int &k);

        void invertY();


    private:
        double x;
        double y;
    };
}


#endif //SPACEINVADERS_COORDINATE_H
