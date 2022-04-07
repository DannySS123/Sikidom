/**
 *  \file test.h
 *  A teszelésre használt függvénye deklarációja
 */

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include "pont.h"
#include "negyzet.h"
#include "kor.h"
#include "haromszog.h"
#include "otszog.h"
#include "hatszog.h"
#include "negyszog.h"
#include "nem_szab_har.h"
#include "sikidom_tarolo.h"
#include "memtrace.h"

/// Beolvasás függvénye, beolvassa az adott fájlt és a feladatnak megfelelõen bemenet alapján eltárolja az adatokat. Hiba esetén kivételt dob.
/// @param fajlnev - string, olvasandó fájl neve
/// @param st - Sikidom_tarolo, ebben lesznek eltárolva a beolvasott sikidomok
void beolvas(std::string fajlnev, Sikidom_tarolo& st);

/// Tesztelés függvénye, megpróbál beolvasni, majd ha sikerült akkor várja a felhasználói inputut a szabványos bemeneten.
/// @param str - string, olvasandó fájl neve
/// @param hanyadik - int, tesztesetnek a száma
void test(std::string str, int hanyadik);

#endif // TEST_H
