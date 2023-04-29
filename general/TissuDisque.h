#pragma once
#define _USE_MATH_DEFINES //pour avoir pi
#include <vector>
#include <cmath>
#include <iostream>
#include "Tissu.h"
#include "Vecteur3D.h"

class TissuDisque : public Tissu {
public:
    //constructeur, copie, destructeur
    TissuDisque(double masse_kg, Vecteur3D centre, Vecteur3D normale_rayon, double pas_radial, double coef_frottement, double k, double angle = M_PI/9);//Angle par défaut de 20 degrés
    TissuDisque(const Tissu&) = delete; //on interdit la copie
    TissuDisque& operator=(const Tissu&) = delete; //affectation aussi interdite car copie interdite
    ~TissuDisque(); // il faut désallouer la mémoire des masses
 
};