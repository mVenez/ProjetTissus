#include "TextViewer.h"
#include "Masse.h"
#include "Ressort.h"
using namespace std;

TextViewer::TextViewer(ostream& flot)
    : flot_(flot) {}

void TextViewer::dessine(Masse const& masse){
    flot_ << masse;
}
void TextViewer::dessine(Ressort const& ressort){
    flot_ << ressort;
}

