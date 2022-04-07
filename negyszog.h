/**
 *  \file negyszog.h
 *  A Kor oszt�ly �s hozz� tartoz� f�ggv�nyek
 */

#ifndef NEGYSZOG_H
#define NEGYSZOG_H

#include "sikidom.h"

/// Negyszog oszt�ly
/// A Sikidom oszt�lyt 3 cs�ccsal eg�sz�ti ki
class Negyszog : public Sikidom {
    Pont p2, p3, p4; /// cs�csok
public:
    /// Konstruktor
    /// A k�z�ppont a n�gy cs�csb�l van kisz�molva
    /// A k�z�ppontot �s az egyik pontot a s�kidom oszt�ly konstruktora be�ll�tja
    /// @param dp1 - els� cs�cs
    /// @param dp2 - m�sodik cs�cs
    /// @param dp3 - harmadik cs�cs
    /// @param dp4 - negyedik cs�cs
    Negyszog(const Pont& dp1, const Pont& dp2, const Pont& dp3, const Pont& dp4):
        Sikidom("negyszog",
                Pont((dp1.getX() + dp2.getX() + dp3.getX() + dp4.getX())/4,
                     (dp1.getY() + dp2.getY() + dp3.getY() + dp4.getY())/4), dp1),
        p2(dp2), p3(dp3), p4(dp4){}

    /// Getter
    /// @return m�sodik cs�cs
    const Pont& getp2() const {return p2;}

    /// Getter
    /// @return harmadik cs�cs
    const Pont& getp3() const {return p3;}

    /// Getter
    /// @return negyedik cs�cs
    const Pont& getp4() const {return p4;}

    /// Megmondja egy pontr�l, hogy az a s�kidom ter�let�n van-e
    /// @param p - a pont
    bool pont_teruletten_van(const Pont& p);

    /// Megadja, hogy a s�kidom teljes ter�let�vel az orig� k�z�ppont� dr sugar� k�r�n k�v�lre esik-e
    /// @param dr - k�r sugara
    bool origo_kp_koron_kivul_esik(const double dr);

    /// Kirajzolja a s�kidomot, azaz a << oper�torral ki�rja az adatait
    void rajzol() const;

    /// Destruktor
    ~Negyszog() {}

};

/// Glob�lis << oper�tor, ami ki�rja a n�gysz�g adatait
/// @param os - ostream
/// @param n - n�gysz�g
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Negyszog& n);

#endif // NEGYSZOG_H
