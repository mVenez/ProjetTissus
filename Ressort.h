#pragma once
#include<iostream>
#include "Masse.h"
#include "Vecteur3D.h"

class Ressort{
public:
    Ressort(Masse&, Masse& , const double, const double);
    Ressort(const Ressort& autre); // on empêche la copie
    ~Ressort();
    Vecteur3D force_rappel(Masse* masse) const;
    void affiche() const;
private:
    double const k_;
    double const l0_;
    double longueur_; //pas utilisé? controler la methode force_rappel()
    Masse* masse1_;  
    Masse* masse2_;
};

std::ostream& operator<<(std::ostream&, const Ressort& );