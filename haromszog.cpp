/**
 *  \file haromszog.cpp
 *  A háromszög osztály és hozzá tartozó függvények definíciója
 */

#include "haromszog.h"

bool Haromszog::pont_teruletten_van(const Pont& p) {
    double terulet = 0;
    double ossz_terulet = 0;
    double a;

    a = p2.tavolsag(p3);
    ossz_terulet = heron(a, a, a);

    terulet += csucsokbol_heron(getp1(), p2, p);
    terulet += csucsokbol_heron(p2, p3, p);
    terulet += csucsokbol_heron(p3, getp1(), p);

    return (terulet <= ossz_terulet + 0.0001); //kerekítés hiba
}

bool Haromszog::origo_kp_koron_kivul_esik(const double dr) {
    for (double x = -dr; x <= dr; x+=0.05) {
        double y = sqrt((dr*dr)-(x*x));
        if (pont_teruletten_van(Pont(x,y)) || pont_teruletten_van(Pont(x, -y))) {
            return false;
        }
    }
    return true;
}

void Haromszog::rajzol() const {
    std::cout << "Rajzolas: " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Haromszog& h) {
    return os << (Sikidom&)h << " p2=" << h.getp2() << " p3=" << h.getp3();
}
