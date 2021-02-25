#ifndef VesmirnaLod_h
#define VesmirnaLod_h

#include<iostream>
#include "Laser.h"
#include "Raketomet.h"
#include "Naklad.h"

using namespace std;

class VesmirnaLod {

private:
	string m_meno;
	int m_peniaze;
	vector<Zbran*> m_zbran;
	Naklad* m_naklad;
	int m_zivoty;
	int m_points;

public:
	VesmirnaLod(string meno);

	Naklad* getNaklad();

	int getPeniaze();

    Zbran* getZbran(int ktoru);

    int getZivoty();

    int getPocetZbrani();

    int getPoints();

    string getMeno();

    void pridajPoints();

	void uberZivoty(int kolko);

	void pridajZivoty(int kolko);

	void pridajPeniaze(int kolko);

	void uberPeniaze(int kolko);

	void odstranZbran(int ktoru);

	void pridajZbran(Zbran* zbran);

	void vypisZbrani();

	void printInfo();
};
#endif // VesmirnaLod_h
