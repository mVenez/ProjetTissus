#include<iostream>
#include "Ressort.h"
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

Ressort::Ressort(Masse& masse1,Masse& masse2, const double k, const double l0)
    : masse1_(new Masse(masse1)), masse2_(new Masse(masse2)), k_(k) , l0_(l0) {
        if(k_ < 0){
            throw invalid_argument("La constante de raideur doit être positive");
        }
        if(l0_ < 0){
            throw invalid_argument("La longueur à repos doit être positive");
        }
        masse1.set_ressort(this);
        masse2.set_ressort(this);
    }
Ressort::~Ressort() {delete masse1_, delete masse2_;}


Vecteur3D Ressort::force_rappel(Masse* masse) const{
    Vecteur3D force_rappel;
    Vecteur3D vecteur_rappel = masse1_->position() - (masse2_->position());
    double longueur = vecteur_rappel.norme();
    force_rappel = ~vecteur_rappel * (-k_ * (longueur - l0_));
    //par défaut le calcul de la force de rappel est fait du point de vue de la masse 1, le if ci-dessous permet le changement de signe si l’appel à été fait du point de vue da la masse 2
    if(masse == masse1_){//égalité de pointeur
        return force_rappel;
    }else if(masse == masse2_){//égalité de pointeur
        return -force_rappel;
    }else{
        throw invalid_argument("La masse n'est pas reliée au ressort");
    }
}

void Ressort::affiche() const {
    cout << "Ressort " << this << " : " << endl;
    cout << "Constante de raideur : " <<  k_ << endl;
    cout << "Longeur à repos : " << l0_ << endl;
    cout << endl;
    cout << "Masse depart : Masse " << masse1_ << " : " << endl;
    cout << *masse1_ << endl;
    cout << "Masse arrivée : Masse " << masse2_ << " : " << endl;
    cout << *masse2_ << endl;
}

ostream& operator<<(ostream& out, const Ressort& res) {
    res.affiche();
    return out;
}