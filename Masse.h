#pragma once
#include<iostream>
#include<vector>
#include "Constantes.h"
#include "Vecteur3D.h"

class Ressort;
class Masse{
public:
    // constructeur
    Masse(double masse, double coefficient_frottement = 0, Vecteur3D position = Vecteur3D(0,0,0), Vecteur3D vitesse = Vecteur3D(0,0,0), Vecteur3D acceleration=g, std::vector<Ressort*> liste_ressort = std::vector<Ressort*>());
    Masse(Masse const& masse) = delete; // copie interdite
    Masse& operator=(Masse const& masse) = delete; //on interdit l’affectation par copie car la copie est interdite
    
    // getters
    double masse() const;
    double coefficient_frottement() const;
    Vecteur3D position() const;
    Vecteur3D vitesse() const;
    Vecteur3D force_subie() const;

    // setters
    void set_ressort(Ressort* ressort); // pour ajouter un ressort a la liste de ressorts
    void set_ressort(std::vector<Ressort*> liste_ressort); // pour définir une nouvelle liste de ressorts
    void unset_ressort(Ressort* ressort); // pour supprimer un ressort de la liste de ressorts
    void unset_ressort(std::vector<Ressort*> liste_ressort); // pour supprimer une liste de ressorts de la liste de ressorts
    void set_position(const Vecteur3D& nouvelle_position);
    void set_vitesse(const Vecteur3D& nouvelle_vitesse);

    // méthodes
    std::ostream& affiche(std::ostream&) const;
    void ajoute_force(Vecteur3D const& df);
    Vecteur3D acceleration() const;
    void mise_a_jour_forces();
    void check_attache() const; //check si la masse n'est connecté à aucun ressort et si elle figure dans tous les ressorts liés
    void check_ressort(const Ressort*) const; //check si un certain ressort est dans liste_ressorts_
   
private:
    double masse_;
    double coefficient_frottement_;
    Vecteur3D position_;
    Vecteur3D vitesse_;
    Vecteur3D force_subie_; // la somme des forces subies (F=ma)
    std::vector<Ressort*> liste_ressort_;
};

//operateurs
std::ostream& operator<<(std::ostream& sortie, Masse const& masse);