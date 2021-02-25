#ifndef Planeta_h
#define Planeta_h

#include<vector>
#include "Surovina.h"
#include "Pirat.h"
#include "VesmirnaLod.h"

class Planeta {

private:
    string m_nazov;
	VesmirnaLod* m_vesmirnaLod;
	vector<Surovina*> m_surovina;
	int m_cenaZaPredajSuroviny;
	int m_cenaZaNakupSuroviny;
	Pirat* m_pirat;

public:
	Planeta(string nazov, int cena, int cena2, Pirat* pirat);

	string getNazov();

	VesmirnaLod* getVesmirnaLod();

	Surovina* getSurovina(int ktora);

	int getCenaZaPredajSuroviny();

	int getCenaZaNakupSuroviny();

	int getPocetSurovin();

	Pirat* getPirat();

	void setVesmirnaLod(VesmirnaLod* lod);

	void vypisSurovin();

	void boj();

	void pridajSurovinu(Surovina* surovina);

	void predajSurovinu();

	void kupSurovinu();

	void menu(VesmirnaLod* lod);

	void printInfo();
};
#endif // Planeta_h
