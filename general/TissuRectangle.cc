#include <vector>
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"
#include "SupportADessin.h"
#include "TissuRectangle.h"
#include "constantes.h"
using namespace std;

//constructeurs
TissuRectangle::TissuRectangle(double masse_kg, Vecteur3D Largeur, Vecteur3D Longueur, Vecteur3D Position_origine, double coef_frottement, int densite_lineique, double k, double l0) : Tissu() {//la densité linéique est le nombre de masse par unité de mesure
    if(l0 < 0){
        l0 = (1/densite_lineique);//permet par défaut d’avoir un ressort de longueur à vide égale à la distance entre deux masses
    }

    //on vérifie que les vecteurs largeur longueur sont bien orthogonaux, si ce n’est pas le cas on modifie largeur en lui soustrayant sa projection sur longueur pour rendre les vecteurs orthogonaux
    if(abs(Largeur*Longueur) > epsilon){
        Largeur -= (Largeur*~Longueur)*~Longueur;
    }

    for(int n = 0; (n*~Largeur).norme() < Largeur.norme(); n++){
        for(int m = 0; (m*~Longueur).norme() < Longueur.norme(); m++){
            Masse* masse = new Masse(masse_kg, coef_frottement, Position_origine + n*~Largeur + m*~Longueur, Vecteur3D(0, 0, 0));
            ajoute_masse(masse);
            if(m > 1){
                connecte(*vector_masse_[vector_masse_.size() - 2], *vector_masse_.back(), k, l0);
            }
            //if(n > 1){
            //    connecte(*vector_masse_[vector_masse_.size() - 2 - m], *vector_masse_.back(), k, l0);
            //}
        }
    }

};
