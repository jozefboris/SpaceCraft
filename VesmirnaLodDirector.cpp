#include "VesmirnaLodDirector.h"

VesmirnaLodDirector::VesmirnaLodDirector(VesmirnaLodBuilder* builder)
{
    m_builder = builder;
}

VesmirnaLod* VesmirnaLodDirector::constructVesmirnaLod(string meno, string nazov, int cena, int sila) {
    m_builder->createVesmirnaLod(meno);
    m_builder->buildZbran(nazov, cena, sila);

    return m_builder->getLod();
}

