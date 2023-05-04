#define _USE_MATH_DEFINES //pour avoir pi
#include <vector>
#include <cmath>
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"
#include "SupportADessin.h"
#include "TissuDisque.h"
#include "constantes.h"
using namespace std;

TissuDisque::TissuDisque(double masse_kg, Vecteur3D centre, Vecteur3D normale_rayon, double pas_radial, double coef_frottement, double k, double angle) : Tissu(){

    cout << "constructeur TissuDisque" << endl;
    //on trouve un vecteur sur le disque en faisant le produit vectoriel de "normale_rayon" avec un vecteur unitaire de la base canonique qui n'est pas colineaire avec "normale_rayon"
    Vecteur3D vecteur_sur_disque_unitaire;
    if (normale_rayon.x() != 0) vecteur_sur_disque_unitaire = ~(Vecteur3D(0, 1, 0) ^ normale_rayon);
    else vecteur_sur_disque_unitaire = ~(Vecteur3D(1, 0, 0) ^ normale_rayon);

    //on calcul le nombre de masse sur le rayon
    int nb_masse_rayon = normale_rayon.norme()/pas_radial;
    cout << "nb_mases_rayon : " << nb_masse_rayon << endl;
    //on calcul le nombre d’angle pour faire un tour complet
    int nb_angle_tour = 2*M_PI/angle;
    cout << "nb_angle_tour : " << nb_angle_tour << endl;
     
    //on crée les masses et les ressorts
    for(double n = 0; n < nb_angle_tour; ++n){
        cout << "n : " << n << endl;
        vecteur_sur_disque_unitaire = ~(cos(angle)*vecteur_sur_disque_unitaire + (1-cos(angle))*(vecteur_sur_disque_unitaire*normale_rayon)*normale_rayon + sin(angle)*(normale_rayon^vecteur_sur_disque_unitaire));
        cout << "vecteur_sur_disque_unitaire : " << vecteur_sur_disque_unitaire << endl;
        for(int m = 1; m <= nb_masse_rayon; ++m){
            cout << "m : " << m << endl;
            Masse* masse = new Masse(masse_kg, coef_frottement, centre + m*pas_radial*~vecteur_sur_disque_unitaire);
            ajoute_masse(masse);
            if(m >= 2){
                connecte(*vector_masse_[vector_masse_.size() - 2], *vector_masse_.back(), k, pas_radial);
            }
            if(n >= 2){
                connecte(*vector_masse_[vector_masse_.size() - nb_masse_rayon - 2], *vector_masse_.back(), k, 2*sin(angle/2)*pas_radial*m);
            }
        }
    }
    //masse centrale
    /*Masse* masse = new Masse(masse_kg, coef_frottement, centre);
    ajoute_masse(masse);
    for(int n = 0; n < 2*M_PI/angle-epsilon; ++n){
        connecte(*vector_masse_[n], *vector_masse_.back(), k, pas_radial);
    }*/

}

//destructeur
TissuDisque::~TissuDisque() {
    for (auto masse : vector_masse_) delete masse;
}