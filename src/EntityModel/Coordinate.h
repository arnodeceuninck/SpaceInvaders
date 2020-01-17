//
// Created by arno on 17/12/2019.
//

#ifndef SPACEINVADERS_COORDINATE_H
#define SPACEINVADERS_COORDINATE_H

namespace spaceinvaders {
class Coordinate {
public:
    /**
     * Constructor
     * @param x
     * @param y
     */
    Coordinate(double x, double y);

    /**
     * Get the x position
     * @return
     */
        [[nodiscard]] double getX() const;

        /**
         * Get the y position
         * @return
         */
        [[nodiscard]] double getY() const;

    /**
     * Add two coordinates to each other
     * @param rhs
     * @return
     */
    Coordinate operator+(const Coordinate &rhs) const;

    /**
     * Subtract two coordinates
     * @param rhs
     * @return
     */
    Coordinate operator-(const Coordinate &rhs) const;

    /**
     * Multiply a coordinate with a constant
     * @param k the constant
     * @return
     */
    Coordinate operator*(const double &k) const;

    /**
     * Add a coordinate to this
     * @param rhs
     * @return
     */
    Coordinate operator+=(const Coordinate &rhs);

    /**
     * Subtract a coordinate from this
     * @param rhs
     * @return
     */
    Coordinate operator-=(const Coordinate &rhs);

    /**
     * Multiply this with a constant
     * @param k the constant
     * @return
     */
    Coordinate operator*=(const double &k);

    /**
     * Multiply only the x coordinate with a constant
     * @param k the constant
     */
    void mulX(const double &k);

    /**
     * Multiply only the y coordinate with a constant
     * @param k the constant
     */
    void mulY(const double &k);

    /**
     * Change the x value
     * @param x
     */
    void setX(double x);

    /**
     * Change the y value
     * @param y
     */
    //        void setY(double y);

private:
    double x;
    double y;
};
} // namespace spaceinvaders

#endif // SPACEINVADERS_COORDINATE_H
