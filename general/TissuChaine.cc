#include <vector>
#include "Masse.h"
#include "Ressort.h"
#include "TissuChaine.h"
using namespace std;

//constructeurs
TissuChaine::TissuChaine(double masse_kg, double coef_frottement, Vecteur3D debutChaine, Vecteur3D finChaine, double pas_entre_masses, double k, bool fixe, double l0) : Tissu() {
    /*bool fixe par défaut à false permet de fixer la première et dernière masse du tissu
    l0 = -1 convention choisi pour un ressort de longueur à vide égale à la distance entre deux masses, tel que le tissu soit au repos par défaut,*/

    if(l0 < 0){
        l0 = pas_entre_masses;//permet par défaut d’avoir un ressort de longueur à vide égale à la distance entre deux masses
    }

    //on calcul le vecteur qui parcours la chaines
    Vecteur3D vecteur_chaine = finChaine - debutChaine;
    if (vecteur_chaine.norme() < epsilon) {
        throw invalid_argument("Les deux points de la chaine sont confondus");
    }

    //on calcul le nombre de masse sur la chaine
    int nb_masse = (vecteur_chaine.norme()/pas_entre_masses) + 1 + epsilon;

    //on crée les masses et les ressorts
    for(int n = 0; n < nb_masse; ++n){
        Masse* masse = new Masse(masse_kg, coef_frottement, debutChaine + n*pas_entre_masses*(~vecteur_chaine));
        ajoute_masse(masse);
        if(n >= 1){
            connecte(*vector_masse_[vector_masse_.size() - 2], *vector_masse_.back(), k, l0);
        }
    }

    if (fixe) {//fixe la première et dernière masse si le parametre fixe est à true
        vector_masse_.front()->fixe();
        vector_masse_.back()->fixe();
    }
}

//destructeur
TissuChaine::~TissuChaine() {
    for (auto masse : vector_masse_) delete masse;
}
