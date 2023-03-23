#include<iostream>
#include "Ressort.h"
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

Ressort::Ressort(const Masse& masse1, const Masse& masse2, const double k, const double l0)
    : masse1_(new Masse(masse1)), masse2_(new Masse(masse2)), k_(k) , l0_(l0) {}
Ressort::Ressort(const Ressort& autre) // copie profonde
    : masse1_(new Masse(*autre.masse1_)), masse2_(new Masse(*autre.masse2_)), k_(autre.k_),  l0_(autre.l0_) {}
Ressort::~Ressort() {delete masse1_, delete masse2_;}

Vecteur3D Ressort::force_rappel() const{
    Vecteur3D force_rappel;
    Vecteur3D vecteur_rappel = masse1_->position() + (masse2_->position() * (-1)); //Faut controler si la formule est correcte j'ai pas compris
    double longueur = vecteur_rappel.norme();
    force_rappel = vecteur_rappel * (-k_ * (longueur - l0_));
    return force_rappel;
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