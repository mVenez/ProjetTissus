#include "Systeme.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Tissu.h"
#include "Objet.h"
#include <vector>
#include <iostream>
using namespace std;

//constructeurs
Systeme::Systeme(vector<Objet*> vector_objet_) 
    : Dessinable(), vector_objet_(vector_objet_) {}

Systeme::Systeme(Objet& objet) 
    : Dessinable(), vector_objet_(vector<Objet*>(1, &objet)) {}

//methodes
void Systeme::dessine_sur(SupportADessin& support) {
    support.dessine(*this); 
}

ostream& Systeme::affiche(ostream& out) const {
    cout << "le système est composé de " << vector_objet_.size() << " objets {" << endl;
    for (auto objet : vector_objet_) {
        cout << *objet << endl;
    }
    cout << "}" << endl;
    return out;
}

ostream& operator<<(ostream& out, Systeme const& systeme) {
    systeme.affiche(out);
    return out;
}