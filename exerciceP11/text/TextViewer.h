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
    TextViewer& operator=(TextViewer&&) = default;

    //méthodes de dessin
    virtual void dessine(Masse const& masse) override;
    virtual void dessine(Ressort const& masse) override;

private:
    std::ostream& flot_;
};
