#include <iostream>
#include <vector>
#include "polinomio.hpp"

Polinomio::Polinomio(terminos_t terminos) : terminos(terminos)
{
}

double Polinomio::raiz() const
{
    // @TODO Implementar método.
    return 0.0;
}

Polinomio Polinomio::derivado() const
{
    // @TODO Implementar método.
    return Polinomio({});
}
