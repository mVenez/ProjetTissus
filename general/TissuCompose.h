#pragma once
#include <vector>
#include <iostream>
#include "Tissu.h"
#include "Vecteur3D.h"
#include "constantes.h"

class TissuCompose : public Tissu {
public:
    //constructeur, copie, destructeur
    TissuCompose(Tissu& tissu); // constructeur pour initializer un tissu avec un seul tissu
    TissuCompose(Tissu& tissu1, Tissu& tissu2, double k = k_ressort_de_couture, double delta = delta_tissu_recompose); //constructeur pour initializer un tissu avec deux tissus qui sont tout de suite cousu ensemble
    TissuCompose(std::vector<Tissu*> vector_tissu, double k = k_ressort_de_couture, double delta = delta_tissu_recompose); //constructeur pour initializer un tissu avec un vecteur de tissus qui sont tout de suite cousu ensemble

    TissuCompose(const Tissu&) = delete; //on interdit la copie
    TissuCompose& operator=(const Tissu&) = delete; //affectation aussi interdite car copie interdite

    //méthodes
    void ajoute_tissu(Tissu& tissu, double k = k_ressort_de_couture, double delta = delta_tissu_recompose); //permet de rajouter un tissu au tissu composé 

    //surcharge interne opérateur +=
    TissuCompose& operator+=(Tissu& tissu);
};