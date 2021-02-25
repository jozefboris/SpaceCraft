#ifndef Raketomet_h
#define Raketomet_h

#include<iostream>
#include "Zbran.h"

using namespace std;

class Raketomet : public Zbran {

private:
	int m_bonusSily;

public:
	Raketomet(string nazov, int cena, int sila, int bonusSily);

	int getCena();

	string getNazev();

	int getSila();
};
#endif
