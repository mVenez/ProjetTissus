#pragma once
#include "Dessinable.h"
#include "Objet.h"
#include <vector>
#include <iostream>

class Systeme : public Dessinable {
public:
    //constructeurs
    Systeme(std::vector<Objet*> vector_objet_);
    Systeme(Objet& objet);
    Systeme(const Systeme&) = delete; //on interdit la copie
    Systeme& operator=(const Systeme&) = delete; //affectation aussi int

    //méthodes
    virtual void dessine_sur(SupportADessin& support) override;
    std::ostream& affiche(std::ostream& out) const;

private:
    std::vector<Objet*> vector_objet_;
};

std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);

