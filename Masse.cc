#include<iostream>
#include "Masse.h"
#include "Ressort.h"
#include "Constantes.h"
#include "Vecteur3D.h"
using namespace std;


Masse::Masse(double masse, double coefficient_frottement, Vecteur3D position, Vecteur3D vitesse, Vecteur3D force_subie)
    : masse_(masse), coefficient_frottement_(coefficient_frottement), position_(position), vitesse_(vitesse), force_subie_(force_subie) {
        if (masse <= 0){
            throw std::invalid_argument("La masse doit être positive");
        }
    }

double Masse::masse() const{
    return masse_;
}

double Masse::coefficient_frottement() const{
    return coefficient_frottement_;
}

Vecteur3D Masse::position() const{
    return position_;
}

Vecteur3D Masse::vitesse() const{
    return vitesse_;
}

Vecteur3D Masse::force_subie() const{
    return force_subie_;
}

void Masse::ajoute_force(Vecteur3D const& df){
    force_subie_ = force_subie_.addition(df);
}

Vecteur3D Masse::acceleration() const{
    return force_subie_.mult(1/masse_);
}

void Masse::mise_a_jour_forces(){
    Vecteur3D force_rappel;
    //for(Ressort* ressort : ressorts_){
    //    force_rappel = force_rappel.addition(ressort->force_rappel());
    //}
    Vecteur3D frottement = vitesse_.mult(-coefficient_frottement_);
}

ostream& operator<<(ostream& sortie, Masse const& masse){
    sortie << "Masse : " << masse.masse() << "kg" << endl;
    sortie << "Coefficient de frottement : " << masse.coefficient_frottement() << endl;
    sortie << "Position : " << masse.position() << endl;
    sortie << "Vitesse : " << masse.vitesse() << endl;
    sortie << "Force subie : " << masse.force_subie() << endl;
    return sortie;
}