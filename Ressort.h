#pragma once
#include<iostream>
#include "Masse.h"
#include "Vecteur3D.h"

class Ressort{
public:
    Ressort(const Masse&, const Masse& masse2, const double k, const double l0);
    Vecteur3D force_rappel() const;
    void affiche() const;
private:
    double const k;
    double const l0;
    double longueur;
    Masse* masse1;  
    Masse* masse2;
};

std::ostream& operator<<(std::ostream& out, const Ressort& res);