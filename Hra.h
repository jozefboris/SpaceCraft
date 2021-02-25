#ifndef Hra_h
#define Hra_h

#include<vector>
#include "VesmirnaLod.h"
#include "VesmirnaLodBuilder.h"
#include "VesmirnaLodDirector.h"
#include "RaketovaLodBuilder.h"
#include "LaserovaLodBuilder.h"
#include "Mapa.h"

class Hra {

private:
	vector<VesmirnaLod*> m_vesmirnaLod;
	Mapa* m_mapa;

public:
	Hra();

	void novaHra();

	void inicializaciaHry();

	void menu();

	void getScore();
};
#endif // Hra_H
