#include <iostream>
#include "SupportADessin.h"

class TextViewer : public SupportADessin {
public:
    TextViewer(std::ostream& flot)
    : flot(flot) {}
    virtual ~TextViewer() = default;

    TextViewer(TextViewer const&)            = delete; 
    TextViewer& operator=(TextViewer const&) = delete;
    TextViewer(TextViewer&&)            = default; 
    TextViewer& operator=(TextViewer&&) = default;

    virtual void dessine(Tissu const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Masse const&) = 0;

private:
    std::ostream& flot;

};