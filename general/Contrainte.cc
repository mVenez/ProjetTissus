#include "Contrainte.h"
#include "Tissu.h"
#include "Masse.h"
using namespace std;

Contrainte::Contrainte(const Vecteur3D& position, double rayon)
    : position_(position), rayon_(rayon) {}

bool Contrainte::concerns(const Masse& masse) const {
    bool dans_sphere_action((position_ - masse.position()).norme() <= rayon_);
    return dans_sphere_action;
}

void Crochet::appliquer(Tissu& tissu, double t) const {
    tissu.applique_crochet(*this);
    //peut etre c'est plus simple une boucle sur Tissu.masses_concernés() qui fait la meme chose que applique_crochet()
    //ça serait une methode en moins
}

Impulsion::Impulsion(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, std::vector<Tissu*> cibles)
    : Contrainte(position, rayon), debut_(debut), fin_(fin), force_(force), tissus_cibles_(cibles) {
        vector<Masse*> masses_concernes_total;
        for (auto tissu : tissus_cibles_) {
            vector<Masse*> masses_concernes_tissu(tissu->masses_concernes(*this));
            for (auto masse : masses_concernes_tissu) {masses_concernes_total.push_back(masse);}
        }
        if(masses_concernes_total.empty()) cerr << "L'impulsion " << this << " ne concerne aucune masse" << endl;
        masses_cibles_ = masses_concernes_total;
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