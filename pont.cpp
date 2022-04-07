/**
 *  \file pont.cpp
 *  A Pont osztály és a hozzá tartozó függvények definíciója
 */

#include "pont.h"

const double Pont::pi = 3.14159265359;

double Pont::tavolsag(const Pont& p2) const {
    return sqrt(pow(x - p2.getX(), 2) + pow(y - p2.getY(), 2));
}

Pont Pont::pont_korul_forgat(const Pont& dp1, double radian) const {
return Pont(
            round(( (dp1.getX()-x)*cos(radian) - (dp1.getY()-y)*sin(radian) + x)*100000)/100000 ,
            round(( (dp1.getX()-x)*sin(radian) + (dp1.getY()-y)*cos(radian) + y)*100000)/100000
            );
}

std::ostream& operator<<(std::ostream& os, const Pont& p) {
    return os << "(" << p.getX() << "," << p.getY() << ")";
}

std::istream& operator>>(std::istream& is, Pont& p) {
    double ix, iy;
    if (!(is >> ix >> iy) && !(is.eof())) {
        std::string err = "Rossz koordinata.";
        throw std::invalid_argument(err);
    }
    p.setX(ix);
    p.setY(iy);
    return is;
}
