#pragma once
#include<iostream>
#include "Masse.h"
#include "Vecteur3D.h"

class Ressort{
public:
    //constructeurs
    Ressort(Masse&, Masse& , const double, const double);
    Ressort(const Ressort& autre) = delete; // on empêche la copie

    //methodes
    Vecteur3D force_rappel(Masse* masse) const;
    std::ostream& affiche(std::ostream& out) const;

private:
    Masse* masse1_;  
    Masse* masse2_;
    double const k_;
    double const l0_;
    //double longueur_; //pas utilisé? controler la methode force_rappel()
};

//operateurs
std::ostream& operator<<(std::ostream&, const Ressort& );