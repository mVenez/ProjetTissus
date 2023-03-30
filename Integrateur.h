#pragma once
#include "Masse.h"

class Integrateur {
public:
    //constructeur
    Integrateur(double dt = 0.01) : dt_(dt) {}

    //méthodes
    virtual void evolue (Masse& masse, double dt = dt_) const;
protected:
    double dt_;
};

class IntegrateurEulerCromer : public Integrateur {
public:
    //constructeur
    IntegrateurEulerCromer(double dt) : Integrateur(dt) {}

    virtual void evolue (Masse& masse, double dt = dt_) const override;
};