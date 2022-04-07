/**
 *  \file kor.h
 *  A Kor oszt�ly �s hozz� tartoz� f�ggv�nyek
 */

#ifndef KOR_H
#define KOR_H

#include "sikidom.h"

/// Kor oszt�ly
/// A Sikidom oszt�lyt egy sug�rral eg�sz�ti ki
class Kor : public Sikidom {
    double r; /// sug�r
public:
    /// Konstruktor
    /// A k�z�ppontot �s az egyik pontot a s�kidom oszt�ly konstruktora be�ll�tja
    /// A sug�r a k�z�ppontb�l �s a pont t�vols�g�b�l van kisz�m�tva
    /// @param dkp - k�z�ppont
    /// @param dp1 - k�r�v egy pontja
    Kor(const Pont& dkp, const Pont& dp1):Sikidom("kor", dkp, dp1), r(dkp.tavolsag(dp1)) {}

    /// Getter
    /// @return sug�r
    const double getR() const {return r;}

    /// Megmondja egy pontr�l, hogy az a s�kidom ter�let�n van-e
    /// @param p - a pont
    bool pont_teruletten_van(const Pont& p);

    /// Megadja, hogy a s�kidom teljes ter�let�vel az orig� k�z�ppont� dr sugar� k�r�n k�v�lre esik-e
    /// @param dr - k�r sugara
    bool origo_kp_koron_kivul_esik(const double dr);

    /// Kirajzolja a s�kidomot, azaz a << oper�torral ki�rja az adatait
    void rajzol() const;

    /// Destruktor
    ~Kor() {}
};

/// Glob�lis << oper�tor, ami ki�rja a k�r adatait
/// @param os - ostream
/// @param k - k�r
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Kor& k);

#endif // KOR_H
