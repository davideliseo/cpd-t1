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

double Polinomio::evaluar(double x) const
{
    auto resultado = 0.0;

    for (const auto &monomio : this->terminos)
    {
        resultado += monomio.evaluar(x);
    }

    return resultado;
}

double Polinomio::resolver() const
{
    // @TODO Implementar método.
    return 0.0;
}

Polinomio Polinomio::derivado() const
{
    terminos_t derivados;

    for (const auto &monomio : this->terminos)
    {
        auto derivado = monomio.derivado();

        // No agregar a la lista de términos aquellos monomios que sean cero.
        if (!derivado.esCero())
        {
            derivados.push_back(derivado);
        }
    }

    return Polinomio(derivados);
}
}
