/**
 *  \file sikidom.cpp
 *  A síkidomo osztály és a hozzá tartozó függvények definíciója
 */

#include "sikidom.h"

std::ostream& operator<<(std::ostream& os, const Sikidom& s) {
   return os << s.getTipus() << ": kp=" << s.getkp() << ", p1=" << s.getp1() << " ";
}

double heron(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double csucsokbol_heron(Pont p1, Pont p2, Pont p3) {
    double a, b, c;
    a = p1.tavolsag(p2); b = p1.tavolsag(p3); c = p2.tavolsag(p3);
    return heron(a, b, c);
}

