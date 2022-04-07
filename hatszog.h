/**
 *  \file hatszog.h
 *  Az Hatszog osztály és hozzá tartozó függvények
 */

#ifndef HATSZOG_H
#define HATSZOG_H

#include "sikidom.h"

/// Hatszog osztály
/// A Sikidom osztályt 5 csúccsal egészíti ki
class Hatszog : public Sikidom {
    Pont p2, p3, p4, p5, p6; /// csúcsok
public:
    /// Konstruktor
    /// A középpontot és az egyik pontot a síkidom osztály konstruktora beállítja
    /// a másik öt csúcsot az elsõ csúcsból forgatjuk a középpont körül
    /// @param dkp - középpont
    /// @param dp1 - első csúcs
    Hatszog(const Pont& dkp, const Pont& dp1):Sikidom("hatszog", dkp, dp1),
        p2(dkp.pont_korul_forgat(dp1, 1*2*dp1.getPi()/6)),
        p3(dkp.pont_korul_forgat(dp1, 2*2*dp1.getPi()/6)),
        p4(dkp.pont_korul_forgat(dp1, 3*2*dp1.getPi()/6)),
        p5(dkp.pont_korul_forgat(dp1, 4*2*dp1.getPi()/6)),
        p6(dkp.pont_korul_forgat(dp1, 5*2*dp1.getPi()/6)){}

    /// Getter
    /// @return második csúcs
    const Pont& getp2() const {return p2;}

    /// Getter
    /// @return harmadik csúcs
    const Pont& getp3() const {return p3;}

    /// Getter
    /// @return negyedik csúcs
    const Pont& getp4() const {return p4;}

    /// Getter
    /// @return ötödik csúcs
    const Pont& getp5() const {return p5;}

    /// Getter
    /// @return hatodik csúcs
    const Pont& getp6() const {return p6;}

    /// Megmondja egy pontról, hogy az a síkidom területén van-e
    /// @param p - a pont
    bool pont_teruletten_van(const Pont& p);

    /// Megadja, hogy a síkidom teljes területével az origó középpontú dr sugarú körön kívülre esik-e
    /// @param dr - kör sugara
    bool origo_kp_koron_kivul_esik(const double dr);

    /// Kirajzolja a síkidomot, azaz a << operátorral kiírja az adatait
    void rajzol() const;

    /// Destruktor
    ~Hatszog() {}
};

/// Globális << operátor, ami kiírja az hatszög adatait
/// @param os - ostream
/// @param h - hatszög
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Hatszog& h);

#endif // HATSZOG_H
