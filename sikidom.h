/**
 *  \file sikidom.h
 *  A síkidomo osztály és hozzá tartozó függvények
 */

#ifndef SIKIDOM_H
#define SIKIDOM_H

#include "pont.h"
#include <string.h>

/// Sikidom absztrakt osztály
class Sikidom {
    std::string tipus; /// Sikidom típusa, neve
    Pont kp, p1;    /// Minden Síkidomnak van legalább 2 pontja, a középpontja és egy csúcsa (kör esetében a körív egy pontja)
public:
    /// Konstruktor
    /// @param tip - síkidom típusa
    /// @param dkp - síkidom középpontja
    /// @param dp1 - síkidom egy csúcsa
    Sikidom(const std::string tip, const Pont& dkp, const Pont& dp1):tipus(tip), kp(dkp), p1(dp1){}

    /// Getter
    /// @return középpont
    const Pont& getkp() const {return kp;}

    /// Getter
    /// @return elsõ csúcs
    const Pont& getp1() const {return p1;}

    /// Getter
    /// @return típus
    const std::string& getTipus() const {return tipus;}

    /// Tisztán virtuális rajzoló függvény
    virtual void rajzol() const = 0;

    /// Tisztán virtuális függvény ami megmondja egy pontról, hogy az a síkidom területén van-e
    virtual bool pont_teruletten_van(const Pont& p) = 0;

    /// Tisztán virtuális függvény ami megmondja, hogy a síkidom teljes területével az origó középpontú dr sugarú körön kívülre esik-e
    /// @param dr - a kör sugara
    virtual bool origo_kp_koron_kivul_esik(const double dr) = 0;

    /// Virtuális destruktor
    virtual ~Sikidom(){};
};


/// Globális << operátor, a síkidom adatait írja ki
/// @param os - ostream
/// @param s - sikidom
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Sikidom& s);

/// Heron képlettel kiszámolja egy háromszög területét az oldalhosszakból
/// @param a - oldalhossz
/// @param b - oldalhossz
/// @param c - oldalhossz
/// @return háromszög területe
double heron(double a, double b, double c);

/// Elõzõ képlethez hasonlóan mûködik, csak ez pontokból számolja a háromszög területét heron képlettel
/// @param p1 - csúcs
/// @param p2 - csúcs
/// @param p3 - csúcs
/// @return háromszög területe
double csucsokbol_heron(Pont p1, Pont p2, Pont p3);

#endif // SIKIDOM_H
