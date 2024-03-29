#include<iostream>
#include "Ressort.h"
#include "Masse.h"
#include "SupportADessin.h"
using namespace std;

//constructeurs
Ressort::Ressort(Masse& masse1,Masse& masse2, const double k, const double l0)
    : masse1_(&masse1), masse2_(&masse2), k_(k) , l0_(l0) {
        if(k_ <= 0){
            throw invalid_argument("La constante de raideur doit être  strictement positive");
        }
        if(l0_ < 0){
            throw invalid_argument("La longueur à repos doit être positive");
        }
        masse1_->set_ressort(this);
        masse2_->set_ressort(this);
    }

//destructeur
Ressort::~Ressort(){
    masse1_->unset_ressort(this, false);
    masse2_->unset_ressort(this, false);
}


//méthodes
Vecteur3D Ressort::force_rappel(Masse* masse) const{
    Vecteur3D force_rappel;
    Vecteur3D vecteur_rappel = masse1_->position() - (masse2_->position());
    double longueur = vecteur_rappel.norme();
    force_rappel = ~vecteur_rappel * (-k_ * (longueur - l0_));
    //par défaut le calcul de la force de rappel est fait du point de vue de la masse 1, le if ci-dessous permet le changement de signe si l’appel à été fait du point de vue da la masse 2
    if(masse == masse1_) {   //égalité de pointeur
        return force_rappel;
    } else if(masse == masse2_) { //égalité de pointeur
        return -force_rappel;
    } else {
        throw invalid_argument("La masse n'est pas reliée au ressort");
    }
}

ostream& Ressort::affiche(ostream& out, bool affichage_masses_complet) const {
    out << "===== Ressort " << this << " =====" << endl;
    out << "Constante de raideur : " <<  k_ << endl;
    out << "Longeur à repos : " << l0_ << endl;
    out << "Masses associées au ressort :" << endl;
    out << "Masse depart : " << masse1_ << endl;
    if(affichage_masses_complet){
        out << *masse1_;
    }
    out << "Masse arrivée : " << masse2_ << endl;
    if(affichage_masses_complet){
        out << *masse2_;
    }
    out << "===== Ressort " << this << " =====" << endl ;
    return out;
}

void Ressort::dessine_sur(SupportADessin &support) {
    support.dessine(*this);
}

//getters
Masse* Ressort::masse1() const {return masse1_;}
Masse* Ressort::masse2() const {return masse2_;}
double Ressort::k() const {return k_;}
double Ressort::l0() const {return l0_;}
double Ressort::l() const {return (masse1_->position() - masse2_->position()).norme();}

//méthodes pour le check() du tissu
void Ressort::check_masses() const {
    if (masse1_ == masse2_) throw runtime_error("Le ressort est attaché aux deux extremités à la même masse");
}
void Ressort::check_masse_connectee(const Masse* masse) const {
    if (masse != masse1_ && masse!= masse2_ ) throw runtime_error("La masse n'est pas connecté au ressort choisi");
}


//opérateurs
ostream& operator<<(ostream& out, const Ressort& res) {
    res.affiche(out);
    return out;
}