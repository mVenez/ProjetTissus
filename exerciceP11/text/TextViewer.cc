#include "TextViewer.h"
#include "Tissu.h"
#include "Systeme.h"
#include "Masse.h"
#include "Ressort.h"
using namespace std;

TextViewer::TextViewer(ostream& flot)
    : flot_(flot) {}

void TextViewer::dessine(Tissu const& tissu){
    flot_ << tissu;
}
void TextViewer::dessine(Systeme const& systeme){
    flot_ << systeme;
}
void TextViewer::dessine(Masse const& masse){
    flot_ << masse;
}
void TextViewer::dessine(Ressort const& ressort){
    flot_ << ressort;
}
void TextViewer::dessine(Objet const& objet) {}
