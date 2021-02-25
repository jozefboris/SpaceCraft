#ifndef Laser_h
#define Laser_h

#include<iostream>
#include "Zbran.h"

using namespace std;

class Laser : public Zbran {

private:
	int m_criticalBonus;

public:
	Laser(string nazov, int cena, int sila, int critical);

	int getCena();

	string getNazev();

	int getSila();
};
#endif
