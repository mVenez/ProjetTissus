#pragma once
#include<vector>
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"


class Tissu {
public:
    //constructeurs et destructeur
    Tissu(std::vector<Masse*> m);
    Tissu(const Tissu&); //copie
    ~Tissu();   //faut desallouer la memoire sinon segfault

    //methodes
    void connecte(Masse& masse1, Masse& masse2, double k, double l0) const ;    //allocation dynamique d'un nouveau ressort qui lie les deux masses
    void mise_a_jour_forces() const;    //met à jour toutes les masses
    void evolue(const Integrateur& integrateur) const;  //intègre toutes les masses
    void check() const;
private:
    std::vector<Masse*> vector_masse_;
    std::vector<Ressort*> vector_ressort_;
};