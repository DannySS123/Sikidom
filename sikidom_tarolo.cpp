/**
 *  \file sikidom_tarolo.cpp
 *  A s�kidomok t�rol�s�ra haszn�lt heterog�n kollekci� oszt�ly f�ggv�nyinek defini�l�sa
 */

#include "sikidom_tarolo.h"

void Sikidom_tarolo::add(Sikidom* s) {
    Sikidom **temp = new Sikidom*[meret + 1];
    if (temp == nullptr) {
        throw std::bad_alloc();
    }
    for (int i = 0; i < meret; ++i){
        temp[i] = tomb[i];
    }
    temp[meret] = s;
    meret++;
    delete[] tomb;
    tomb = temp;
}

void Sikidom_tarolo::kiir() {
    for (int i = 0; i < meret; ++i) {
        tomb[i]->rajzol();
    }
}

Sikidom_tarolo::~Sikidom_tarolo() {
    for (int i = 0; i < meret; ++i) {
        delete tomb[i];
    }
    delete[] tomb;
}
