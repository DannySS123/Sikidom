/**
 *  \file hatszog.cpp
 *  Az Hatszog osztály és hozzá tartozó függvények definíciója
 */

#include "hatszog.h"

bool Hatszog::pont_teruletten_van(const Pont& p) {
    double ossz_terulet = 0;
    double terulet = 0;
    double a, b;
    a = getkp().tavolsag(p2);
    b = p2.tavolsag(p3);
    ossz_terulet = 6 * heron(a, a, b); // 6 háromszög területe
    terulet += csucsokbol_heron(getp1(), p2, p);
    terulet += csucsokbol_heron(p2, p3, p);
    terulet += csucsokbol_heron(p3, p4, p);
    terulet += csucsokbol_heron(p4, p5, p);
    terulet += csucsokbol_heron(p5, p6, p);
    terulet += csucsokbol_heron(p6, getp1(), p);

    return (terulet <= ossz_terulet + 0.0001); //kerekítés hiba
}

bool Hatszog::origo_kp_koron_kivul_esik(const double dr) {
    for (double x = -dr; x <= dr; x+=0.05) {
        double y = sqrt((dr*dr)-(x*x));
        if (pont_teruletten_van(Pont(x,y)) || pont_teruletten_van(Pont(x, -y))) {
            return false;
        }
    }
    return true;
}

void Hatszog::rajzol() const {
    std::cout << "Rajzolas: " << (*this) << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Hatszog& h) {
     return os << (Sikidom&)h << " p2=" << h.getp2() << " p3=" << h.getp3() << " p4=" << h.getp4() << " p5=" << h.getp5() << " p6=" << h.getp6();
}
