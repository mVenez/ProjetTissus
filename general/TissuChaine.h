#pragma once
#include<vector>
#include <iostream>
#include "Tissu.h"
#include "Vecteur3D.h"

class TissuChaine : public Tissu {
public:
    //constructeur, copie, destructeur
    TissuChaine(double masse_kg, double coef_frottement, double k, double l0, std::vector<Vecteur3D>& tableau_position, bool fixe = false); //bool fixe par défaut à false permet de fixer le premier point du tissu
    TissuChaine(const Tissu&) = delete; //on interdit la copie
    TissuChaine& operator=(const Tissu&) = delete; //affectation aussi interdite car copie interdite
    ~TissuChaine(); // il faut désallouer la mémoire des masses
 
};