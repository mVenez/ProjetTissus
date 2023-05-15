#pragma once
#include <vector>
#include <iostream>
#include "SupportADessin.h"
#include "Integrateur.h"
class Tissu;

// la class objet est une class virtuelle pure qui permet à la class système de contenir des objets de type tissu
class Objet{
    public:
        virtual void dessine_sur(SupportADessin& support) = 0;
        virtual std::ostream& affiche(std::ostream& out) const = 0;

        virtual void mise_a_jour_forces() const = 0;
        virtual void evolue(const Integrateur& integrateur) const = 0;
        virtual void check() const = 0;
};

std::ostream& operator<<(std::ostream& sortie, Objet const& objet);
