/**
 *  \file Nem_szab_har.cpp
 *  A háromszög osztály és hozzá tartozó függvények definíciója
 */

#include "nem_szab_har.h"

bool Nem_szab_haromszog::pont_teruletten_van(const Pont& p) {
    double ossz_terulet = 0;
    ossz_terulet += csucsokbol_heron(getp1(), p2, getkp());
    ossz_terulet += csucsokbol_heron(p2, p3, getkp());
    ossz_terulet += csucsokbol_heron(p3, getp1(), getkp());

    double terulet = 0;
    terulet += csucsokbol_heron(getp1(), p2, p);
    terulet += csucsokbol_heron(p2, p3, p);
    terulet += csucsokbol_heron(p3, getp1(), p);

    return (terulet <= ossz_terulet + 0.0001); //kerekítés hiba
}

bool Nem_szab_haromszog::origo_kp_koron_kivul_esik(const double dr) {
    for (double x = -dr; x <= dr; x+=0.05) {
        double y = sqrt((dr*dr)-(x*x));
        if (pont_teruletten_van(Pont(x,y)) || pont_teruletten_van(Pont(x, -y))) {
            return false;
        }
    }
    return true;
}

void Nem_szab_haromszog::rajzol() const {
    std::cout << "Rajzolas: " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Nem_szab_haromszog& h) {
    return os << (Sikidom&)h << " p2=" << h.getp2() << " p3=" << h.getp3();
}

