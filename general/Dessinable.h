#pragma once
class SupportADessin;

class Dessinable {  //classe mère de Masse, Tissu et Systeme
public:
    virtual void dessine_sur(SupportADessin&) = 0;
};
