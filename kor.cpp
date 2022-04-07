/**
 *  \file kor.cpp
 *  A Kor osztály és hozzá tartozó függvények definíciója
 */

#include "kor.h"

bool Kor::pont_teruletten_van(const Pont& p) {
    return (p.tavolsag(getkp()) <= r);
}

bool Kor::origo_kp_koron_kivul_esik(const double dr) {
    return ( dr < (Pont(0,0).tavolsag(getkp()) - r) );
}

void Kor::rajzol() const {
     std::cout << "Rajzolas: " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Kor& k) {
    return os << (Sikidom&)k << "r=" << k.getR();
}
