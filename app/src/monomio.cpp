#include "monomio.hpp"

Monomio::Monomio(coeficiente_t coeficiente, grado_t grado)
    : coeficiente(coeficiente), grado(grado)
{
}

Monomio Monomio::derivado() const
{
    return Monomio(this->coeficiente * this->grado, this->grado - 1);
}
