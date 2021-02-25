#ifndef Naklad_h
#define Naklad_H

#include<vector>
#include "Surovina.h"

class Naklad {

private:
	int m_objem;
	vector<Surovina*> m_surovina;

public:
	Naklad(int objem);

	int getObjem();

	bool getVolneMiestoVNaklade();

	Surovina* getSurovinu(int ktoru);

	int getPocetSurovin();

	void pridajSurovinu(Surovina* surovina);

	void odoberSurovinu(int ktoru);

	void vypisSurovinyVNaklade();

	void printInfo();
};
#endif // Naklad_h
