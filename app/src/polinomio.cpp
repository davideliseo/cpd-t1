#include <iostream>
#include <algorithm>
#include <vector>
#include "polinomio.hpp"

Polinomio::Polinomio(terminos_t terminos) : terminos(terminos)
{
}

Monomio::grado_t Polinomio::grado() const
{
    // Encuentra el monomio de grado mayor.
    auto mayor = std::max_element(this->terminos.begin(), this->terminos.end(),
                                  [](const Monomio &lhs, const Monomio &rhs)
                                  { return lhs < rhs; });
    return mayor->grado;
}

double Polinomio::resolver() const
{
    // @TODO Implementar método.
    return 0.0;
}

Polinomio Polinomio::derivado() const
{
    // @TODO Implementar método.
    return Polinomio({});
}
