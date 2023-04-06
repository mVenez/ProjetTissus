#include <iostream>
#include "Tissu.h"
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"

//constructeurs et destructeur
Tissu::Tissu(Masse& masse) : vector_masse_({&masse}) {}
Tissu::Tissu(std::vector<Masse*> vector_masse) : vector_masse_(vector_masse) {}

//methodes
void Tissu::connecte(Masse& masse1, Masse& masse2, double k, double l0) const {
    Ressort* ressort = new Ressort(masse1, masse2, k, l0);
    vector_ressort_.push_back(ressort);
}

void Tissu::mise_a_jour_forces() const {
    for (auto masse : vector_masse_) masse->mise_a_jour_forces();
}

void Tissu::evolue(const Integrateur& integrateur) const {
    for(auto masse : vector_masse_) integrateur.evolue(*masse);
}