#include "Contrainte.h"
#include "Masse.h"

Contrainte::Contrainte(const Vecteur3D& position, double rayon)
    : position_(position), rayon_(rayon) {}

bool Contrainte::concerns(const Masse& masse) const {
    bool dans_sphere_action((position_ - masse.position()).norme() < rayon_);
    return dans_sphere_action;
}

void Crochet::appliquer(Tissu& tissu, double dt) const {
    /*for (auto masse : tissu.vector_masse()) {
        if (concerns(*masse))
            masse.
    }*/
}
