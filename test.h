/**
 *  \file test.h
 *  A teszel�sre haszn�lt f�ggv�nye deklar�ci�ja
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

/// Beolvas�s f�ggv�nye, beolvassa az adott f�jlt �s a feladatnak megfelel�en bemenet alapj�n elt�rolja az adatokat. Hiba eset�n kiv�telt dob.
/// @param fajlnev - string, olvasand� f�jl neve
/// @param st - Sikidom_tarolo, ebben lesznek elt�rolva a beolvasott sikidomok
void beolvas(std::string fajlnev, Sikidom_tarolo& st);

/// Tesztel�s f�ggv�nye, megpr�b�l beolvasni, majd ha siker�lt akkor v�rja a felhaszn�l�i inputut a szabv�nyos bemeneten.
/// @param str - string, olvasand� f�jl neve
/// @param hanyadik - int, tesztesetnek a sz�ma
void test(std::string str, int hanyadik);

#endif // TEST_H
