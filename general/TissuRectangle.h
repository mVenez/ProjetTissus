#pragma once
#include<vector>
#include <iostream>
#include "Tissu.h"
#include "Vecteur3D.h"

class TissuRectangle : public Tissu {
public:
    //constructeur, copie, destructeur
    TissuRectangle(double masse_kg, Vecteur3D Largeur, Vecteur3D Longueur, Vecteur3D Position_origine, double coef_frottement, int densite_lineique, double k, double l0 = -1);//l0 = 1 convention choisi pour un ressort de longueur à vide égale à la distance entre deux masses, tel que le tissu soit au repos par défaut
    TissuRectangle(const Tissu&) = delete; //on interdit la copie
    TissuRectangle& operator=(const Tissu&) = delete; //affectation aussi interdite car copie interdite
    ~TissuRectangle(); // il faut désallouer la mémoire des masses
 
};