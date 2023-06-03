#pragma once
#include "Vecteur3D.h"

extern const Vecteur3D g; //constante gravitationelle
extern const double epsilon; //epsilon pour l’égalité des double
extern const double dt_const; //pas de temps dt des simulation de tissu
extern const double delta_tissu_recompose; //delta par défaut des tissu recomposé, c’est à dire l’écart en dessous duquel l’on connecte de masse avec un ressort lors de la composition de tissu
extern const double k_ressort_de_couture; //raideur des ressorts de "couture" c’est à dire la raideur des ressorts qui relient les deux tissus lors de la composition de tissu
extern const double taille_affichage_masse; //taille des masses lors de l’affichage
extern const double rouge, vert, bleu; //couleur de l’arrière plan lors de l’affichage