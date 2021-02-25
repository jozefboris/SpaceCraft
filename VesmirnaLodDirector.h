#ifndef VESMIRNALODDIRECTOR_H
#define VESMIRNALODDIRECTOR_H

#include <iostream>
#include "VesmirnaLodBuilder.h"

class VesmirnaLodDirector
{
    public:
        VesmirnaLodDirector(VesmirnaLodBuilder* builder);
        VesmirnaLod* constructVesmirnaLod(string meno, string nazov, int cena, int sila);

    private:
        VesmirnaLodBuilder* m_builder;
};

#endif // VESMIRNALODDIRECTOR_H
