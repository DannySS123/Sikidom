/**
 *  \file negyszog.cpp
 *  A Kor osztály és hozzá tartozó függvények definíciója
 */

#include "negyszog.h"

bool Negyszog::pont_teruletten_van(const Pont& p) {
    double ossz_terulet = 0;
    ossz_terulet += csucsokbol_heron(getp1(), p2, getkp());
    ossz_terulet += csucsokbol_heron(p2, p3, getkp());
    ossz_terulet += csucsokbol_heron(p3, p4, getkp());
    ossz_terulet += csucsokbol_heron(p4, getp1(), getkp());

    double terulet = 0;
    terulet += csucsokbol_heron(getp1(), p2, p);
    terulet += csucsokbol_heron(p2, p3, p);
    terulet += csucsokbol_heron(p3, p4, p);
    terulet += csucsokbol_heron(p4, getp1(), p);
    return (terulet <= ossz_terulet + 0.0001); //kerekítés hiba
}

bool Negyszog::origo_kp_koron_kivul_esik(const double dr) {
    for (double x = -dr; x <= dr; x+=0.05) {
        double y = sqrt((dr*dr)-(x*x));
        if (pont_teruletten_van(Pont(x,y)) || pont_teruletten_van(Pont(x, -y))) {
            return false;
        }
    }
    return true;
}

void Negyszog::rajzol() const {
    std::cout << "Rajzolas: " << (*this) << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Negyszog& n)  {
    return os << (Sikidom&)n << " p2=" << n.getp2() << " p3=" << n.getp3() << " p4=" << n.getp4();
}
