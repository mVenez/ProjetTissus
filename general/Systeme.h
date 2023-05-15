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
    Systeme(std::vector<Tissu*> vector_tissus, std::vector<Contrainte*> vector_contraintes = std::vector<Contrainte*>());
    Systeme(Tissu& objet, Contrainte& contrainte);
    Systeme(Tissu& objet);
    Systeme(const Systeme&) = delete; //on interdit la copie
    Systeme& operator=(const Systeme&) = delete; //affectation aussi interdite

    //méthodes
    virtual void dessine_sur(SupportADessin& support) override;
    std::ostream& affiche(std::ostream& out) const;

    void evolue(const Integrateur& integrateur) const;
    void check() const; //lance un check des tous les objets

private:
    std::vector<Tissu*> vector_tissus_;
    std::vector<Contrainte*> vector_contraintes_;
};

//operateurs
std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);

