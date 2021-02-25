#include "Naklad.h"

Naklad::Naklad(int objem) {
	m_objem = objem;
}

int Naklad::getObjem() {
	return m_objem;
}

bool Naklad::getVolneMiestoVNaklade() {
    if(this->getPocetSurovin()+1 <= m_objem){
        return true;
    } else {
        return false;
    }
}

Surovina* Naklad::getSurovinu(int ktoru) {
	return m_surovina.at(ktoru);
}

int Naklad::getPocetSurovin() {
	return m_surovina.size();
}

void Naklad::pridajSurovinu(Surovina* surovina) {
	m_surovina.push_back(surovina);
}

void Naklad::odoberSurovinu(int ktoru) {
	m_surovina.erase(m_surovina.begin() + ktoru);
}

void Naklad::vypisSurovinyVNaklade() {
	int i;
	if(m_surovina.size() != 0){
        for(i=0;i<m_surovina.size();i++){
            cout << "[" << i << "] Surovina " << endl;
            cout << " --- " << m_surovina.at(i)->getNazov() << endl;
        }
	} else {
        cout << "Nie su dostupne ziadne suroviny" << endl;
	}
}

void Naklad::printInfo() {
    cout << "------------Naklad-----------" << endl;
    cout << " Objem: " << m_objem << endl;
    this->vypisSurovinyVNaklade();
}
