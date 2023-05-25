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

//class IntegrateurNewmark

//constructeur
IntegrateurNewmark::IntegrateurNewmark(double dt, double epsilon) : Integrateur(dt), epsilon_(epsilon) {}

void IntegrateurNewmark::evolue(Masse& masse) const{
    //pour comprendre ce qui se passe ici voir section 2.3 du complément mathématique du projet
    Vecteur3D x_old(masse.position());
    Vecteur3D v_old(masse.vitesse());
    Vecteur3D a_old(masse.acceleration());
    Vecteur3D x(x_old);
    Vecteur3D v(v_old);
    Vecteur3D s(a_old);
    Vecteur3D q;
    Vecteur3D r;
    do {
        q = x;
        r = a_old;
        v = v_old + (dt_/2.0) * (r + s);
        x = x_old + dt_ * v + (dt_*dt_/6.0) * (r + 2.0*s);
    } while ((x - q).norme() > epsilon_);
    masse.set_position(x);
    masse.set_vitesse(v);
}
