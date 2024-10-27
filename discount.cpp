#include "discount.h"

template <typename t>
void aplica_discount(t* a, int procent)
{
    a->reducere(procent);
}

template <>
void aplica_discount<geaca>(geaca* g, int procent)
{
    if (g->getImpermeabil() == "da")
    {
        g->reducere(50);
    }
    else
    {
        g->reducere(procent);
    }
}

template <>
void aplica_discount<tricou>(tricou* tr, int procent)
{
    if (tr->getCuloare() == "alb" && tr->getPret() < 150)
    {
        tr->reducere(20);
    }
    else
    {
        tr->reducere(procent);
    }
}
template void aplica_discount<articol>(articol*, int);
template void aplica_discount<geaca>(geaca*, int);
template void aplica_discount<tricou>(tricou*, int);