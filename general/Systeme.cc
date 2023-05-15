#include "Systeme.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Tissu.h"
#include "Integrateur.h"
#include "Contrainte.h"
#include <vector>
#include <iostream>
using namespace std;

//constructeurs
Systeme::Systeme(vector<Tissu*> vector_tissus, vector<Contrainte*> vector_contraintes) 
    : vector_tissus_(vector_tissus), vector_contraintes_(vector_contraintes) {}

Systeme::Systeme(Tissu& tissu, Contrainte& contrainte) 
    : vector_tissus_(vector<Tissu*>(1, &tissu)) , vector_contraintes_(vector<Contrainte*>(1, &contrainte)) {}

Systeme::Systeme(Tissu& tissu) 
    : vector_tissus_(vector<Tissu*>(1, &tissu)) , vector_contraintes_(vector<Contrainte*>()) {}


void Systeme::dessine_sur(SupportADessin& support) {
    for(auto tissu : vector_tissus_) {
        tissu->dessine_sur(support);
    }
}

ostream& Systeme::affiche(ostream& out) const {
    out << "=============== Système " << this << " de " << vector_tissus_.size();
    if (vector_tissus_.size() == 1) {out << " tissu ===============" << endl;}
        else {out << " objets ===============" << endl;}
    for (auto tissu : vector_tissus_) {
        out << *tissu;
        //if last element no endl
        if (tissu != vector_tissus_.back()){
            out << endl;
        }
    }
    out << "=============== Système " << this << " de " << vector_tissus_.size();
    if (vector_tissus_.size() == 1) {out << " tissu ===============" << endl;}
    return out;
}

void Systeme::evolue(const Integrateur& integrateur) const{
    for (auto tissu : vector_tissus_) {
        tissu->mise_a_jour_forces();
        for (auto contrainte : vector_contraintes_) {
            contrainte->appliquer(*tissu, 30);
        }
        tissu->evolue(integrateur);
    }
}
void Systeme::check() const {
    for (auto tissu : vector_tissus_) tissu->check();
}

//operateurs
ostream& operator<<(ostream& out, Systeme const& systeme) {
    systeme.affiche(out);
    return out;
}
