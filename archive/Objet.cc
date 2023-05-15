#include "Objet.h"
#include <vector>
#include <iostream>
using namespace std;

ostream& operator<<(std::ostream& sortie, Objet const& objet){
    objet.affiche(sortie);
    return sortie;
}
