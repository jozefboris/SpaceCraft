#include "LaserovaLodBuilder.h"

void LaserovaLodBuilder::buildZbran(string nazov, int cena, int sila){
    this->getLod()->pridajZbran(new Laser(nazov, cena, sila, 5));
}
