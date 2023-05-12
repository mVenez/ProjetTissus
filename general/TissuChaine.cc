#include <vector>
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"
#include "SupportADessin.h"
#include "TissuChaine.h"
using namespace std;

//constructeurs
TissuChaine::TissuChaine(double masse_kg, double coef_frottement, double k, double l0, std::vector<Vecteur3D>& tableau_position, bool fixe) : Tissu() {
    /*bool fixe à false par défault permet de fixer la première masse du tissu*/

    //on cree les masses
    for (auto position : tableau_position) {
        Masse* masse = new Masse(masse_kg, coef_frottement, position);
        ajoute_masse(masse);
    }
    //on cree les ressorts
    for (int i(0); i < tableau_position.size() - 1; ++i) {
        connecte(*vector_masse_[i], *vector_masse_[i + 1], k, l0);
    }
    if (fixe) vector_masse_[0]->fixe();//fixe la première masse si le parametre fixe est à true
}

//destructeur
TissuChaine::~TissuChaine() {
    for (auto masse : vector_masse_) delete masse;
}