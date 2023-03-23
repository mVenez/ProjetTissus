#include<iostream>
#include "Masse.h"
#include "Ressort.h"
#include "Constantes.h"
#include "Vecteur3D.h"
using namespace std;

// constructeur
Masse::Masse(double masse, double coefficient_frottement, Vecteur3D position, Vecteur3D vitesse, Vecteur3D acceleration, std::vector<Ressort*> liste_ressort)
    : masse_(masse), coefficient_frottement_(coefficient_frottement), position_(position), vitesse_(vitesse), force_subie_(masse * acceleration), liste_ressort_(liste_ressort) {
    if (masse <= 0){
        throw invalid_argument("La masse doit être positive");
    }
}


// getters
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


// setters
void Masse::set_ressort(Ressort* ressort){
    liste_ressort_.push_back(ressort);
}
void Masse::set_ressort(std::vector<Ressort*> liste_ressort){
    liste_ressort_ = liste_ressort;
}


// méthodes
void Masse::ajoute_force(Vecteur3D const& df){
    force_subie_ += (df);
}

Vecteur3D Masse::acceleration() const{
    return force_subie_ * (1/masse_);
}

void Masse::mise_a_jour_forces(){
    Vecteur3D force_rappel;
    for(Ressort* ressort : liste_ressort_){
        force_rappel = force_rappel + (ressort->force_rappel(this));
    }
    Vecteur3D frottement = vitesse_ * (-coefficient_frottement_);
    force_subie_ = force_rappel + frottement;
}


// opérateurs

ostream& operator<<(ostream& sortie, Masse const& masse){
    sortie << "Masse : " << masse.masse() << "kg" << endl;
    sortie << "Coefficient de frottement : " << masse.coefficient_frottement() << endl;
    sortie << "Position : " << masse.position() << endl;
    sortie << "Vitesse : " << masse.vitesse() << endl;
    sortie << "Force subie : " << masse.force_subie() << endl;
    return sortie;
}