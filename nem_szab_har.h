/**
 *  \file Nem_szab_har.h
 *  A nem szabályos háromszög osztály és hozzá tartozó függvények
 */
#ifndef NEM_SZAB_HAR_H
#define NEM_SZAB_HAR_H

#include "sikidom.h"

/// Nem_szab_haromszog osztály
/// A Sikidom osztályt 2 csúccsal egészíti ki
class Nem_szab_haromszog : public Sikidom {
    Pont p2, p3; /// másik két csúcs
public:
    /// Konstruktor
    /// @param dkp - középpont
    /// @param dp1 - elsõ csúcs
    /// @param dp2 - második csúcs
    /// @param dp3 - harmadik csúcs
    Nem_szab_haromszog(const Pont& dkp, const Pont& dp1, const Pont& dp2, const Pont& dp3):
        Sikidom("nem_szab_haromszog",dkp, dp1), p2(dp2), p3(dp3) {}

    /// Getter
    /// @return második csúcs
    const Pont& getp2() const {return p2;}

    /// Getter
    /// @return harmadik csúcs
    const Pont& getp3() const {return p3;}

    ///Megmondja egy pontról, hogy az a síkidom területén van-e
    /// @param p - a pont
    bool pont_teruletten_van(const Pont& p);

    ///Megadja, hogy a síkidom teljes területével az origó középpontú dr sugarú körön kívülre esik-e
    /// @param dr - kör sugara
    bool origo_kp_koron_kivul_esik(const double dr);

    ///Kirajzolja a síkidomot, azaz a << operátorral kiírja az adatait
    void rajzol() const;

    ///Destruktor
    ~Nem_szab_haromszog() {}
};

/// Globális << operátor, ami kiírja a háromszög adatait
/// @param os - ostream
/// @param h - nem szabályos háromszög
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Nem_szab_haromszog& h);

#endif // NEM_SZAB_HAR_H
