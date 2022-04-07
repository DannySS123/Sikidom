/**
 *  \file haromszog.h
 *  A háromszög osztály és hozzá tartozó függvények
 */

#ifndef HAROMSZOG_H
#define HAROMSZOG_H

#include "sikidom.h"

/// Haromszog osztály
/// A Sikidom osztályt 2 csúccsal egészíti ki
class Haromszog : public Sikidom {
    Pont p2, p3; /// második és harmadik csúcs
public:
    /// Konstruktor
    /// A középpontot és az egyik pontot a síkidom osztály konstruktora beállítja
    /// a másik két csúcsot az elsõ csúcsból forgatjuk a középpont körül
    /// @param dkp - középpont
    /// @param dp1 - egy csúcs
    Haromszog(const Pont& dkp, const Pont& dp1):Sikidom("haromszog", dkp, dp1),
        p2(dkp.pont_korul_forgat(dp1, 1*2*dp1.getPi()/3)),
        p3(dkp.pont_korul_forgat(dp1, 2*2*dp1.getPi()/3)){}

    /// Getter
    /// @return második csúcs
    const Pont& getp2() const {return p2;}

    /// Getter
    /// @return harmadik csúcs
    const Pont& getp3() const {return p3;}

    /// Megmondja egy pontról, hogy az a síkidom területén van-e
    /// @param p - a pont
    bool pont_teruletten_van(const Pont& p);

    /// Megadja, hogy a síkidom teljes területével az origó középpontú dr sugarú körön kívülre esik-e
    /// @param dr - kör sugara
    bool origo_kp_koron_kivul_esik(const double dr);

    /// Kirajzolja a síkidomot, azaz a << operátorral kiírja az adatait
    void rajzol() const;

    /// Destruktor
    ~Haromszog() {}
};

/// Globális << operátor, ami kiírja a háromszög adatait
/// @param os - ostream
/// @param h - háromszög
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Haromszog& h);

#endif // HAROMSZOG_H
