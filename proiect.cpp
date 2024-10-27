#include <iostream>
#include "articol.h"
#include "client.h"
#include "cos.h"
#include "magazin.h"
#include "inventar.h"
#include "discount.h"
using namespace std;


int articol :: nr_total = 0;
int main()
{
    magazin* m = magazin::getInstance();
    tricou* tricou1 = new tricou(100, "tricou 1", "alb", "bumbac", 200, 100, 300);
    tricou* tricou2 = new tricou(400, "tricou 2", "negru", "bumbac", 30, 10, 15);
    hanorac* hanorac1 = new hanorac(500, "hanorac 1", "alb", "bumbac", 100, 150, 100);
    hanorac* hanorac2 = new hanorac(650, "hanorac 2", "negru", "bumbac", 10, 15, 20);
    camasa* camasa1 = new camasa(400, "camasa 1", "alb", "in", 50, 50, 50);
    geaca* geaca1 = new geaca(1200, "geaca de piele", "negru", "piele naturala", 20, 30, 20, "da");
//    articol :: veziNrArticole();
    m->articolNou(tricou1);
    m->articolNou(tricou2);
    m->articolNou(hanorac1);
    m->articolNou(hanorac2);
    m->articolNou(camasa1);
    m->articolNou(geaca1);

    aplica_discount(tricou1);
    aplica_discount(tricou2);
    aplica_discount(geaca1);

    m->meniu2();
//
    return 0;
}