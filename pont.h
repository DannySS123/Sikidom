/**
 *  \file pont.h
 *  A Pont osztály és a hozzá tartozó függvények deklarációja
 */

#ifndef PONT_H
#define PONT_H

#include <iostream>
#include <math.h>

/// Pont osztály
class Pont {
    static const double pi; ///statikus pi, hogy az értéke később bármelyik pontból elérhető legyen.
    double x, y; ///Pont x és y koordinátái
public:
    /// Konstruktor
    /// @param dx - x koordináta
    /// @param dy - y koordináta
    Pont(double dx = 0, double dy = 0):x(dx), y(dy) {}

    /// X getter
    /// @return x - x koordináta
    double getX() const {return x;}

    /// Y getter
    /// @return y - y koordináta
    double getY() const {return y;}

    /// Pi getter
    /// @return pi - pi értéke
    double getPi() const {return pi;}

    /// X setter
    /// @param dx - x új értéke
    void setX(double dx) {x = dx;}

    /// Y setter
    /// @param dy - y új értéke
    void setY(double dy) {y = dy;}

    /// Két Pont távolságát adja meg (pitagoras tétellel)
    /// @param p2 - a másik pont amitől mérjük a távolságot
    /// @return a két pont távolsága
    double tavolsag(const Pont& p2) const;

    /// Az adott pont körül forgat egy másik pontot
    /// Az adott pontot origóba toljuk, és ugyanezzel a vektorral eltoljuk a másik pontot is, majd forgatunk és visszatoljuk
    /// @param dp1 - a másik pont, amit forgatni fogunk
    /// @param radian - forgatás szöge radiánban
    /// @return Pont - az elforgatás után kapott
    Pont pont_korul_forgat(const Pont& dp1, double radian) const;
};

/// Globális << operátor a Pont adatainak kiírásához
/// @param os - ostream
/// @param p - Pont
/// @return os - ostream
std::ostream& operator<<(std::ostream& os, const Pont& p);

/// Globális >> operátor a Pont adatainak beolvasásához
/// @param is - istream
/// @param p - Pont
/// @return is - istream
std::istream& operator>>(std::istream& is, Pont& p);

#endif // PONT_H
