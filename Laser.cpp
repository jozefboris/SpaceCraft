#include "Laser.h"

Laser::Laser(string nazov, int cena, int sila, int critical):Zbran(nazov, cena, sila) {
    m_nazov = nazov;
	m_sila = sila * critical;
	m_cena = cena;
}


