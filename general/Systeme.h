#pragma once
#include "Dessinable.h"
#include "Tissu.h"
#include "Integrateur.h"
#include "Contrainte.h"
#include <vector>
#include <iostream>

class Systeme : public Dessinable {
public:
    //constructeurs
    Systeme(Tissu& tissu, Contrainte& contrainte);
    Systeme(Tissu& tissu, std::vector<Contrainte*> vector_contraintes = std::vector<Contrainte*>());
    Systeme(std::vector<Tissu*> vector_tissus, Contrainte& contrainte);
    Systeme(std::vector<Tissu*> vector_tissus, std::vector<Contrainte*> vector_contraintes = std::vector<Contrainte*>());

    Systeme(const Systeme&) = delete;
    Systeme& operator=(const Systeme&) = delete;

    //méthodes
    virtual void dessine_sur(SupportADessin& support) override;
    std::ostream& affiche(std::ostream& out) const;
    std::ostream& affiche_positions(std::ostream& out) const;

    void evolue(const Integrateur& integrateur);
    void check() const; //lance un check des tous les objets

private:
    std::vector<Tissu*> vector_tissus_;
    std::vector<Contrainte*> vector_contraintes_;
    double t_;   //temps passé du debut de la simulation
};

//operateurs
std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);

