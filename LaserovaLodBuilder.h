#ifndef LaserovaLodBuilder_H
#define LaserovaLodBuilder_H


#include <iostream>
#include "VesmirnaLodBuilder.h"
#include "Laser.h"

using namespace std;

class LaserovaLodBuilder : public VesmirnaLodBuilder {
    public:
        void buildZbran(string nazov, int cena, int sila);
};

#endif // LaserovaLodBuilder_H
