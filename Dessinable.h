#pragma once
class SupportADessin;

class Dessinable {  //classe mère de Masse, Tissu et Systeme
    virtual void dessine_sur(SupportADessin&) = 0;
};