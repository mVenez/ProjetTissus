#include <iostream>
#include "Tissu.h"
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"

//constructeurs et destructeur
Tissu::Tissu(std::vector<Masse*> m) : masses(m) {}

//methodes
void Tissu::connecte(Masse& masse1, Masse& masse2, double k, double l0) const {
    Ressort* ressort = new Ressort(masse1, masse2, k, l0);
}

void Tissu::mise_a_jour_forces() const {
    for (auto masse : masses) masse->mise_a_jour_forces();
}

void Tissu::evolue(const Integrateur& integrateur) const {
    for(auto masse : masses) integrateur.evolue(*masse);
}