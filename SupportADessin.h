#pragma once
class Tissu;
class Systeme;
class Masse;


class SupportADessin {
public:
    virtual ~SupportADessin() = default;
    
    virtual void dessine(Tissu const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Masse const&) = 0;

};

class TextViewer {

};