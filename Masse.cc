#include<iostream>
#include "Masse.h"
#include "Ressort.h"
#include "constantes.h"
#include "Vecteur3D.h"
using namespace std;


Masse::Masse(double masse, double coefficient_frottement, Vecteur3D position, Vecteur3D vitesse, Vecteur3D force_subie)
    : masse(masse), coefficient_frottement(coefficient_frottement), position_(position), vitesse(vitesse), force_subie(force_subie) {
        if (masse <= 0){
            throw std::invalid_argument("La masse doit être positive");
        }
    }

Vecteur3D Masse::position() const{
    return position_;
}

void Masse::ajoute_force(Vecteur3D const& df){
    force_subie = force_subie.addition(df);
}

Vecteur3D Masse::acceleration() const{
    return force_subie.mult(1/masse);
}

void Masse::mise_a_jour_forces(){
    Vecteur3D force_rappel;
    for(Ressort* ressort : ressorts){
        force_rappel = force_rappel.addition(ressort->force_rappel());
    }
    Vecteur3D frottement = vitesse.mult(-coefficient_frottement);
}
