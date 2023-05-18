#include <iostream>
#include <vector>
#include "Tissu.h"
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"
#include "SupportADessin.h"
#include "Contrainte.h"
using namespace std;

//constructeurs
Tissu::Tissu(Masse& masse) : vector_masse_({&masse}), vector_ressort_({}) {}
Tissu::Tissu(std::vector<Masse*> vector_masse) : vector_masse_(vector_masse), vector_ressort_({}) {}


//destructeur
Tissu::~Tissu() {
    for (auto ressort : vector_ressort_) delete ressort;
}

//methodes
void Tissu::ajoute_masse(Masse* m) {
    vector_masse_.push_back(m);
}

void Tissu::connecte(Masse& masse1, Masse& masse2, double k, double l0) {
    Ressort* ressort = new Ressort(masse1, masse2, k, l0);
    vector_ressort_.push_back(ressort);  
}

bool Tissu::contient(Masse* m) const {
    bool trouve(false);
    for (auto masse : vector_masse_) if(masse == m) {trouve = true;};
    return trouve;
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
    out << "============ Tissu " << this << " ============" << endl;
    for (auto masse : vector_masse_) {
        masse->affiche(out);
        //if last element, no endl
        if (masse != vector_masse_.back()){
            out << endl;
        }
    }
    out << endl << endl;
    for (auto ressort : vector_ressort_) {
        ressort->affiche(out, false);
        //if last element, no endl
        if (ressort != vector_ressort_.back()){
            out << endl;
        }
    }
    out << "============ Tissu " << this << " ============" << endl;
    return out;
}

void Tissu::dessine_sur(SupportADessin& support) {
    for (auto masse : vector_masse_) {masse->dessine_sur(support);}
    for (auto ressort : vector_ressort_) {ressort->dessine_sur(support);}
}

void Tissu::applique_crochet(const Crochet& contrainte) const {
    for (auto masse : vector_masse_) {
        if (contrainte.concerns(*masse)) {
            masse->ajoute_force(-(masse->force_subie()));
            masse->set_vitesse(Vecteur3D(0,0,0));
        }
    }
} 
    
std::vector<Masse*> Tissu::masses_concernes(const Contrainte& contrainte) const {
    std::vector<Masse*> liste_masses_concernes;
    for (auto masse : vector_masse_) {
        if (contrainte.concerns(*masse)) liste_masses_concernes.push_back(masse);
    }
    return liste_masses_concernes;
}


void Tissu::applique_impulsion(const Impulsion& contrainte, Vecteur3D force ) const {
    for (auto masse : vector_masse_) {
        if (contrainte.concerns(*masse)) masse->ajoute_force(force);
    }
}
//surcharge de l'operateur << pour afficher un tissu
ostream& operator<<(ostream& out, const Tissu& tissu) {
    return tissu.affiche(out);
}
