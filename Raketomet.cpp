#include "Raketomet.h"

Raketomet::Raketomet(string nazov, int cena, int sila, int bonusSily):Zbran(nazov, cena, sila) {
    m_nazov = nazov;
	m_sila = sila + bonusSily;
	m_cena = cena;
}



