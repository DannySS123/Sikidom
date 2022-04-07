/**
 *  \file negyzet.h
 *  A Negyzet osztály és hozzá tartozó függvények
 */

#ifndef NEGYZET_H
#define NEGYZET_H

#include "sikidom.h"

/// Negyzet osztály
/// A Sikidom osztályt 3 csúcssal egészíti ki
class Negyzet : public Sikidom {
    Pont p2, p3, p4; /// csúcsok
public:
    /// Konstruktor
    /// A középpontot és az egyik pontot a síkidom osztály konstruktora beállítja
    /// a másik három csúcsot az elsõ csúcsból forgatjuk a középpont körül
    /// @param dkp - középpont
    /// @param dp1 - első csúcs
    Negyzet(const Pont& dkp, const Pont& dp1):Sikidom("negyzet", dkp, dp1),
        p2(dkp.pont_korul_forgat(dp1, 1*dp1.getPi()/2)),
        p3(dkp.pont_korul_forgat(dp1, 2*dp1.getPi()/2)),
        p4(dkp.pont_korul_forgat(dp1, 3*dp1.getPi()/2)){}

    /// Getter
    /// @return második csúcs
    const Pont& getp2() const {return p2;}

    /// Getter
    /// @return harmadik csúcs
    const Pont& getp3() const {return p3;}

    /// Getter
    /// @return negyedik csúcs
    const Pont& getp4() const {return p4;}

    ///Megmondja egy pontról, hogy az a síkidom területén van-e
    /// @param p - a pont
    bool pont_teruletten_van(const Pont& p);

    ///Megadja, hogy a síkidom teljes területével az origó középpontú dr sugarú körön kívülre esik-e
    /// @param dr - kör sugara
    bool origo_kp_koron_kivul_esik(const double dr);

    ///Kirajzolja a síkidomot, azaz a << operátorral kiírja az adatait
    void rajzol() const;

    /// Destruktor
    ~Negyzet() {}
};

/// Globális << operátor, ami kiírja a négyzet adatait
/// @param os - ostream
/// @param n - négyzet
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Negyzet& n);

#endif // NEGYZET_H
