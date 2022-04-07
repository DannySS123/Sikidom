/**
 *  \file sikidom_tarolo.h
 *  A síkidomok tárolására használt heterogén kollekció osztálya
 */

#ifndef SIKIDOM_TAROLO_H
#define SIKIDOM_TAROLO_H

#include "sikidom.h"

/// Sikidom_tarolo osztály
class Sikidom_tarolo {
    int meret;  /// mérete
    Sikidom* *tomb; /// Síkidom pointereket tároló tömb
public:
    ///Konstruktor
    /// @param m - tömb mérete
    Sikidom_tarolo(int m = 0):meret(m), tomb(nullptr) {}

    /// Getter
    /// @return meret
    int getMeret() {return meret;}

    /// [] operátor
    /// @param i - int, a tömb indexe
    /// @return Sikidom*, a sikidomokat tároló tömb adott elemére mutató pointer
    Sikidom* operator[](int i) {return tomb[i];}

    /// Add függvény, amivel hozzá lehet adni egy új elemet a tömbhöz
    /// @param s - Sikidom*, az új elem pointere
    void add(Sikidom* s);

    /// Kiírja a tárolt síkidomokat
    void kiir();

    /// Destruktor
    /// Felszabadítja a tömbben tárolt pointereket és magát a tömböt is.
    ~Sikidom_tarolo();
};


#endif // SIKIDOM_TAROLO_H
