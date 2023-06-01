#include "Contrainte.h"
#include "Tissu.h"
#include "Masse.h"
#include <cmath>
using namespace std;

//classe Contrainte
Contrainte::Contrainte(const Vecteur3D& position, double rayon)
    : position_(position), rayon_(rayon) {
        if (rayon < 0) throw invalid_argument("Contrainte avec rayon negatif");
    }

bool Contrainte::concerns(const Masse& masse) const {
    bool dans_sphere_action((position_ - masse.position()).norme() <= rayon_);
    return dans_sphere_action;
}

//classe Crochet
void Crochet::appliquer(Tissu& tissu, double t) const {
    for (auto masse : tissu.masses_concernes(*this)) {
        masse->ajoute_force(-(masse->force_subie()));
        masse->set_vitesse(Vecteur3D(0,0,0));
        masse->fixe();
    }
}

//classe Impulsion
Impulsion::Impulsion(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, std::vector<Tissu*> cibles)
    : Contrainte(position, rayon), debut_(debut), fin_(fin), force_(force), tissus_cibles_(cibles) {
        //On controle les parametres passés
        if (debut < 0) throw invalid_argument("Impulsion avec instant t de debut negatif");
        if (fin < debut) {debut_ = fin; fin_ = debut;}
        if (force == Vecteur3D(0,0,0)) cerr << "L'Impulsion" << this << "a force nulle" << endl;

        //L'Impulsion memorise toutes les masses concernés à la construction
        for (auto tissu : tissus_cibles_) {
            for (auto masse : tissu->masses_concernes(*this)) {
                masses_cibles_.push_back(masse); 
                masse->gravite(false);
            }
        } 
        if(masses_cibles_.empty()) cerr << "L'impulsion " << this << " ne concerne aucune masse" << endl;
    }

Impulsion::Impulsion(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, Tissu& cible)
    : Impulsion(position, rayon, debut, fin, force, vector<Tissu*>(1, &cible)) {}

void Impulsion::appliquer(Tissu& tissu, double t) const {
    if (t >= debut_ && t <= fin_) {
        for (auto masse : masses_cibles_) {
            if (tissu.contient(masse)){
                //masse->ajoute_force( -(masse->masse() * g));
                masse->ajoute_force(force_);
            }
        }
    }
}

//classe ImpulsionSin
ImpulsionSin::ImpulsionSin(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, double frequence, std::vector<Tissu*> cibles)
    : Impulsion(position, rayon, debut, fin, force, cibles), f_(frequence) {
        if (frequence <= 0) throw invalid_argument("Fréquence d'impulsion sinusoidale negative ou nulle");
    }

ImpulsionSin::ImpulsionSin(const Vecteur3D &position, double rayon, double debut, double fin, Vecteur3D force, double frequence, Tissu &cible)
    : ImpulsionSin(position, rayon, debut, fin, force, frequence, vector<Tissu*>(1, &cible)) {}

void ImpulsionSin::appliquer(Tissu& tissu, double t) const {
    if (t >= debut_ && t <= fin_) {
        for (auto masse : masses_cibles_) {
            if (tissu.contient(masse)) {
                //masse->ajoute_force( -(masse->masse() * g));
                masse->ajoute_force(force_ * sin(2*M_PI * f_ * (t - debut_)));}
        }
    }
}
