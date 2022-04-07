/**
 *  \file sikidom.h
 *  A s�kidomo oszt�ly �s hozz� tartoz� f�ggv�nyek
 */

#ifndef SIKIDOM_H
#define SIKIDOM_H

#include "pont.h"
#include <string.h>

/// Sikidom absztrakt oszt�ly
class Sikidom {
    std::string tipus; /// Sikidom t�pusa, neve
    Pont kp, p1;    /// Minden S�kidomnak van legal�bb 2 pontja, a k�z�ppontja �s egy cs�csa (k�r eset�ben a k�r�v egy pontja)
public:
    /// Konstruktor
    /// @param tip - s�kidom t�pusa
    /// @param dkp - s�kidom k�z�ppontja
    /// @param dp1 - s�kidom egy cs�csa
    Sikidom(const std::string tip, const Pont& dkp, const Pont& dp1):tipus(tip), kp(dkp), p1(dp1){}

    /// Getter
    /// @return k�z�ppont
    const Pont& getkp() const {return kp;}

    /// Getter
    /// @return els� cs�cs
    const Pont& getp1() const {return p1;}

    /// Getter
    /// @return t�pus
    const std::string& getTipus() const {return tipus;}

    /// Tiszt�n virtu�lis rajzol� f�ggv�ny
    virtual void rajzol() const = 0;

    /// Tiszt�n virtu�lis f�ggv�ny ami megmondja egy pontr�l, hogy az a s�kidom ter�let�n van-e
    virtual bool pont_teruletten_van(const Pont& p) = 0;

    /// Tiszt�n virtu�lis f�ggv�ny ami megmondja, hogy a s�kidom teljes ter�let�vel az orig� k�z�ppont� dr sugar� k�r�n k�v�lre esik-e
    /// @param dr - a k�r sugara
    virtual bool origo_kp_koron_kivul_esik(const double dr) = 0;

    /// Virtu�lis destruktor
    virtual ~Sikidom(){};
};


/// Glob�lis << oper�tor, a s�kidom adatait �rja ki
/// @param os - ostream
/// @param s - sikidom
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Sikidom& s);

/// Heron k�plettel kisz�molja egy h�romsz�g ter�let�t az oldalhosszakb�l
/// @param a - oldalhossz
/// @param b - oldalhossz
/// @param c - oldalhossz
/// @return h�romsz�g ter�lete
double heron(double a, double b, double c);

/// El�z� k�plethez hasonl�an m�k�dik, csak ez pontokb�l sz�molja a h�romsz�g ter�let�t heron k�plettel
/// @param p1 - cs�cs
/// @param p2 - cs�cs
/// @param p3 - cs�cs
/// @return h�romsz�g ter�lete
double csucsokbol_heron(Pont p1, Pont p2, Pont p3);

#endif // SIKIDOM_H
