#include<iostream>
#include "Ressort.h"
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

Ressort::Ressort(const Masse& masse1, const Masse& masse2, const double k, const double l0)
        : masse1(new Masse(masse1)), masse2(new Masse(masse2)), k(k) , l0(l0) {}

Vecteur3D Ressort::force_rappel(Masse const& masse) const{
    Vecteur3D force_rappel;
    Vecteur3D vecteur_rappel = masse1->position() - (masse2->position());
    double longueur = vecteur_rappel.norme();
    force_rappel = ~vecteur_rappel * (-k * (longueur - l0));
    if(masse == *masse1){
        return force_rappel;
    }else if(masse != *masse2){
        return -force_rappel;
    }else{
        throw invalid_argument("La masse n'est pas reliée au ressort");
    }
}

void Ressort::affiche() const {
    cout << "Ressort " << this << " : " << endl;
    cout << k << " # cst raideur" << endl;
    cout << l0 << " # longeur à repos" << endl;
    cout << "blablabla masse blablabla:"<< endl;
}

ostream& operator<<(ostream& out, const Ressort& res) {
    res.affiche();
}