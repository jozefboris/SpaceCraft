#include "RaketovaLodBuilder.h"

void RaketovaLodBuilder::buildZbran(string nazov, int cena, int sila){
    this->getLod()->pridajZbran(new Raketomet(nazov, cena, sila, (cena - sila)));
}
