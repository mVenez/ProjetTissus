#pragma once
#include "Tissu.h"
#include "Vecteur3D.h"
#include <vector>

class Contrainte {
public:
    //constructeurs
    Contrainte(const Vecteur3D& position, double rayon);
    Contrainte(const Contrainte&) = delete;
    Contrainte& operator=(const Contrainte&) = delete;

    //méthodes
    bool concerns(const Masse& masse)const;
    virtual void appliquer(Tissu& tissu, double t) const = 0;

private:
    Vecteur3D position_;
    double rayon_;
};


class Crochet : public Contrainte {
public:
    using Contrainte::Contrainte;

    virtual void appliquer(Tissu& tissu, double t) const override;
};


class Impulsion : public Contrainte {
public:
    //constructeurs
    Impulsion(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, std::vector<Tissu*> cibles);
    Impulsion(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, Tissu& cible);

    virtual void appliquer(Tissu& tissu, double t) const override;

protected:
    double debut_;
    double fin_;
    Vecteur3D force_;
    std::vector<Tissu*> tissus_cibles_;
    std::vector<Masse*> masses_cibles_;
};

class ImpulsionSin : public Impulsion {
public:
    //constructeurs
    ImpulsionSin(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, double frequence, std::vector<Tissu*> cibles);
    ImpulsionSin(const Vecteur3D& position, double rayon, double debut, double fin, Vecteur3D force, double frequence, Tissu& cible);

    virtual void appliquer(Tissu& tissu, double t) const override;

private:
    double f_;
};