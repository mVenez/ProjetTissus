#include "Integrateur.h"
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

void Integrateur::evolue(Masse& masse, double dt) const {
    masse.set_position(masse.position() + (dt * masse.vitesse()));
    masse.set_vitesse(masse.vitesse() + (dt * masse.acceleration()));
    masse.mise_a_jour_forces();
}

void IntegrateurEulerCromer::evolue(Masse& masse, double dt) const {
    masse.set_vitesse(masse.vitesse() + (dt * masse.acceleration()));
    masse.set_position(masse.position() + (dt * masse.vitesse()));
    masse.mise_a_jour_forces();
}