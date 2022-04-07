/**
 *  \file negyszog.h
 *  A Kor osztály és hozzá tartozó függvények
 */

#ifndef NEGYSZOG_H
#define NEGYSZOG_H

#include "sikidom.h"

/// Negyszog osztály
/// A Sikidom osztályt 3 csúccsal egészíti ki
class Negyszog : public Sikidom {
    Pont p2, p3, p4; /// csúcsok
public:
    /// Konstruktor
    /// A középpont a négy csúcsból van kiszámolva
    /// A középpontot és az egyik pontot a síkidom osztály konstruktora beállítja
    /// @param dp1 - elsõ csúcs
    /// @param dp2 - második csúcs
    /// @param dp3 - harmadik csúcs
    /// @param dp4 - negyedik csúcs
    Negyszog(const Pont& dp1, const Pont& dp2, const Pont& dp3, const Pont& dp4):
        Sikidom("negyszog",
                Pont((dp1.getX() + dp2.getX() + dp3.getX() + dp4.getX())/4,
                     (dp1.getY() + dp2.getY() + dp3.getY() + dp4.getY())/4), dp1),
        p2(dp2), p3(dp3), p4(dp4){}

    /// Getter
    /// @return második csúcs
    const Pont& getp2() const {return p2;}

    /// Getter
    /// @return harmadik csúcs
    const Pont& getp3() const {return p3;}

    /// Getter
    /// @return negyedik csúcs
    const Pont& getp4() const {return p4;}

    /// Megmondja egy pontról, hogy az a síkidom területén van-e
    /// @param p - a pont
    bool pont_teruletten_van(const Pont& p);

    /// Megadja, hogy a síkidom teljes területével az origó középpontú dr sugarú körön kívülre esik-e
    /// @param dr - kör sugara
    bool origo_kp_koron_kivul_esik(const double dr);

    /// Kirajzolja a síkidomot, azaz a << operátorral kiírja az adatait
    void rajzol() const;

    /// Destruktor
    ~Negyszog() {}

};

/// Globális << operátor, ami kiírja a négyszög adatait
/// @param os - ostream
/// @param n - négyszög
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Negyszog& n);

#endif // NEGYSZOG_H
