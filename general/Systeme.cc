#include "Systeme.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Objet.h"
#include "Integrateur.h"
#include "Contrainte.h"
#include <vector>
#include <iostream>
using namespace std;

//constructeurs
Systeme::Systeme(vector<Objet*> vector_objet, vector<Contrainte*> vector_contraintes) 
    : Dessinable(), vector_objet_(vector_objet), vector_contrainte_(vector_contraintes) {}

Systeme::Systeme(Objet& objet, Contrainte& contrainte) 
    : Dessinable(), vector_objet_(vector<Objet*>(1, &objet)) , vector_contrainte_(vector<Contrainte*>(1, &contrainte)) {}


void Systeme::dessine_sur(SupportADessin& support) {
    for(auto objet : vector_objet_) {
        objet->dessine_sur(support);
    }
}

ostream& Systeme::affiche(ostream& out) const {
    out << "=============== Système " << this << " de " << vector_objet_.size();
    if (vector_objet_.size() == 1) {out << " objet ===============" << endl;}
        else {out << " objets ===============" << endl;}
    for (auto objet : vector_objet_) {
        out << *objet;
        //if last element no endl
        if (objet != vector_objet_.back()){
            out << endl;
        }
    }
    out << "=============== Système " << this << " de " << vector_objet_.size();
    if (vector_objet_.size() == 1) {out << " objet ===============" << endl;}
    return out;
}

void Systeme::evolue(const Integrateur& integrateur) const{
    for (auto objet : vector_objet_) {
        objet->mise_a_jour_forces();
        objet->evolue(integrateur);
    }
}
void Systeme::check() const {
    for (auto objet : vector_objet_) objet->check();
}

//operateurs
ostream& operator<<(ostream& out, Systeme const& systeme) {
    systeme.affiche(out);
    return out;
}
