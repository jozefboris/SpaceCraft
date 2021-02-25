#include "Planeta.h"

Planeta::Planeta(string nazov, int cena, int cena2, Pirat* pirat) {
    m_nazov = nazov;
	m_cenaZaNakupSuroviny = cena;
	m_cenaZaPredajSuroviny = cena2;
	m_pirat = pirat;
	m_vesmirnaLod = nullptr;
}

string Planeta::getNazov() {
    return m_nazov;
}

VesmirnaLod* Planeta::getVesmirnaLod() {
	return m_vesmirnaLod;
}

Surovina* Planeta::getSurovina(int ktora) {
	return m_surovina.at(ktora);
}

int Planeta::getCenaZaPredajSuroviny() {
	return m_cenaZaPredajSuroviny;
}

int Planeta::getCenaZaNakupSuroviny() {
	return m_cenaZaNakupSuroviny;
}

int Planeta::getPocetSurovin(){
    return m_surovina.size();
}

Pirat* Planeta::getPirat() {
	return m_pirat;
}

void Planeta::setVesmirnaLod(VesmirnaLod* lod) {
	m_vesmirnaLod = lod;
	if(m_vesmirnaLod != nullptr){
        cout << "Uspesne si pristal" << endl << endl;
	} else {
        cout << "Uspesne si odletel z planety. " << endl << endl;
	}
}

void Planeta::vypisSurovin() {
	int i;
	if(m_surovina.size() != 0){
        for(i=0;i<m_surovina.size();i++){
            cout << "[" << i << "] Surovina" << endl;
            cout << " --- " << m_surovina.at(i)->getNazov() << endl;
        }
	} else {
        cout << "Nie su dostupne ziadne suroviny na tejto planete" << endl;
	}
}

void Planeta::boj() {
	int myDmg = 0;
	for(int i=0; i < this->getVesmirnaLod()->getPocetZbrani(); i++){
        myDmg += this->getVesmirnaLod()->getZbran(i)->getSila();
	}

	while(this->getPirat()->getZivot() > 0 && this->getVesmirnaLod()->getZivoty() > 0){
        this->getPirat()->uberZivot(myDmg);
        this->getVesmirnaLod()->uberZivoty(this->getPirat()->getSila());
	}

	if(this->getVesmirnaLod()->getZivoty() > 0){
        this->getVesmirnaLod()->pridajPeniaze(this->getPirat()->getSila() * 10);
        cout << " Boj s piratom si vyhral" << endl;
	} else {
        cout << " Boj s piratom si prehral " << endl;
	}
}

void Planeta::pridajSurovinu(Surovina* surovina) {
    m_surovina.push_back(surovina);
}

void Planeta::predajSurovinu() {
    if(m_vesmirnaLod != nullptr){
        if(m_vesmirnaLod->getNaklad()->getPocetSurovin() != 0){
            int volba;
            cout << " Ktoru surovinu chces predat? Ak si sa rozhodol, ze ziadnu, zadaj 999. " << endl;
            m_vesmirnaLod->getNaklad()->vypisSurovinyVNaklade();
            cout << " Tvoja volba: ";
            cin >> volba;
            if((volba != 999) || (volba < (m_vesmirnaLod->getNaklad()->getPocetSurovin()))){
                m_vesmirnaLod->getNaklad()->odoberSurovinu(volba);
                m_vesmirnaLod->pridajPeniaze(m_cenaZaPredajSuroviny);
                m_vesmirnaLod->pridajPoints();
                cout << " Surovina bola uspesne predana " << endl;
            } else {
                cout << " Zadal si zlu hodnotu " << endl;
            }
        } else {
            cout << "V inventari nemas ziadne suroviny, nemas co predavat" << endl;
        }
    } else {
        cout << "Nie si na planete, tuto akciu nemozno vykonat" << endl << endl;
    }
}

void Planeta::kupSurovinu() {
    int volba;
	if(m_vesmirnaLod != nullptr){
        if(m_vesmirnaLod->getNaklad()->getVolneMiestoVNaklade() == true){
            if(this->getPocetSurovin() != 0){
                this->vypisSurovin();
                cout << "Ktoru chces kupit?";
                cin >> volba;
                if(volba < this->getPocetSurovin()) {
                    if(m_vesmirnaLod->getPeniaze() >= (m_cenaZaNakupSuroviny)){
                        m_vesmirnaLod->getNaklad()->pridajSurovinu(m_surovina.at(volba));
                        m_vesmirnaLod->uberPeniaze(m_cenaZaNakupSuroviny);
                        m_vesmirnaLod->pridajPoints();
                        cout << " Uspesne si nakupil " << endl;
                    } else {
                        cout << "Nemas dostatok penazi na to, aby si kupil tuto surovinu" << endl;
                    }
                } else {
                    cout << " Zla volba " << endl;
                }
            } else {
                cout << "Na planete nie su ziadne suroviny " << endl;
            }
        } else {
            cout << "V inventari uz nie je volne miesto" << endl;
        }
    } else {
        cout << "Nie si na planete, tuto akciu nemozno vykonat" << endl << endl;
    }
}

void Planeta::menu(VesmirnaLod* lod){
    int volba;
    do {
        cout << "---- " << this->getNazov() << " ----" << endl;
        cout << "1) Info o planete" << endl;
        cout << "2) Info o sebe" << endl;
        cout << "3) Nakup suroviny" << endl;
        cout << "4) Predaj suroviny" << endl;
        cout << "5) Pristat na planete" << endl;
        cout << "6) Opustit planetu" << endl;
        cout << "--------------------" << endl;

        cout << " Tvoja moznost";
        cin >> volba;
        if(volba > 0 && volba < 7){
            switch(volba) {
                case 1:
                    this->printInfo();
                    break;
                case 2:
                    lod->printInfo();
                    break;
                case 3:
                    this->kupSurovinu();
                    break;
                case 4:
                    this->predajSurovinu();
                    break;
                case 5:
                    this->setVesmirnaLod(lod);
                    break;
                case 6:
                    this->boj();
                    m_vesmirnaLod->pridajPoints();
                    this->setVesmirnaLod(nullptr);
                    break;
            }
        }
    } while((volba < 6) || (volba < 0));
}

void Planeta::printInfo() {
    cout << "----------------Planeta info----------------" << endl;
	cout << " Nazov: " << m_nazov << endl;
	cout << " Cena za nakup suroviny: " << m_cenaZaNakupSuroviny << endl;
	cout << " Cena za predaj suroviny: " << m_cenaZaPredajSuroviny << endl;
	this->vypisSurovin();
	cout << "-----------------------------------------" << endl << endl;
}
