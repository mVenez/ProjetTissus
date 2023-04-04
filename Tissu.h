#pragma once
#include<vector>
#include "Masse.h"
#include "Ressort.h"


class Tissu {
public:
    Tissu(std::vector<Masse*> m);    //bool manuel ou non?
    Tissu(const Tissu&); //copie
    ~Tissu();   //faut desallouer la memoire sinon segfault

    void connecte(Masse& masse1, Masse& masse2, double k, double l0) const ;

private:
    std::vector<Masse*> masses;
};