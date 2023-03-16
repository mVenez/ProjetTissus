#include<iostream>
#include "Masse.h"
#include "Vecteur3D.h"

class Ressort{
public:
    Vecteur3D force_rappel() const;
private:
    double const k;
    double const l0;
    double longueur;
    Masse masse1;
    Masse masse2;
};