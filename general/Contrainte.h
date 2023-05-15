#pragma once
#include "Tissu.h"
#include "Vecteur3D.h"

class Contrainte {
public:
    //constructeurs
    Contrainte(const Vecteur3D& position, double rayon);
    Contrainte(const Contrainte&) = delete;
    Contrainte& operator=(const Contrainte&) = delete;

    //méthodes
    virtual void appliquer(Tissu& tissu, double dt) const = 0;

    bool concerns(const Masse& masse)const ;

private:
    Vecteur3D position_;
    double rayon_;
};

class Crochet : public Contrainte {
public:
    using Contrainte::Contrainte;
    virtual void appliquer(Tissu& tissu, double dt) const;

};
