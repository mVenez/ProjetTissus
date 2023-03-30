#include "Integrateur.h"
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

//super-class Integrateur

//constructeur
Integrateur::Integrateur(double dt) : dt_(dt) {
    if (dt <= 0){
        throw invalid_argument("Le pas de temps doit être positif");
    }
}

void Integrateur::evolue(Masse& masse) const {
    masse.set_position(masse.position() + (dt_ * masse.vitesse()));
    masse.set_vitesse(masse.vitesse() + (dt_ * masse.acceleration()));
    masse.mise_a_jour_forces();
}

//class IntegrateurEulerCromer

//constructeur
IntegrateurEulerCromer::IntegrateurEulerCromer(double dt) : Integrateur(dt) {}


void IntegrateurEulerCromer::evolue(Masse& masse) const{
    masse.set_vitesse(masse.vitesse() + (dt_ * masse.acceleration()));
    masse.set_position(masse.position() + (dt_ * masse.vitesse()));
    masse.mise_a_jour_forces();
}