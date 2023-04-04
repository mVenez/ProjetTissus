#include <iostream>
#include "Tissu.h"
#include "Masse.h"
#include "Ressort.h"

Tissu::Tissu(std::vector<Masse*> m) : masses(m) {}     //bool manuel ou non?


void Tissu::connecte(Masse& masse1, Masse& masse2, double k, double l0) const {
    Ressort* ressort = new Ressort(masse1, masse2, k, l0);
}