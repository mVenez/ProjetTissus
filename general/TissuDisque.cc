#define _USE_MATH_DEFINES //pour avoir pi
#include <vector>
#include <cmath>
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"
#include "SupportADessin.h"
#include "TissuDisque.h"
#include "constantes.h"
using namespace std;

TissuDisque::TissuDisque(double masse_kg, Vecteur3D centre, Vecteur3D normale_rayon, double pas_radial, double coef_frottement, double k, double angle) : Tissu(){

    //on trouve un vecteur sur le disque en faisant le produit vectoriel de "normale_rayon" avec un vecteur unitaire de la base canonique qui n'est pas colineaire avec "normale_rayon"
    Vecteur3D vecteur_sur_disque_unitaire;
    if (normale_rayon.x() != 0) vecteur_sur_disque_unitaire = ~(Vecteur3D(0, 1, 0) ^ normale_rayon);
    else vecteur_sur_disque_unitaire = ~(Vecteur3D(1, 0, 0) ^ normale_rayon);

    //on calcul le nombre de masse sur le rayon
    int nb_masse_rayon = normale_rayon.norme()*pas_radial;
     
    //on crée les masses et les ressorts
    for(double rad = 0; rad < 2*M_PI-epsilon; rad += angle){
        for(int n = 1; n < nb_masse_rayon; ++n){
            Masse* masse = new Masse(masse_kg, coef_frottement, centre + n*pas_radial*~vecteur_sur_disque_unitaire);
            ajoute_masse(masse);
            if(n >= 1){
                connecte(*vector_masse_[vector_masse_.size() - 2], *vector_masse_.back(), k, pas_radial);
            }
            if(rad >= angle-epsilon){
                connecte(*vector_masse_[vector_masse_.size() - nb_masse_rayon - 2], *vector_masse_.back(), k, 2*sin(angle/2)*pas_radial*n);
            }
        }
    }
    //masse centrale
    Masse* masse = new Masse(masse_kg, coef_frottement, centre);
    ajoute_masse(masse);
    for(int n = 0; n < 2*M_PI/angle-epsilon; ++n){
        connecte(*vector_masse_[n], *vector_masse_.back(), k, pas_radial);
    }
}

//destructeur
TissuDisque::~TissuDisque() {
    for (auto masse : vector_masse_) delete masse;
    Tissu::~Tissu();
}