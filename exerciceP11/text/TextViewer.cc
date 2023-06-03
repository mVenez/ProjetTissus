#include "TextViewer.h"
#include "Masse.h"
#include "Ressort.h"
using namespace std;

//constructeur
TextViewer::TextViewer(ostream& flot)
    : flot_(flot) {}

//SupportADessin::dessine()
void TextViewer::dessine(Masse const& masse){
    flot_ << masse;
}
void TextViewer::dessine(Ressort const& ressort){
    flot_ << ressort;
}

