#pragma once
#include <iostream>
#include "SupportADessin.h"

class TextViewer : public SupportADessin {
public:
    //constructeurs et destructeur
    TextViewer(std::ostream& flot);
    virtual ~TextViewer() = default;

    TextViewer(TextViewer const&)            = delete; 
    TextViewer& operator=(TextViewer const&) = delete;
    TextViewer(TextViewer&&)            = default; 
    //TextViewer& operator=(TextViewer&&) = default;

    //méthodes de dessin
    virtual void dessine(Tissu const& tissu) override;
    virtual void dessine(Systeme const& systeme) override;
    virtual void dessine(Masse const& masse) override;
    virtual void dessine(Contenu const& masse) override; //À ENLEVER

private:
    std::ostream& flot_;

};