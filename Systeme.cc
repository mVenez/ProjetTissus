#include "Systeme.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Tissu.h"
#include <vector>
#include <iostream>
using namespace std;

//constructeurs
Systeme::Systeme(vector<Tissu*> liste_tissus) 
    : Dessinable(), liste_tissus_(liste_tissus) {}

Systeme::Systeme(Tissu& tissu) 
    : Dessinable(), liste_tissus_({&tissu}) {}

//methodes
void Systeme::dessine_sur(SupportADessin& support) {
    support.dessine(*this); 
}

void Systeme::affiche(ostream& out) const {
    vector<Masse*> liste_masses_total;
    vector<Ressort*> liste_ressorts_total;
    //ICI IL FAUT AJOUTER TOUTES LES MASSES ET LES RESSORTS AUX DEUX VECTORS
    cout << "Le système est constitué de " << liste_masses_total.size() << "masses et de " << liste_ressorts_total.size() << "ressorts : " << endl;
    for (auto masse: liste_masses_total) {cout << masse;}
    for (auto ressort: liste_ressorts_total) {cout << ressort;}
}

ostream& operator<<(ostream& out, Systeme const& systeme) {
    systeme.affiche(out);
    return out;
}