#include<iostream>
#include "Ressort.h"
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

Ressort::Ressort(Masse& masse1,Masse& masse2, const double k, const double l0)
    : masse1_(&masse1), masse2_(&masse2), k_(k) , l0_(l0) {
        if(k_ <= 0){
            throw invalid_argument("La constante de raideur doit être  strictement positive");
        }
        if(l0_ < 0){
            throw invalid_argument("La longueur à repos doit être positive");
        }
        masse1.set_ressort(this);
        masse2.set_ressort(this);
    }

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
        throw invalid_argument("La masse n'est pas reliée au ressort"); // ici on pourrait renvoyer le vecteur nul, ça depend de la façon dans laquelle on construit le tissu
    }
}

ostream& Ressort::affiche(ostream& out) const {
    out << "Ressort " << this << " : " << endl;
    out << "Constante de raideur : " <<  k_ << endl;
    out << "Longeur à repos : " << l0_ << endl;
    out << "Masse associées au ressort :" << endl << "{"<< endl;
    out << "Masse depart : Masse " << masse1_ << " : " << endl;
    out << *masse1_ << endl;
    out << "Masse arrivée : Masse " << masse2_ << " : " << endl;
    out << *masse2_ << "}" << endl;
    return out;
}

ostream& operator<<(ostream& out, const Ressort& res) {
    res.affiche(out);
    return out;
}