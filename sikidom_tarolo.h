/**
 *  \file sikidom_tarolo.h
 *  A s�kidomok t�rol�s�ra haszn�lt heterog�n kollekci� oszt�lya
 */

#ifndef SIKIDOM_TAROLO_H
#define SIKIDOM_TAROLO_H

#include "sikidom.h"

/// Sikidom_tarolo oszt�ly
class Sikidom_tarolo {
    int meret;  /// m�rete
    Sikidom* *tomb; /// S�kidom pointereket t�rol� t�mb
public:
    ///Konstruktor
    /// @param m - t�mb m�rete
    Sikidom_tarolo(int m = 0):meret(m), tomb(nullptr) {}

    /// Getter
    /// @return meret
    int getMeret() {return meret;}

    /// [] oper�tor
    /// @param i - int, a t�mb indexe
    /// @return Sikidom*, a sikidomokat t�rol� t�mb adott elem�re mutat� pointer
    Sikidom* operator[](int i) {return tomb[i];}

    /// Add f�ggv�ny, amivel hozz� lehet adni egy �j elemet a t�mbh�z
    /// @param s - Sikidom*, az �j elem pointere
    void add(Sikidom* s);

    /// Ki�rja a t�rolt s�kidomokat
    void kiir();

    /// Destruktor
    /// Felszabad�tja a t�mbben t�rolt pointereket �s mag�t a t�mb�t is.
    ~Sikidom_tarolo();
};


#endif // SIKIDOM_TAROLO_H
