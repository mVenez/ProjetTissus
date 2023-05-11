#include "Systeme.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Objet.h"
#include "Integrateur.h"
#include <vector>
#include <iostream>
using namespace std;

//constructeurs
Systeme::Systeme(vector<Objet*> vector_objet_) 
    : Dessinable(), vector_objet_(vector_objet_) {}

Systeme::Systeme(Objet& objet) 
    : Dessinable(), vector_objet_(vector<Objet*>(1, &objet)) {}

/*//getters
std::vector<Objet*> Systeme::vector_objet() const {return vector_objet_;}*/
//methodes
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

//operateurs
ostream& operator<<(ostream& out, Systeme const& systeme) {
    systeme.affiche(out);
    return out;
}
