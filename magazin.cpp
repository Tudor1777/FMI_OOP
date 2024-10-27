#include "magazin.h"
#include "articol.h"
#include "cos.h"
#include "client.h"
#include "discount.h"

magazin* magazin::instance = nullptr;

magazin* magazin::getInstance() 
{
    if (instance == nullptr) 
    {
        instance = new magazin();
    }
    return instance;
}

magazin :: ~magazin()
        {
            for (auto& art : articole) 
            {
                delete &art;
            }
        } 
void magazin :: setCastig(int n)
        {
            castig = n;
        }
int magazin :: getCastig() const
        {
            return castig;
        }
       

void magazin :: comanda(cos c, client user)
        {
            int i = 0;
            while ( c.getCumparaturi(i) != 0 && i < 99 )
            {
                articol a = *c.getCumparaturi(i);
                setCastig(a.getPret() * a.getnrCos() + getCastig());
                ++i;
            }
            string adresa, livrare;
            bool b;
            cout << "\nAdresa: ";
            cin.ignore();
            getline(cin, adresa);
            user.setAdresa(adresa);
            cout << "\nDoriti livrare rapida? (+50RON) ";
            getline(cin, livrare);
            if ( livrare == "da" )
            {
                user.setLivrare( 1 );
                setCastig( getCastig() + 50 );
            }
            else 
            {
                user.setLivrare( 0 );
            }
            cout << "\nPretul total al comenzii este: " << getCastig() << "\nComanda a fost plasata.";
            // c.golesteCosul();
        }
void magazin :: meniu2()
{
        int n, y, nr_bucati, nr_oferta;
        string s, raspuns;
        cos c;
        client client1;
        inventar<articol> inv2 = this->getInventar();
//        cout << "Introduceti tara de origine : ";
//        cin >> s;
//        client1.setTara(s);
        while ( true )
        {
        cout << "Alegeti categoria: \n 1.Tricouri \n 2.Hanorace \n 3.Camasi \n 4.Geci \n 5.Vezi cosul \n";
        cin >> n;
        if ( n == 1 )
        {
            int k = 0;
            inv2.afisareCategorie<tricou>();
            cout<< "Alegeti tricoul: ";
            cin >> y;
            cout << "Alegeti marimea: ";
            cin >> s;
            cout << "Alegeti cantitatea: ";
            cin >> nr_bucati;
            for (const auto& x : inv2.getArticole())
            {
                if (tricou *t = dynamic_cast<tricou*>(x))
                {
                    k++; 
                    if (k == y) 
                    { 
                        c.adauga_in_Cos(*t, nr_bucati, s);
                        break;
                    }
                }
            }
            if (k < y) {
                cout << "Nu exista acest tricou\n";
            }
        }
        if ( n == 2 )
        {
            int k = 0;
            inv2.afisareCategorie<hanorac>();
            cout<< "Alegeti hanoracul: ";
            cin >> y;
            cout << "Alegeti marimea: ";
            cin >> s;
            cout << "Alegeti cantitatea: ";
            cin >> nr_bucati;
            for (const auto& x : inv2.getArticole())
            {
                if (hanorac *h = dynamic_cast<hanorac*>(x))
                {
                    k++; 
                    if (k == y) 
                    { 
                        c.adauga_in_Cos(*h, nr_bucati, s);
                        break;
                    }
                }
            }
            if (k < y) {
                cout << "Nu exista acest hanorac\n";
            }
        }
        if ( n == 3 )
        {
            int k = 0;
            inv2.afisareCategorie<camasa>();
            cout<< "Alegeti camasa: ";
            cin >> y;
            cout << "Alegeti marimea: ";
            cin >> s;
            cout << "Alegeti cantitatea: ";
            cin >> nr_bucati;
            for (const auto& x : inv2.getArticole())
            {
                if (camasa *cm = dynamic_cast<camasa*>(x))
                {
                    k++; 
                    if (k == y) 
                    { 
                        c.adauga_in_Cos(*cm, nr_bucati, s);
                        break;
                    }
                }
            }
            if (k < y) {
                cout << "Nu exista aceasta camasa\n";
            }
        }
        if ( n == 4 )
        {
            int k = 0;
            inv2.afisareCategorie<geaca>();
            cout<< "Alegeti geaca: ";
            cin >> y;
            cout << "Alegeti marimea: ";
            cin >> s;
            cout << "Alegeti cantitatea: ";
            cin >> nr_bucati;
            for (const auto& x : inv2.getArticole())
            {
                if (geaca *h = dynamic_cast<geaca*>(x))
                {
                    k++; 
                    if (k == y) 
                    { 
                        c.adauga_in_Cos(*h, nr_bucati, s);
                        break;
                    }
                }
            }
            if (k < y) {
                cout << "Nu exista aceasta geaca\n";
            }

        }
        if ( n == 5 )
        {
            c.veziCosul();
            if ( c.getCumparaturi(0) == 0 )
            {
                cout << "\nCosul este gol!\n";
            }
            else
            {
                cout << "Comandati?\n";
                cin >> s;
                if ( s == "da" )
                    break;
            }
            
        }      
        
        }   
        comanda(c, client1);
}

inventar<articol> magazin ::getInventar()
{
    return inv;
}
void magazin :: setInventar(inventar<articol> i)
{
    inv = i;
}

void magazin :: adaugaArticol(tricou x)
{
    articole.push_back( make_unique<tricou>(move(x)));
}
void magazin :: adaugaArticol(hanorac x)
{
    articole.push_back( make_unique<hanorac>(move(x)));
}
void magazin :: adaugaArticol(camasa x)
{
    articole.push_back( make_unique<camasa>(move(x)));
}
void magazin :: adaugaArticol(geaca x)
{
    articole.push_back( make_unique<geaca>(move(x)));
}

void magazin ::articolNou(articol* a)
{
    inv.adaugaArticol(a);
}
void magazin :: veziArticole(string categorie, int discount) const
{
    if ( categorie == "tricouri" )
    {
        for( const auto& x : articole)
        {
            tricou* y = dynamic_cast<tricou*>(x.get());
            if ( y )
            {
                y->reducere(discount);
                y->afisareArticol();
            }
        }
    }
    if ( categorie == "hanorace" )
    {
        for( const auto& x : articole)
        {
            hanorac* y = dynamic_cast<hanorac*>(x.get());
            if ( y )
            {
                y->reducere(discount);
                y->afisareArticol();
            }
        }
    }
    if ( categorie == "camasi" )
    {
        for( const auto& x : articole)
        {
            camasa* y = dynamic_cast<camasa*>(x.get());
            if ( y )
            {
                y->reducere(discount);
                y->afisareArticol();
            }
        }
    }
    if ( categorie == "geci" )
    {
        for( const auto& x : articole)
        {
            geaca* y = dynamic_cast<geaca*>(x.get());
            if ( y )
            {
                y->reducere(discount);
                y->afisareArticol();
            }
        }
    }
    
}