#ifndef Pirat_h
#define Pirat_h

#include<iostream>

using namespace std;

class Pirat {

private:
	int m_zivot;
	int m_sila;

public:
	Pirat(int zivot, int sila);

	int getZivot();

	int getSila();

	void uberZivot(int okolko);

	void printInfo();
};
#endif // Pirat_h
