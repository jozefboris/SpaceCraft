#ifndef Zbran_h
#define Zbran_h

#include<iostream>

using namespace std;

class Zbran {

protected:
	string m_nazov;
	int m_cena;
	int m_sila;

public:
	Zbran(string nazov, int cena, int sila);

	int getCena();

	string getNazev();

	int getSila();
};
#endif // Zbran_h
