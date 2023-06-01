#pragma once
#include<vector>
#include <iostream>
#include "Dessinable.h"
#include "constantes.h"
class Ressort;

class Masse : public Dessinable {
public:
    // constructeur
    Masse(double masse, double coefficient_frottement = 0, Vecteur3D position = Vecteur3D(0,0,0), Vecteur3D vitesse = Vecteur3D(0,0,0), Vecteur3D acceleration=g, std::vector<Ressort*> liste_ressort = std::vector<Ressort*>(), bool fixe = false, bool gravite = true);
    Masse(Masse const& masse) = delete; // copie interdite
    Masse& operator=(Masse const& masse) = delete; //on interdit l’affectation par copie car la copie est interdite
    
    // getters
    double masse() const;
    double coefficient_frottement() const;
    Vecteur3D position() const;
    Vecteur3D vitesse() const;
    Vecteur3D force_subie() const;
    Vecteur3D acceleration() const;

    // setters
    void fixe(bool fixe = true);
    void gravite(bool gravite = true);
    void set_ressort(Ressort* ressort); // pour ajouter un ressort a la liste de ressorts
    void unset_ressort(Ressort* ressort, bool gestion_suppresion_ressort = true); // pour supprimer un ressort de la liste de ressorts
    void set_position(const Vecteur3D& nouvelle_position);
    void set_vitesse(const Vecteur3D& nouvelle_vitesse);

    // méthodes
    void ajoute_force(Vecteur3D const& df);
    void mise_a_jour_forces();
    std::ostream& affiche(std::ostream&) const;
    virtual void dessine_sur(SupportADessin& support) override;

    //méthodes de check
    void check_attache() const; //check si la masse n'est connecté à aucun ressort et si elle figure dans tous les ressorts liés
    void check_ressort(const Ressort*) const; //check si un certain ressort est dans liste_ressorts_
   
private:
    double masse_;
    double coefficient_frottement_;
    Vecteur3D position_;
    Vecteur3D vitesse_;
    Vecteur3D force_subie_; // la somme des forces subies (F=ma)
    std::vector<Ressort*> liste_ressort_;
    bool fixe_; // si la masse est fixe ou non
    bool gravite_; //est-ce que la gravité affecte la masse?
};

//operateurs
std::ostream& operator<<(std::ostream& sortie, Masse const& masse);