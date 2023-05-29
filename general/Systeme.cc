#include <vector>
#include <iostream>
#include "Systeme.h"
#include "Contrainte.h"
using namespace std;

//constructeurs (tous les combinaisons)
Systeme::Systeme(vector<Tissu*> vector_tissus, vector<Contrainte*> vector_contraintes) 
    : vector_tissus_(vector_tissus), vector_contraintes_(vector_contraintes), t_(0) {}

Systeme::Systeme(Tissu& tissu, Contrainte& contrainte) 
    : Systeme(vector<Tissu*>(1, &tissu), vector<Contrainte*>(1, &contrainte)) {}

Systeme::Systeme(Tissu& tissu, std::vector<Contrainte*> vector_contraintes)
    : Systeme(vector<Tissu*>(1, &tissu), vector_contraintes) {}

Systeme::Systeme(std::vector<Tissu*> vector_tissus, Contrainte& contrainte) 
    : Systeme(vector_tissus, vector<Contrainte*>(1, &contrainte)) {}


//affichage
void Systeme::dessine_sur(SupportADessin& support) {
    for(auto tissu : vector_tissus_) {
        tissu->dessine_sur(support);
    }
}

ostream& Systeme::affiche(ostream& out) const {
    out << "=============== Système " << this << " de " << vector_tissus_.size();
    if (vector_tissus_.size() == 1) {out << " tissu ===============";}
        else {out << " tissus ===============";}
    out << " t = " << t_ << endl;
    for (auto tissu : vector_tissus_) {
        out << *tissu;
        //if last element no endl
        if (tissu != vector_tissus_.back()){
            out << endl;
        }
    }
    out << "=============== Système " << this << " de " << vector_tissus_.size();
    if (vector_tissus_.size() == 1) {out << " tissu ===============" << endl;}
        else {out << " tissus ===============" << endl;}
    return out;
}

ostream& Systeme::affiche_positions(ostream& out) const {   
    out << "## (position) Systeme au temps : " << t_ << endl;
    for (auto tissu : vector_tissus_) {tissu->affiche_positions(out);}
    return out;
}

//méthode principale de la simulation
void Systeme::evolue(const Integrateur& integrateur) {
    for (auto tissu : vector_tissus_) {
        tissu->mise_a_jour_forces();    //on calcule toutes les forces exercées sur chaque masse
        for (auto contrainte : vector_contraintes_) {
            contrainte->appliquer(*tissu, t_);  //on applique toutes les contraintes
        }
        t_ += integrateur.dt(); //le temps est mis à jour
        tissu->evolue(integrateur); //le systeme evolue
    }
}

//check complet du système
void Systeme::check() const {
    for (auto tissu : vector_tissus_) tissu->check();
}

//operateurs
ostream& operator<<(ostream& out, Systeme const& systeme) {
    systeme.affiche(out);
    return out;
}
