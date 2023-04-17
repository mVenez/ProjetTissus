#include <iostream>
#include <vector>
#include "Tissu.h"
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#include "Objet.h"
using namespace std;

//constructeurs
Tissu::Tissu(Masse& masse) : vector_masse_({&masse}) {}

Tissu::Tissu(std::vector<Masse*> vector_masse) : vector_masse_(vector_masse) {}


//destructeur
Tissu::~Tissu() {
    for (auto ressort : vector_ressort_) delete ressort;
}

//getters
vector<Masse*> Tissu::vector_masse() const {
    return vector_masse_;
}
vector<Ressort*> Tissu::vector_ressort() const {
    return vector_ressort_;
}


//methodes
void Tissu::ajoute_masse(Masse* m) {
    vector_masse_.push_back(m);
}

void Tissu::connecte(Masse& masse1, Masse& masse2, double k, double l0) {
    Ressort* ressort = new Ressort(masse1, masse2, k, l0);
    vector_ressort_.push_back(ressort);
}

void Tissu::mise_a_jour_forces() const {
    for (auto masse : vector_masse_) masse->mise_a_jour_forces();
}

void Tissu::evolue(const Integrateur& integrateur) const {
    for(auto masse : vector_masse_) integrateur.evolue(*masse);

}

void Tissu::check() const {
    for (auto masse : vector_masse_) {
        masse->check_attache();
    }
    for (auto ressort : vector_ressort_) {
        ressort->check_masses();
    }

}

ostream& Tissu::affiche(ostream& out) const {
    out << "======================" << endl;
    out << "Tissu : " << this << endl;
    out << "Les masses sont : {" << endl;
    for (auto masse : vector_masse_) {
        masse->affiche(out);
        out << endl;
    }
    out << "}" << endl << endl;
    out << "Les ressorts sont : {" << endl;
    for (auto ressort : vector_ressort_) {
        ressort->affiche(out, false);
        out << endl;
    }
    out << "}" << endl;
    out << "======================" << endl << endl;
    return out;
}

void Tissu::dessine_sur(SupportADessin& support) {
    support.dessine(*this); 
}



//surcharge de l'operateur << pour afficher un tissu
ostream& operator<<(ostream& out, const Tissu& tissu) {
    return tissu.affiche(out);
}