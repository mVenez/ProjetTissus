#pragma once
#include<iostream>
#include<vector>
#include "Constantes.h"
#include "Vecteur3D.h"

class Ressort; // forward declare en place de #include, car on utilise seulement un pointeur. Il faut tester si une methode dans Masse.cc qui utilise ressort marche bien et peut acceder aux attributs et  methodes necessaires
class Masse{
public:
    // constructeur
    Masse(double masse, double coefficient_frottement = 0, Vecteur3D position = Vecteur3D(0,0,0), Vecteur3D vitesse = Vecteur3D(0,0,0), Vecteur3D acceleration=g, std::vector<Ressort*> liste_ressort = std::vector<Ressort*>());
    Masse(Masse const& masse) = delete; // copie interdite
    
    // getters
    double masse() const;
    double coefficient_frottement() const;
    Vecteur3D position() const;
    Vecteur3D vitesse() const;
    Vecteur3D force_subie() const;

    // setters
    void set_ressort(Ressort* ressort); // pour ajouter un ressort a la liste de ressorts
    void set_ressort(std::vector<Ressort*> liste_ressort); // pour définir une nouvelle liste de ressorts

    // méthodes
    void ajoute_force(Vecteur3D const& df);
    Vecteur3D acceleration() const;
    void mise_a_jour_forces();
   
private:
    double masse_;
    double coefficient_frottement_;
    Vecteur3D position_;
    Vecteur3D vitesse_;
    Vecteur3D force_subie_; // l’accelération multiplié par la masse
    std::vector<Ressort*> liste_ressort_;
};

std::ostream& operator<<(std::ostream& sortie, Masse const& masse);