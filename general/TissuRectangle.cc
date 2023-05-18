#include <vector>
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"
#include "SupportADessin.h"
#include "TissuRectangle.h"
#include "constantes.h"
using namespace std;

//constructeurs
TissuRectangle::TissuRectangle(double masse_kg, Vecteur3D Largeur, Vecteur3D Longueur, Vecteur3D Position_origine, double coef_frottement, double pas_entre_masses, double k, bool fixe, double l0) : Tissu() {
    /*bool fixe par défaut à false permet de fixer le contour du tissu
    l0 = 1 convention choisi pour un ressort de longueur à vide égale à la distance entre deux masses, tel que le tissu soit au repos par défaut,*/

    if(l0 < 0){
        l0 = pas_entre_masses;//permet par défaut d’avoir un ressort de longueur à vide égale à la distance entre deux masses
    }

    //on vérifie que les vecteurs largeur longueur sont bien orthogonaux, si ce n’est pas le cas on modifie largeur en lui soustrayant sa projection sur longueur pour rendre les vecteurs orthogonaux
    if(abs(Largeur*Longueur) > epsilon){
        Largeur -= (Largeur*~Longueur)*~Longueur;
    }

    //on calcul le nombre de masse sur chaque coté du rectangle
    int nb_masse_largeur = (Largeur.norme()/pas_entre_masses) + 1 + epsilon;
    int nb_masse_longueur = (Longueur.norme()/pas_entre_masses) + 1 + epsilon;

    //on crée les masses et les ressorts
    for(int n = 0; n < nb_masse_largeur; ++n){
        for(int m = 0; m < nb_masse_longueur; ++m){
            Masse* masse = new Masse(masse_kg, coef_frottement, Position_origine + n*pas_entre_masses*(~Largeur) + m*pas_entre_masses*(~Longueur));
            ajoute_masse(masse);
            if(fixe && (n == 0 || n == nb_masse_largeur - 1 || m == 0 || m == nb_masse_longueur - 1)){//si le parametre fixe est à true on fixe le contour du rectangle
                vector_masse_.back()->fixe();
            }
            if(m >= 1){
                connecte(*vector_masse_[vector_masse_.size() - 2], *vector_masse_.back(), k, l0);
            }
            if(n >= 1){
                connecte(*vector_masse_[vector_masse_.size() - nb_masse_longueur - 1], *vector_masse_.back(), k, l0);
            }
        }
    }
}

//destructeur
TissuRectangle::~TissuRectangle() {
    for (auto masse : vector_masse_) delete masse;
}
