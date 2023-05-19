#include "Contrainte.h"
#include "Tissu.h"
#include "Masse.h"
#include <cmath>
using namespace std;

//classe Contrainte
Contrainte::Contrainte(const Vecteur3D& position, double rayon)
    : position_(position), rayon_(rayon) {}

bool Contrainte::concerns(const Masse& masse) const {
    bool dans_sphere_action((position_ - masse.position()).norme() <= rayon_);
    return dans_sphere_action;
}

//classe Crochet
void Crochet::appliquer(Tissu& tissu, double t) const {
    for (auto masse : tissu.masses_concernes(*this)) {
        masse->ajoute_force(-(masse->force_subie()));
        masse->set_vitesse(Vecteur3D(0,0,0));
    }
}

//classe Impulsion
Impulsion::Impulsion(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, std::vector<Tissu*> cibles)
    : Contrainte(position, rayon), debut_(debut), fin_(fin), force_(force), tissus_cibles_(cibles) {
        for (auto tissu : tissus_cibles_) {
            for (auto masse : tissu->masses_concernes(*this)) {masses_cibles_.push_back(masse);}
        }
        if(masses_cibles_.empty()) cerr << "L'impulsion " << this << " ne concerne aucune masse" << endl;
    }

Impulsion::Impulsion(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, Tissu& cible)
    : Impulsion(position, rayon, debut, fin, force, vector<Tissu*>(1, &cible)) {}

void Impulsion::appliquer(Tissu& tissu, double t) const {
    if (t >= debut_ && t <= fin_) {
        for (auto masse : masses_cibles_) {
            if (tissu.contient(masse)) masse->ajoute_force(force_);
        }
    }
}

//classe ImpulsionSin
ImpulsionSin::ImpulsionSin(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, double frequence, std::vector<Tissu*> cibles)
    : Impulsion(position, rayon, debut, fin, force, cibles), f_(frequence) {}

ImpulsionSin::ImpulsionSin(const Vecteur3D &position, double rayon, double debut, double fin, Vecteur3D force, double frequence, Tissu &cible)
    : ImpulsionSin(position, rayon, debut, fin, force, frequence, vector<Tissu*>(1, &cible)) {}

void ImpulsionSin::appliquer(Tissu& tissu, double t) const {
    if (t >= debut_ && t <= fin_) {
        for (auto masse : masses_cibles_) {
            if (tissu.contient(masse)) {masse->ajoute_force(force_ * sin(2*M_PI * f_ * (t - debut_)));}
        }
    }
}
