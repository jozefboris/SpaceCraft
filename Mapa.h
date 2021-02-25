#ifndef Mapa_h
#define Mapa_h

#include<vector>
#include<iostream>

#include "Planeta.h"
#include "Surovina.h"
#include "VesmirnaLod.h"

class Mapa {

private:
	vector<Planeta*> m_planety;
	vector<Surovina*> m_suroviny;

public:
	Mapa();

	Planeta* getPlaneta(int ktora);

	Surovina* getSurovina(int ktora);

	int getPocetPlanet();

	int getPocetSurovin();

	void vypisPlanet();

	void vypisSurovin();

	void menu(VesmirnaLod* lod);

	void pridajPlanetu(Planeta* planeta);

	void pridajSurovinu(Surovina* surovina);
};
#endif // Mapa
