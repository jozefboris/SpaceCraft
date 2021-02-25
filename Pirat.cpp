#include "Pirat.h"

Pirat::Pirat(int zivot, int sila) {
	m_zivot = zivot;
	m_sila = sila;
}

int Pirat::getZivot() {
	return m_zivot;
}

int Pirat::getSila() {
	return m_sila;
}

void Pirat::uberZivot(int okolko) {
	m_zivot -= okolko;
}

void Pirat::printInfo() {
	cout << "----------------Pirat info----------------" << endl;
	cout << "Zivot: " << this->getZivot() << endl;
	cout << "Sila: " << this->getSila() << endl;
	cout << "-----------------------------------------" << endl << endl;
}
