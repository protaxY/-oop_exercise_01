#ifndef LB1_POSITION_H
#define LB1_POSITION_H

#include <math.h>
#include <iostream>
#define DBL_EPSILON 10e-15
class Position{
    private:
        double latitude;
        double longitude;
        double norm()const;
        void check_limits();//берет координаты по модулю, чтобы они не выходили за приделы [-90,90] и [-180,180]
    public:
        Position();
        Position(double cur_latitude, double cur_longitude);
        Position set_position(double cur_latitude, double cur_longitude);
        void print_position();
        friend Position operator+(const Position &lhs, const Position &rhs);
        friend Position operator-(const Position &lhs, const Position &rhs);
        friend Position operator*(const Position &lhs, const Position &rhs);
        friend Position operator/(const Position &lhs, const Position &rhs);
        friend bool operator==(const Position &lhs, const Position &rhs);
        friend bool operator!=(const Position &lhs, const Position &rhs);
        friend bool operator>(const Position &lhs, const Position &rhs);
        friend bool operator>=(const Position &lhs, const Position &rhs);
        friend bool operator<(const Position &lhs, const Position &rhs);
        friend bool operator<=(const Position &lhs, const Position &rhs);
};
#endif