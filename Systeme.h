#pragma once
#include "Dessinable.h"
#include <vector>
class Tissu;

class Systeme : public Dessinable {
public:
    //constructeurs
    Systeme(std::vector<Tissu*> liste_tissus);
    Systeme(Tissu& tissu);
    Systeme(const Systeme&) = delete; //on interdit la copie
    Systeme& operator=(const Systeme&) = delete; //affectation aussi int

    //méthodes
    virtual void dessine_sur(SupportADessin& support) override;
    void affiche(std::ostream& out) const;

private:
    std::vector<Tissu*> liste_tissus_;
};
/*private:
    std::vector<Objet*> vector_objet_;
};*/

std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);

class Objet{};
