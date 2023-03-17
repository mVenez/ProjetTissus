#include<iostream>
#include "Ressort.h"
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

Vecteur3D Ressort::force_rappel() const{
    Vecteur3D force_rappel;
    Vecteur3D vecteur_rappel = masse1.position() + (masse2.position() * (-1)); //Faut controler si la formule est correcte j'ai pas compris
    double longueur = vecteur_rappel.norme();
    force_rappel = vecteur_rappel * (-k * (longueur - l0));
    return force_rappel;
}

