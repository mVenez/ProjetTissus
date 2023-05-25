#pragma once
#include<vector>
#include <iostream>
#include "Dessinable.h"
#include "Vecteur3D.h"
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"
class Contrainte;
class Crochet;
class Impulsion;

class Tissu : public Dessinable {
public:
    //constructeurs, copie, destructeur
    Tissu(Masse& masse);    //constructeur pour initializer un tissu avec une seule masse puis en ajouter après
    Tissu(std::vector<Masse*> vector_masse = std::vector<Masse*>());    //constructeur auquel on passe un vecteur de masses directement, permet également d’initialiser un tissu "vide"
    Tissu(const Tissu&) = delete;   //on interdit la copie
    Tissu& operator=(const Tissu&) = delete;    //affectation aussi interdite car copie interdite
    ~Tissu();       //faut desallouer la memoire sinon segfault

    //methodes
    void ajoute_masse(Masse* );
    void connecte(Masse& masse1, Masse& masse2, double k, double l0);    //allocation dynamique d'un nouveau ressort qui lie les deux masses
    bool contient(Masse*) const;

    //simulation
    void mise_a_jour_forces() const ;    //met à jour toutes les masses
    void evolue(const Integrateur& integrateur) const ;  //intègre toutes les masses
    std::vector<Masse*> masses_concernes(const Contrainte&) const;  //renvoie une liste des masses concernées par uen contrainte
    void check() const ;    //check total du tissu
    
    virtual std::ostream& affiche(std::ostream& out) const ;   //affiche les masses et les ressorts du tissu
    std::ostream& affiche_positions(std::ostream& out) const;
    virtual void dessine_sur(SupportADessin& support) override;

protected:
    void give_gestion_ressort(); //methodes pour délégué la gestion des ressorts à une classe fille

    std::vector<Masse*> vector_masse_;
    std::vector<Ressort*> vector_ressort_;

    friend class TissuCompose; //Il est logique en terme de conception que la class TissuCompse puisse accéder au attributs de Tissu car TissuCompose est très proche de Tissu
};

//surcharge de l'operateur << pour afficher un tissu
std::ostream& operator<<(std::ostream& out, const Tissu& tissu);
