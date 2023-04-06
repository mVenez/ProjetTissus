#pragma once
#include<iostream>
#include "Masse.h"
#include "Vecteur3D.h"

class Ressort{
public:
    //constructeurs
    Ressort(Masse& masse1, Masse& masse2, const double k, const double l0);
    Ressort(const Ressort& autre) = delete; // on empêche la copie
    Ressort& operator=(const Ressort& autre) = delete; //on interdit l’affectation par copie car la copie est interdite

    //methodes
    Vecteur3D force_rappel(Masse* masse) const;
    std::ostream& affiche(std::ostream& out) const;
    void check_masses() const;  //check si les masse d'arrivé et depart sont les mêmes et si le ressort figure dans les listes de ressorts des deux masses
    void check_masse_connectee(const Masse*) const; //check si une masse est connectée à ce ressort


private:
    Masse* masse1_;  
    Masse* masse2_;
    double const k_;
    double const l0_;
};

//operateurs
std::ostream& operator<<(std::ostream&, const Ressort& );