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

TissuDisque::TissuDisque(double masse_kg, Vecteur3D centre, Vecteur3D normal, double rayon, double pas_entre_deux_masse_sur_rayon, double coef_frottement, double k, double angle) : Tissu(){//"normal" est un vecteur normal au disque qui a pour norme le rayon du disque

    cout << "constructeur TissuDisque" << endl;
    //on vérifie que le vecteur normal est non nul
    if(normal.norme() == 0){
        throw invalid_argument("Le vecteur normal doit être non nul");
    }
    //on rend unitaire le vecteur normal
    normal = ~normal;

    //on trouve un vecteur sur le disque en faisant le produit vectoriel de "normal" avec un vecteur unitaire de la base canonique qui n'est pas colineaire avec "normal"
    Vecteur3D u; //vecteur unitaire sur le disque
    if (normal.x() != 0) u = ~(Vecteur3D(0, 1, 0) ^ normal);
    else u = ~(Vecteur3D(1, 0, 0) ^ normal);
    cout << "||u|| : " << u.norme() << endl;

    //on vérifie que les vecteur u et normal soit bien orthogonaux
    if(abs(u*normal) > epsilon){
        throw invalid_argument("Les vecteurs u et normal doivent être orthogonaux");
    }


    //on calcul le nombre de masse sur le rayon
    int nb_masse_rayon = rayon/pas_entre_deux_masse_sur_rayon;
    cout << "nb_mases_rayon : " << nb_masse_rayon << endl;
    //on calcul le nombre d’angle pour faire un tour complet
    int nb_angle_tour = 2*M_PI/angle;
    cout << "nb_angle_tour : " << nb_angle_tour << endl;
     
    //on crée les masses et les ressorts
    for(double n = 0; n < nb_angle_tour; ++n){
        cout << "n : " << n << endl;
        u = (cos(angle)*u + sin(angle)*(normal^u));//  + (1-cos(angle))*(u*normal)*normal
        cout << "u : " << u << endl;
        cout << "||u|| : " << u.norme() << endl;
        for(int m = 1; m <= nb_masse_rayon; ++m){
            cout << "m : " << m << endl;
            Masse* masse = new Masse(masse_kg, coef_frottement, centre + m*pas_entre_deux_masse_sur_rayon*~u);
            ajoute_masse(masse);
            if(m >= 2){
                connecte(*vector_masse_[vector_masse_.size() - 2], *vector_masse_.back(), k, pas_entre_deux_masse_sur_rayon);
            }
            if(n >= 1){
                connecte(*vector_masse_[vector_masse_.size() - nb_masse_rayon - 1], *vector_masse_.back(), k, 2*sin(angle/2)*pas_entre_deux_masse_sur_rayon*m);
            }
            if(n == nb_angle_tour - 1){//permet de connecter les deux "bout" du tissu disque quand on arrive à la dernière itération de la boucle
                cout << "lalaautenristaéoljiatuenrist auenristauneristanuresitanruesti" << endl;
                connecte(*vector_masse_[m-1], *vector_masse_.back(), k, 2*sin(angle/2)*pas_entre_deux_masse_sur_rayon*m);
            }
        }
    }
    //masse centrale
    Masse* masse = new Masse(masse_kg, coef_frottement, centre);
    ajoute_masse(masse);
    for(double n = 0; n < nb_angle_tour; ++n){
        cout << "n : " << n << endl;
        connecte(*vector_masse_[n], *vector_masse_.back(), k, pas_entre_deux_masse_sur_rayon);
    }
    cout << "masse centrale : " << *vector_masse_.back() << endl;

}

//destructeur
TissuDisque::~TissuDisque() {
    for (auto masse : vector_masse_) delete masse;
}