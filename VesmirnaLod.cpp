#include "VesmirnaLod.h"

VesmirnaLod::VesmirnaLod(string meno) {
	m_meno = meno;
	m_naklad = new Naklad(10);
	m_peniaze = 1000;
    m_zivoty = 4000;
    m_points=0;
}

Naklad* VesmirnaLod::getNaklad() {
    return m_naklad;
}

string VesmirnaLod::getMeno() {
    return m_meno;
}

int VesmirnaLod::getPeniaze() {
    return m_peniaze;
}

int VesmirnaLod::getPocetZbrani(){
    return m_zbran.size();
}

int VesmirnaLod::getZivoty(){
    return m_zivoty;
}

int VesmirnaLod::getPoints(){
    return m_points;
}

Zbran* VesmirnaLod::getZbran(int ktoru) {
    return m_zbran.at(ktoru);
}

void VesmirnaLod::uberZivoty(int kolko) {
	m_zivoty -= kolko;
}

void VesmirnaLod::pridajZivoty(int kolko) {
	m_zivoty += kolko;
}

void VesmirnaLod::pridajPeniaze(int kolko) {
	m_peniaze += kolko;
}

void VesmirnaLod::pridajPoints(){
    m_points += 10;
}

void VesmirnaLod::uberPeniaze(int kolko) {
	m_peniaze -= kolko;
}

void VesmirnaLod::odstranZbran(int ktoru) {
	m_zbran.erase(m_zbran.begin() + ktoru);
}

void VesmirnaLod::pridajZbran(Zbran* zbran) {
	m_zbran.push_back(zbran);
}

void VesmirnaLod::vypisZbrani() {
    int i;
	cout << "-----------------------------------------" << endl;
	for(i=0;i<m_zbran.size();i++){
        cout << "---------[" << i << "] Zbran------------- " << endl;
        cout << "Nazov: " << m_zbran.at(i)->getNazev() << endl;
        cout << "Sila: " << m_zbran.at(i)->getSila() << endl;
        cout << "Cena: " << m_zbran.at(i)->getCena() << endl;
	}
	cout << "-----------------------------------------" << endl << endl;
}

void VesmirnaLod::printInfo() {
	cout << "------------- Vesmirna lod -------------" << endl;
	cout << " Meno: " << m_meno << endl;
	cout << " Peniaze: " << m_peniaze << endl;
	cout << " Zivoty: " << m_zivoty << endl;
	this->vypisZbrani();
	this->getNaklad()->printInfo();
	cout << "----------------------------------------" << endl;
}
