#pragma once
class Masse;

class Integrateur {
public:
    //constructeur
    Integrateur(double dt = 0.01);

    //méthodes
    virtual void evolue (Masse& masse) const;
    
protected:
    double dt_;
};

class IntegrateurEulerCromer : public Integrateur {
public:
    //constructeur
    IntegrateurEulerCromer(double dt);

    //méthodes
    virtual void evolue (Masse& masse) const override;
};