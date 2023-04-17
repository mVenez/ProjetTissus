#pragma once
#include <vector>
#include <iostream>
#include "SupportADessin.h"
#include "Integrateur.h"
class Tissu;

// la class objet est une class virtuelle pure qui permet à la class système de contenir des objets de type tissu ou de type contrainte (à venir) via le polymorphisme
class Objet{
    public:
        virtual void dessine_sur(SupportADessin& support) = 0;
        virtual std::ostream& affiche(std::ostream& out) const = 0;

        //est-ce que ces trois methodes en bas ont un sense pour une contrainte?
        virtual void mise_a_jour_forces() const = 0;
        virtual void evolue(const Integrateur& integrateur) const = 0;
        virtual void check() const = 0; //celle ci est probablement pas necessaire
};

std::ostream& operator<<(std::ostream& sortie, Objet const& objet);
