#pragma once
#include<vector>
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"


class Tissu {
public:
    //constructeurs, copie, destructeur
    Tissu(Masse& masse);//constructeur pour initializer un tissu avec une seule masse puis en ajouter après
    Tissu(std::vector<Masse*> vector_masse);//constructeur auquel on passe un vecteur de masses directement
    Tissu(const Tissu&) = delete; //on interdit la copie
    Tissu& operator=(const Tissu&) = delete; //affectation aussi interdite car copie interdite
    ~Tissu();   //faut desallouer la memoire sinon segfault

    //methodes
    void ajoute_masse(Masse* m);    //ajoute une masse au tissu
    void connecte(Masse& masse1, Masse& masse2, double k, double l0);    //allocation dynamique d'un nouveau ressort qui lie les deux masses
    void mise_a_jour_forces() const;    //met à jour toutes les masses
    void evolue(const Integrateur& integrateur) const;  //intègre toutes les masses
    void check() const; //check total du tissu
private:
    std::vector<Masse*> vector_masse_;
    std::vector<Ressort*> vector_ressort_;
};