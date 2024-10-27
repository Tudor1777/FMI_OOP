#ifndef DISCOUNT_H
#define DISCOUNT_H

#include "geaca.h"
#include "tricou.h"

template <typename t>
void aplica_discount(t* a, int procent = 0);

template <>
void aplica_discount<geaca>(geaca* g, int procent);

template <>
void aplica_discount<tricou>(tricou* tr, int procent);

extern template void aplica_discount<articol>(articol*, int);
extern template void aplica_discount<geaca>(geaca*, int);
extern template void aplica_discount<tricou>(tricou*, int);

#endif