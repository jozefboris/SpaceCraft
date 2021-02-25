#include "Zbran.h"

Zbran::Zbran(string nazov, int cena, int sila) {
	m_nazov = nazov;
	m_cena = cena;
	m_sila = sila;
}

int Zbran::getSila() {
	return m_sila;
}

int Zbran::getCena() {
    return m_cena;
}

string Zbran::getNazev() {
    return m_nazov;
}
