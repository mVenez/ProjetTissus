#pragma once
class Ressort;
class Masse;

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
    virtual void dessine(Masse const&) = 0;
    virtual void dessine(Ressort const&) = 0;

};
