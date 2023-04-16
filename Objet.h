#pragma once
#include <vector>
#include <iostream>
#include "SupportADessin.h"
class Tissu;

// la class objet est une class virtuelle pure qui permet à la class système de contenir des objets de type tissu ou de type contrainte (à venir) via le polymorphisme
class Objet{
    public:
        virtual void dessine_sur(SupportADessin& support) = 0;
        virtual std::ostream& affiche(std::ostream& out) const = 0;
        virtual std::vector<Tissu*> getTissus() const = 0;
        virtual std::vector<Objet*> getObjets() const = 0;
};

std::ostream& operator<<(std::ostream& sortie, Objet const& objet);
