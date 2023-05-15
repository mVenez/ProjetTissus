#pragma once
#include "Dessinable.h"
#include "Objet.h"
#include "Integrateur.h"
#include "Contrainte.h"
#include <vector>
#include <iostream>

class Systeme : public Dessinable {
public:
    //constructeurs
    Systeme(std::vector<Objet*> vector_objet, std::vector<Contrainte*> vector_contraintes = std::vector<Contrainte*>());
    Systeme(Objet& objet, Contrainte& contrainte);
    Systeme(const Systeme&) = delete; //on interdit la copie
    Systeme& operator=(const Systeme&) = delete; //affectation aussi interdite

    //méthodes
    virtual void dessine_sur(SupportADessin& support) override;
    std::ostream& affiche(std::ostream& out) const;

    virtual void evolue(const Integrateur& integrateur) const;
    virtual void check() const; //lance un check des tous les objets

private:
    std::vector<Objet*> vector_objet_;
    std::vector<Contrainte*> vector_contrainte_;
};

//operateurs
std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);

