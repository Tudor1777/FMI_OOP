#ifndef INVENTAR_H
#define INVENTAR_H


#include <iostream>
#include <vector>
#include <memory>
#include "articol.h"
#include "client.h"
#include "cos.h"
#include "magazin.h"
#include "discount.h"
using namespace std;

template <typename t>
class inventar
{
    private:
        vector <t*> articole;
    public:
        vector<t*> getArticole()
        {
            return articole;
        }
        void adaugaArticol(t* a)
        {
            articole.push_back(a);
        }
        void afisareArticole()const
        {
            for (const auto& a : articole)
            {
                a->afisareArticol();
            }
        }
        template<typename u>
        void afisareCategorie()const
        {
            for (const auto& a : articole)
            {
                if (dynamic_cast<u*>(a))
                {
                    aplica_discount(a);
                    a->afisareArticol();
                }
            }
        }

//        ~inventar()
//        {
//            for (auto& a : articole)
//            {
//                delete a;
//            }
//        }
};


#endif //OOP_INVENTAR_H
