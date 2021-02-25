#include "Hra.h"

Hra::Hra() {
    m_mapa = nullptr;
}

void Hra::novaHra() {
    int volba = 0;

    do {
        cout << "-*-*-*-*-* Menu *-*-*-*-*-*-" << endl;
        cout << " 1. Nova hra " << endl;
        cout << " 2. Score " << endl;
        cout << " 3. Konec hry " << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << " Tvoja volba " << endl;
        cin >> volba;
        if(volba > 0 || volba < 3){
            switch(volba){
                case 1:
                    this->inicializaciaHry();
                    break;
                case 2:
                    this->getScore();
                    break;
            }
        }
    } while(volba != 3);
}

void Hra::inicializaciaHry() {
    string meno,zbran;
    int volba = 0;
    int vyber = 0;
    cout << "****** Prolog *******" << endl;
    cout << " Zvolsi svoje meno ";
    cin >> meno;
    cout << "*********************" << endl;

    while(volba != 1 && volba != 2){
        cout << "------- Vyber si aky typ lode chces byt -------" << endl;
        cout << "  1. Raketova lod " << endl;
        cout << "  2. Laserova lod " << endl;
        cout << "----------------------------------------------" << endl;

        cin >> volba;
        if(volba == 1){
                VesmirnaLodDirector* dir = new VesmirnaLodDirector( new RaketovaLodBuilder() );
                cout << "   Zvol nazov zbrane " << endl;
                cin >> zbran;
                m_vesmirnaLod.push_back(dir->constructVesmirnaLod(meno, zbran, 100, 220));
                break;
        } else if(volba == 2) {
                VesmirnaLodDirector* dir = new VesmirnaLodDirector( new LaserovaLodBuilder() );
                cout << "   Zvol nazov zbrane " << endl;
                cin >> zbran;
                m_vesmirnaLod.push_back(dir->constructVesmirnaLod(meno, zbran, 100, 150));
        }
    }

    m_mapa = new Mapa();

    m_mapa->menu(m_vesmirnaLod.at(m_vesmirnaLod.size()-1));
}

void Hra::getScore(){
    cout << endl << "======= SCORE ======" << endl;
    for(int i=0; i < m_vesmirnaLod.size(); i++){
        cout << i+1 << "| " << m_vesmirnaLod.at(i)->getMeno() << " -- " << m_vesmirnaLod.at(i)->getPoints() << " bodov. " << endl;
    }
    cout << "=======================" << endl << endl;
}

