#pragma once
#include<vector>
#include <iostream>
#include "Tissu.h"
#include "Vecteur3D.h"

class TissuChaine : public Tissu {
public:
    //constructeur, copie, destructeur
    TissuChaine(double masse_kg, double coef_frottement, Vecteur3D debutChaine, Vecteur3D finChaine, double pas_entre_masses, double k, bool fixe = false, double l0 = -1);
        /*bool fixe par défaut à false permet de fixer la première et dernière masse du tissu
        l0 = -1 convention choisi pour un ressort de longueur à vide égale à la distance entre deux masses, tel que le tissu soit au repos par défaut,*/
    TissuChaine(const Tissu&) = delete; //on interdit la copie
    TissuChaine& operator=(const Tissu&) = delete; //affectation aussi interdite car copie interdite
    ~TissuChaine(); // il faut désallouer la mémoire des masses
 
};