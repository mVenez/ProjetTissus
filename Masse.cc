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
void Masse::set_position(const Vecteur3D& nouvelle_position) {
    position_ = nouvelle_position;
}
void Masse::set_vitesse(const Vecteur3D& nouvelle_vitesse) {
    vitesse_ = nouvelle_vitesse;
}

// méthodes
ostream& Masse::affiche(ostream& out) const{
    out << "Masse : " << masse_ << "kg" << endl;
    out << "Coefficient de frottement : " << coefficient_frottement_ << endl;
    out << "Position : " << position_ << endl;
    out << "Vitesse : " << vitesse_ << endl;
    out << "Force subie : " << force_subie_ << endl;
    out << liste_ressort_.size() << " ressorts ";
    if (!liste_ressort_.empty()) {
        out << " :" << endl;
        for (auto ressort : liste_ressort_) {out << ressort << endl;}
    } else {out << endl;}
    return out;
}


void Masse::ajoute_force(Vecteur3D const& df){
    force_subie_ += (df);
}

Vecteur3D Masse::acceleration() const{
    return (force_subie_ * (1/masse_));
}

void Masse::mise_a_jour_forces(){
    Vecteur3D force_rappel;
    for(Ressort* ressort : liste_ressort_){
        force_rappel += (ressort->force_rappel(this));
    }
    Vecteur3D frottement = vitesse_ * (-coefficient_frottement_);
    Vecteur3D poids = masse_ * g;
    force_subie_ = force_rappel + frottement + poids;
}


// opérateurs

ostream& operator<<(ostream& out, Masse const& masse){
    masse.affiche(out);
    return out;
}