#pragma once
class Tissu;
class Systeme;
class Ressort;
class Masse;
class Objet;

class SupportADessin {
public:
    //constructeurs et destructeur
    SupportADessin() = default; 
    virtual ~SupportADessin() = default;
    SupportADessin(SupportADessin const&)            = delete; 
    SupportADessin& operator=(SupportADessin const&) = delete;
    SupportADessin(SupportADessin&&)            = default; 
    SupportADessin& operator=(SupportADessin&&) = default;

    //méthodes de dessin
    virtual void dessine(Tissu const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Masse const&) = 0;
    virtual void dessine(Ressort const&) = 0;
    virtual void dessine(Objet const&) = 0;

};
