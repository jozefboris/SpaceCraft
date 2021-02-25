#include "VesmirnaLodBuilder.h"

VesmirnaLodBuilder::createVesmirnaLod(string meno)
{
    m_lod = new VesmirnaLod(meno);
}

VesmirnaLod* VesmirnaLodBuilder::getLod(){
    return m_lod;
}
