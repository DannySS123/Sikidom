/**
 *  \file Nem_szab_har.h
 *  A nem szab�lyos h�romsz�g oszt�ly �s hozz� tartoz� f�ggv�nyek
 */
#ifndef NEM_SZAB_HAR_H
#define NEM_SZAB_HAR_H

#include "sikidom.h"

/// Nem_szab_haromszog oszt�ly
/// A Sikidom oszt�lyt 2 cs�ccsal eg�sz�ti ki
class Nem_szab_haromszog : public Sikidom {
    Pont p2, p3; /// m�sik k�t cs�cs
public:
    /// Konstruktor
    /// @param dkp - k�z�ppont
    /// @param dp1 - els� cs�cs
    /// @param dp2 - m�sodik cs�cs
    /// @param dp3 - harmadik cs�cs
    Nem_szab_haromszog(const Pont& dkp, const Pont& dp1, const Pont& dp2, const Pont& dp3):
        Sikidom("nem_szab_haromszog",dkp, dp1), p2(dp2), p3(dp3) {}

    /// Getter
    /// @return m�sodik cs�cs
    const Pont& getp2() const {return p2;}

    /// Getter
    /// @return harmadik cs�cs
    const Pont& getp3() const {return p3;}

    ///Megmondja egy pontr�l, hogy az a s�kidom ter�let�n van-e
    /// @param p - a pont
    bool pont_teruletten_van(const Pont& p);

    ///Megadja, hogy a s�kidom teljes ter�let�vel az orig� k�z�ppont� dr sugar� k�r�n k�v�lre esik-e
    /// @param dr - k�r sugara
    bool origo_kp_koron_kivul_esik(const double dr);

    ///Kirajzolja a s�kidomot, azaz a << oper�torral ki�rja az adatait
    void rajzol() const;

    ///Destruktor
    ~Nem_szab_haromszog() {}
};

/// Glob�lis << oper�tor, ami ki�rja a h�romsz�g adatait
/// @param os - ostream
/// @param h - nem szab�lyos h�romsz�g
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Nem_szab_haromszog& h);

#endif // NEM_SZAB_HAR_H
