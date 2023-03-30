#pragma once
#include "Masse.h"

class Integrateur {
public:
    virtual void evolue (Masse& , double ) const;
};

class IntegrateurEulerCromer : public Integrateur {
public:
    virtual void evolue (Masse& , double ) const override;
};