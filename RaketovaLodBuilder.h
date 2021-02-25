#ifndef RAKETOVALODBUILDER_H
#define RAKETOVALODBUILDER_H


#include <iostream>
#include "VesmirnaLodBuilder.h"
#include "Raketomet.h"

using namespace std;

class RaketovaLodBuilder : public VesmirnaLodBuilder {
    public:
        void buildZbran(string nazov, int cena, int sila);
};

#endif // RAKETOVALOD_H
