#include "Integrateur.h"
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

//super-class Integrateur

//constructeur
Integrateur::Integrateur(double dt) : dt_(dt) {
    if (dt < 0){    //dt<=0 donne un problème lorsqu'on evolue le systeme dans GLWidget::TimerEvent()
        throw invalid_argument("Le pas de temps doit être positif");
    }
}

void Integrateur::evolue(Masse& masse) const {
    masse.set_position(masse.position() + (dt_ * masse.vitesse()));
    masse.set_vitesse(masse.vitesse() + (dt_ * masse.acceleration()));
}

//class IntegrateurEulerCromer

//constructeur
IntegrateurEulerCromer::IntegrateurEulerCromer(double dt) : Integrateur(dt) {}


void IntegrateurEulerCromer::evolue(Masse& masse) const{
    masse.set_vitesse(masse.vitesse() + (dt_ * masse.acceleration()));
    masse.set_position(masse.position() + (dt_ * masse.vitesse()));
}
