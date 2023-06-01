#include<iostream>
#include <algorithm>
#include "Masse.h"
#include "Ressort.h"
#include "constantes.h"
#include "Vecteur3D.h"
#include "SupportADessin.h"
#include "Dessinable.h"
using namespace std;

// constructeur
Masse::Masse(double masse, double coefficient_frottement, Vecteur3D position, Vecteur3D vitesse, Vecteur3D acceleration, std::vector<Ressort*> liste_ressort, bool fixe, bool gravite)
    : masse_(masse), coefficient_frottement_(coefficient_frottement), position_(position), vitesse_(vitesse), force_subie_(masse * acceleration), liste_ressort_(liste_ressort), fixe_(fixe), gravite_(gravite)  {
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

Vecteur3D Masse::acceleration() const{
    return (force_subie_ * (1/masse_));
}

// setters
void Masse::fixe(bool fixe){
    fixe_ = fixe;
}
void Masse::gravite(bool gravite) {
    gravite_ = gravite;
}

void Masse::set_ressort(Ressort* ressort){  // ajoute un ressort à la liste actuelle de ressorts
    liste_ressort_.push_back(ressort);
}

void Masse::unset_ressort(Ressort* ressort, bool gestion_suppression_ressort){ // bool par défaut à true
    if (gestion_suppression_ressort){
        delete ressort;
        ressort = nullptr;
    }else{
        liste_ressort_.erase(remove(liste_ressort_.begin(), liste_ressort_.end(), ressort), liste_ressort_.end());
    }
}

void Masse::set_position(const Vecteur3D& nouvelle_position) {
    position_ = nouvelle_position;
}
void Masse::set_vitesse(const Vecteur3D& nouvelle_vitesse) {
    vitesse_ = nouvelle_vitesse;
}

// méthodes
void Masse::ajoute_force(Vecteur3D const& df){
    if (!fixe_) {
        force_subie_ += (df);
    }
}

void Masse::mise_a_jour_forces(){
    if (fixe_) {
        force_subie_ = Vecteur3D(0,0,0);
        return;
    }
    Vecteur3D force_rappel;
    for(Ressort* ressort : liste_ressort_){
        force_rappel += (ressort->force_rappel(this));
    }
    Vecteur3D frottement = vitesse_ * (-coefficient_frottement_);
    force_subie_ = force_rappel + frottement;

    Vecteur3D poids = masse_ * g;
    if (gravite_) force_subie_+= poids;
}

ostream& Masse::affiche(ostream& out) const{
    out << "===== Masse " << this << " =====" << endl;
    out << "Fixe : " << (fixe_ ? "oui" : "non") << endl;
    out << "Masse de la masse : " << masse_ << "kg" << endl;
    out << "Coefficient de frottement : " << coefficient_frottement_ << endl;
    out << "Position : " << position_ << endl;
    out << "Vitesse : " << vitesse_ << endl;
    out << "Force subie : " << force_subie_ << endl;
    out << liste_ressort_.size() << " ressorts ";
    if (!liste_ressort_.empty()) {
        out << " :" << endl;
        for (auto ressort : liste_ressort_) {out << ressort << endl;}
    } else {out << endl;}
    out << "===== Masse " << this << " =====" << endl ;
    return out;
}

void Masse::dessine_sur(SupportADessin& support) {
    support.dessine(*this); 
}

//méthodes pour le check() du tissu
void Masse::check_attache() const {
    if (liste_ressort_.empty()) throw runtime_error("La masse n'est lié à aucun ressort");
    for (auto ressort : liste_ressort_) ressort->check_masse_connectee(this);
}

void Masse::check_ressort(const Ressort* ptr_res) const {
    bool trouve(false);
    for (auto ressort : liste_ressort_) {
        if (ressort == ptr_res) {trouve = true;}
    }
    if (!trouve) throw runtime_error("Le ressort n'est pas attaché à la masse choisie");
}

// opérateurs
ostream& operator<<(ostream& out, Masse const& masse){
    masse.affiche(out);
    return out;
}