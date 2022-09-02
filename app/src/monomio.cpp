#include <cmath>
#include "monomio.hpp"

Monomio::Monomio(coeficiente_t coeficiente, grado_t grado)
    : coeficiente(coeficiente), grado(grado)
{
}

bool Monomio::esCero() const
{
    return this->coeficiente == 0;
}

bool Monomio::esConstante() const
{
    return this->grado == 0;
}

double Monomio::evaluar(double x) const
{
    return this->coeficiente * std::pow(x, this->grado);
}

Monomio Monomio::derivado() const
{
    // La derivada de un monomio constante es 0.
    if (this->esConstante())
    {
        return Monomio(0.0, 0);
    }

    return Monomio(this->coeficiente * this->grado, this->grado - 1);
}
