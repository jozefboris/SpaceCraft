#include "Mapa.h"

Mapa::Mapa() {
    m_suroviny.push_back(new Surovina("Uran"));
    m_suroviny.push_back(new Surovina("Zelezo"));
    m_suroviny.push_back(new Surovina("Zlato"));
    m_suroviny.push_back(new Surovina("Olovo"));
    m_suroviny.push_back(new Surovina("Adamantium"));

    m_planety.push_back(new Planeta("Mars", 300, 500, new Pirat(100, 50)));
    m_planety.at(m_planety.size()-1)->pridajSurovinu(m_suroviny.at(0));
    m_planety.at(m_planety.size()-1)->pridajSurovinu(m_suroviny.at(4));
    m_planety.push_back(new Planeta("Zem", 300, 500, new Pirat(200, 200)));
    m_planety.at(m_planety.size()-1)->pridajSurovinu(m_suroviny.at(1));
    m_planety.at(m_planety.size()-1)->pridajSurovinu(m_suroviny.at(2));
    m_planety.at(m_planety.size()-1)->pridajSurovinu(m_suroviny.at(3));
    m_planety.push_back(new Planeta("Jupiter", 300, 500, new Pirat(300, 70)));
    m_planety.at(m_planety.size()-1)->pridajSurovinu(m_suroviny.at(2));
    m_planety.at(m_planety.size()-1)->pridajSurovinu(m_suroviny.at(4));
    m_planety.push_back(new Planeta("Saturn", 300, 500, new Pirat(100, 100)));
    m_planety.at(m_planety.size()-1)->pridajSurovinu(m_suroviny.at(0));
    m_planety.at(m_planety.size()-1)->pridajSurovinu(m_suroviny.at(3));
    m_planety.at(m_planety.size()-1)->pridajSurovinu(m_suroviny.at(1));
}

Planeta* Mapa::getPlaneta(int ktora) {
	return m_planety.at(ktora);
}

Surovina* Mapa::getSurovina(int ktora) {
	return m_suroviny.at(ktora);
}

int Mapa::getPocetPlanet() {
	return m_planety.size();
}

int Mapa::getPocetSurovin() {
	return m_suroviny.size();
}

void Mapa::vypisPlanet() {
	if(this->getPocetPlanet() > 0){
        for(int i=0; i < this->getPocetPlanet(); i++) {
            cout << i << ") " << this->getPlaneta(i)->getNazov() << endl;
        }
	} else {
        cout << "Neexistuju ziadne planety" << endl;
	}
}

void Mapa::vypisSurovin() {
	if(this->getPocetSurovin() > 0) {
        for(int i=0; i < this->getPocetSurovin(); i++) {
            cout << i << ") " << this->getSurovina(i)->getNazov() << endl;
        }
	} else {
        cout << "Neexistuju ziadne suroviny." << endl;
	}
}

void Mapa::menu(VesmirnaLod* lod) {
    int vyber;
    do {
        this->vypisPlanet();
        cout << this->getPocetPlanet() << " Konec" << endl;
        cout << "Vyber si na ktoru planetu chces ist: ";
        cin >> vyber;

        if((vyber >= 0) && (vyber < this->getPocetPlanet())){
            this->getPlaneta(vyber)->menu(lod);
        }
    } while((vyber <= 0) || (vyber < this->getPocetPlanet()));
}

void Mapa::pridajPlanetu(Planeta* planeta){
    m_planety.push_back(planeta);
}

void Mapa::pridajSurovinu(Surovina* surovina){
    m_suroviny.push_back(surovina);
}
