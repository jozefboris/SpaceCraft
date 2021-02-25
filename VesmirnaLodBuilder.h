#ifndef VESMIRNALODBUILDER_H
#define VESMIRNALODBUILDER_H

#include<iostream>
#include "VesmirnaLod.h"
using namespace std;

class VesmirnaLodBuilder
{
    public:
        createVesmirnaLod(string meno);
        virtual void buildZbran(string nazov, int cena, int sila) = 0;
        VesmirnaLod* getLod();

    protected:
        VesmirnaLod* m_lod;
};

#endif // VESMIRNALODBUILDER_H
