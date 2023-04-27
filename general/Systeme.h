#pragma once
#include "Dessinable.h"
#include "Objet.h"
#include "Integrateur.h"
#include <vector>
#include <iostream>

class Systeme : public Dessinable {
public:
    //constructeurs
    Systeme(std::vector<Objet*> vector_objet_);
    Systeme(Objet& objet);
    Systeme(const Systeme&) = delete; //on interdit la copie
    Systeme& operator=(const Systeme&) = delete; //affectation aussi interdite

    //méthodes
    virtual void dessine_sur(SupportADessin& support) override;
    std::ostream& affiche(std::ostream& out) const;
    virtual void evolue(const Integrateur& integrateur) const;

private:
    std::vector<Objet*> vector_objet_;
};

//operateurs
std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);

