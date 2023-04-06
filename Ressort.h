#pragma once
#include<iostream>
#include "Masse.h"
#include "Vecteur3D.h"

class Ressort{
public:
    //constructeurs, copie, destructeur
    Ressort(Masse& masse1, Masse& masse2, const double k, const double l0);
    Ressort(const Ressort& autre) = delete; // on empêche la copie
    Ressort& operator=(const Ressort& autre) = delete; //on interdit l’affectation par copie car la copie est interdite
    ~Ressort();//destructeur pour retire le ressorts supprimé de la liste des ressorts des masses

    //methodes
    Vecteur3D force_rappel(Masse* masse) const;
    std::ostream& affiche(std::ostream& out) const;

private:
    Masse* masse1_;  
    Masse* masse2_;
    double const k_;
    double const l0_;
};

//operateurs
std::ostream& operator<<(std::ostream&, const Ressort& );