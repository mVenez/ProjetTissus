#pragma once

class Dessinable {
    virtual void dessine_sur(SupportADessin&);
};

class SupportADessin {
public:
    virtual ~SupportADessin() = default;
    
    virtual void dessine(Tissu const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Masse const&) = 0;

};
