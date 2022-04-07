/**
 *  \file kor.h
 *  A Kor osztály és hozzá tartozó függvények
 */

#ifndef KOR_H
#define KOR_H

#include "sikidom.h"

/// Kor osztály
/// A Sikidom osztályt egy sugárral egészíti ki
class Kor : public Sikidom {
    double r; /// sugár
public:
    /// Konstruktor
    /// A középpontot és az egyik pontot a síkidom osztály konstruktora beállítja
    /// A sugár a középpontból és a pont távolságából van kiszámítva
    /// @param dkp - középpont
    /// @param dp1 - körív egy pontja
    Kor(const Pont& dkp, const Pont& dp1):Sikidom("kor", dkp, dp1), r(dkp.tavolsag(dp1)) {}

    /// Getter
    /// @return sugár
    const double getR() const {return r;}

    /// Megmondja egy pontról, hogy az a síkidom területén van-e
    /// @param p - a pont
    bool pont_teruletten_van(const Pont& p);

    /// Megadja, hogy a síkidom teljes területével az origó középpontú dr sugarú körön kívülre esik-e
    /// @param dr - kör sugara
    bool origo_kp_koron_kivul_esik(const double dr);

    /// Kirajzolja a síkidomot, azaz a << operátorral kiírja az adatait
    void rajzol() const;

    /// Destruktor
    ~Kor() {}
};

/// Globális << operátor, ami kiírja a kör adatait
/// @param os - ostream
/// @param k - kör
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Kor& k);

#endif // KOR_H
