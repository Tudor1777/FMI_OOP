#ifndef MAGAZIN_H
#define MAGAZIN_H
#include <iostream>
#include <vector>
#include <memory>
#include "articol.h"
#include "cos.h"
#include "client.h"
#include "tricou.h"
#include "hanorac.h"
#include "camasa.h"
#include "geaca.h"
#include "inventar.h"
using namespace std;

class magazin 
{
    private:
        inventar<articol> inv;
        int castig = 0;
        vector <unique_ptr<articol>> articole;
        static magazin* instance;
        magazin() : castig(0) {}
        magazin(const magazin&) = delete;
        magazin& operator=(const magazin&) = delete;

    public:
        ~magazin();
        static magazin* getInstance();
        void setCastig(int n);
        int getCastig() const;
        inventar<articol> getInventar();
        void setInventar(inventar<articol> i);
        //comanda
        void comanda(cos c, client user);
        //meniu
        void meniu();

        void meniu2();


        void adaugaArticol( tricou x );
        void adaugaArticol( hanorac x );
        void adaugaArticol( camasa x );
        void adaugaArticol( geaca x );
        void articolNou(articol* a);
        void veziArticole(string categorie, int discount) const;
        
};
#endif