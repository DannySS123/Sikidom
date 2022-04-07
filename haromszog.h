/**
 *  \file haromszog.h
 *  A h�romsz�g oszt�ly �s hozz� tartoz� f�ggv�nyek
 */

#ifndef HAROMSZOG_H
#define HAROMSZOG_H

#include "sikidom.h"

/// Haromszog oszt�ly
/// A Sikidom oszt�lyt 2 cs�ccsal eg�sz�ti ki
class Haromszog : public Sikidom {
    Pont p2, p3; /// m�sodik �s harmadik cs�cs
public:
    /// Konstruktor
    /// A k�z�ppontot �s az egyik pontot a s�kidom oszt�ly konstruktora be�ll�tja
    /// a m�sik k�t cs�csot az els� cs�csb�l forgatjuk a k�z�ppont k�r�l
    /// @param dkp - k�z�ppont
    /// @param dp1 - egy cs�cs
    Haromszog(const Pont& dkp, const Pont& dp1):Sikidom("haromszog", dkp, dp1),
        p2(dkp.pont_korul_forgat(dp1, 1*2*dp1.getPi()/3)),
        p3(dkp.pont_korul_forgat(dp1, 2*2*dp1.getPi()/3)){}

    /// Getter
    /// @return m�sodik cs�cs
    const Pont& getp2() const {return p2;}

    /// Getter
    /// @return harmadik cs�cs
    const Pont& getp3() const {return p3;}

    /// Megmondja egy pontr�l, hogy az a s�kidom ter�let�n van-e
    /// @param p - a pont
    bool pont_teruletten_van(const Pont& p);

    /// Megadja, hogy a s�kidom teljes ter�let�vel az orig� k�z�ppont� dr sugar� k�r�n k�v�lre esik-e
    /// @param dr - k�r sugara
    bool origo_kp_koron_kivul_esik(const double dr);

    /// Kirajzolja a s�kidomot, azaz a << oper�torral ki�rja az adatait
    void rajzol() const;

    /// Destruktor
    ~Haromszog() {}
};

/// Glob�lis << oper�tor, ami ki�rja a h�romsz�g adatait
/// @param os - ostream
/// @param h - h�romsz�g
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Haromszog& h);

#endif // HAROMSZOG_H
