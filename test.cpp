/**
 *  \file test.h
 *  A teszelésre használt függvénye definíciója
 */

#include "test.h"

void beolvas(std::string fajlnev, Sikidom_tarolo& st) {
    std::ifstream readFile(fajlnev);
    std::string str, err;

    if (readFile.fail()) {
        err = "Nem sikerult megnyitni a fajlt. (" + fajlnev + ")";
        throw std::ios_base::failure(err);
    }

    Pont kp, p1;
    err = "Rossz koordinata";
    while (readFile >> str) {
        if (!(readFile >> kp >> p1)) {
            throw std::invalid_argument(err);
        }
        if (str == "kor") {
            Kor *k = new Kor(kp, p1);
            if ((k->origo_kp_koron_kivul_esik(1.0))) {
                st.add(k);
            } else {
                delete k;
            }
        } else if (str == "haromszog") {
            Haromszog *h = new Haromszog(kp, p1);
            if ((h->origo_kp_koron_kivul_esik(1.0))) {
                st.add(h);
            } else {
                delete h;
            }
        } else if (str == "negyzet") {
            Negyzet *n = new Negyzet(kp, p1);
            if ((n->origo_kp_koron_kivul_esik(1.0))) {
                st.add(n);
            } else {
                delete n;
            }
        } else if (str == "otszog") {
            Otszog *o = new Otszog(kp, p1);
            if ((o->origo_kp_koron_kivul_esik(1.0))) {
                st.add(o);
            } else {
                delete o;
            }
        } else if (str == "hatszog") {
            Hatszog *h = new Hatszog(kp, p1);
            if ((h->origo_kp_koron_kivul_esik(1.0))) {
                st.add(h);
            } else {
                delete h;
            }
        } else if (str == "negyszog") {
            Pont a,b;
            if (!(readFile >> a >> b)) {
                throw std::invalid_argument(err);
            }
            Negyszog *n = new Negyszog(kp, p1, a, b);
            if ((n->origo_kp_koron_kivul_esik(1.0))) {
                st.add(n);
            } else {
                delete n;
            }
        } else if (str == "nem_szab_haromszog") {
            Pont a,b;
            if (!(readFile >> a >> b)){
                throw std::invalid_argument(err);
            }
            if (kp.getX() != (p1.getX() + a.getX() + b.getX())/3 || kp.getY() != (p1.getY() + a.getY() + b.getY())/3) {
                err = "Rossz kp";
                throw std::invalid_argument(err);
            }
            Nem_szab_haromszog *h = new Nem_szab_haromszog(kp, p1, a, b);
            if ((h->origo_kp_koron_kivul_esik(1.0))) {
                st.add(h);
            } else {
                delete h;
            }
        } else {
            err = "Nincs ilyen sikidom: " + str;
            throw std::invalid_argument(err);
        }
        std::cout << str << kp << p1 << std::endl;
    }
    std::cout << "---------" << std::endl;
    readFile.close();
}

void test(std::string str, int hanyadik) {
    Sikidom_tarolo st;
    try {
        std::cout << "***Teszt " << hanyadik << ":" << std::endl << "------------" << std::endl;
        beolvas(str, st);
    } catch(std::bad_alloc& e) {
        std::cout <<  "Hiba: " << e.what() << std::endl << std::endl << std::endl;
        return;
    } catch(std::ios_base::failure& e) {
        std::cout <<  "Hiba: " << e.what() << std::endl << std::endl << std::endl;
        return;
    } catch(std::invalid_argument& e) {
        std::cout <<  "Hiba: " << e.what() << std::endl << std::endl << std::endl;
        return;
    }
    std::cout << "Origo kozeppuntu egysegkoron kivulre eso sikidomok: " << std::endl;
    st.kiir();
    std::cout << std::endl << std::endl << "Adjon meg pontokat 'x y' alakban" << std::endl;
    Pont p;
    bool talalt = false;
    while (!std::cin.eof()) {
        try {
            std::cin >> p;
        } catch(std::invalid_argument& e) {
            std::cout <<  "Hiba: " << e.what() << std::endl << std::endl << std::endl;
            std::cin.clear ();
            std::cin.ignore(1000,'\n');
            continue;
        }
        if (!std::cin.eof()) {
            std::cout << "A pont ezeknek a sikidomoknak a teruleten van:" << std::endl;
            talalt = false;
            for (int i = 0; i < st.getMeret(); ++i) {
                if (st[i]->pont_teruletten_van(p)) {
                    st[i]->rajzol();
                    talalt = true;
                }
            }
            if (!talalt) {
                std::cout << "Egyik sikidom teruleten sincs a pont." << std::endl;
            }
            std::cout << std::endl;
        }
    }
}
